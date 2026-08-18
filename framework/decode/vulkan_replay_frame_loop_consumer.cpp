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

#include "decode/custom_vulkan_struct_handle_mappers.h"

#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"
#include "decode/vulkan_replay_frame_loop_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

#define CHECK_VK_RESULT(_res_, _func_)                                        \
    {                                                                         \
        VkResult _RES = (_res_);                                              \
        if (_RES != VK_SUCCESS)                                               \
        {                                                                     \
            GFXRECON_LOG_ERROR("[%s:%u] synthetic call to %s failed with %s", \
                               __FILE__,                                      \
                               __LINE__,                                      \
                               _func_,                                        \
                               util::ToString(_RES).c_str());                 \
            std::exit(-1);                                                    \
        }                                                                     \
    }

void VulkanReplayFrameLoopConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessStateEndMarker(frame_number);

    // If trim state had to be loaded, call StartLooping() again
    if (frame_loop_info_.IsLooping())
    {
        per_device_fence_tracking_.clear();
        per_device_event_tracking_.clear();
        StartLooping();
    }
}

void VulkanReplayFrameLoopConsumer::StartLooping()
{
    WaitDevicesIdle();
    GFXRECON_LOG_DEBUG("VulkanReplayFrameLoopConsumer::StartLooping()");
    TrackFenceStates();
    TrackEventStates();
    TrackImageLayouts();
}

void VulkanReplayFrameLoopConsumer::TrackSubpass0Layouts(format::HandleId              render_pass,
                                                         const VkRenderPassCreateInfo* create_info)
{
    if (create_info == nullptr || create_info->subpassCount == 0 || create_info->pSubpasses == nullptr)
    {
        return;
    }

    const VkSubpassDescription& subpass = create_info->pSubpasses[0];
    std::vector<VkImageLayout>& layouts = render_pass_subpass_0_layouts_[render_pass];
    layouts.assign(create_info->attachmentCount, VK_IMAGE_LAYOUT_UNDEFINED);

    if (subpass.pColorAttachments != nullptr)
    {
        for (uint32_t i = 0; i < subpass.colorAttachmentCount; ++i)
        {
            const VkAttachmentReference& attachment = subpass.pColorAttachments[i];
            if (attachment.attachment < create_info->attachmentCount)
            {
                layouts[attachment.attachment] = attachment.layout;
            }
        }
    }

    if (subpass.pDepthStencilAttachment != nullptr &&
        subpass.pDepthStencilAttachment->attachment < create_info->attachmentCount)
    {
        layouts[subpass.pDepthStencilAttachment->attachment] = subpass.pDepthStencilAttachment->layout;
    }
}

