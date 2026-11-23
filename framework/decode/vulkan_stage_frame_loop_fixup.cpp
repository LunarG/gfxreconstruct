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

#include "decode/vulkan_stage_frame_loop_fixup.h"

#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_image_layout_map_util.h"
#include "graphics/vulkan_resources_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"
#include "util/alignment_utils.h"
#include "util/callbacks.h"
#include "util/logging.h"

#include <algorithm>
#include <cinttypes>
#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

bool IsFrameEndBoundary(const PNextNode* pnext)
{
    const Decoded_VkFrameBoundaryEXT* frame_boundary = GetPNextMetaStruct<Decoded_VkFrameBoundaryEXT>(pnext);
    return (frame_boundary != nullptr) && (frame_boundary->decoded_value != nullptr) &&
           ((frame_boundary->decoded_value->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT) != 0);
}

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

bool VulkanStageFrameLoopFixup::SemaphoreTracking::IsBinary(format::HandleId semaphore) const
{
    const VulkanSemaphoreInfo* info = object_table_.GetVkSemaphoreInfo(semaphore);
    return info != nullptr && !info->is_timeline;
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::ClassifySignal(format::HandleId semaphore)
{
    if (!IsBinary(semaphore))
    {
        return;
    }
    // At this point, this semaphore is considered an unconsumed in-loop-signal.
    // If still present at the loop boundary, it gets drained.
    in_loop_signaled_semaphores_.insert(semaphore);
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::ClassifyWait(format::HandleId semaphore)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::QueuePresentKHR& args)
{
    const auto* present_info = args.pPresentInfo.GetMetaStructPointer();
    for (format::HandleId semaphore : present_info->pWaitSemaphores.GetSpan())
    {
        ClassifyWait(semaphore);
    }
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit& args)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit2KHR& args)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::QueueSubmit2& args)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::AcquireNextImageKHR& args)
{
    ClassifySignal(args.semaphore);
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackSemaphores(const args::AcquireNextImage2KHR& args)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::TrackTimelineValue(format::HandleId semaphore)
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

bool VulkanStageFrameLoopFixup::SemaphoreTracking::IsFixable(const VulkanSemaphoreInfo* semaphore_info) const
{
    return (semaphore_info != nullptr && semaphore_info->handle != VK_NULL_HANDLE && !semaphore_info->is_external &&
            !semaphore_info->shadow_signaled && semaphore_info->forward_progress);
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::FixupSemaphores(format::HandleId queue)
{
    // Device is expected to be idle at this point.
    FixupBinarySemaphores(queue);
    FixupTimelineSemaphores(queue);
}

void VulkanStageFrameLoopFixup::SemaphoreTracking::FixupBinarySemaphores(format::HandleId queue)
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

void VulkanStageFrameLoopFixup::SemaphoreTracking::FixupTimelineSemaphores(format::HandleId queue)
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

void VulkanStageFrameLoopFixup::ResetBufferTracking()
{
    // Destroying the shadow resources of the loop is not a call of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    for (auto& [device_id, buffer_tracking] : per_device_buffer_tracking_)
    {
        buffer_tracking.DestroyShadowBuffers();
    }
    per_device_buffer_tracking_.clear();
}

void VulkanStageFrameLoopFixup::ResetBufferTracking(format::HandleId device)
{
    // Destroying the shadow resources of the loop is not a call of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    auto it = per_device_buffer_tracking_.find(device);
    if (it != per_device_buffer_tracking_.end())
    {
        it->second.DestroyShadowBuffers();
        per_device_buffer_tracking_.erase(it);
    }
}

static bool CanRestoreImage(const VkImageCreateInfo* create_info)
{
    if (const auto* usage_flags2 = graphics::vulkan_struct_get_pnext<VkImageUsageFlags2CreateInfoKHR>(create_info))
    {
        if ((usage_flags2->usage & VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR) != 0)
        {
            return false;
        }
    }
    else if ((create_info->usage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) != 0)
    {
        return false;
    }

    if (const auto* stencil_usage2 = graphics::vulkan_struct_get_pnext<VkImageStencilUsage2CreateInfoKHR>(create_info))
    {
        if ((stencil_usage2->stencilUsage & VK_IMAGE_USAGE_2_TRANSIENT_ATTACHMENT_BIT_KHR) != 0)
        {
            return false;
        }
    }
    else if (const auto* stencil_usage = graphics::vulkan_struct_get_pnext<VkImageStencilUsageCreateInfo>(create_info))
    {
        if ((stencil_usage->stencilUsage & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT) != 0)
        {
            return false;
        }
    }

    const auto* external_format = graphics::vulkan_struct_get_pnext<VkExternalFormatANDROID>(create_info);
    if ((external_format != nullptr) && (external_format->externalFormat != 0))
    {
        return false;
    }

    const auto* external_memory = graphics::vulkan_struct_get_pnext<VkExternalMemoryImageCreateInfo>(create_info);
    if ((external_memory != nullptr) &&
        ((external_memory->handleTypes & VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID) != 0))
    {
        return false;
    }

    return true;
}

VulkanStageFrameLoopFixup::SemaphoreTracking& VulkanStageFrameLoopFixup::GetSemaphoreTracking(format::HandleId device)
{
    auto it = per_device_semaphore_tracking_.find(device);
    if (it == per_device_semaphore_tracking_.end())
    {
        auto&             object_table  = object_info_table_;
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

void VulkanStageFrameLoopFixup::TrackFenceStates()
{
    object_info_table_.VisitVkFenceInfo([this](const VulkanFenceInfo* fence_info) {
        GFXRECON_LOG_DEBUG("Tracking fence state for fence %" PRIu64, fence_info->capture_id);
        format::HandleId device_id = fence_info->parent_id;
        this->TrackFenceState(device_id, fence_info->capture_id);
    });
}

void VulkanStageFrameLoopFixup::TrackEventStates()
{
    object_info_table_.VisitVkEventInfo([this](const VulkanEventInfo* event_info) {
        GFXRECON_LOG_DEBUG("Tracking event state for event %" PRIu64, event_info->capture_id);
        format::HandleId device_id = event_info->parent_id;
        this->TrackEventState(device_id, event_info->capture_id);
    });
}

void VulkanStageFrameLoopFixup::TrackEventState(format::HandleId device, format::HandleId event)
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
        VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        VulkanEventInfo* event_info = object_info_table_.GetVkEventInfo(event);
        GFXRECON_ASSERT(event_info != nullptr);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
        GFXRECON_ASSERT(device_table != nullptr);
        VkResult res = device_table->GetEventStatus(device_info->handle, event_info->handle);
        GFXRECON_LOG_DEBUG("Event %" PRIu64 " set == %s", event, res == VK_EVENT_SET ? "true" : "false");
        t.initial_event_states_[event] = res == VK_EVENT_SET;
    }
}

void VulkanStageFrameLoopFixup::TrackSemaphoreStates()
{
    object_info_table_.VisitVkSemaphoreInfo([this](const VulkanSemaphoreInfo* semaphore_info) {
        if (semaphore_info->is_timeline && !semaphore_info->is_external)
        {
            GFXRECON_LOG_DEBUG("Tracking semaphore state for semaphore %" PRIu64, semaphore_info->capture_id);
            format::HandleId device_id = semaphore_info->parent_id;
            this->GetSemaphoreTracking(device_id).TrackTimelineValue(semaphore_info->capture_id);
        }
    });
}

VulkanStageFrameLoopFixup::BufferTracking& VulkanStageFrameLoopFixup::GetBufferTracking(format::HandleId device)
{
    auto it = per_device_buffer_tracking_.find(device);
    if (it == per_device_buffer_tracking_.end())
    {
        auto&             object_table = object_info_table_;
        VulkanDeviceInfo* device_info  = object_table.GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        const auto& device_table = *GetDeviceTable(device_info->handle);

        const VkPhysicalDeviceMemoryProperties* memory_properties = GetMemoryProperties(device_info);

        auto result = per_device_buffer_tracking_.emplace(
            device, BufferTracking(device, device_table, object_table, device_info->allocator, memory_properties));
        it = result.first;
        GFXRECON_ASSERT(result.second);
    }
    return it->second;
}

void VulkanStageFrameLoopFixup::RecordBufferStates()
{
    CommonObjectInfoTable& table = object_info_table_;

    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_buffers;
    table.VisitVkBufferInfo([&table, &device_buffers](const VulkanBufferInfo* buffer_info) {
        if (buffer_info == nullptr || buffer_info->handle == VK_NULL_HANDLE || buffer_info->size == 0)
        {
            return;
        }

        // A buffer should never outlive the device that created it in the object info table.
        GFXRECON_ASSERT(table.GetVkDeviceInfo(buffer_info->parent_id) != nullptr);

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

void VulkanStageFrameLoopFixup::FixupDeviceBuffers(format::HandleId device)
{
    auto it = per_device_buffer_tracking_.find(device);
    if (it == per_device_buffer_tracking_.end())
    {
        return;
    }

    it->second.Restore();
}

VkDeviceSize
VulkanStageFrameLoopFixup::BufferTracking::MaxBlockSize(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                                        uint32_t                                memory_type_index)
{
    GFXRECON_ASSERT(memory_type_index < memory_properties.memoryTypeCount);

    // An allocation can never be larger than the heap that it comes from.
    const uint32_t heap_index = memory_properties.memoryTypes[memory_type_index].heapIndex;

    // `kMaxMemoryBlockSize` is the 1 GiB that we know no allocation should exceed. However, the memory type's heap
    // might be greater or lower than this, such as resizable bar being in chunks of 256 MiB.
    return std::min(kMaxMemoryBlockSize, memory_properties.memoryHeaps[heap_index].size);
}

bool VulkanStageFrameLoopFixup::BufferTracking::MemoryBlock::Allocate(uint32_t     memory_type_index,
                                                                      VkDeviceSize allocation_size)
{
    GFXRECON_ASSERT(allocator != nullptr);
    GFXRECON_ASSERT(memory == VK_NULL_HANDLE);

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.allocationSize       = allocation_size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    if (allocator->AllocateMemoryDirect(&alloc_info, nullptr, &memory, &mem_data) != VK_SUCCESS)
    {
        return false;
    }

    size = allocation_size;

    return true;
}

VkResult VulkanStageFrameLoopFixup::BufferTracking::MemoryBlock::Bind(const TemporaryBuffer& shadow)
{
    GFXRECON_ASSERT(allocator != nullptr);

    const VkMemoryRequirements& requirements = shadow.requirements;

    const VkDeviceSize offset = util::aligned_value(next_offset, requirements.alignment);
    GFXRECON_ASSERT((offset + requirements.size) <= size);

    VkMemoryPropertyFlags bind_properties = 0;

    VkResult result = allocator->BindBufferMemoryDirect(
        shadow.handle, memory, offset, shadow.resource_data, mem_data, &bind_properties);
    if (result == VK_SUCCESS)
    {
        next_offset = offset + requirements.size;
    }

    return result;
}

void VulkanStageFrameLoopFixup::BufferTracking::PendingShadowBuffer::CopyBuffer(
    const graphics::VulkanDeviceTable& device_table,
    CommonObjectInfoTable&             object_table,
    VkCommandBuffer                    command_buffer) const
{
    const VulkanBufferInfo* buffer_info = object_table.GetVkBufferInfo(buffer_id);
    GFXRECON_ASSERT(buffer_info != nullptr);

    const VkBufferCopy region = { 0, 0, shadow.size };
    device_table.CmdCopyBuffer(command_buffer, buffer_info->handle, shadow.handle, 1, &region);
}

size_t VulkanStageFrameLoopFixup::BufferTracking::AddMemoryBlock(uint32_t     memory_type_index,
                                                                 VkDeviceSize preferred_size,
                                                                 VkDeviceSize minimum_size)
{
    const VkDeviceSize max_size = MaxBlockSize(*memory_properties_, memory_type_index);
    GFXRECON_ASSERT(minimum_size <= max_size);

    const VkDeviceSize desired_size    = std::max(preferred_size, minimum_size);
    const VkDeviceSize allocation_size = std::min(desired_size, max_size);

    MemoryBlock block(*allocator_);
    if (!block.Allocate(memory_type_index, allocation_size))
    {
        return kInvalidBlockIndex;
    }

    memory_blocks_.push_back(std::move(block));

    return memory_blocks_.size() - 1;
}

void VulkanStageFrameLoopFixup::BufferTracking::RecordInitialState(const std::vector<format::HandleId>& buffer_ids)
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

    // Create a shadow buffer for every buffer to copy and estimate how much memory they need.
    std::vector<PendingShadowBuffer> pending_shadows;
    uint32_t                         memory_type_index = std::numeric_limits<uint32_t>::max();
    VkDeviceSize                     unbound_size      = 0;

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

        TemporaryBuffer shadow(
            device_info->handle, allocator_.get(), device_table_, buffer_info->size, kShadowBufferUsage);
        if (shadow.handle == VK_NULL_HANDLE)
        {
            GFXRECON_LOG_WARNING("Failed to create shadow buffer for buffer %" PRIu64 " (size %" PRIu64
                                 "); its contents will not be restored across loop repetitions.",
                                 buffer_id,
                                 buffer_info->size);
            continue;
        }

        PendingShadowBuffer pending(buffer_id, std::move(shadow));

        const VkMemoryRequirements requirements = pending.shadow.requirements;

        // The shadow buffers are all created with the same flags and usage, and should use the same memory type index.
        if (memory_type_index == std::numeric_limits<uint32_t>::max())
        {
            // Only vkCmdCopyBuffer ever touches a shadow buffer, so we prefer keeping the shadow buffer device local.
            // If the application buffer was also device local, buffer data won't need to be transferred through PCIe.
            // Even if the application buffer was host visible, having a non device local shadow buffer would still
            // need to transfer over PCIe and execute it on the GPU for copies.
            memory_type_index = graphics::GetMemoryTypeIndex(
                *memory_properties_, requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
            if (memory_type_index == std::numeric_limits<uint32_t>::max())
            {
                memory_type_index = graphics::GetMemoryTypeIndex(*memory_properties_, requirements.memoryTypeBits, 0);
            }
            if (memory_type_index == std::numeric_limits<uint32_t>::max())
            {
                GFXRECON_LOG_WARNING("No suitable memory type for shadow buffer for buffer %" PRIu64
                                     "; its contents will not be restored across loop repetitions.",
                                     buffer_id);
                continue;
            }
        }
        GFXRECON_ASSERT((requirements.memoryTypeBits & (1u << memory_type_index)) != 0);

        if (requirements.size > MaxBlockSize(*memory_properties_, memory_type_index))
        {
            GFXRECON_LOG_WARNING("Shadow buffer for buffer %" PRIu64 " requires %" PRIu64
                                 " bytes, more than the largest block that can be allocated from memory type %u; its "
                                 "contents will not be restored across loop repetitions.",
                                 buffer_id,
                                 requirements.size,
                                 memory_type_index);
            continue;
        }

        // The padding that aligning each suballocation adds is part of what a block has to hold.
        unbound_size += util::aligned_value(requirements.size, requirements.alignment);
        pending_shadows.push_back(std::move(pending));
    }

    // Suballocate the shadow buffers.
    uint32_t copy_count  = 0;
    size_t   block_index = kInvalidBlockIndex;

    for (size_t i = 0; i < pending_shadows.size(); ++i)
    {
        PendingShadowBuffer&       pending      = pending_shadows[i];
        const VkMemoryRequirements requirements = pending.shadow.requirements;

        if (block_index != kInvalidBlockIndex)
        {
            const MemoryBlock& block  = memory_blocks_[block_index];
            const VkDeviceSize offset = util::aligned_value(block.next_offset, requirements.alignment);

            if ((offset + requirements.size) > block.size)
            {
                // The block is full, so the shadow buffers that are left need a new one.
                block_index = kInvalidBlockIndex;
            }
        }

        if (block_index == kInvalidBlockIndex)
        {
            block_index = AddMemoryBlock(memory_type_index, unbound_size, requirements.size);

            if (block_index == kInvalidBlockIndex)
            {
                GFXRECON_LOG_WARNING("Failed to allocate %" PRIu64 " bytes of shadow memory from memory type %u; the "
                                     "contents of %zu buffers will not be restored across loop repetitions.",
                                     unbound_size,
                                     memory_type_index,
                                     pending_shadows.size() - i);
                break;
            }
        }

        VkResult result = memory_blocks_[block_index].Bind(pending.shadow);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Failed to bind shadow memory for buffer %" PRIu64
                                 " with %s; its contents will not be restored across loop repetitions.",
                                 pending.buffer_id,
                                 util::ToString(result).c_str());
            continue;
        }

        unbound_size -= std::min(unbound_size, util::aligned_value(requirements.size, requirements.alignment));

        pending.CopyBuffer(device_table_, object_table_, temp_cmd_buff.command_buffer);

        shadow_buffers_.emplace(pending.buffer_id, std::move(pending.shadow));
        ++copy_count;
    }

    if (copy_count > 0)
    {
        CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "vkQueueSubmit");
    }

    GFXRECON_LOG_DEBUG("Recorded the contents of %u buffers into %zu shadow memory blocks for device %" PRIu64,
                       copy_count,
                       memory_blocks_.size(),
                       device_id_);
}

void VulkanStageFrameLoopFixup::BufferTracking::Restore()
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
        device_table_.CmdCopyBuffer(temp_cmd_buff.command_buffer, shadow.handle, buffer_info->handle, 1, &region);
        ++restore_count;
    }

    // No need to submit anything if there are no buffers to restore.
    if (restore_count > 0)
    {
        CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "vkQueueSubmit");
    }
}

