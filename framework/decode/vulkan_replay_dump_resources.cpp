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

#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_replay_dump_resources_copy_array_of_pointers.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "vulkan_replay_dump_resources.h"
#include "decode/vulkan_pnext_node.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "util/logging.h"
#include "util/to_string.h"

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>
#if !defined(WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesBase::VulkanReplayDumpResourcesBase(const VulkanReplayOptions&            options,
                                                             CommonObjectInfoTable*                object_info_table,
                                                             const VulkanPerDeviceAddressTrackers& address_trackers) :
    BeginCommandBufferQueueSubmit_Indices_(options.BeginCommandBufferQueueSubmit_Indices),
    recording_(false), dump_resources_before_(options.dump_resources_before), object_info_table_(object_info_table),
    output_json_per_command(options.dump_resources_json_per_command), default_delegate_(nullptr),
    user_delegate_(nullptr), active_delegate_(nullptr), address_trackers_(address_trackers),
    dump_as_build_input_buffers_(options.dump_resources_dump_build_AS_input_buffers)
{
    capture_filename = std::filesystem::path(options.capture_filename).stem().string();

    if (options.dump_resources_binary_file_compression_type != format::CompressionType::kNone)
    {
        compressor_ = std::unique_ptr<util::Compressor>(
            format::CreateCompressor(options.dump_resources_binary_file_compression_type));
    }

    if (!options.Draw_Indices.size() && !options.Dispatch_Indices.size() && !options.TraceRays_Indices.size())
    {
        return;
    }

    if (user_delegate_ != nullptr)
    {
        active_delegate_ = user_delegate_;
    }
    else
    {
        // Use a default delegate if none was provided.
        default_delegate_ =
            std::make_unique<DefaultVulkanDumpResourcesDelegate>(options, *object_info_table, capture_filename);
        active_delegate_ = default_delegate_.get();
    }

    if (!options.dump_resources_json_per_command)
    {
        active_delegate_->Open();
    }

    for (size_t i = 0; i < BeginCommandBufferQueueSubmit_Indices_.size(); ++i)
    {
        const decode::Index qs_index  = BeginCommandBufferQueueSubmit_Indices_[i].second;
        const decode::Index bcb_index = BeginCommandBufferQueueSubmit_Indices_[i].first;
        const bool          has_draw  = i < options.Draw_Indices.size() && options.Draw_Indices[i].size();
        const bool has_dispatch       = (i < options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size()) ||
                                  (i < options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size());
        const bool has_secondaries =
            ((i < options.ExecuteCommands_Indices.size()) && !options.ExecuteCommands_Indices[i].empty());

        if (has_draw)
        {
            draw_call_contexts_.emplace(std::piecewise_construct,
                                        std::forward_as_tuple(bcb_index, qs_index),
                                        std::forward_as_tuple(&options.Draw_Indices[i],
                                                              &options.RenderPass_Indices[i],
                                                              options.DrawSubresources,
                                                              *object_info_table,
                                                              options,
                                                              *active_delegate_,
                                                              compressor_.get(),
                                                              acceleration_structures_context_,
                                                              address_trackers));
        }

        if (has_dispatch)
        {
            dispatch_ray_contexts_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(bcb_index, qs_index),
                std::forward_as_tuple((options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                          ? &options.Dispatch_Indices[i]
                                          : nullptr,
                                      options.DispatchSubresources,
                                      (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                          ? &options.TraceRays_Indices[i]
                                          : nullptr,
                                      options.TraceRaysSubresources,
                                      *object_info_table_,
                                      options,
                                      *active_delegate_,
                                      compressor_.get(),
                                      acceleration_structures_context_,
                                      address_trackers));
        }
    }

    // Once all contexts are created do a second pass and assign the secondaries to the primaries the are executed from
    for (size_t i = 0;
         i < options.BeginCommandBufferQueueSubmit_Indices.size() && i < options.ExecuteCommands_Indices.size();
         ++i)
    {
        if (options.ExecuteCommands_Indices[i].empty())
        {
            continue;
        }

        const decode::Index bcb_index = BeginCommandBufferQueueSubmit_Indices_[i].first;
        const decode::Index qs_index  = BeginCommandBufferQueueSubmit_Indices_[i].second;

        std::vector<DrawCallsDumpingContext*> primary_dc_contexts = FindDrawCallCommandBufferContext(bcb_index);
        for (auto& [execute_commands_index, secondary_bcbs] : options.ExecuteCommands_Indices[i])
        {
            for (auto& secondary_bcb : secondary_bcbs)
            {
                std::vector<DrawCallsDumpingContext*> secondary_dc_contexts =
                    FindDrawCallCommandBufferContext(secondary_bcb);
                if (!secondary_dc_contexts.empty())
                {
                    if (primary_dc_contexts.empty())
                    {
                        auto new_primary =
                            draw_call_contexts_.emplace(std::piecewise_construct,
                                                        std::forward_as_tuple(bcb_index, qs_index),
                                                        std::forward_as_tuple(nullptr,
                                                                              &options.RenderPass_Indices[i],
                                                                              options.DrawSubresources,
                                                                              *object_info_table,
                                                                              options,
                                                                              *active_delegate_,
                                                                              compressor_.get(),
                                                                              acceleration_structures_context_,
                                                                              address_trackers));

                        primary_dc_contexts = FindDrawCallCommandBufferContext(bcb_index);
                    }

                    for (auto prim_contex : primary_dc_contexts)
                    {
                        for (auto sec_context : secondary_dc_contexts)
                        {
                            prim_contex->AssignSecondary(execute_commands_index, sec_context);
                        }
                    }
                }
            }
        }

        std::vector<DispatchTraceRaysDumpingContext*> primary_disp_contexts =
            FindDispatchRaysCommandBufferContext(bcb_index);
        for (auto& execute_commands : options.ExecuteCommands_Indices[i])
        {
            const uint64_t execute_commands_index = execute_commands.first;
            for (auto& secondary : execute_commands.second)
            {
                std::vector<DispatchTraceRaysDumpingContext*> secondary_disp_contexts =
                    FindDispatchRaysCommandBufferContext(secondary);
                if (!secondary_disp_contexts.empty())
                {
                    if (primary_disp_contexts.empty())
                    {
                        dispatch_ray_contexts_.emplace(std::piecewise_construct,
                                                       std::forward_as_tuple(bcb_index, qs_index),
                                                       std::forward_as_tuple(nullptr,
                                                                             options.DispatchSubresources,
                                                                             nullptr,
                                                                             options.TraceRaysSubresources,
                                                                             *object_info_table_,
                                                                             options,
                                                                             *active_delegate_,
                                                                             compressor_.get(),
                                                                             acceleration_structures_context_,
                                                                             address_trackers));

                        primary_disp_contexts = FindDispatchRaysCommandBufferContext(bcb_index);
                    }

                    for (auto prim_context : primary_disp_contexts)
                    {
                        for (auto sec_context : secondary_disp_contexts)
                        {
                            prim_context->AssignSecondary(execute_commands_index, sec_context);
                        }
                    }
                }
            }
        }
    }

    // Number of command buffers for DrawCallsDumpingContext need to be recalculated when dumping resources from
    // secondaries. This is done in a separate pass since we need to be sure that all assignments have been completed.
    if (!options.ExecuteCommands_Indices.empty())
    {
        for (size_t i = 0; i < BeginCommandBufferQueueSubmit_Indices_.size(); ++i)
        {
            if (options.ExecuteCommands_Indices[i].empty())
            {
                continue;
            }

            const uint64_t                        bcb_index           = BeginCommandBufferQueueSubmit_Indices_[i].first;
            std::vector<DrawCallsDumpingContext*> primary_dc_contexts = FindDrawCallCommandBufferContext(bcb_index);
            if (!primary_dc_contexts.empty())
            {
                for (DrawCallsDumpingContext* prim_context : primary_dc_contexts)
                {
                    prim_context->RecaclulateCommandBuffers();
                }
            }
        }
    }
}

VulkanReplayDumpResourcesBase::~VulkanReplayDumpResourcesBase()
{
    Release();
}

void VulkanReplayDumpResourcesBase::Release()
{
    // active_delegate_ could be nullptr because constructor could return before creating delegate.
    if (active_delegate_)
    {
        active_delegate_->Close();
        active_delegate_  = nullptr;
        default_delegate_ = nullptr;
    }
    draw_call_contexts_.clear();
    dispatch_ray_contexts_.clear();
    cb_bcb_map_.clear();
    BeginCommandBufferQueueSubmit_Indices_.clear();

    acceleration_structures_context_.clear();

    recording_ = false;
}

std::vector<DrawCallsDumpingContext*>
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    std::vector<DrawCallsDumpingContext*> contexts;

    auto begin_entry = cb_bcb_map_.find(original_command_buffer);
    if (begin_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == begin_entry->second)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

DrawCallsDumpingContext*
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer,
                                                                decode::Index   qs_index)
{
    auto begin_entry = cb_bcb_map_.find(original_command_buffer);
    if (begin_entry == cb_bcb_map_.end())
    {
        return nullptr;
    }

    const decode::Index bcb_index = begin_entry->second;

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_index && it->first.second == qs_index)
        {
            return &it->second;
        }
    }

    return nullptr;
}

