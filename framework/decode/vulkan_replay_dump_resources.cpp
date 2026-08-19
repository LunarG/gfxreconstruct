/*
** Copyright (c) 2024-2025 LunarG, Inc.
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

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/vulkan_descriptor_utils.h"
#include "decode/vulkan_device_address_tracker.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_delegate.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_dump_resources_transfer.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "graphics/vulkan_submit_info_util.h"
#include "vulkan_replay_dump_resources.h"
#include "decode/vulkan_pnext_node.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "util/logging.h"

#include <algorithm>
#include <cstddef>
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>

#if !defined(_WIN32)
#include <dirent.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReplayDumpResourcesBase::VulkanReplayDumpResourcesBase(const VulkanReplayOptions&            options,
                                                             CommonObjectInfoTable*                object_info_table,
                                                             const VulkanPerDeviceAddressTrackers& address_trackers,
                                                             const graphics::InstanceDispatchTablesMap& instance_tables,
                                                             const graphics::DeviceDispatchTablesMap&   device_tables) :
    BeginCommandBufferQueueSubmit_Indices_(options.BeginCommandBufferQueueSubmit_Indices),
    active_contexts_(0), dump_resources_before_(options.dump_resources_before), object_info_table_(object_info_table),
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

    if (options.Draw_Indices.empty() && options.Dispatch_Indices.empty() && options.TraceRays_Indices.empty() &&
        options.Transfer_Indices.empty())
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
        default_delegate_ = std::make_unique<DefaultVulkanDumpResourcesDelegate>(options, *object_info_table);
        active_delegate_  = default_delegate_.get();
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
        const bool has_transfer = options.Transfer_Indices.size() && options.Transfer_Indices[i].size();

        if (has_draw)
        {
            draw_call_contexts_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(bcb_index, qs_index),
                std::forward_as_tuple(std::make_unique<DrawCallsDumpingContext>(&options.Draw_Indices[i],
                                                                                &options.RenderPass_Indices[i],
                                                                                bcb_index,
                                                                                qs_index,
                                                                                options.DrawSubresources,
                                                                                *object_info_table,
                                                                                options,
                                                                                *active_delegate_,
                                                                                compressor_.get(),
                                                                                acceleration_structures_context_,
                                                                                address_trackers)));
        }

        if (has_dispatch)
        {
            dispatch_ray_contexts_.emplace(std::piecewise_construct,
                                           std::forward_as_tuple(bcb_index, qs_index),
                                           std::forward_as_tuple(std::make_unique<DispatchTraceRaysDumpingContext>(
                                               (options.Dispatch_Indices.size() && options.Dispatch_Indices[i].size())
                                                   ? &options.Dispatch_Indices[i]
                                                   : nullptr,
                                               options.DispatchSubresources,
                                               (options.TraceRays_Indices.size() && options.TraceRays_Indices[i].size())
                                                   ? &options.TraceRays_Indices[i]
                                                   : nullptr,
                                               bcb_index,
                                               qs_index,
                                               options.TraceRaysSubresources,
                                               *object_info_table_,
                                               options,
                                               *active_delegate_,
                                               compressor_.get(),
                                               acceleration_structures_context_,
                                               address_trackers)));
        }

        if (has_transfer)
        {
            transfer_contexts_.emplace(
                std::piecewise_construct,
                std::forward_as_tuple(bcb_index, qs_index),
                std::forward_as_tuple(std::make_unique<TransferDumpingContext>(&options.Transfer_Indices[i],
                                                                               bcb_index,
                                                                               qs_index,
                                                                               *object_info_table_,
                                                                               instance_tables,
                                                                               device_tables,
                                                                               options,
                                                                               *active_delegate_,
                                                                               address_trackers,
                                                                               acceleration_structures_context_,
                                                                               compressor_.get())));
        }

        if (!qs_index && !bcb_index)
        {
            // Zero BeginCommandBuffer and QueueSubmit indices indicates that there is request to dump transfer commands
            // from the state setup section.
            active_contexts_ = 1;
        }
    }

    // Once all contexts are created do a second pass and assign the secondaries to the primaries they are executed
    // from. For each pair (BCBp, QS) for a primary that executes a secondary there should be the secondary's
    // corresponding (BCBs, QS) pair. QS is the same block index for both Primary and Secondary since in the end they
    // are submitted in the same QueueSubmit index. A primary that has one BCB but is submitted in multiple QS is a
    // different context and should be paired with the corresponding secondary's context (if that secondary is marked
    // for dumping too).
    //
    // An example:
    // (BCBp, QS0), (BCBp, QS1), (BCBs, QS0), (BSBs, QS1)
    // The same recorded primary (BSBp) is marked for dumping in two different queue submissions (QS0 and QS1).
    // The primary executes the secondary recorded in BCBs. This request will create 4 draw call dumping contexts:
    // (BCBp, QS0): Primary context 0 (PC0)
    // (BCBp, QS1): Primary context 1 (PC1)
    // (BCBs, QS0): Secondary context 0 (SC0)
    // (BCBs, QS1): Secondary context 1 (SC1)
    // PC0 must be assigned with SC0 and PC1 with SC1.
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

        std::shared_ptr<DrawCallsDumpingContext> primary_dc_context =
            FindContext(draw_call_contexts_, bcb_index, qs_index);
        for (auto& [execute_commands_index, secondary_bcbs] : options.ExecuteCommands_Indices[i])
        {
            for (auto& secondary_bcb : secondary_bcbs)
            {
                std::shared_ptr<DrawCallsDumpingContext> secondary_dc_context =
                    FindContext(draw_call_contexts_, secondary_bcb, qs_index);
                if (secondary_dc_context != nullptr)
                {
                    // If a primary has not been marked for dumping but executes a secondary that has been marked, then
                    // that primary will not have a context created. Create one now.
                    if (primary_dc_context == nullptr)
                    {
                        auto [new_primary_it, success] =
                            draw_call_contexts_.emplace(std::piecewise_construct,
                                                        std::forward_as_tuple(bcb_index, qs_index),
                                                        std::forward_as_tuple(std::make_unique<DrawCallsDumpingContext>(
                                                            nullptr,
                                                            &options.RenderPass_Indices[i],
                                                            bcb_index,
                                                            qs_index,
                                                            options.DrawSubresources,
                                                            *object_info_table,
                                                            options,
                                                            *active_delegate_,
                                                            compressor_.get(),
                                                            acceleration_structures_context_,
                                                            address_trackers)));
                        GFXRECON_ASSERT(success);
                        primary_dc_context = new_primary_it->second;
                    }

                    primary_dc_context->AssignSecondary(execute_commands_index, secondary_dc_context);
                }
            }
        }

        std::shared_ptr<DispatchTraceRaysDumpingContext> primary_disp_context =
            FindContext(dispatch_ray_contexts_, bcb_index, qs_index);
        for (auto& [execute_commands_index, secondary_bcbs] : options.ExecuteCommands_Indices[i])
        {
            for (auto& secondary_bcb : secondary_bcbs)
            {
                std::shared_ptr<DispatchTraceRaysDumpingContext> secondary_disp_context =
                    FindContext(dispatch_ray_contexts_, secondary_bcb, qs_index);

                if (secondary_disp_context != nullptr)
                {
                    // If a primary has not been marked for dumping but executes a secondary that has been marked, then
                    // that primary will not have a context created. Create one now.
                    if (primary_disp_context == nullptr)
                    {
                        auto [new_primary_it, success] = dispatch_ray_contexts_.emplace(
                            std::piecewise_construct,
                            std::forward_as_tuple(bcb_index, qs_index),
                            std::forward_as_tuple(
                                std::make_unique<DispatchTraceRaysDumpingContext>(nullptr,
                                                                                  options.DispatchSubresources,
                                                                                  nullptr,
                                                                                  bcb_index,
                                                                                  qs_index,
                                                                                  options.TraceRaysSubresources,
                                                                                  *object_info_table_,
                                                                                  options,
                                                                                  *active_delegate_,
                                                                                  compressor_.get(),
                                                                                  acceleration_structures_context_,
                                                                                  address_trackers)));
                        GFXRECON_ASSERT(success);
                        primary_disp_context = new_primary_it->second;
                    }

                    primary_disp_context->AssignSecondary(execute_commands_index, secondary_disp_context);
                }
            }
        }
    }

    // Number of command buffers for DrawCallsDumpingContext need to be recalculated when dumping resources from
    // secondaries. This is done in a separate pass since we need to be sure that all assignments have been completed.
    if (!options.ExecuteCommands_Indices.empty())
    {
        for (size_t i = 0;
             i < BeginCommandBufferQueueSubmit_Indices_.size() && i < options.ExecuteCommands_Indices.size();
             ++i)
        {
            if (options.ExecuteCommands_Indices[i].empty())
            {
                continue;
            }

            const uint64_t bcb_index = BeginCommandBufferQueueSubmit_Indices_[i].first;
            const uint64_t qs_index  = BeginCommandBufferQueueSubmit_Indices_[i].second;

            std::shared_ptr<DrawCallsDumpingContext> primary_dc_context =
                FindContext(draw_call_contexts_, bcb_index, qs_index);
            if (primary_dc_context != nullptr)
            {
                primary_dc_context->RecaclulateCommandBuffers();
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
}

std::vector<std::shared_ptr<DrawCallsDumpingContext>>
VulkanReplayDumpResourcesBase::FindDrawCallDumpingContexts(VkCommandBuffer original_command_buffer)
{
    std::vector<std::shared_ptr<DrawCallsDumpingContext>> contexts;

    auto begin_entry = cb_bcb_map_.find(original_command_buffer);
    if (begin_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    const decode::Index bcb_index = begin_entry->second;
    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_index)
        {
            contexts.push_back(it->second);
        }
    }

    return contexts;
}

std::shared_ptr<DrawCallsDumpingContext>
VulkanReplayDumpResourcesBase::FindDrawCallDumpingContext(VkCommandBuffer original_command_buffer,
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
            return it->second;
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<DrawCallsDumpingContext>>
VulkanReplayDumpResourcesBase::FindDrawCallDumpingContexts(uint64_t bcb_id)
{
    std::vector<std::shared_ptr<DrawCallsDumpingContext>> contexts;

    for (auto it = draw_call_contexts_.begin(); it != draw_call_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(it->second);
        }
    }

    return contexts;
}

std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>>
VulkanReplayDumpResourcesBase::FindDispatchTraceRaysContexts(uint64_t bcb_id)
{
    std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> contexts;

    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_id)
        {
            contexts.push_back(it->second);
        }
    }

    return contexts;
}

std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>>
VulkanReplayDumpResourcesBase::FindDispatchTraceRaysContexts(VkCommandBuffer original_command_buffer)
{
    std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> contexts;

    auto bcb_entry = cb_bcb_map_.find(original_command_buffer);
    if (bcb_entry == cb_bcb_map_.end())
    {
        return contexts;
    }

    const decode::Index bcb_index = bcb_entry->second;
    for (auto it = dispatch_ray_contexts_.begin(); it != dispatch_ray_contexts_.end(); ++it)
    {
        if (it->first.first == bcb_index)
        {
            contexts.push_back(it->second);
        }
    }

    return contexts;
}

std::shared_ptr<DispatchTraceRaysDumpingContext>
VulkanReplayDumpResourcesBase::FindDispatchTraceRaysContext(VkCommandBuffer original_command_buffer,
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
            return it->second;
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<TransferDumpingContext>>
VulkanReplayDumpResourcesBase::FindTransferContextCmdIndex(uint64_t cmd_index)
{
    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts;
    for (auto& transf_context : transfer_contexts_)
    {
        const CommandIndices& cmd_indices = transf_context.second->GetCommandIndices();
        if (std::find(cmd_indices.begin(), cmd_indices.end(), cmd_index) != cmd_indices.end())
        {
            transf_contexts.push_back(transf_context.second);
        }
    }

    return transf_contexts;
}

std::vector<std::shared_ptr<const TransferDumpingContext>>
VulkanReplayDumpResourcesBase::FindTransferContextBcbIndex(uint64_t bcb_index) const
{
    std::vector<std::shared_ptr<const TransferDumpingContext>> transf_contexts;

    for (auto& transf_context : transfer_contexts_)
    {
        if (transf_context.first.first == bcb_index)
        {
            transf_contexts.push_back(transf_context.second);
        }
    }

    return transf_contexts;
}

template <typename MapOfContexts>
void VulkanReplayDumpResourcesBase::ReleaseDumpingContexts(MapOfContexts& contexts, decode::Index qs_index)
{
    const auto count = std::erase_if(contexts, [qs_index](const auto& item) {
        const auto& [bcb_qs_pair, context] = item;
        return bcb_qs_pair.second == qs_index;
    });
    GFXRECON_ASSERT(count <= active_contexts_);
    active_contexts_ -= count;
}

void VulkanReplayDumpResourcesBase::ReleaseDumpingContexts(decode::Index qs_index)
{
    ReleaseDumpingContexts(draw_call_contexts_, qs_index);
    ReleaseDumpingContexts(dispatch_ray_contexts_, qs_index);
    ReleaseDumpingContexts(transfer_contexts_, qs_index);

    BeginCommandBufferQueueSubmit_Indices_.erase(
        std::remove_if(
            BeginCommandBufferQueueSubmit_Indices_.begin(),
            BeginCommandBufferQueueSubmit_Indices_.end(),
            [qs_index](const BeginCmdBufQueueSubmitPair& index_pair) { return index_pair.second == qs_index; }),
        BeginCommandBufferQueueSubmit_Indices_.end());

    // Once all submissions are complete release resources
    if (BeginCommandBufferQueueSubmit_Indices_.empty())
    {
        GFXRECON_ASSERT(!active_contexts_);
        Release();
    }
}

VkResult VulkanReplayDumpResourcesBase::BeginCommandBuffer(uint64_t                 bcb_index,
                                                           VulkanCommandBufferInfo* original_command_buffer_info,
                                                           const graphics::VulkanDeviceTable*   device_table,
                                                           const graphics::VulkanInstanceTable* inst_table,
                                                           const VkCommandBufferBeginInfo*      begin_info)
{
    assert(device_table);
    assert(inst_table);

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(bcb_index);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(bcb_index);
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

    const std::vector<std::shared_ptr<const TransferDumpingContext>> transf_contexts =
        FindTransferContextBcbIndex(bcb_index);

    if (!dr_contexts.empty() || !dc_contexts.empty() || !transf_contexts.empty())
    {
        active_contexts_ += dr_contexts.size() + dc_contexts.size() + transf_contexts.size();
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDraw(
            call_info, func, original_command_buffer, vertex_count, instance_count, first_vertex, first_instance);
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);

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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndirect(call_info, func, original_command_buffer, buffer_info, offset, draw_count, stride);
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);

    for (auto dc_context : dc_contexts)
    {
        dc_context->CmdDrawIndexedIndirect(
            call_info, func, original_command_buffer, buffer_info, offset, draw_count, stride);
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

                const auto num_attachments =
                    GFXRECON_NARROWING_CAST(uint32_t, attachment_begin_info->pAttachments.GetLength());
                const format::HandleId* handle_ids = attachment_begin_info->pAttachments.GetPointer();

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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

                const auto num_attachments =
                    GFXRECON_NARROWING_CAST(uint32_t, attachment_begin_info->pAttachments.GetLength());
                const format::HandleId* handle_ids = attachment_begin_info->pAttachments.GetPointer();

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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    // Do not record NextSubpass commands in current DrawCall context command buffers.
    // It will be handled by DrawCallsDumpingContext::NextSubpass
    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);

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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

void VulkanReplayDumpResourcesBase::OverrideCmdPushDescriptorSet(
    const ApiCallInfo&                                  call_info,
    PFN_vkCmdPushDescriptorSet                          func,
    VkCommandBuffer                                     original_command_buffer,
    VkPipelineBindPoint                                 pipeline_bind_point,
    const VulkanPipelineLayoutInfo*                     layout_info,
    uint32_t                                            set,
    uint32_t                                            descriptor_write_count,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes)
{
    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->PushDescriptorSet(
            PipelineBindPointToShaderStageFlags(pipeline_bind_point), set, descriptor_write_count, p_descriptor_writes);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it,
                 pipeline_bind_point,
                 layout_info->handle,
                 set,
                 descriptor_write_count,
                 p_descriptor_writes->GetPointer());
        }
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_cmd_buf = dr_context->GetDispatchRaysCommandBuffer();
        func(dr_cmd_buf,
             pipeline_bind_point,
             layout_info->handle,
             set,
             descriptor_write_count,
             p_descriptor_writes->GetPointer());

        dr_context->PushDescriptorSet(
            PipelineBindPointToShaderStageFlags(pipeline_bind_point), set, descriptor_write_count, p_descriptor_writes);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdPushDescriptorSetKHR(
    const ApiCallInfo&                                  call_info,
    PFN_vkCmdPushDescriptorSet                          func,
    VkCommandBuffer                                     original_command_buffer,
    VkPipelineBindPoint                                 pipeline_bind_point,
    const VulkanPipelineLayoutInfo*                     layout_info,
    uint32_t                                            set,
    uint32_t                                            descriptor_write_count,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* p_descriptor_writes)
{
    OverrideCmdPushDescriptorSet(call_info,
                                 func,
                                 original_command_buffer,
                                 pipeline_bind_point,
                                 layout_info,
                                 set,
                                 descriptor_write_count,
                                 p_descriptor_writes);
}

void VulkanReplayDumpResourcesBase::OverrideCmdPushDescriptorSet2(
    const ApiCallInfo&                                     call_info,
    PFN_vkCmdPushDescriptorSet2                            func,
    VkCommandBuffer                                        original_command_buffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    const auto* set_info_meta = pPushDescriptorSetInfo->GetMetaStructPointer();
    GFXRECON_ASSERT(set_info_meta != nullptr);

    const auto* set_info = pPushDescriptorSetInfo->GetPointer();
    GFXRECON_ASSERT(set_info != nullptr);

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->PushDescriptorSet(
            set_info->stageFlags, set_info->set, set_info->descriptorWriteCount, set_info_meta->pDescriptorWrites);

        CommandBufferIterator first, last;
        dc_context->GetDrawCallActiveCommandBuffers(first, last);
        for (CommandBufferIterator it = first; it < last; ++it)
        {
            func(*it, set_info);
        }
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        VkCommandBuffer dr_cmd_buf = dr_context->GetDispatchRaysCommandBuffer();
        func(dr_cmd_buf, set_info);

        dr_context->PushDescriptorSet(
            set_info->stageFlags, set_info->set, set_info->descriptorWriteCount, set_info_meta->pDescriptorWrites);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                                     call_info,
    PFN_vkCmdPushDescriptorSet2KHR                         func,
    VkCommandBuffer                                        original_command_buffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    OverrideCmdPushDescriptorSet2(call_info, func, original_command_buffer, pPushDescriptorSetInfo);
}

void VulkanReplayDumpResourcesBase::OverrideCmdBindDescriptorSets2(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdBindDescriptorSets2                            func,
    VkCommandBuffer                                         original_command_buffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    const auto bind_meta = pBindDescriptorSetsInfo->GetMetaStructPointer();

    std::vector<VkPipelineBindPoint> bind_points =
        graphics::ShaderStageFlagsToPipelineBindPoints(bind_meta->decoded_value->stageFlags);

    const auto layout_info = object_info_table_->GetVkPipelineLayoutInfo(bind_meta->layout);

    std::vector<const VulkanDescriptorSetInfo*> desc_set_infos(bind_meta->decoded_value->descriptorSetCount, nullptr);

    for (uint32_t i = 0; i < bind_meta->decoded_value->descriptorSetCount; ++i)
    {
        const VulkanDescriptorSetInfo* desc_set_info =
            object_info_table_->GetVkDescriptorSetInfo(bind_meta->pDescriptorSets.GetPointer()[i]);
        desc_set_infos[i] = desc_set_info;
    }

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdDispatch(call_info, func, original_command_buffer, groupCountX, groupCountY, groupCountZ);
    }

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdDispatchIndirect(call_info, func, original_command_buffer, buffer_info, offset);
    }

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const VkStridedDeviceAddressRegionKHR* in_pRaygenShaderBindingTable   = pRaygenShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pMissShaderBindingTable     = pMissShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pHitShaderBindingTable      = pHitShaderBindingTable->GetPointer();
    const VkStridedDeviceAddressRegionKHR* in_pCallableShaderBindingTable = pCallableShaderBindingTable->GetPointer();

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
    GFXRECON_ASSERT(IsRecording());

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
    for (auto dr_context : dr_contexts)
    {
        dr_context->CmdTraceRaysIndirect2KHR(call_info, func, original_command_buffer, indirectDeviceAddress);
    }

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
    assert(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
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
            dc_context->RecordCmdBeginRendering(*it, pRenderingInfo->GetPointer());
        }
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
    assert(IsRecording());

    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        if (dc_context->ShouldHandleRenderPass(call_info.index))
        {
            dc_context->EndRendering();
        }
        else
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                dc_context->RecordCmdEndRendering(*it);
            }
        }
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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

VkResult VulkanReplayDumpResourcesBase::QueueSubmit(std::span<const VkSubmitInfo>      submit_infos,
                                                    const graphics::VulkanDeviceTable& device_table,
                                                    const VulkanQueueInfo*             queue,
                                                    VkFence                            fence,
                                                    uint64_t                           index)
{
    // Losslessly widen each VkSubmitInfo into a VkSubmitInfo2 and forward to the canonical QueueSubmit2 implementation.
    // The translator owns the storage referenced by the produced VkSubmitInfo2 array and must outlive the submit call.
    graphics::SubmitInfo2Translator translated(submit_infos);

    return QueueSubmit2(translated.GetSubmitInfos2(), device_table, queue, fence, index);
}

VkResult VulkanReplayDumpResourcesBase::QueueSubmit2(std::span<const VkSubmitInfo2>     submit_infos,
                                                     const graphics::VulkanDeviceTable& device_table,
                                                     const VulkanQueueInfo*             queue_info,
                                                     VkFence                            fence,
                                                     uint64_t                           qs_index)
{
#define CHECK_VK_ERROR(_res_, _func_)                                                                               \
    if (_res_ != VK_SUCCESS)                                                                                        \
    {                                                                                                               \
        GFXRECON_LOG_ERROR("[%s:%u] %s failed with %s", __FILE__, __LINE__, _func_, util::ToString(_res_).c_str()); \
        Release();                                                                                                  \
        return _res_;                                                                                               \
    }

    std::map<std::pair<Index, Index>, std::shared_ptr<TransferDumpingContext>>          transfer_contexts;
    std::map<std::pair<Index, Index>, std::shared_ptr<DispatchTraceRaysDumpingContext>> dispatch_contexts;

    if (!output_json_per_command)
    {
        active_delegate_->DumpStart();
    }

    const size_t submit_count = submit_infos.size();
    for (size_t si = 0; si < submit_count; ++si)
    {
        std::vector<VkCommandBufferSubmitInfo> submit_cbs;
        VkResult                               res = VK_SUCCESS;

        // For each VkSubmitInfo2 we shall create a different fence. The provided fence will be used only in the last
        // VkSubmitInfo2. If none is provided then we will create one.
        const bool     last_submit_info  = (si == submit_count - 1);
        const bool     create_temp_fence = (!last_submit_info) || (last_submit_info && (fence == VK_NULL_HANDLE));
        TemporaryFence submission_fence(create_temp_fence ? VK_NULL_HANDLE : fence, queue_info->parent, device_table);

        VkSubmitInfo2 modified_submit_info = submit_infos[si];
        for (uint32_t cb = 0; cb < submit_infos[si].commandBufferInfoCount; ++cb)
        {
            const bool            last_cmd_buf   = (cb == submit_infos[si].commandBufferInfoCount - 1);
            const VkCommandBuffer command_buffer = submit_infos[si].pCommandBufferInfos[cb].commandBuffer;

            // The command_buffer (primary) is not marked for dumping
            if (cb_bcb_map_.find(command_buffer) == cb_bcb_map_.end())
            {
                submit_cbs.push_back(VkCommandBufferSubmitInfo{
                    VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, nullptr, command_buffer, 0 });

                // Look for transfer contexts from secondaries. This case can happen when command_buffer is a primary
                // which is not marked for dumping but contains vkCmdExecuteCommands with secondaries that are marked to
                // dump transfer
                for (auto& [bcb_qs_pair, transf_context] : transfer_contexts_)
                {
                    if (bcb_qs_pair.second == qs_index)
                    {
                        transfer_contexts.emplace(std::make_pair(static_cast<Index>(si), static_cast<Index>(cb)),
                                                  transf_context);
                    }
                }
            }
            else
            {
                bool has_transfer_or_dispatch = false;

                // Look for transfer contexts (both primary and secondary) submitted in this queue submission.
                for (auto& [bcb_qs_pair, transf_context] : transfer_contexts_)
                {
                    if (bcb_qs_pair.second == qs_index)
                    {
                        transfer_contexts.emplace(std::make_pair(static_cast<Index>(si), static_cast<Index>(cb)),
                                                  transf_context);
                        submit_cbs.push_back(VkCommandBufferSubmitInfo{
                            VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, nullptr, command_buffer, 0 });
                        has_transfer_or_dispatch = true;
                    }
                }

                // Handle Dispatch/TraceRays commands
                if (auto dispatch_context = FindDispatchTraceRaysContext(command_buffer, qs_index))
                {
                    dispatch_contexts.emplace(std::make_pair(static_cast<Index>(si), static_cast<Index>(cb)),
                                              dispatch_context);
                    // Dispatch/RayTracing context uses a clone command buffer. We submit that one instead of the
                    // original.
                    submit_cbs.push_back(VkCommandBufferSubmitInfo{ VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO,
                                                                    nullptr,
                                                                    dispatch_context->GetDispatchRaysCommandBuffer(),
                                                                    0 });
                    has_transfer_or_dispatch = true;
                }

                // Handle Draw commands
                if (auto dc_context = FindDrawCallDumpingContext(command_buffer, qs_index))
                {
                    // Submit previous command buffers from this VkSubmitInfo before dumping draw calls
                    if (!submit_cbs.empty())
                    {
                        modified_submit_info.commandBufferInfoCount = static_cast<uint32_t>(submit_cbs.size());
                        modified_submit_info.pCommandBufferInfos    = submit_cbs.data();
                        res                                         = SubmitInfo2OnQueue(
                            device_table, queue_info->handle, modified_submit_info, submission_fence.handle);
                        CHECK_VK_ERROR(res, "QueueSubmit")

                        // The fence might be reused. Wait and reset
                        res = submission_fence.Wait();
                        CHECK_VK_ERROR(res, "WaitForFences")

                        // If there's nothing else to submit then don't reset the fence in case this is the fence
                        // provided in the original QueueSubmit and the application will do a wait on the fence after
                        // the submit
                        if (!last_submit_info || (last_submit_info && !last_cmd_buf))
                        {
                            res = submission_fence.Reset();
                            CHECK_VK_ERROR(res, "ResetFences")
                        }

                        // The semaphores have been used up by the submission. Don't use them again.
                        modified_submit_info.waitSemaphoreInfoCount   = 0;
                        modified_submit_info.pWaitSemaphoreInfos      = nullptr;
                        modified_submit_info.signalSemaphoreInfoCount = 0;
                        modified_submit_info.pSignalSemaphoreInfos    = nullptr;
                        submit_cbs.clear();
                    }

                    res = dc_context->DumpDrawCalls(
                        queue_info->handle, modified_submit_info, static_cast<Index>(si), static_cast<Index>(cb));
                    CHECK_VK_ERROR(res, "DumpDrawCalls")

                    // The semaphores have been used up by the submission. Don't use them again.
                    modified_submit_info.waitSemaphoreInfoCount   = 0;
                    modified_submit_info.pWaitSemaphoreInfos      = nullptr;
                    modified_submit_info.signalSemaphoreInfoCount = 0;
                    modified_submit_info.pSignalSemaphoreInfos    = nullptr;

                    // Insert original command buffer in the vector for submission. If has_transfer_or_dispatch is true
                    // then the command buffer has already been submitted
                    if (!has_transfer_or_dispatch)
                    {
                        GFXRECON_ASSERT(submit_cbs.empty());
                        submit_cbs.push_back(VkCommandBufferSubmitInfo{
                            VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO, nullptr, command_buffer, 0 });
                    }
                }
            }
        }

        if (!submit_cbs.empty())
        {
            modified_submit_info.commandBufferInfoCount = static_cast<uint32_t>(submit_cbs.size());
            modified_submit_info.pCommandBufferInfos    = submit_cbs.data();
            res = SubmitInfo2OnQueue(device_table, queue_info->handle, modified_submit_info, submission_fence.handle);
            CHECK_VK_ERROR(res, "QueueSubmit")

            res = submission_fence.Wait();
            CHECK_VK_ERROR(res, "WaitForFences")

            submit_cbs.clear();
        }
    }

    for (auto& [pair, transfer_context] : transfer_contexts)
    {
        VkResult res = transfer_context->DumpTransferCommands(pair.first, pair.second);
        CHECK_VK_ERROR(res, "DumpTransferCommands")
    }

    for (auto& [pair, disp_context] : dispatch_contexts)
    {
        VkResult res = disp_context->DumpDispatchTraceRays(pair.first, pair.second);
        CHECK_VK_ERROR(res, "DumpDispatchTraceRays")
    }

    if (!output_json_per_command)
    {
        active_delegate_->DumpEnd();
    }

    ReleaseDumpingContexts(qs_index);

    return VK_SUCCESS;
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

void VulkanReplayDumpResourcesBase::ResetCommandBuffer(VkCommandBuffer original_command_buffer)
{
    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
        FindDrawCallDumpingContexts(original_command_buffer);
    for (auto dc_context : dc_contexts)
    {
        dc_context->Release();
    }

    const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
        FindDispatchTraceRaysContexts(original_command_buffer);
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
            const auto library_count = GFXRECON_NARROWING_CAST(uint32_t, pipeline_library_info->pLibraries.GetLength());
            const format::HandleId* ppl_ids = pipeline_library_info->pLibraries.GetPointer();

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
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
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
    const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_primary_contexts =
        FindDrawCallDumpingContexts(commandBuffer);

    for (auto dc_primary_context : dc_primary_contexts)
    {
        CommandBufferIterator primary_first, primary_last;
        dc_primary_context->GetDrawCallActiveCommandBuffers(primary_first, primary_last);

        std::vector<std::shared_ptr<DrawCallsDumpingContext>> secondaries_to_execute =
            dc_primary_context->SecondariesToExecute(call_info.index);
        if (!secondaries_to_execute.empty())
        {
            uint32_t                     finalized_primaries = 0;
            std::vector<VkCommandBuffer> accumulated_secondaries_command_buffers;
            for (uint32_t i = 0; (i < commandBufferCount); ++i)
            {
                // Handle the executed secondaries that are marked for dumping separately
                auto secondary_to_execute = secondaries_to_execute.begin();
                for (; secondary_to_execute != secondaries_to_execute.end(); ++secondary_to_execute)
                {
                    if (pCommandBuffers[i] == secondary_to_execute->get()->GetOriginalCommandBuffer())
                    {
                        break;
                    }
                }

                if (secondary_to_execute != secondaries_to_execute.end())
                {
                    const std::vector<VkCommandBuffer>& secondaries_command_buffers =
                        secondary_to_execute->get()->GetCommandBuffers();
                    GFXRECON_ASSERT(secondaries_command_buffers.size() <=
                                    primary_last - (primary_first + finalized_primaries));
                    for (size_t scb = 0; scb < secondaries_command_buffers.size(); ++scb)
                    {
                        // Each primary should execute the command buffer from the previous
                        // secondary contexts as well
                        func(*(primary_first + finalized_primaries),
                             GFXRECON_NARROWING_CAST(uint32_t, accumulated_secondaries_command_buffers.size()),
                             accumulated_secondaries_command_buffers.data());

                        func(*(primary_first + finalized_primaries), 1, &secondaries_command_buffers[scb]);
                        dc_primary_context->MergeRenderPasses(*secondary_to_execute->get());
                        ++finalized_primaries;
                    }

                    // Keep accumulating the command buffer from all secondary contexts
                    accumulated_secondaries_command_buffers.insert(accumulated_secondaries_command_buffers.end(),
                                                                   secondaries_command_buffers.begin(),
                                                                   secondaries_command_buffers.end());

                    // The other primaries need to execute this secondary as well
                    for (CommandBufferIterator primary_it = (primary_first + finalized_primaries);
                         primary_it < primary_last;
                         ++primary_it)
                    {
                        func(*primary_it, 1, &pCommandBuffers[i]);
                    }

                    dc_primary_context->UpdateSecondaries(*secondary_to_execute->get(), call_info.index, i);

                    // All primaries have been finalized. Nothing else to do
                    if (finalized_primaries == primary_last - primary_first)
                    {
                        break;
                    }

                    // Dumping the same secondary multiple times from the same execution is not handled yet.
                    // Remove the entry from the vector to prevent from attempting to handle the same secondary again
                    secondaries_to_execute.erase(secondary_to_execute);
                }
                else
                {
                    // The command buffer either has no dumping context or its context belongs to a
                    // different vkCmdExecuteCommands call.
                    for (CommandBufferIterator primary_it = (primary_first + finalized_primaries);
                         primary_it < primary_last;
                         ++primary_it)
                    {
                        func(*primary_it, 1, &pCommandBuffers[i]);
                    }
                }
            }
        }
        else
        {
            for (CommandBufferIterator primary_it = primary_first; primary_it < primary_last; ++primary_it)
            {
                func(*primary_it, commandBufferCount, pCommandBuffers);
            }
        }
    }

    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_primary_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_primary_context : dr_primary_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_primary_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> secondaries_to_execute =
                    dr_primary_context->SecondariesToExecute(call_info.index);
                if (!secondaries_to_execute.empty())
                {
                    for (uint32_t i = 0; i < commandBufferCount; ++i)
                    {
                        // Handle the executed secondaries that are marked for dumping separately
                        auto secondary_to_execute = secondaries_to_execute.begin();
                        for (; secondary_to_execute != secondaries_to_execute.end(); ++secondary_to_execute)
                        {
                            if (pCommandBuffers[i] == secondary_to_execute->get()->GetOriginalCommandBuffer())
                            {
                                break;
                            }
                        }

                        if (secondary_to_execute != secondaries_to_execute.end())
                        {
                            VkCommandBuffer secondary_command_buffer =
                                secondary_to_execute->get()->GetDispatchRaysCommandBuffer();
                            func(dispatch_rays_command_buffer, 1, &secondary_command_buffer);

                            dr_primary_context->UpdateSecondaries(*secondary_to_execute->get(), call_info.index, i);

                            // Dumping the same secondary multiple times from the same execution is not handled yet.
                            // Remove the entry from the vector to prevent from attempting to handle the same secondary
                            // again
                            secondaries_to_execute.erase(secondary_to_execute);
                        }
                        else
                        {
                            func(dispatch_rays_command_buffer, 1, &pCommandBuffers[i]);
                        }
                    }
                }
                else
                {
                    func(dispatch_rays_command_buffer, commandBufferCount, pCommandBuffers);
                }
            }
        }
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
    const auto*                                            p_infos      = pInfos->GetPointer();
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
            p_infos[i],
            range_infos[i],
            dump_as_build_input_buffers_,
            false);
        if (res != VK_SUCCESS)
        {
            return;
        }
    }
}

void VulkanReplayDumpResourcesBase::HandleCmdCopyAccelerationStructureKHR(
    const graphics::VulkanDeviceTable&        device_table,
    const VulkanCommandBufferInfo*            original_command_buffer,
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

    auto new_entry =
        acceleration_structures_context_.emplace(dst,
                                                 std::make_shared<AccelerationStructureDumpResourcesContext>(
                                                     dst, device_table, *object_info_table_, address_trackers_));
    new_entry.first->second->CloneBuildAccelerationStructuresInputBuffers(
        (original_command_buffer != nullptr) ? original_command_buffer->handle : VK_NULL_HANDLE,
        *src_context_entry->second,
        dump_as_build_input_buffers_);
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

void VulkanReplayDumpResourcesBase::ProcessInitBufferCommand(
    uint64_t cmd_index, format::HandleId device_id, format::HandleId buffer_id, uint64_t data_size, const uint8_t* data)
{
    std::shared_ptr<TransferDumpingContext> transf_context = FindContext(transfer_contexts_, 0, 0);
    if (transf_context != nullptr)
    {
        transf_context->HandleInitBufferCommand(cmd_index, device_id, buffer_id, data_size, data);
    }
}

void VulkanReplayDumpResourcesBase::ProcessInitImageCommand(VkCommandBuffer              command_buffer,
                                                            uint64_t                     cmd_index,
                                                            format::HandleId             device_id,
                                                            format::HandleId             image_id,
                                                            uint64_t                     data_size,
                                                            uint32_t                     aspect,
                                                            uint32_t                     layout,
                                                            const std::vector<uint64_t>& level_sizes,
                                                            const uint8_t*               data)
{
    std::shared_ptr<TransferDumpingContext> transf_context = FindContext(transfer_contexts_, 0, 0);
    if (transf_context != nullptr)
    {
        transf_context->HandleInitImageCommand(command_buffer,
                                               cmd_index,
                                               device_id,
                                               image_id,
                                               data_size,
                                               static_cast<VkImageAspectFlagBits>(aspect),
                                               static_cast<VkImageLayout>(layout),
                                               level_sizes,
                                               data);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBuffer(const ApiCallInfo&                          call_info,
                                                          PFN_vkCmdCopyBuffer                         func,
                                                          VkCommandBuffer                             commandBuffer,
                                                          const VulkanBufferInfo*                     srcBuffer,
                                                          const VulkanBufferInfo*                     dstBuffer,
                                                          uint32_t                                    regionCount,
                                                          StructPointerDecoder<Decoded_VkBufferCopy>* pRegions,
                                                          bool                                        before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, srcBuffer->handle, dstBuffer->handle, regionCount, pRegions->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer, srcBuffer->handle, dstBuffer->handle, regionCount, pRegions->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBuffer(
            call_info, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions->GetPointer(), before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBuffer2(
    const ApiCallInfo&                               call_info,
    PFN_vkCmdCopyBuffer2                             func,
    VkCommandBuffer                                  commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
    bool                                             before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyBufferInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer, pCopyBufferInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBuffer2(call_info, commandBuffer, pCopyBufferInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBuffer2KHR(
    const ApiCallInfo&                               call_info,
    PFN_vkCmdCopyBuffer2KHR                          func,
    VkCommandBuffer                                  commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
    bool                                             before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyBufferInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer, pCopyBufferInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBuffer2(call_info, commandBuffer, pCopyBufferInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBufferToImage(
    const ApiCallInfo&                               call_info,
    PFN_vkCmdCopyBufferToImage                       func,
    VkCommandBuffer                                  commandBuffer,
    const VulkanBufferInfo*                          srcBuffer,
    const VulkanImageInfo*                           dstImage,
    VkImageLayout                                    dstImageLayout,
    uint32_t                                         regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions,
    bool                                             before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, srcBuffer->handle, dstImage->handle, dstImageLayout, regionCount, pRegions->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer,
                     srcBuffer->handle,
                     dstImage->handle,
                     dstImageLayout,
                     regionCount,
                     pRegions->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBufferToImage(call_info,
                                                   commandBuffer,
                                                   srcBuffer,
                                                   dstImage,
                                                   dstImageLayout,
                                                   regionCount,
                                                   pRegions->GetPointer(),
                                                   before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBufferToImage2(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdCopyBufferToImage2                             func,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
    bool                                                    before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyBufferToImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer, pCopyBufferToImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBufferToImage2(call_info, commandBuffer, pCopyBufferToImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdCopyBufferToImage2KHR                          func,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
    bool                                                    before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyBufferToImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dr_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dr_command_buffer != VK_NULL_HANDLE)
            {
                func(dr_command_buffer, pCopyBufferToImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyBufferToImage2(call_info, commandBuffer, pCopyBufferToImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImage(const ApiCallInfo&                         call_info,
                                                         PFN_vkCmdCopyImage                         func,
                                                         VkCommandBuffer                            commandBuffer,
                                                         const VulkanImageInfo*                     srcImage,
                                                         VkImageLayout                              srcImageLayout,
                                                         const VulkanImageInfo*                     dstImage,
                                                         VkImageLayout                              dstImageLayout,
                                                         uint32_t                                   regionCount,
                                                         StructPointerDecoder<Decoded_VkImageCopy>* pRegions,
                                                         bool                                       before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it,
                     srcImage->handle,
                     srcImageLayout,
                     dstImage->handle,
                     dstImageLayout,
                     regionCount,
                     pRegions->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer,
                     srcImage->handle,
                     srcImageLayout,
                     dstImage->handle,
                     dstImageLayout,
                     regionCount,
                     pRegions->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImage(call_info,
                                           commandBuffer,
                                           srcImage,
                                           srcImageLayout,
                                           dstImage,
                                           dstImageLayout,
                                           regionCount,
                                           pRegions->GetPointer(),
                                           before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImage2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdCopyImage2                             func,
    VkCommandBuffer                                 commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
    bool                                            before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pCopyImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImage2(call_info, commandBuffer, pCopyImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImage2KHR(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdCopyImage2KHR                          func,
    VkCommandBuffer                                 commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
    bool                                            before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pCopyImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImage2(call_info, commandBuffer, pCopyImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImageToBuffer(
    const ApiCallInfo&                               call_info,
    PFN_vkCmdCopyImageToBuffer                       func,
    VkCommandBuffer                                  commandBuffer,
    const VulkanImageInfo*                           srcImage,
    VkImageLayout                                    srcImageLayout,
    const VulkanBufferInfo*                          dstBuffer,
    uint32_t                                         regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions,
    bool                                             before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, srcImage->handle, srcImageLayout, dstBuffer->handle, regionCount, pRegions->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer,
                     srcImage->handle,
                     srcImageLayout,
                     dstBuffer->handle,
                     regionCount,
                     pRegions->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImageToBuffer(call_info,
                                                   commandBuffer,
                                                   srcImage,
                                                   srcImageLayout,
                                                   dstBuffer,
                                                   regionCount,
                                                   pRegions->GetPointer(),
                                                   before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImageToBuffer2(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdCopyImageToBuffer2                             func,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
    bool                                                    before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyImageToBufferInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pCopyImageToBufferInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImageToBuffer2(call_info, commandBuffer, pCopyImageToBufferInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                                      call_info,
    PFN_vkCmdCopyImageToBuffer2                             func,
    VkCommandBuffer                                         commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
    bool                                                    before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pCopyImageToBufferInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pCopyImageToBufferInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyImageToBuffer2(call_info, commandBuffer, pCopyImageToBufferInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBlitImage(const ApiCallInfo&                         call_info,
                                                         PFN_vkCmdBlitImage                         func,
                                                         VkCommandBuffer                            commandBuffer,
                                                         const VulkanImageInfo*                     srcImage,
                                                         VkImageLayout                              srcImageLayout,
                                                         const VulkanImageInfo*                     dstImage,
                                                         VkImageLayout                              dstImageLayout,
                                                         uint32_t                                   regionCount,
                                                         StructPointerDecoder<Decoded_VkImageBlit>* pRegions,
                                                         VkFilter                                   filter,
                                                         bool                                       before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it,
                     srcImage->handle,
                     srcImageLayout,
                     dstImage->handle,
                     dstImageLayout,
                     regionCount,
                     pRegions->GetPointer(),
                     filter);
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer,
                     srcImage->handle,
                     srcImageLayout,
                     dstImage->handle,
                     dstImageLayout,
                     regionCount,
                     pRegions->GetPointer(),
                     filter);
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdBlitImage(call_info,
                                           commandBuffer,
                                           srcImage,
                                           srcImageLayout,
                                           dstImage,
                                           dstImageLayout,
                                           regionCount,
                                           pRegions->GetPointer(),
                                           filter,
                                           before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBlitImage2(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdBlitImage2                             func,
    VkCommandBuffer                                 commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
    bool                                            before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pBlitImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pBlitImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdBlitImage2(call_info, commandBuffer, pBlitImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBlitImage2KHR(
    const ApiCallInfo&                              call_info,
    PFN_vkCmdBlitImage2KHR                          func,
    VkCommandBuffer                                 commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
    bool                                            before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts =
            FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            dc_context->GetDrawCallActiveCommandBuffers(first, last);
            for (CommandBufferIterator it = first; it < last; ++it)
            {
                func(*it, pBlitImageInfo->GetPointer());
            }
        }

        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pBlitImageInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdBlitImage2(call_info, commandBuffer, pBlitImageInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                                                         call_info,
    PFN_vkCmdBuildAccelerationStructuresKHR                                    func,
    VkCommandBuffer                                                            commandBuffer,
    uint32_t                                                                   infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos,
    bool                                                                       before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command && commandBuffer != VK_NULL_HANDLE)
    {
        VkAccelerationStructureBuildGeometryInfoKHR* build_geometry_infos = pInfos->GetPointer();
        VkAccelerationStructureBuildRangeInfoKHR**   build_range_infos    = ppBuildRangeInfos->GetPointer();

        std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            bool                  found = dc_context->GetDrawCallActiveCommandBuffers(first, last);
            if (found)
            {
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, infoCount, build_geometry_infos, build_range_infos);
                }
            }
        }

        std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto& dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, infoCount, build_geometry_infos, build_range_infos);
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdBuildAccelerationStructuresKHR(
            call_info, commandBuffer, infoCount, pInfos, ppBuildRangeInfos, before_command);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                                                call_info,
    PFN_vkCmdCopyAccelerationStructureKHR                             func,
    VkCommandBuffer                                                   commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo,
    bool                                                              before_command)
{
    // In case DumpBeforeCommand is true, draw call and compute/ray tracing contexts need to be handled only once
    if (!before_command)
    {
        std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        for (auto dc_context : dc_contexts)
        {
            CommandBufferIterator first, last;
            bool                  found = dc_context->GetDrawCallActiveCommandBuffers(first, last);
            if (found)
            {
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo->GetPointer());
                }
            }
        }

        std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts =
            FindDispatchTraceRaysContexts(commandBuffer);
        for (auto& dr_context : dr_contexts)
        {
            VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
            if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
            {
                func(dispatch_rays_command_buffer, pInfo->GetPointer());
            }
        }
    }

    std::vector<std::shared_ptr<TransferDumpingContext>> transf_contexts = FindTransferContextCmdIndex(call_info.index);
    for (auto transf_context : transf_contexts)
    {
        transf_context->HandleCmdCopyAccelerationStructureKHR(call_info, commandBuffer, pInfo, before_command);
    }
}

void VulkanReplayDumpResourcesBase::ProcessStateEndMarker()
{
    std::shared_ptr<TransferDumpingContext> transfer_context = FindContext(transfer_contexts_, 0, 0);
    if (transfer_context != nullptr)
    {
        VkResult res = transfer_context->DumpTransferCommands(0, 0);
        if (res != VK_SUCCESS)
        {
            Release();
            GFXRECON_LOG_FATAL("Dumping transfer commands from state setup section failed (%s)",
                               util::ToString<VkResult>(res).c_str());
        }

        // ProcessStateEndMarker marks the end of the state setup section. If a TransferDumpingContext was assigned to
        // dump transfer commands from there then now it becomes inactive.
        ReleaseDumpingContexts(transfer_contexts_, 0);
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginQuery(const ApiCallInfo&         call_info,
                                                          PFN_vkCmdBeginQuery        func,
                                                          VkCommandBuffer            original_command_buffer,
                                                          const VulkanQueryPoolInfo* queryPool,
                                                          uint32_t                   query,
                                                          VkQueryControlFlags        flags)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, flags);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, flags);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndQuery(const ApiCallInfo&         call_info,
                                                        PFN_vkCmdEndQuery          func,
                                                        VkCommandBuffer            original_command_buffer,
                                                        const VulkanQueryPoolInfo* queryPool,
                                                        uint32_t                   query)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdResetQueryPool(const ApiCallInfo&         call_info,
                                                              PFN_vkCmdResetQueryPool    func,
                                                              VkCommandBuffer            original_command_buffer,
                                                              const VulkanQueryPoolInfo* queryPool,
                                                              uint32_t                   firstQuery,
                                                              uint32_t                   queryCount)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, firstQuery, queryCount);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, firstQuery, queryCount);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteTimestamp(const ApiCallInfo&         call_info,
                                                              PFN_vkCmdWriteTimestamp    func,
                                                              VkCommandBuffer            original_command_buffer,
                                                              VkPipelineStageFlagBits    pipelineStage,
                                                              const VulkanQueryPoolInfo* queryPool,
                                                              uint32_t                   query)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, pipelineStage, queryPool->handle, query);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, pipelineStage, queryPool->handle, query);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyQueryPoolResults(const ApiCallInfo&            call_info,
                                                                    PFN_vkCmdCopyQueryPoolResults func,
                                                                    VkCommandBuffer            original_command_buffer,
                                                                    const VulkanQueryPoolInfo* queryPool,
                                                                    uint32_t                   firstQuery,
                                                                    uint32_t                   queryCount,
                                                                    const VulkanBufferInfo*    dstBuffer,
                                                                    VkDeviceSize               dstOffset,
                                                                    VkDeviceSize               stride,
                                                                    VkQueryResultFlags         flags)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(
                command_buffer, queryPool->handle, firstQuery, queryCount, dstBuffer->handle, dstOffset, stride, flags);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(
                command_buffer, queryPool->handle, firstQuery, queryCount, dstBuffer->handle, dstOffset, stride, flags);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                                            call_info,
    PFN_vkCmdCopyQueryPoolResultsToMemoryKHR                      func,
    VkCommandBuffer                                               original_command_buffer,
    const VulkanQueryPoolInfo*                                    queryPool,
    uint32_t                                                      firstQuery,
    uint32_t                                                      queryCount,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                                      dstFlags,
    VkQueryResultFlags                                            queryResultFlags)
{
    if (IsRecording())
    {
        const VkStridedDeviceAddressRangeKHR* dst_range = pDstRange->GetPointer();
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, firstQuery, queryCount, dst_range, dstFlags, queryResultFlags);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, firstQuery, queryCount, dst_range, dstFlags, queryResultFlags);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteTimestamp2(const ApiCallInfo&         call_info,
                                                               PFN_vkCmdWriteTimestamp2   func,
                                                               VkCommandBuffer            original_command_buffer,
                                                               VkPipelineStageFlags2      stage,
                                                               const VulkanQueryPoolInfo* queryPool,
                                                               uint32_t                   query)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, stage, queryPool->handle, query);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, stage, queryPool->handle, query);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteTimestamp2KHR(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdWriteTimestamp2KHR func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  VkPipelineStageFlags2       stage,
                                                                  const VulkanQueryPoolInfo*  queryPool,
                                                                  uint32_t                    query)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, stage, queryPool->handle, query);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, stage, queryPool->handle, query);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdBeginQueryIndexedEXT(const ApiCallInfo&            call_info,
                                                                    PFN_vkCmdBeginQueryIndexedEXT func,
                                                                    VkCommandBuffer            original_command_buffer,
                                                                    const VulkanQueryPoolInfo* queryPool,
                                                                    uint32_t                   query,
                                                                    VkQueryControlFlags        flags,
                                                                    uint32_t                   index)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, flags, index);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, flags, index);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdEndQueryIndexedEXT(const ApiCallInfo&          call_info,
                                                                  PFN_vkCmdEndQueryIndexedEXT func,
                                                                  VkCommandBuffer             original_command_buffer,
                                                                  const VulkanQueryPoolInfo*  queryPool,
                                                                  uint32_t                    query,
                                                                  uint32_t                    index)
{
    if (IsRecording())
    {
        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, index);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, queryPool->handle, query, index);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                               call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV func,
    VkCommandBuffer                                  original_command_buffer,
    uint32_t                                         accelerationStructureCount,
    const format::HandleId*                          pAccelerationStructures,
    VkQueryType                                      queryType,
    const VulkanQueryPoolInfo*                       queryPool,
    uint32_t                                         firstQuery)
{
    if (IsRecording())
    {
        std::vector<VkAccelerationStructureNV> acceleration_structures(accelerationStructureCount, VK_NULL_HANDLE);
        for (uint32_t i = 0; i < accelerationStructureCount; ++i)
        {
            const VulkanAccelerationStructureNVInfo* as_info =
                object_info_table_->GetVkAccelerationStructureNVInfo(pAccelerationStructures[i]);
            acceleration_structures[i] = (as_info != nullptr) ? as_info->handle : VK_NULL_HANDLE;
        }

        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer,
                 accelerationStructureCount,
                 acceleration_structures.data(),
                 queryType,
                 queryPool->handle,
                 firstQuery);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer,
                 accelerationStructureCount,
                 acceleration_structures.data(),
                 queryType,
                 queryPool->handle,
                 firstQuery);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteMicromapsPropertiesEXT(const ApiCallInfo& call_info,
                                                                           PFN_vkCmdWriteMicromapsPropertiesEXT func,
                                                                           VkCommandBuffer original_command_buffer,
                                                                           uint32_t        micromapCount,
                                                                           const format::HandleId*    pMicromaps,
                                                                           VkQueryType                queryType,
                                                                           const VulkanQueryPoolInfo* queryPool,
                                                                           uint32_t                   firstQuery)
{
    if (IsRecording())
    {
        std::vector<VkMicromapEXT> micromaps(micromapCount, VK_NULL_HANDLE);
        for (uint32_t i = 0; i < micromapCount; ++i)
        {
            const VulkanMicromapEXTInfo* micromap_info = object_info_table_->GetVkMicromapEXTInfo(pMicromaps[i]);
            micromaps[i] = (micromap_info != nullptr) ? micromap_info->handle : VK_NULL_HANDLE;
        }

        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, micromapCount, micromaps.data(), queryType, queryPool->handle, firstQuery);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer, micromapCount, micromaps.data(), queryType, queryPool->handle, firstQuery);
        });
    }
}

void VulkanReplayDumpResourcesBase::OverrideCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                                call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR func,
    VkCommandBuffer                                   original_command_buffer,
    uint32_t                                          accelerationStructureCount,
    const format::HandleId*                           pAccelerationStructures,
    VkQueryType                                       queryType,
    const VulkanQueryPoolInfo*                        queryPool,
    uint32_t                                          firstQuery)
{
    if (IsRecording())
    {
        std::vector<VkAccelerationStructureKHR> acceleration_structures(accelerationStructureCount, VK_NULL_HANDLE);
        for (uint32_t i = 0; i < accelerationStructureCount; ++i)
        {
            const VulkanAccelerationStructureKHRInfo* as_info =
                object_info_table_->GetVkAccelerationStructureKHRInfo(pAccelerationStructures[i]);
            acceleration_structures[i] = (as_info != nullptr) ? as_info->handle : VK_NULL_HANDLE;
        }

        ForEachDrawCallCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer,
                 accelerationStructureCount,
                 acceleration_structures.data(),
                 queryType,
                 queryPool->handle,
                 firstQuery);
        });
        ForEachDispatchTraceRaysCommandBuffer(original_command_buffer, [&](VkCommandBuffer command_buffer) {
            func(command_buffer,
                 accelerationStructureCount,
                 acceleration_structures.data(),
                 queryType,
                 queryPool->handle,
                 firstQuery);
        });
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)
