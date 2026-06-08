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

void VulkanReplayFrameLoopConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                                     call_info,
    VkResult                                               returnValue,
    format::HandleId                                       device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>*   pAllocator,
    HandlePointerDecoder<VkCommandPool>*                   pCommandPool)
{
    if (frame_loop_info_.IsRepetition())
    {
        // Don't repeatedly recreate the command pool during the looping frame
        return;
    }

    // Set VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT in order to prevent validation
    // error regarding implicitly resetting the command buffer
    VkCommandPoolCreateInfo* create_info = pCreateInfo->GetPointer();
    create_info->flags |= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    VulkanReplayConsumer::Process_vkCreateCommandPool(
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
    if (frame_loop_info_.IsRepetition() && !frame_loop_info_.IsFinalIteration())
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
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsFinalIteration())
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
    if (frame_loop_info_.IsRepetition() && !frame_loop_info_.IsFinalIteration())
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

void VulkanReplayFrameLoopConsumer::Process_vkWaitForFences(const ApiCallInfo&             call_info,
                                                            VkResult                       returnValue,
                                                            format::HandleId               device,
                                                            uint32_t                       fenceCount,
                                                            HandlePointerDecoder<VkFence>* pFences,
                                                            VkBool32                       waitAll,
                                                            uint64_t                       timeout)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        for (int i = 0; i < fenceCount; ++i)
        {
            if (!per_device_fence_tracking_.contains(device))
            {
                per_device_fence_tracking_[device] = {};
            }
            FenceTracking& t = per_device_fence_tracking_[device];

            format::HandleId fence = pFences->GetPointer()[i];
            if (t.waited_upon_fences_.contains(fence))
            {
                t.waited_upon_fences_[fence] += 1;
            }
            else
            {
                t.waited_upon_fences_[fence] = 1;
            }
            GFXRECON_LOG_DEBUG("VkFence with handle \"%" PRIu64 "\" has been waited on %" PRIu32 " times.",
                               fence,
                               t.waited_upon_fences_[fence]);
        }
    }

    VulkanReplayConsumer::Process_vkWaitForFences(
        call_info, returnValue, device, fenceCount, pFences, waitAll, timeout);
}

void VulkanReplayFrameLoopConsumer::Process_vkQueueSubmit(const ApiCallInfo&                          call_info,
                                                          VkResult                                    returnValue,
                                                          format::HandleId                            queue,
                                                          uint32_t                                    submitCount,
                                                          StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
                                                          format::HandleId                            fence)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Collect fences submitted during the looping frame
        VulkanFenceInfo* fence_info = GetObjectInfoTable().GetVkFenceInfo(fence);
        if (fence_info != nullptr)
        {
            format::HandleId device = GetObjectInfoTable().GetVkQueueInfo(queue)->parent_id;
            if (!per_device_fence_tracking_.contains(device))
            {
                per_device_fence_tracking_[device] = {};
            }
            FenceTracking& t = per_device_fence_tracking_[device];

            if (t.signaled_fences_.contains(fence))
            {
                t.signaled_fences_[fence] += 1;
            }
            else
            {
                t.signaled_fences_[fence] = 1;
            }
            t.signaled_fences_[fence];
            GFXRECON_LOG_DEBUG("VkFence with handle \"%" PRIu64 "\" has been signaled %" PRIu32 " times.",
                               fence,
                               t.signaled_fences_[fence]);
        }
    }

    VulkanReplayConsumer::Process_vkQueueSubmit(call_info, returnValue, queue, submitCount, pSubmits, fence);
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

    // Gather fences that need to be synthetically waited on
    std::vector<VkFence> manual_wait_fences;
    manual_wait_fences.reserve(t.signaled_fences_.size());
    for (auto [fence_id, signal_count] : t.signaled_fences_)
    {
        uint32_t wait_count = 0;
        if (t.waited_upon_fences_.contains(fence_id))
        {
            wait_count = t.waited_upon_fences_[fence_id];
        }

        // Manually wait on the fence if it's signaled more times than it is waited upon
        if (signal_count > wait_count)
        {
            GFXRECON_LOG_DEBUG("Will synthetically wait on fence %" PRIu64, fence_id);
            VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
            manual_wait_fences.push_back(fence_info->handle);
        }
    }

    // Gather fences that need to be synthetically signaled
    std::vector<VkFence> manual_signal_fences;
    manual_signal_fences.reserve(t.signaled_fences_.size());
    for (auto [fence_id, wait_count] : t.waited_upon_fences_)
    {
        uint32_t signal_count = 0;
        if (t.signaled_fences_.contains(fence_id))
        {
            signal_count = t.signaled_fences_[fence_id];
        }

        // Manually signal fence if it's waited on more times than it is signaled
        if (wait_count > signal_count)
        {
            GFXRECON_LOG_DEBUG("Will synthetically signal fence %" PRIu64, fence_id);
            VulkanFenceInfo* fence_info = table.GetVkFenceInfo(fence_id);
            manual_signal_fences.push_back(fence_info->handle);
        }
    }

    VkResult result;

    if (manual_wait_fences.size() > 0)
    {
        GFXRECON_LOG_DEBUG("Synthetically waiting on fences...");
        result = device_table->WaitForFences(vk_device,
                                             manual_wait_fences.size(),
                                             manual_wait_fences.data(),
                                             VK_TRUE,
                                             std::numeric_limits<uint64_t>::max());
        CHECK_VK_RESULT(result, "vkWaitForFences");

        GFXRECON_LOG_DEBUG("Resetting synthetically waited on fences...");
        result = device_table->ResetFences(vk_device, manual_wait_fences.size(), manual_wait_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");
    }

    if (manual_signal_fences.size() > 0)
    {
        // Fences may have been waited on but not reset, so we reset the fences we're going
        // to manually signal here just in case.
        result = device_table->ResetFences(vk_device, manual_signal_fences.size(), manual_signal_fences.data());
        CHECK_VK_RESULT(result, "vkResetFences");

        GFXRECON_LOG_DEBUG("Synthetically signaling fences...");
        for (VkFence fence : manual_signal_fences)
        {
            VulkanQueueInfo* queue_info = table.GetVkQueueInfo(queue);
            result                      = device_table->QueueSubmit(queue_info->handle, 0, nullptr, fence);
            CHECK_VK_RESULT(result, "vkDeviceWaitIdle");
        }
    }
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

        FixupDeviceFences(queue_info->parent_id, queue);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