void VulkanStageFrameLoopFixup::BufferTracking::DestroyShadowBuffers()
{
    // The shadow buffers have to be destroyed before the memory that they are bound to is freed.
    shadow_buffers_.clear();
    memory_blocks_.clear();
}

void VulkanStageFrameLoopFixup::TrackFenceState(format::HandleId device, format::HandleId fence)
{
    // If fence hasn't been seen yet, check and store the state it is in.
    FenceTracking& t = per_device_fence_tracking_[device];
    if (!t.initial_fence_states_.contains(fence))
    {
        VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        VulkanFenceInfo* fence_info = object_info_table_.GetVkFenceInfo(fence);
        GFXRECON_ASSERT(fence_info != nullptr);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device_info->handle);
        GFXRECON_ASSERT(device_table != nullptr);
        VkResult res = device_table->GetFenceStatus(device_info->handle, fence_info->handle);
        GFXRECON_LOG_DEBUG("Fence %" PRIu64 " signaled == %s", fence, res == VK_SUCCESS ? "true" : "false");
        t.initial_fence_states_[fence] = res == VK_SUCCESS;
    }
}

void VulkanStageFrameLoopFixup::FixupDeviceFences(format::HandleId device, format::HandleId queue)
{
    // Get fence tracking info associated with this VkDevice
    if (!per_device_fence_tracking_.contains(device))
    {
        // No need to fixup fences if there weren't any
        return;
    }
    FenceTracking& t = per_device_fence_tracking_[device];

    VulkanObjectInfoTable&             table        = object_info_table_;
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
        GFXRECON_LOG_DEBUG("Synthetically resetting all %zu observed fences...", all_fences.size());
        result = device_table->ResetFences(vk_device, all_fences.size(), all_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    // Synthetically signal the ones that were originally signaled
    GFXRECON_LOG_DEBUG("Synthetically signaling %zu fences...", fences_to_signal.size());
    VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
    for (VkFence fence : fences_to_signal)
    {
        result = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
        CHECK_VK_RESULT(result, "vkQueueSubmit");
    }
}

void VulkanStageFrameLoopFixup::FixupDeviceEvents(format::HandleId device)
{
    // Get event tracking info associated with this VkDevice
    if (!per_device_event_tracking_.contains(device))
    {
        // No need to fixup event if there weren't any.
        return;
    }

    EventTracking& t = per_device_event_tracking_[device];

    VulkanObjectInfoTable&             table        = object_info_table_;
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

VulkanStageFrameLoopFixup::ImageTracking& VulkanStageFrameLoopFixup::GetImageTracking(format::HandleId device)
{
    auto it = per_device_image_tracking_.find(device);
    if (it == per_device_image_tracking_.end())
    {
        auto&             object_table = object_info_table_;
        VulkanDeviceInfo* device_info  = object_table.GetVkDeviceInfo(device);
        GFXRECON_ASSERT(device_info != nullptr);
        const auto& device_table = *GetDeviceTable(device_info->handle);

        const VkPhysicalDeviceMemoryProperties* memory_properties = GetMemoryProperties(device_info);

        auto result = per_device_image_tracking_.emplace(
            device, ImageTracking(device, device_table, object_table, device_info->allocator, memory_properties));
        it = result.first;
        GFXRECON_ASSERT(result.second);
    }
    return it->second;
}

bool VulkanStageFrameLoopFixup::CanSnapshotImageContents(const VulkanImageInfo* image_info) const
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

void VulkanStageFrameLoopFixup::TrackImageStates()
{
    // Images that exists now and therefore needs its layouts recorded.
    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_images;
    // Images that can have content restored.
    std::unordered_map<format::HandleId, std::vector<format::HandleId>> device_restorable_images;

    object_info_table_.VisitVkImageInfo(
        [this, &device_images, &device_restorable_images](const VulkanImageInfo* image_info) {
            if (image_info->handle == VK_NULL_HANDLE)
            {
                return;
            }

            // Table still holds stale entries after a `vkDestroySwapchainKHR`.
            if (image_info->swapchain_id != format::kNullHandleId)
            {
                return;
            }

            // An image should never outlive the device that created it in the object info table.
            GFXRECON_ASSERT(object_info_table_.GetVkDeviceInfo(image_info->parent_id) != nullptr);

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

void VulkanStageFrameLoopFixup::FixupDeviceImages(format::HandleId device, format::HandleId queue)
{
    auto it = per_device_image_tracking_.find(device);
    if (it == per_device_image_tracking_.end())
    {
        return;
    }

    it->second.Restore(queue);
}

void VulkanStageFrameLoopFixup::ResetImageTracking()
{
    // Destroying the shadow resources of the loop is not a call of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    for (auto& [device_id, image_tracking] : per_device_image_tracking_)
    {
        image_tracking.DestroyShadowImages();
    }
    per_device_image_tracking_.clear();
}

void VulkanStageFrameLoopFixup::ResetImageTracking(format::HandleId device)
{
    // Destroying the shadow resources of the loop is not a call of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    auto it = per_device_image_tracking_.find(device);
    if (it != per_device_image_tracking_.end())
    {
        it->second.DestroyShadowImages();
        per_device_image_tracking_.erase(it);
    }
}

// Creates the device-local image that an image's contents are snapshotted into, and binds memory to it.
bool VulkanStageFrameLoopFixup::ImageTracking::CreateShadowImage(format::HandleId       image_id,
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
    create_info.samples           = image_info->sample_count;
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

    const VkImageAspectFlags aspects         = state.initial_layouts.GetAspects();
    const VkImageAspectFlags barrier_aspects = graphics::ToBarrierAspects(aspects, aspects);
    state.shadow_range = { barrier_aspects, 0, image_info->level_count, 0, image_info->layer_count };

    return true;
}

void VulkanStageFrameLoopFixup::ImageTracking::DestroyShadowImage(ImageState& state)
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

void VulkanStageFrameLoopFixup::ImageTracking::RecordInitialState(
    const std::vector<format::HandleId>& image_ids, const std::vector<format::HandleId>& restorable_image_ids)
{
    restore_commands_ = {};

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

        graphics::BuildCopyableSubresourceRanges(image_info->format,
                                                 image_info->level_count,
                                                 image_info->layer_count,
                                                 state.initial_layouts,
                                                 state.copyable_ranges,
                                                 state.excluded_ranges);

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

        graphics::BuildImageCopyRegions(
            image_info->format, image_info->extent, state.copyable_ranges, state.copy_regions);

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

        graphics::AppendTransferLayoutBarriers(image_info->handle,
                                               image_info->subresource_layouts,
                                               state.excluded_ranges,
                                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                               pre_barriers);
    }

    // Transitions those subresources back out of VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    std::vector<VkImageMemoryBarrier> post_barriers = pre_barriers;

    graphics::ReverseLayoutBarriers(post_barriers);

    // Transition shadows
    for (format::HandleId image_id : recorded_ids)
    {
        const ImageState& state = image_states_.at(image_id);

        pre_barriers.push_back(graphics::MakeLayoutRestoreBarrier(
            state.shadow_image, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, state.shadow_range));
        post_barriers.push_back(graphics::MakeLayoutRestoreBarrier(state.shadow_image,
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

void VulkanStageFrameLoopFixup::ImageTracking::BuildRestoreCommands()
{
    RestoreCommands& commands = restore_commands_;
    commands.built            = true;

    for (auto& [image_id, state] : image_states_)
    {
        VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
        if (image_info == nullptr || image_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        const size_t first_post_barrier = commands.post_barriers.size();

        if (state.HasShadow())
        {
            graphics::AppendTransferLayoutBarriers(image_info->handle,
                                                   image_info->subresource_layouts,
                                                   state.excluded_ranges,
                                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                                   commands.pre_barriers);

            image_info->subresource_layouts = state.initial_layouts;
            graphics::AppendTransferLayoutBarriers(image_info->handle,
                                                   image_info->subresource_layouts,
                                                   state.excluded_ranges,
                                                   VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                                   commands.post_barriers);
            graphics::ReverseLayoutBarriers(commands.post_barriers, first_post_barrier);

            commands.copy_ids.push_back(image_id);
        }
        else // Image contents could not be restored but still restore the layouts to their initial state.
        {
            graphics::AppendImageLayoutBarriers(
                image_info->handle, image_info->subresource_layouts, state.initial_layouts, commands.post_barriers);
            if (commands.post_barriers.size() == first_post_barrier)
            {
                continue;
            }

            image_info->subresource_layouts = state.initial_layouts;
        }

        const VkImageLayout intermediate_layout = (commands.post_barriers.size() > first_post_barrier)
                                                      ? commands.post_barriers.back().newLayout
                                                      : VK_IMAGE_LAYOUT_MAX_ENUM;
        if (intermediate_layout != VK_IMAGE_LAYOUT_MAX_ENUM)
        {
            image_info->intermediate_layout = intermediate_layout;
        }

        commands.layout_updates.emplace_back(image_id, intermediate_layout);
    }
}

void VulkanStageFrameLoopFixup::ImageTracking::Restore(format::HandleId queue)
{
    if (image_states_.empty())
    {
        return;
    }

    VulkanDeviceInfo* device_info = object_table_.GetVkDeviceInfo(device_id_);
    VulkanQueueInfo*  queue_info  = object_table_.GetVkQueueInfo(queue);
    GFXRECON_ASSERT(device_info != nullptr && queue_info != nullptr);

    const bool built_this_restore = !restore_commands_.built;
    if (built_this_restore)
    {
        BuildRestoreCommands();
    }
    const RestoreCommands& commands = restore_commands_;

    if (commands.copy_ids.empty() && commands.post_barriers.empty())
    {
        return;
    }

    if (!built_this_restore)
    {
        for (const auto& [image_id, intermediate_layout] : commands.layout_updates)
        {
            VulkanImageInfo* image_info = object_table_.GetVkImageInfo(image_id);
            GFXRECON_ASSERT(image_info != nullptr);

            image_info->subresource_layouts = image_states_.at(image_id).initial_layouts;
            if (intermediate_layout != VK_IMAGE_LAYOUT_MAX_ENUM)
            {
                image_info->intermediate_layout = intermediate_layout;
            }
        }
    }

    TemporaryCommandBuffer temp_cmd_buff(*device_info, device_table_);
    if (temp_cmd_buff.CreateAndBegin(queue_info->family_index, queue_info->handle) != VK_SUCCESS)
    {
        return;
    }

    // Transition images to VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL and shadows to
    // VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL.
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, commands.pre_barriers);

    // Copy the contents of each shadow into its source image.
    for (format::HandleId image_id : commands.copy_ids)
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
    CmdImageLayoutBarriers(device_table_, temp_cmd_buff.command_buffer, commands.post_barriers);

    CHECK_VK_RESULT(temp_cmd_buff.SubmitAndDestroy(), "TemporaryCommandBuffer::SubmitAndDestroy");
}

void VulkanStageFrameLoopFixup::ImageTracking::DestroyShadowImages()
{
    for (auto& [image_id, state] : image_states_)
    {
        DestroyShadowImage(state);
    }
    image_states_.clear();
    restore_commands_ = {};
}

void VulkanStageFrameLoopFixup::FixupDeviceObjects(format::HandleId device, format::HandleId queue)
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

// Stage

VulkanStageFrameLoopFixup::VulkanStageFrameLoopFixup(CommonObjectInfoTable&    object_info_table,
                                                     graphics::FrameLoopInfo&  frame_loop_info,
                                                     VulkanDispatchTableLookup dispatch_tables) :
    object_info_table_(object_info_table),
    frame_loop_info_(frame_loop_info), dispatch_tables_(std::move(dispatch_tables))
{
    GFXRECON_ASSERT(dispatch_tables_.get_instance_table && dispatch_tables_.get_device_table);
}

VulkanStageFrameLoopFixup::~VulkanStageFrameLoopFixup()
{
    ResetTracking();
}

const graphics::VulkanInstanceTable* VulkanStageFrameLoopFixup::GetInstanceTable(const void* handle) const
{
    return dispatch_tables_.get_instance_table(handle);
}

const graphics::VulkanDeviceTable* VulkanStageFrameLoopFixup::GetDeviceTable(const void* handle) const
{
    return dispatch_tables_.get_device_table(handle);
}

const VkPhysicalDeviceMemoryProperties*
VulkanStageFrameLoopFixup::GetMemoryProperties(const VulkanDeviceInfo* device_info) const
{
    GFXRECON_ASSERT(device_info != nullptr);

    const VulkanPhysicalDeviceInfo* phys_info = object_info_table_.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(phys_info != nullptr);

    if ((phys_info->replay_device_info != nullptr) && phys_info->replay_device_info->memory_properties.has_value())
    {
        return &phys_info->replay_device_info->memory_properties.value();
    }
    return &phys_info->capture_memory_properties;
}

void VulkanStageFrameLoopFixup::RecordLoopStartState()
{
    // The calls that save the state of the loop are not calls of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    // The replay consumer waits for every device it created.
    VulkanConsumerStage::WaitDevicesIdle();

    GFXRECON_LOG_DEBUG("VulkanStageFrameLoopFixup: recording the state at the start of the loop");
    TrackFenceStates();
    TrackEventStates();
    TrackImageStates();
    TrackSemaphoreStates();
    RecordBufferStates();
}

void VulkanStageFrameLoopFixup::ResetTracking()
{
    per_device_fence_tracking_.clear();
    per_device_event_tracking_.clear();
    per_device_semaphore_tracking_.clear();
    ResetBufferTracking();
    ResetImageTracking();
}

void VulkanStageFrameLoopFixup::EndFrame(format::HandleId queue)
{
    const VulkanQueueInfo* queue_info = object_info_table_.GetVkQueueInfo(queue);
    if (queue_info == nullptr)
    {
        return;
    }

    VkDevice device = queue_info->parent;
    GFXRECON_ASSERT(device != VK_NULL_HANDLE);
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);

    // The calls that restore the state of the loop are not calls of the application.
    util::MarkInjectedCommandsHelper injected_commands_scope;

    GFXRECON_LOG_DEBUG("Waiting for device to idle...");
    CHECK_VK_RESULT(device_table->DeviceWaitIdle(device), "vkDeviceWaitIdle");

    FixupDeviceObjects(queue_info->parent_id, queue);
}

// Loop start

void VulkanStageFrameLoopFixup::StartLooping()
{
    VulkanConsumerStage::StartLooping();
    RecordLoopStartState();
}

void VulkanStageFrameLoopFixup::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanConsumerStage::ProcessStateEndMarker(frame_number);

    // The loop started before the trim state finished loading, so the state that it recorded is out of date.
    if (frame_loop_info_.IsLooping())
    {
        ResetTracking();
        RecordLoopStartState();
    }
}

// Devices

void VulkanStageFrameLoopFixup::Process_vkDestroyDevice(const ApiCallInfo& call_info, args::DestroyDevice& args)
{
    // The replay consumer destroys a device that the loop uses only in the final iteration.
    if (!frame_loop_info_.IsLooping() || frame_loop_info_.IsFinalIteration())
    {
        ResetBufferTracking(args.device);
        ResetImageTracking(args.device);
    }

    Forward(call_info, args);
}

// Resources

void VulkanStageFrameLoopFixup::Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args)
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

    Forward(call_info, args);
}

void VulkanStageFrameLoopFixup::Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args)
{
    VkImageCreateInfo*      create_info = args.pCreateInfo.GetPointer();
    const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(args.device);

    if ((create_info != nullptr) && !args.pImage.IsNull() && (device_info != nullptr) && CanRestoreImage(create_info) &&
        graphics::VulkanResourcesUtil::IsFormatSupported(*GetInstanceTable(device_info->parent),
                                                         device_info->parent,
                                                         create_info->format,
                                                         create_info->tiling,
                                                         VK_FORMAT_FEATURE_TRANSFER_SRC_BIT |
                                                             VK_FORMAT_FEATURE_TRANSFER_DST_BIT,
                                                         create_info))
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

    Forward(call_info, args);
}

// Synchronization objects

void VulkanStageFrameLoopFixup::Process_vkCreateFence(const ApiCallInfo& call_info, args::CreateFence& args)
{
    Forward(call_info, args);

    if (frame_loop_info_.IsFirstIteration() && !args.pFence.IsNull() && (args.pCreateInfo.GetPointer() != nullptr))
    {
        // Record the initial state of the new fence
        FenceTracking& t = per_device_fence_tracking_[args.device];
        bool           signaled =
            (args.pCreateInfo.GetPointer()->flags & VK_FENCE_CREATE_SIGNALED_BIT) == VK_FENCE_CREATE_SIGNALED_BIT;
        t.initial_fence_states_[*args.pFence.GetPointer()] = signaled;
    }
}

void VulkanStageFrameLoopFixup::Process_vkDestroyFence(const ApiCallInfo& call_info, args::DestroyFence& args)
{
    Forward(call_info, args);

    // The replay consumer keeps a fence that the loop uses until the final iteration.
    const bool destroyed = (object_info_table_.GetVkFenceInfo(args.fence) == nullptr);
    if (destroyed)
    {
        auto tracking = per_device_fence_tracking_.find(args.device);
        if (tracking != per_device_fence_tracking_.end())
        {
            // Remove fence tracking struct from map if
            // fence was created and destroyed during the loop range.
            tracking->second.initial_fence_states_.erase(args.fence);
        }
    }
}

void VulkanStageFrameLoopFixup::Process_vkCreateEvent(const ApiCallInfo& call_info, args::CreateEvent& args)
{
    Forward(call_info, args);

    const VkEventCreateInfo* create_info = args.pCreateInfo.GetPointer();
    if ((create_info == nullptr) || args.pEvent.IsNull())
    {
        return;
    }

    const format::HandleId event_id = *args.pEvent.GetPointer();
    if (frame_loop_info_.IsLooping())
    {
        loop_created_objects_.insert(event_id);
    }

    // Track host visible events. Device only events cannot be set or reset from the host.
    const bool host_visible = (create_info->flags & VK_EVENT_CREATE_DEVICE_ONLY_BIT) == 0;
    if (!host_visible)
    {
        return;
    }

    host_visible_events_.insert(event_id);

    if (frame_loop_info_.IsFirstIteration())
    {
        const VulkanEventInfo*  event_info  = object_info_table_.GetVkEventInfo(event_id);
        const VulkanDeviceInfo* device_info = object_info_table_.GetVkDeviceInfo(args.device);
        if ((event_info == nullptr) || (device_info == nullptr))
        {
            return;
        }

        // The status query is not a call of the application.
        util::MarkInjectedCommandsHelper injected_commands_scope;

        // Record the initial state of the new event
        const VkResult status =
            GetDeviceTable(device_info->handle)->GetEventStatus(device_info->handle, event_info->handle);
        per_device_event_tracking_[args.device].initial_event_states_[event_id] = (status == VK_EVENT_SET);
    }
}

void VulkanStageFrameLoopFixup::Process_vkDestroyEvent(const ApiCallInfo& call_info, args::DestroyEvent& args)
{
    if (loop_created_objects_.erase(args.event) > 0)
    {
        auto tracking = per_device_event_tracking_.find(args.device);
        if (tracking != per_device_event_tracking_.end())
        {
            // Remove event tracking struct from map if
            // event was created and destroyed during the loop range.
            tracking->second.initial_event_states_.erase(args.event);
            host_visible_events_.erase(args.event);
        }
    }

    Forward(call_info, args);
}

void VulkanStageFrameLoopFixup::Process_vkCreateSemaphore(const ApiCallInfo& call_info, args::CreateSemaphore& args)
{
    Forward(call_info, args);

    if (args.pSemaphore.IsNull())
    {
        return;
    }

    const format::HandleId semaphore_id = *args.pSemaphore.GetPointer();
    if (frame_loop_info_.IsLooping())
    {
        loop_created_objects_.insert(semaphore_id);
    }

    // A semaphore created inside the loop range persists across iterations.
    const VulkanSemaphoreInfo* semaphore_info = object_info_table_.GetVkSemaphoreInfo(semaphore_id);
    if (frame_loop_info_.IsFirstIteration() && (semaphore_info != nullptr) && semaphore_info->is_timeline)
    {
        auto& semaphore_tracking                                  = GetSemaphoreTracking(args.device);
        semaphore_tracking.initial_timeline_values_[semaphore_id] = semaphore_info->initial_value;
    }
}

void VulkanStageFrameLoopFixup::Process_vkDestroySemaphore(const ApiCallInfo& call_info, args::DestroySemaphore& args)
{
    if (loop_created_objects_.erase(args.semaphore) > 0)
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

    Forward(call_info, args);
}

// Submits and presents

template <typename ArgsT>
void VulkanStageFrameLoopFixup::ProcessQueueSubmit(const ApiCallInfo& call_info, ArgsT& args)
{
    Forward(call_info, args);

    if (!frame_loop_info_.IsLooping())
    {
        return;
    }

    if (frame_loop_info_.IsFirstIteration())
    {
        const VulkanQueueInfo* queue_info = object_info_table_.GetVkQueueInfo(args.queue);
        if (queue_info != nullptr)
        {
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }
    }

    for (const auto& submit : args.pSubmits.GetMetaStructSpan())
    {
        if (IsFrameEndBoundary(submit.pNext))
        {
            EndFrame(args.queue);
        }
    }
}

void VulkanStageFrameLoopFixup::Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args)
{
    ProcessQueueSubmit(call_info, args);
}

void VulkanStageFrameLoopFixup::Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args)
{
    ProcessQueueSubmit(call_info, args);
}

void VulkanStageFrameLoopFixup::Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args)
{
    ProcessQueueSubmit(call_info, args);
}

