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
#include "graphics/vulkan_resources_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
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
        ResetImageTracking();
        StartLooping();
    }
}

VulkanReplayFrameLoopConsumer::~VulkanReplayFrameLoopConsumer()
{
    ResetBufferTracking();
    ResetImageTracking();
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
        ResetImageTracking(args.device);
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

        if (auto* usage_flags2 = graphics::vulkan_struct_get_pnext<VkBufferUsageFlags2CreateInfo>(create_info))
        {
            usage_flags2->usage |= VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_2_TRANSFER_DST_BIT;
        }
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(call_info, args);
}

static bool CanRestoreImage(const VkImageCreateInfo* create_info)
{
    if (const auto* usage_flags2 = graphics::vulkan_struct_get_pnext<VkImageUsageFlags2CreateInfoKHR>(create_info))
    {
        if ((usage_flags2->usage & VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR) != 0)
        {
            return true;
        }
    }
    else if ((create_info->usage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) != 0)
    {
        return true;
    }

    if (const auto* stencil_usage2 = graphics::vulkan_struct_get_pnext<VkImageStencilUsage2CreateInfoKHR>(create_info))
    {
        return (stencil_usage2->stencilUsage & VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR) != 0;
    }
    if (const auto* stencil_usage = graphics::vulkan_struct_get_pnext<VkImageStencilUsageCreateInfo>(create_info))
    {
        return (stencil_usage->stencilUsage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) != 0;
    }

    return false;
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args)
{
    VkImageCreateInfo* create_info = args.pCreateInfo.GetPointer();

    if ((create_info != nullptr) && !args.pImage.IsNull() && !CanRestoreImage(create_info))
    {
        create_info->usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

        if (auto* usage_flags2 = graphics::vulkan_struct_get_pnext<VkImageUsageFlags2CreateInfoKHR>(create_info))
        {
            usage_flags2->usage |= VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR | VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR;
        }
        if (auto* stencil_usage = graphics::vulkan_struct_get_pnext<VkImageStencilUsageCreateInfo>(create_info))
        {
            stencil_usage->stencilUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        }
        if (auto* stencil_usage2 = graphics::vulkan_struct_get_pnext<VkImageStencilUsage2CreateInfoKHR>(create_info))
        {
            stencil_usage2->stencilUsage |=
                VK_IMAGE_USAGE_2_TRANSFER_SRC_BIT_KHR | VK_IMAGE_USAGE_2_TRANSFER_DST_BIT_KHR;
        }

        restorable_images_.insert(*args.pImage.GetPointer());
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateImage(call_info, args);
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
    TrackImageStates();
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
    if (it == per_device_buffer_tracking_.end())
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

// Accounts for multi-planar formats, which require that all planes be transitioned together.
static VkImageAspectFlags ToBarrierAspects(VkImageAspectFlags transition_aspects, VkImageAspectFlags image_aspects)
{
    constexpr VkImageAspectFlags kPlaneAspects =
        VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT | VK_IMAGE_ASPECT_PLANE_2_BIT;

    const VkImageAspectFlags planes = transition_aspects & kPlaneAspects;
    if ((planes != 0) && (planes == (image_aspects & kPlaneAspects)))
    {
        return (transition_aspects & ~kPlaneAspects) | VK_IMAGE_ASPECT_COLOR_BIT;
    }

    return transition_aspects;
}

static void AppendImageLayoutBarriers(const VulkanImageInfo*             image_info,
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
            barriers.push_back(
                MakeLayoutRestoreBarrier(image_info->handle,
                                         current,
                                         initial,
                                         { ToBarrierAspects(aspects, aspects), 0, mip_levels, 0, array_layers }));
        }
        return;
    }

    struct AspectTransition
    {
        VkImageAspectFlags aspects;
        VkImageLayout      old_layout;
        VkImageLayout      new_layout;
    };
    // Map to group aspects sharing the same transition.
    AspectTransition transitions[std::size(graphics::kLayoutMapAspects)];

    // Restore each subresource individually, while coalescing aspects.
    for (uint32_t mip_level = 0; mip_level < mip_levels; ++mip_level)
    {
        for (uint32_t array_layer = 0; array_layer < array_layers; ++array_layer)
        {
            uint32_t transition_count = 0;

            for (VkImageAspectFlagBits aspect : graphics::kLayoutMapAspects)
            {
                if ((aspects & aspect) == 0)
                {
                    continue;
                }

                const VkImageLayout initial = initial_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);
                const VkImageLayout current = current_layouts.GetSubresourceLayout(aspect, mip_level, array_layer);

                if ((initial == current) || !IsRestorableLayout(initial))
                {
                    continue;
                }

                // Check if there is an existing transition (uses the same old and new layouts).
                uint32_t index = 0;
                while ((index < transition_count) &&
                       ((transitions[index].old_layout != current) || (transitions[index].new_layout != initial)))
                {
                    ++index;
                }
                // Otherwise create a new transition.
                if (index == transition_count)
                {
                    transitions[transition_count++] = { 0, current, initial };
                }

                transitions[index].aspects |= aspect;
            }

            for (uint32_t index = 0; index < transition_count; ++index)
            {
                const AspectTransition& transition = transitions[index];

                barriers.push_back(MakeLayoutRestoreBarrier(
                    image_info->handle,
                    transition.old_layout,
                    transition.new_layout,
                    { ToBarrierAspects(transition.aspects, aspects), mip_level, 1, array_layer, 1 }));
            }
        }
    }
}

