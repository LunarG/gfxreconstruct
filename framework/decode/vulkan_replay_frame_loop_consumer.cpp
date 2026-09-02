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
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"

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
        ResetBufferTracking();
        StartLooping();
    }
}

VulkanReplayFrameLoopConsumer::~VulkanReplayFrameLoopConsumer()
{
    ResetBufferTracking();
}

void VulkanReplayFrameLoopConsumer::ResetBufferTracking()
{
    for (auto& [device_id, buffer_tracking] : per_device_buffer_tracking_)
    {
        buffer_tracking.DestroyShadowBuffers();
    }
    per_device_buffer_tracking_.clear();
}

void VulkanReplayFrameLoopConsumer::ResetBufferTracking(format::HandleId device)
{
    auto it = per_device_buffer_tracking_.find(device);
    if (it != per_device_buffer_tracking_.end())
    {
        it->second.DestroyShadowBuffers();
        per_device_buffer_tracking_.erase(it);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyDevice(const ApiCallInfo& call_info, args::DestroyDevice& args)
{
    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDevice(call_info, args);
    ResetBufferTracking(args.device);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args)
{
    VkBufferCreateInfo* create_info = args.pCreateInfo.GetPointer();

    // Ensure that buffers can be copied to and from so contents can be restored.
    if (create_info != nullptr)
    {
        create_info->usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;

        if (auto* usage_flags2_info = graphics::vulkan_struct_get_pnext<VkBufferUsageFlags2CreateInfoKHR>(create_info))
        {
            usage_flags2_info->usage |= VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR | VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR;
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(call_info, args);
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
    TrackSemaphoreStates();

    RecordBufferStates();
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

VulkanReplayFrameLoopConsumer::BufferTracking& VulkanReplayFrameLoopConsumer::GetBufferTracking(format::HandleId device)
{
    auto it = per_device_buffer_tracking_.find(device);
    if (it == per_device_buffer_tracking_.end())
    {
        auto&             object_table = GetObjectInfoTable();
        VulkanDeviceInfo* device_info  = object_table.GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        const auto& device_table = *GetDeviceTable(device_info->handle);

        VulkanPhysicalDeviceInfo* phys_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
        GFXRECON_ASSERT(phys_info != nullptr);
        const VkPhysicalDeviceMemoryProperties* memory_properties = &phys_info->capture_memory_properties;
        if (phys_info->replay_device_info != nullptr && phys_info->replay_device_info->memory_properties.has_value())
        {
            memory_properties = &phys_info->replay_device_info->memory_properties.value();
        }

        auto result = per_device_buffer_tracking_.emplace(
            device, BufferTracking(device, device_table, object_table, device_info->allocator, memory_properties));
        it = result.first;
        GFXRECON_ASSERT(result.second);
    }
    return it->second;
}

void VulkanReplayFrameLoopConsumer::RecordBufferStates()
{
    CommonObjectInfoTable& table = GetObjectInfoTable();

    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_buffers;
    table.VisitVkBufferInfo([&device_buffers](const VulkanBufferInfo* buffer_info) {
        if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE || buffer_info->size == 0)
        {
            return;
        }

        // A buffer that was created but never bound to memory (vkBindBufferMemory never called, or
        // never succeeded) has no backing memory at all.
        if (buffer_info->memory_property_flags == 0)
        {
            GFXRECON_LOG_DEBUG("RecordBufferStates: Skipping buffer %" PRIu64
                               " with no bound memory; its contents will not be restored across loop "
                               "repetitions.",
                               buffer_info->capture_id);
            return;
        }

        device_buffers[buffer_info->parent_id].push_back(buffer_info->capture_id);
    });

    for (const auto& [device_id, buffer_ids] : device_buffers)
    {
        GetBufferTracking(device_id).RecordInitialState(buffer_ids);
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceBuffers(format::HandleId device)
{
    auto it = per_device_buffer_tracking_.find(device);
    if (it == per_device_buffer_tracking_.end() || it->second.shadow_buffers_.empty())
    {
        return;
    }

    it->second.Restore(frame_loop_info_.IsFirstIteration());
}

void VulkanReplayFrameLoopConsumer::BufferTracking::RecordInitialState(const std::vector<format::HandleId>& buffer_ids)
{
    if (allocator_ == nullptr || buffer_ids.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    GFXRECON_ASSERT(device_info != nullptr);

    const uint32_t fallback_queue_family_index =
        graphics::FindGraphicsOrComputeQueueFamilyIndex(device_info->enabled_queue_family_flags);

    // Group buffers by the queue family
    std::unordered_map<uint32_t, std::vector<format::HandleId>> buffer_ids_by_family;
    for (format::HandleId buffer_id : buffer_ids)
    {
        if (shadow_buffers_.contains(buffer_id))
        {
            continue;
        }

        const VulkanBufferInfo* buffer_info = object_table_.GetVkBufferInfo(buffer_id);
        if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE || buffer_info->size == 0)
        {
            continue;
        }

        uint32_t family = fallback_queue_family_index;
        if ((buffer_info->sharing_mode == VK_SHARING_MODE_EXCLUSIVE) &&
            (buffer_info->current_queue_family_index != VK_QUEUE_FAMILY_IGNORED))
        {
            family = buffer_info->current_queue_family_index;
        }

        buffer_ids_by_family[family].push_back(buffer_id);
    }

    for (const auto& [family, family_buffer_ids] : buffer_ids_by_family)
    {
        TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
        if (temp_cmd_buff.CreateAndBegin(family) != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("RecordInitialState: Could not create a snapshot command buffer on queue family "
                                 "%u; %zu buffer(s) will not be restored across loop repetitions.",
                                 family,
                                 family_buffer_ids.size());
            continue;
        }

        uint32_t copy_count = 0;
        for (format::HandleId buffer_id : family_buffer_ids)
        {
            const VulkanBufferInfo* buffer_info = object_table_.GetVkBufferInfo(buffer_id);
            if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE)
            {
                continue;
            }

            VkBufferCreateInfo create_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
            create_info.size               = buffer_info->size;
            create_info.usage              = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            create_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;

            ShadowBuffer shadow;
            shadow.size = buffer_info->size;

            VkResult result = allocator_->CreateBufferDirect(&create_info, nullptr, &shadow.buffer, &shadow.alloc_data);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Failed to create shadow buffer for buffer %" PRIu64 " (size %" PRIu64
                                     ") with %s; its contents will not be restored across loop repetitions.",
                                     buffer_id,
                                     buffer_info->size,
                                     util::ToString(result).c_str());
                continue;
            }

            VkMemoryRequirements mem_reqs;
            device_table_.GetBufferMemoryRequirements(device_info->handle, shadow.buffer, &mem_reqs);

            uint32_t memory_type_index = graphics::GetMemoryTypeIndex(
                *memory_properties_, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
            if (memory_type_index == std::numeric_limits<uint32_t>::max())
            {
                memory_type_index = graphics::GetMemoryTypeIndex(*memory_properties_, mem_reqs.memoryTypeBits, 0);
            }
            if (memory_type_index == std::numeric_limits<uint32_t>::max())
            {
                GFXRECON_LOG_WARNING("No suitable memory type for shadow buffer for buffer %" PRIu64
                                     "; its contents will not be restored across loop repetitions.",
                                     buffer_id);
                allocator_->DestroyBufferDirect(shadow.buffer, nullptr, shadow.alloc_data);
                continue;
            }

            VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            alloc_info.allocationSize       = mem_reqs.size;
            alloc_info.memoryTypeIndex      = memory_type_index;

            result = allocator_->AllocateMemoryDirect(&alloc_info, nullptr, &shadow.memory, &shadow.mem_data);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Failed to allocate shadow memory for buffer %" PRIu64 " (size %" PRIu64
                                     ") with %s; its contents will not be restored across loop "
                                     "repetitions.",
                                     buffer_id,
                                     mem_reqs.size,
                                     util::ToString(result).c_str());
                allocator_->DestroyBufferDirect(shadow.buffer, nullptr, shadow.alloc_data);
                continue;
            }

            VkMemoryPropertyFlags bind_properties = 0;
            result                                = allocator_->BindBufferMemoryDirect(
                shadow.buffer, shadow.memory, 0, shadow.alloc_data, shadow.mem_data, &bind_properties);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Failed to bind shadow memory for buffer %" PRIu64
                                     " with %s; its contents will not be restored across loop repetitions.",
                                     buffer_id,
                                     util::ToString(result).c_str());
                allocator_->FreeMemoryDirect(shadow.memory, nullptr, shadow.mem_data);
                allocator_->DestroyBufferDirect(shadow.buffer, nullptr, shadow.alloc_data);
                continue;
            }

            VkBufferCopy region = { 0, 0, buffer_info->size };
            device_table_.CmdCopyBuffer(temp_cmd_buff.command_buffer, buffer_info->handle, shadow.buffer, 1, &region);

            shadow_buffers_[buffer_id] = shadow;
            ++copy_count;
        }

        if (copy_count > 0)
        {
            CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "vkQueueSubmit");
        }
    }
}

void VulkanReplayFrameLoopConsumer::BufferTracking::Restore(bool is_first_iteration)
{
    if (shadow_buffers_.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    GFXRECON_ASSERT(device_info != nullptr);

    const uint32_t fallback_queue_family_index =
        graphics::FindGraphicsOrComputeQueueFamilyIndex(device_info->enabled_queue_family_flags);

    // Group shadow buffers by the queue family.
    if (is_first_iteration)
    {
        buffer_ids_by_family_.clear();
        for (const auto& [buffer_id, shadow] : shadow_buffers_)
        {
            const VulkanBufferInfo* buffer_info = object_table_.GetVkBufferInfo(buffer_id);
            if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE)
            {
                continue;
            }

            uint32_t family = fallback_queue_family_index;
            if ((buffer_info->sharing_mode == VK_SHARING_MODE_EXCLUSIVE) &&
                (buffer_info->current_queue_family_index != VK_QUEUE_FAMILY_IGNORED))
            {
                family = buffer_info->current_queue_family_index;
            }

            buffer_ids_by_family_[family].push_back(buffer_id);
        }
    }

    for (const auto& [family, buffer_ids] : buffer_ids_by_family_)
    {
        TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
        if (temp_cmd_buff.CreateAndBegin(family) != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("BufferTracking::Restore: Could not create a restore command buffer on queue "
                                 "family %u; %zu buffer(s) will not be restored across loop repetitions.",
                                 family,
                                 buffer_ids.size());
            continue;
        }

        uint32_t restore_count = 0;
        for (format::HandleId buffer_id : buffer_ids)
        {
            const auto&             shadow      = shadow_buffers_.at(buffer_id);
            const VulkanBufferInfo* buffer_info = object_table_.GetVkBufferInfo(buffer_id);
            if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE)
            {
                continue;
            }

            VkBufferCopy region = { 0, 0, shadow.size };
            device_table_.CmdCopyBuffer(temp_cmd_buff.command_buffer, shadow.buffer, buffer_info->handle, 1, &region);
            ++restore_count;
        }

        // No need to submit anything if there are no buffers to restore.
        if (restore_count > 0)
        {
            CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "vkQueueSubmit");
        }
    }
}

