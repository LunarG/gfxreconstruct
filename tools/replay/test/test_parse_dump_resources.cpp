/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

/// Tests for the --dump-resources input json parser: the legacy flat schema and the tree schema.

#include <catch2/catch.hpp>

#include "parse_dump_resources_cli.h"

#include "decode/vulkan_replay_options.h"
#include "util/platform.h"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace gfxrecon;
using decode::Index;

namespace
{

struct TempJsonFile
{
    std::filesystem::path path;

    explicit TempJsonFile(const std::string& text)
    {
        static int counter = 0;
        path               = std::filesystem::temp_directory_path() /
               ("gfxrecon_vdr_test_" + std::to_string(util::platform::GetCurrentProcessId()) + "_" +
                std::to_string(counter++) + ".json");
        std::ofstream(path) << text;
    }

    ~TempJsonFile()
    {
        std::error_code ec;
        std::filesystem::remove(path, ec);
    }
};

struct ParseResult
{
    bool                        ok{ false };
    decode::VulkanReplayOptions options;
};

ParseResult ParseFile(const std::filesystem::path& path)
{
    ParseResult result;
    result.options.dump_resources_block_indices = path.string();
    result.ok                                   = parse_dump_resources::parse_dump_resources_arg(result.options);
    return result;
}

ParseResult Parse(const std::string& text)
{
    TempJsonFile file(text);
    return ParseFile(file.path);
}

using Pairs = std::vector<decode::BeginCmdBufQueueSubmitPair>;
using Rows  = std::vector<decode::CommandIndices>;
using RPs   = std::vector<decode::RenderPassIndices>;

// One command buffer row with everything the replayer reads for it, independent of row order and of how empty
// render pass rows were spelled.
struct Row
{
    decode::BeginCmdBufQueueSubmitPair      key;
    decode::CommandIndices                  draw;
    decode::CommandIndices                  dispatch;
    decode::CommandIndices                  trace_rays;
    decode::CommandIndices                  transfer;
    decode::RenderPassIndices               render_passes;
    std::map<Index, decode::CommandIndices> execute_commands;

    bool operator==(const Row& other) const = default;
};

template <typename Vector>
typename Vector::value_type RowOrEmpty(const Vector& rows, size_t i)
{
    return i < rows.size() ? rows[i] : typename Vector::value_type{};
}

std::vector<Row> Canonical(const decode::VulkanReplayOptions& options)
{
    std::vector<Row> rows;
    for (size_t i = 0; i < options.BeginCommandBufferQueueSubmit_Indices.size(); ++i)
    {
        Row row;
        row.key           = options.BeginCommandBufferQueueSubmit_Indices[i];
        row.draw          = RowOrEmpty(options.Draw_Indices, i);
        row.dispatch      = RowOrEmpty(options.Dispatch_Indices, i);
        row.trace_rays    = RowOrEmpty(options.TraceRays_Indices, i);
        row.transfer      = RowOrEmpty(options.Transfer_Indices, i);
        row.render_passes = RowOrEmpty(options.RenderPass_Indices, i);
        row.render_passes.erase(std::remove_if(row.render_passes.begin(),
                                               row.render_passes.end(),
                                               [](const decode::CommandIndices& r) { return r.empty(); }),
                                row.render_passes.end());

        for (const auto& [ec, secondaries] : RowOrEmpty(options.ExecuteCommands_Indices, i))
        {
            decode::CommandIndices sorted = secondaries;
            std::sort(sorted.begin(), sorted.end());
            row.execute_commands[ec] = sorted;
        }
        rows.push_back(row);
    }
    std::sort(rows.begin(), rows.end(), [](const Row& a, const Row& b) { return a.key < b.key; });
    return rows;
}

void RequireSameRequest(const decode::VulkanReplayOptions& a, const decode::VulkanReplayOptions& b)
{
    REQUIRE(Canonical(a) == Canonical(b));
    REQUIRE(a.DrawSubresources == b.DrawSubresources);
    REQUIRE(a.DispatchSubresources == b.DispatchSubresources);
    REQUIRE(a.TraceRaysSubresources == b.TraceRaysSubresources);
    REQUIRE(a.TransferSubresources == b.TransferSubresources);

    REQUIRE(a.dump_resources_scale == b.dump_resources_scale);
    REQUIRE(a.dump_resources_output_dir == b.dump_resources_output_dir);
    REQUIRE(a.dump_resources_color_attachment_index == b.dump_resources_color_attachment_index);
    REQUIRE(a.dump_resources_before == b.dump_resources_before);
    REQUIRE(a.dump_resources_dump_depth == b.dump_resources_dump_depth);
    REQUIRE(a.dump_resources_dump_vertex_index_buffer == b.dump_resources_dump_vertex_index_buffer);
    REQUIRE(a.dump_all_descriptors == b.dump_all_descriptors);
    REQUIRE(a.dump_resources_dump_all_image_subresources == b.dump_resources_dump_all_image_subresources);
    REQUIRE(a.dump_resources_dump_raw_images == b.dump_resources_dump_raw_images);
    REQUIRE(a.dump_resources_dump_separate_alpha == b.dump_resources_dump_separate_alpha);
    REQUIRE(a.dump_resources_dump_unused_vertex_bindings == b.dump_resources_dump_unused_vertex_bindings);
    REQUIRE(a.dump_resources_image_format == b.dump_resources_image_format);
    REQUIRE(a.dump_resources_json_per_command == b.dump_resources_json_per_command);
    REQUIRE(a.dump_resources_binary_file_compression_type == b.dump_resources_binary_file_compression_type);
    REQUIRE(a.dump_resources_dump_build_AS_input_buffers == b.dump_resources_dump_build_AS_input_buffers);
}

const decode::ImageSubresourceRanges kAllSubresources{ VK_IMAGE_ASPECT_NONE,      0, VK_REMAINING_MIP_LEVELS,    0,
                                                       VK_REMAINING_ARRAY_LAYERS, 0, decode::REMAINING_Z_INDICES };

// Example 4.2 of the schema proposal without the two Resources entries.
const char* kTreeExample42 = R"({
  "QueueSubmits": [ {
    "Index": 2002,
    "CommandBuffers": [ {
      "Index": 1000,
      "RenderPasses": [ [ 1009, 1015, 1022, 1024, 1036 ] ],
      "Draw":      [ 1014, 1020, 1021, 1029, 1035 ],
      "Dispatch":  [ 1003 ],
      "TraceRays": [ 1007 ],
      "Transfer":  [ 1004, 1008 ],
      "ExecuteCommands": [
        { "Index": 1023, "CommandBuffers": [ { "Index": 100, "Draw": [ 105 ] } ] },
        { "Index": 1030, "CommandBuffers": [ { "Index": 200, "Draw": [ 205, 206 ] },
                                             { "Index": 300, "Draw": [ 305, 306 ] } ] },
        { "Index": 1037, "CommandBuffers": [ { "Index": 400, "Dispatch": [ 403 ] } ] },
        { "Index": 1038, "CommandBuffers": [ { "Index": 500, "RenderPasses": [ [ 501, 507 ] ],
                                                             "Draw": [ 506 ] } ] }
      ]
    } ]
  } ]
})";

