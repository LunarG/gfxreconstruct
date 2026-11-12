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

// Catch must come before the Vulkan headers.
#include <catch2/catch.hpp>

#include "decode/file_processor.h"
#include "decode/json_writer.h"
#include "decode/marker_json_consumer.h"
#include "decode/metadata_json_consumer.h"
#include "generated/generated_vulkan_consumer_stage.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_json_consumer.h"
#include "util/memory_output_stream.h"

#include <filesystem>
#include <sstream>
#include <string>
#include <vector>

using namespace gfxrecon::decode;

namespace
{

using VulkanJsonConsumer = MetadataJsonConsumer<MarkerJsonConsumer<VulkanExportJsonConsumer>>;

// JsonOptions are process-wide and assert if set twice, so set them once for the whole binary.
void SetJsonOptionsOnce()
{
    static const bool set = [] {
        using gfxrecon::util::JsonOptions;
        JsonOptions::root_dir      = std::string{};
        JsonOptions::data_sub_dir  = std::string{};
        JsonOptions::format        = gfxrecon::util::JsonFormat::JSON;
        JsonOptions::dump_binaries = false;
        JsonOptions::expand_flags  = false;
        JsonOptions::hex_handles   = false;
        return true;
    }();
    (void)set;
}

// Converts a capture to JSON the way gfxrecon-convert does, optionally behind an empty stage.
std::string ConvertToJson(const std::string& path, bool through_stage)
{
    SetJsonOptionsOnce();

    FileProcessor file_processor;
    REQUIRE(file_processor.Initialize(path));

    gfxrecon::util::MemoryOutputStream out;
    JsonWriter                         json_writer{ "test", path };
    file_processor.SetAnnotationProcessor(&json_writer);

    VulkanJsonConsumer  json_consumer;
    VulkanConsumerStage stage;
    VulkanDecoder       decoder;
    json_consumer.Initialize(&json_writer);

    if (through_stage)
    {
        stage.AddNext(&json_consumer);
        decoder.AddConsumer(&stage);
    }
    else
    {
        decoder.AddConsumer(&json_consumer);
    }

    file_processor.AddDecoder(&decoder);
    json_writer.StartStream(&out);
    file_processor.InitializeFrameProcessing();

    bool success = file_processor.ProcessPreFrame();
    while (success)
    {
        success = file_processor.ProcessNextFrame();
    }

    json_writer.Destroy();
    json_consumer.Destroy();

    REQUIRE(file_processor.GetErrorState() == BlockIOError::kErrorNone);
    return std::string(reinterpret_cast<const char*>(out.GetData()), out.GetDataSize());
}

std::vector<std::string> KnownGoodCaptures()
{
    std::vector<std::string> paths;
    for (const auto& entry : std::filesystem::directory_iterator(GFXRECON_KNOWN_GOOD_DIR))
    {
        if (entry.path().extension() == ".gfxr")
        {
            paths.push_back(entry.path().string());
        }
    }
    return paths;
}

// Describes the first line where the two JSON outputs differ, and the block that holds it.
// Returns an empty string when they match. Catch would print both outputs in full.
std::string FirstDifference(const std::string& direct, const std::string& staged)
{
    // Only the block index key sits at two-space indentation. Nested keys sit deeper.
    const std::string index_key = "  \"index\": ";

    std::istringstream direct_lines(direct);
    std::istringstream staged_lines(staged);
    std::string        direct_line;
    std::string        staged_line;
    std::string        block = "header";

    for (size_t line = 1;; ++line)
    {
        const bool has_direct = static_cast<bool>(std::getline(direct_lines, direct_line));
        const bool has_staged = static_cast<bool>(std::getline(staged_lines, staged_line));

        if (!has_direct && !has_staged)
        {
            return {};
        }

        if (direct_line.compare(0, index_key.size(), index_key) == 0)
        {
            block = "block " + std::to_string(std::stoull(direct_line.substr(index_key.size())));
        }

        if (has_direct != has_staged || direct_line != staged_line)
        {
            return block + ", line " + std::to_string(line) +
                   "\n  direct: " + (has_direct ? direct_line : "<end of output>") +
                   "\n  staged: " + (has_staged ? staged_line : "<end of output>");
        }
    }
}

} // namespace

// An empty stage must be invisible. Every known-good capture converts to the same JSON
// with and without one in front of the JSON consumer.
TEST_CASE("Empty stage leaves the JSON of every known-good capture unchanged", "[stage]")
{
    const auto captures = KnownGoodCaptures();
    REQUIRE_FALSE(captures.empty());

    for (const auto& path : captures)
    {
        INFO(path);

        const std::string direct = ConvertToJson(path, false);
        const std::string staged = ConvertToJson(path, true);

        REQUIRE_FALSE(direct.empty());

        const std::string difference = FirstDifference(direct, staged);
        INFO(difference);
        CHECK(difference.empty());
    }
}