static bool IsSubresourceCopyable(const graphics::ImageLayoutMap& layouts,
                                  VkImageAspectFlags              aspects,
                                  uint32_t                        mip_level,
                                  uint32_t                        array_layer)
{
    for (VkImageAspectFlagBits aspect : graphics::kLayoutMapAspects)
    {
        if (((aspects & aspect) != 0) &&
            !IsRestorableLayout(layouts.GetSubresourceLayout(aspect, mip_level, array_layer)))
        {
            return false;
        }
    }
    return true;
}

// Collects the subresources whose layout at the start of the loop range can be
// transitioned away from and back to.
static void BuildCopyableSubresourceRanges(const VulkanImageInfo*                image_info,
                                           const graphics::ImageLayoutMap&       initial_layouts,
                                           std::vector<VkImageSubresourceRange>& ranges,
                                           std::vector<VkImageSubresourceRange>& excluded_ranges)
{
    std::vector<VkImageAspectFlagBits> aspects;
    bool                               combined_depth_stencil = false;
    graphics::GetFormatAspects(image_info->format, &aspects, &combined_depth_stencil);

    // The depth and stencil aspects of a combined format
    if (combined_depth_stencil)
    {
        aspects.assign(1, static_cast<VkImageAspectFlagBits>(VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT));
    }

    for (VkImageAspectFlagBits aspect : aspects)
    {
        const VkImageAspectFlags aspect_mask = static_cast<VkImageAspectFlags>(aspect);

        for (uint32_t mip_level = 0; mip_level < image_info->level_count; ++mip_level)
        {
            // Coalesce neighbouring layers
            uint32_t run_start    = 0;
            uint32_t run_count    = 0;
            bool     run_copyable = false;

            for (uint32_t array_layer = 0; array_layer < image_info->layer_count; ++array_layer)
            {
                const bool copyable = IsSubresourceCopyable(initial_layouts, aspect_mask, mip_level, array_layer);

                if ((run_count != 0) && (copyable != run_copyable))
                {
                    (run_copyable ? ranges : excluded_ranges)
                        .push_back({ aspect_mask, mip_level, 1, run_start, run_count });
                    run_count = 0;
                }

                if (run_count == 0)
                {
                    run_start    = array_layer;
                    run_copyable = copyable;
                }
                ++run_count;
            }

            if (run_count != 0)
            {
                (run_copyable ? ranges : excluded_ranges)
                    .push_back({ aspect_mask, mip_level, 1, run_start, run_count });
            }
        }
    }
}

