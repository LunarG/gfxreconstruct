/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "parse_dump_resources_cli.h"

#include "decode/vulkan_replay_dump_resources_options.h"
#include "decode/vulkan_replay_dump_resources_request.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_pre_process_consumer.h"
#include "util/json_util.h"
#include "util/logging.h"
#include "util/options.h"
#include "util/platform.h"
#include "util/strings.h"

#include <algorithm>
#include <cctype>
#include <cinttypes>
#include <cstdint>
#include <fstream>
#include <initializer_list>
#include <limits>
#include <map>
#include <optional>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(parse_dump_resources)

using json = nlohmann::ordered_json;

static std::string to_lower(std::string s)
{
    for (char& c : s)
    {
        c = tolower(c);
    }
    return s;
}

static bool ends_with(std::string const& fullString, std::string const& ending)
{
    bool rval = false;
    if (fullString.length() >= ending.length())
    {
        rval = (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    return rval;
}

static bool AreIndicesSorted(const std::vector<uint64_t>& indices)
{
    if (indices.size() == 1)
    {
        return true;
    }

    for (size_t i = 1; i < indices.size(); ++i)
    {
        // Allow for two consecutive indices to be equal. This can be the case where two different command buffers
        // are submitted in the same QueueSubmit command, hence the index of tha QueueSubmit will appear
        // twice in the indices
        if (indices[i] < indices[i - 1])
        {
            return false;
        }
    }

    return true;
}

static bool CheckIndicesForErrors(const gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    // Each per-command array is indexed by BeginCommandBuffer list position, so an array that is
    // present must provide one row per BeginCommandBuffer entry (rows may be empty).
    const size_t n_bcb_rows = vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.size();

    const std::pair<const char*, size_t> row_counts[] = {
        { "Draw", vulkan_replay_options.Draw_Indices.size() },
        { "RenderPass", vulkan_replay_options.RenderPass_Indices.size() },
        { "Dispatch", vulkan_replay_options.Dispatch_Indices.size() },
        { "TraceRays", vulkan_replay_options.TraceRays_Indices.size() },
        { "ExecuteCommands", vulkan_replay_options.ExecuteCommands_Indices.size() },
        { "Transfer", vulkan_replay_options.Transfer_Indices.size() },
    };

    for (const auto& [name, count] : row_counts)
    {
        if (count != 0 && count != n_bcb_rows)
        {
            GFXRECON_LOG_ERROR(
                "Malformed VDR input json: %s has %zu entries but BeginCommandBuffer has %zu", name, count, n_bcb_rows);
            return true;
        }
    }

    // Indices should be provided sorted
    if (vulkan_replay_options.Draw_Indices.size())
    {
        bool is_complete = false;
        for (const auto& indices : vulkan_replay_options.Draw_Indices)
        {
            is_complete |= (indices.size() > 0);

            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incorrect --dump-resources block indices parameters");
                GFXRECON_LOG_ERROR("Draw indices are not sorted")
                return true;
            }
        }

        if (!is_complete)
        {
            GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources block indices parameters");
            GFXRECON_LOG_ERROR("Draw indices should be a 2 dimensional array");
            return true;
        }
    }

    if (vulkan_replay_options.RenderPass_Indices.size())
    {
        bool is_complete = false;
        for (const auto& indices0 : vulkan_replay_options.RenderPass_Indices)
        {
            for (const auto& indices1 : indices0)
            {
                is_complete |= (indices1.size() > 0);

                if (!AreIndicesSorted(indices1))
                {
                    GFXRECON_LOG_ERROR("ERROR - incorrect --dump-resources block indices parameters");
                    GFXRECON_LOG_ERROR("Render pass indices are not sorted")
                    return true;
                }

                if (indices1.size() == 1)
                {
                    GFXRECON_LOG_ERROR("ERROR - incorrect --dump-resources block indices parameters");
                    GFXRECON_LOG_ERROR("A render pass index range holds its begin, one entry per subpass "
                                       "boundary and its end, or nothing for an inheriting secondary");
                    return true;
                }
            }
        }

        if (!is_complete)
        {
            GFXRECON_LOG_ERROR("ERROR - incomplete --dump-resources block indices parameters");
            GFXRECON_LOG_ERROR("RenderPass indices should be a 3 dimensional array");
            return true;
        }
    }

    if (vulkan_replay_options.Dispatch_Indices.size())
    {
        for (const auto& indices : vulkan_replay_options.Dispatch_Indices)
        {
            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incorrect --dump-resources block indices parameters");
                GFXRECON_LOG_ERROR("Dispatch indices are not sorted")
                return true;
            }
        }
    }

    if (vulkan_replay_options.TraceRays_Indices.size())
    {
        for (const auto& indices : vulkan_replay_options.TraceRays_Indices)
        {
            if (!AreIndicesSorted(indices))
            {
                GFXRECON_LOG_ERROR("ERROR - incorrect --dump-resources parameters");
                GFXRECON_LOG_ERROR("TraceRays indices are not sorted")
                return true;
            }
        }
    }

    // Verify that all BCB indices in the ExecuteCommands lists exist in the BeginCommandBufferQueueSubmit
    for (size_t i = 0; i < vulkan_replay_options.ExecuteCommands_Indices.size(); ++i)
    {
        const auto& execute_commands = vulkan_replay_options.ExecuteCommands_Indices[i];
        if (execute_commands.empty())
        {
            continue;
        }

        if (i >= vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.size())
        {
            GFXRECON_LOG_ERROR("Malformed VDR input json: ExecuteCommands entry %zu has no corresponding "
                               "BeginCommandBuffer entry",
                               i);
            return true;
        }

        const decode::Index qs_index = vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices[i].second;
        for (const auto& execute_command : execute_commands)
        {
            for (const auto& secondary_bcb : execute_command.second)
            {
                if (!std::any_of(vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.begin(),
                                 vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.end(),
                                 [secondary_bcb, qs_index](const decode::BeginCmdBufQueueSubmitPair& entry) {
                                     return entry.first == secondary_bcb && entry.second == qs_index;
                                 }))
                {
                    GFXRECON_LOG_ERROR("Malformed VDR input json: BeginCommandBuffer index %" PRIu64
                                       " referenced in ExecuteCommands is not paired with QueueSubmit index %" PRIu64
                                       " (the QueueSubmit of the primary that executes it) in the BeginCommandBuffer "
                                       "list",
                                       secondary_bcb,
                                       qs_index);
                    return true;
                }
            }
        }
    }

    return false;
}