// The same request in the legacy schema, as printed in the proposal.
const char* kLegacyExample42 = R"({
  "BeginCommandBuffer": [ 1000, 100, 200, 300, 400, 500 ],
  "QueueSubmit":        [ 2002, 2002, 2002, 2002, 2002, 2002 ],
  "Draw":      [ [ 1014, 1020, 1021, 1029, 1035 ], [ 105 ], [ 205, 206 ], [ 305, 306 ], [ ], [ 506 ] ],
  "Dispatch":  [ [ 1003 ], [ ], [ ], [ ], [ 403 ], [ ] ],
  "TraceRays": [ [ 1007 ], [ ], [ ], [ ], [ ], [ ] ],
  "Transfer":  [ [ 1004, 1008 ], [ ], [ ], [ ], [ ], [ ] ],
  "RenderPass": [ [ [ 1009, 1015, 1022, 1024, 1036 ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ 501, 507 ] ] ],
  "ExecuteCommands": [ [ [ 1023, 100 ], [ 1030, 200, 300 ], [ 1037, 400 ], [ 1038, 500 ] ], [ ], [ ], [ ], [ ], [ ] ]
})";

} // namespace

// Legacy flat schema

TEST_CASE("legacy: minimal draw request", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({ "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307, 308 ] ],
                              "RenderPass": [ [ [ 302, 313 ] ] ], "QueueSubmit": [ 315 ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.dumping_resources);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 301, 315 } });
    REQUIRE(r.options.Draw_Indices == Rows{ { 307, 308 } });
    REQUIRE(r.options.RenderPass_Indices == RPs{ { { 302, 313 } } });
    REQUIRE(r.options.Dispatch_Indices.empty());
    REQUIRE(r.options.ExecuteCommands_Indices.empty());
    REQUIRE_FALSE(r.options.dump_resources_request.has_value());
}

TEST_CASE("legacy: secondary executed from a primary keeps file order", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({
        "BeginCommandBuffer": [ 754, 736 ],
        "Draw": [ [ 761 ], [ ] ],
        "RenderPass": [ [ [ ] ], [ [ 3948, 3950 ] ] ],
        "ExecuteCommands": [ [ [ ] ], [ [ 3949, 754 ] ] ],
        "QueueSubmit": [ 3952, 3952 ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 754, 3952 }, { 736, 3952 } });
    REQUIRE(r.options.Draw_Indices == Rows{ { 761 }, {} });
    REQUIRE(r.options.RenderPass_Indices == RPs{ { {} }, { { 3948, 3950 } } });
    REQUIRE(r.options.ExecuteCommands_Indices.size() == 2);
    REQUIRE(r.options.ExecuteCommands_Indices[0].empty());
    REQUIRE(r.options.ExecuteCommands_Indices[1] == decode::ExecuteCommands{ { 3949, { 754 } } });
}

