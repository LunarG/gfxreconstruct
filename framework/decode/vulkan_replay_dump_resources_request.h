/*
** Copyright (c) 2019-2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_REQUEST_H
#define GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_REQUEST_H

#include "format/format.h"
#include "util/defines.h"
#include "util/options.h"

#include <cstdint>
#include <limits>
#include <map>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using Index             = uint64_t;
using CommandIndices    = std::vector<Index>;
using RenderPassIndices = std::vector<std::vector<Index>>;
using ExecuteCommands   = std::unordered_map<Index, CommandIndices>;

struct DescriptorLocation
{
    DescriptorLocation() = delete;

    DescriptorLocation(uint32_t s, uint32_t b, uint32_t ai) : set(s), binding(b), array_index(ai) {}

    DescriptorLocation(const DescriptorLocation& other) :
        set(other.set), binding(other.binding), array_index(other.array_index)
    {}

    bool const operator==(const DescriptorLocation& other) const
    {
        return (set == other.set) && (binding == other.binding) && (array_index == other.array_index);
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

struct CommandLocation
{
    CommandLocation() = delete;

    CommandLocation(Index bcb, Index qs, Index cmd) :
        begin_command_buffer_index(bcb), queue_submit_index(qs), cmd_index(cmd)
    {}

    CommandLocation(const CommandLocation& other) :
        begin_command_buffer_index(other.begin_command_buffer_index), queue_submit_index(other.queue_submit_index),
        cmd_index(other.cmd_index)
    {}

    bool const operator==(const CommandLocation& other) const
    {
        return (begin_command_buffer_index == other.begin_command_buffer_index) &&
               (queue_submit_index == other.queue_submit_index) && (cmd_index == other.cmd_index);
    }

    bool const operator<(const CommandLocation& other) const
    {
        if (begin_command_buffer_index == other.begin_command_buffer_index)
        {
            if (queue_submit_index == other.queue_submit_index)
            {
                return cmd_index < other.cmd_index;
            }
            else
            {
                return queue_submit_index < other.queue_submit_index;
            }
        }
        else
        {
            return begin_command_buffer_index < other.begin_command_buffer_index;
        }
    }

    Index begin_command_buffer_index;
    Index queue_submit_index;
    Index cmd_index;
};

static constexpr uint32_t REMAINING_Z_INDICES = std::numeric_limits<uint32_t>::max();
struct ImageSubresourceRanges
{
    VkImageAspectFlags aspect_mask{ VK_IMAGE_ASPECT_NONE };
    uint32_t           base_mip_level{ 0 };
    uint32_t           level_count{ 0 };
    uint32_t           base_array_layer{ 0 };
    uint32_t           layer_count{ 0 };
    uint32_t           base_z{ 0 };
    uint32_t           z_count{ 0 };

    bool operator==(const ImageSubresourceRanges& other) const = default;
};

using DescriptorImageSubresourcesPair   = std::pair<DescriptorLocation, ImageSubresourceRanges>;
using DescriptorImageSubresourcesVector = std::vector<DescriptorImageSubresourcesPair>;
using CommandImageSubresource           = std::map<CommandLocation, DescriptorImageSubresourcesVector>;
using BeginCmdBufQueueSubmitPair        = std::pair<decode::Index, decode::Index>;

// Keys of the tree-shaped dump resources request. The option keys (kVDROption*) live in
// vulkan_replay_dump_resources_options.h.
static constexpr const char* kDumpResourcesRequestDumpingOptions  = "DumpingOptions";
static constexpr const char* kDumpResourcesRequestQueueSubmits    = "QueueSubmits";
static constexpr const char* kDumpResourcesRequestStateSetup      = "StateSetup";
static constexpr const char* kDumpResourcesRequestResources       = "Resources";
static constexpr const char* kDumpResourcesRequestIndex           = "Index";
static constexpr const char* kDumpResourcesRequestPosition        = "Position";
static constexpr const char* kDumpResourcesRequestCommandBuffers  = "CommandBuffers";
static constexpr const char* kDumpResourcesRequestRenderPasses    = "RenderPasses";
static constexpr const char* kDumpResourcesRequestDraw            = "Draw";
static constexpr const char* kDumpResourcesRequestDispatch        = "Dispatch";
static constexpr const char* kDumpResourcesRequestTraceRays       = "TraceRays";
static constexpr const char* kDumpResourcesRequestTransfer        = "Transfer";
static constexpr const char* kDumpResourcesRequestExecuteCommands = "ExecuteCommands";
static constexpr const char* kDumpResourcesRequestDescriptors     = "Descriptors";
static constexpr const char* kDumpResourcesRequestIDs             = "IDs";
static constexpr const char* kDumpResourcesRequestId              = "Id";

// The DumpingOptions object of a tree-shaped request. Every key is optional: at the top level an absent key keeps
// the default, inside a command it keeps the top-level value.
struct DumpResourcesDumpingOptions
{
    std::optional<float>                   scale;
    std::optional<util::ScreenshotFormat>  image_format;
    std::optional<std::string>             output_dir;
    std::optional<int>                     color_attachment_index;
    std::optional<format::CompressionType> binary_file_compression_type;
    std::optional<bool>                    dump_before_command;
    std::optional<bool>                    dump_depth;
    std::optional<bool>                    dump_vertex_index_buffer;
    std::optional<bool>                    dump_all_descriptors;
    std::optional<bool>                    dump_all_image_subresources;
    std::optional<bool>                    dump_raw_images;
    std::optional<bool>                    dump_separate_alpha;
    std::optional<bool>                    dump_unused_vertex_bindings;
    std::optional<bool>                    json_output_per_command;
    std::optional<bool>                    dump_build_as_input_buffers;

    bool Empty() const
    {
        return !scale && !image_format && !output_dir && !color_attachment_index && !binary_file_compression_type &&
               !dump_before_command && !dump_depth && !dump_vertex_index_buffer && !dump_all_descriptors &&
               !dump_all_image_subresources && !dump_raw_images && !dump_separate_alpha &&
               !dump_unused_vertex_bindings && !json_output_per_command && !dump_build_as_input_buffers;
    }

    bool operator==(const DumpResourcesDumpingOptions& other) const = default;
};

// One entry of a Draw, Dispatch, TraceRays or Transfer list.
struct DumpResourcesCommandRequest
{
    Index index{ 0 };

    // True when the "Descriptors" key was present. An empty list then means "dump no descriptors".
    bool                              has_descriptors{ false };
    DescriptorImageSubresourcesVector descriptors;

    // Overrides for this command only.
    DumpResourcesDumpingOptions dumping_options;

    bool operator==(const DumpResourcesCommandRequest& other) const = default;
};

struct DumpResourcesResourceId
{
    format::HandleId                      id{ 0 };
    std::optional<ImageSubresourceRanges> subresource_range;

    bool operator==(const DumpResourcesResourceId& other) const = default;
};

// "Dump every live image, buffer and acceleration structure right after this block".
struct DumpResourcesResourceRequest
{
    Index index{ 0 };

    // Empty means every live resource.
    std::vector<DumpResourcesResourceId> ids;

    DumpResourcesDumpingOptions dumping_options;

    bool operator==(const DumpResourcesResourceRequest& other) const = default;
};

struct DumpResourcesExecuteCommandsRequest;

// A primary command buffer under a QueueSubmit, or a secondary under an ExecuteCommands.
struct DumpResourcesCommandBufferRequest
{
    // vkBeginCommandBuffer block index.
    Index index{ 0 };

    // Which appearances of this command buffer are meant. Empty means the first appearance.
    // Under a QueueSubmit: pairs of (pSubmits index, pCommandBuffers index).
    std::vector<std::pair<uint32_t, uint32_t>> submit_positions;
    // Under an ExecuteCommands: pCommandBuffers indices.
    std::vector<uint32_t> execute_positions;

    // [begin, nextSubpass..., end] ranges, sorted by begin.
    RenderPassIndices render_passes;

    // Sorted by index, no duplicates.
    std::vector<DumpResourcesCommandRequest> draws;
    std::vector<DumpResourcesCommandRequest> dispatches;
    std::vector<DumpResourcesCommandRequest> trace_rays;
    std::vector<DumpResourcesCommandRequest> transfers;

    std::vector<DumpResourcesExecuteCommandsRequest> execute_commands;
    std::vector<DumpResourcesResourceRequest>        resources;

    // Defined below, once DumpResourcesExecuteCommandsRequest is defined.
    bool operator==(const DumpResourcesCommandBufferRequest& other) const;
};

struct DumpResourcesExecuteCommandsRequest
{
    // vkCmdExecuteCommands block index.
    Index index{ 0 };

    std::vector<DumpResourcesCommandBufferRequest> command_buffers;

    bool operator==(const DumpResourcesExecuteCommandsRequest& other) const = default;
};

inline bool DumpResourcesCommandBufferRequest::operator==(const DumpResourcesCommandBufferRequest& other) const
{
    return (index == other.index) && (submit_positions == other.submit_positions) &&
           (execute_positions == other.execute_positions) && (render_passes == other.render_passes) &&
           (draws == other.draws) && (dispatches == other.dispatches) && (trace_rays == other.trace_rays) &&
           (transfers == other.transfers) && (execute_commands == other.execute_commands) &&
           (resources == other.resources);
}

struct DumpResourcesQueueSubmitRequest
{
    // vkQueueSubmit / vkQueueSubmit2 block indices the command buffers below apply to. Sorted, no duplicates.
    std::vector<Index> indices;

    std::vector<DumpResourcesCommandBufferRequest> command_buffers;

    bool operator==(const DumpResourcesQueueSubmitRequest& other) const = default;
};

// A fully parsed tree-shaped dump resources request.
struct DumpResourcesRequest
{
    // Top-level DumpingOptions: defaults for every command.
    DumpResourcesDumpingOptions dumping_options;

    std::vector<DumpResourcesQueueSubmitRequest> queue_submits;

    // StateSetup.Transfer: meta commands of a trimmed capture's state-setup block.
    std::vector<DumpResourcesCommandRequest> state_setup_transfers;

    // Top-level Resources: snapshots after blocks that are not recorded in a command buffer.
    std::vector<DumpResourcesResourceRequest> resources;

    bool operator==(const DumpResourcesRequest& other) const = default;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REPLAY_DUMP_RESOURCES_REQUEST_H
