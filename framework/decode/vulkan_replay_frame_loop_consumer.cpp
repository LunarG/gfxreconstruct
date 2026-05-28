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

#include "decode/vulkan_replay_frame_loop_consumer.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"

#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"
#include "decode/vulkan_replay_frame_loop_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

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

    if (frame_loop_info_.IsRepetition())
    {
        // Skip allocation of dangling descriptor pools
        if (dangling_descriptor_pools_.contains(pool_id))
        {
            return;
        }
    }

    VulkanReplayConsumer::Process_vkCreateDescriptorPool(
        call_info, returnValue, device, pCreateInfo, pAllocator, pDescriptorPool);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Gather descriptor pools that are created during the loop range
        dangling_descriptor_pools_.insert(pool_id);
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
        if (dangling_descriptor_pools_.contains(descriptorPool))
        {
            return;
        }
    }

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        if (!dangling_descriptor_pools_.contains(descriptorPool))
        {
            // If this pool was not created during the loop range, ignore destroying it.
            dangling_descriptor_pools_.insert(descriptorPool);
            return;
        }
        else
        {
            // Created and destroyed during the loop range
            dangling_descriptor_pools_.erase(descriptorPool);

            // Check if this was the pool for any heretofore dangling descriptors
            DeleteDanglingPoolDescriptorSets(descriptorPool);
        }
    }
    VulkanReplayConsumer::Process_vkDestroyDescriptorPool(call_info, device, descriptorPool, pAllocator);
}

void VulkanReplayFrameLoopConsumer::Process_vkResetDescriptorPool(const ApiCallInfo&                          call_info,
                                                                  VkResult                                    returnValue,
                                                                  format::HandleId                            device,
                                                                  format::HandleId                            descriptorPool,
                                                                  VkDescriptorPoolResetFlags                  flags)
{
    if (frame_loop_info_.IsRepetition())
    {
        // If any of the sets in this pool are dangling, skip pool reset
        for (format::HandleId set_id : dangling_descriptor_sets_)
        {
            VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(set_id);
            if (info->pool_id == descriptorPool)
            {
                return;
            }
        }
    }

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        // Reset descriptor pool means that the pool is still valid, but the allocated descriptor sets are not
        // Check if this was the pool for any heretofore dangling descriptors
        DeleteDanglingPoolDescriptorSets(descriptorPool);
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
        const format::HandleId* set_handles = pDescriptorSets->GetPointer();
        for (int i = 0; i < pDescriptorSets->GetLength(); ++i)
        {
            if (dangling_descriptor_sets_.contains(set_handles[i]))
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
        const format::HandleId* set_handles = pDescriptorSets->GetPointer();
        for (int i = 0; i < pDescriptorSets->GetLength(); ++i)
        {
            dangling_descriptor_sets_.insert(set_handles[i]);
        }
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkFreeDescriptorSets(const ApiCallInfo&                          call_info,
                                                                 VkResult                                    returnValue,
                                                                 format::HandleId                            device,
                                                                 format::HandleId                            descriptorPool,
                                                                 uint32_t                                    descriptorSetCount,
                                                                 HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    if (frame_loop_info_.IsRepetition())
    {
        // If any of the descriptor sets are _not_ in the dangling list,
        // then we want to omit their destruction
        const format::HandleId* handles = pDescriptorSets->GetPointer();
        for (int i = 0; i < descriptorSetCount; ++i)
        {
            if (!dangling_descriptor_sets_.contains(handles[i]))
            {
                return;
            }
        }
    }

    VulkanReplayConsumer::Process_vkFreeDescriptorSets(
        call_info, returnValue, device, descriptorPool, descriptorSetCount, pDescriptorSets);

    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsRepetition())
    {
        const format::HandleId* handles = pDescriptorSets->GetPointer();
        for (int i = 0; i < descriptorSetCount; ++i)
        {
            if (dangling_descriptor_sets_.contains(handles[i]))
            {
                // Any descriptor set that was freed during the loop range is not dangling
                dangling_descriptor_sets_.erase(handles[i]);
            }
            else
            {
                // Descriptor set freed during loop range but created before
                dangling_descriptor_sets_.insert(handles[i]);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumer::DeleteDanglingPoolDescriptorSets(format::HandleId descriptorPool)
{
    std::vector<format::HandleId> handles_to_delete;
    handles_to_delete.reserve(dangling_descriptor_sets_.size());
    for (format::HandleId handle : dangling_descriptor_sets_)
    {
        VulkanDescriptorSetInfo* info = GetObjectInfoTable().GetVkDescriptorSetInfo(handle);
        if (info->pool_id == descriptorPool)
        {
            handles_to_delete.push_back(handle);
        }
    }

    for (format::HandleId handle : handles_to_delete)
    {
        dangling_descriptor_sets_.erase(handle);
    }
}

void VulkanReplayFrameLoopConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                              call_info,
    VkResult                                        returnValue,
    format::HandleId                                queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    // Get device
    CommonObjectInfoTable& table      = GetObjectInfoTable();
    VulkanQueueInfo*       queue_info = table.GetVkQueueInfo(queue);
    VkDevice               device     = queue_info->parent;
    GFXRECON_ASSERT(device);
    const graphics::VulkanDeviceTable* device_table = GetDeviceTable(device);
    GFXRECON_ASSERT(device_table);

    VulkanReplayConsumer::Process_vkQueuePresentKHR(call_info, returnValue, queue, pPresentInfo);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