void VulkanReplayFrameLoopConsumer::BufferTracking::DestroyShadowBuffers()
{
    if (allocator_ != nullptr)
    {
        for (auto& [buffer_id, shadow] : shadow_buffers_)
        {
            if (shadow.buffer != VK_NULL_HANDLE)
            {
                allocator_->DestroyBufferDirect(shadow.buffer, nullptr, shadow.alloc_data);
            }
            if (shadow.memory != VK_NULL_HANDLE)
            {
                allocator_->FreeMemoryDirect(shadow.memory, nullptr, shadow.mem_data);
            }
        }
    }
    shadow_buffers_.clear();
}

void VulkanReplayFrameLoopConsumer::TrackBufferQueueFamilyUsage(format::HandleId command_buffer_id,
                                                                format::HandleId buffer_id)
{
    if (buffer_id == format::kNullHandleId)
    {
        return;
    }

    CommonObjectInfoTable& table = GetObjectInfoTable();

    VulkanBufferInfo* buffer_info = table.GetVkBufferInfo(buffer_id);
    if (buffer_info == nullptr || buffer_info->sharing_mode != VK_SHARING_MODE_EXCLUSIVE)
    {
        return;
    }

    VulkanCommandBufferInfo* cb_info = table.GetVkCommandBufferInfo(command_buffer_id);
    if (cb_info == nullptr)
    {
        return;
    }

    const VulkanCommandPoolInfo* pool_info = table.GetVkCommandPoolInfo(cb_info->pool_id);
    if (pool_info == nullptr || pool_info->queue_family_index == VK_QUEUE_FAMILY_IGNORED)
    {
        return;
    }

    cb_info->buffer_queue_family_touches[buffer_id] = pool_info->queue_family_index;
}