std::vector<const DrawCallsDumpingContext*>
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    std::vector<const DrawCallsDumpingContext*> contexts;

    auto begin_entry = cb_bcb_map_.find(original_command_buffer);
    if (begin_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == begin_entry->second)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

std::vector<DrawCallsDumpingContext*> VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id)
{
    std::vector<DrawCallsDumpingContext*> contexts;

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

std::vector<const DrawCallsDumpingContext*>
VulkanReplayDumpResourcesBase::FindDrawCallCommandBufferContext(uint64_t bcb_id) const
{
    std::vector<const DrawCallsDumpingContext*> contexts;

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

std::vector<DispatchTraceRaysDumpingContext*>
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id)
{
    std::vector<DispatchTraceRaysDumpingContext*> contexts;

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

std::vector<const DispatchTraceRaysDumpingContext*>
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(uint64_t bcb_id) const
{
    std::vector<const DispatchTraceRaysDumpingContext*> contexts;

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

std::vector<DispatchTraceRaysDumpingContext*>
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer)
{
    std::vector<DispatchTraceRaysDumpingContext*> contexts;

    auto bcb_entry = cb_bcb_map_.find(original_command_buffer);
    if (bcb_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_entry->second)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

DispatchTraceRaysDumpingContext*
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer,
                                                                    decode::Index   qs_index)
{
    auto bcb_entry = cb_bcb_map_.find(original_command_buffer);
    if (bcb_entry == cb_bcb_map_.end())
    {
        return nullptr;
    }

    const decode::Index bcb_index = bcb_entry->second;

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_index && it->first.second == qs_index)
        {
            return &it->second;
        }
    }

    return nullptr;
}

std::vector<const DispatchTraceRaysDumpingContext*>
VulkanReplayDumpResourcesBase::FindDispatchRaysCommandBufferContext(VkCommandBuffer original_command_buffer) const
{
    std::vector<const DispatchTraceRaysDumpingContext*> contexts;

    auto bcb_entry = cb_bcb_map_.find(original_command_buffer);
    if (bcb_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_entry->second)
        {
            contexts.push_back(&it->second);
        }
    }

    return contexts;
}

