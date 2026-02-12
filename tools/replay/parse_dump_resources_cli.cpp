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

#include "decode/vulkan_replay_dump_resources_options.h"
#include "decode/vulkan_replay_options.h"
#include "replay_settings.h"
#include "util/json_util.h"
#include "util/logging.h"
#include "decode/vulkan_pre_process_consumer.h"
#include "util/options.h"
#include "util/platform.h"

#include <cctype>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(parse_dump_resources)

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

static void ExtractVulkanDumpResourcesParameters(const nlohmann::ordered_json           jargs,
                                                 gfxrecon::decode::VulkanReplayOptions& vulkan_replay_options)
{
    if (jargs.contains(gfxrecon::decode::kVDROptions))
    {
        for (auto vdr_option = jargs[gfxrecon::decode::kVDROptions].begin();
             vdr_option != jargs[gfxrecon::decode::kVDROptions].end();
             ++vdr_option)
        {
            const std::string option_name = vdr_option.key();

            if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionScale))
            {
                vulkan_replay_options.dump_resources_scale = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionOutputDir))
            {
                vulkan_replay_options.dump_resources_output_dir = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionColorAttachmentIndex))
            {
                vulkan_replay_options.dump_resources_color_attachment_index = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionBefore))
            {
                vulkan_replay_options.dump_resources_before = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionDumpDepth))
            {
                vulkan_replay_options.dump_resources_dump_depth = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpVertexIndexBuffer))
            {
                vulkan_replay_options.dump_resources_dump_vertex_index_buffer = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpAllDescriptors))
            {
                vulkan_replay_options.dump_all_descriptors = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpAllImageSubresources))
            {
                vulkan_replay_options.dump_resources_dump_all_image_subresources = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpRawImages))
            {
                vulkan_replay_options.dump_resources_dump_raw_images = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpSeparateAlpha))
            {
                vulkan_replay_options.dump_resources_dump_separate_alpha = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionDumpUnusedVertexBindings))
            {
                vulkan_replay_options.dump_resources_dump_unused_vertex_bindings = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(), gfxrecon::decode::kVDROptionImageFormat))
            {
                const std::string image_format = *vdr_option;

                if (!util::platform::StringCompareNoCase(image_format.c_str(), util::kScreenshotFormatBmp))
                {
                    vulkan_replay_options.dump_resources_image_format = gfxrecon::util::ScreenshotFormat::kBmp;
                }
                else if (!util::platform::StringCompareNoCase(image_format.c_str(), util::kScreenshotFormatPng))
                {
                    vulkan_replay_options.dump_resources_image_format = gfxrecon::util::ScreenshotFormat::kPng;
                }
                else
                {
                    GFXRECON_LOG_WARNING("Unrecognized image format \"%s\" in input json.", image_format.c_str());
                }
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionJsonOutputPerCommand))
            {
                vulkan_replay_options.dump_resources_json_per_command = *vdr_option;
            }
            else if (!util::platform::StringCompareNoCase(option_name.c_str(),
                                                          gfxrecon::decode::kVDROptionBinaryFileCompressionType))
            {
                const std::string compression_type_str = *vdr_option;

                if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeNone))
                {
                    vulkan_replay_options.dump_resources_binary_file_compression_type = format::CompressionType::kNone;
                }
                else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeLz4))
                {
                    vulkan_replay_options.dump_resources_binary_file_compression_type = format::CompressionType::kLz4;
                }
                else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeZlib))
                {
                    vulkan_replay_options.dump_resources_binary_file_compression_type = format::CompressionType::kZlib;
                }
                else if (!util::platform::StringCompareNoCase(compression_type_str.c_str(), util::kCompressionTypeZstd))
                {
                    vulkan_replay_options.dump_resources_binary_file_compression_type = format::CompressionType::kZstd;
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
                vulkan_replay_options.dump_resources_dump_build_AS_input_buffers = *vdr_option;
            }
            else
            {
                GFXRECON_LOG_WARNING("Unrecognized VDR option detected in input json: %s", option_name.c_str())
            }
        }
    }
}