void VulkanReplayFrameLoopConsumer::TrackBufferQueueFamilyTransfer(format::HandleId command_buffer_id,
                                                                   format::HandleId buffer_id,
                                                                   uint32_t         src_queue_family_index,
                                                                   uint32_t         dst_queue_family_index)
{
    if (buffer_id == format::kNullHandleId || src_queue_family_index == dst_queue_family_index)
    {
        return;
    }

    auto is_sentinel = [](uint32_t family) {
        return (family == VK_QUEUE_FAMILY_IGNORED) || (family == VK_QUEUE_FAMILY_EXTERNAL) ||
               (family == VK_QUEUE_FAMILY_FOREIGN_EXT);
    };
    if (is_sentinel(src_queue_family_index) || is_sentinel(dst_queue_family_index))
    {
        // Not a transfer between two real queue families on this device
        return;
    }

    CommonObjectInfoTable& table       = GetObjectInfoTable();
    VulkanBufferInfo*      buffer_info = table.GetVkBufferInfo(buffer_id);
    if (buffer_info == nullptr || buffer_info->sharing_mode != VK_SHARING_MODE_EXCLUSIVE)
    {
        return;
    }

    VulkanCommandBufferInfo* cb_info = table.GetVkCommandBufferInfo(command_buffer_id);
    if (cb_info == nullptr)
    {
        return;
    }

    cb_info->buffer_queue_family_touches[buffer_id] = dst_queue_family_index;
}