TEST_CASE("legacy: descriptors with a subresource range", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({
        "BeginCommandBuffer": [ 2525 ], "QueueSubmit": [ 2548 ], "RenderPass": [ [ [ 2526, 2538 ] ] ],
        "Draw": [ [ { "Index": 2533, "Descriptors": [
                        { "Set": 0, "Binding": 1, "ArrayIndex": 0,
                          "SubresourceRange": { "AspectMask": "VK_IMAGE_ASPECT_COLOR_BIT", "BaseMipLevel": 1,
                                                "LevelCount": "VK_REMAINING_MIP_LEVELS", "BaseArrayLayer": 1,
                                                "LayerCount": 1 } },
                        { "Set": 0, "Binding": 1, "ArrayIndex": 0 } ] },
                    { "Index": 2537 }, 2538 ] ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.Draw_Indices == Rows{ { 2533, 2537, 2538 } });
    REQUIRE(r.options.DrawSubresources.size() == 1);
    const auto& descriptors = r.options.DrawSubresources.at(decode::CommandLocation(2525, 2548, 2533));
    REQUIRE(descriptors.size() == 1); // the duplicate descriptor is dropped
    REQUIRE(descriptors[0].first == decode::DescriptorLocation(0, 1, 0));
    REQUIRE(descriptors[0].second ==
            decode::ImageSubresourceRanges{
                VK_IMAGE_ASPECT_COLOR_BIT, 1, VK_REMAINING_MIP_LEVELS, 1, 1, 0, decode::REMAINING_Z_INDICES });
}

TEST_CASE("legacy: one dimensional Dispatch list is accepted", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({ "BeginCommandBuffer": [ 229 ], "QueueSubmit": [ 234 ], "Dispatch": [ 232 ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.Dispatch_Indices == Rows{ { 232 } });
}

TEST_CASE("legacy: state setup block with placeholder TraceRays row", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({ "BeginCommandBuffer": [ 0 ], "TraceRays": [ [ ] ], "Transfer": [ [ 261, 262 ] ],
                              "QueueSubmit": [ 0 ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 0, 0 } });
    REQUIRE(r.options.TraceRays_Indices == Rows{ {} });
    REQUIRE(r.options.Transfer_Indices == Rows{ { 261, 262 } });
}

TEST_CASE("legacy: DumpResourcesOptions are case insensitive and lenient", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({
        "DumpResourcesOptions": { "scale": 0.5, "IMAGEFORMAT": "png", "DumpDepth": true,
                                  "BinaryFileCompressionType": "ZSTD", "ColorAttachmentIndex": 2,
                                  "OutputDir": "out", "NotAnOption": 1, "DumpBuildAccelerationStructuresInputBuffers": true },
        "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307 ] ], "RenderPass": [ [ [ 302, 313 ] ] ],
        "QueueSubmit": [ 315 ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.dump_resources_scale == 0.5f);
    REQUIRE(r.options.dump_resources_image_format == util::ScreenshotFormat::kPng);
    REQUIRE(r.options.dump_resources_dump_depth);
    REQUIRE(r.options.dump_resources_binary_file_compression_type == format::CompressionType::kZstd);
    REQUIRE(r.options.dump_resources_color_attachment_index == 2);
    REQUIRE(r.options.dump_resources_output_dir == "out");
    REQUIRE(r.options.dump_resources_dump_build_AS_input_buffers);
}

TEST_CASE("legacy: transfer descriptors land in TransferSubresources", "[vdr-parse][legacy]")
{
    const auto r = Parse(R"({ "BeginCommandBuffer": [ 125 ], "QueueSubmit": [ 130 ],
                              "Transfer": [ [ { "Index": 126, "Descriptors": [ { "Set": 0, "Binding": 0, "ArrayIndex": 0 } ] } ] ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.Transfer_Indices == Rows{ { 126 } });
    REQUIRE(r.options.TransferSubresources.count(decode::CommandLocation(125, 130, 126)) == 1);
    REQUIRE(r.options.TraceRaysSubresources.empty());
}

TEST_CASE("legacy: malformed requests are rejected", "[vdr-parse][legacy]")
{
    const char* malformed[] = {
        // duplicate (bcb, qs) pair
        R"({ "BeginCommandBuffer": [ 301, 301 ], "Draw": [ [ 307 ], [ 308 ] ], "QueueSubmit": [ 315, 315 ] })",
        // length mismatch
        R"({ "BeginCommandBuffer": [ 301, 302 ], "Draw": [ [ 307 ], [ ] ], "QueueSubmit": [ 315 ] })",
        // Draw present but every row empty
        R"({ "BeginCommandBuffer": [ 301 ], "Draw": [ [ ] ], "QueueSubmit": [ 315 ] })",
        // render pass range with a single entry
        R"({ "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307 ] ], "RenderPass": [ [ [ 302 ] ] ], "QueueSubmit": [ 315 ] })",
        // syntax error
        R"({ "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307 ] ], )",
        // type mismatch inside the options
        R"({ "DumpResourcesOptions": { "Scale": "big" }, "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307 ] ],
             "RenderPass": [ [ [ 302, 313 ] ] ], "QueueSubmit": [ 315 ] })",
        // type mismatch inside an index list
        R"({ "BeginCommandBuffer": [ "301" ], "Draw": [ [ 307 ] ], "RenderPass": [ [ [ 302, 313 ] ] ], "QueueSubmit": [ 315 ] })",
    };

    for (const char* text : malformed)
    {
        INFO(text);
        const auto r = Parse(text);
        REQUIRE_FALSE(r.ok);
        REQUIRE_FALSE(r.options.dumping_resources);
    }
}

TEST_CASE("legacy: arguments that are not a json file are ignored", "[vdr-parse][legacy]")
{
    decode::VulkanReplayOptions options;
    options.dump_resources_block_indices = "QueueSubmit=315,BeginCommandBuffer=301,Draw=307";
    REQUIRE(parse_dump_resources::parse_dump_resources_arg(options));
    REQUIRE(options.BeginCommandBufferQueueSubmit_Indices.empty());

    options.dump_resources_block_indices = "";
    REQUIRE(parse_dump_resources::parse_dump_resources_arg(options));
    REQUIRE(options.BeginCommandBufferQueueSubmit_Indices.empty());
}

// Tree schema

