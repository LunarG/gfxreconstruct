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
    if (!frame_loop_info_.IsLooping() || frame_loop_info_.IsFinalIteration())
    {
        ResetBufferTracking(args.device);
    }
    VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDevice(call_info, args);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args)
{
    VkBufferCreateInfo* create_info = args.pCreateInfo.GetPointer();

    // Ensure that buffers can be copied to and from so contents can be restored.
    if (create_info != nullptr)
    {
        create_info->usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
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

    it->second.Restore();
}

void VulkanReplayFrameLoopConsumer::BufferTracking::RecordInitialState(const std::vector<format::HandleId>& buffer_ids)
{
    if (allocator_ == nullptr || buffer_ids.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    GFXRECON_ASSERT(device_info != nullptr);

    TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
    if (temp_cmd_buff.CreateAndBegin(graphics::FindGraphicsOrComputeQueueFamilyIndex) != VK_SUCCESS)
    {
        return;
    }

    uint32_t copy_count = 0;
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

void VulkanReplayFrameLoopConsumer::BufferTracking::Restore()
{
    if (shadow_buffers_.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    GFXRECON_ASSERT(device_info != nullptr);

    TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
    if (temp_cmd_buff.CreateAndBegin(graphics::FindGraphicsOrComputeQueueFamilyIndex) != VK_SUCCESS)
    {
        return;
    }

    uint32_t restore_count = 0;
    for (const auto& [buffer_id, shadow] : shadow_buffers_)
    {
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