template <typename json_iterator>
static void ExtractIndexAndDescriptors(const json_iterator                  it,
                                       decode::Index                        bcb_index,
                                       std::vector<decode::CommandIndices>& cmd_indices,
                                       decode::CommandImageSubresource&     command_subresources)
{
    if (it->is_number())
    {
        cmd_indices[bcb_index].push_back(*it);
    }
    else
    {
        const decode::Index cmd_index = it->at("Index");
        cmd_indices[bcb_index].push_back(cmd_index);

        if (it->contains("Descriptors"))
        {
            const auto& subresources = it->at("Descriptors");
            for (const auto& sr : subresources)
            {
                const uint32_t set     = sr["Set"];
                const uint32_t binding = sr["Binding"];
                const uint32_t ai      = sr["ArrayIndex"];

                VkImageSubresourceRange subresource_range;
                if (sr.contains("SubresourceRange"))
                {
                    const auto&              range      = sr["SubresourceRange"];
                    const VkImageAspectFlags aspect     = StrToImageAspectFlagBits(range["AspectMask"]);
                    const uint32_t           base_level = range["BaseMipLevel"];
                    const uint32_t           base_layer = range["BaseArrayLayer"];

                    uint32_t level_count;
                    if (range["LevelCount"].is_number())
                    {
                        level_count = range["LevelCount"];
                    }
                    else
                    {
                        const std::string level_count_str = range["LevelCount"];
                        if (!level_count_str.compare("VK_REMAINING_MIP_LEVELS"))
                        {
                            level_count = VK_REMAINING_MIP_LEVELS;
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING(
                                "The string \"%s\", that is being passed as \"LevelCount\" for command index: %" PRIu64
                                ", descriptor set: %" PRIu64 ", binding set: %" PRIu64 " and, array index: %" PRIu64
                                ", is not recognized and will be ignored (will use 1 instead).",
                                level_count_str.c_str(),
                                cmd_index,
                                set,
                                binding,
                                ai);
                            level_count = 1;
                        }
                    }

                    uint32_t layer_count;
                    if (range["LayerCount"].is_number())
                    {
                        layer_count = range["LayerCount"];
                    }
                    else
                    {
                        const std::string layer_count_str = range["LayerCount"];
                        if (!layer_count_str.compare("VK_REMAINING_ARRAY_LAYERS"))
                        {
                            layer_count = VK_REMAINING_ARRAY_LAYERS;
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING(
                                "The string \"%s\", that is being passed as \"LayerCount\" for command index: %" PRIu64
                                ", descriptor set: %" PRIu64 ", binding set: %" PRIu64 " and, array index: %" PRIu64
                                ", is not recognized and will be ignored (will use 1 instead).",
                                layer_count_str.c_str(),
                                cmd_index,
                                set,
                                binding,
                                ai);
                            layer_count = 1;
                        }
                    }

                    subresource_range = { aspect, base_level, level_count, base_layer, layer_count };
                }
                else
                {
                    subresource_range = {
                        VK_IMAGE_ASPECT_NONE, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS
                    };
                }
                command_subresources[cmd_index].emplace(decode::DescriptorLocation{ set, binding, ai },
                                                        subresource_range);
            }
        }
    }
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
        vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.clear();
        vulkan_replay_options.Draw_Indices.clear();
        vulkan_replay_options.RenderPass_Indices.clear();
        vulkan_replay_options.Dispatch_Indices.clear();
        vulkan_replay_options.TraceRays_Indices.clear();
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

        nlohmann::ordered_json jargs;
        dr_json_file >> jargs;

        // Parse VDR input options from json file
        ExtractVulkanDumpResourcesParameters(jargs, vulkan_replay_options);

        // BeginCommandBuffer and QueueSubmit lists are expected to have the same length
        if (jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER].size() != jargs[decode::DUMP_ARG_QUEUE_SUBMIT].size())
        {
            GFXRECON_LOG_FATAL("Malformed VDR input json: BeginCommandBuffer and QueueSubmit index lists are "
                               "expected to have the same length.");
            vulkan_replay_options.dumping_resources = false;
            return false;
        }

        // Transfer command indices from json to vectors in vulkan_replay_options
        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER].size(); idx0++)
        {
            const decode::Index qs  = jargs[decode::DUMP_ARG_QUEUE_SUBMIT][idx0];
            const decode::Index bcb = jargs[decode::DUMP_ARG_BEGIN_COMMAND_BUFFER][idx0];

            const decode::BeginCmdBufQueueSubmitPair new_pair = std::make_pair(bcb, qs);
            if (std::find(vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.begin(),
                          vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.end(),
                          new_pair) != vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.end())
            {
                GFXRECON_LOG_FATAL("Malformed VDR input json: BeginCommandBuffer and QueueSubmit index pair (%" PRIu64
                                   ", %" PRIu64 ") already exist",
                                   bcb,
                                   qs);
                vulkan_replay_options.dumping_resources = false;
                return false;
            }
            vulkan_replay_options.BeginCommandBufferQueueSubmit_Indices.emplace_back(new_pair);
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_DRAW].size(); idx0++)
        {
            vulkan_replay_options.Draw_Indices.push_back(std::vector<uint64_t>());
            for (auto it = jargs[decode::DUMP_ARG_DRAW][idx0].begin(); it != jargs[decode::DUMP_ARG_DRAW][idx0].end();
                 ++it)
            {
                ExtractIndexAndDescriptors(
                    it, idx0, vulkan_replay_options.Draw_Indices, vulkan_replay_options.DrawSubresources);
            }
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_RENDER_PASS].size(); idx0++)
        {
            vulkan_replay_options.RenderPass_Indices.push_back(std::vector<std::vector<uint64_t>>());
            for (int idx1 = 0; idx1 < jargs[decode::DUMP_ARG_RENDER_PASS][idx0].size(); idx1++)
            {
                vulkan_replay_options.RenderPass_Indices[idx0].push_back(std::vector<uint64_t>());
                for (int idx2 = 0; idx2 < jargs[decode::DUMP_ARG_RENDER_PASS][idx0][idx1].size(); idx2++)
                {
                    vulkan_replay_options.RenderPass_Indices[idx0][idx1].push_back(
                        jargs[decode::DUMP_ARG_RENDER_PASS][idx0][idx1][idx2]);
                }
            }
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_TRACE_RAYS].size(); idx0++)
        {
            vulkan_replay_options.TraceRays_Indices.push_back(std::vector<uint64_t>());
            for (auto it = jargs[decode::DUMP_ARG_TRACE_RAYS][idx0].begin();
                 it != jargs[decode::DUMP_ARG_TRACE_RAYS][idx0].end();
                 ++it)
            {
                ExtractIndexAndDescriptors(
                    it, idx0, vulkan_replay_options.TraceRays_Indices, vulkan_replay_options.TraceRaysSubresources);
            }
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_DISPATCH].size(); idx0++)
        {
            vulkan_replay_options.Dispatch_Indices.push_back(std::vector<uint64_t>());
            for (auto it = jargs[decode::DUMP_ARG_DISPATCH][idx0].begin();
                 it != jargs[decode::DUMP_ARG_DISPATCH][idx0].end();
                 ++it)
            {
                ExtractIndexAndDescriptors(
                    it, idx0, vulkan_replay_options.Dispatch_Indices, vulkan_replay_options.DispatchSubresources);
            }
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS].size(); ++idx0)
        {
            vulkan_replay_options.ExecuteCommands_Indices.push_back(decode::ExecuteCommands());
            for (int idx1 = 0; idx1 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0].size(); idx1++)
            {
                if (!jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1].empty())
                {
                    const uint64_t execute_commands_index = jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1][0];
                    for (int idx2 = 1; idx2 < jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1].size(); idx2++)
                    {
                        const uint64_t secondardy_bcb = jargs[decode::DUMP_ARG_EXECUTE_COMMANDS][idx0][idx1][idx2];
                        vulkan_replay_options.ExecuteCommands_Indices[idx0][execute_commands_index].push_back(
                            secondardy_bcb);
                    }
                }
            }
        }

        for (int idx0 = 0; idx0 < jargs[decode::DUMP_ARG_TRANSFER].size(); idx0++)
        {
            vulkan_replay_options.Transfer_Indices.push_back(std::vector<uint64_t>());
            for (auto it = jargs[decode::DUMP_ARG_TRANSFER][idx0].begin();
                 it != jargs[decode::DUMP_ARG_TRANSFER][idx0].end();
                 ++it)
            {
                ExtractIndexAndDescriptors(
                    it, idx0, vulkan_replay_options.Transfer_Indices, vulkan_replay_options.TraceRaysSubresources);
            }
        }
    }

    bool parse_error = CheckIndicesForErrors(vulkan_replay_options);

    vulkan_replay_options.dumping_resources = !parse_error;
    return !parse_error;
}

GFXRECON_END_NAMESPACE(parse_dump_resources)
GFXRECON_END_NAMESPACE(gfxrecon)