VkResult VulkanReplayDumpResourcesBase::BeginCommandBuffer(uint64_t                 bcb_index,
                                                           VulkanCommandBufferInfo* original_command_buffer_info,
                                                           const graphics::VulkanDeviceTable*   device_table,
                                                           const graphics::VulkanInstanceTable* inst_table,
                                                           const VkCommandBufferBeginInfo*      begin_info)
{
    assert(device_table);
    assert(inst_table);

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(bcb_index);
    for (auto dc_context : dc_contexts)
    {
        VkResult res =
            dc_context->BeginCommandBuffer(original_command_buffer_info, device_table, inst_table, begin_info);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Cloning command buffer for dumping draw calls failed (%s).",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts = FindDispatchRaysCommandBufferContext(bcb_index);
    for (auto dr_context : dr_contexts)
    {
        VkResult res =
            dr_context->BeginCommandBuffer(original_command_buffer_info, device_table, inst_table, begin_info);
        if (res != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Cloning command buffer for dumping compute/ray tracing failed (%s).",
                               util::ToString<VkResult>(res).c_str())
            return res;
        }
    }

    if (!dr_contexts.empty() || !dc_contexts.empty())
    {
        recording_                                        = true;
        cb_bcb_map_[original_command_buffer_info->handle] = bcb_index;
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDraw(
            call_info, func, original_command_buffer, vertex_count, instance_count, first_vertex, first_instance);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, vertex_count, instance_count, first_vertex, first_instance);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDrawIndexed(const ApiCallInfo&   call_info,
                                                           PFN_vkCmdDrawIndexed func,
                                                           VkCommandBuffer      original_command_buffer,
                                                           uint32_t             index_count,
                                                           uint32_t             instance_count,
                                                           uint32_t             first_index,
                                                           int32_t              vertex_offset,
                                                           uint32_t             first_instance)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndexed(call_info,
                                   func,
                                   original_command_buffer,
                                   index_count,
                                   instance_count,
                                   first_index,
                                   vertex_offset,
                                   first_instance);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, index_count, instance_count, first_index, vertex_offset, first_instance);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndirect(call_info, func, original_command_buffer, buffer_info, offset, draw_count, stride);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndexedIndirect(
            call_info, func, original_command_buffer, buffer_info, offset, draw_count, stride);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, buffer_info->handle, offset, draw_count, stride);
        }
    }
}

void VulkanReplayDumpResourcesBase::HandleCmdDrawIndirectCount(const ApiCallInfo&         call_info,
                                                               PFN_vkCmdDrawIndirectCount func,
                                                               VkCommandBuffer            original_command_buffer,
                                                               const VulkanBufferInfo*    buffer_info,
                                                               VkDeviceSize               offset,
                                                               const VulkanBufferInfo*    count_buffer_info,
                                                               VkDeviceSize               count_buffer_offset,
                                                               uint32_t                   max_draw_count,
                                                               uint32_t                   stride,
                                                               DrawCallsDumpingContext::DrawCallType drawcall_type)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndirectCount(call_info,
                                         func,
                                         original_command_buffer,
                                         buffer_info,
                                         offset,
                                         count_buffer_info,
                                         count_buffer_offset,
                                         max_draw_count,
                                         stride,
                                         drawcall_type);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
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
    }
}