TEST_CASE("tree: minimal request lowers like the legacy one", "[vdr-parse][tree]")
{
    const auto tree = Parse(R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [
                                   { "Index": 301, "RenderPasses": [ [ 302, 313 ] ], "Draw": [ 307, 308 ] } ] } ] })");
    REQUIRE(tree.ok);
    REQUIRE(tree.options.dumping_resources);
    REQUIRE(tree.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 301, 315 } });
    REQUIRE(tree.options.Draw_Indices == Rows{ { 307, 308 } });
    REQUIRE(tree.options.RenderPass_Indices == RPs{ { { 302, 313 } } });
    REQUIRE(tree.options.Dispatch_Indices.empty());
    REQUIRE(tree.options.TraceRays_Indices.empty());
    REQUIRE(tree.options.Transfer_Indices.empty());
    REQUIRE(tree.options.ExecuteCommands_Indices.empty());

    const auto legacy = Parse(R"({ "BeginCommandBuffer": [ 301 ], "Draw": [ [ 307, 308 ] ],
                                   "RenderPass": [ [ [ 302, 313 ] ] ], "QueueSubmit": [ 315 ] })");
    REQUIRE(legacy.ok);
    RequireSameRequest(tree.options, legacy.options);

    // The request tree is kept for the replayer.
    REQUIRE(tree.options.dump_resources_request.has_value());
    decode::DumpResourcesRequest expected;
    expected.queue_submits.push_back({ { 315 }, { {} } });
    auto& cb         = expected.queue_submits[0].command_buffers[0];
    cb.index         = 301;
    cb.render_passes = { { 302, 313 } };
    cb.draws         = { { 307 }, { 308 } };
    REQUIRE(*tree.options.dump_resources_request == expected);
}

TEST_CASE("tree: primary with secondaries (proposal example 4.2)", "[vdr-parse][tree]")
{
    const auto r = Parse(kTreeExample42);
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices ==
            Pairs{ { 1000, 2002 }, { 100, 2002 }, { 200, 2002 }, { 300, 2002 }, { 400, 2002 }, { 500, 2002 } });
    REQUIRE(r.options.Draw_Indices ==
            Rows{ { 1014, 1020, 1021, 1029, 1035 }, { 105 }, { 205, 206 }, { 305, 306 }, {}, { 506 } });
    REQUIRE(r.options.Dispatch_Indices == Rows{ { 1003 }, {}, {}, {}, { 403 }, {} });
    REQUIRE(r.options.TraceRays_Indices == Rows{ { 1007 }, {}, {}, {}, {}, {} });
    REQUIRE(r.options.Transfer_Indices == Rows{ { 1004, 1008 }, {}, {}, {}, {}, {} });
    REQUIRE(r.options.RenderPass_Indices ==
            RPs{ { { 1009, 1015, 1022, 1024, 1036 } }, {}, {}, {}, {}, { { 501, 507 } } });
    REQUIRE(r.options.ExecuteCommands_Indices.size() == 6);
    REQUIRE(r.options.ExecuteCommands_Indices[0] ==
            decode::ExecuteCommands{ { 1023, { 100 } }, { 1030, { 200, 300 } }, { 1037, { 400 } }, { 1038, { 500 } } });
    for (size_t i = 1; i < 6; ++i)
    {
        REQUIRE(r.options.ExecuteCommands_Indices[i].empty());
    }

    const auto legacy = Parse(kLegacyExample42);
    REQUIRE(legacy.ok);
    RequireSameRequest(r.options, legacy.options);
}

TEST_CASE("tree: a QueueSubmit index list repeats the subtree per submission", "[vdr-parse][tree]")
{
    std::string text = kTreeExample42;
    text.replace(text.find("\"Index\": 2002"), std::string("\"Index\": 2002").size(), "\"Index\": [ 2002, 2000 ]");

    const auto r = Parse(text);
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices.size() == 12);
    for (size_t i = 0; i < 6; ++i)
    {
        REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices[i].second == 2000);
        REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices[i + 6].second == 2002);
        REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices[i].first ==
                r.options.BeginCommandBufferQueueSubmit_Indices[i + 6].first);
        REQUIRE(r.options.Draw_Indices[i] == r.options.Draw_Indices[i + 6]);
        REQUIRE(r.options.ExecuteCommands_Indices[i] == r.options.ExecuteCommands_Indices[i + 6]);
    }
    REQUIRE(r.options.dump_resources_request->queue_submits[0].indices == std::vector<Index>{ 2000, 2002 });
}

TEST_CASE("tree: secondary under a primary that only carries the render pass (example 4.4)", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 2000, "CommandBuffers": [ {
        "Index": 1000, "RenderPasses": [ [ 1001, 1003 ] ],
        "ExecuteCommands": [ { "Index": 1002, "CommandBuffers": [ { "Index": 100, "Draw": [ 105 ] } ] } ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 1000, 2000 }, { 100, 2000 } });
    REQUIRE(r.options.Draw_Indices == Rows{ {}, { 105 } });
    REQUIRE(r.options.RenderPass_Indices == RPs{ { { 1001, 1003 } }, {} });
    REQUIRE(r.options.ExecuteCommands_Indices[0] == decode::ExecuteCommands{ { 1002, { 100 } } });
    REQUIRE(r.options.Dispatch_Indices.empty());
    REQUIRE(r.options.TraceRays_Indices.empty());
    REQUIRE(r.options.Transfer_Indices.empty());
}

TEST_CASE("tree: descriptor culling (example 4.6)", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 2548, "CommandBuffers": [ {
        "Index": 2525, "RenderPasses": [ [ 2526, 2538 ] ],
        "Draw": [ { "Index": 2533, "Descriptors": [ { "Set": 0, "Binding": 1, "ArrayIndex": 0 } ] }, 2537 ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.Draw_Indices == Rows{ { 2533, 2537 } });
    REQUIRE(r.options.DrawSubresources.size() == 1);
    const auto& descriptors = r.options.DrawSubresources.at(decode::CommandLocation(2525, 2548, 2533));
    REQUIRE(descriptors.size() == 1);
    REQUIRE(descriptors[0].first == decode::DescriptorLocation(0, 1, 0));
    REQUIRE(descriptors[0].second == kAllSubresources);
}

TEST_CASE("tree: state setup meta commands (example 4.7)", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "StateSetup": { "Transfer": [ 267, 266 ] } })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 0, 0 } });
    REQUIRE(r.options.Transfer_Indices == Rows{ { 266, 267 } });
    REQUIRE(r.options.Draw_Indices.empty());
    REQUIRE(r.options.Dispatch_Indices.empty());
    REQUIRE(r.options.TraceRays_Indices.empty());
    REQUIRE(r.options.RenderPass_Indices.empty());
    REQUIRE(r.options.ExecuteCommands_Indices.empty());
    REQUIRE(r.options.dump_resources_request->state_setup_transfers.size() == 2);

    const auto legacy = Parse(R"({ "BeginCommandBuffer": [ 0 ], "QueueSubmit": [ 0 ], "Transfer": [ [ 266, 267 ] ] })");
    REQUIRE(legacy.ok);
    RequireSameRequest(r.options, legacy.options);
}

