/*
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_replay_dump_resources_json.h"
#include "format/format.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "vulkan_replay_dump_resources.h"
#include "util/logging.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>
#if !defined(WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesBase::VulkanReplayDumpResourcesBase(const VulkanReplayOptions& options,
                                                             CommonObjectInfoTable&     object_info_table) :
    QueueSubmit_indices_(options.QueueSubmit_Indices),
    recording_(false), dump_resources_before_(options.dump_resources_before), object_info_table_(object_info_table),
    output_json_per_command(options.dump_resources_json_per_command), dump_json_(options)
{
    capture_filename = std::filesystem::path(options.capture_filename).stem().string();

    if (!options.Draw_Indices.size() && !options.Dispatch_Indices.size() && !options.TraceRays_Indices.size())
    {
        return;
    }

    if (!options.dump_resources_json_per_command)
    {
        dump_json_.Open(options.capture_filename, options.dump_resources_output_dir);
    }

    for (size_t i = 0; i < options.BeginCommandBuffer_Indices.size(); ++i)
    {
        const uint64_t bcb_index = options.BeginCommandBuffer_Indices[i];

        if (i < options.Draw_Indices.size() && options.Draw_Indices[i].size())
        {
            assert(options.RenderPass_Indices[i].size());

            draw_call_contexts.emplace(bcb_index,
                                       DrawCallsDumpingContext(options.Draw_Indices[i],
                                                               options.RenderPass_Indices[i],
                                                               object_info_table,
                                                               options,
                                                               dump_json_,
                                                               capture_filename));
        }

        if ((i < options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size()) ||
            (i < options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size()))
        {
            dispatch_ray_contexts.emplace(bcb_index,
                                          DispatchTraceRaysDumpingContext(
                                              (options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                                  ? options.Dispatch_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                                  ? options.TraceRays_Indices[i]
                                                  : std::vector<uint64_t>(),
                                              object_info_table_,
                                              options,
                                              dump_json_,
                                              capture_filename));
        }
    }
}

VulkanReplayDumpResourcesBase::~VulkanReplayDumpResourcesBase()
{
    Release();
}

void VulkanReplayDumpResourcesBase::Release()
{
    dump_json_.Close();
    draw_call_contexts.clear();
    dispatch_ray_contexts.clear();
    cmd_buf_begin_map_.clear();
    QueueSubmit_indices_.clear();

    recording_ = false;
}

DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    auto begin_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (begin_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto context_entry = draw_call_contexts.find(begin_entry->second);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

DrawCallsDumpingContext* VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

const DrawCallsDumpingContext* VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = draw_call_contexts.find(bcb_id);
    if (context_entry == draw_call_contexts.end())
    {
        return nullptr;
    }

    const DrawCallsDumpingContext* context = &context_entry->second;
    return context;
}

DispatchTraceRaysDumpingContext* VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id)
{
    auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

const DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const
{
    const auto context_entry = dispatch_ray_contexts.find(bcb_id);
    if (context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &context_entry->second;
    return context;
}

DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

const DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    const auto bcb_entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (bcb_entry == cmd_buf_begin_map_.end())
    {
        return nullptr;
    }

    const auto dr_context_entry = dispatch_ray_contexts.find(bcb_entry->second);
    if (dr_context_entry == dispatch_ray_contexts.end())
    {
        return nullptr;
    }

    const DispatchTraceRaysDumpingContext* context = &dr_context_entry->second;
    return context;
}

VkResult VulkanReplayDumpResourcesBase::CloneCommandBuffer(uint64_t                 bcb_index,
                                                           VulkanCommandBufferInfo* original_command_buffer_info,
                                                           const encode::VulkanDeviceTable*   device_table,
                                                           const encode::VulkanInstanceTable* inst_table)

{
    assert(device_table);
    assert(inst_table);

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(bcb_index);
    if (dc_context != nullptr)
    {
        VkResult res = dc_context->CloneCommandBuffer(original_command_buffer_info, device_table, inst_table);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Cloning command buffer for dumping draw calls failed (%s).",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }

        cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        recording_                                               = true;
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(bcb_index);
    if (dr_context != nullptr)
    {
        VkResult res = dr_context->CloneCommandBuffer(original_command_buffer_info, device_table, inst_table);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Cloning command buffer for dumping compute/ray tracing failed (%s).",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }

        cmd_buf_begin_map_[original_command_buffer_info->handle] = bcb_index;
        recording_                                               = true;
    }

    return VK_SUCCESS;
}

void VulkanReplayDumpResourcesBase::OverrideCmdDraw(const ApiCallInfo& call_info,
                                                    PFN_vkCmdDraw      func,
                                                    VkCommandBuffer    original_command_buffer,
                                                    uint32_t           vertex_count,
                                                    uint32_t           instance_count,
                                                    uint32_t           first_vertex,
                                                    uint32_t           first_instance)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);

        dc_context->InsertNewDrawParameters(dc_index, vertex_count, instance_count, first_vertex, first_instance);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, vertex_count, instance_count, first_vertex, first_instance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, vertex_count, instance_count, first_vertex, first_instance);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);

        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdDrawIndexed func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           uint32_t             index_count,
                                                           uint32_t             instance_count,
                                                           uint32_t             first_index,
                                                           int32_t              vertexOffset,
                                                           uint32_t             first_instance)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    // Copy vertex attribute info
    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndexedParameters(
            dc_index, index_count, instance_count, first_index, vertexOffset, first_instance);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, index_count, instance_count, first_index, vertexOffset, first_instance);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, index_count, instance_count, first_index, vertexOffset, first_instance);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirect(const ApiCallInfo&      call_info,
                                                            PFN_vkCmdDrawIndirect   func,
                                                            VkCommandBuffer         original_command_buffer,
                                                            const VulkanBufferInfo* buffer_info,
                                                            VkDeviceSize            offset,
                                                            uint32_t                draw_count,
                                                            uint32_t                stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    // Copy vertex attribute info
    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndirectParameters(dc_index, buffer_info, offset, draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirect(const ApiCallInfo&           call_info,
                                                                   PFN_vkCmdDrawIndexedIndirect func,
                                                                   VkCommandBuffer              original_command_buffer,
                                                                   const VulkanBufferInfo*      buffer_info,
                                                                   VkDeviceSize                 offset,
                                                                   uint32_t                     draw_count,
                                                                   uint32_t                     stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndexedIndirectParameters(dc_index, buffer_info, offset, draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                                                 PFN_vkCmdDrawIndirectCount func,
                                                                 VkCommandBuffer            original_command_buffer,
                                                                 const VulkanBufferInfo*    buffer_info,
                                                                 VkDeviceSize               offset,
                                                                 const VulkanBufferInfo*    count_buffer_info,
                                                                 VkDeviceSize               count_buffer_offset,
                                                                 uint32_t                   max_draw_count,
                                                                 uint32_t                   stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewIndirectCountParameters(
            dc_index, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCount(const ApiCallInfo&                call_info,
                                                                        PFN_vkCmdDrawIndexedIndirectCount func,
                                                                        VkCommandBuffer         original_command_buffer,
                                                                        const VulkanBufferInfo* buffer_info,
                                                                        VkDeviceSize            offset,
                                                                        const VulkanBufferInfo* count_buffer_info,
                                                                        VkDeviceSize            count_buffer_offset,
                                                                        uint32_t                max_draw_count,
                                                                        uint32_t                stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndexedIndirectCountParameters(
            dc_index, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndirectCountKHR(const ApiCallInfo&            call_info,
                                                                    PFN_vkCmdDrawIndirectCountKHR func,
                                                                    VkCommandBuffer         original_command_buffer,
                                                                    const VulkanBufferInfo* buffer_info,
                                                                    VkDeviceSize            offset,
                                                                    const VulkanBufferInfo* count_buffer_info,
                                                                    VkDeviceSize            count_buffer_offset,
                                                                    uint32_t                max_draw_count,
                                                                    uint32_t                stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndirectCountKHRParameters(
            dc_index, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                                           PFN_vkCmdDrawIndexedIndirectCountKHR func,
                                                                           VkCommandBuffer original_command_buffer,
                                                                           const VulkanBufferInfo* buffer_info,
                                                                           VkDeviceSize            offset,
                                                                           const VulkanBufferInfo* count_buffer_info,
                                                                           VkDeviceSize            count_buffer_offset,
                                                                           uint32_t                max_draw_count,
                                                                           uint32_t                stride)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t           dc_index   = call_info.index;
    const bool               must_dump  = MustDumpDrawCall(original_command_buffer, dc_index);
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);

    // Finalize draw call command buffer before the actual draw call in order
    // to handle dumping render targets before the draw call
    if (dump_resources_before_ && must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }

    if (dc_context != nullptr && must_dump)
    {
        dc_context->InsertNewDrawIndexedIndirectCountKHRParameters(
            dc_index, buffer_info, offset, count_buffer_info, count_buffer_offset, max_draw_count, stride);
        dc_context->CopyVertexInputStateInfo(dc_index);
        dc_context->SnapshotBoundDescriptors(dc_index);
        dc_context->CopyDrawIndirectParameters(dc_index);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it, buffer_info->handle, offset, count_buffer_info->handle, count_buffer_offset, max_draw_count, stride);
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer,
             buffer_info->handle,
             offset,
             count_buffer_info->handle,
             count_buffer_offset,
             max_draw_count,
             stride);
    }

    if (must_dump)
    {
        assert(dc_context != nullptr);
        dc_context->FinalizeCommandBuffer();
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass                             func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const VulkanFramebufferInfo* framebuffer_info = object_info_table_.GetVkFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const VulkanRenderPassInfo* render_pass_info = object_info_table_.GetVkRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   contents);
        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass2(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass2                            func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>*    pSubpassBeginInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
        auto       framebuffer_id        = render_pass_info_meta->framebuffer;
        auto       render_pass_id        = render_pass_info_meta->renderPass;

        const VulkanFramebufferInfo* framebuffer_info = object_info_table_.GetVkFramebufferInfo(framebuffer_id);
        assert(framebuffer_info);

        const VulkanRenderPassInfo* render_pass_info = object_info_table_.GetVkRenderPassInfo(render_pass_id);
        assert(render_pass_info);

        // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::BeginRenderPass
        VkResult res = dc_context->BeginRenderPass(render_pass_info,
                                                   pRenderPassBegin->GetPointer()->clearValueCount,
                                                   pRenderPassBegin->GetPointer()->pClearValues,
                                                   framebuffer_info,
                                                   pRenderPassBegin->GetPointer()->renderArea,
                                                   pSubpassBeginInfo->GetPointer()->contents);

        assert(res == VK_SUCCESS);
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdNextSubpass func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           VkSubpassContents    contents)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    // Do not record NextSubpass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallsDumpingContext::NextSubpass
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        dc_context->NextSubpass(contents);
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, contents);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, contents);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdNextSubpass2(
    const ApiCallInfo&                                call_info,
    PFN_vkCmdNextSubpass2                             func,
    VkCommandBuffer                                   original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>*   pSubpassEndInfo)
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record NextSubpass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::NextSubpass
        dc_context->NextSubpass(pSubpassBeginInfo->GetPointer()->contents);
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                                             PFN_vkCmdEndRenderPass func,
                                                             VkCommandBuffer        original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdEndRenderPass2                         func,
    VkCommandBuffer                                 original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    assert(IsRecording(original_command_buffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->ShouldHandleRenderPass(call_info.index))
    {
        // Do not record EndRenderPass commands in current DrawCall context command buffers.
        // It will be handled by DrawCallsDumpingContext::EndRenderPass
        dc_context->EndRenderPass();
    }
    else if (dc_context != nullptr)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pSubpassEndInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pSubpassEndInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindPipeline(const ApiCallInfo&        call_info,
                                                            PFN_vkCmdBindPipeline     func,
                                                            VkCommandBuffer           original_command_buffer,
                                                            VkPipelineBindPoint       pipelineBindPoint,
                                                            const VulkanPipelineInfo* pipeline)
{
    assert(pipeline);
    assert(IsRecording(original_command_buffer));

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pipelineBindPoint, pipeline->handle);
        }

        DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline->handle);

        DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
        assert(context);
        context->BindPipeline(pipelineBindPoint, pipeline);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindDescriptorSets(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdBindDescriptorSets func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  VkPipelineBindPoint         pipeline_bind_point,
                                                                  const VulkanPipelineLayoutInfo* layout_info,
                                                                  uint32_t                        first_set,
                                                                  uint32_t                        descriptor_sets_count,
                                                                  const format::HandleId*         descriptor_sets_ids,
                                                                  uint32_t                        dynamicOffsetCount,
                                                                  const uint32_t*                 pDynamicOffsets)
{
    assert(IsRecording(original_command_buffer));
    assert(descriptor_sets_ids);

    PipelineBindPoints           bind_point = VkPipelineBindPointToPipelineBindPoint(pipeline_bind_point);
    std::vector<VkDescriptorSet> desc_set_handles(descriptor_sets_count, VK_NULL_HANDLE);
    std::vector<const VulkanDescriptorSetInfo*> desc_set_infos(descriptor_sets_count, nullptr);

    for (uint32_t i = 0; i < descriptor_sets_count; ++i)
    {
        const VulkanDescriptorSetInfo* desc_set_info =
            object_info_table_.GetVkDescriptorSetInfo(descriptor_sets_ids[i]);
        assert(desc_set_info);
        desc_set_infos[i]   = desc_set_info;
        desc_set_handles[i] = desc_set_info->handle;
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context)
    {
        dc_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }

    CommandBufferIterator first, last;
    GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    for (CommandBufferIterator it = first; it < last; ++it)
    {
        func(*it,
             pipeline_bind_point,
             layout_info->handle,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    VkCommandBuffer dr_cmd_buf = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dr_cmd_buf != VK_NULL_HANDLE)
    {
        func(dr_cmd_buf,
             pipeline_bind_point,
             layout_info->handle,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context)
    {
        dr_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindIndexBuffer(const ApiCallInfo&       call_info,
                                                               PFN_vkCmdBindIndexBuffer func,
                                                               VkCommandBuffer          original_command_buffer,
                                                               const VulkanBufferInfo*  buffer,
                                                               VkDeviceSize             offset,
                                                               VkIndexType              indexType)
{
    // buffer can be VK_NULL_HANDLE/NULL
    VkBuffer buffer_handle = buffer != nullptr ? buffer->handle : VK_NULL_HANDLE;

    CommandBufferIterator first, last;
    bool                  found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    if (found)
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_handle, offset, indexType);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer_handle, offset, indexType);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr)
    {
        dc_context->BindIndexBuffer(call_info.index, buffer, offset, indexType);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindIndexBuffer2KHR(const ApiCallInfo&           call_info,
                                                                   PFN_vkCmdBindIndexBuffer2KHR func,
                                                                   VkCommandBuffer              original_command_buffer,
                                                                   const VulkanBufferInfo*      buffer,
                                                                   VkDeviceSize                 offset,
                                                                   VkDeviceSize                 size,
                                                                   VkIndexType                  indexType)
{
    // buffer can be VK_NULL_HANDLE/NULL
    VkBuffer buffer_handle = buffer != nullptr ? buffer->handle : VK_NULL_HANDLE;

    CommandBufferIterator first, last;
    bool                  found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    if (found)
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_handle, offset, size, indexType);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer_handle, offset, size, indexType);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr)
    {
        dc_context->BindIndexBuffer(call_info.index, buffer, offset, indexType, size);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindVertexBuffers(const ApiCallInfo&         call_info,
                                                                 PFN_vkCmdBindVertexBuffers func,
                                                                 VkCommandBuffer            original_command_buffer,
                                                                 uint32_t                   firstBinding,
                                                                 uint32_t                   bindingCount,
                                                                 const format::HandleId*    buffer_ids,
                                                                 const VkDeviceSize*        pOffsets)
{
    CommandBufferIterator first, last;
    bool                  found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    VkCommandBuffer       dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);

    std::vector<const VulkanBufferInfo*> buffer_infos(bindingCount, nullptr);
    std::vector<VkBuffer>                buffer_handles(bindingCount, VK_NULL_HANDLE);
    if (found || dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            // Buffer can be VK_NULL_HANDLE
            const VulkanBufferInfo* buffer_info = object_info_table_.GetVkBufferInfo(buffer_ids[i]);

            buffer_infos[i]   = buffer_info;
            buffer_handles[i] = buffer_info != nullptr ? buffer_info->handle : VK_NULL_HANDLE;
        }
    }

    if (found)
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
        }
    }

    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
    }

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && bindingCount)
    {
        assert(buffer_infos.size() == bindingCount);
        dc_context->BindVertexBuffers(call_info.index, firstBinding, buffer_infos, pOffsets);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdSetVertexInputEXT(
    const ApiCallInfo&                                                   call_info,
    PFN_vkCmdSetVertexInputEXT                                           func,
    VkCommandBuffer                                                      original_command_buffer,
    uint32_t                                                             vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>*   pVertexBindingDescriptions,
    uint32_t                                                             vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    const VkVertexInputBindingDescription2EXT* in_pVertexBindingDescriptions = pVertexBindingDescriptions->GetPointer();
    const VkVertexInputAttributeDescription2EXT* in_pVertexAttributeDescriptions =
        pVertexAttributeDescriptions->GetPointer();

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it,
                 vertexBindingDescriptionCount,
                 in_pVertexBindingDescriptions,
                 vertexAttributeDescriptionCount,
                 in_pVertexAttributeDescriptions);
        }

        DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        dc_context->SetVertexInput(vertexBindingDescriptionCount,
                                   in_pVertexBindingDescriptions,
                                   vertexAttributeDescriptionCount,
                                   in_pVertexAttributeDescriptions);
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer,
             vertexBindingDescriptionCount,
             in_pVertexBindingDescriptions,
             vertexAttributeDescriptionCount,
             in_pVertexAttributeDescriptions);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindVertexBuffers2(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdBindVertexBuffers2 func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  uint32_t                    firstBinding,
                                                                  uint32_t                    bindingCount,
                                                                  const format::HandleId*     pBuffers_ids,
                                                                  const VkDeviceSize*         pOffsets,
                                                                  const VkDeviceSize*         pSizes,
                                                                  const VkDeviceSize*         pStrides)
{
    CommandBufferIterator first, last;
    bool                  dc_found = GetDrawCallActiveCommandBuffers(original_command_buffer, first, last);
    VkCommandBuffer       dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);

    std::vector<VkBuffer> buffer_handles(bindingCount);
    if (dc_found || dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            const VulkanBufferInfo* buffer_info = object_info_table_.GetVkBufferInfo(pBuffers_ids[i]);
            buffer_handles[i]                   = (buffer_info != nullptr) ? buffer_info->handle : VK_NULL_HANDLE;
        }
    }

    if (dc_found)
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, firstBinding, bindingCount, buffer_handles.data(), pOffsets, pSizes, pStrides);
        }

        DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        if (dc_context != nullptr && bindingCount)
        {
            assert(pBuffers_ids);
            assert(pOffsets);
            assert(pSizes);
            assert(pStrides);

            std::vector<const VulkanBufferInfo*> buffer_infos(bindingCount);

            for (uint32_t i = 0; i < bindingCount; ++i)
            {
                const VulkanBufferInfo* buffer_info = object_info_table_.GetVkBufferInfo(pBuffers_ids[i]);

                buffer_infos[i] = buffer_info;
            }

            dc_context->BindVertexBuffers2(call_info.index, firstBinding, buffer_infos, pOffsets, pSizes, pStrides);
        }
    }

    if (dispatch_rays_command_buffer)
    {
        func(dispatch_rays_command_buffer,
             firstBinding,
             bindingCount,
             buffer_handles.data(),
             pOffsets,
             pSizes,
             pStrides);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                        PFN_vkCmdDispatch  func,
                                                        VkCommandBuffer    original_command_buffer,
                                                        uint32_t           groupCountX,
                                                        uint32_t           groupCountY,
                                                        uint32_t           groupCountZ)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t                   disp_index = call_info.index;
    const bool                       must_dump  = MustDumpDispatch(original_command_buffer, disp_index);
    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (must_dump)
    {
        dr_context->InsertNewDispatchParameters(disp_index, groupCountX, groupCountY, groupCountZ);
    }

    if (dump_resources_before_ && must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneDispatchMutableResources(disp_index, true);
        dr_context->FinalizeCommandBuffer(true);
    }

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, groupCountX, groupCountY, groupCountZ);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneDispatchMutableResources(disp_index, false);
        dr_context->SnapshotBoundDescriptorsDispatch(disp_index);
        dr_context->FinalizeCommandBuffer(true);
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                                                PFN_vkCmdDispatchIndirect func,
                                                                VkCommandBuffer           original_command_buffer,
                                                                const VulkanBufferInfo*   buffer_info,
                                                                VkDeviceSize              offset)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t                   disp_index = call_info.index;
    const bool                       must_dump  = MustDumpDispatch(original_command_buffer, disp_index);
    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (must_dump)
    {
        dr_context->InsertNewDispatchParameters(disp_index, buffer_info, offset);
    }

    if (dump_resources_before_ && must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneDispatchMutableResources(disp_index, true);
        dr_context->FinalizeCommandBuffer(true);
    }

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_info->handle, offset);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, buffer_info->handle, offset);
    }

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneDispatchMutableResources(disp_index, false);
        dr_context->CopyDispatchIndirectParameters(disp_index);
        dr_context->SnapshotBoundDescriptorsDispatch(disp_index);
        dr_context->FinalizeCommandBuffer(true);
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysKHR(
    const ApiCallInfo&                                             call_info,
    PFN_vkCmdTraceRaysKHR                                          func,
    VkCommandBuffer                                                original_command_buffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                                       width,
    uint32_t                                                       height,
    uint32_t                                                       depth)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t                   tr_index   = call_info.index;
    const bool                       must_dump  = MustDumpTraceRays(original_command_buffer, tr_index);
    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->InsertNewTraceRaysParameters(tr_index,
                                                 in_pRaygenShaderBindingTable,
                                                 in_pMissShaderBindingTable,
                                                 in_pHitShaderBindingTable,
                                                 in_pCallableShaderBindingTable,
                                                 width,
                                                 height,
                                                 depth);
    }

    if (dump_resources_before_ && must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, true);
        dr_context->FinalizeCommandBuffer(true);
    }

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it,
                 in_pRaygenShaderBindingTable,
                 in_pMissShaderBindingTable,
                 in_pHitShaderBindingTable,
                 in_pCallableShaderBindingTable,
                 width,
                 height,
                 depth);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer,
             in_pRaygenShaderBindingTable,
             in_pMissShaderBindingTable,
             in_pHitShaderBindingTable,
             in_pCallableShaderBindingTable,
             width,
             height,
             depth);
    }

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, false);
        dr_context->SnapshotBoundDescriptorsTraceRays(tr_index);
        dr_context->FinalizeCommandBuffer(false);
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                                             call_info,
    PFN_vkCmdTraceRaysIndirectKHR                                  func,
    VkCommandBuffer                                                original_command_buffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                                                indirectDeviceAddress)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t                   tr_index   = call_info.index;
    const bool                       must_dump  = MustDumpTraceRays(original_command_buffer, tr_index);
    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->InsertNewTraceRaysIndirectParameters(tr_index,
                                                         in_pRaygenShaderBindingTable,
                                                         in_pMissShaderBindingTable,
                                                         in_pHitShaderBindingTable,
                                                         in_pCallableShaderBindingTable,
                                                         indirectDeviceAddress);
    }

    if (dump_resources_before_ && must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, true);
        dr_context->FinalizeCommandBuffer(true);
    }

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it,
                 in_pRaygenShaderBindingTable,
                 in_pMissShaderBindingTable,
                 in_pHitShaderBindingTable,
                 in_pCallableShaderBindingTable,
                 indirectDeviceAddress);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer,
             in_pRaygenShaderBindingTable,
             in_pMissShaderBindingTable,
             in_pHitShaderBindingTable,
             in_pCallableShaderBindingTable,
             indirectDeviceAddress);
    }

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, false);
        dr_context->CopyTraceRaysIndirectParameters(tr_index);
        dr_context->SnapshotBoundDescriptorsTraceRays(tr_index);
        dr_context->FinalizeCommandBuffer(false);
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysIndirect2KHR(const ApiCallInfo&             call_info,
                                                                     PFN_vkCmdTraceRaysIndirect2KHR func,
                                                                     VkCommandBuffer original_command_buffer,
                                                                     VkDeviceAddress indirectDeviceAddress)
{
    assert(IsRecording(original_command_buffer));

    const uint64_t                   tr_index   = call_info.index;
    const bool                       must_dump  = MustDumpTraceRays(original_command_buffer, tr_index);
    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->InsertNewTraceRaysIndirect2Parameters(tr_index, indirectDeviceAddress);
    }

    if (dump_resources_before_ && must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, true);
        dr_context->FinalizeCommandBuffer(true);
    }

    CommandBufferIterator first, last;
    if (GetDrawCallActiveCommandBuffers(original_command_buffer, first, last))
    {
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, indirectDeviceAddress);
        }
    }

    VkCommandBuffer dispatch_rays_command_buffer = GetDispatchRaysCommandBuffer(original_command_buffer);
    if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
    {
        func(dispatch_rays_command_buffer, indirectDeviceAddress);
    }

    if (must_dump)
    {
        assert(dr_context != nullptr);

        dr_context->CloneTraceRaysMutableResources(tr_index, false);
        dr_context->CopyTraceRaysIndirectParameters(tr_index);
        dr_context->SnapshotBoundDescriptorsTraceRays(tr_index);
        dr_context->FinalizeCommandBuffer(false);
        UpdateRecordingStatus(original_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRendering(
    const ApiCallInfo&                             call_info,
    PFN_vkCmdBeginRendering                        func,
    VkCommandBuffer                                commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    assert(IsRecording(commandBuffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(commandBuffer);
    if (dc_context != nullptr)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            const auto   rendering_info_meta    = pRenderingInfo->GetMetaStructPointer();
            const size_t n_color_attachments    = rendering_info_meta->pColorAttachments->GetLength();
            const auto   color_attachments_meta = rendering_info_meta->pColorAttachments->GetMetaStructPointer();

            std::vector<VulkanImageInfo*> color_attachments(n_color_attachments);
            std::vector<VkImageLayout>    color_attachment_layouts(n_color_attachments);
            for (size_t i = 0; i < n_color_attachments; ++i)
            {
                const VulkanImageViewInfo* img_view_info =
                    object_info_table_.GetVkImageViewInfo(color_attachments_meta[i].imageView);
                assert(img_view_info != nullptr);

                VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_view_info->image_id);
                assert(img_info != nullptr);

                color_attachments[i]        = img_info;
                color_attachment_layouts[i] = color_attachments_meta[i].decoded_value->imageLayout;
            }

            VulkanImageInfo* depth_attachment;
            VkImageLayout    depth_attachment_layout;
            if (rendering_info_meta->pDepthAttachment != nullptr)
            {
                const auto depth_attachment_meta = rendering_info_meta->pDepthAttachment->GetMetaStructPointer();
                const VulkanImageViewInfo* img_view_info =
                    object_info_table_.GetVkImageViewInfo(depth_attachment_meta->imageView);
                assert(img_view_info != nullptr);

                VulkanImageInfo* img_info = object_info_table_.GetVkImageInfo(img_view_info->image_id);
                assert(img_info != nullptr);

                depth_attachment        = img_info;
                depth_attachment_layout = depth_attachment_meta->decoded_value->imageLayout;
            }
            else
            {
                depth_attachment        = nullptr;
                depth_attachment_layout = VK_IMAGE_LAYOUT_GENERAL;
            }

            dc_context->BeginRendering(color_attachments,
                                       color_attachment_layouts,
                                       depth_attachment,
                                       depth_attachment_layout,
                                       pRenderingInfo->GetPointer()->renderArea);
        }

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pRenderingInfo->GetPointer());
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer, pRenderingInfo->GetPointer());
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderingKHR(
    const ApiCallInfo&                             call_info,
    PFN_vkCmdBeginRenderingKHR                     func,
    VkCommandBuffer                                commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    OverrideCmdBeginRendering(call_info, func, commandBuffer, pRenderingInfo);
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRendering(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdEndRendering func,
                                                            VkCommandBuffer       commandBuffer)
{
    assert(IsRecording(commandBuffer));

    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(commandBuffer);
    if (dc_context != nullptr)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            dc_context->EndRendering();
        }

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it);
        }
    }

    VkCommandBuffer dr_command_buffer = GetDispatchRaysCommandBuffer(commandBuffer);
    if (dr_command_buffer != VK_NULL_HANDLE)
    {
        func(dr_command_buffer);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderingKHR(const ApiCallInfo&       call_info,
                                                               PFN_vkCmdEndRenderingKHR func,
                                                               VkCommandBuffer          commandBuffer)
{
    OverrideCmdEndRendering(call_info, func, commandBuffer);
}

bool VulkanReplayDumpResourcesBase::MustDumpDrawCall(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (context != nullptr)
    {
        return context->MustDumpDrawCall(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::MustDumpDispatch(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->MustDumpDispatch(index);
    }
    else
    {
        return false;
    }
}

bool VulkanReplayDumpResourcesBase::MustDumpTraceRays(VkCommandBuffer original_command_buffer, uint64_t index) const
{
    assert(original_command_buffer != VK_NULL_HANDLE);
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    assert(context);

    if (context != nullptr)
    {
        return context->MustDumpTraceRays(index);
    }
    else
    {
        return false;
    }
}

VkResult VulkanReplayDumpResourcesBase::QueueSubmit(const std::vector<VkSubmitInfo>& submit_infos,
                                                    const encode::VulkanDeviceTable& device_table,
                                                    VkQueue                          queue,
                                                    VkFence                          fence,
                                                    uint64_t                         index)
{
    bool     pre_submit = false;
    bool     submitted  = false;
    VkResult res        = VK_SUCCESS;

    // First do a submission with all command buffer except the ones we are interested in
    std::vector<VkSubmitInfo>                 modified_submit_infos = submit_infos;
    std::vector<std::vector<VkCommandBuffer>> modified_command_buffer_handles(modified_submit_infos.size());
    for (size_t s = 0; s < modified_submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = modified_submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = modified_submit_infos[s].pCommandBuffers;

        for (uint32_t o = 0; o < command_buffer_count; ++o)
        {
            auto bcb_entry = cmd_buf_begin_map_.find(command_buffer_handles[o]);
            if (bcb_entry != cmd_buf_begin_map_.end())
            {
                continue;
            }
            else
            {
                pre_submit = true;
                modified_command_buffer_handles[s].push_back(command_buffer_handles[o]);
            }
        }

        if (modified_command_buffer_handles[s].size())
        {
            modified_submit_infos[s].commandBufferCount = modified_command_buffer_handles[s].size();
            modified_submit_infos[s].pCommandBuffers    = modified_command_buffer_handles[s].data();
        }
        else
        {
            modified_submit_infos[s].commandBufferCount = 0;
            modified_submit_infos[s].pCommandBuffers    = nullptr;
        }
    }

    if (pre_submit)
    {
        res =
            device_table.QueueSubmit(queue, modified_submit_infos.size(), modified_submit_infos.data(), VK_NULL_HANDLE);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
            Release();
            return res;
        }

        // Wait
        res = device_table.QueueWaitIdle(queue);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("QueueWaitIdle failed with %s", util::ToString<VkResult>(res).c_str());
            Release();
            return res;
        }
    }

    if (!output_json_per_command)
    {
        dump_json_.BlockStart();
    }

    for (size_t s = 0; s < submit_infos.size(); s++)
    {
        size_t     command_buffer_count   = submit_infos[s].commandBufferCount;
        const auto command_buffer_handles = submit_infos[s].pCommandBuffers;

        for (size_t o = 0; o < command_buffer_count; ++o)
        {
            if (pre_submit)
            {
                // These semaphores have already been handled. Do not bother with them
                modified_submit_infos[s].waitSemaphoreCount = 0;
                modified_submit_infos[s].pSignalSemaphores  = 0;
            }

            DrawCallsDumpingContext*         dc_context = FindDrawCallCommandBufferContext(command_buffer_handles[o]);
            DispatchTraceRaysDumpingContext* dr_context =
                FindDispatchRaysCommandBufferContext(command_buffer_handles[o]);

            if (dc_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());

                res = dc_context->DumpDrawCalls(
                    queue, index, cmd_buf_begin_map_[command_buffer_handles[o]], modified_submit_infos[s], fence);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Dumping draw calls failed (%s). Terminating.",
                                       util::ToString<VkResult>(res).c_str())
                    Release();
                    exit(1);
                    return res;
                }

                submitted = true;
            }

            if (dr_context != nullptr)
            {
                assert(cmd_buf_begin_map_.find(command_buffer_handles[o]) != cmd_buf_begin_map_.end());
                res = dr_context->DumpDispatchTraceRays(
                    queue, index, cmd_buf_begin_map_[command_buffer_handles[o]], modified_submit_infos[s], fence);
                if (res != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Dumping dispatch/ray tracing failed (%s). Terminating.",
                                       util::ToString<VkResult>(res).c_str())
                    Release();
                    exit(1);
                    return res;
                }

                submitted = true;
            }
        }
    }

    assert(res == VK_SUCCESS);

    if (!output_json_per_command)
    {
        dump_json_.BlockEnd();
    }

    // Looks like we didn't submit anything. Do the submission as it would have been done
    // without further modifications
    if (!submitted)
    {
        res = device_table.QueueSubmit(queue, submit_infos.size(), submit_infos.data(), fence);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR(
                "(%s:%u) QueueSubmit failed with %s", __FILE__, __LINE__, util::ToString<VkResult>(res).c_str());
        }
    }
    else
    {
        auto index_it = QueueSubmit_indices_.find(index);
        assert(index_it != QueueSubmit_indices_.end());
        QueueSubmit_indices_.erase(index_it);

        // Once all submissions are complete release resources
        if (QueueSubmit_indices_.empty())
        {
            Release();
        }
    }

    return VK_SUCCESS;
}

bool VulkanReplayDumpResourcesBase::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(index);

    if (dc_context == nullptr)
    {
        const DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(index);
        return dr_context != nullptr;
    }
    else
    {
        return true;
    }
}

bool VulkanReplayDumpResourcesBase::GetDrawCallActiveCommandBuffers(VkCommandBuffer        original_command_buffer,
                                                                    CommandBufferIterator& first,
                                                                    CommandBufferIterator& last) const
{
    assert(IsRecording(original_command_buffer));

    const DrawCallsDumpingContext* stack = FindDrawCallCommandBufferContext(original_command_buffer);

    if (stack != nullptr)
    {
        stack->GetDrawCallActiveCommandBuffers(first, last);
        return true;
    }
    else
    {
        return false;
    }
}

VkCommandBuffer
VulkanReplayDumpResourcesBase::GetDispatchRaysCommandBuffer(VkCommandBuffer original_command_buffer) const
{
    assert(IsRecording(original_command_buffer));

    const DispatchTraceRaysDumpingContext* context = FindDispatchRaysCommandBufferContext(original_command_buffer);

    if (context != nullptr)
    {
        VkCommandBuffer dr_command_buffer = context->GetDispatchRaysCommandBuffer();
        assert(dr_command_buffer != VK_NULL_HANDLE);

        return dr_command_buffer;
    }
    else
    {
        return VK_NULL_HANDLE;
    }
}

bool VulkanReplayDumpResourcesBase::UpdateRecordingStatus(VkCommandBuffer original_command_buffer)
{
    assert(recording_);

    const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr && dc_context->IsRecording())
    {
        return true;
    }

    const DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context != nullptr && dr_context->IsRecording())
    {
        return true;
    }

    recording_ = false;
    return false;
}

bool VulkanReplayDumpResourcesBase::MustDumpQueueSubmitIndex(uint64_t index) const
{
    // Indices should be sorted
    return QueueSubmit_indices_.find(index) != QueueSubmit_indices_.end();
}

bool VulkanReplayDumpResourcesBase::IsRecording(VkCommandBuffer original_command_buffer) const
{
    if (recording_)
    {
        const DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
        if (dc_context)
        {
            if (dc_context->IsRecording())
            {
                return true;
            }
        }

        const DispatchTraceRaysDumpingContext* dr_context =
            FindDispatchRaysCommandBufferContext(original_command_buffer);
        if (dr_context != nullptr)
        {
            if (dr_context->IsRecording())
            {
                return true;
            }
        }
    }

    return false;
}

uint64_t
VulkanReplayDumpResourcesBase::GetBeginCommandBufferIndexOfCommandBuffer(VkCommandBuffer original_command_buffer) const
{
    const auto& entry = cmd_buf_begin_map_.find(original_command_buffer);
    if (entry != cmd_buf_begin_map_.end())
    {
        return entry->second;
    }
    else
    {
        return 0;
    }
}

void VulkanReplayDumpResourcesBase::ResetCommandBuffer(VkCommandBuffer original_command_buffer)
{
    DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(original_command_buffer);
    if (dc_context != nullptr)
    {
        dc_context->Release();
    }

    DispatchTraceRaysDumpingContext* dr_context = FindDispatchRaysCommandBufferContext(original_command_buffer);
    if (dr_context != nullptr)
    {
        dr_context->Release();
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