void VulkanReplayDumpResourcesBase::HandleCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                    call_info,
    PFN_vkCmdDrawIndirectCountKHR         func,
    VkCommandBuffer                       original_command_buffer,
    const VulkanBufferInfo*               buffer_info,
    VkDeviceSize                          offset,
    const VulkanBufferInfo*               count_buffer_info,
    VkDeviceSize                          count_buffer_offset,
    uint32_t                              max_draw_count,
    uint32_t                              stride,
    DrawCallsDumpingContext::DrawCallType drawcall_type)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndexedIndirectCount(call_info,
                                                func,
                                                original_command_buffer,
                                                buffer_info,
                                                offset,
                                                count_buffer_info,
                                                count_buffer_offset,
                                                max_draw_count,
                                                stride,
                                                drawcall_type);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
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
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderPass(
    const ApiCallInfo&                                   call_info,
    PFN_vkCmdBeginRenderPass                             func,
    VkCommandBuffer                                      original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                                    contents)
{
    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
            auto       framebuffer_id        = render_pass_info_meta->framebuffer;
            auto       render_pass_id        = render_pass_info_meta->renderPass;

            const VulkanFramebufferInfo* framebuffer_info = object_info_table_->GetVkFramebufferInfo(framebuffer_id);
            assert(framebuffer_info);

            VulkanRenderPassInfo* render_pass_info = object_info_table_->GetVkRenderPassInfo(render_pass_id);
            assert(render_pass_info);

            // The attachments for imageless framebuffers are provided in the pNext chain of vkCmdBeginRenderPass
            if ((framebuffer_info->framebuffer_flags & VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT) ==
                VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT)
            {
                const auto* attachment_begin_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(
                    pRenderPassBegin->GetMetaStructPointer()->pNext);
                GFXRECON_ASSERT(attachment_begin_info);

                uint32_t                num_attachments = attachment_begin_info->pAttachments.GetLength();
                const format::HandleId* handle_ids      = attachment_begin_info->pAttachments.GetPointer();

                GFXRECON_ASSERT(num_attachments == render_pass_info->attachment_description_final_layouts.size());
                render_pass_info->begin_renderpass_override_attachments.assign(handle_ids,
                                                                               handle_ids + num_attachments);
            }

            // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
            // It will be handled by DrawCallsDumpingContext::BeginRenderPass
            const auto* renderpass_begin_info = pRenderPassBegin->GetPointer();
            VkResult    res =
                dc_context->BeginRenderPass(render_pass_info, framebuffer_info, renderpass_begin_info, contents);
            assert(res == VK_SUCCESS);
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pRenderPassBegin->GetPointer(), contents);
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, pRenderPassBegin->GetPointer(), contents);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            const auto render_pass_info_meta = pRenderPassBegin->GetMetaStructPointer();
            auto       framebuffer_id        = render_pass_info_meta->framebuffer;
            auto       render_pass_id        = render_pass_info_meta->renderPass;

            const VulkanFramebufferInfo* framebuffer_info = object_info_table_->GetVkFramebufferInfo(framebuffer_id);
            assert(framebuffer_info);

            VulkanRenderPassInfo* render_pass_info = object_info_table_->GetVkRenderPassInfo(render_pass_id);
            assert(render_pass_info);

            if ((framebuffer_info->framebuffer_flags & VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT) ==
                VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT)
            {
                // The attachments for imageless framebuffers are provided in the pNext chain of vkCmdBeginRenderPass
                const auto* attachment_begin_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(
                    pRenderPassBegin->GetMetaStructPointer()->pNext);
                GFXRECON_ASSERT(attachment_begin_info);

                uint32_t                num_attachments = attachment_begin_info->pAttachments.GetLength();
                const format::HandleId* handle_ids      = attachment_begin_info->pAttachments.GetPointer();

                GFXRECON_ASSERT(num_attachments == render_pass_info->attachment_description_final_layouts.size());
                render_pass_info->begin_renderpass_override_attachments.assign(handle_ids,
                                                                               handle_ids + num_attachments);
            }

            // Do not record vkCmdBeginRenderPass commands in current DrawCall context command buffers.
            // It will be handled by DrawCallsDumpingContext::BeginRenderPass
            const auto* renderpass_begin_info = pRenderPassBegin->GetPointer();
            VkResult    res                   = dc_context->BeginRenderPass(
                render_pass_info, framebuffer_info, renderpass_begin_info, pSubpassBeginInfo->GetPointer()->contents);

            assert(res == VK_SUCCESS);
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, pRenderPassBegin->GetPointer(), pSubpassBeginInfo->GetPointer());
        }
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
    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            dc_context->NextSubpass(contents);
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, contents);
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, contents);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            // Do not record NextSubpass commands in current DrawCall context command buffers.
            // It will be handled by DrawCallsDumpingContext::NextSubpass
            dc_context->NextSubpass(pSubpassBeginInfo->GetPointer()->contents);
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, pSubpassBeginInfo->GetPointer(), pSubpassEndInfo->GetPointer());
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass(const ApiCallInfo&     call_info,
                                                             PFN_vkCmdEndRenderPass func,
                                                             VkCommandBuffer        original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            // Do not record EndRenderPass commands in current DrawCall context command buffers.
            // It will be handled by DrawCallsDumpingContext::EndRenderPass
            dc_context->EndRenderPass();
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it);
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderPass2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdEndRenderPass2                         func,
    VkCommandBuffer                                 original_command_buffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            // Do not record EndRenderPass commands in current DrawCall context command buffers.
            // It will be handled by DrawCallsDumpingContext::EndRenderPass
            dc_context->EndRenderPass();
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pSubpassEndInfo->GetPointer());
            }
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, pSubpassEndInfo->GetPointer());
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->BindPipeline(pipelineBindPoint, pipeline);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pipelineBindPoint, pipeline->handle);
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->BindPipeline(pipelineBindPoint, pipeline);

        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
            func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline->handle);
        }
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

    std::vector<VkDescriptorSet>                desc_set_handles(descriptor_sets_count, VK_NULL_HANDLE);
    std::vector<const VulkanDescriptorSetInfo*> desc_set_infos(descriptor_sets_count, nullptr);

    for (uint32_t i = 0; i < descriptor_sets_count; ++i)
    {
        const VulkanDescriptorSetInfo* desc_set_info =
            object_info_table_->GetVkDescriptorSetInfo(descriptor_sets_ids[i]);
        desc_set_infos[i]   = desc_set_info;
        desc_set_handles[i] = (desc_set_info != nullptr) ? desc_set_info->handle : VK_NULL_HANDLE;
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
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
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_cmd_buf = dr_context->GetDispatchRaysCommandBuffer();
        func(dr_cmd_buf,
             pipeline_bind_point,
             layout_info->handle,
             first_set,
             descriptor_sets_count,
             desc_set_handles.data(),
             dynamicOffsetCount,
             pDynamicOffsets);

        dr_context->BindDescriptorSets(
            pipeline_bind_point, first_set, desc_set_infos, dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindDescriptorSets2(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdBindDescriptorSets2                            func,
    VkCommandBuffer                                         original_command_buffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    const auto bind_meta = pBindDescriptorSetsInfo->GetMetaStructPointer();

    std::vector<VkPipelineBindPoint> bind_points =
        ShaderStageFlagsToPipelineBindPoints(bind_meta->decoded_value->stageFlags);

    const auto layout_info = object_info_table_->GetVkPipelineLayoutInfo(bind_meta->layout);

    std::vector<const VulkanDescriptorSetInfo*> desc_set_infos(bind_meta->decoded_value->descriptorSetCount, nullptr);

    for (uint32_t i = 0; i < bind_meta->decoded_value->descriptorSetCount; ++i)
    {
        const VulkanDescriptorSetInfo* desc_set_info =
            object_info_table_->GetVkDescriptorSetInfo(bind_meta->pDescriptorSets.GetPointer()[i]);
        desc_set_infos[i] = desc_set_info;
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        for (const auto bind_point : bind_points)
        {
            dc_context->BindDescriptorSets(bind_point,
                                           bind_meta->decoded_value->firstSet,
                                           desc_set_infos,
                                           bind_meta->decoded_value->dynamicOffsetCount,
                                           bind_meta->decoded_value->pDynamicOffsets);
        }

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, pBindDescriptorSetsInfo->GetPointer());
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_cmd_buf = dr_context->GetDispatchRaysCommandBuffer();
        func(dr_cmd_buf, pBindDescriptorSetsInfo->GetPointer());

        for (const auto bind_point : bind_points)
        {
            dr_context->BindDescriptorSets(bind_point,
                                           bind_meta->decoded_value->firstSet,
                                           desc_set_infos,
                                           bind_meta->decoded_value->dynamicOffsetCount,
                                           bind_meta->decoded_value->pDynamicOffsets);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->BindIndexBuffer(call_info.index, buffer, offset, indexType);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_handle, offset, indexType);
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
            func(dispatch_rays_command_buffer, buffer_handle, offset, indexType);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_handle, offset, size, indexType);
        }

        dc_context->BindIndexBuffer(call_info.index, buffer, offset, indexType, size);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
            func(dispatch_rays_command_buffer, buffer_handle, offset, size, indexType);
        }
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
    std::vector<const VulkanBufferInfo*> buffer_infos(bindingCount, nullptr);
    std::vector<VkBuffer>                buffer_handles(bindingCount, VK_NULL_HANDLE);
    for (uint32_t i = 0; i < bindingCount; ++i)
    {
        // Buffer can be VK_NULL_HANDLE
        const VulkanBufferInfo* buffer_info = object_info_table_->GetVkBufferInfo(buffer_ids[i]);

        buffer_infos[i]   = buffer_info;
        buffer_handles[i] = buffer_info != nullptr ? buffer_info->handle : VK_NULL_HANDLE;
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        GFXRECON_ASSERT(buffer_infos.size() == bindingCount);
        dc_context->BindVertexBuffers(call_info.index, firstBinding, buffer_infos, pOffsets);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
            func(dispatch_rays_command_buffer, firstBinding, bindingCount, buffer_handles.data(), pOffsets);
        }
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

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it,
                 vertexBindingDescriptionCount,
                 in_pVertexBindingDescriptions,
                 vertexAttributeDescriptionCount,
                 in_pVertexAttributeDescriptions);
        }

        dc_context->SetVertexInput(vertexBindingDescriptionCount,
                                   in_pVertexBindingDescriptions,
                                   vertexAttributeDescriptionCount,
                                   in_pVertexAttributeDescriptions);
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
        {
            func(dispatch_rays_command_buffer,
                 vertexBindingDescriptionCount,
                 in_pVertexBindingDescriptions,
                 vertexAttributeDescriptionCount,
                 in_pVertexAttributeDescriptions);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindVertexBuffers2EXT(const ApiCallInfo&             call_info,
                                                                     PFN_vkCmdBindVertexBuffers2EXT func,
                                                                     VkCommandBuffer         original_command_buffer,
                                                                     uint32_t                firstBinding,
                                                                     uint32_t                bindingCount,
                                                                     const format::HandleId* pBuffers_ids,
                                                                     const VkDeviceSize*     pOffsets,
                                                                     const VkDeviceSize*     pSizes,
                                                                     const VkDeviceSize*     pStrides)
{
    HandleCmdBindVertexBuffers2(
        call_info, func, original_command_buffer, firstBinding, bindingCount, pBuffers_ids, pOffsets, pSizes, pStrides);
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
    HandleCmdBindVertexBuffers2(
        call_info, func, original_command_buffer, firstBinding, bindingCount, pBuffers_ids, pOffsets, pSizes, pStrides);
}

void VulkanReplayDumpResourcesBase::HandleCmdBindVertexBuffers2(const ApiCallInfo&          call_info,
                                                                PFN_vkCmdBindVertexBuffers2 func,
                                                                VkCommandBuffer             original_command_buffer,
                                                                uint32_t                    firstBinding,
                                                                uint32_t                    bindingCount,
                                                                const format::HandleId*     pBuffers_ids,
                                                                const VkDeviceSize*         pOffsets,
                                                                const VkDeviceSize*         pSizes,
                                                                const VkDeviceSize*         pStrides)
{
    std::vector<VkBuffer> buffer_handles(bindingCount);
    for (uint32_t i = 0; i < bindingCount; ++i)
    {
        const VulkanBufferInfo* buffer_info = object_info_table_->GetVkBufferInfo(pBuffers_ids[i]);
        buffer_handles[i]                   = (buffer_info != nullptr) ? buffer_info->handle : VK_NULL_HANDLE;
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, firstBinding, bindingCount, buffer_handles.data(), pOffsets, pSizes, pStrides);
        }

        if (dc_context != nullptr && bindingCount)
        {
            std::vector<const VulkanBufferInfo*> buffer_infos(bindingCount);

            for (uint32_t i = 0; i < bindingCount; ++i)
            {
                const VulkanBufferInfo* buffer_info = object_info_table_->GetVkBufferInfo(pBuffers_ids[i]);

                buffer_infos[i] = buffer_info;
            }

            dc_context->BindVertexBuffers2(call_info.index, firstBinding, buffer_infos, pOffsets, pSizes, pStrides);
        }
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
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
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatch(const ApiCallInfo& call_info,
                                                        PFN_vkCmdDispatch  func,
                                                        VkCommandBuffer    original_command_buffer,
                                                        uint32_t           groupCountX,
                                                        uint32_t           groupCountY,
                                                        uint32_t           groupCountZ)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdDispatch(call_info, func, original_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, groupCountX, groupCountY, groupCountZ);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdDispatchIndirect(const ApiCallInfo&        call_info,
                                                                PFN_vkCmdDispatchIndirect func,
                                                                VkCommandBuffer           original_command_buffer,
                                                                const VulkanBufferInfo*   buffer_info,
                                                                VkDeviceSize              offset)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdDispatchIndirect(call_info, func, original_command_buffer, buffer_info, offset);
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, buffer_info->handle, offset);
        }
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

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdTraceRaysKHR(call_info,
                                    func,
                                    original_command_buffer,
                                    pRaygenShaderBindingTable,
                                    pMissShaderBindingTable,
                                    pHitShaderBindingTable,
                                    pCallableShaderBindingTable,
                                    width,
                                    height,
                                    depth);
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
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

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdTraceRaysIndirectKHR(call_info,
                                            func,
                                            original_command_buffer,
                                            pRaygenShaderBindingTable,
                                            pMissShaderBindingTable,
                                            pHitShaderBindingTable,
                                            pCallableShaderBindingTable,
                                            indirectDeviceAddress);
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_contest : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_contest->GetDrawCallActiveCommandBuffers(first, last);
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
}