TEST_CASE("tree: state setup next to queue submits", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "StateSetup": { "Transfer": [ 266 ] },
                              "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Transfer": [ 303 ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 301, 315 }, { 0, 0 } });
    REQUIRE(r.options.Transfer_Indices == Rows{ { 303 }, { 266 } });
}

TEST_CASE("tree: top-level DumpingOptions apply to the request (example 4.8)", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({
        "DumpingOptions": { "ImageFormat": "png", "DumpDepth": true, "Scale": 0.25, "OutputDir": "out",
                            "BinaryFileCompressionType": "lz4", "ColorAttachmentIndex": -1, "JsonOutputPerCommand": true },
        "QueueSubmits": [ { "Index": 315, "CommandBuffers": [
            { "Index": 301, "RenderPasses": [ [ 302, 313 ] ], "Draw": [ 307, 308 ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.dump_resources_image_format == util::ScreenshotFormat::kPng);
    REQUIRE(r.options.dump_resources_dump_depth);
    REQUIRE(r.options.dump_resources_scale == 0.25f);
    REQUIRE(r.options.dump_resources_output_dir == "out");
    REQUIRE(r.options.dump_resources_binary_file_compression_type == format::CompressionType::kLz4);
    REQUIRE(r.options.dump_resources_color_attachment_index == -1);
    REQUIRE(r.options.dump_resources_json_per_command);
    REQUIRE(r.options.dump_resources_request->dumping_options.image_format == util::ScreenshotFormat::kPng);
    REQUIRE_FALSE(r.options.dump_resources_request->dumping_options.dump_raw_images.has_value());
}

TEST_CASE("tree: lists are sorted by the parser", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [
        { "Index": 301, "RenderPasses": [ [ 320, 330 ], [ 302, 313 ] ], "Draw": [ 309, 307, 308 ], "Dispatch": [ 325, 322 ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.Draw_Indices == Rows{ { 307, 308, 309 } });
    REQUIRE(r.options.Dispatch_Indices == Rows{ { 322, 325 } });
    REQUIRE(r.options.RenderPass_Indices == RPs{ { { 302, 313 }, { 320, 330 } } });
}

TEST_CASE("tree: a secondary executed from several places with the same request shares one row", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 425, "CommandBuffers": [ {
        "Index": 311, "RenderPasses": [ [ 327, 330 ] ],
        "ExecuteCommands": [ { "Index": 328, "CommandBuffers": [ { "Index": 241, "Draw": [ 246 ] } ] },
                             { "Index": 329, "CommandBuffers": [ { "Index": 241, "Draw": [ 246 ] } ] } ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 311, 425 }, { 241, 425 } });
    REQUIRE(r.options.Draw_Indices == Rows{ {}, { 246 } });
    REQUIRE(r.options.ExecuteCommands_Indices[0] == decode::ExecuteCommands{ { 328, { 241 } }, { 329, { 241 } } });

    const auto different = Parse(R"({ "QueueSubmits": [ { "Index": 425, "CommandBuffers": [ {
        "Index": 311, "RenderPasses": [ [ 327, 330 ] ],
        "ExecuteCommands": [ { "Index": 328, "CommandBuffers": [ { "Index": 241, "Draw": [ 246 ] } ] },
                             { "Index": 329, "CommandBuffers": [ { "Index": 241, "Draw": [ 247 ] } ] } ] } ] } ] })");
    REQUIRE_FALSE(different.ok);
}

TEST_CASE("tree: a secondary executed from two primaries shares one row", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 500, "CommandBuffers": [
        { "Index": 300, "ExecuteCommands": [ { "Index": 310, "CommandBuffers": [ { "Index": 100, "Dispatch": [ 103 ] } ] } ] },
        { "Index": 400, "ExecuteCommands": [ { "Index": 410, "CommandBuffers": [ { "Index": 100, "Dispatch": [ 103 ] } ] } ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 300, 500 }, { 100, 500 }, { 400, 500 } });
    REQUIRE(r.options.Dispatch_Indices == Rows{ {}, { 103 }, {} });
    REQUIRE(r.options.ExecuteCommands_Indices[0] == decode::ExecuteCommands{ { 310, { 100 } } });
    REQUIRE(r.options.ExecuteCommands_Indices[2] == decode::ExecuteCommands{ { 410, { 100 } } });
}

TEST_CASE("tree: nested secondaries get their own ExecuteCommands row", "[vdr-parse][tree]")
{
    const auto r = Parse(R"({ "QueueSubmits": [ { "Index": 500, "CommandBuffers": [
        { "Index": 300, "ExecuteCommands": [ { "Index": 310, "CommandBuffers": [
            { "Index": 200, "ExecuteCommands": [ { "Index": 210, "CommandBuffers": [
                { "Index": 100, "Dispatch": [ 103 ] } ] } ] } ] } ] } ] } ] })");
    REQUIRE(r.ok);
    REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices == Pairs{ { 300, 500 }, { 200, 500 }, { 100, 500 } });
    REQUIRE(r.options.ExecuteCommands_Indices[0] == decode::ExecuteCommands{ { 310, { 200 } } });
    REQUIRE(r.options.ExecuteCommands_Indices[1] == decode::ExecuteCommands{ { 210, { 100 } } });
    REQUIRE(r.options.ExecuteCommands_Indices[2].empty());
    REQUIRE(r.options.Dispatch_Indices == Rows{ {}, {}, { 103 } });
}