void VulkanReplayFrameLoopConsumer::TrackSubpass0Layouts(format::HandleId               render_pass,
                                                         const VkRenderPassCreateInfo2* create_info)
{
    if (create_info == nullptr || create_info->subpassCount == 0 || create_info->pSubpasses == nullptr)
    {
        return;
    }

    const VkSubpassDescription2& subpass = create_info->pSubpasses[0];
    std::vector<VkImageLayout>&  layouts = render_pass_subpass_0_layouts_[render_pass];
    layouts.assign(create_info->attachmentCount, VK_IMAGE_LAYOUT_UNDEFINED);

    if (subpass.pColorAttachments != nullptr)
    {
        for (uint32_t i = 0; i < subpass.colorAttachmentCount; ++i)
        {
            const VkAttachmentReference2& attachment = subpass.pColorAttachments[i];
            if (attachment.attachment < create_info->attachmentCount)
            {
                layouts[attachment.attachment] = attachment.layout;
            }
        }
    }

    if (subpass.pDepthStencilAttachment != nullptr &&
        subpass.pDepthStencilAttachment->attachment < create_info->attachmentCount)
    {
        layouts[subpass.pDepthStencilAttachment->attachment] = subpass.pDepthStencilAttachment->layout;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateRenderPass(const ApiCallInfo&      call_info,
                                                               args::CreateRenderPass& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass(call_info, args);

    if (args.result == VK_SUCCESS && !args.pRenderPass.IsNull())
    {
        TrackSubpass0Layouts(*args.pRenderPass.GetPointer(), args.pCreateInfo.GetPointer());
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateRenderPass2(const ApiCallInfo&       call_info,
                                                                args::CreateRenderPass2& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2(call_info, args);

    if (args.result == VK_SUCCESS && !args.pRenderPass.IsNull())
    {
        TrackSubpass0Layouts(*args.pRenderPass.GetPointer(), args.pCreateInfo.GetPointer());
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateRenderPass2KHR(const ApiCallInfo&          call_info,
                                                                   args::CreateRenderPass2KHR& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2KHR(call_info, args);

    if (args.result == VK_SUCCESS && !args.pRenderPass.IsNull())
    {
        TrackSubpass0Layouts(*args.pRenderPass.GetPointer(), args.pCreateInfo.GetPointer());
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyRenderPass(const ApiCallInfo&       call_info,
                                                                args::DestroyRenderPass& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyRenderPass(call_info, args);

    if (GetObjectInfoTable().GetVkRenderPassInfo(args.renderPass) == nullptr)
    {
        render_pass_subpass_0_layouts_.erase(args.renderPass);
    }
}

void VulkanReplayFrameLoopConsumer::ApplySubpass0Layouts(format::HandleId command_buffer)
{
    VulkanCommandBufferInfo* cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(command_buffer);
    if (cb_info == nullptr)
    {
        return;
    }

    auto entry = render_pass_subpass_0_layouts_.find(cb_info->active_render_pass_id);
    if (entry == render_pass_subpass_0_layouts_.end())
    {
        return;
    }

    const std::vector<VkImageLayout>& subpass_0_layouts         = entry->second;
    const auto&                       attachment_image_view_ids = cb_info->active_render_pass_attachment_image_view_ids;
    for (size_t i = 0; i < attachment_image_view_ids.size() && i < subpass_0_layouts.size(); ++i)
    {
        if (subpass_0_layouts[i] == VK_IMAGE_LAYOUT_UNDEFINED)
        {
            continue;
        }

        VulkanImageViewInfo* image_view_info = GetObjectInfoTable().GetVkImageViewInfo(attachment_image_view_ids[i]);
        if (image_view_info != nullptr)
        {
            cb_info->image_layout_barriers[image_view_info->image_id] = subpass_0_layouts[i];
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginRenderPass(const ApiCallInfo&        call_info,
                                                                 args::CmdBeginRenderPass& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass(call_info, args);
    ApplySubpass0Layouts(args.commandBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginRenderPass2(const ApiCallInfo&         call_info,
                                                                  args::CmdBeginRenderPass2& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(call_info, args);
    ApplySubpass0Layouts(args.commandBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginRenderPass2KHR(const ApiCallInfo&            call_info,
                                                                     args::CmdBeginRenderPass2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(call_info, args);
    ApplySubpass0Layouts(args.commandBuffer);
}

void VulkanReplayFrameLoopConsumer::ApplyRenderingLayouts(format::HandleId                               command_buffer,
                                                          StructPointerDecoder<Decoded_VkRenderingInfo>& info)
{
    VulkanCommandBufferInfo*       cb_info        = GetObjectInfoTable().GetVkCommandBufferInfo(command_buffer);
    const VkRenderingInfo*         rendering_info = info.GetPointer();
    const Decoded_VkRenderingInfo* rendering_meta = info.GetMetaStructPointer();
    if (cb_info == nullptr || rendering_info == nullptr || rendering_meta == nullptr)
    {
        return;
    }

    auto track_attachment = [this, cb_info](format::HandleId image_view_id, VkImageLayout layout) {
        if (layout != VK_IMAGE_LAYOUT_UNDEFINED && image_view_id != format::kNullHandleId)
        {
            auto image_view_info = GetObjectInfoTable().GetVkImageViewInfo(image_view_id);
            if (image_view_info != nullptr)
            {
                cb_info->image_layout_barriers[image_view_info->image_id] = layout;
            }
        }
    };

    if (rendering_info->pColorAttachments != nullptr && rendering_meta->pColorAttachments != nullptr)
    {
        const Decoded_VkRenderingAttachmentInfo* color_meta = rendering_meta->pColorAttachments->GetMetaStructPointer();
        if (color_meta != nullptr)
        {
            const uint32_t color_count = std::min(static_cast<uint32_t>(rendering_info->colorAttachmentCount),
                                                  static_cast<uint32_t>(rendering_meta->pColorAttachments->GetLength()));
            for (uint32_t i = 0; i < color_count; ++i)
            {
                track_attachment(color_meta[i].imageView, rendering_info->pColorAttachments[i].imageLayout);
            }
        }
    }

    if (rendering_info->pDepthAttachment != nullptr && rendering_meta->pDepthAttachment != nullptr &&
        rendering_meta->pDepthAttachment->GetMetaStructPointer() != nullptr)
    {
        track_attachment(rendering_meta->pDepthAttachment->GetMetaStructPointer()->imageView,
                         rendering_info->pDepthAttachment->imageLayout);
    }

    if (rendering_info->pStencilAttachment != nullptr && rendering_meta->pStencilAttachment != nullptr &&
        rendering_meta->pStencilAttachment->GetMetaStructPointer() != nullptr)
    {
        track_attachment(rendering_meta->pStencilAttachment->GetMetaStructPointer()->imageView,
                         rendering_info->pStencilAttachment->imageLayout);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginRendering(const ApiCallInfo&       call_info,
                                                                args::CmdBeginRendering& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginRendering(call_info, args);
    ApplyRenderingLayouts(args.commandBuffer, args.pRenderingInfo);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginRenderingKHR(const ApiCallInfo&          call_info,
                                                                   args::CmdBeginRenderingKHR& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(call_info, args);
    ApplyRenderingLayouts(args.commandBuffer, args.pRenderingInfo);
}

void VulkanReplayFrameLoopConsumer::TrackFenceStates()
{
    GetObjectInfoTable().VisitVkFenceInfo([this](const VulkanFenceInfo* fence_info) {
        GFXRECON_LOG_DEBUG("Tracking fence state for fence %" PRIu64, fence_info->capture_id);
        format::HandleId device_id = fence_info->parent_id;
        this->TrackFenceState(device_id, fence_info->capture_id);
    });
}

void VulkanReplayFrameLoopConsumer::TrackEventStates()
{
    GetObjectInfoTable().VisitVkEventInfo([this](const VulkanEventInfo* event_info) {
        GFXRECON_LOG_DEBUG("Tracking event state for event %" PRIu64, event_info->capture_id);
        format::HandleId device_id = event_info->parent_id;
        this->TrackEventState(device_id, event_info->capture_id);
    });
}

void VulkanReplayFrameLoopConsumer::TrackEventState(format::HandleId device, format::HandleId event)
{
    if (!host_visible_events_.contains(event))
    {
        // Ignore device only events.
        return;
    }

    // If event hasn't been seen yet, check and store the state it is in.
    EventTracking& t = per_device_event_tracking_[device];
    if (!t.initial_event_states_.contains(event))
    {
        VulkanDeviceInfo* device_info = GetObjectInfoTable().GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        VulkanEventInfo* event_info = GetObjectInfoTable().GetVkEventInfo(event);
        GFXRECON_ASSERT(event_info != nullptr);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
        GFXRECON_ASSERT(device_table != nullptr);
        VkResult res = device_table->GetEventStatus(device_info->handle, event_info->handle);
        GFXRECON_LOG_DEBUG("Event %" PRIu64 " set == %s", event, res == VK_EVENT_SET ? "true" : "false");
        t.initial_event_states_[event] = res == VK_EVENT_SET;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(const ApiCallInfo&       call_info,
                                                                args::CreateCommandPool& args)
{
    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    VkCommandPoolCreateInfo* create_info = args.pCreateInfo.GetPointer();
    create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateCommandPool(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyDescriptorPool(const ApiCallInfo&           call_info,
                                                                    args::DestroyDescriptorPool& args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.descriptorPool is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorPool if:
    //    We are not looping
    //    We are looping and args.descriptorPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.descriptorPool))
        VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.descriptorPool))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.

        // Check if this was the pool for any heretofore dangling descriptors
        RemovePoolDanglingCreateDescriptors(args.descriptorPool);
        VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, args);
        allocatedLoopResources.erase(args.descriptorPool);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.

        // Check if this was the pool for any heretofore dangling descriptors
        RemovePoolDanglingCreateDescriptors(args.descriptorPool);
        VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumer::RemovePoolDanglingCreateDescriptors(format::HandleId descriptorPool)
{
    std::vector<format::HandleId> handles_to_delete;
    handles_to_delete.reserve(dangling_create_descriptor_sets_.size());
    for (format::HandleId handle : dangling_create_descriptor_sets_)
    {
        VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(handle);
        if (info != nullptr && info->pool_id == descriptorPool)
        {
            handles_to_delete.push_back(handle);
        }
    }
    for (format::HandleId handle : handles_to_delete)
    {
        dangling_create_descriptor_sets_.erase(handle);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkResetDescriptorPool(const ApiCallInfo&         call_info,
                                                                  args::ResetDescriptorPool& args)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsFinalIteration())
    {
        // If any of the sets in this pool are dangling, skip pool reset
        for (format::HandleId set_id : dangling_create_descriptor_sets_)
        {
            VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(set_id);
            if (info != nullptr && info->pool_id == args.descriptorPool)
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkResetDescriptorPool(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateDescriptorSets(const ApiCallInfo&            call_info,
                                                                     args::AllocateDescriptorSets& args)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Skip allocation of dangling descriptor sets
        for (format::HandleId set_handle : args.pDescriptorSets.GetSpan())
        {
            if (dangling_create_descriptor_sets_.contains(set_handle))
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkAllocateDescriptorSets(call_info, args);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // During first iteration of looping range, record which descriptor sets are allocated
        // They will be removed from the set if they are freed during the loop range
        for (format::HandleId set_handle : args.pDescriptorSets.GetSpan())
        {
            dangling_create_descriptor_sets_.insert(set_handle);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeDescriptorSets(const ApiCallInfo&        call_info,
                                                                 args::FreeDescriptorSets& args)
{
    if (frame_loop_info_.IsRepetition() && !frame_loop_info_.IsFinalIteration())
    {
        // If any of the descriptor sets are in the dangling list,
        // then we want to omit their destruction
        for (format::HandleId set_handle : args.pDescriptorSets.GetSpan())
        {
            if (dangling_destroy_descriptor_sets_.contains(set_handle))
            {
                return;
            }
        }
    }

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        bool skip_call = false;
        for (format::HandleId set_handle : args.pDescriptorSets.GetSpan())
        {
            if (dangling_create_descriptor_sets_.contains(set_handle))
            {
                // Any descriptor set that was freed during the loop range is not dangling
                dangling_create_descriptor_sets_.erase(set_handle);
            }
            else
            {
                // Descriptor set freed during loop range but created before
                dangling_destroy_descriptor_sets_.insert(set_handle);
                skip_call = true;
            }
        }
        if (skip_call)
        {
            return;
        }
    }

    // For pools that contain dangling descriptor sets, this code will only be reached once,
    // during the final iteration of the loop range.
    RemovePoolDanglingCreateDescriptors(args.descriptorPool);

    VulkanReplayConsumer::Process_vkFreeDescriptorSets(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateFence(const ApiCallInfo& call_info, args::CreateFence& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateFence(call_info, args);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Record the initial state of the new fence
        FenceTracking& t = per_device_fence_tracking_[args.device];
        bool           signaled =
            (args.pCreateInfo.GetPointer()->flags & VK_FENCE_CREATE_SIGNALED_BIT) == VK_FENCE_CREATE_SIGNALED_BIT;
        t.initial_fence_states_[*args.pFence.GetPointer()] = signaled;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyFence(const ApiCallInfo& call_info, args::DestroyFence& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyFence(call_info, args);
    bool destroyed = (GetObjectInfoTable().GetVkFenceInfo(args.fence) == nullptr);
    if (destroyed)
    {
        if (per_device_fence_tracking_.contains(args.device))
        {
            FenceTracking& t = per_device_fence_tracking_[args.device];

            // Remove fence tracking struct from map if
            // fence was created and destroyed during the loop range.
            t.initial_fence_states_.erase(args.fence);
        }
    }
}

void VulkanReplayFrameLoopConsumer::TrackFenceState(format::HandleId device, format::HandleId fence)
{
    // If fence hasn't been seen yet, check and store the state it is in.
    FenceTracking& t = per_device_fence_tracking_[device];
    if (!t.initial_fence_states_.contains(fence))
    {
        VulkanDeviceInfo* device_info = GetObjectInfoTable().GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        VulkanFenceInfo* fence_info = GetObjectInfoTable().GetVkFenceInfo(fence);
        GFXRECON_ASSERT(fence_info != nullptr);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
        GFXRECON_ASSERT(device_table != nullptr);
        VkResult res = device_table->GetFenceStatus(device_info->handle, fence_info->handle);
        GFXRECON_LOG_DEBUG("Fence %" PRIu64 " signaled == %s", fence, res == VK_SUCCESS ? "true" : "false");
        t.initial_fence_states_[fence] = res == VK_SUCCESS;
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceFences(format::HandleId device, format::HandleId queue)
{
    // Get fence tracking info associated with this VkDevice
    if (!per_device_fence_tracking_.contains(device))
    {
        // No need to fixup fences if there weren't any
        return;
    }
    FenceTracking& t = per_device_fence_tracking_[device];

    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    VkDevice                           vk_device    = table.GetVkDeviceInfo(device)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(vk_device);

    // Reset all fences, then synthetically signal the fences that were signaled
    // at the start of the loop range
    std::vector<VkFence> all_fences;
    std::vector<VkFence> fences_to_signal;
    all_fences.reserve(t.initial_fence_states_.size());
    fences_to_signal.reserve(t.initial_fence_states_.size());
    for (auto [fence_id, was_initially_signaled] : t.initial_fence_states_)
    {
        VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
        all_fences.push_back(fence_info->handle);
        if (was_initially_signaled)
        {
            fences_to_signal.push_back(fence_info->handle);
        }
    }

    VkResult result;

    // Reset all fences
    if (all_fences.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically resetting all %" PRIu64 " observed fences...", all_fences.size());
        result = device_table->ResetFences(vk_device, all_fences.size(), all_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    // Synthetically signal the ones that were originally signaled
    GFXRECON_LOG_DEBUG("Synthetically signaling %" PRIu64 " fences...", fences_to_signal.size());
    VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
    for (VkFence fence : fences_to_signal)
    {
        result = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
        CHECK_VK_RESULT(result, "vkQueueSubmit");
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceEvents(format::HandleId device)
{
    // Get event tracking info associated with this VkDevice
    if (!per_device_event_tracking_.contains(device))
    {
        // No need to fixup event if there weren't any.
        return;
    }

    EventTracking& t = per_device_event_tracking_[device];

    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    VkDevice                           vk_device    = table.GetVkDeviceInfo(device)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(vk_device);

    // Set all events to their initial state.
    for (auto [event_id, was_initially_set] : t.initial_event_states_)
    {
        VulkanEventInfo* event_info = table.GetVkEventInfo(event_id);
        VkEvent          vk_event   = event_info->handle;
        VkResult         result     = VK_ERROR_UNKNOWN;
        if (was_initially_set)
        {
            CHECK_VK_RESULT(device_table->SetEvent(vk_device, vk_event), "vkSetEvent");
        }
        else
        {
            CHECK_VK_RESULT(device_table->ResetEvent(vk_device, vk_event), "vkResetEvent");
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateEvent(const ApiCallInfo& call_info, args::CreateEvent& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateEvent(call_info, args);

    const VkEventCreateInfo* create_info = args.pCreateInfo.GetPointer();
    if (create_info == nullptr)
    {
        return;
    }

    // Track host visible events.
    bool host_visible = (create_info->flags & VK_EVENT_CREATE_DEVICE_ONLY_BIT) != VK_EVENT_CREATE_DEVICE_ONLY_BIT;
    if (host_visible)
    {
        format::HandleId event_id = *args.pEvent.GetPointer();
        host_visible_events_.insert(event_id);
    }

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        bool device_only = (create_info->flags & VK_EVENT_CREATE_DEVICE_ONLY_BIT) == VK_EVENT_CREATE_DEVICE_ONLY_BIT;
        // Ignore device only events.
        if (!device_only)
        {
            // Record the initial state of the new event
            EventTracking&                     t               = per_device_event_tracking_[args.device];
            VulkanObjectInfoTable&             table           = GetObjectInfoTable();
            VkDevice                           vk_device       = table.GetVkDeviceInfo(args.device)->handle;
            const graphics::VulkanDeviceTable* device_table    = GetDeviceTable(vk_device);
            VkEvent                            vk_event        = *args.pEvent.GetHandlePointer();
            VkResult                           status          = device_table->GetEventStatus(vk_device, vk_event);
            bool                               is_set          = (status == VK_EVENT_SET);
            t.initial_event_states_[*args.pEvent.GetPointer()] = is_set;
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyEvent(const ApiCallInfo& call_info, args::DestroyEvent& args)
{
    if (allocatedLoopResources.contains(args.event))
    {
        if (per_device_event_tracking_.contains(args.device))
        {
            EventTracking& t = per_device_event_tracking_[args.device];

            // Remove event tracking struct from map if
            // event was created and destroyed during the loop range.
            t.initial_event_states_.erase(args.event);
            host_visible_events_.erase(args.event);
        }
    }
    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyEvent(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkMapMemory(const ApiCallInfo& call_info, args::MapMemory& args)
{
    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in mapped_loop_memory
    if (frame_loop_info_.IsLooping())
    {
        if (mapped_loop_memory.contains(args.memory))
        {
            return; // Already mapped in loop range, skip re-mapping
        }

        // First time mapping in the loop
        mapped_loop_memory.insert(args.memory);
    }
    VulkanReplayConsumer::Process_vkMapMemory(call_info, args);
}

void VulkanReplayFrameLoopConsumer::FrameBoundaryEndOfFrame(format::HandleId queue, PNextNode* pNext)
{
    const Decoded_VkFrameBoundaryEXT* frame_boundary = GetPNextMetaStruct<Decoded_VkFrameBoundaryEXT>(pNext);
    if (frame_boundary != nullptr)
    {
        if ((frame_boundary->decoded_value->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT) ==
            VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT)
        {
            // This submit is being used as a frame boundary
            CommonObjectInfoTable& table      = GetObjectInfoTable();
            VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(queue);
            VkDevice               device     = queue_info->parent;
            GFXRECON_ASSERT(device != 0);
            const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
            GFXRECON_ASSERT(device_table != nullptr);

            GFXRECON_LOG_DEBUG("Waiting for device to idle...");
            VkResult result = device_table->DeviceWaitIdle(device);
            CHECK_VK_RESULT(result, "vkDeviceWaitIdle");

            FixupDeviceObjects(queue_info->parent_id, queue);
        }
    }
}

void VulkanReplayFrameLoopConsumer::TrackImageLayouts()
{
    initial_image_layouts_.clear();
    GetObjectInfoTable().VisitVkImageInfo([this](const VulkanImageInfo* image_info) {
        if (image_info->handle != VK_NULL_HANDLE)
        {
            initial_image_layouts_[image_info->capture_id] = image_info->current_layout;
        }
    });
}

void VulkanReplayFrameLoopConsumer::PropagateImageLayouts(format::HandleId command_buffer)
{
    VulkanCommandBufferInfo* cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(command_buffer);
    if (cb_info == nullptr)
    {
        return;
    }

    for (const auto& [image_id, layout] : cb_info->image_layout_barriers)
    {
        VulkanImageInfo* image_info = GetObjectInfoTable().GetVkImageInfo(image_id);
        if (image_info != nullptr)
        {
            image_info->current_layout = layout;
        }
    }
}

void VulkanReplayFrameLoopConsumer::SubmitImageLayoutBarriers(const VulkanDeviceInfo*                  device_info,
                                                              const VulkanQueueInfo*                   queue_info,
                                                              const std::vector<VkImageMemoryBarrier>& barriers)
{
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
    GFXRECON_ASSERT(device_table != nullptr);

    VkCommandPoolCreateInfo pool_create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    pool_create_info.flags                   = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
    pool_create_info.queueFamilyIndex        = queue_info->family_index;

    VkCommandPool command_pool = VK_NULL_HANDLE;
    VkResult result = device_table->CreateCommandPool(device_info->handle, &pool_create_info, nullptr, &command_pool);
    CHECK_VK_RESULT(result, "vkCreateCommandPool");

    VkCommandBufferAllocateInfo allocate_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    allocate_info.commandPool                 = command_pool;
    allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocate_info.commandBufferCount          = 1;

    VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    result = device_table->AllocateCommandBuffers(device_info->handle, &allocate_info, &command_buffer);
    CHECK_VK_RESULT(result, "vkAllocateCommandBuffers");

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    result = device_table->BeginCommandBuffer(command_buffer, &begin_info);
    CHECK_VK_RESULT(result, "vkBeginCommandBuffer");

    device_table->CmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     static_cast<uint32_t>(barriers.size()),
                                     barriers.data());

    result = device_table->EndCommandBuffer(command_buffer);
    CHECK_VK_RESULT(result, "vkEndCommandBuffer");

    VkSubmitInfo submit_info       = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;

    result = device_table->QueueSubmit(queue_info->handle, 1, &submit_info, VK_NULL_HANDLE);
    CHECK_VK_RESULT(result, "vkQueueSubmit");

    // The pool is destroyed after, so the command buffer cannot be left in flight.
    result = device_table->QueueWaitIdle(queue_info->handle);
    CHECK_VK_RESULT(result, "vkQueueWaitIdle");

    device_table->DestroyCommandPool(device_info->handle, command_pool, nullptr);
}

void VulkanReplayFrameLoopConsumer::FixupImageLayouts(format::HandleId device, format::HandleId queue)
{
    if (initial_image_layouts_.empty())
    {
        return;
    }

    VulkanObjectInfoTable& table      = GetObjectInfoTable();
    VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(queue);
    VulkanDeviceInfo*      device_info = table.GetVkDeviceInfo(device);
    GFXRECON_ASSERT(queue_info != nullptr && device_info != nullptr);

    // Transition every image that has changed from it's original layout.
    std::vector<VkImageMemoryBarrier> barriers;
    table.VisitVkImageInfo([this, device, &table, &barriers](const VulkanImageInfo* image_info) {
        if (image_info->handle == VK_NULL_HANDLE || image_info->parent_id != device)
        {
            return;
        }

        // Images created inside the loop range have no starting layout to return to.
        auto initial_layout = initial_image_layouts_.find(image_info->capture_id);
        if (initial_layout == initial_image_layouts_.end() || initial_layout->second == image_info->current_layout ||
            initial_layout->second == VK_IMAGE_LAYOUT_UNDEFINED ||
            initial_layout->second == VK_IMAGE_LAYOUT_PREINITIALIZED)
        {
            return;
        }

        VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
        barrier.srcAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        barrier.dstAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
        barrier.oldLayout            = image_info->current_layout;
        barrier.newLayout            = initial_layout->second;
        barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
        barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
        barrier.image                = image_info->handle;
        barrier.subresourceRange     = { graphics::GetFormatAspects(image_info->format),
                                         0,
                                         image_info->level_count,
                                         0,
                                         image_info->layer_count };

        barriers.push_back(barrier);

        VulkanImageInfo* mutable_image_info = table.GetVkImageInfo(image_info->capture_id);
        GFXRECON_ASSERT(mutable_image_info != nullptr);
        mutable_image_info->current_layout      = initial_layout->second;
        mutable_image_info->intermediate_layout = mutable_image_info->current_layout;
    });

    if (barriers.empty())
    {
        return;
    }

    SubmitImageLayoutBarriers(device_info, queue_info, barriers);
}

void VulkanReplayFrameLoopConsumer::FixupDeviceObjects(format::HandleId device, format::HandleId queue)
{
    if (!frame_loop_info_.IsLooping() || frame_loop_info_.IsFinalIteration())
    {
        return;
    }
    FixupDeviceEvents(device);
    FixupImageLayouts(device, queue);
    FixupDeviceFences(device, queue);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueBindSparse(const ApiCallInfo& call_info, args::QueueBindSparse& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkQueueBindSparse(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        for (Decoded_VkBindSparseInfo submit : args.pBindInfo.GetMetaStructSpan())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, args);

    for (const Decoded_VkSubmitInfo& submit : args.pSubmits.GetMetaStructSpan())
    {
        for (format::HandleId command_buffer : submit.pCommandBuffers.GetSpan())
        {
            PropagateImageLayouts(command_buffer);
        }

        if (frame_loop_info_.IsLooping())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit2(call_info, args);

    for (const Decoded_VkSubmitInfo2& submit : args.pSubmits.GetMetaStructSpan())
    {
        if (submit.pCommandBufferInfos != nullptr)
        {
            for (const Decoded_VkCommandBufferSubmitInfo& cb_submit : submit.pCommandBufferInfos->GetMetaStructSpan())
            {
                PropagateImageLayouts(cb_submit.commandBuffer);
            }
        }

        if (frame_loop_info_.IsLooping())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, args);

    CommonObjectInfoTable& table      = GetObjectInfoTable();
    VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(args.queue);
    VkDevice               device     = queue_info->parent;
    GFXRECON_ASSERT(device != 0);
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);

    if (frame_loop_info_.IsLooping())
    {
        GFXRECON_LOG_DEBUG("Waiting for device to idle...");
        VkResult result = device_table->DeviceWaitIdle(device);
        CHECK_VK_RESULT(result, "vkDeviceWaitIdle");

        FixupDeviceObjects(queue_info->parent_id, args.queue);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkUnmapMemory(const ApiCallInfo& call_info, args::UnmapMemory& args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if memory is in mapped_loop_memory

    // Call Process_vkUnmapMemory if:
    //    We are not looping
    //    We are looping and memory is in mapped_loop_memory, i.e. it is mapped/unmapped inside loop
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.memory));
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
    }
    else if (mapped_loop_memory.contains(args.memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
        mapped_loop_memory.erase(args.memory);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireProfilingLockKHR(const ApiCallInfo&             call_info,
                                                                      args::AcquireProfilingLockKHR& args)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is false (not acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(args.device) || !profilingLockState[args.device])
    {
        VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(call_info, args);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[args.device] = true;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkReleaseProfilingLockKHR(const ApiCallInfo&             call_info,
                                                                      args::ReleaseProfilingLockKHR& args)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is true (acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(args.device) || profilingLockState[args.device])
    {
        VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(call_info, args);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[args.device] = false;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