void VulkanReplayDumpResourcesBase::OverrideCmdTraceRaysIndirect2KHR(const ApiCallInfo&             call_info,
                                                                     PFN_vkCmdTraceRaysIndirect2KHR func,
                                                                     VkCommandBuffer original_command_buffer,
                                                                     VkDeviceAddress indirectDeviceAddress)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdTraceRaysIndirect2KHR(call_info, func, original_command_buffer, indirectDeviceAddress);
    }

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, indirectDeviceAddress);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRendering(
    const ApiCallInfo&                             call_info,
    PFN_vkCmdBeginRendering                        func,
    VkCommandBuffer                                original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
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
                    object_info_table_->GetVkImageViewInfo(color_attachments_meta[i].imageView);
                assert(img_view_info != nullptr);

                VulkanImageInfo* img_info = object_info_table_->GetVkImageInfo(img_view_info->image_id);
                assert(img_info != nullptr);

                color_attachments[i]        = img_info;
                color_attachment_layouts[i] = color_attachments_meta[i].decoded_value->imageLayout;
            }

            VulkanImageInfo* depth_attachment;
            VkImageLayout    depth_attachment_layout;
            if (rendering_info_meta->pDepthAttachment != nullptr &&
                rendering_info_meta->pDepthAttachment->GetMetaStructPointer() != nullptr)
            {
                const auto depth_attachment_meta = rendering_info_meta->pDepthAttachment->GetMetaStructPointer();
                const VulkanImageViewInfo* img_view_info =
                    object_info_table_->GetVkImageViewInfo(depth_attachment_meta->imageView);
                assert(img_view_info != nullptr);

                VulkanImageInfo* img_info = object_info_table_->GetVkImageInfo(img_view_info->image_id);
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

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer, pRenderingInfo->GetPointer());
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginRenderingKHR(
    const ApiCallInfo&                             call_info,
    PFN_vkCmdBeginRenderingKHR                     func,
    VkCommandBuffer                                original_command_buffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    OverrideCmdBeginRendering(call_info, func, original_command_buffer, pRenderingInfo);
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRendering(const ApiCallInfo&    call_info,
                                                            PFN_vkCmdEndRendering func,
                                                            VkCommandBuffer       original_command_buffer)
{
    assert(IsRecording(original_command_buffer));

    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
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

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
        if (dr_command_buffer != VK_NULL_HANDLE)
        {
            func(dr_command_buffer);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndRenderingKHR(const ApiCallInfo&       call_info,
                                                               PFN_vkCmdEndRenderingKHR func,
                                                               VkCommandBuffer          original_command_buffer)
{
    OverrideCmdEndRendering(call_info, func, original_command_buffer);
}

VkResult VulkanReplayDumpResourcesBase::QueueSubmit(const std::vector<VkSubmitInfo>&   submit_infos,
                                                    const graphics::VulkanDeviceTable& device_table,
                                                    VkQueue                            queue,
                                                    VkFence                            fence,
                                                    uint64_t                           index)
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
            auto bcb_entry = cb_bcb_map_.find(command_buffer_handles[o]);
            if (bcb_entry != cb_bcb_map_.end())
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
        active_delegate_->DumpStart();
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
                modified_submit_infos[s].waitSemaphoreCount   = 0;
                modified_submit_infos[s].signalSemaphoreCount = 0;
            }

            DrawCallsDumpingContext* dc_context = FindDrawCallCommandBufferContext(command_buffer_handles[o], index);
            if (dc_context != nullptr)
            {
                res = dc_context->DumpDrawCalls(
                    queue, index, cb_bcb_map_[command_buffer_handles[o]], modified_submit_infos[s], fence);
                if (res != VK_SUCCESS)
                {
                    Release();
                    RaiseFatalError(("Dumping draw calls failed (" + util::ToString<VkResult>(res) + ")").c_str());
                    return res;
                }

                submitted = true;
            }

            DispatchTraceRaysDumpingContext* dr_context =
                FindDispatchRaysCommandBufferContext(command_buffer_handles[o], index);
            if (dr_context != nullptr)
            {
                res = dr_context->DumpDispatchTraceRays(
                    queue, index, cb_bcb_map_[command_buffer_handles[o]], modified_submit_infos[s], fence, !submitted);
                if (res != VK_SUCCESS)
                {
                    Release();
                    RaiseFatalError(
                        ("Dumping dispatch/ray tracing failed (" + util::ToString<VkResult>(res) + ")").c_str());
                    return res;
                }

                submitted = true;
            }

            // In case we are dumping multiple command buffers from the same submission
            modified_submit_infos[s].waitSemaphoreCount   = 0;
            modified_submit_infos[s].signalSemaphoreCount = 0;
        }
    }

    assert(res == VK_SUCCESS);

    if (!output_json_per_command)
    {
        active_delegate_->DumpEnd();
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
        BeginCommandBufferQueueSubmit_Indices_.erase(
            std::remove_if(
                BeginCommandBufferQueueSubmit_Indices_.begin(),
                BeginCommandBufferQueueSubmit_Indices_.end(),
                [index](const BeginCmdBufQueueSubmitPair& index_pair) { return index_pair.second == index; }),
            BeginCommandBufferQueueSubmit_Indices_.end());

        // Once all submissions are complete release resources
        if (BeginCommandBufferQueueSubmit_Indices_.empty())
        {
            Release();
        }
    }

    return VK_SUCCESS;
}