void VulkanStageFrameLoopFixup::Process_vkQueueBindSparse(const ApiCallInfo& call_info, args::QueueBindSparse& args)
{
    Forward(call_info, args);

    if (frame_loop_info_.IsLooping())
    {
        for (const Decoded_VkBindSparseInfo& bind_info : args.pBindInfo.GetMetaStructSpan())
        {
            if (IsFrameEndBoundary(bind_info.pNext))
            {
                EndFrame(args.queue);
            }
        }
    }
}

void VulkanStageFrameLoopFixup::Process_vkAcquireNextImageKHR(const ApiCallInfo&         call_info,
                                                              args::AcquireNextImageKHR& args)
{
    Forward(call_info, args);

    if (frame_loop_info_.IsFirstIteration())
    {
        GetSemaphoreTracking(args.device).TrackSemaphores(args);
    }
}

void VulkanStageFrameLoopFixup::Process_vkAcquireNextImage2KHR(const ApiCallInfo&          call_info,
                                                               args::AcquireNextImage2KHR& args)
{
    Forward(call_info, args);

    if (frame_loop_info_.IsFirstIteration())
    {
        GetSemaphoreTracking(args.device).TrackSemaphores(args);
    }
}

void VulkanStageFrameLoopFixup::Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args)
{
    Forward(call_info, args);

    if (!frame_loop_info_.IsLooping())
    {
        return;
    }

    if (frame_loop_info_.IsFirstIteration())
    {
        const VulkanQueueInfo* queue_info = object_info_table_.GetVkQueueInfo(args.queue);
        if (queue_info != nullptr)
        {
            GetSemaphoreTracking(queue_info->parent_id).TrackSemaphores(args);
        }
    }

    EndFrame(args.queue);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