static VkImageAspectFlags StrToImageAspectFlagBits(const std::string& str)
{
    static const std::map<std::string, VkImageAspectFlagBits> aspect_flags = {
        { "VK_IMAGE_ASPECT_COLOR_BIT", VK_IMAGE_ASPECT_COLOR_BIT },
        { "VK_IMAGE_ASPECT_DEPTH_BIT", VK_IMAGE_ASPECT_DEPTH_BIT },
        { "VK_IMAGE_ASPECT_STENCIL_BIT", VK_IMAGE_ASPECT_STENCIL_BIT },
        { "VK_IMAGE_ASPECT_METADATA_BIT", VK_IMAGE_ASPECT_METADATA_BIT },
        { "VK_IMAGE_ASPECT_PLANE_0_BIT", VK_IMAGE_ASPECT_PLANE_0_BIT },
        { "VK_IMAGE_ASPECT_PLANE_1_BIT", VK_IMAGE_ASPECT_PLANE_1_BIT },
        { "VK_IMAGE_ASPECT_PLANE_2_BIT", VK_IMAGE_ASPECT_PLANE_2_BIT },
        { "VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT },
        { "VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT },
        { "VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT },
        { "VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT", VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT },
        { "VK_IMAGE_ASPECT_PLANE_0_BIT_KHR", VK_IMAGE_ASPECT_PLANE_0_BIT_KHR },
        { "VK_IMAGE_ASPECT_PLANE_1_BIT_KHR", VK_IMAGE_ASPECT_PLANE_1_BIT_KHR },
        { "VK_IMAGE_ASPECT_PLANE_2_BIT_KHR", VK_IMAGE_ASPECT_PLANE_2_BIT_KHR }
    };

    VkImageAspectFlags flags = VK_IMAGE_ASPECT_NONE;

    for (const auto& aspect : aspect_flags)
    {
        if (str.find(aspect.first) != std::string::npos)
        {
            flags |= aspect.second;
        }
    }

    return flags;
}

// Every validation failure of the input json is reported through this exception and caught once in
// parse_dump_resources_arg. The message carries the json path of the offending value.
struct RequestError : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

[[noreturn]] static void Fail(const std::string& path, const std::string& what)
{
    throw RequestError("Malformed VDR input json: " + (path.empty() ? std::string() : path + ": ") + what);
}

static std::string FormatKeyPath(const std::string& path, const char* key)
{
    return path.empty() ? std::string(key) : path + "." + key;
}

static std::string FormatElementPath(const std::string& path, size_t i)
{
    return path + "[" + std::to_string(i) + "]";
}

static void ClearDumpResourcesRequest(decode::VulkanReplayOptions& vulkan_replay_options)
{
    vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.clear();
    vulkan_replay_options.RenderPass_Indices.clear();
    vulkan_replay_options.Draw_Indices.clear();
    vulkan_replay_options.DrawSubresources.clear();
    vulkan_replay_options.Dispatch_Indices.clear();
    vulkan_replay_options.DispatchSubresources.clear();
    vulkan_replay_options.TraceRays_Indices.clear();
    vulkan_replay_options.TraceRaysSubresources.clear();
    vulkan_replay_options.Transfer_Indices.clear();
    vulkan_replay_options.TransferSubresources.clear();
    vulkan_replay_options.ExecuteCommands_Indices.clear();
    vulkan_replay_options.dump_resources_request.reset();
}

// Dumping options. Shared by both schemas: the legacy "DumpResourcesOptions" object is parsed leniently (unknown
// keys and values are warnings, as before), the "DumpingOptions" object of the tree schema strictly.

static decode::DumpResourcesDumpingOptions
ParseDumpingOptions(const json& options, const std::string& path, bool strict)
{
    decode::DumpResourcesDumpingOptions result;

    if (!options.is_object())
    {
        Fail(path, "must be a JSON object");
    }

    auto read_bool = [&](const json& value, const std::string& key_path) -> bool {
        if (strict && !value.is_boolean())
        {
            Fail(key_path, "must be a boolean");
        }
        return value.get<bool>();
    };

    for (auto vdr_option = options.begin(); vdr_option != options.end(); ++vdr_option)
    {
        const std::string option_name = vdr_option.key();
        const std::string key_path    = FormatKeyPath(path, option_name.c_str());
        const json&       value       = *vdr_option;

        if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionScale))
        {
            if (strict && (!value.is_number() || value.get<float>() <= 0.0f))
            {
                Fail(key_path, "must be a number greater than 0");
            }
            result.scale = value.get<float>();
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionOutputDir))
        {
            if (strict && !value.is_string())
            {
                Fail(key_path, "must be a string");
            }
            result.output_dir = value.get<std::string>();
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionColorAttachmentIndex))
        {
            if (strict && (!value.is_number_integer() || value.get<int64_t>() < -1))
            {
                Fail(key_path, "must be an integer greater than or equal to -1");
            }
            result.color_attachment_index = value.get<int>();
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionBefore))
        {
            result.dump_before_command = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionDumpDepth))
        {
            result.dump_depth = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionDumpVertexIndexBuffer))
        {
            result.dump_vertex_index_buffer = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionDumpAllDescriptors))
        {
            result.dump_all_descriptors = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionDumpAllImageSubresources))
        {
            result.dump_all_image_subresources = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionDumpRawImages))
        {
            result.dump_raw_images = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionDumpSeparateAlpha))
        {
            result.dump_separate_alpha = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionDumpUnusedVertexBindings))
        {
            result.dump_unused_vertex_bindings = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionImageFormat))
        {
            if (strict && !value.is_string())
            {
                Fail(key_path, "must be \"bmp\" or \"png\"");
            }
            const std::string image_format = value.get<std::string>();

            if (!util::platform::StringCompareNoCase(image_format.c_str(), util::kScreenshotFormatBmp))
            {
                result.image_format = gfxrecon::util::ScreenshotFormat::kBmp;
            }
            else if (!util::platform::StringCompareNoCase(image_format.c_str(), util::kScreenshotFormatPng))
            {
                result.image_format = gfxrecon::util::ScreenshotFormat::kPng;
            }
            else if (strict)
            {
                Fail(key_path, "unrecognized image format \"" + image_format + "\"; must be \"bmp\" or \"png\"");
            }
            else
            {
                GFXRECON_LOG_WARNING("Unrecognized image format \"%s\" in input json.", image_format.c_str());
            }
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionJsonOutputPerCommand))
        {
            result.json_output_per_command = read_bool(value, key_path);
        }
        else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                      gfxrecon::decode::kVDROptionBinaryFileCompressionType))
        {
            if (strict && !value.is_string())
            {
                Fail(key_path, "must be one of \"none\", \"lz4\", \"zlib\", \"zstd\"");
            }
            const std::string compression_type_str = value.get<std::string>();

            if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeNone))
            {
                result.binary_file_compression_type = format::CompressionType::kNone;
            }
            else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeLz4))
            {
                result.binary_file_compression_type = format::CompressionType::kLz4;
            }
            else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeZlib))
            {
                result.binary_file_compression_type = format::CompressionType::kZlib;
            }
            else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeZstd))
            {
                result.binary_file_compression_type = format::CompressionType::kZstd;
            }
            else if (strict)
            {
                Fail(key_path,
                     "unrecognized compression method \"" + compression_type_str +
                         "\"; must be one of \"none\", \"lz4\", \"zlib\", \"zstd\"");
            }
            else
            {
                GFXRECON_LOG_WARNING("Unrecognized compression method \"%s\" in input json.",
                                     compression_type_str.c_str());
            }
        }
        else if (!util::platform::StringCompareNoCase(
                     option_name.c_str(), gfxrecon::decode::kVDROptionDumpBuildAccelerationStructuresInputBuffers))
        {
            result.dump_build_as_input_buffers = read_bool(value, key_path);
        }
        else if (strict)
        {
            Fail(path, "unknown option \"" + option_name + "\"");
        }
        else
        {
            GFXRECON_LOG_WARNING("Unrecognized VDR option detected in input json: %s", option_name.c_str())
        }
    }

    return result;
}

static void ApplyDumpingOptions(const decode::DumpResourcesDumpingOptions& options,
                                decode::VulkanReplayOptions&               vulkan_replay_options)
{
    if (options.scale)
    {
        vulkan_replay_options.dump_resources_scale = *options.scale;
    }
    if (options.output_dir)
    {
        vulkan_replay_options.dump_resources_output_dir = *options.output_dir;
    }
    if (options.color_attachment_index)
    {
        vulkan_replay_options.dump_resources_color_attachment_index = *options.color_attachment_index;
    }
    if (options.dump_before_command)
    {
        vulkan_replay_options.dump_resources_before = *options.dump_before_command;
    }
    if (options.dump_depth)
    {
        vulkan_replay_options.dump_resources_dump_depth = *options.dump_depth;
    }
    if (options.dump_vertex_index_buffer)
    {
        vulkan_replay_options.dump_resources_dump_vertex_index_buffer = *options.dump_vertex_index_buffer;
    }
    if (options.dump_all_descriptors)
    {
        vulkan_replay_options.dump_all_descriptors = *options.dump_all_descriptors;
    }
    if (options.dump_all_image_subresources)
    {
        vulkan_replay_options.dump_resources_dump_all_image_subresources = *options.dump_all_image_subresources;
    }
    if (options.dump_raw_images)
    {
        vulkan_replay_options.dump_resources_dump_raw_images = *options.dump_raw_images;
    }
    if (options.dump_separate_alpha)
    {
        vulkan_replay_options.dump_resources_dump_separate_alpha = *options.dump_separate_alpha;
    }
    if (options.dump_unused_vertex_bindings)
    {
        vulkan_replay_options.dump_resources_dump_unused_vertex_bindings = *options.dump_unused_vertex_bindings;
    }
    if (options.image_format)
    {
        vulkan_replay_options.dump_resources_image_format = *options.image_format;
    }
    if (options.json_output_per_command)
    {
        vulkan_replay_options.dump_resources_json_per_command = *options.json_output_per_command;
    }
    if (options.binary_file_compression_type)
    {
        vulkan_replay_options.dump_resources_binary_file_compression_type = *options.binary_file_compression_type;
    }
    if (options.dump_build_as_input_buffers)
    {
        vulkan_replay_options.dump_resources_dump_build_AS_input_buffers = *options.dump_build_as_input_buffers;
    }
}