void VulkanReplayFrameLoopConsumer::TrackBufferOwnershipTransfers(format::HandleId                command_buffer_id,
                                                                  const Decoded_VkDependencyInfo* dependency_info_meta)
{
    if (dependency_info_meta == nullptr || dependency_info_meta->pBufferMemoryBarriers == nullptr)
    {
        return;
    }

    TrackBufferMemoryBarrierTransfers(command_buffer_id, *dependency_info_meta->pBufferMemoryBarriers);
}

void VulkanReplayFrameLoopConsumer::TrackBufferMemoryBarrierTransfers(
    format::HandleId command_buffer_id, const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& barriers)
{
    const auto* meta = barriers.GetMetaStructPointer();
    const auto* raw  = barriers.GetPointer();
    if (meta == nullptr || raw == nullptr)
    {
        return;
    }

    const size_t count = barriers.GetLength();
    for (size_t i = 0; i < count; ++i)
    {
        TrackBufferQueueFamilyTransfer(
            command_buffer_id, meta[i].buffer, raw[i].srcQueueFamilyIndex, raw[i].dstQueueFamilyIndex);
    }
}

void VulkanReplayFrameLoopConsumer::TrackBufferMemoryBarrierTransfers(
    format::HandleId command_buffer_id, const StructPointerDecoder<Decoded_VkBufferMemoryBarrier2>& barriers)
{
    const auto* meta = barriers.GetMetaStructPointer();
    const auto* raw  = barriers.GetPointer();
    if (meta == nullptr || raw == nullptr)
    {
        return;
    }

    const size_t count = barriers.GetLength();
    for (size_t i = 0; i < count; ++i)
    {
        TrackBufferQueueFamilyTransfer(
            command_buffer_id, meta[i].buffer, raw[i].srcQueueFamilyIndex, raw[i].dstQueueFamilyIndex);
    }
}

void VulkanReplayFrameLoopConsumer::ApplyBufferQueueFamilyOwnership(format::HandleId command_buffer_id)
{
    CommonObjectInfoTable&   table   = GetObjectInfoTable();
    VulkanCommandBufferInfo* cb_info = table.GetVkCommandBufferInfo(command_buffer_id);
    if (cb_info == nullptr || cb_info->buffer_queue_family_touches.empty())
    {
        return;
    }

    for (const auto& [buffer_id, family_index] : cb_info->buffer_queue_family_touches)
    {
        VulkanBufferInfo* buffer_info = table.GetVkBufferInfo(buffer_id);
        if (buffer_info != nullptr)
        {
            buffer_info->current_queue_family_index = family_index;
        }
    }
}