static void BuildImageCopyRegions(const VulkanImageInfo*                      image_info,
                                  const std::vector<VkImageSubresourceRange>& ranges,
                                  std::vector<VkImageCopy>&                   regions)
{
    regions.reserve(ranges.size());

    for (const VkImageSubresourceRange& range : ranges)
    {
        const VkImageSubresourceLayers subresource = {
            range.aspectMask, range.baseMipLevel, range.baseArrayLayer, range.layerCount
        };

        VkExtent3D extent = graphics::ScaleToMipLevel(image_info->extent, range.baseMipLevel);

        if (vkuFormatIsMultiplane(image_info->format))
        {
            const VkExtent2D divisors = vkuFindMultiplaneExtentDivisors(
                image_info->format, static_cast<VkImageAspectFlagBits>(range.aspectMask));

            extent.width /= divisors.width;
            extent.height /= divisors.height;
        }

        VkImageCopy region    = {};
        region.srcSubresource = subresource;
        region.dstSubresource = subresource;
        region.extent         = extent;
        regions.push_back(region);
    }
}

static void AppendTransferLayoutBarriers(const VulkanImageInfo*                      image_info,
                                         const std::vector<VkImageSubresourceRange>& excluded_ranges,
                                         VkImageLayout                               transfer_layout,
                                         std::vector<VkImageMemoryBarrier>&          barriers)
{
    graphics::ImageLayoutMap target_layouts = image_info->subresource_layouts;
    target_layouts.SetUniformLayout(transfer_layout);

    for (const VkImageSubresourceRange& range : excluded_ranges)
    {
        target_layouts.SetLayout(range, VK_IMAGE_LAYOUT_UNDEFINED);
    }

    AppendImageLayoutBarriers(image_info, target_layouts, barriers);
}

static void ReverseLayoutBarriers(std::vector<VkImageMemoryBarrier>& barriers, size_t first = 0)
{
    for (size_t i = first; i < barriers.size(); ++i)
    {
        std::swap(barriers[i].oldLayout, barriers[i].newLayout);
    }
}

static void CmdImageLayoutBarriers(const graphics::VulkanDeviceTable&       device_table,
                                   VkCommandBuffer                          command_buffer,
                                   const std::vector<VkImageMemoryBarrier>& barriers)
{
    if (barriers.empty())
    {
        return;
    }

    device_table.CmdPipelineBarrier(command_buffer,
                                    VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    0,
                                    0,
                                    nullptr,
                                    0,
                                    nullptr,
                                    static_cast<uint32_t>(barriers.size()),
                                    barriers.data());
}

VulkanReplayFrameLoopConsumer::ImageTracking& VulkanReplayFrameLoopConsumer::GetImageTracking(format::HandleId device)
{
    auto it = per_device_image_tracking_.find(device);
    if (it == per_device_image_tracking_.end())
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

        auto result = per_device_image_tracking_.emplace(
            device, ImageTracking(device, device_table, object_table, device_info->allocator, memory_properties));
        it = result.first;
        GFXRECON_ASSERT(result.second);
    }
    return it->second;
}

bool VulkanReplayFrameLoopConsumer::CanSnapshotImageContents(const VulkanImageInfo* image_info) const
{
    const format::HandleId image_id = image_info->capture_id;

    if (!restorable_images_.contains(image_id))
    {
        return false;
    }

    if (image_info->memory_property_flags == 0)
    {
        GFXRECON_LOG_DEBUG("TrackImageStates: Skipping image %" PRIu64
                           " with no bound memory; its contents will not be restored across loop repetitions.",
                           image_id);
        return false;
    }

    if ((image_info->memory_property_flags & VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT) != 0)
    {
        GFXRECON_LOG_DEBUG("TrackImageStates: Skipping image %" PRIu64
                           " backed by lazily allocated memory; its contents will not be restored across loop "
                           "repetitions.",
                           image_id);
        return false;
    }

    return true;
}