// Descriptors and image subresource ranges. Shared by both schemas.

static uint32_t ExtractAndFilterSubresourceRange(const json&        range,
                                                 const std::string& range_name,
                                                 const std::string& alternative_end_range_name,
                                                 const std::string& context,
                                                 bool               strict)
{
    uint32_t count = std::numeric_limits<uint32_t>::max();
    if (range.contains(range_name))
    {
        if (range[range_name].is_number())
        {
            if (strict && !range[range_name].is_number_unsigned())
            {
                Fail(context, range_name + " must be an unsigned integer or " + alternative_end_range_name);
            }
            count = range[range_name];
        }
        else
        {
            if (strict && !range[range_name].is_string())
            {
                Fail(context, range_name + " must be an unsigned integer or " + alternative_end_range_name);
            }
            const std::string level_count_str = range[range_name];
            if (level_count_str.compare(alternative_end_range_name))
            {
                if (strict)
                {
                    Fail(context,
                         "the string \"" + level_count_str + "\" passed as " + range_name +
                             " is not recognized; use an unsigned integer or " + alternative_end_range_name);
                }

                GFXRECON_LOG_WARNING("The string \"%s\", that is being passed as %s for %s, is not recognized and "
                                     "will be ignored (will use 1 instead).",
                                     level_count_str.c_str(),
                                     range_name.c_str(),
                                     context.c_str());
                count = 1;
            }
        }
    }

    return count;
}

static decode::ImageSubresourceRanges
ParseSubresourceRange(const json& range, const std::string& path, const std::string& context, bool strict)
{
    if (!range.is_object())
    {
        Fail(path, "must be a JSON object");
    }

    if (!range.contains("AspectMask") || !range["AspectMask"].is_string())
    {
        Fail(path, "AspectMask is required and must be a string such as \"VK_IMAGE_ASPECT_COLOR_BIT\"");
    }

    const VkImageAspectFlags aspect     = StrToImageAspectFlagBits(range["AspectMask"]);
    const uint32_t           base_level = range.value("BaseMipLevel", 0u);
    const uint32_t           base_layer = range.value("BaseArrayLayer", 0u);
    const uint32_t           base_z     = range.value("BaseZIndex", 0u);

    const uint32_t level_count =
        ExtractAndFilterSubresourceRange(range, "LevelCount", "VK_REMAINING_MIP_LEVELS", context, strict);
    const uint32_t layer_count =
        ExtractAndFilterSubresourceRange(range, "LayerCount", "VK_REMAINING_ARRAY_LAYERS", context, strict);
    const uint32_t z_count = ExtractAndFilterSubresourceRange(range, "ZCount", "REMAINING_Z_INDICES", context, strict);

    return decode::ImageSubresourceRanges{ aspect, base_level, level_count, base_layer, layer_count, base_z, z_count };
}

// Appends the entries of a "Descriptors" array to requested_descriptors, skipping descriptors that are already in it.
static void ParseDescriptors(const json&                                descriptors,
                             decode::Index                              cmd_index,
                             const std::string&                         path,
                             bool                                       strict,
                             decode::DescriptorImageSubresourcesVector& requested_descriptors)
{
    if (!descriptors.is_array())
    {
        Fail(path, "must be a JSON array");
    }

    size_t i = 0;
    for (const auto& sr : descriptors)
    {
        const std::string sr_path = FormatElementPath(path, i++);

        if (!sr.is_object() || !sr.contains("Set") || !sr.contains("Binding") || !sr.contains("ArrayIndex"))
        {
            Fail(sr_path, "a descriptor is an object with \"Set\", \"Binding\" and \"ArrayIndex\"");
        }

        if (strict && (!sr["Set"].is_number_unsigned() || !sr["Binding"].is_number_unsigned() ||
                       !sr["ArrayIndex"].is_number_unsigned()))
        {
            Fail(sr_path, "\"Set\", \"Binding\" and \"ArrayIndex\" must be unsigned integers");
        }

        const uint32_t set     = sr["Set"];
        const uint32_t binding = sr["Binding"];
        const uint32_t ai      = sr["ArrayIndex"];

        const decode::DescriptorLocation desc_tuple(set, binding, ai);

        // DescriptorImageSubresourcesVector is a vector so we need to filter duplicate entries manually
        if (std::find_if(requested_descriptors.begin(),
                         requested_descriptors.end(),
                         [&desc_tuple](const decode::DescriptorImageSubresourcesPair& element) {
                             return element.first == desc_tuple;
                         }) != requested_descriptors.end())
        {
            if (strict)
            {
                Fail(sr_path,
                     "descriptor (set " + std::to_string(set) + ", binding " + std::to_string(binding) +
                         ", array index " + std::to_string(ai) + ") is listed twice");
            }
            continue;
        }

        if (sr.contains("SubresourceRange"))
        {
            const std::string context =
                "command index: " + std::to_string(cmd_index) + ", descriptor set: " + std::to_string(set) +
                ", binding set: " + std::to_string(binding) + " and, array index: " + std::to_string(ai);

            requested_descriptors.emplace_back(
                desc_tuple,
                ParseSubresourceRange(
                    sr["SubresourceRange"], FormatKeyPath(sr_path, "SubresourceRange"), context, strict));
        }
        else
        {
            // If no sub resources have been specified then there are two cases:
            // 1) If it is not an image based descriptor then the subresource range will ne be used
            // 2) If it is an image based descriptor we will dump subresources depending on the value of the
            //    dump_resources_dump_all_image_subresources option
            requested_descriptors.emplace_back(desc_tuple,
                                               decode::ImageSubresourceRanges{ VK_IMAGE_ASPECT_NONE,
                                                                               0,
                                                                               VK_REMAINING_MIP_LEVELS,
                                                                               0,
                                                                               VK_REMAINING_ARRAY_LAYERS,
                                                                               0,
                                                                               decode::REMAINING_Z_INDICES });
        }
    }
}

// Legacy flat schema: parallel BeginCommandBuffer / QueueSubmit / Draw / ... arrays correlated by position.

template <typename json_iterator>
static void ExtractIndexAndDescriptors(const json_iterator                  it,
                                       decode::Index                        bcb_index,
                                       decode::Index                        qs_index,
                                       size_t                               index,
                                       std::vector<decode::CommandIndices>& cmd_indices,
                                       decode::CommandImageSubresource&     command_subresources)
{
    if (it->is_number())
    {
        cmd_indices[index].push_back(*it);
    }
    else
    {
        const decode::Index cmd_index = it->at("Index");
        cmd_indices[index].push_back(cmd_index);

        const decode::CommandLocation command_location(bcb_index, qs_index, cmd_index);

        if (it->contains("Descriptors"))
        {
            auto [requested_descriptors_entry, success] = command_subresources.emplace(
                std::piecewise_construct, std::forward_as_tuple(command_location), std::forward_as_tuple());

            ParseDescriptors(
                it->at("Descriptors"), cmd_index, "Descriptors", false, requested_descriptors_entry->second);
        }
    }
}