TEST_CASE("tree: features the replayer does not support yet are rejected", "[vdr-parse][tree]")
{
    const char* unsupported[] = {
        // Position under a QueueSubmit (example 4.3)
        R"({ "QueueSubmits": [ { "Index": 2000, "CommandBuffers": [ { "Index": 1000, "Position": [ [ 0, 0 ], [ 0, 1 ] ],
             "Dispatch": [ 1003 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 2000, "CommandBuffers": [ { "Index": 1000, "Position": [ 0, 0 ],
             "Dispatch": [ 1003 ] } ] } ] })",
        // Position under an ExecuteCommands (example 4.4)
        R"({ "QueueSubmits": [ { "Index": 2000, "CommandBuffers": [ { "Index": 1000, "RenderPasses": [ [ 1001, 1003 ] ],
             "ExecuteCommands": [ { "Index": 1002, "CommandBuffers": [ { "Index": 100, "Position": [ 0, 1 ], "Draw": [ 105 ] } ] } ] } ] } ] })",
        // Resources at the top level and inside a command buffer
        R"({ "Resources": [ 2001 ] })",
        R"({ "QueueSubmits": [ { "Index": 2000, "CommandBuffers": [ { "Index": 1000, "Transfer": [ 1008 ],
             "Resources": [ { "Index": 1008, "IDs": [ 75, { "Id": 76, "SubresourceRange": { "AspectMask": "VK_IMAGE_ASPECT_COLOR_BIT" } } ] } ] } ] } ] })",
        // per-command DumpingOptions (example 4.8)
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ [ 302, 313 ] ],
             "Draw": [ 307, { "Index": 308, "DumpingOptions": { "Scale": 0.5, "DumpVertexIndexBuffer": true } } ] } ] } ] })",
    };

    for (const char* text : unsupported)
    {
        INFO(text);
        const auto r = Parse(text);
        REQUIRE_FALSE(r.ok);
        REQUIRE_FALSE(r.options.dumping_resources);
        REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices.empty());
    }

    // An empty per-command DumpingOptions object changes nothing and is accepted.
    const auto empty_options = Parse(R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301,
        "RenderPasses": [ [ 302, 313 ] ], "Draw": [ { "Index": 308, "DumpingOptions": { } } ] } ] } ] })");
    REQUIRE(empty_options.ok);
}

TEST_CASE("tree: malformed requests are rejected", "[vdr-parse][tree]")
{
    const char* malformed[] = {
        // unknown and legacy keys at the top level
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ], "QueueSubmit": [ 315 ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ], "DumpResourcesOptions": { } })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ], "Foo": 1 })",
        R"({ })",
        R"({ "DumpingOptions": { "Scale": 1.0 } })",
        R"([ 1, 2, 3 ])",
        R"({ "QueueSubmits": [ ] })",
        // unknown keys inside nodes
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ], "Extra": 1 } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPass": [ [ 302, 313 ] ], "Draw": [ 307 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Draw": [ { "Index": 307, "Descriptor": [ ] } ] } ] } ] })",
        // missing or malformed indices
        R"({ "QueueSubmits": [ { "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": -1, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315.0, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": "315", "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 0, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": [ ], "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": [ 315, 315 ], "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303, "304" ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": 303 } ] } ] })",
        // duplicates
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] }, { "Index": 301, "Dispatch": [ 304 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] },
                               { "Index": 315, "CommandBuffers": [ { "Index": 302, "Dispatch": [ 304 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303, 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ], "Draw": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [
             { "Index": 310, "CommandBuffers": [ { "Index": 100, "Dispatch": [ 103 ] } ] },
             { "Index": 310, "CommandBuffers": [ { "Index": 200, "Dispatch": [ 203 ] } ] } ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [
             { "Index": 310, "CommandBuffers": [ { "Index": 100, "Dispatch": [ 103 ] }, { "Index": 100, "Dispatch": [ 103 ] } ] } ] } ] } ] })",
        // render pass ranges
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ [ 302 ] ], "Draw": [ 307 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ [ ] ], "Draw": [ 307 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ [ 313, 302 ] ], "Draw": [ 307 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ [ 302, 313 ], [ 302, 320 ] ], "Draw": [ 307 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "RenderPasses": [ 302, 313 ], "Draw": [ 307 ] } ] } ] })",
        // Position shapes
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Position": [ 0 ], "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Position": 0, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Position": [ 0, 1, 2 ], "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Position": [ [ 0, 0 ], [ 0, 0 ] ], "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [
             { "Index": 310, "CommandBuffers": [ { "Index": 100, "Position": [ [ 0, 1 ] ], "Dispatch": [ 103 ] } ] } ] } ] } ] })",
        // ExecuteCommands shapes
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [ { "Index": 310, "CommandBuffers": [ ] } ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [ { "Index": 310 } ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "ExecuteCommands": [ [ 310, 100 ] ] } ] } ] })",
        // descriptors
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ { "Index": 303, "Descriptors": [ { "Binding": 1, "ArrayIndex": 0 } ] } ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ { "Index": 303, "Descriptors": [
             { "Set": 0, "Binding": 1, "ArrayIndex": 0 }, { "Set": 0, "Binding": 1, "ArrayIndex": 0 } ] } ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ { "Index": 303, "Descriptors": [
             { "Set": 0, "Binding": 1, "ArrayIndex": 0, "SubresourceRange": { "AspectMask": "VK_IMAGE_ASPECT_COLOR_BIT", "LevelCount": "ALL" } } ] } ] } ] } ] })",
        // DumpingOptions
        R"({ "DumpingOptions": { "Sclae": 1.0 }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "Scale": "1.0" }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "Scale": 0 }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "DumpDepth": 1 }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "ImageFormat": "jpg" }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "BinaryFileCompressionType": "gzip" }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "DumpingOptions": { "ColorAttachmentIndex": -2 }, "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ 303 ] } ] } ] })",
        R"({ "QueueSubmits": [ { "Index": 315, "CommandBuffers": [ { "Index": 301, "Dispatch": [ { "Index": 303, "DumpingOptions": { "JsonOutputPerCommand": true } } ] } ] } ] })",
        // StateSetup
        R"({ "StateSetup": { "Draw": [ 266 ] } })",
        R"({ "StateSetup": { } })",
        R"({ "StateSetup": [ 266 ] })",
        // syntax error
        R"({ "QueueSubmits": [ { "Index": 315, )",
    };

    for (const char* text : malformed)
    {
        INFO(text);
        const auto r = Parse(text);
        REQUIRE_FALSE(r.ok);
        REQUIRE_FALSE(r.options.dumping_resources);
        REQUIRE(r.options.BeginCommandBufferQueueSubmit_Indices.empty());
        REQUIRE_FALSE(r.options.dump_resources_request.has_value());
    }
}

