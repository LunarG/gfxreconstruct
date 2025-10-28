/*
** Copyright (c) 2019-2020 Valve Corporation
** Copyright (c) 2019-2023 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
#define GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H

#include "decode/replay_options.h"

#include "decode/vulkan_resource_allocator.h"
#include "format/format.h"
#include "util/defines.h"

#include <cstdint>
#include <functional>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef std::function<VulkanResourceAllocator*()> CreateResourceAllocator;

// Default log level to use prior to loading settings.
const util::Log::Severity kDefaultLogLevel = util::Log::Severity::kInfoSeverity;

enum class SkipGetFenceStatus
{
    NoSkip,
    SkipUnsuccessful,
    SkipAll,
    COUNT
};

using Index             = uint64_t;
using CommandIndices    = std::vector<Index>;
using RenderPassIndices = std::vector<std::vector<Index>>;
using ExecuteCommands   = std::unordered_map<Index, CommandIndices>;

struct DescriptorLocation
{
    bool const operator==(const DescriptorLocation& other) const
    {
        return set == other.set && binding == other.binding && array_index == other.array_index;
    }

    bool const operator<(const DescriptorLocation& other) const
    {
        if (set == other.set)
        {
            if (binding == other.binding)
            {
                return array_index < other.array_index;
            }
            else
            {
                return binding < other.binding;
            }
        }
        else
        {
            return set < other.set;
        }
    }

    uint32_t set;
    uint32_t binding;
    uint32_t array_index;
};

using CommandImageSubresource =
    std::unordered_map<decode::Index, std::map<DescriptorLocation, VkImageSubresourceRange>>;
using CommandImageSubresourceIterator = CommandImageSubresource::const_iterator;

// Default color attachment index selection for dump resources feature.
// This default value essentially defines to dump all attachments.
static constexpr int kUnspecifiedColorAttachment = -1;

struct VulkanReplayOptions : public ReplayOptions
{
    bool                         enable_vulkan{ true };
    bool                         capture{ false };
    bool                         omit_pipeline_cache_data{ false };
    bool                         use_colorspace_fallback{ false };
    bool                         offscreen_swapchain_frame_boundary{ false };
    util::SwapchainOption        swapchain_option{ util::SwapchainOption::kVirtual };
    util::PresentModeOption      present_mode_option{ util::PresentModeOption::kCapture };
    bool                         virtual_swapchain_skip_blit{ false };
    int32_t                      override_gpu_group_index{ -1 };
    int32_t                      surface_index{ -1 };
    CreateResourceAllocator      create_resource_allocator;
    uint32_t                     screenshot_width, screenshot_height;
    float                        screenshot_scale;
    std::string                  replace_shader_dir;
    SkipGetFenceStatus           skip_get_fence_status{ SkipGetFenceStatus::NoSkip };
    std::vector<util::UintRange> skip_get_fence_ranges;
    bool                         wait_before_present{ false };
    VkFlags                      debug_message_severity{ VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                                    VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT };

    // Dumping resources related configurable replay options
    std::vector<decode::Index> BeginCommandBuffer_Indices;
    std::vector<decode::Index> QueueSubmit_Indices;

    std::vector<RenderPassIndices> RenderPass_Indices;
    std::vector<CommandIndices>    Draw_Indices;
    CommandImageSubresource        DrawSubresources;

    std::vector<CommandIndices> Dispatch_Indices;
    CommandImageSubresource     DispatchSubresources;

    std::vector<CommandIndices> TraceRays_Indices;
    CommandImageSubresource     TraceRaysSubresources;

    // ExecuteCommands block index : vector or BeginCommandBuffer indices of secondary cbs.
    std::vector<ExecuteCommands> ExecuteCommands_Indices;

    std::string            dump_resources_block_indices;
    util::ScreenshotFormat dump_resources_image_format{ util::ScreenshotFormat::kBmp };

    // Flag to quickly check whether the feature is enabled or not
    bool  dumping_resources{ false };
    bool  dump_resources_dump_depth{ false };
    int   dump_resources_color_attachment_index{ kUnspecifiedColorAttachment };
    float dump_resources_scale{ 1.0f };
    bool  dump_resources_dump_vertex_index_buffer{ false };
    bool  dump_resources_json_per_command{ false };
    bool  dump_resources_dump_immutable_resources{ false };
    bool  dump_resources_dump_all_image_subresources{ false };
    bool  dump_resources_dump_raw_images{ false };
    bool  dump_resources_dump_separate_alpha{ false };
    bool  dump_resources_dump_unused_vertex_bindings{ false };

    format::CompressionType dump_resources_binary_file_compression_type{ format::CompressionType::kNone };

    bool preload_measurement_range{ false };

    std::string load_pipeline_cache_filename;
    std::string save_pipeline_cache_filename;
    bool        add_new_pipeline_caches;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_OPTIONS_H