static bool ParseLegacyRequest(json& jargs, gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    // Parse VDR input options from json file
    if (jargs.contains(gfxrecon::decode::kVDROptions))
    {
        ApplyDumpingOptions(ParseDumpingOptions(jargs[gfxrecon::decode::kVDROptions], decode::kVDROptions, false),
                            vulkan_replay_options);
    }

    // BeginCommandBuffer and QueueSubmit lists are expected to have the same length
    if (jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER].size() != jargs[decode::DUMP_ARG_QUEUE_SUBMIT].size())
    {
        GFXRECON_LOG_ERROR("Malformed VDR input json: BeginCommandBuffer and QueueSubmit index lists are "
                           "expected to have the same length.");
        return false;
    }

    // Transfer command indices from json to vectors in vulkan_replay_options
    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER].size(); idx0++)
    {
        const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
        const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

        const decode::BeginCmdBufQueueSubmitPair new_pair = std::make_pair(bcb, qs);
        if (std::find(vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.begin(),
                      vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.end(),
                      new_pair) != vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.end())
        {
            GFXRECON_LOG_ERROR("Malformed VDR input json: BeginCommandBuffer and QueueSubmit index pair (%" PRIu64
                               ", %" PRIu64 ") already exist",
                               bcb,
                               qs);
            return false;
        }
        vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.emplace_back(new_pair);
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_DRAW].size(); idx0++)
    {
        const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
        const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

        vulkan_replay_options.Draw_Indices.push_back(std::vector<uint64_t>());
        for (auto it = jargs[decode::DUMP_ARG_DRAW][idx0].begin(); it != jargs[decode::DUMP_ARG_DRAW][idx0].end(); ++it)
        {
            ExtractIndexAndDescriptors(
                it, bcb, qs, idx0, vulkan_replay_options.Draw_Indices, vulkan_replay_options.DrawSubresources);
        }
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_RENDER_PASS].size(); idx0++)
    {
        vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
        for (size_t idx1 = 0; idx1 < jargs[decode::DUMP_ARG_RENDER_PASS][idx0].size(); idx1++)
        {
            vulkan_replay_options.RenderPass_Indices[idx0].push_back(std::vector<uint64_t>());
            for (size_t idx2 = 0; idx2 < jargs[decode::DUMP_ARG_RENDER_PASS][idx0][idx1].size(); idx2++)
            {
                vulkan_replay_options.RenderPass_Indices[idx0][idx1].push_back(
                    jargs[decode::DUMP_ARG_RENDER_PASS][idx0][idx1][idx2]);
            }
        }
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_TRACE_RAYS].size(); idx0++)
    {
        const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
        const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

        vulkan_replay_options.TraceRays_Indices.push_back(std::vector<uint64_t>());
        for (auto it = jargs[decode::DUMP_ARG_TRACE_RAYS][idx0].begin();
             it != jargs[decode::DUMP_ARG_TRACE_RAYS][idx0].end();
             ++it)
        {
            ExtractIndexAndDescriptors(it,
                                       bcb,
                                       qs,
                                       idx0,
                                       vulkan_replay_options.TraceRays_Indices,
                                       vulkan_replay_options.TraceRaysSubresources);
        }
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_DISPATCH].size(); idx0++)
    {
        const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
        const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

        vulkan_replay_options.Dispatch_Indices.push_back(std::vector<uint64_t>());
        for (auto it = jargs[decode::DUMP_ARG_DISPATCH][idx0].begin();
             it != jargs[decode::DUMP_ARG_DISPATCH][idx0].end();
             ++it)
        {
            ExtractIndexAndDescriptors(
                it, bcb, qs, idx0, vulkan_replay_options.Dispatch_Indices, vulkan_replay_options.DispatchSubresources);
        }
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS].size(); ++idx0)
    {
        vulkan_replay_options.ExecuteCommands_Indices.push_back(decode::ExecuteCommands());
        for (size_t idx1 = 0; idx1 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0].size(); idx1++)
        {
            if (!jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1].empty())
            {
                const uint64_t execute_commands_index = jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1][0];
                for (size_t idx2 = 1; idx2 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1].size(); idx2++)
                {
                    const uint64_t secondardy_bcb = jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1][idx2];
                    vulkan_replay_options.ExecuteCommands_Indices[idx0][execute_commands_index].push_back(
                        secondardy_bcb);
                }
            }
        }
    }

    for (size_t idx0 = 0; idx0 < jargs[decode::DUMP_ARG_TRANSFER].size(); idx0++)
    {
        const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
        const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

        vulkan_replay_options.Transfer_Indices.push_back(std::vector<uint64_t>());
        for (auto it = jargs[decode::DUMP_ARG_TRANSFER][idx0].begin();
             it != jargs[decode::DUMP_ARG_TRANSFER][idx0].end();
             ++it)
        {
            ExtractIndexAndDescriptors(
                it, bcb, qs, idx0, vulkan_replay_options.Transfer_Indices, vulkan_replay_options.TransferSubresources);
        }
    }

    return true;
}

// Tree schema: QueueSubmits -> CommandBuffers -> ( ExecuteCommands -> CommandBuffers )* -> Draw / Dispatch /
// TraceRays / Transfer. See vulkan_dump_resources.md.

enum class CommandBufferParent
{
    kQueueSubmit,
    kExecuteCommands
};

static bool IsLegacyKey(const std::string& key)
{
    static const std::string legacy_keys[] = { decode::DUMP_ARG_BEGIN_COMMAND_BUFFER,
                                               decode::DUMP_ARG_QUEUE_SUBMIT,
                                               decode::DUMP_ARG_DRAW,
                                               decode::DUMP_ARG_RENDER_PASS,
                                               decode::DUMP_ARG_DISPATCH,
                                               decode::DUMP_ARG_TRACE_RAYS,
                                               decode::DUMP_ARG_TRANSFER,
                                               decode::DUMP_ARG_EXECUTE_COMMANDS,
                                               decode::kVDROptions };
    return std::find(std::begin(legacy_keys), std::end(legacy_keys), key) != std::end(legacy_keys);
}

static void RequireObject(const json& value, const std::string& path)
{
    if (!value.is_object())
    {
        Fail(path, "must be a JSON object");
    }
}

static void RequireNonEmptyArray(const json& value, const std::string& path)
{
    if (!value.is_array() || value.empty())
    {
        Fail(path, "must be a non-empty JSON array");
    }
}

// Performs a sanity check on a json object that it should contain only objects listed in the allowed list
static void CheckAllowedKeys(const json& object, const std::string& path, std::initializer_list<const char*> allowed)
{
    for (auto it = object.begin(); it != object.end(); ++it)
    {
        const std::string& key = it.key();
        if (std::find_if(allowed.begin(), allowed.end(), [&key](const char* a) { return key == a; }) == allowed.end())
        {
            std::string message = "unknown key \"" + key + "\" (allowed:";
            for (const char* a : allowed)
            {
                message += " ";
                message += a;
            }
            message += ")";
            if (IsLegacyKey(key))
            {
                message +=
                    "; \"" + key + "\" belongs to the legacy flat schema and cannot be mixed with the tree schema";
            }
            Fail(path, message);
        }
    }
}

// A block index of any command.
static decode::Index RequireBlockIndex(const json& value, const std::string& path)
{
    if (!value.is_number_unsigned())
    {
        Fail(path, "must be an unsigned integer block index");
    }
    return value.get<decode::Index>();
}

// The block index of a QueueSubmit, CommandBuffer or ExecuteCommands node.
static decode::Index GetBlockIndex(const json& value, const std::string& path)
{
    const decode::Index index = RequireBlockIndex(value, path);
    if (index == 0)
    {
        Fail(path, "block index 0 is reserved for the state-setup block; use \"StateSetup\" to dump its meta commands");
    }
    return index;
}

static uint32_t RequireUnsigned32(const json& value, const std::string& path)
{
    if (!value.is_number_unsigned() || value.get<uint64_t>() > std::numeric_limits<uint32_t>::max())
    {
        Fail(path, "must be an unsigned 32-bit integer");
    }
    return value.get<uint32_t>();
}

static const json& RequireKey(const json& object, const std::string& path, const char* key)
{
    if (!object.contains(key))
    {
        Fail(path, std::string("\"") + key + "\" is required");
    }
    return object[key];
}

// A feature of the tree schema that the parser accepts but the replayer does not implement yet.
[[noreturn]] static void Unsupported(const std::string& path, const std::string& what)
{
    throw RequestError("Unsupported VDR input json: " + path + ": " + what);
}