// Legacy requests from the CI suites converted by hand to the tree schema must lower to the same rows.

TEST_CASE("equivalence: dispatch indirect from a secondary", "[vdr-parse][equivalence]")
{
    const auto legacy = Parse(R"({ "BeginCommandBuffer": [ 1232, 1230 ], "Dispatch": [ [ 1238, 1243 ], [ ] ],
                                   "ExecuteCommands": [ [ [ ] ], [ [ 1247, 1232 ] ] ], "QueueSubmit": [ 1309, 1309 ] })");
    const auto tree   = Parse(R"({ "QueueSubmits": [ { "Index": 1309, "CommandBuffers": [ { "Index": 1230,
                                   "ExecuteCommands": [ { "Index": 1247, "CommandBuffers": [ { "Index": 1232, "Dispatch": [ 1238, 1243 ] } ] } ] } ] } ] })");
    REQUIRE(legacy.ok);
    REQUIRE(tree.ok);
    RequireSameRequest(legacy.options, tree.options);
}

TEST_CASE("equivalence: transfer from a secondary", "[vdr-parse][equivalence]")
{
    const auto legacy = Parse(R"({ "BeginCommandBuffer": [ 114, 120 ], "ExecuteCommands": [ [ [ ] ], [ [ 121, 114 ] ] ],
                                   "Transfer": [ [ 116 ], [ ] ], "QueueSubmit": [ 124, 124 ] })");
    const auto tree   = Parse(R"({ "QueueSubmits": [ { "Index": 124, "CommandBuffers": [ { "Index": 120,
                                   "ExecuteCommands": [ { "Index": 121, "CommandBuffers": [ { "Index": 114, "Transfer": [ 116 ] } ] } ] } ] } ] })");
    REQUIRE(legacy.ok);
    REQUIRE(tree.ok);
    RequireSameRequest(legacy.options, tree.options);
}

TEST_CASE("equivalence: dynamic rendering in secondaries over two submissions", "[vdr-parse][equivalence]")
{
    const auto legacy =
        Parse(R"({ "BeginCommandBuffer": [ 954, 940, 1258, 1244 ], "Draw": [ [ 963 ], [ ], [ 1267 ], [ ] ],
                                   "RenderPass": [ [ [ 955, 964 ] ], [ [ ] ], [ [ 1259, 1268 ] ], [ [ ] ] ],
                                   "ExecuteCommands": [ [ [ ] ], [ [ 966, 954 ] ], [ [ ] ], [ [ 1270, 1258 ] ] ],
                                   "QueueSubmit": [ 970, 970, 1274, 1274 ] })");
    const auto tree = Parse(R"({ "QueueSubmits": [
        { "Index": 970, "CommandBuffers": [ { "Index": 940, "ExecuteCommands": [ { "Index": 966, "CommandBuffers": [
            { "Index": 954, "RenderPasses": [ [ 955, 964 ] ], "Draw": [ 963 ] } ] } ] } ] },
        { "Index": 1274, "CommandBuffers": [ { "Index": 1244, "ExecuteCommands": [ { "Index": 1270, "CommandBuffers": [
            { "Index": 1258, "RenderPasses": [ [ 1259, 1268 ] ], "Draw": [ 1267 ] } ] } ] } ] } ] })");
    REQUIRE(legacy.ok);
    REQUIRE(tree.ok);
    RequireSameRequest(legacy.options, tree.options);
}

