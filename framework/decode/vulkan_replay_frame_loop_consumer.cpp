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
#include "decode/vulkan_temporary_objects.h"

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

bool VulkanReplayFrameLoopConsumer::SemaphoreTracking::IsBinary(format::HandleId semaphore) const
{
    const VulkanSemaphoreInfo* info = object_table_.GetVkSemaphoreInfo(semaphore);
    return info != nullptr && !info->is_timeline;
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::ClassifySignal(format::HandleId semaphore)
{
    if (!IsBinary(semaphore))
    {
        return;
    }
    // At this point, this semaphore is considered an unconsumed in-loop-signal.
    // If still present at the loop boundary, it gets drained.
    in_loop_signaled_semaphores_.insert(semaphore);
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::ClassifyWait(format::HandleId semaphore)
{
    if (!IsBinary(semaphore))
    {
        return;
    }

    // Attempt to consume a pending in-loop signal.
    bool consumed = in_loop_signaled_semaphores_.erase(semaphore) > 0;

    if (!consumed)
    {
        // This semaphores is expected to be signaled before the loop range.
        // This means that every repetition needs to signal this semaphore synthetically.
        before_loop_signaled_semaphores_.insert(semaphore);
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::QueuePresentKHR& args)
{
    const auto* present_info = args.pPresentInfo.GetMetaStructPointer();
    for (format::HandleId semaphore : present_info->pWaitSemaphores.GetSpan())
    {
        ClassifyWait(semaphore);
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit& args)
{
    for (const auto& submit_info : args.pSubmits.GetMetaStructSpan())
    {
        for (format::HandleId semaphore : submit_info.pWaitSemaphores.GetSpan())
        {
            ClassifyWait(semaphore);
        }

        for (format::HandleId semaphore : submit_info.pSignalSemaphores.GetSpan())
        {
            ClassifySignal(semaphore);
        }
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit2KHR& args)
{
    for (const auto& submit_info : args.pSubmits.GetMetaStructSpan())
    {
        if (submit_info.pWaitSemaphoreInfos != nullptr)
        {
            const auto wait_semaphore_infos = submit_info.pWaitSemaphoreInfos->GetMetaStructSpan();
            for (const auto& wait_info : wait_semaphore_infos)
            {
                ClassifyWait(wait_info.semaphore);
            }
        }

        if (submit_info.pSignalSemaphoreInfos != nullptr)
        {
            const auto signal_semaphore_infos = submit_info.pSignalSemaphoreInfos->GetMetaStructSpan();
            for (const auto& signal_info : signal_semaphore_infos)
            {
                ClassifySignal(signal_info.semaphore);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit2& args)
{
    for (const auto& submit_info : args.pSubmits.GetMetaStructSpan())
    {
        if (submit_info.pWaitSemaphoreInfos != nullptr)
        {
            const auto wait_semaphore_infos = submit_info.pWaitSemaphoreInfos->GetMetaStructSpan();
            for (const auto& wait_info : wait_semaphore_infos)
            {
                ClassifyWait(wait_info.semaphore);
            }
        }

        if (submit_info.pSignalSemaphoreInfos != nullptr)
        {
            const auto signal_semaphore_infos = submit_info.pSignalSemaphoreInfos->GetMetaStructSpan();
            for (const auto& signal_info : signal_semaphore_infos)
            {
                ClassifySignal(signal_info.semaphore);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::AcquireNextImageKHR& args)
{
    ClassifySignal(args.semaphore);
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackSemaphores(const args::AcquireNextImage2KHR& args)
{
    // This semaphore is going to be signaled by the loop range.
    const auto* acquire_info = args.pAcquireInfo.GetMetaStructPointer();
    ClassifySignal(acquire_info->semaphore);
}

static PFN_vkGetSemaphoreCounterValue GetSemaphoreCounterValueProc(const graphics::VulkanDeviceTable& device_table)
{
    if (device_table.GetSemaphoreCounterValue != graphics::noop::vkGetSemaphoreCounterValue)
    {
        return device_table.GetSemaphoreCounterValue;
    }
    return device_table.GetSemaphoreCounterValueKHR;
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::TrackTimelineValue(format::HandleId semaphore)
{
    if (initial_timeline_values_.contains(semaphore))
    {
        // Already snapshotted.
        return;
    }

    const VulkanSemaphoreInfo* semaphore_info = object_table_.GetVkSemaphoreInfo(semaphore);
    uint64_t                   initial_value  = 0;
    CHECK_VK_RESULT(GetSemaphoreCounterValueProc(device_table_)(device_, semaphore_info->handle, &initial_value),
                    "vkGetSemaphoreCounterValue");
    GFXRECON_LOG_DEBUG("Tracking timeline semaphore %" PRIu64 " with initial value %" PRIu64, semaphore, initial_value);
    initial_timeline_values_.emplace(semaphore, initial_value);
}

bool VulkanReplayFrameLoopConsumer::SemaphoreTracking::IsFixable(const VulkanSemaphoreInfo* semaphore_info) const
{
    return (semaphore_info != nullptr && semaphore_info->handle != VK_NULL_HANDLE && !semaphore_info->is_external &&
            !semaphore_info->shadow_signaled && semaphore_info->forward_progress);
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::FixupSemaphores(format::HandleId queue)
{
    // Device is expected to be idle at this point.
    FixupBinarySemaphores(queue);
    FixupTimelineSemaphores(queue);
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::FixupBinarySemaphores(format::HandleId queue)
{
    // The semaphores collected in this vector are semaphores that end up signaled within the loop range.
    // This means that, on repetition, they are going to be signaled again.
    // So, before repeating the loop range, these semaphores are drained (waited on)
    // to ensure that the next loop iteration starts with them in an unsignaled state.
    std::vector<VkSemaphore>          drain;
    std::vector<VkPipelineStageFlags> drain_stages;

    // The semaphores collected in this vector are semaphores that have been waited on within the loop range,
    // but are not signaled within the loop range.
    // This means that, on repetition, they are going to be waited on again.
    // So, before repeating the loop range, these semaphores are replenished (signaled)
    // to ensure that the next loop iteration starts with them in a signaled state.
    std::vector<VkSemaphore> replenish;

    for (auto& semaphore : in_loop_signaled_semaphores_)
    {
        if (before_loop_signaled_semaphores_.contains(semaphore))
        {
            // This semaphore ends up signaled within the loop range,
            // but is also expected to be signaled before the loop range.
            // Net result: nothing to do.
            continue;
        }

        const VulkanSemaphoreInfo* semaphore_info = object_table_.GetVkSemaphoreInfo(semaphore);
        if (IsFixable(semaphore_info))
        {
            GFXRECON_LOG_DEBUG("Fixing up semaphore %" PRIu64 " for queue %" PRIu64, semaphore, queue);
            drain.push_back(semaphore_info->handle);
            drain_stages.push_back(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
        }
    }

    for (auto& semaphore : before_loop_signaled_semaphores_)
    {
        if (in_loop_signaled_semaphores_.contains(semaphore))
        {
            // Same as above: this semaphore ends up signaled within the loop range..
            continue;
        }

        const VulkanSemaphoreInfo* semaphore_info = object_table_.GetVkSemaphoreInfo(semaphore);
        if (IsFixable(semaphore_info))
        {
            GFXRECON_LOG_DEBUG("Fixing up semaphore %" PRIu64 " for queue %" PRIu64, semaphore, queue);
            replenish.push_back(semaphore_info->handle);
        }
    }

    if (!drain.empty() || !replenish.empty())
    {
        VkSubmitInfo submit_info{ VK_STRUCTURE_TYPE_SUBMIT_INFO };
        submit_info.waitSemaphoreCount   = static_cast<uint32_t>(drain.size());
        submit_info.pWaitSemaphores      = drain.data();
        submit_info.pWaitDstStageMask    = drain_stages.data();
        submit_info.signalSemaphoreCount = static_cast<uint32_t>(replenish.size());
        submit_info.pSignalSemaphores    = replenish.data();

        VkQueue queue_handle = object_table_.GetVkQueueInfo(queue)->handle;
        CHECK_VK_RESULT(device_table_.QueueSubmit(queue_handle, 1, &submit_info, VK_NULL_HANDLE), "vkQueueSubmit");
        CHECK_VK_RESULT(device_table_.QueueWaitIdle(queue_handle), "vkQueueWaitIdle");
    }
}

void VulkanReplayFrameLoopConsumer::SemaphoreTracking::FixupTimelineSemaphores(format::HandleId queue)
{
    // Timeline semaphores cannot be rewound, so we need to replace each drifted semaphore with a fresh one.
    for (const auto& [semaphore, initial_value] : initial_timeline_values_)
    {
        VulkanSemaphoreInfo* semaphore_info = object_table_.GetVkSemaphoreInfo(semaphore);
        if (!IsFixable(semaphore_info))
        {
            continue;
        }

        uint64_t current_value = 0;
        CHECK_VK_RESULT(GetSemaphoreCounterValueProc(device_table_)(device_, semaphore_info->handle, &current_value),
                        "vkGetSemaphoreCounterValue");
        GFXRECON_ASSERT(current_value >= initial_value);
        if (current_value == initial_value)
        {
            // Semaphore is already at the expected value, no need to fix it.
            continue;
        }

        GFXRECON_LOG_DEBUG("Timeline semaphore %" PRIu64 ": %" PRIu64 " -> recreate at %" PRIu64,
                           semaphore,
                           current_value,
                           initial_value);

        VkSemaphoreTypeCreateInfo type_info{ VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO };
        type_info.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
        type_info.initialValue  = initial_value;
        VkSemaphoreCreateInfo create_info{ VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
        create_info.pNext = &type_info;

        VkSemaphore replacement = VK_NULL_HANDLE;
        CHECK_VK_RESULT(device_table_.CreateSemaphore(device_, &create_info, nullptr, &replacement),
                        "vkCreateSemaphore");
        device_table_.DestroySemaphore(device_, semaphore_info->handle, nullptr);
        // Handle replacement.
        semaphore_info->handle = replacement;
    }
}

void VulkanReplayFrameLoopConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessStateEndMarker(frame_number);

    // If trim state had to be loaded, call StartLooping() again
    if (frame_loop_info_.IsLooping())
    {
        per_device_fence_tracking_.clear();
        per_device_event_tracking_.clear();
        per_device_semaphore_tracking_.clear();
        StartLooping();
    }
}

VulkanReplayFrameLoopConsumer::SemaphoreTracking&
VulkanReplayFrameLoopConsumer::GetSemaphoreTracking(format::HandleId device)
{
    auto it = per_device_semaphore_tracking_.find(device);
    if (it == per_device_semaphore_tracking_.end())
    {
        auto&             object_table  = GetObjectInfoTable();
        VulkanDeviceInfo* device_info   = object_table.GetVkDeviceInfo(device);
        VkDevice          device_handle = device_info->handle;
        const auto&       device_table  = *GetDeviceTable(device_handle);
        auto              result        = per_device_semaphore_tracking_.emplace(
            device, SemaphoreTracking(device_handle, device_table, object_table));
        it = result.first;
        GFXRECON_ASSERT(result.second);
    }
    return it->second;
}

void VulkanReplayFrameLoopConsumer::StartLooping()
{
    WaitDevicesIdle();
    GFXRECON_LOG_DEBUG("VulkanReplayFrameLoopConsumer::StartLooping()");
    TrackFenceStates();
    TrackEventStates();
    TrackImageLayouts();
    TrackSemaphoreStates();
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

void VulkanReplayFrameLoopConsumer::TrackSemaphoreStates()
{
    GetObjectInfoTable().VisitVkSemaphoreInfo([this](const VulkanSemaphoreInfo* semaphore_info) {
        if (semaphore_info->is_timeline && !semaphore_info->is_external)
        {
            GFXRECON_LOG_DEBUG("Tracking semaphore state for semaphore %" PRIu64, semaphore_info->capture_id);
            format::HandleId device_id = semaphore_info->parent_id;
            this->GetSemaphoreTracking(device_id).TrackTimelineValue(semaphore_info->capture_id);
        }
    });
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

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(const ApiCallInfo&        call_info,
                                                                 args::BeginCommandBuffer& args)
{
    VulkanReplayConsumer::Process_vkBeginCommandBuffer(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        // Record query pool reset commands
        VulkanCommandBufferInfo* cb_info       = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer);
        format::HandleId         device        = cb_info->parent_id;
        VkDevice                 replay_device = GetObjectInfoTable().GetVkDeviceInfo(device)->handle;
        GFXRECON_ASSERT(replay_device != 0);
        GetObjectInfoTable().VisitVkQueryPoolInfo([this, replay_device, cb_info](const VulkanQueryPoolInfo* info) {
            GFXRECON_ASSERT(query_pool_sizes_.contains(info->capture_id));
            const graphics::VulkanDeviceTable* device_table = GetDeviceTable(replay_device);
            GFXRECON_ASSERT(device_table != nullptr);
            VkQueryPool pool_handle = info->handle;
            uint32_t    pool_size   = query_pool_sizes_[info->capture_id];
            GFXRECON_LOG_DEBUG(
                "Resetting pool 0x%" PRIx64 " (replay time handle == 0x%" PRIx64 ")", info->handle, info->capture_id);
            device_table->CmdResetQueryPool(cb_info->handle, pool_handle, 0, pool_size);

            // keep tracked query availability in sync with the injected reset
            cb_info->recorded_query_ops.push_back({ info->capture_id, 0, pool_size, false });
        });
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

        // keep tracked event terminal-state in sync with the fixup
        event_info->latched_set = was_initially_set;
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

void VulkanReplayFrameLoopConsumer::Process_vkCreateSemaphore(const ApiCallInfo& call_info, args::CreateSemaphore& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateSemaphore(call_info, args);

    if (args.pSemaphore.IsNull())
    {
        return;
    }

    format::HandleId     semaphore_id   = *args.pSemaphore.GetPointer();
    VulkanSemaphoreInfo* semaphore_info = GetObjectInfoTable().GetVkSemaphoreInfo(semaphore_id);

    // A semaphore created inside the loop range persists across iterations.
    if (frame_loop_info_.IsFirstIteration() && semaphore_info->is_timeline)
    {
        auto& semaphore_tracking                                  = GetSemaphoreTracking(args.device);
        semaphore_tracking.initial_timeline_values_[semaphore_id] = semaphore_info->initial_value;
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroySemaphore(const ApiCallInfo&      call_info,
                                                               args::DestroySemaphore& args)
{
    if (allocatedLoopResources.contains(args.semaphore))
    {
        // This semaphore was created and destroyed during the loop range.
        // That means there is no cross-iteration state to reconcile.
        auto semaphore_tracking_it = per_device_semaphore_tracking_.find(args.device);
        if (semaphore_tracking_it != per_device_semaphore_tracking_.end())
        {
            auto& semaphore_tracking = semaphore_tracking_it->second;
            semaphore_tracking.in_loop_signaled_semaphores_.erase(args.semaphore);
            semaphore_tracking.before_loop_signaled_semaphores_.erase(args.semaphore);
            semaphore_tracking.initial_timeline_values_.erase(args.semaphore);
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkDestroySemaphore(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateQueryPool(const ApiCallInfo& call_info, args::CreateQueryPool& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkCreateQueryPool(call_info, args);

    if (!frame_loop_info_.IsLooping() || (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition()))
    {
        // If this query pool was created outside the loop range or if it's the first iteration
        // of the loop range, save query pool creation sizes
        uint32_t               count  = args.pCreateInfo.GetPointer()->queryCount;
        const format::HandleId handle = *args.pQueryPool.GetPointer();
        query_pool_sizes_[handle]     = count;
    }
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

// The aspect bits ImageLayoutMap tracks, in the order it slots them.
static constexpr VkImageAspectFlagBits kTrackedAspects[] = { VK_IMAGE_ASPECT_COLOR_BIT,   VK_IMAGE_ASPECT_DEPTH_BIT,
                                                             VK_IMAGE_ASPECT_STENCIL_BIT, VK_IMAGE_ASPECT_PLANE_0_BIT,
                                                             VK_IMAGE_ASPECT_PLANE_1_BIT, VK_IMAGE_ASPECT_PLANE_2_BIT };

static bool IsRestorableLayout(VkImageLayout layout)
{
    return (layout != VK_IMAGE_LAYOUT_UNDEFINED) && (layout != VK_IMAGE_LAYOUT_PREINITIALIZED);
}

static VkImageMemoryBarrier MakeLayoutRestoreBarrier(VkImage                        image,
                                                     VkImageLayout                  old_layout,
                                                     VkImageLayout                  new_layout,
                                                     const VkImageSubresourceRange& subresource_range)
{
    VkImageMemoryBarrier barrier = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
    barrier.srcAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    barrier.dstAccessMask        = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    barrier.oldLayout            = old_layout;
    barrier.newLayout            = new_layout;
    barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.image                = image;
    barrier.subresourceRange     = subresource_range;
    return barrier;
}

static void AppendImageLayoutRestoreBarriers(const VulkanImageInfo*             image_info,
                                             const graphics::ImageLayoutMap&    initial_layouts,
                                             std::vector<VkImageMemoryBarrier>& barriers)
{
    const graphics::ImageLayoutMap& current_layouts = image_info->subresource_layouts;

    if (!initial_layouts.IsInitialized() || !current_layouts.IsInitialized())
    {
        return;
    }

    const VkImageAspectFlags aspects      = initial_layouts.GetAspects();
    const uint32_t           mip_levels   = initial_layouts.GetMipLevels();
    const uint32_t           array_layers = initial_layouts.GetArrayLayers();

    // Uniform fast path.
    if (initial_layouts.IsUniform() && current_layouts.IsUniform())
    {
        const VkImageAspectFlagBits first_aspect = static_cast<VkImageAspectFlagBits>(aspects & ~(aspects - 1));
        const VkImageLayout         initial      = initial_layouts.GetSubresourceLayout(first_aspect, 0, 0);
        const VkImageLayout         current      = current_layouts.GetSubresourceLayout(first_aspect, 0, 0);

        if ((initial != current) && IsRestorableLayout(initial))
        {
            barriers.push_back(MakeLayoutRestoreBarrier(
                image_info->handle, current, initial, { aspects, 0, mip_levels, 0, array_layers }));
        }
        return;
    }

    // Otherwise restore each subresource individually.
    for (VkImageAspectFlagBits aspect : kTrackedAspects)
    {
        if ((aspects & aspect) == 0)
        {
            continue;
        }

        for (uint32_t mip_level = 0; mip_level < mip_levels; ++mip_level)
        {
            for (uint32_t array_layer = 0; array_layer < array_layers; ++array_layer)
            {
                const VkImageLayout initial = initial_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);
                const VkImageLayout current = current_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);

                if ((initial == current) || !IsRestorableLayout(initial))
                {
                    continue;
                }

                barriers.push_back(MakeLayoutRestoreBarrier(
                    image_info->handle,
                    current,
                    initial,
                    { static_cast<VkImageAspectFlags>(aspect), mip_level, 1, array_layer, 1 }));
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::TrackImageLayouts()
{
    initial_image_layouts_.clear();
    GetObjectInfoTable().VisitVkImageInfo([this](const VulkanImageInfo* image_info) {
        if (image_info->handle != VK_NULL_HANDLE)
        {
            initial_image_layouts_[image_info->capture_id] = image_info->subresource_layouts;
        }
    });
}

void VulkanReplayFrameLoopConsumer::SubmitImageLayoutBarriers(const VulkanDeviceInfo*                  device_info,
                                                              const VulkanQueueInfo*                   queue_info,
                                                              const std::vector<VkImageMemoryBarrier>& barriers)
{
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
    GFXRECON_ASSERT(device_table != nullptr);

    TemporaryCommandBuffer temp_command_buffer(*device_info, *device_table);

    VkResult result = temp_command_buffer.CreateAndBegin(queue_info->family_index, queue_info->queue_index);
    CHECK_VK_RESULT(result, "TemporaryCommandBuffer::CreateAndBegin");

    device_table->CmdPipelineBarrier(temp_command_buffer.command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     static_cast<uint32_t>(barriers.size()),
                                     barriers.data());

    result = temp_command_buffer.SubmitAndDestroy();
    CHECK_VK_RESULT(result, "TemporaryCommandBuffer::SubmitAndDestroy");
}

void VulkanReplayFrameLoopConsumer::FixupImageLayouts(format::HandleId device, format::HandleId queue)
{
    if (initial_image_layouts_.empty())
    {
        return;
    }

    VulkanObjectInfoTable& table       = GetObjectInfoTable();
    VulkanQueueInfo*       queue_info  = table.GetVkQueueInfo(queue);
    VulkanDeviceInfo*      device_info = table.GetVkDeviceInfo(device);
    GFXRECON_ASSERT(queue_info != nullptr && device_info != nullptr);

    // Transition every image subresource that has changed from its original layout.
    std::vector<VkImageMemoryBarrier> barriers;
    table.VisitVkImageInfo([this, device, &table, &barriers](const VulkanImageInfo* image_info) {
        if (image_info->handle == VK_NULL_HANDLE || image_info->parent_id != device)
        {
            return;
        }

        // Images created inside the loop range have no starting layout to return to.
        auto initial_layouts = initial_image_layouts_.find(image_info->capture_id);
        if (initial_layouts == initial_image_layouts_.end())
        {
            return;
        }

        const size_t barrier_count = barriers.size();
        AppendImageLayoutRestoreBarriers(image_info, initial_layouts->second, barriers);
        if (barriers.size() == barrier_count)
        {
            return;
        }

        VulkanImageInfo* mutable_image_info = table.GetVkImageInfo(image_info->capture_id);
        GFXRECON_ASSERT(mutable_image_info != nullptr);
        mutable_image_info->subresource_layouts = initial_layouts->second;

        mutable_image_info->intermediate_layout = barriers.back().newLayout;
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
    GetSemaphoreTracking(device).FixupSemaphores(queue);
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

    if (frame_loop_info_.IsLooping())
    {
        if (frame_loop_info_.IsFirstIteration())
        {
            VulkanQueueInfo* queue_info = GetObjectInfoTable().GetVkQueueInfo(args.queue);
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }

        for (Decoded_VkSubmitInfo submit : args.pSubmits.GetMetaStructSpan())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit2(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        if (frame_loop_info_.IsFirstIteration())
        {
            VulkanQueueInfo* queue_info = GetObjectInfoTable().GetVkQueueInfo(args.queue);
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }

        for (Decoded_VkSubmitInfo2 submit : args.pSubmits.GetMetaStructSpan())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    VulkanReplayConsumer::Process_vkQueueSubmit2KHR(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        if (frame_loop_info_.IsFirstIteration())
        {
            VulkanQueueInfo* queue_info = GetObjectInfoTable().GetVkQueueInfo(args.queue);
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }

        for (Decoded_VkSubmitInfo2 submit : args.pSubmits.GetMetaStructSpan())
        {
            FrameBoundaryEndOfFrame(args.queue, submit.pNext);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireNextImageKHR(const ApiCallInfo&         call_info,
                                                                  args::AcquireNextImageKHR& args)
{
    VulkanReplayConsumer::Process_vkAcquireNextImageKHR(call_info, args);

    if (frame_loop_info_.IsFirstIteration())
    {
        GetSemaphoreTracking(args.device).TrackSemaphores(args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireNextImage2KHR(const ApiCallInfo&          call_info,
                                                                   args::AcquireNextImage2KHR& args)
{
    VulkanReplayConsumer::Process_vkAcquireNextImage2KHR(call_info, args);

    if (frame_loop_info_.IsFirstIteration())
    {
        GetSemaphoreTracking(args.device).TrackSemaphores(args);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        CommonObjectInfoTable& table      = GetObjectInfoTable();
        VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(args.queue);
        VkDevice               device     = queue_info->parent;
        GFXRECON_ASSERT(device != VK_NULL_HANDLE);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
        GFXRECON_ASSERT(device_table != nullptr);

        if (frame_loop_info_.IsFirstIteration())
        {
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }

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