static std::vector<decode::Index> ParseIndexOrIndexList(const json& value, const std::string& path)
{
    std::vector<decode::Index> indices;

    if (value.is_number())
    {
        indices.push_back(GetBlockIndex(value, path));
    }
    else if (value.is_array() && !value.empty())
    {
        for (size_t i = 0; i < value.size(); ++i)
        {
            indices.push_back(GetBlockIndex(value[i], FormatElementPath(path, i)));
        }

        std::sort(indices.begin(), indices.end());

        // Check for duplicate entries
        const auto dup = std::adjacent_find(indices.begin(), indices.end());
        if (dup != indices.end())
        {
            Fail(path, "lists block index " + std::to_string(*dup) + " twice");
        }
    }
    else
    {
        Fail(path, "must be a block index or a non-empty list of block indices");
    }

    return indices;
}

static void RejectTopLevelOnlyOptions(const decode::DumpResourcesDumpingOptions& options, const std::string& path)
{
    if (options.json_output_per_command)
    {
        Fail(path,
             std::string(decode::kVDROptionJsonOutputPerCommand) + " can only be set in the top-level DumpingOptions");
    }
    if (options.dump_before_command)
    {
        Fail(path, std::string(decode::kVDROptionBefore) + " can only be set in the top-level DumpingOptions");
    }
    if (options.binary_file_compression_type)
    {
        Fail(path,
             std::string(decode::kVDROptionBinaryFileCompressionType) +
                 " can only be set in the top-level DumpingOptions");
    }
}

static decode::DumpResourcesCommandRequest ParseCommand(const json& value, const std::string& path)
{
    decode::DumpResourcesCommandRequest command;

    if (value.is_number())
    {
        // When just the block index is provided
        command.index = RequireBlockIndex(value, path);
    }
    else if (value.is_object())
    {
        // When index, and/or descriptors and/or dumping options are provided
        CheckAllowedKeys(value,
                         path,
                         { decode::kDumpResourcesRequestIndex,
                           decode::kDumpResourcesRequestDescriptors,
                           decode::kDumpResourcesRequestDumpingOptions });

        const auto& index_key = RequireKey(value, path, decode::kDumpResourcesRequestIndex);
        command.index         = RequireBlockIndex(index_key, FormatKeyPath(path, decode::kDumpResourcesRequestIndex));

        // Parse descriptors
        if (value.contains(decode::kDumpResourcesRequestDescriptors))
        {
            command.has_descriptors = true;
            ParseDescriptors(value[decode::kDumpResourcesRequestDescriptors],
                             command.index,
                             FormatKeyPath(path, decode::kDumpResourcesRequestDescriptors),
                             true,
                             command.descriptors);
        }

        // Parse per command dumping options but warn as unsupported for now
        if (value.contains(decode::kDumpResourcesRequestDumpingOptions))
        {
            const std::string options_path = FormatKeyPath(path, decode::kDumpResourcesRequestDumpingOptions);
            command.dumping_options =
                ParseDumpingOptions(value[decode::kDumpResourcesRequestDumpingOptions], options_path, true);
            RejectTopLevelOnlyOptions(command.dumping_options, options_path);

            if (!command.dumping_options.Empty())
            {
                Unsupported(options_path, "per-command DumpingOptions are not supported by the replayer yet");
            }
        }
    }
    else
    {
        Fail(path, "a command is a block index or an object { \"Index\", \"Descriptors\", \"DumpingOptions\" }");
    }

    return command;
}

static std::vector<decode::DumpResourcesCommandRequest> ParseCommandList(const json& value, const std::string& path)
{
    if (!value.is_array())
    {
        Fail(path, "must be a JSON array of commands");
    }

    std::vector<decode::DumpResourcesCommandRequest> commands;
    for (size_t i = 0; i < value.size(); ++i)
    {
        commands.push_back(ParseCommand(value[i], FormatElementPath(path, i)));
    }

    // Check for duplicate entries
    std::stable_sort(commands.begin(), commands.end(), [](const auto& a, const auto& b) { return a.index < b.index; });
    const auto dup = std::adjacent_find(
        commands.begin(), commands.end(), [](const auto& a, const auto& b) { return a.index == b.index; });
    if (dup != commands.end())
    {
        Fail(path, "lists block index " + std::to_string(dup->index) + " twice");
    }

    return commands;
}