void VulkanReplayFrameLoopConsumer::ApplyBufferQueueFamilyOwnership(StructPointerDecoder<Decoded_VkSubmitInfo>& submits)
{
    for (const Decoded_VkSubmitInfo& submit : submits.GetMetaStructSpan())
    {
        const format::HandleId* command_buffer_ids   = submit.pCommandBuffers.GetPointer();
        size_t                  command_buffer_count = submit.pCommandBuffers.GetLength();
        for (size_t i = 0; i < command_buffer_count; ++i)
        {
            ApplyBufferQueueFamilyOwnership(command_buffer_ids[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ApplyBufferQueueFamilyOwnership(
    StructPointerDecoder<Decoded_VkSubmitInfo2>& submits)
{
    for (const Decoded_VkSubmitInfo2& submit : submits.GetMetaStructSpan())
    {
        if (submit.pCommandBufferInfos == nullptr)
        {
            continue;
        }

        const auto* command_buffer_infos = submit.pCommandBufferInfos->GetMetaStructPointer();
        size_t      command_buffer_count = submit.pCommandBufferInfos->GetLength();
        for (size_t i = 0; i < command_buffer_count; ++i)
        {
            ApplyBufferQueueFamilyOwnership(command_buffer_infos[i].commandBuffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBuffer(const ApiCallInfo& call_info, args::CmdCopyBuffer& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBuffer(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.srcBuffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBuffer2(const ApiCallInfo& call_info, args::CmdCopyBuffer2& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2(call_info, args);
    const auto* info = args.pCopyBufferInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->srcBuffer);
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->dstBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBuffer2KHR(const ApiCallInfo&       call_info,
                                                                args::CmdCopyBuffer2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(call_info, args);
    const auto* info = args.pCopyBufferInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->srcBuffer);
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->dstBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdFillBuffer(const ApiCallInfo& call_info, args::CmdFillBuffer& args)
{
    VulkanReplayConsumer::Process_vkCmdFillBuffer(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdUpdateBuffer(const ApiCallInfo& call_info, args::CmdUpdateBuffer& args)
{
    VulkanReplayConsumer::Process_vkCmdUpdateBuffer(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindVertexBuffers(const ApiCallInfo&          call_info,
                                                                   args::CmdBindVertexBuffers& args)
{
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(call_info, args);
    const format::HandleId* buffers = args.pBuffers.GetPointer();
    if (buffers != nullptr)
    {
        for (uint32_t i = 0; i < args.bindingCount; ++i)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffers[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindVertexBuffers2(const ApiCallInfo&           call_info,
                                                                    args::CmdBindVertexBuffers2& args)
{
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2(call_info, args);
    const format::HandleId* buffers = args.pBuffers.GetPointer();
    if (buffers != nullptr)
    {
        for (uint32_t i = 0; i < args.bindingCount; ++i)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffers[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindVertexBuffers2EXT(const ApiCallInfo&              call_info,
                                                                       args::CmdBindVertexBuffers2EXT& args)
{
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2EXT(call_info, args);
    const format::HandleId* buffers = args.pBuffers.GetPointer();
    if (buffers != nullptr)
    {
        for (uint32_t i = 0; i < args.bindingCount; ++i)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffers[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindIndexBuffer(const ApiCallInfo&        call_info,
                                                                 args::CmdBindIndexBuffer& args)
{
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindIndexBuffer2(const ApiCallInfo&         call_info,
                                                                  args::CmdBindIndexBuffer2& args)
{
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindIndexBuffer2KHR(const ApiCallInfo&            call_info,
                                                                     args::CmdBindIndexBuffer2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2KHR(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndirect(const ApiCallInfo& call_info, args::CmdDrawIndirect& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndirect(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndexedIndirect(const ApiCallInfo&            call_info,
                                                                     args::CmdDrawIndexedIndirect& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndirectCount(const ApiCallInfo&          call_info,
                                                                   args::CmdDrawIndirectCount& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCount(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndirectCountKHR(const ApiCallInfo&             call_info,
                                                                      args::CmdDrawIndirectCountKHR& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndexedIndirectCount(const ApiCallInfo&                 call_info,
                                                                          args::CmdDrawIndexedIndirectCount& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(const ApiCallInfo& call_info,
                                                                             args::CmdDrawIndexedIndirectCountKHR& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDispatchIndirect(const ApiCallInfo&         call_info,
                                                                  args::CmdDispatchIndirect& args)
{
    VulkanReplayConsumer::Process_vkCmdDispatchIndirect(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBufferToImage(const ApiCallInfo&          call_info,
                                                                   args::CmdCopyBufferToImage& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.srcBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBufferToImage2(const ApiCallInfo&           call_info,
                                                                    args::CmdCopyBufferToImage2& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(call_info, args);
    const auto* info = args.pCopyBufferToImageInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->srcBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyBufferToImage2KHR(const ApiCallInfo&              call_info,
                                                                       args::CmdCopyBufferToImage2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(call_info, args);
    const auto* info = args.pCopyBufferToImageInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->srcBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyImageToBuffer(const ApiCallInfo&          call_info,
                                                                   args::CmdCopyImageToBuffer& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyImageToBuffer2(const ApiCallInfo&           call_info,
                                                                    args::CmdCopyImageToBuffer2& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(call_info, args);
    const auto* info = args.pCopyImageToBufferInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->dstBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyImageToBuffer2KHR(const ApiCallInfo&              call_info,
                                                                       args::CmdCopyImageToBuffer2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(call_info, args);
    const auto* info = args.pCopyImageToBufferInfo.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->dstBuffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdCopyQueryPoolResults(const ApiCallInfo&             call_info,
                                                                      args::CmdCopyQueryPoolResults& args)
{
    VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier(const ApiCallInfo&        call_info,
                                                                 args::CmdPipelineBarrier& args)
{
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier(call_info, args);
    TrackBufferMemoryBarrierTransfers(args.commandBuffer, args.pBufferMemoryBarriers);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier2(const ApiCallInfo&         call_info,
                                                                  args::CmdPipelineBarrier2& args)
{
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(call_info, args);
    TrackBufferOwnershipTransfers(args.commandBuffer, args.pDependencyInfo.GetMetaStructPointer());
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPipelineBarrier2KHR(const ApiCallInfo&            call_info,
                                                                     args::CmdPipelineBarrier2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(call_info, args);
    TrackBufferOwnershipTransfers(args.commandBuffer, args.pDependencyInfo.GetMetaStructPointer());
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWaitEvents(const ApiCallInfo& call_info, args::CmdWaitEvents& args)
{
    VulkanReplayConsumer::Process_vkCmdWaitEvents(call_info, args);
    TrackBufferMemoryBarrierTransfers(args.commandBuffer, args.pBufferMemoryBarriers);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWaitEvents2(const ApiCallInfo& call_info, args::CmdWaitEvents2& args)
{
    VulkanReplayConsumer::Process_vkCmdWaitEvents2(call_info, args);

    const auto* dependency_infos = args.pDependencyInfos.GetMetaStructPointer();
    if (dependency_infos != nullptr)
    {
        for (uint32_t i = 0; i < args.eventCount; ++i)
        {
            TrackBufferOwnershipTransfers(args.commandBuffer, &dependency_infos[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWaitEvents2KHR(const ApiCallInfo&       call_info,
                                                                args::CmdWaitEvents2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(call_info, args);

    const auto* dependency_infos = args.pDependencyInfos.GetMetaStructPointer();
    if (dependency_infos != nullptr)
    {
        for (uint32_t i = 0; i < args.eventCount; ++i)
        {
            TrackBufferOwnershipTransfers(args.commandBuffer, &dependency_infos[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdSetEvent2(const ApiCallInfo& call_info, args::CmdSetEvent2& args)
{
    VulkanReplayConsumer::Process_vkCmdSetEvent2(call_info, args);
    TrackBufferOwnershipTransfers(args.commandBuffer, args.pDependencyInfo.GetMetaStructPointer());
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdSetEvent2KHR(const ApiCallInfo& call_info, args::CmdSetEvent2KHR& args)
{
    VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(call_info, args);
    TrackBufferOwnershipTransfers(args.commandBuffer, args.pDependencyInfo.GetMetaStructPointer());
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo& call_info, args::CmdBindTransformFeedbackBuffersEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, args);
    for (format::HandleId buffer_id : args.pBuffers.GetSpan())
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, buffer_id);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndirectByteCountEXT(const ApiCallInfo&                 call_info,
                                                                          args::CmdDrawIndirectByteCountEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.counterBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndirectCountAMD(const ApiCallInfo&             call_info,
                                                                      args::CmdDrawIndirectCountAMD& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(const ApiCallInfo& call_info,
                                                                             args::CmdDrawIndexedIndirectCountAMD& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo& call_info, args::CmdBeginConditionalRenderingEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(call_info, args);
    const auto* info = args.pConditionalRenderingBegin.GetMetaStructPointer();
    if (info != nullptr)
    {
        TrackBufferQueueFamilyUsage(args.commandBuffer, info->buffer);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo& call_info, args::CmdBuildAccelerationStructureNV& args)
{
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.instanceData);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.scratch);
    // Note: vertex/index/transform buffers nested in args.pInfo->pGeometries are not tracked here.
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdTraceRaysNV(const ApiCallInfo& call_info, args::CmdTraceRaysNV& args)
{
    VulkanReplayConsumer::Process_vkCmdTraceRaysNV(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.raygenShaderBindingTableBuffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.missShaderBindingTableBuffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.hitShaderBindingTableBuffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.callableShaderBindingTableBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWriteBufferMarkerAMD(const ApiCallInfo&             call_info,
                                                                      args::CmdWriteBufferMarkerAMD& args)
{
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWriteBufferMarker2AMD(const ApiCallInfo&              call_info,
                                                                       args::CmdWriteBufferMarker2AMD& args)
{
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.dstBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawMeshTasksIndirectNV(const ApiCallInfo&                call_info,
                                                                         args::CmdDrawMeshTasksIndirectNV& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo& call_info, args::CmdDrawMeshTasksIndirectCountNV& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(const ApiCallInfo&                 call_info,
                                                                          args::CmdDrawMeshTasksIndirectEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo& call_info, args::CmdDrawMeshTasksIndirectCountEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.countBuffer);
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo& call_info, args::CmdPreprocessGeneratedCommandsNV& args)
{
    VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(call_info, args);

    const auto* info = args.pGeneratedCommandsInfo.GetMetaStructPointer();
    if (info == nullptr)
    {
        return;
    }

    TrackBufferQueueFamilyUsage(args.commandBuffer, info->preprocessBuffer);

    if (info->pStreams != nullptr && !info->pStreams->IsNull() && info->pStreams->HasData())
    {
        const auto* streams = info->pStreams->GetMetaStructPointer();
        for (uint32_t i = 0; i < info->pStreams->GetLength(); ++i)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, streams[i].buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdExecuteGeneratedCommandsNV(const ApiCallInfo& call_info,
                                                                            args::CmdExecuteGeneratedCommandsNV& args)
{
    VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(call_info, args);

    const auto* info = args.pGeneratedCommandsInfo.GetMetaStructPointer();
    if (info == nullptr)
    {
        return;
    }

    TrackBufferQueueFamilyUsage(args.commandBuffer, info->preprocessBuffer);

    if (info->pStreams != nullptr && !info->pStreams->IsNull() && info->pStreams->HasData())
    {
        const auto* streams = info->pStreams->GetMetaStructPointer();
        for (uint32_t i = 0; i < info->pStreams->GetLength(); ++i)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, streams[i].buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindDescriptorBuffersEXT(const ApiCallInfo&                 call_info,
                                                                          args::CmdBindDescriptorBuffersEXT& args)
{
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBuffersEXT(call_info, args);

    const auto* binding_infos = args.pBindingInfos.GetMetaStructPointer();
    if (binding_infos == nullptr)
    {
        return;
    }

    for (uint32_t i = 0; i < args.bufferCount; ++i)
    {
        const auto* buffer_handle_info =
            GetPNextMetaStruct<Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT>(binding_infos[i].pNext);
        if (buffer_handle_info != nullptr)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffer_handle_info->buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(const ApiCallInfo& call_info,
                                                                           args::CmdDrawClusterIndirectHUAWEI& args)
{
    VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(call_info, args);
    TrackBufferQueueFamilyUsage(args.commandBuffer, args.buffer);
}

void VulkanReplayFrameLoopConsumer::TrackDescriptorSetBufferWrite(format::HandleId set_id,
                                                                  uint32_t         binding,
                                                                  uint32_t         array_element,
                                                                  format::HandleId buffer_id)
{
    if (set_id == format::kNullHandleId || buffer_id == format::kNullHandleId)
    {
        return;
    }

    const uint64_t slot                   = (static_cast<uint64_t>(binding) << 32) | array_element;
    descriptor_set_buffers_[set_id][slot] = buffer_id;
}

void VulkanReplayFrameLoopConsumer::TrackDescriptorSetBufferUsage(format::HandleId command_buffer_id,
                                                                  format::HandleId set_id)
{
    auto it = descriptor_set_buffers_.find(set_id);
    if (it == descriptor_set_buffers_.end())
    {
        return;
    }

    for (const auto& [slot, buffer_id] : it->second)
    {
        TrackBufferQueueFamilyUsage(command_buffer_id, buffer_id);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkUpdateDescriptorSets(const ApiCallInfo&          call_info,
                                                                   args::UpdateDescriptorSets& args)
{
    VulkanReplayConsumer::Process_vkUpdateDescriptorSets(call_info, args);

    const auto* writes      = args.pDescriptorWrites.GetPointer();
    const auto* meta_writes = args.pDescriptorWrites.GetMetaStructPointer();
    if (writes == nullptr || meta_writes == nullptr)
    {
        return;
    }

    for (uint32_t i = 0; i < args.descriptorWriteCount; ++i)
    {
        const auto* buffer_info = meta_writes[i].pBufferInfo;
        if (buffer_info == nullptr || buffer_info->IsNull() || !buffer_info->HasData())
        {
            continue;
        }

        const auto* buffer_meta = buffer_info->GetMetaStructPointer();
        for (uint32_t element = 0; element < writes[i].descriptorCount; ++element)
        {
            TrackDescriptorSetBufferWrite(meta_writes[i].dstSet,
                                          writes[i].dstBinding,
                                          writes[i].dstArrayElement + element,
                                          buffer_meta[element].buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdBindDescriptorSets(const ApiCallInfo&           call_info,
                                                                    args::CmdBindDescriptorSets& args)
{
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(call_info, args);
    for (format::HandleId set_id : args.pDescriptorSets.GetSpan())
    {
        TrackDescriptorSetBufferUsage(args.commandBuffer, set_id);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPushDescriptorSet(const ApiCallInfo&          call_info,
                                                                   args::CmdPushDescriptorSet& args)
{
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet(call_info, args);

    const auto* meta_writes = args.pDescriptorWrites.GetMetaStructPointer();
    if (meta_writes == nullptr)
    {
        return;
    }

    for (uint32_t i = 0; i < args.descriptorWriteCount; ++i)
    {
        const auto* buffer_info = meta_writes[i].pBufferInfo;
        if (buffer_info == nullptr || buffer_info->IsNull() || !buffer_info->HasData())
        {
            continue;
        }

        const auto* buffer_meta = buffer_info->GetMetaStructPointer();
        for (uint32_t element = 0; element < buffer_info->GetLength(); ++element)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffer_meta[element].buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdPushDescriptorSetKHR(const ApiCallInfo&             call_info,
                                                                      args::CmdPushDescriptorSetKHR& args)
{
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(call_info, args);

    const auto* meta_writes = args.pDescriptorWrites.GetMetaStructPointer();
    if (meta_writes == nullptr)
    {
        return;
    }

    for (uint32_t i = 0; i < args.descriptorWriteCount; ++i)
    {
        const auto* buffer_info = meta_writes[i].pBufferInfo;
        if (buffer_info == nullptr || buffer_info->IsNull() || !buffer_info->HasData())
        {
            continue;
        }

        const auto* buffer_meta = buffer_info->GetMetaStructPointer();
        for (uint32_t element = 0; element < buffer_info->GetLength(); ++element)
        {
            TrackBufferQueueFamilyUsage(args.commandBuffer, buffer_meta[element].buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdExecuteCommands(const ApiCallInfo&        call_info,
                                                                 args::CmdExecuteCommands& args)
{
    VulkanReplayConsumer::Process_vkCmdExecuteCommands(call_info, args);

    CommonObjectInfoTable&   table           = GetObjectInfoTable();
    VulkanCommandBufferInfo* primary_cb_info = table.GetVkCommandBufferInfo(args.commandBuffer);
    if (primary_cb_info == nullptr)
    {
        return;
    }

    const format::HandleId* secondary_ids = args.pCommandBuffers.GetPointer();
    if (secondary_ids == nullptr)
    {
        return;
    }

    for (uint32_t i = 0; i < args.commandBufferCount; ++i)
    {
        VulkanCommandBufferInfo* secondary_cb_info = table.GetVkCommandBufferInfo(secondary_ids[i]);
        if (secondary_cb_info == nullptr)
        {
            continue;
        }

        // If two secondary command buffers touch the same buffer, the one that executes later should overwrite
        for (const auto& [buffer_id, family_index] : secondary_cb_info->buffer_queue_family_touches)
        {
            primary_cb_info->buffer_queue_family_touches[buffer_id] = family_index;
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkBeginCommandBuffer(const ApiCallInfo&        call_info,
                                                                 args::BeginCommandBuffer& args)
{
    VulkanReplayConsumer::Process_vkBeginCommandBuffer(call_info, args);
    if (VulkanCommandBufferInfo* cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer))
    {
        cb_info->buffer_queue_family_touches.clear();
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkResetCommandBuffer(const ApiCallInfo&        call_info,
                                                                 args::ResetCommandBuffer& args)
{
    VulkanReplayConsumer::Process_vkResetCommandBuffer(call_info, args);
    if (VulkanCommandBufferInfo* cb_info = GetObjectInfoTable().GetVkCommandBufferInfo(args.commandBuffer))
    {
        cb_info->buffer_queue_family_touches.clear();
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

void VulkanReplayFrameLoopConsumer::FixupDeviceObjects(format::HandleId device, format::HandleId queue)
{
    if (!frame_loop_info_.IsLooping() || frame_loop_info_.IsFinalIteration())
    {
        return;
    }
    FixupDeviceEvents(device);
    FixupDeviceFences(device, queue);
    FixupDeviceBuffers(device);
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

    ApplyBufferQueueFamilyOwnership(args.pSubmits);

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

    ApplyBufferQueueFamilyOwnership(args.pSubmits);

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

    ApplyBufferQueueFamilyOwnership(args.pSubmits);

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