bool VulkanReplayDumpResourcesBase::DumpingBeginCommandBufferIndex(uint64_t index) const
{
    const std::vector<const DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(index);

    if (dc_contexts.empty())
    {
        const std::vector<const DispatchTraceRaysDumpingContext*> dr_contexts =
            FindDispatchRaysCommandBufferContext(index);
        return !dr_contexts.empty();
    }
    else
    {
        return true;
    }
}

bool VulkanReplayDumpResourcesBase::UpdateRecordingStatus(VkCommandBuffer original_command_buffer)
{
    assert(recording_);

    recording_ = !BeginCommandBufferQueueSubmit_Indices_.empty();

    return recording_;
}

bool VulkanReplayDumpResourcesBase::MustDumpQueueSubmitIndex(uint64_t index) const
{
    for (auto it = BeginCommandBufferQueueSubmit_Indices_.begin(); it != BeginCommandBufferQueueSubmit_Indices_.end();
         ++it)
    {
        if (it->second == index)
        {
            return true;
        }
    }

    return false;
}

bool VulkanReplayDumpResourcesBase::IsRecording(VkCommandBuffer original_command_buffer) const
{
    if (recording_)
    {
        const std::vector<const DrawCallsDumpingContext*> dc_contexts =
            FindDrawCallCommandBufferContext(original_command_buffer);
        for (auto dc_context : dc_contexts)
        {
            if (dc_context->IsRecording())
            {
                return true;
            }
        }

        const std::vector<const DispatchTraceRaysDumpingContext*> dr_contexts =
            FindDispatchRaysCommandBufferContext(original_command_buffer);
        for (auto dr_context : dr_contexts)
        {
            if (dr_context->IsRecording())
            {
                return true;
            }
        }
    }

    return false;
}

void VulkanReplayDumpResourcesBase::ResetCommandBuffer(VkCommandBuffer original_command_buffer)
{
    const std::vector<DrawCallsDumpingContext*> dc_contexts = FindDrawCallCommandBufferContext(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->Release();
    }

    const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
        FindDispatchRaysCommandBufferContext(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->Release();
    }
}