void VulkanReplayFrameLoopConsumer::TrackImageStates()
{
    // Images that exists now and therefore needs its layouts recorded.
    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_images;
    // Images that can have content restored.
    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_restorable_images;

    GetObjectInfoTable().VisitVkImageInfo(
        [this, &device_images, &device_restorable_images](const VulkanImageInfo* image_info) {
            if (image_info->handle == VK_NULL_HANDLE)
            {
                return;
            }

            device_images[image_info->parent_id].push_back(image_info->capture_id);

            if (CanSnapshotImageContents(image_info))
            {
                device_restorable_images[image_info->parent_id].push_back(image_info->capture_id);
            }
        });

    for (const auto& [device_id, image_ids] : device_images)
    {
        GetImageTracking(device_id).RecordInitialState(image_ids, device_restorable_images[device_id]);
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceImages(format::HandleId device, format::HandleId queue)
{
    auto it = per_device_image_tracking_.find(device);
    if (it == per_device_image_tracking_.end())
    {
        return;
    }

    it->second.Restore(queue);
}

void VulkanReplayFrameLoopConsumer::ResetImageTracking()
{
    for (auto& [device_id, image_tracking] : per_device_image_tracking_)
    {
        image_tracking.DestroyShadowImages();
    }
    per_device_image_tracking_.clear();
}

void VulkanReplayFrameLoopConsumer::ResetImageTracking(format::HandleId device)
{
    auto it = per_device_image_tracking_.find(device);
    if (it != per_device_image_tracking_.end())
    {
        it->second.DestroyShadowImages();
        per_device_image_tracking_.erase(it);
    }
}

// Creates the device-local image that an image's contents are snapshotted into, and binds memory to it.
bool VulkanReplayFrameLoopConsumer::ImageTracking::CreateShadowImage(format::HandleId       image_id,
                                                                     const VulkanImageInfo* image_info,
                                                                     ImageState&            state)
{
    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    GFXRECON_ASSERT(device_info != nullptr);

    VkImageCreateInfo create_info = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.imageType         = image_info->type;
    create_info.format            = image_info->format;
    create_info.extent            = image_info->extent;
    create_info.mipLevels         = image_info->level_count;
    create_info.arrayLayers       = image_info->layer_count;
    create_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
    create_info.usage             = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;
    create_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;

    VkResult result = allocator_->CreateImageDirect(&create_info, nullptr, &state.shadow_image, &state.alloc_data);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Failed to create shadow image for image %" PRIu64
                             " with %s; its contents will not be restored across loop repetitions.",
                             image_id,
                             util::ToString(result).c_str());
        state.shadow_image = VK_NULL_HANDLE;
        return false;
    }

    VkMemoryRequirements mem_reqs;
    device_table_.GetImageMemoryRequirements(device_info->handle, state.shadow_image, &mem_reqs);

    uint32_t memory_type_index =
        graphics::GetMemoryTypeIndex(*memory_properties_, mem_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    if (memory_type_index == std::numeric_limits<uint32_t>::max())
    {
        memory_type_index = graphics::GetMemoryTypeIndex(*memory_properties_, mem_reqs.memoryTypeBits, 0);
    }
    if (memory_type_index == std::numeric_limits<uint32_t>::max())
    {
        GFXRECON_LOG_WARNING("No suitable memory type for shadow image for image %" PRIu64
                             "; its contents will not be restored across loop repetitions.",
                             image_id);
        return false;
    }

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.allocationSize       = mem_reqs.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    result = allocator_->AllocateMemoryDirect(&alloc_info, nullptr, &state.shadow_memory, &state.mem_data);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Failed to allocate shadow memory for image %" PRIu64 " (size %" PRIu64
                             ") with %s; its contents will not be restored across loop repetitions.",
                             image_id,
                             mem_reqs.size,
                             util::ToString(result).c_str());
        state.shadow_memory = VK_NULL_HANDLE;
        return false;
    }

    VkMemoryPropertyFlags bind_properties = 0;
    result                                = allocator_->BindImageMemoryDirect(
        state.shadow_image, state.shadow_memory, 0, state.alloc_data, state.mem_data, &bind_properties);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_WARNING("Failed to bind shadow memory for image %" PRIu64
                             " with %s; its contents will not be restored across loop repetitions.",
                             image_id,
                             util::ToString(result).c_str());
        return false;
    }

    const VkImageAspectFlags aspects = state.initial_layouts.GetAspects();
    state.shadow_range = { ToBarrierAspects(aspects, aspects), 0, image_info->level_count, 0, image_info->layer_count };

    return true;
}