static decode::RenderPassIndices ParseRenderPasses(const json& value, const std::string& path)
{
    if (!value.is_array())
    {
        Fail(path, "must be a list of [begin, nextSubpass..., end] block index ranges");
    }

    decode::RenderPassIndices render_passes;
    for (size_t i = 0; i < value.size(); ++i)
    {
        const std::string range_path = FormatElementPath(path, i);
        const json&       range      = value[i];

        if (!range.is_array())
        {
            Fail(range_path, "must be a [begin, nextSubpass..., end] block index range");
        }
        if (range.empty())
        {
            Fail(range_path,
                 "is empty; omit RenderPasses for a secondary that inherits the render pass of its primary");
        }
        if (range.size() == 1)
        {
            Fail(range_path,
                 "a render pass range holds its begin, one entry per subpass boundary and its end "
                 "([beginRendering, endRendering] for dynamic rendering)");
        }

        std::vector<decode::Index> indices;
        for (size_t j = 0; j < range.size(); ++j)
        {
            indices.push_back(RequireBlockIndex(range[j], FormatElementPath(range_path, j)));
        }

        if (!std::is_sorted(indices.begin(), indices.end()) ||
            std::adjacent_find(indices.begin(), indices.end()) != indices.end())
        {
            Fail(range_path, "block indices must be strictly increasing");
        }

        render_passes.push_back(std::move(indices));
    }

    std::stable_sort(
        render_passes.begin(), render_passes.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
    const auto dup = std::adjacent_find(
        render_passes.begin(), render_passes.end(), [](const auto& a, const auto& b) { return a[0] == b[0]; });
    if (dup != render_passes.end())
    {
        Fail(path, "lists the range beginning at block " + std::to_string((*dup)[0]) + " twice");
    }

    return render_passes;
}

static void ParsePosition(const json&                                value,
                          const std::string&                         path,
                          CommandBufferParent                        parent,
                          decode::DumpResourcesCommandBufferRequest& command_buffer)
{
    if (parent == CommandBufferParent::kQueueSubmit)
    {
        auto parse_pair = [&](const json& pair, const std::string& pair_path) {
            if (!pair.is_array() || pair.size() != 2)
            {
                Fail(pair_path, "must be a [submitIndex, commandBufferIndex] pair");
            }
            command_buffer.submit_positions.emplace_back(RequireUnsigned32(pair[0], FormatElementPath(pair_path, 0)),
                                                         RequireUnsigned32(pair[1], FormatElementPath(pair_path, 1)));
        };

        if (value.is_array() && !value.empty() && value[0].is_number())
        {
            parse_pair(value, path);
        }
        else if (value.is_array() && !value.empty() && value[0].is_array())
        {
            for (size_t i = 0; i < value.size(); ++i)
            {
                parse_pair(value[i], FormatElementPath(path, i));
            }
        }
        else
        {
            Fail(path,
                 "Position under a QueueSubmit must be a [submitIndex, commandBufferIndex] pair or a non-empty "
                 "list of such pairs");
        }

        auto& positions = command_buffer.submit_positions;
        std::sort(positions.begin(), positions.end());
        if (std::adjacent_find(positions.begin(), positions.end()) != positions.end())
        {
            Fail(path, "lists the same appearance twice");
        }
    }
    else
    {
        if (value.is_number())
        {
            command_buffer.execute_positions.push_back(RequireUnsigned32(value, path));
        }
        else if (value.is_array() && !value.empty())
        {
            for (size_t i = 0; i < value.size(); ++i)
            {
                command_buffer.execute_positions.push_back(RequireUnsigned32(value[i], FormatElementPath(path, i)));
            }
        }
        else
        {
            Fail(path,
                 "Position under an ExecuteCommands must be a pCommandBuffers index or a non-empty list of "
                 "pCommandBuffers indices");
        }

        auto& positions = command_buffer.execute_positions;
        std::sort(positions.begin(), positions.end());
        if (std::adjacent_find(positions.begin(), positions.end()) != positions.end())
        {
            Fail(path, "lists the same appearance twice");
        }
    }

    // Warn as unsupported for now
    Unsupported(path,
                "Position is not supported by the replayer yet; omit it to dump the first appearance of the "
                "command buffer");
}

static decode::DumpResourcesResourceRequest ParseResource(const json& value, const std::string& path)
{
    decode::DumpResourcesResourceRequest resource;

    if (value.is_number())
    {
        resource.index = RequireBlockIndex(value, path);
    }
    else if (value.is_object())
    {
        CheckAllowedKeys(value,
                         path,
                         { decode::kDumpResourcesRequestIndex,
                           decode::kDumpResourcesRequestIDs,
                           decode::kDumpResourcesRequestDumpingOptions });

        resource.index = RequireBlockIndex(RequireKey(value, path, decode::kDumpResourcesRequestIndex),
                                           FormatKeyPath(path, decode::kDumpResourcesRequestIndex));

        if (value.contains(decode::kDumpResourcesRequestIDs))
        {
            const std::string ids_path = FormatKeyPath(path, decode::kDumpResourcesRequestIDs);
            const json&       ids      = value[decode::kDumpResourcesRequestIDs];
            if (!ids.is_array())
            {
                Fail(ids_path, "must be a list of capture object IDs or { \"Id\", \"SubresourceRange\" } objects");
            }

            for (size_t i = 0; i < ids.size(); ++i)
            {
                const std::string               id_path = FormatElementPath(ids_path, i);
                const json&                     id      = ids[i];
                decode::DumpResourcesResourceId entry;

                if (id.is_number())
                {
                    entry.id = RequireBlockIndex(id, id_path);
                }
                else if (id.is_object())
                {
                    CheckAllowedKeys(id, id_path, { decode::kDumpResourcesRequestId, "SubresourceRange" });
                    entry.id = RequireBlockIndex(RequireKey(id, id_path, decode::kDumpResourcesRequestId),
                                                 FormatKeyPath(id_path, decode::kDumpResourcesRequestId));
                    if (id.contains("SubresourceRange"))
                    {
                        const std::string range_path = FormatKeyPath(id_path, "SubresourceRange");
                        entry.subresource_range =
                            ParseSubresourceRange(id["SubresourceRange"], range_path, range_path, true);
                    }
                }
                else
                {
                    Fail(id_path, "must be a capture object ID or an object { \"Id\", \"SubresourceRange\" }");
                }

                resource.ids.push_back(std::move(entry));
            }
        }

        if (value.contains(decode::kDumpResourcesRequestDumpingOptions))
        {
            const std::string options_path = FormatKeyPath(path, decode::kDumpResourcesRequestDumpingOptions);
            resource.dumping_options =
                ParseDumpingOptions(value[decode::kDumpResourcesRequestDumpingOptions], options_path, true);
            RejectTopLevelOnlyOptions(resource.dumping_options, options_path);
        }
    }
    else
    {
        Fail(path, "a resource snapshot is a block index or an object { \"Index\", \"IDs\", \"DumpingOptions\" }");
    }

    return resource;
}

static std::vector<decode::DumpResourcesResourceRequest> ParseResourceList(const json& value, const std::string& path)
{
    if (!value.is_array())
    {
        Fail(path, "must be a JSON array of resource snapshots");
    }

    std::vector<decode::DumpResourcesResourceRequest> resources;
    for (size_t i = 0; i < value.size(); ++i)
    {
        resources.push_back(ParseResource(value[i], FormatElementPath(path, i)));
    }

    std::stable_sort(
        resources.begin(), resources.end(), [](const auto& a, const auto& b) { return a.index < b.index; });
    const auto dup = std::adjacent_find(
        resources.begin(), resources.end(), [](const auto& a, const auto& b) { return a.index == b.index; });
    if (dup != resources.end())
    {
        Fail(path, "lists block index " + std::to_string(dup->index) + " twice");
    }

    // Warn as unsupported for now
    if (!resources.empty())
    {
        Unsupported(path, "Resources are not supported by the replayer yet");
    }

    return resources;
}

static decode::DumpResourcesExecuteCommandsRequest ParseExecuteCommands(const json& value, const std::string& path);

static decode::DumpResourcesCommandBufferRequest
ParseCommandBuffer(const json& value, const std::string& path, CommandBufferParent parent)
{
    RequireObject(value, path);
    CheckAllowedKeys(value,
                     path,
                     { decode::kDumpResourcesRequestIndex,
                       decode::kDumpResourcesRequestPosition,
                       decode::kDumpResourcesRequestRenderPasses,
                       decode::kDumpResourcesRequestDraw,
                       decode::kDumpResourcesRequestDispatch,
                       decode::kDumpResourcesRequestTraceRays,
                       decode::kDumpResourcesRequestTransfer,
                       decode::kDumpResourcesRequestExecuteCommands,
                       decode::kDumpResourcesRequestResources });

    decode::DumpResourcesCommandBufferRequest command_buffer;

    const json& index_key = RequireKey(value, path, decode::kDumpResourcesRequestIndex);
    command_buffer.index  = GetBlockIndex(index_key, FormatKeyPath(path, decode::kDumpResourcesRequestIndex));

    // Parse render passes, if any
    if (value.contains(decode::kDumpResourcesRequestRenderPasses))
    {
        command_buffer.render_passes =
            ParseRenderPasses(value[decode::kDumpResourcesRequestRenderPasses],
                              FormatKeyPath(path, decode::kDumpResourcesRequestRenderPasses));
    }

    const std::pair<const char*, std::vector<decode::DumpResourcesCommandRequest>*> command_lists[] = {
        { decode::kDumpResourcesRequestDraw, &command_buffer.draws },
        { decode::kDumpResourcesRequestDispatch, &command_buffer.dispatches },
        { decode::kDumpResourcesRequestTraceRays, &command_buffer.trace_rays },
        { decode::kDumpResourcesRequestTransfer, &command_buffer.transfers },
    };

    // Parse block indices of valid commands
    std::map<decode::Index, const char*> list_of_block;
    for (const auto& [name, list] : command_lists)
    {
        if (!value.contains(name))
        {
            continue;
        }

        *list = ParseCommandList(value[name], FormatKeyPath(path, name));

        for (const auto& command : *list)
        {
            const auto [it, inserted] = list_of_block.emplace(command.index, name);
            if (!inserted)
            {
                Fail(path,
                     "block " + std::to_string(command.index) + " appears in both " + it->second + " and " + name);
            }
        }
    }

    // Parse ExecuteCommands
    if (value.contains(decode::kDumpResourcesRequestExecuteCommands))
    {
        const std::string ec_path = FormatKeyPath(path, decode::kDumpResourcesRequestExecuteCommands);
        const json&       ecs     = value[decode::kDumpResourcesRequestExecuteCommands];
        if (!ecs.is_array())
        {
            Fail(ec_path, "must be a JSON array");
        }

        for (size_t i = 0; i < ecs.size(); ++i)
        {
            command_buffer.execute_commands.push_back(ParseExecuteCommands(ecs[i], FormatElementPath(ec_path, i)));
        }

        // Sort and check for duplicate entries
        auto& ec = command_buffer.execute_commands;
        std::stable_sort(ec.begin(), ec.end(), [](const auto& a, const auto& b) { return a.index < b.index; });
        const auto dup =
            std::adjacent_find(ec.begin(), ec.end(), [](const auto& a, const auto& b) { return a.index == b.index; });
        if (dup != ec.end())
        {
            Fail(ec_path,
                 "lists vkCmdExecuteCommands block " + std::to_string(dup->index) +
                     " twice; put all its command buffers under one entry");
        }
    }

    // Parse Resources
    if (value.contains(decode::kDumpResourcesRequestResources))
    {
        command_buffer.resources = ParseResourceList(value[decode::kDumpResourcesRequestResources],
                                                     FormatKeyPath(path, decode::kDumpResourcesRequestResources));
    }

    if (command_buffer.draws.empty() && command_buffer.dispatches.empty() && command_buffer.trace_rays.empty() &&
        command_buffer.transfers.empty() && command_buffer.execute_commands.empty() && command_buffer.resources.empty())
    {
        GFXRECON_LOG_WARNING("VDR input json: %s: command buffer %" PRIu64 " requests nothing to dump",
                             path.c_str(),
                             command_buffer.index);
    }

    // Parse Position
    if (value.contains(decode::kDumpResourcesRequestPosition))
    {
        ParsePosition(value[decode::kDumpResourcesRequestPosition],
                      FormatKeyPath(path, decode::kDumpResourcesRequestPosition),
                      parent,
                      command_buffer);
    }

    return command_buffer;
}

// Parses the "CommandBuffers" array of a QueueSubmit or ExecuteCommands node.
static std::vector<decode::DumpResourcesCommandBufferRequest>
ParseCommandBuffers(const json& node, const std::string& path, CommandBufferParent parent)
{
    const std::string cbs_path = FormatKeyPath(path, decode::kDumpResourcesRequestCommandBuffers);
    const json&       cbs      = RequireKey(node, path, decode::kDumpResourcesRequestCommandBuffers);
    RequireNonEmptyArray(cbs, cbs_path);

    std::vector<decode::DumpResourcesCommandBufferRequest> command_buffers;
    for (size_t i = 0; i < cbs.size(); ++i)
    {
        command_buffers.push_back(ParseCommandBuffer(cbs[i], FormatElementPath(cbs_path, i), parent));
    }

    std::stable_sort(
        command_buffers.begin(), command_buffers.end(), [](const auto& a, const auto& b) { return a.index < b.index; });
    const auto dup = std::adjacent_find(command_buffers.begin(),
                                        command_buffers.end(),
                                        [](const auto& a, const auto& b) { return a.index == b.index; });
    if (dup != command_buffers.end())
    {
        Fail(cbs_path,
             "command buffer " + std::to_string(dup->index) +
                 " is listed twice; use a Position list to request several appearances of a command buffer");
    }

    return command_buffers;
}

static decode::DumpResourcesExecuteCommandsRequest ParseExecuteCommands(const json& value, const std::string& path)
{
    RequireObject(value, path);
    CheckAllowedKeys(value, path, { decode::kDumpResourcesRequestIndex, decode::kDumpResourcesRequestCommandBuffers });

    const auto& index_key = RequireKey(value, path, decode::kDumpResourcesRequestIndex);

    decode::DumpResourcesExecuteCommandsRequest execute_commands;
    execute_commands.index = GetBlockIndex(index_key, FormatKeyPath(path, decode::kDumpResourcesRequestIndex));
    execute_commands.command_buffers = ParseCommandBuffers(value, path, CommandBufferParent::kExecuteCommands);

    return execute_commands;
}

// Parses the top-level QueueSubmits array into request.queue_submits.
static void ParseQueueSubmits(const json& qss, decode::DumpResourcesRequest& request)
{
    const std::string qss_path = decode::kDumpResourcesRequestQueueSubmits;
    RequireNonEmptyArray(qss, qss_path);

    std::unordered_set<decode::Index> seen;
    for (size_t i = 0; i < qss.size(); ++i)
    {
        const std::string path  = FormatElementPath(qss_path, i);
        const json&       value = qss[i];

        RequireObject(value, path);
        CheckAllowedKeys(
            value, path, { decode::kDumpResourcesRequestIndex, decode::kDumpResourcesRequestCommandBuffers });

        decode::DumpResourcesQueueSubmitRequest queue_submit;
        queue_submit.indices = ParseIndexOrIndexList(RequireKey(value, path, decode::kDumpResourcesRequestIndex),
                                                     FormatKeyPath(path, decode::kDumpResourcesRequestIndex));
        queue_submit.command_buffers = ParseCommandBuffers(value, path, CommandBufferParent::kQueueSubmit);

        for (const decode::Index index : queue_submit.indices)
        {
            if (!seen.insert(index).second)
            {
                Fail(path,
                     "queue submit " + std::to_string(index) +
                         " is listed in more than one QueueSubmits entry; put all its command buffers under one entry");
            }
        }

        request.queue_submits.push_back(std::move(queue_submit));
    }
}

// Parses the new schema
static decode::DumpResourcesRequest ParseTreeRequest(const json& root)
{
    RequireObject(root, "");
    CheckAllowedKeys(root,
                     "",
                     { decode::kDumpResourcesRequestDumpingOptions,
                       decode::kDumpResourcesRequestQueueSubmits,
                       decode::kDumpResourcesRequestStateSetup,
                       decode::kDumpResourcesRequestResources });

    if (!root.contains(decode::kDumpResourcesRequestQueueSubmits) &&
        !root.contains(decode::kDumpResourcesRequestStateSetup) &&
        !root.contains(decode::kDumpResourcesRequestResources))
    {
        Fail("", "at least one of QueueSubmits, StateSetup or Resources is required");
    }

    decode::DumpResourcesRequest request;

    // Parse global DumpingOptions
    if (root.contains(decode::kDumpResourcesRequestDumpingOptions))
    {
        request.dumping_options = ParseDumpingOptions(
            root[decode::kDumpResourcesRequestDumpingOptions], decode::kDumpResourcesRequestDumpingOptions, true);
    }

    // Parse QueueSubmits
    if (root.contains(decode::kDumpResourcesRequestQueueSubmits))
    {
        ParseQueueSubmits(root[decode::kDumpResourcesRequestQueueSubmits], request);
    }

    // Parse StateSetup
    if (root.contains(decode::kDumpResourcesRequestStateSetup))
    {
        const std::string ss_path = decode::kDumpResourcesRequestStateSetup;
        const json&       ss      = root[decode::kDumpResourcesRequestStateSetup];

        RequireObject(ss, ss_path);
        CheckAllowedKeys(ss, ss_path, { decode::kDumpResourcesRequestTransfer });

        const std::string key       = FormatKeyPath(ss_path, decode::kDumpResourcesRequestTransfer);
        const json&       transfers = RequireKey(ss, ss_path, decode::kDumpResourcesRequestTransfer);
        RequireNonEmptyArray(transfers, key);
        request.state_setup_transfers = ParseCommandList(transfers, key);
    }

    // Parse Resources
    if (root.contains(decode::kDumpResourcesRequestResources))
    {
        request.resources =
            ParseResourceList(root[decode::kDumpResourcesRequestResources], decode::kDumpResourcesRequestResources);
    }

    return request;
}

// Lowering of the tree into the per-command-buffer rows the replayer consumes. Every (BeginCommandBuffer,
// QueueSubmit) pair becomes one row; a secondary gets its own row paired with the QueueSubmit of the primary that
// executes it, and the primary's ExecuteCommands row references it.

struct RowInfo
{
    size_t                                           row;
    bool                                             is_secondary;
    const decode::DumpResourcesCommandBufferRequest* source;
};

using RowMap = std::map<decode::BeginCmdBufQueueSubmitPair, RowInfo>;

static decode::CommandIndices CommandIndicesOf(const std::vector<decode::DumpResourcesCommandRequest>& commands)
{
    decode::CommandIndices indices;
    indices.reserve(commands.size());
    for (const auto& command : commands)
    {
        indices.push_back(command.index);
    }
    return indices;
}

static void StoreDescriptors(const std::vector<decode::DumpResourcesCommandRequest>& commands,
                             decode::Index                                           bcb,
                             decode::Index                                           qs,
                             decode::CommandImageSubresource&                        subresources)
{
    for (const auto& command : commands)
    {
        if (command.has_descriptors)
        {
            subresources[decode::CommandLocation(bcb, qs, command.index)] = command.descriptors;
        }
    }
}

static size_t AddRow(const decode::DumpResourcesCommandBufferRequest& cb,
                     decode::Index                                    bcb,
                     decode::Index                                    qs,
                     decode::VulkanReplayOptions&                     options)
{
    options.BeginCommandBufferQueueSubmit_Indices.emplace_back(bcb, qs);
    options.Draw_Indices.push_back(CommandIndicesOf(cb.draws));
    options.Dispatch_Indices.push_back(CommandIndicesOf(cb.dispatches));
    options.TraceRays_Indices.push_back(CommandIndicesOf(cb.trace_rays));
    options.Transfer_Indices.push_back(CommandIndicesOf(cb.transfers));
    options.RenderPass_Indices.push_back(cb.render_passes);
    options.ExecuteCommands_Indices.emplace_back();

    StoreDescriptors(cb.draws, bcb, qs, options.DrawSubresources);
    StoreDescriptors(cb.dispatches, bcb, qs, options.DispatchSubresources);
    StoreDescriptors(cb.trace_rays, bcb, qs, options.TraceRaysSubresources);
    StoreDescriptors(cb.transfers, bcb, qs, options.TransferSubresources);

    return options.BeginCommandBufferQueueSubmit_Indices.size() - 1;
}

struct ParentExecuteCommands
{
    size_t        primary_row;
    decode::Index index;
};

static void EmitCommandBuffer(const decode::DumpResourcesCommandBufferRequest& cb,
                              decode::Index                                    qs,
                              const std::optional<ParentExecuteCommands>&      parent,
                              RowMap&                                          rows,
                              decode::VulkanReplayOptions&                     options)
{
    const decode::BeginCmdBufQueueSubmitPair key(cb.index, qs);

    size_t row;
    bool   merged = false;

    const auto found = rows.find(key);
    if (found == rows.end())
    {
        row = AddRow(cb, cb.index, qs, options);
        rows.emplace(key, RowInfo{ row, parent.has_value(), &cb });
    }
    else
    {
        if (!parent || !found->second.is_secondary)
        {
            Fail("",
                 "command buffer " + std::to_string(cb.index) + " is requested twice for queue submit " +
                     std::to_string(qs));
        }

        if (!(*found->second.source == cb))
        {
            Fail("",
                 "secondary command buffer " + std::to_string(cb.index) +
                     " is executed from several vkCmdExecuteCommands in queue submit " + std::to_string(qs) +
                     " with different dump requests; this is not supported yet, request the same commands under "
                     "each ExecuteCommands entry");
        }

        row    = found->second.row;
        merged = true;
    }

    if (parent)
    {
        // Index-based access: the vectors reallocate while the subtree is emitted.
        auto& secondaries = options.ExecuteCommands_Indices[parent->primary_row][parent->index];
        if (std::find(secondaries.begin(), secondaries.end(), cb.index) != secondaries.end())
        {
            Fail("",
                 "command buffer " + std::to_string(cb.index) + " is listed twice under vkCmdExecuteCommands " +
                     std::to_string(parent->index));
        }
        secondaries.push_back(cb.index);
    }

    if (merged)
    {
        // The identical subtree has been emitted already, including any nested secondaries.
        return;
    }

    for (const auto& ec : cb.execute_commands)
    {
        for (const auto& secondary : ec.command_buffers)
        {
            EmitCommandBuffer(secondary, qs, ParentExecuteCommands{ row, ec.index }, rows, options);
        }
    }
}

template <typename Rows>
static void ClearIfAllRowsEmpty(Rows& rows)
{
    if (std::all_of(rows.begin(), rows.end(), [](const auto& row) { return row.empty(); }))
    {
        rows.clear();
    }
}

// Fills the per-command-buffer index vectors of VulkanReplayOptions (BeginCommandBufferQueueSubmit_Indices,
// Draw/Dispatch/TraceRays/Transfer/RenderPass/ExecuteCommands_Indices and the *Subresources maps) from a parsed tree
// request. Each command buffer node becomes one row per queue submit index it is listed under, secondaries get rows
// of their own paired with the primary's submit index, and StateSetup becomes the (0, 0) row. Typed arrays that end
// up with no entry at all are cleared, as the replayer expects them absent rather than full of empty rows.
static void LowerTreeRequest(const decode::DumpResourcesRequest& request, decode::VulkanReplayOptions& options)
{
    RowMap rows;

    for (const auto& queue_submit : request.queue_submits)
    {
        for (const decode::Index qs : queue_submit.indices)
        {
            for (const auto& cb : queue_submit.command_buffers)
            {
                EmitCommandBuffer(cb, qs, std::nullopt, rows, options);
            }
        }
    }

    if (!request.state_setup_transfers.empty())
    {
        // Zero BeginCommandBuffer and QueueSubmit indices request the meta commands of the state-setup block.
        decode::DumpResourcesCommandBufferRequest state_setup;
        state_setup.index     = 0;
        state_setup.transfers = request.state_setup_transfers;
        AddRow(state_setup, 0, 0, options);
    }

    // A typed array without a single entry must be absent, not a list of empty rows.
    ClearIfAllRowsEmpty(options.Draw_Indices);
    ClearIfAllRowsEmpty(options.Dispatch_Indices);
    ClearIfAllRowsEmpty(options.TraceRays_Indices);
    ClearIfAllRowsEmpty(options.Transfer_Indices);
    ClearIfAllRowsEmpty(options.RenderPass_Indices);
    ClearIfAllRowsEmpty(options.ExecuteCommands_Indices);
}

// Function to parse the --dump-resoures argument, specifically vulkan_replay_options.dump_resources.
// If the text of the argument looks like it is for DX12 dump resources, it quietly returns.

bool parse_dump_resources_arg(gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    bool        dump_resource_option_is_d3d12 = false;
    std::string parse_error_message;

#if defined(D3D12_SUPPORT)
    // Parse dump_resource arg to see if it is for d3d12
    // (i.e. it consists of 3 comma-separated integers)
    std::vector<std::string> values =
        gfxrecon::util::strings::SplitString(vulkan_replay_options.dump_resources_block_indices, ',');
    if (values.size() == 3)
    {
        dump_resource_option_is_d3d12 = true;
        for (int n = 0; n < 3; n++)
        {
            std::string v = values[n];
            dump_resource_option_is_d3d12 &= (!v.empty() && std::all_of(v.begin(), v.end(), ::isdigit));
        }
    }
#endif

    if (vulkan_replay_options.dump_resources_block_indices.empty() || dump_resource_option_is_d3d12)
    {
        // Clear dump resources indices and return if arg is either null or intended for d3d12
        ClearDumpResourcesRequest(vulkan_replay_options);
        return true;
    }

    // Vulkan dump resources expects only a json file
    if (ends_with(to_lower(vulkan_replay_options.dump_resources_block_indices), ".json"))
    {
        std::ifstream dr_json_file(vulkan_replay_options.dump_resources_block_indices, std::ifstream::binary);
        if (!dr_json_file.is_open())
        {
            GFXRECON_LOG_ERROR("Could not open \"%s\" for input",
                               vulkan_replay_options.dump_resources_block_indices.c_str());
            vulkan_replay_options.dumping_resources = false;
            return false;
        }

        ClearDumpResourcesRequest(vulkan_replay_options);

        try
        {
            json jargs;
            dr_json_file >> jargs;

            // A top-level BeginCommandBuffer key selects the legacy flat schema.
            if (jargs.is_object() && jargs.contains(decode::DUMP_ARG_BEGIN_COMMAND_BUFFER))
            {
                GFXRECON_LOG_WARNING("\"%s\" input json is using the old schema which is deprecated.",
                               vulkan_replay_options.dump_resources_block_indices.c_str());

                if (!ParseLegacyRequest(jargs, vulkan_replay_options))
                {
                    ClearDumpResourcesRequest(vulkan_replay_options);
                    vulkan_replay_options.dumping_resources = false;
                    return false;
                }
            }
            else
            {
                decode::DumpResourcesRequest request = ParseTreeRequest(jargs);
                LowerTreeRequest(request, vulkan_replay_options);
                ApplyDumpingOptions(request.dumping_options, vulkan_replay_options);
                vulkan_replay_options.dump_resources_request = std::move(request);
            }
        }
        catch (const RequestError& e)
        {
            GFXRECON_LOG_ERROR("%s", e.what());
            ClearDumpResourcesRequest(vulkan_replay_options);
            vulkan_replay_options.dumping_resources = false;
            return false;
        }
        catch (const std::exception& e)
        {
            GFXRECON_LOG_ERROR("Failed to parse VDR input json \"%s\": %s",
                               vulkan_replay_options.dump_resources_block_indices.c_str(),
                               e.what());
            ClearDumpResourcesRequest(vulkan_replay_options);
            vulkan_replay_options.dumping_resources = false;
            return false;
        }
    }

    bool parse_error = CheckIndicesForErrors(vulkan_replay_options);

    vulkan_replay_options.dumping_resources = !parse_error;
    return !parse_error;
}

GFXRECON_END_NAMESPACE(parse_dump_resources)
GFXRECON_END_NAMESPACE(gfxrecon)