TEST_CASE("equivalence: secondaries executed from several places with empty descriptor lists",
          "[vdr-parse][equivalence]")
{
    const auto legacy = Parse(R"({
        "BeginCommandBuffer": [ 269, 311, 206, 213, 220, 227, 234, 241, 248 ],
        "QueueSubmit": [ 425, 425, 425, 425, 425, 425, 425, 425, 425 ],
        "ExecuteCommands": [ [ [ ] ], [ [ 318, 206 ], [ 323, 213, 220, 227, 234 ], [ 328, 241 ], [ 329, 241 ], [ 334, 248 ], [ 341, 269 ] ],
                             [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ] ],
        "Draw": [ [ { "Index": 274, "Descriptors": [ ] } ], [ ], [ { "Index": 211, "Descriptors": [ ] } ],
                  [ { "Index": 218, "Descriptors": [ ] } ], [ { "Index": 225, "Descriptors": [ ] } ],
                  [ { "Index": 232, "Descriptors": [ ] } ], [ { "Index": 239, "Descriptors": [ ] } ],
                  [ { "Index": 246, "Descriptors": [ ] } ], [ { "Index": 253, "Descriptors": [ ] } ] ],
        "RenderPass": [ [ [ ] ], [ [ 317, 319 ], [ 322, 324 ], [ 327, 330 ], [ 333, 335 ], [ 338, 340, 342 ] ],
                        [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ], [ [ ] ] ] })");
    const auto tree   = Parse(R"({ "QueueSubmits": [ { "Index": 425, "CommandBuffers": [ { "Index": 311,
        "RenderPasses": [ [ 317, 319 ], [ 322, 324 ], [ 327, 330 ], [ 333, 335 ], [ 338, 340, 342 ] ],
        "ExecuteCommands": [
            { "Index": 318, "CommandBuffers": [ { "Index": 206, "Draw": [ { "Index": 211, "Descriptors": [ ] } ] } ] },
            { "Index": 323, "CommandBuffers": [ { "Index": 213, "Draw": [ { "Index": 218, "Descriptors": [ ] } ] },
                                                { "Index": 220, "Draw": [ { "Index": 225, "Descriptors": [ ] } ] },
                                                { "Index": 227, "Draw": [ { "Index": 232, "Descriptors": [ ] } ] },
                                                { "Index": 234, "Draw": [ { "Index": 239, "Descriptors": [ ] } ] } ] },
            { "Index": 328, "CommandBuffers": [ { "Index": 241, "Draw": [ { "Index": 246, "Descriptors": [ ] } ] } ] },
            { "Index": 329, "CommandBuffers": [ { "Index": 241, "Draw": [ { "Index": 246, "Descriptors": [ ] } ] } ] },
            { "Index": 334, "CommandBuffers": [ { "Index": 248, "Draw": [ { "Index": 253, "Descriptors": [ ] } ] } ] },
            { "Index": 341, "CommandBuffers": [ { "Index": 269, "Draw": [ { "Index": 274, "Descriptors": [ ] } ] } ] } ] } ] } ] })");
    REQUIRE(legacy.ok);
    REQUIRE(tree.ok);
    RequireSameRequest(legacy.options, tree.options);
    REQUIRE(tree.options.DrawSubresources.size() == 8);
}

TEST_CASE("equivalence: descriptor subresource range", "[vdr-parse][equivalence]")
{
    const char* descriptors = R"([ { "Set": 0, "Binding": 1, "ArrayIndex": 0,
        "SubresourceRange": { "AspectMask": "VK_IMAGE_ASPECT_COLOR_BIT", "BaseMipLevel": 1, "LevelCount": "VK_REMAINING_MIP_LEVELS",
                              "BaseArrayLayer": 1, "LayerCount": 1 } } ])";
    const auto  legacy      = Parse(std::string(R"({ "BeginCommandBuffer": [ 2525 ], "QueueSubmit": [ 2548 ],
        "Draw": [ [ { "Index": 2533, "Descriptors": )") +
                              descriptors + R"( }, { "Index": 2537 } ] ],
        "RenderPass": [ [ [ 2526, 2538 ] ] ] })");
    const auto  tree = Parse(std::string(R"({ "QueueSubmits": [ { "Index": 2548, "CommandBuffers": [ { "Index": 2525,
        "RenderPasses": [ [ 2526, 2538 ] ], "Draw": [ { "Index": 2533, "Descriptors": )") +
                            descriptors + R"( }, 2537 ] } ] } ] })");
    REQUIRE(legacy.ok);
    REQUIRE(tree.ok);
    RequireSameRequest(legacy.options, tree.options);
}

// Hidden: parses every "*.dr-args.json" below the directory named by GFXRECON_VDR_JSON_DIR, and when a
// "<name>.dr-args.json.tree.json" sibling exists (the same request written in the tree schema) requires both to lower
// to the same rows. Run with: gfxrecon_replay_test "[vdr-suite]"
TEST_CASE("every request below GFXRECON_VDR_JSON_DIR parses and matches its tree sibling", "[.][vdr-suite]")
{
    const char* dir = std::getenv("GFXRECON_VDR_JSON_DIR");
    if (dir == nullptr)
    {
        WARN("GFXRECON_VDR_JSON_DIR is not set; nothing to check");
        return;
    }

    const std::string suffix       = ".dr-args.json";
    size_t            legacy_files = 0;
    size_t            tree_files   = 0;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(dir))
    {
        const std::string name = entry.path().filename().string();
        if (!entry.is_regular_file() || name.size() < suffix.size() ||
            name.compare(name.size() - suffix.size(), suffix.size(), suffix) != 0)
        {
            continue;
        }

        INFO(entry.path().string());
        const auto legacy = ParseFile(entry.path());
        REQUIRE(legacy.ok);
        ++legacy_files;

        const std::filesystem::path tree_path = entry.path().string() + ".tree.json";
        if (std::filesystem::exists(tree_path))
        {
            const auto tree = ParseFile(tree_path);
            REQUIRE(tree.ok);
            REQUIRE(tree.options.dump_resources_request.has_value());
            RequireSameRequest(legacy.options, tree.options);
            ++tree_files;
        }
    }

    INFO("legacy files: " << legacy_files << ", with tree sibling: " << tree_files);
    REQUIRE(legacy_files > 0);
}