void VulkanReplayDumpResourcesBase::DumpGraphicsPipelineInfos(
    const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    uint32_t                                                          createInfoCount,
    HandlePointerDecoder<VkPipeline>*                                 pPipelines)
{
    const VkGraphicsPipelineCreateInfo*         in_p_create_infos = pCreateInfos->GetPointer();
    const Decoded_VkGraphicsPipelineCreateInfo* create_info_meta  = pCreateInfos->GetMetaStructPointer();

    for (uint32_t i = 0; i < createInfoCount; ++i)
    {
        VulkanPipelineInfo* pipeline_info = reinterpret_cast<VulkanPipelineInfo*>(pPipelines->GetConsumerData(i));

        // Copy vertex input state information
        if (in_p_create_infos != nullptr && in_p_create_infos[i].pVertexInputState)
        {
            // Vertex binding info
            for (uint32_t vb = 0; vb < in_p_create_infos[i].pVertexInputState->vertexBindingDescriptionCount; ++vb)
            {
                VulkanPipelineInfo::InputBindingDescription info{
                    in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].stride,
                    in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].inputRate
                };

                uint32_t binding = in_p_create_infos[i].pVertexInputState->pVertexBindingDescriptions[vb].binding;
                pipeline_info->vertex_input_binding_map.emplace(binding, info);
            }

            // Vertex attribute info
            for (uint32_t va = 0; va < in_p_create_infos[i].pVertexInputState->vertexAttributeDescriptionCount; ++va)
            {
                VulkanPipelineInfo::InputAttributeDescription info{
                    in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].binding,
                    in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].format,
                    in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].offset
                };

                uint32_t location = in_p_create_infos[i].pVertexInputState->pVertexAttributeDescriptions[va].location;
                pipeline_info->vertex_input_attribute_map.emplace(location, info);
            }
        }

        // Dynamic state
        if (in_p_create_infos != nullptr && in_p_create_infos[i].pDynamicState)
        {
            for (uint32_t ds = 0; ds < in_p_create_infos[i].pDynamicState->dynamicStateCount; ++ds)
            {
                if (in_p_create_infos[i].pDynamicState->pDynamicStates[ds] == VK_DYNAMIC_STATE_VERTEX_INPUT_EXT)
                {
                    pipeline_info->dynamic_vertex_input = true;
                }
                else if (in_p_create_infos[i].pDynamicState->pDynamicStates[ds] ==
                         VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT)
                {
                    pipeline_info->dynamic_vertex_binding_stride = true;
                }
            }
        }

        // handle optional VkGraphicsPipelineLibraryCreateInfoEXT
        const auto* gpl_info =
            graphics::vulkan_struct_get_pnext<VkGraphicsPipelineLibraryCreateInfoEXT>(in_p_create_infos);
        if (gpl_info != nullptr)
        {
            pipeline_info->gpl_flags = gpl_info->flags;
        }

        // handle optional VkPipelineLibraryCreateInfoKHR
        const auto* pipeline_library_info =
            GetPNextMetaStruct<Decoded_VkPipelineLibraryCreateInfoKHR>(create_info_meta->pNext);
        if (pipeline_library_info != nullptr)
        {
            const uint32_t          library_count = pipeline_library_info->pLibraries.GetLength();
            const format::HandleId* ppl_ids       = pipeline_library_info->pLibraries.GetPointer();

            for (uint32_t lib_idx = 0; lib_idx < library_count; ++lib_idx)
            {
                const VulkanPipelineInfo* gpl_ppl = object_info_table_->GetVkPipelineInfo(ppl_ids[lib_idx]);

                if ((gpl_ppl->gpl_flags & VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT) ==
                    VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT)
                {
                    pipeline_info->vertex_input_attribute_map    = gpl_ppl->vertex_input_attribute_map;
                    pipeline_info->vertex_input_binding_map      = gpl_ppl->vertex_input_binding_map;
                    pipeline_info->dynamic_vertex_input          = gpl_ppl->dynamic_vertex_input;
                    pipeline_info->dynamic_vertex_binding_stride = gpl_ppl->dynamic_vertex_binding_stride;
                }

                // Accumulate shader stages from the other pipelines from the library
                pipeline_info->shader_stages |= gpl_ppl->shader_stages;
            }
        }

        // Copy pipeline layout information
        if (create_info_meta != nullptr)
        {
            const auto ppl_layout_info = object_info_table_->GetVkPipelineLayoutInfo(create_info_meta[i].layout);
            if (ppl_layout_info != nullptr)
            {
                pipeline_info->desc_set_layouts = ppl_layout_info->desc_set_layouts;
            }
        }

        // Aggregate used shader stages flags
        for (uint32_t ss = 0; ss < in_p_create_infos[i].stageCount; ++ss)
        {
            pipeline_info->shader_stages |= static_cast<VkShaderStageFlags>(in_p_create_infos[i].pStages[ss].stage);
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideEndCommandBuffer(const ApiCallInfo&     call_info,
                                                             PFN_vkEndCommandBuffer func,
                                                             VkCommandBuffer        commandBuffer)
{
    if (IsRecording(commandBuffer))
    {
        const std::vector<DispatchTraceRaysDumpingContext*> dr_contexts =
            FindDispatchRaysCommandBufferContext(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            dr_context->EndCommandBuffer();
        }
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdExecuteCommands(const ApiCallInfo&       call_info,
                                                               PFN_vkCmdExecuteCommands func,
                                                               VkCommandBuffer          commandBuffer,
                                                               uint32_t                 commandBufferCount,
                                                               const VkCommandBuffer*   pCommandBuffers)
{
    const std::vector<DrawCallsDumpingContext*> dc_primary_contexts = FindDrawCallCommandBufferContext(commandBuffer);

    for (auto dc_primary_context : dc_primary_contexts)
    {
        CommandBufferIterator primary_first, primary_last;
        dc_primary_context->GetDrawCallActiveCommandBuffers(primary_first, primary_last);

        if (dc_primary_context->ShouldHandleExecuteCommands(call_info.index))
        {
            uint32_t finalized_primaries = 0;
            for (uint32_t i = 0; i < commandBufferCount; ++i)
            {
                const std::vector<DrawCallsDumpingContext*> dc_secondary_contexts =
                    FindDrawCallCommandBufferContext(pCommandBuffers[i]);
                if (!dc_secondary_contexts.empty())
                {
                    for (auto dc_secondary_context : dc_secondary_contexts)
                    {
                        const std::vector<VkCommandBuffer>& secondarys_command_buffers =
                            dc_secondary_context->GetCommandBuffers();

                        GFXRECON_ASSERT(secondarys_command_buffers.size() <=
                                        primary_last - (primary_first + finalized_primaries));
                        for (size_t scb = 0; scb < secondarys_command_buffers.size(); ++scb)
                        {
                            func(*(primary_first + finalized_primaries), 1, &secondarys_command_buffers[scb]);
                            dc_primary_context->FinalizeCommandBuffer();
                            dc_primary_context->MergeRenderPasses(*dc_secondary_context);
                            ++finalized_primaries;
                        }

                        // All primaries have been finalized. Nothing else to do
                        if (finalized_primaries == primary_last - primary_first)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for (CommandBufferIterator primary_it = (primary_first + finalized_primaries);
                         primary_it < primary_last;
                         ++primary_it)
                    {
                        func(*primary_it, 1, &pCommandBuffers[i]);
                    }
                }
            }
            dc_primary_context->UpdateSecondaries();
        }
        else
        {
            for (CommandBufferIterator primary_it = primary_first; primary_it < primary_last; ++primary_it)
            {
                func(*primary_it, commandBufferCount, pCommandBuffers);
            }
        }
    }

    if (IsRecording(commandBuffer))
    {
        const std::vector<DispatchTraceRaysDumpingContext*> dr_primary_contexts =
            FindDispatchRaysCommandBufferContext(commandBuffer);
        for (auto dr_primary_context : dr_primary_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_primary_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                if (dr_primary_context->ShouldHandleExecuteCommands(call_info.index))
                {
                    for (uint32_t i = 0; i < commandBufferCount; ++i)
                    {
                        const std::vector<DispatchTraceRaysDumpingContext*> dr_secondary_contexts =
                            FindDispatchRaysCommandBufferContext(pCommandBuffers[i]);
                        if (!dr_secondary_contexts.empty())
                        {
                            for (auto dr_secondary_context : dr_secondary_contexts)
                            {
                                VkCommandBuffer secondary_command_buffer =
                                    dr_secondary_context->GetDispatchRaysCommandBuffer();
                                func(dispatch_rays_command_buffer, 1, &secondary_command_buffer);
                            }
                        }
                        else
                        {
                            func(dispatch_rays_command_buffer, 1, &pCommandBuffers[i]);
                        }
                    }
                    dr_primary_context->UpdateSecondaries();
                }
                else
                {
                    func(dispatch_rays_command_buffer, commandBufferCount, pCommandBuffers);
                }
            }
        }
    }
}

void VulkanReplayDumpResourcesBase::DumpResourcesSetFatalErrorHandler(std::function<void(const char*)> handler)
{
    fatal_error_handler_ = handler;
}

void VulkanReplayDumpResourcesBase::RaiseFatalError(const char* message) const
{
    if (fatal_error_handler_ != nullptr)
    {
        fatal_error_handler_(message);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBuildAccelerationStructuresKHR(
    const VulkanCommandBufferInfo*                                             original_command_buffer,
    const graphics::VulkanDeviceTable&                                         device_table,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos)
{
    auto*                                                  p_infos_meta = pInfos->GetMetaStructPointer();
    const auto*                                            p_infos      = p_infos_meta->decoded_value;
    const VkAccelerationStructureBuildRangeInfoKHR* const* range_infos  = ppBuildRangeInfos->GetPointer();

    for (uint32_t i = 0; i < infoCount; ++i)
    {
        const auto* dst_as =
            object_info_table_->GetVkAccelerationStructureKHRInfo(p_infos_meta[i].dstAccelerationStructure);
        GFXRECON_ASSERT(dst_as != nullptr);

        auto entry = acceleration_structures_context_.find(dst_as);
        if (entry != acceleration_structures_context_.end())
        {
            // Call destructor to release any resources
            acceleration_structures_context_.erase(entry);
        }

        auto new_entry =
            acceleration_structures_context_.emplace(dst_as,
                                                     std::make_shared<AccelerationStructureDumpResourcesContext>(
                                                         dst_as, device_table, *object_info_table_, address_trackers_));

        VkResult res = new_entry.first->second->CloneBuildAccelerationStructuresInputBuffers(
            (original_command_buffer != nullptr) ? original_command_buffer->handle : VK_NULL_HANDLE,
            &p_infos_meta[i],
            range_infos[i],
            dump_as_build_input_buffers_);
        if (res != VK_SUCCESS)
        {
            return;
        }
    }
}

void VulkanReplayDumpResourcesBase::HandleCmdCopyAccelerationStructureKHR(
    const graphics::VulkanDeviceTable&        device_table,
    const VulkanAccelerationStructureKHRInfo* src,
    const VulkanAccelerationStructureKHRInfo* dst)
{
    GFXRECON_ASSERT(src != nullptr);
    GFXRECON_ASSERT(dst != nullptr);

    const auto src_context_entry = acceleration_structures_context_.find(src);
    if (src_context_entry == acceleration_structures_context_.end())
    {
        return;
    }

    const auto dst_context_entry = acceleration_structures_context_.find(dst);
    if (dst_context_entry != acceleration_structures_context_.end())
    {
        acceleration_structures_context_.erase(dst_context_entry);
    }

    acceleration_structures_context_.emplace(dst, src_context_entry->second);
}

void VulkanReplayDumpResourcesBase::HandleDestroyAccelerationStructureKHR(
    const VulkanAccelerationStructureKHRInfo* as_info)
{
    if (as_info != nullptr)
    {
        const auto& entry = acceleration_structures_context_.find(as_info);
        if (entry != acceleration_structures_context_.end())
        {
            acceleration_structures_context_.erase(entry);
        }
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