void VulkanReplayFrameLoopConsumer::ImageTracking::DestroyShadowImage(ImageState& state)
{
    if (allocator_ != nullptr)
    {
        if (state.shadow_image != VK_NULL_HANDLE)
        {
            allocator_->DestroyImageDirect(state.shadow_image, nullptr, state.alloc_data);
        }
        if (state.shadow_memory != VK_NULL_HANDLE)
        {
            allocator_->FreeMemoryDirect(state.shadow_memory, nullptr, state.mem_data);
        }
    }

    state.shadow_image  = VK_NULL_HANDLE;
    state.shadow_memory = VK_NULL_HANDLE;
    state.copyable_ranges.clear();
    state.excluded_ranges.clear();
    state.copy_regions.clear();
}

void VulkanReplayFrameLoopConsumer::ImageTracking::RecordInitialState(
    const std::vector<format::HandleId>& image_ids, const std::vector<format::HandleId>& restorable_image_ids)
{
    // Record layouts
    for (format::HandleId image_id : image_ids)
    {
        const VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        if (image_info == nullptr)
        {
            continue;
        }

        image_states_[image_id].initial_layouts = image_info->subresource_layouts;
    }

    if (allocator_ == nullptr || restorable_image_ids.empty())
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

    std::vector<format::HandleId> recorded_ids;

    for (format::HandleId image_id : restorable_image_ids)
    {
        const VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        if (image_info == nullptr || image_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        ImageState& state = image_states_[image_id];

        BuildCopyableSubresourceRanges(image_info, state.initial_layouts, state.copyable_ranges, state.excluded_ranges);

        if (state.copyable_ranges.empty())
        {
            // Every subresource started out undefined and have nothing to be restored to.
            GFXRECON_LOG_DEBUG("RecordInitialState: Skipping image %" PRIu64
                               " with no defined subresource layouts; its contents will not be restored across "
                               "loop repetitions.",
                               image_id);
            state.excluded_ranges.clear();
            continue;
        }

        BuildImageCopyRegions(image_info, state.copyable_ranges, state.copy_regions);

        if (!CreateShadowImage(image_id, image_info, state))
        {
            DestroyShadowImage(state);
            continue;
        }

        recorded_ids.push_back(image_id);
    }

    if (recorded_ids.empty())
    {
        return;
    }

    // Puts every copyable subresource of each source image into VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    std::vector<VkImageMemoryBarrier> pre_barriers;

    for (format::HandleId image_id : recorded_ids)
    {
        const VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        const ImageState&      state      = image_states_.at(image_id);

        AppendTransferLayoutBarriers(
            image_info, state.excluded_ranges, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, pre_barriers);
    }

    // Transitions those subresources back out of VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    std::vector<VkImageMemoryBarrier> post_barriers = pre_barriers;

    ReverseLayoutBarriers(post_barriers);

    // Transition shadows
    for (format::HandleId image_id : recorded_ids)
    {
        const ImageState& state = image_states_.at(image_id);

        pre_barriers.push_back(MakeLayoutRestoreBarrier(
            state.shadow_image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, state.shadow_range));
        post_barriers.push_back(MakeLayoutRestoreBarrier(state.shadow_image,
                                                         VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                                         VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                         state.shadow_range));
    }

    // Transition images to VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL and shadows to VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL.
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, pre_barriers);

    // Copy the contents of each source image into its shadow.
    for (format::HandleId image_id : recorded_ids)
    {
        const VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        const ImageState&      state      = image_states_.at(image_id);

        device_table_.CmdCopyImage(temp_cmd_buff.command_buffer,
                                   image_info->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   state.shadow_image,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   static_cast<uint32_t>(state.copy_regions.size()),
                                   state.copy_regions.data());
    }

    // Transition images back to their initial layouts and shadows to VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, post_barriers);

    CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "TemporaryCommandBuffer::SubmitAndDestroy");
}

