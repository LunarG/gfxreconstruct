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

namespace
{
VkImageAspectFlags GetAspectMask(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            return VK_IMAGE_ASPECT_DEPTH_BIT;
        case VK_FORMAT_S8_UINT:
            return VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

VkAccessFlags GetAccessFlags(VkImageLayout layout)
{
    switch (layout)
    {
        case VK_IMAGE_LAYOUT_UNDEFINED:
            return 0;
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            return VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
            return VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            return VK_ACCESS_SHADER_READ_BIT;
        case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
            return VK_ACCESS_TRANSFER_READ_BIT;
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
            return VK_ACCESS_TRANSFER_WRITE_BIT;
        default:
            return VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    }
}
} // namespace

VulkanReplayFrameLoopConsumer::~VulkanReplayFrameLoopConsumer()
{
    if (restoration_command_pool_ != VK_NULL_HANDLE && restoration_device_ != VK_NULL_HANDLE)
    {
        const graphics::VulkanDeviceTable* dev_table = GetDeviceTable(restoration_device_);
        if (dev_table)
        {
            dev_table->DestroyCommandPool(restoration_device_, restoration_command_pool_, nullptr);
        }
    }
}

void VulkanReplayFrameLoopConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessStateEndMarker(frame_number);
    if (frame_loop_info_.GetLoopFrame() == 1)
    {
        CaptureInitialFenceStates();
        RecordInitialLayouts();
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkCommandPool>*                   pCommandPool)
{
    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    if (pCreateInfo != nullptr && pCreateInfo->GetPointer() != nullptr)
    {
        VkCommandPoolCreateInfo* create_info = pCreateInfo->GetPointer();
        create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    }

    VulkanReplayFrameLoopConsumerBase::Process_vkCreateCommandPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pCommandPool);
}

void VulkanReplayFrameLoopConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                                        call_info,
    VkResult                                                  returnValue,
    format::HandleId                                          device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*      pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*                   pDescriptorPool)
{
    format::HandleId pool_id = *pDescriptorPool->GetPointer();
    GFXRECON_ASSERT(pDescriptorPool != nullptr && pDescriptorPool->GetPointer() != nullptr);

    if (frame_loop_info_.IsRepetition())
    {
        // Skip allocation of descriptor pools with a dangling creation
        if (dangling_create_descriptor_pools_.contains(pool_id))
        {
            return;
        }
    }

    VulkanReplayConsumer::Process_vkCreateDescriptorPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pDescriptorPool);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Gather descriptor pools that are created during the loop range
        // We will delete any pools from this set that are destroyed during the loop range
        dangling_create_descriptor_pools_.insert(pool_id);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                                   call_info,
    format::HandleId                                     device,
    format::HandleId                                     descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Skip destruction of descriptor pools with a dangling destruction
        if (dangling_destroy_descriptor_pools_.contains(descriptorPool))
        {
            return;
        }
    }

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        if (!dangling_create_descriptor_pools_.contains(descriptorPool))
        {
            // If this pool was not created during the loop range, ignore destroying it.
            dangling_destroy_descriptor_pools_.insert(descriptorPool);
            return;
        }
        else
        {
            // Created and destroyed during the loop range, not dangling
            dangling_create_descriptor_pools_.erase(descriptorPool);

            // Check if this was the pool for any heretofore dangling descriptors
            RemovePoolDanglingCreateDescriptors(descriptorPool);
        }
    }
    VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, device, descriptorPool, pAllocator);
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
                                                                  VkResult                   returnValue,
                                                                  format::HandleId           device,
                                                                  format::HandleId           descriptorPool,
                                                                  VkDescriptorPoolResetFlags flags)
{
    if (frame_loop_info_.IsLooping())
    {
        // If any of the sets in this pool are dangling, skip pool reset
        for (format::HandleId set_id : dangling_create_descriptor_sets_)
        {
            VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(set_id);
            if (info != nullptr && info->pool_id == descriptorPool)
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkResetDescriptorPool(call_info, returnValue, device, descriptorPool, flags);
}

void VulkanReplayFrameLoopConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                                         call_info,
    VkResult                                                   returnValue,
    format::HandleId                                           device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*                     pDescriptorSets)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Skip allocation of dangling descriptor sets
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            if (dangling_create_descriptor_sets_.contains(set_handle))
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkAllocateDescriptorSets(
        call_info, returnValue, device, pAllocateInfo, pDescriptorSets);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // During first iteration of looping range, record which descriptor sets are allocated
        // They will be removed from the set if they are freed during the loop range
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
        {
            dangling_create_descriptor_sets_.insert(set_handle);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeDescriptorSets(const ApiCallInfo& call_info,
                                                                 VkResult           returnValue,
                                                                 format::HandleId   device,
                                                                 format::HandleId   descriptorPool,
                                                                 uint32_t           descriptorSetCount,
                                                                 HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets)
{
    if (frame_loop_info_.IsRepetition())
    {
        // If any of the descriptor sets are in the dangling list,
        // then we want to omit their destruction
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
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
        for (format::HandleId set_handle : pDescriptorSets->GetSpan())
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
    RemovePoolDanglingCreateDescriptors(descriptorPool);

    VulkanReplayConsumer::Process_vkFreeDescriptorSets(
        call_info, returnValue, device, descriptorPool, descriptorSetCount, pDescriptorSets);
}

void VulkanReplayFrameLoopConsumer::OnLoopStart()
{
    WaitDevicesIdle();
    CaptureInitialFenceStates();
}

void VulkanReplayFrameLoopConsumer::CaptureInitialFenceStates()
{
    GFXRECON_LOG_DEBUG("VulkanReplayFrameLoopConsumer::CaptureInitialFenceStates: Capturing initial fence states...");
    initial_fence_states_.clear();

    VulkanObjectInfoTable& table = GetObjectInfoTable();
    table.VisitVkFenceInfo([this, &table](const VulkanFenceInfo* fence_info) {
        if (fence_info->handle != VK_NULL_HANDLE)
        {
            auto device_info = table.GetVkDeviceInfo(fence_info->parent_id);
            if (device_info != nullptr && device_info->handle != VK_NULL_HANDLE)
            {
                VkDevice                           device       = device_info->handle;
                const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
                if (device_table != nullptr)
                {
                    VkResult status = device_table->GetFenceStatus(device, fence_info->handle);
                    initial_fence_states_[fence_info->capture_id] = status;
                    GFXRECON_LOG_DEBUG("  Fence %" PRIu64 " (handle %" PRIu64 ") initial state: %s",
                                       fence_info->capture_id,
                                       (uint64_t)fence_info->handle,
                                       status == VK_SUCCESS ? "SIGNALED"
                                                            : (status == VK_NOT_READY ? "UNSIGNALED" : "ERROR"));
                }
            }
        }
    });
}

void VulkanReplayFrameLoopConsumer::ProcessStateEndMarker(uint64_t frame_number)
{
    VulkanReplayConsumer::ProcessStateEndMarker(frame_number);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        GFXRECON_LOG_DEBUG("VulkanReplayFrameLoopConsumer::ProcessStateEndMarker: Setup finished for N = 1.");
        OnLoopStart(); // Trigger unified capture (which waits for idle internally!)
    }
}

void VulkanReplayFrameLoopConsumer::FixupDeviceFences(format::HandleId device, format::HandleId queue)
{
    VulkanObjectInfoTable&             table        = GetObjectInfoTable();
    VkDevice                           vk_device    = table.GetVkDeviceInfo(device)->handle;
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(vk_device);

    std::vector<VkFence> fences_to_reset;  // Fences to reset (signaled -> unsignaled)
    std::vector<VkFence> fences_to_signal; // Fences to signal (unsignaled -> signaled)

    for (auto [fence_id, initial_status] : initial_fence_states_)
    {
        const VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
        if (fence_info == nullptr || fence_info->handle == VK_NULL_HANDLE)
        {
            continue;
        }

        // Only process fences for this device
        if (fence_info->parent_id != device)
        {
            continue;
        }

        VkResult current_status = device_table->GetFenceStatus(vk_device, fence_info->handle);

        if (initial_status == VK_NOT_READY && current_status == VK_SUCCESS)
        {
            GFXRECON_LOG_DEBUG("Fence %" PRIu64 " (handle %" PRIu64
                               ") was initially UNSIGNALED but is now SIGNALED. Will reset it.",
                               fence_id,
                               (uint64_t)fence_info->handle);
            fences_to_reset.push_back(fence_info->handle);
        }
        else if (initial_status == VK_SUCCESS && current_status == VK_NOT_READY)
        {
            GFXRECON_LOG_DEBUG("Fence %" PRIu64 " (handle %" PRIu64
                               ") was initially SIGNALED but is now UNSIGNALED. Will signal it.",
                               fence_id,
                               (uint64_t)fence_info->handle);
            fences_to_signal.push_back(fence_info->handle);
        }
    }

    if (fences_to_reset.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically resetting %zu fences...", fences_to_reset.size());
        VkResult result = device_table->ResetFences(vk_device, fences_to_reset.size(), fences_to_reset.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    if (fences_to_signal.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically signaling %zu fences...", fences_to_signal.size());
        VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
        for (VkFence fence : fences_to_signal)
        {
            VkResult result = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
            CHECK_VK_RESULT(result, "vkQueueSubmit");
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkMapMemory(const ApiCallInfo&               call_info,
                                                        VkResult                         returnValue,
                                                        format::HandleId                 device,
                                                        format::HandleId                 memory,
                                                        VkDeviceSize                     offset,
                                                        VkDeviceSize                     size,
                                                        VkMemoryMapFlags                 flags,
                                                        PointerDecoder<uint64_t, void*>* ppData)
{
    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in mapped_loop_memory
    if (frame_loop_info_.IsLooping())
    {
        if (mapped_loop_memory.contains(memory))
        {
            return; // Already mapped in loop range, skip re-mapping
        }

        // First time mapping in the loop
        mapped_loop_memory.insert(memory);
    }
    VulkanReplayConsumer::Process_vkMapMemory(call_info, returnValue, device, memory, offset, size, flags, ppData);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                              call_info,
    VkResult                                        returnValue,
    format::HandleId                                queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, returnValue, queue, pPresentInfo);

    if (frame_loop_info_.IsLooping())
    {
        // Get device
        CommonObjectInfoTable& table      = GetObjectInfoTable();
        VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(queue);
        VkDevice               device     = queue_info->parent;
        GFXRECON_ASSERT(device);
        const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
        GFXRECON_ASSERT(device_table);

        VkResult result;

        GFXRECON_LOG_DEBUG("Waiting for device to idle...");
        result = device_table->DeviceWaitIdle(device);
        CHECK_VK_RESULT(result, "vkDeviceWaitIdle");

        // Restore image layouts at the loop boundary
        RestoreImageLayouts(device, device_table, queue_info);

        FixupDeviceFences(queue_info->parent_id, queue);
    }

    frame_number_++;
    if (frame_loop_info_.AtLoopFrame(frame_number_) && !frame_loop_info_.IsLooping())
    {
        RecordInitialLayouts();
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkCmdWriteTimestamp(const ApiCallInfo&      call_info,
                                                                format::HandleId        commandBuffer,
                                                                VkPipelineStageFlagBits pipelineStage,
                                                                format::HandleId        queryPool,
                                                                uint32_t                query)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Skip writing timestamps during repetition to avoid "query not reset" errors
        // if the capture doesn't reset them in the frame.
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp(call_info, commandBuffer, pipelineStage, queryPool, query);
}

void VulkanReplayFrameLoopConsumer::Process_vkUnmapMemory(const ApiCallInfo& call_info,
                                                          format::HandleId   device,
                                                          format::HandleId   memory)
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
        GFXRECON_ASSERT(!allocatedLoopResources.contains(memory));
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
    }
    else if (mapped_loop_memory.contains(memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
        mapped_loop_memory.erase(memory);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkUnmapMemory(call_info, device, memory);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                                           call_info,
    VkResult                                                     returnValue,
    format::HandleId                                             device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is false (not acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(device) || !profilingLockState[device])
    {
        VulkanReplayConsumer::Process_vkAcquireProfilingLockKHR(call_info, returnValue, device, pInfo);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[device] = true;
    }

    frame_number_++;
    if (frame_loop_info_.AtLoopFrame(frame_number_) && !frame_loop_info_.IsLooping())
    {
        RecordInitialLayouts();
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkReleaseProfilingLockKHR(const ApiCallInfo& call_info,
                                                                      format::HandleId   device)
{
    // If we are not looping, if current lock state for this device is undefined, or
    // the current state is true (acquired), call replay consumer
    if (!frame_loop_info_.IsLooping() || !profilingLockState.contains(device) || profilingLockState[device])
    {
        VulkanReplayConsumer::Process_vkReleaseProfilingLockKHR(call_info, device);
        // We're assuming call was successful. We don't have a way to check result.
        profilingLockState[device] = false;
    }
}

void VulkanReplayFrameLoopConsumer::RecordInitialLayouts()
{
    initial_image_layouts_.clear();
    GetObjectInfoTable().VisitVkImageInfo([this](const VulkanImageInfo* info) {
        if (info != nullptr && info->handle != VK_NULL_HANDLE)
        {
            initial_image_layouts_[info->capture_id] = info->current_layout;
        }
    });
}

bool VulkanReplayFrameLoopConsumer::InitializeRestorationResources(VkDevice device, uint32_t queue_family_index)
{
    if (restoration_command_pool_ != VK_NULL_HANDLE)
    {
        return true;
    }

    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table);

    VkCommandPoolCreateInfo pool_create_info = {};
    pool_create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    pool_create_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    pool_create_info.queueFamilyIndex = queue_family_index;

    VkResult result = device_table->CreateCommandPool(device, &pool_create_info, nullptr, &restoration_command_pool_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create restoration command pool, result=%d", result);
        return false;
    }

    restoration_device_ = device;

    VkCommandBufferAllocateInfo alloc_info = {};
    alloc_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    alloc_info.commandPool = restoration_command_pool_;
    alloc_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount = 1;

    result = device_table->AllocateCommandBuffers(device, &alloc_info, &restoration_command_buffer_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to allocate restoration command buffer, result=%d", result);
        device_table->DestroyCommandPool(device, restoration_command_pool_, nullptr);
        restoration_command_pool_ = VK_NULL_HANDLE;
        restoration_device_ = VK_NULL_HANDLE;
        return false;
    }

    return true;
}

void VulkanReplayFrameLoopConsumer::RestoreImageLayouts(
    VkDevice device,
    const graphics::VulkanDeviceTable* device_table,
    VulkanQueueInfo* queue_info)
{
    std::vector<VkImageMemoryBarrier> barriers;

    GetObjectInfoTable().VisitVkImageInfo([this, &barriers](const VulkanImageInfo* info) {
        if (info == nullptr || info->handle == VK_NULL_HANDLE)
        {
            return;
        }

        VkImageLayout target_layout = VK_IMAGE_LAYOUT_UNDEFINED;
        auto it = initial_image_layouts_.find(info->capture_id);
        if (it != initial_image_layouts_.end())
        {
            target_layout = it->second;
        }
        else
        {
            target_layout = info->initial_layout;
        }

        if (target_layout == VK_IMAGE_LAYOUT_UNDEFINED || target_layout == VK_IMAGE_LAYOUT_PREINITIALIZED)
        {
            return;
        }

        if (info->current_layout != target_layout)
        {
            VkImageMemoryBarrier barrier = {};
            barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            barrier.oldLayout = info->current_layout;
            barrier.newLayout = target_layout;
            barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
            barrier.image = info->handle;
            
            barrier.subresourceRange.aspectMask = GetAspectMask(info->format);
            barrier.subresourceRange.baseMipLevel = 0;
            barrier.subresourceRange.levelCount = info->level_count;
            barrier.subresourceRange.baseArrayLayer = 0;
            barrier.subresourceRange.layerCount = info->layer_count;

            barrier.srcAccessMask = GetAccessFlags(info->current_layout);
            barrier.dstAccessMask = GetAccessFlags(target_layout);

            barriers.push_back(barrier);

            auto mutable_info = const_cast<VulkanImageInfo*>(info);
            mutable_info->current_layout = target_layout;
        }
    });

    if (barriers.empty())
    {
        return;
    }

    if (!InitializeRestorationResources(device, queue_info->family_index))
    {
        return;
    }

    // Record commands
    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    device_table->BeginCommandBuffer(restoration_command_buffer_, &begin_info);

    device_table->CmdPipelineBarrier(
        restoration_command_buffer_,
        VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
        VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
        0,
        0, nullptr,
        0, nullptr,
        static_cast<uint32_t>(barriers.size()), barriers.data()
    );

    device_table->EndCommandBuffer(restoration_command_buffer_);

    // Submit
    VkSubmitInfo submit_info = {};
    submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers = &restoration_command_buffer_;

    VkQueue replayed_queue = queue_info->handle;
    VkResult result = device_table->QueueSubmit(replayed_queue, 1, &submit_info, VK_NULL_HANDLE);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to submit layout restoration commands, result=%d", result);
    }
    else
    {
        device_table->QueueWaitIdle(replayed_queue);
    }
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