void VulkanReplayFrameLoopConsumer::ImageTracking::Restore(format::HandleId queue)
{
    if (image_states_.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    VulkanQueueInfo*  queue_info  = object_table_.GetVkQueueInfo(queue);
    GFXRECON_ASSERT(device_info != nullptr && queue_info != nullptr);

    std::vector<format::HandleId> copy_ids;
    // Puts every copyable subresource of each source image into VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL.
    std::vector<VkImageMemoryBarrier> pre_barriers;
    // Transitions subresources to their initial recorded layouts.
    std::vector<VkImageMemoryBarrier> post_barriers;

    for (auto& [image_id, state] : image_states_)
    {
        VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        if (image_info == nullptr || image_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        const size_t first_post_barrier = post_barriers.size();

        if (state.HasShadow())
        {
            AppendTransferLayoutBarriers(
                image_info, state.excluded_ranges, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, pre_barriers);

            image_info->subresource_layouts = state.initial_layouts;
            AppendTransferLayoutBarriers(
                image_info, state.excluded_ranges, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, post_barriers);
            ReverseLayoutBarriers(post_barriers, first_post_barrier);

            copy_ids.push_back(image_id);
        }
        else // Image contents could not be restored but still restore the layouts to their initial state.
        {
            AppendImageLayoutBarriers(image_info, state.initial_layouts, post_barriers);
            if (post_barriers.size() == first_post_barrier)
            {
                continue;
            }

            image_info->subresource_layouts = state.initial_layouts;
        }

        image_info->intermediate_layout = post_barriers.back().newLayout;
    }

    if (copy_ids.empty() && post_barriers.empty())
    {
        return;
    }

    TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
    if (temp_cmd_buff.CreateAndBegin(queue_info->family_index, queue_info->handle) != VK_SUCCESS)
    {
        return;
    }

    // Transition images to VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL and shadows to
    // VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, pre_barriers);

    // Copy the contents of each shadow into its source image.
    for (format::HandleId image_id : copy_ids)
    {
        const VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        const ImageState&      state      = image_states_.at(image_id);

        device_table_.CmdCopyImage(temp_cmd_buff.command_buffer,
                                   state.shadow_image,
                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                   image_info->handle,
                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                   static_cast<uint32_t>(state.copy_regions.size()),
                                   state.copy_regions.data());
    }

    // Transition images to their initial layouts and shadows to VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, post_barriers);

    CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "TemporaryCommandBuffer::SubmitAndDestroy");
}

void VulkanReplayFrameLoopConsumer::ImageTracking::DestroyShadowImages()
{
    for (auto& [image_id, state] : image_states_)
    {
        DestroyShadowImage(state);
    }
    image_states_.clear();
}

void VulkanReplayFrameLoopConsumer::FixupDeviceObjects(format::HandleId device, format::HandleId queue)
{
    if (!frame_loop_info_.IsLooping() || frame_loop_info_.IsFinalIteration())
    {
        return;
    }
    FixupDeviceEvents(device);
    FixupDeviceImages(device, queue);
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
