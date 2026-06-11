/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_replay_frame_loop_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


void VulkanReplayFrameLoopConsumerBase::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    format::HandleId handle = *pInstance->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateInstance(call_info, returnValue, pCreateInfo, pAllocator, pInstance);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if instance is in allocatedLoopResources

    // Call Process_vkDestroyInstance if:
    //    We are not looping
    //    We are looping and instance is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(instance) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, instance, pAllocator);
        // Remove instance from allocatedLoopResources
        if (inAllocatedLoopResources(instance))
        {
            allocatedLoopResources.erase(instance);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    format::HandleId handle = *pDevice->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDevice(call_info, returnValue, physicalDevice, pCreateInfo, pAllocator, pDevice);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if device is in allocatedLoopResources

    // Call Process_vkDestroyDevice if:
    //    We are not looping
    //    We are looping and device is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(device) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, device, pAllocator);
        // Remove device from allocatedLoopResources
        if (inAllocatedLoopResources(device))
        {
            allocatedLoopResources.erase(device);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    format::HandleId handle = *pMemory->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkAllocateMemory(call_info, returnValue, device, pAllocateInfo, pAllocator, pMemory);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if memory is in allocatedLoopResources

    // Call Process_vkFreeMemory if:
    //    We are not looping
    //    We are looping and memory is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(memory) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, device, memory, pAllocator);
        // Remove memory from allocatedLoopResources
        if (inAllocatedLoopResources(memory))
        {
            allocatedLoopResources.erase(memory);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory(call_info, returnValue, device, buffer, memory, memoryOffset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory(call_info, returnValue, device, image, memory, memoryOffset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkQueueBindSparse(call_info, returnValue, queue, bindInfoCount, pBindInfo, fence);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    format::HandleId handle = *pFence->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateFence(call_info, returnValue, device, pCreateInfo, pAllocator, pFence);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if fence is in allocatedLoopResources

    // Call Process_vkDestroyFence if:
    //    We are not looping
    //    We are looping and fence is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(fence) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, device, fence, pAllocator);
        // Remove fence from allocatedLoopResources
        if (inAllocatedLoopResources(fence))
        {
            allocatedLoopResources.erase(fence);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    format::HandleId handle = *pSemaphore->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSemaphore(call_info, returnValue, device, pCreateInfo, pAllocator, pSemaphore);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if semaphore is in allocatedLoopResources

    // Call Process_vkDestroySemaphore if:
    //    We are not looping
    //    We are looping and semaphore is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(semaphore) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, device, semaphore, pAllocator);
        // Remove semaphore from allocatedLoopResources
        if (inAllocatedLoopResources(semaphore))
        {
            allocatedLoopResources.erase(semaphore);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    format::HandleId handle = *pQueryPool->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateQueryPool(call_info, returnValue, device, pCreateInfo, pAllocator, pQueryPool);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if queryPool is in allocatedLoopResources

    // Call Process_vkDestroyQueryPool if:
    //    We are not looping
    //    We are looping and queryPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(queryPool) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, device, queryPool, pAllocator);
        // Remove queryPool from allocatedLoopResources
        if (inAllocatedLoopResources(queryPool))
        {
            allocatedLoopResources.erase(queryPool);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    format::HandleId handle = *pBuffer->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateBuffer(call_info, returnValue, device, pCreateInfo, pAllocator, pBuffer);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if buffer is in allocatedLoopResources

    // Call Process_vkDestroyBuffer if:
    //    We are not looping
    //    We are looping and buffer is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(buffer) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, device, buffer, pAllocator);
        // Remove buffer from allocatedLoopResources
        if (inAllocatedLoopResources(buffer))
        {
            allocatedLoopResources.erase(buffer);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    format::HandleId handle = *pImage->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImage(call_info, returnValue, device, pCreateInfo, pAllocator, pImage);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if image is in allocatedLoopResources

    // Call Process_vkDestroyImage if:
    //    We are not looping
    //    We are looping and image is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(image) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, device, image, pAllocator);
        // Remove image from allocatedLoopResources
        if (inAllocatedLoopResources(image))
        {
            allocatedLoopResources.erase(image);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    format::HandleId handle = *pView->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImageView(call_info, returnValue, device, pCreateInfo, pAllocator, pView);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if imageView is in allocatedLoopResources

    // Call Process_vkDestroyImageView if:
    //    We are not looping
    //    We are looping and imageView is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(imageView) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, device, imageView, pAllocator);
        // Remove imageView from allocatedLoopResources
        if (inAllocatedLoopResources(imageView))
        {
            allocatedLoopResources.erase(imageView);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if commandPool is in allocatedLoopResources

    // Call Process_vkDestroyCommandPool if:
    //    We are not looping
    //    We are looping and commandPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(commandPool) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, device, commandPool, pAllocator);
        // Remove commandPool from allocatedLoopResources
        if (inAllocatedLoopResources(commandPool))
        {
            allocatedLoopResources.erase(commandPool);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkAllocateCommandBuffers(call_info, returnValue, device, pAllocateInfo, pCommandBuffers);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkFreeCommandBuffers(call_info, device, commandPool, commandBufferCount, pCommandBuffers);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    format::HandleId handle = *pEvent->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateEvent(call_info, returnValue, device, pCreateInfo, pAllocator, pEvent);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if event is in allocatedLoopResources

    // Call Process_vkDestroyEvent if:
    //    We are not looping
    //    We are looping and event is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(event) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
        // Remove event from allocatedLoopResources
        if (inAllocatedLoopResources(event))
        {
            allocatedLoopResources.erase(event);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    format::HandleId handle = *pView->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateBufferView(call_info, returnValue, device, pCreateInfo, pAllocator, pView);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if bufferView is in allocatedLoopResources

    // Call Process_vkDestroyBufferView if:
    //    We are not looping
    //    We are looping and bufferView is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(bufferView) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, device, bufferView, pAllocator);
        // Remove bufferView from allocatedLoopResources
        if (inAllocatedLoopResources(bufferView))
        {
            allocatedLoopResources.erase(bufferView);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    format::HandleId handle = *pShaderModule->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateShaderModule(call_info, returnValue, device, pCreateInfo, pAllocator, pShaderModule);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if shaderModule is in allocatedLoopResources

    // Call Process_vkDestroyShaderModule if:
    //    We are not looping
    //    We are looping and shaderModule is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(shaderModule) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, device, shaderModule, pAllocator);
        // Remove shaderModule from allocatedLoopResources
        if (inAllocatedLoopResources(shaderModule))
        {
            allocatedLoopResources.erase(shaderModule);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    format::HandleId handle = *pPipelineCache->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePipelineCache(call_info, returnValue, device, pCreateInfo, pAllocator, pPipelineCache);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if pipelineCache is in allocatedLoopResources

    // Call Process_vkDestroyPipelineCache if:
    //    We are not looping
    //    We are looping and pipelineCache is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(pipelineCache) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, device, pipelineCache, pAllocator);
        // Remove pipelineCache from allocatedLoopResources
        if (inAllocatedLoopResources(pipelineCache))
        {
            allocatedLoopResources.erase(pipelineCache);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMergePipelineCaches(call_info, returnValue, device, dstCache, srcCacheCount, pSrcCaches);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < createInfoCount; i++)
        {
            format::HandleId handle = *(pPipelines[i].GetPointer());
            if (!inAllocatedLoopResources(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateComputePipelines(call_info, returnValue, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < createInfoCount; i++)
            {
                format::HandleId handle = *(pPipelines[i].GetPointer());
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if pipeline is in allocatedLoopResources

    // Call Process_vkDestroyPipeline if:
    //    We are not looping
    //    We are looping and pipeline is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(pipeline) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, device, pipeline, pAllocator);
        // Remove pipeline from allocatedLoopResources
        if (inAllocatedLoopResources(pipeline))
        {
            allocatedLoopResources.erase(pipeline);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    format::HandleId handle = *pPipelineLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePipelineLayout(call_info, returnValue, device, pCreateInfo, pAllocator, pPipelineLayout);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if pipelineLayout is in allocatedLoopResources

    // Call Process_vkDestroyPipelineLayout if:
    //    We are not looping
    //    We are looping and pipelineLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(pipelineLayout) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, device, pipelineLayout, pAllocator);
        // Remove pipelineLayout from allocatedLoopResources
        if (inAllocatedLoopResources(pipelineLayout))
        {
            allocatedLoopResources.erase(pipelineLayout);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    format::HandleId handle = *pSampler->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSampler(call_info, returnValue, device, pCreateInfo, pAllocator, pSampler);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if sampler is in allocatedLoopResources

    // Call Process_vkDestroySampler if:
    //    We are not looping
    //    We are looping and sampler is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(sampler) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, device, sampler, pAllocator);
        // Remove sampler from allocatedLoopResources
        if (inAllocatedLoopResources(sampler))
        {
            allocatedLoopResources.erase(sampler);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    format::HandleId handle = *pSetLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(call_info, returnValue, device, pCreateInfo, pAllocator, pSetLayout);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if descriptorSetLayout is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorSetLayout if:
    //    We are not looping
    //    We are looping and descriptorSetLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(descriptorSetLayout) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, device, descriptorSetLayout, pAllocator);
        // Remove descriptorSetLayout from allocatedLoopResources
        if (inAllocatedLoopResources(descriptorSetLayout))
        {
            allocatedLoopResources.erase(descriptorSetLayout);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < createInfoCount; i++)
        {
            format::HandleId handle = *(pPipelines[i].GetPointer());
            if (!inAllocatedLoopResources(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(call_info, returnValue, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < createInfoCount; i++)
            {
                format::HandleId handle = *(pPipelines[i].GetPointer());
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    format::HandleId handle = *pFramebuffer->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateFramebuffer(call_info, returnValue, device, pCreateInfo, pAllocator, pFramebuffer);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if framebuffer is in allocatedLoopResources

    // Call Process_vkDestroyFramebuffer if:
    //    We are not looping
    //    We are looping and framebuffer is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(framebuffer) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, device, framebuffer, pAllocator);
        // Remove framebuffer from allocatedLoopResources
        if (inAllocatedLoopResources(framebuffer))
        {
            allocatedLoopResources.erase(framebuffer);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass(call_info, returnValue, device, pCreateInfo, pAllocator, pRenderPass);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if renderPass is in allocatedLoopResources

    // Call Process_vkDestroyRenderPass if:
    //    We are not looping
    //    We are looping and renderPass is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(renderPass) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, device, renderPass, pAllocator);
        // Remove renderPass from allocatedLoopResources
        if (inAllocatedLoopResources(renderPass))
        {
            allocatedLoopResources.erase(renderPass);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory2(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory2(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    format::HandleId handle = *pDescriptorUpdateTemplate->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(call_info, returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if descriptorUpdateTemplate is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorUpdateTemplate if:
    //    We are not looping
    //    We are looping and descriptorUpdateTemplate is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(descriptorUpdateTemplate) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, device, descriptorUpdateTemplate, pAllocator);
        // Remove descriptorUpdateTemplate from allocatedLoopResources
        if (inAllocatedLoopResources(descriptorUpdateTemplate))
        {
            allocatedLoopResources.erase(descriptorUpdateTemplate);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    format::HandleId handle = *pYcbcrConversion->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(call_info, returnValue, device, pCreateInfo, pAllocator, pYcbcrConversion);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if ycbcrConversion is in allocatedLoopResources

    // Call Process_vkDestroySamplerYcbcrConversion if:
    //    We are not looping
    //    We are looping and ycbcrConversion is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(ycbcrConversion) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, device, ycbcrConversion, pAllocator);
        // Remove ycbcrConversion from allocatedLoopResources
        if (inAllocatedLoopResources(ycbcrConversion))
        {
            allocatedLoopResources.erase(ycbcrConversion);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2(call_info, returnValue, device, pCreateInfo, pAllocator, pRenderPass);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    format::HandleId handle = *pPrivateDataSlot->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePrivateDataSlot(call_info, returnValue, device, pCreateInfo, pAllocator, pPrivateDataSlot);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if privateDataSlot is in allocatedLoopResources

    // Call Process_vkDestroyPrivateDataSlot if:
    //    We are not looping
    //    We are looping and privateDataSlot is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(privateDataSlot) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, device, privateDataSlot, pAllocator);
        // Remove privateDataSlot from allocatedLoopResources
        if (inAllocatedLoopResources(privateDataSlot))
        {
            allocatedLoopResources.erase(privateDataSlot);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfo>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMapMemory2(call_info, returnValue, device, pMemoryMapInfo, ppData);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo>* pMemoryUnmapInfo)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkUnmapMemory2(call_info, returnValue, device, pMemoryUnmapInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfo>* pTransitions)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkTransitionImageLayout(call_info, returnValue, device, transitionCount, pTransitions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if surface is in allocatedLoopResources

    // Call Process_vkDestroySurfaceKHR if:
    //    We are not looping
    //    We are looping and surface is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(surface) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, instance, surface, pAllocator);
        // Remove surface from allocatedLoopResources
        if (inAllocatedLoopResources(surface))
        {
            allocatedLoopResources.erase(surface);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    format::HandleId handle = *pSwapchain->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSwapchainKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pSwapchain);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if swapchain is in allocatedLoopResources

    // Call Process_vkDestroySwapchainKHR if:
    //    We are not looping
    //    We are looping and swapchain is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(swapchain) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, device, swapchain, pAllocator);
        // Remove swapchain from allocatedLoopResources
        if (inAllocatedLoopResources(swapchain))
        {
            allocatedLoopResources.erase(swapchain);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    format::HandleId handle = *pMode->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(call_info, returnValue, physicalDevice, display, pCreateInfo, pAllocator, pMode);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    format::HandleId handle = *pSwapchains->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(call_info, returnValue, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    format::HandleId handle = *pVideoSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateVideoSessionKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pVideoSession);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if videoSession is in allocatedLoopResources

    // Call Process_vkDestroyVideoSessionKHR if:
    //    We are not looping
    //    We are looping and videoSession is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(videoSession) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, device, videoSession, pAllocator);
        // Remove videoSession from allocatedLoopResources
        if (inAllocatedLoopResources(videoSession))
        {
            allocatedLoopResources.erase(videoSession);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindVideoSessionMemoryKHR(call_info, returnValue, device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    format::HandleId handle = *pVideoSessionParameters->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateVideoSessionParametersKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pVideoSessionParameters);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if videoSessionParameters is in allocatedLoopResources

    // Call Process_vkDestroyVideoSessionParametersKHR if:
    //    We are not looping
    //    We are looping and videoSessionParameters is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(videoSessionParameters) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, device, videoSessionParameters, pAllocator);
        // Remove videoSessionParameters from allocatedLoopResources
        if (inAllocatedLoopResources(videoSessionParameters))
        {
            allocatedLoopResources.erase(videoSessionParameters);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(call_info, returnValue, device, pImportSemaphoreFdInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    format::HandleId handle = *pDescriptorUpdateTemplate->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if descriptorUpdateTemplate is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorUpdateTemplateKHR if:
    //    We are not looping
    //    We are looping and descriptorUpdateTemplate is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(descriptorUpdateTemplate) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, device, descriptorUpdateTemplate, pAllocator);
        // Remove descriptorUpdateTemplate from allocatedLoopResources
        if (inAllocatedLoopResources(descriptorUpdateTemplate))
        {
            allocatedLoopResources.erase(descriptorUpdateTemplate);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(call_info, returnValue, device, pCreateInfo, pAllocator, pRenderPass);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkImportFenceFdKHR(call_info, returnValue, device, pImportFenceFdInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    format::HandleId handle = *pYcbcrConversion->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pYcbcrConversion);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if ycbcrConversion is in allocatedLoopResources

    // Call Process_vkDestroySamplerYcbcrConversionKHR if:
    //    We are not looping
    //    We are looping and ycbcrConversion is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(ycbcrConversion) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, device, ycbcrConversion, pAllocator);
        // Remove ycbcrConversion from allocatedLoopResources
        if (inAllocatedLoopResources(ycbcrConversion))
        {
            allocatedLoopResources.erase(ycbcrConversion);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory2KHR(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    format::HandleId handle = *pDeferredOperation->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDeferredOperationKHR(call_info, returnValue, device, pAllocator, pDeferredOperation);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if operation is in allocatedLoopResources

    // Call Process_vkDestroyDeferredOperationKHR if:
    //    We are not looping
    //    We are looping and operation is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(operation) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, device, operation, pAllocator);
        // Remove operation from allocatedLoopResources
        if (inAllocatedLoopResources(operation))
        {
            allocatedLoopResources.erase(operation);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfo>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMapMemory2KHR(call_info, returnValue, device, pMemoryMapInfo, ppData);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfo>* pMemoryUnmapInfo)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkUnmapMemory2KHR(call_info, returnValue, device, pMemoryUnmapInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineBinaryCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    StructPointerDecoder<Decoded_VkPipelineBinaryHandlesInfoKHR>* pBinaries)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCreatePipelineBinariesKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pBinaries);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineBinary,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if pipelineBinary is in allocatedLoopResources

    // Call Process_vkDestroyPipelineBinaryKHR if:
    //    We are not looping
    //    We are looping and pipelineBinary is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(pipelineBinary) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, device, pipelineBinary, pAllocator);
        // Remove pipelineBinary from allocatedLoopResources
        if (inAllocatedLoopResources(pipelineBinary))
        {
            allocatedLoopResources.erase(pipelineBinary);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseCapturedPipelineDataInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseCapturedPipelineDataKHR(call_info, returnValue, device, pInfo, pAllocator);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR>* pReleaseInfo)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseSwapchainImagesKHR(call_info, returnValue, device, pReleaseInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    format::HandleId handle = *pCallback->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pCallback);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if callback is in allocatedLoopResources

    // Call Process_vkDestroyDebugReportCallbackEXT if:
    //    We are not looping
    //    We are looping and callback is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(callback) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, instance, callback, pAllocator);
        // Remove callback from allocatedLoopResources
        if (inAllocatedLoopResources(callback))
        {
            allocatedLoopResources.erase(callback);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateViSurfaceNN(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseDisplayEXT(call_info, returnValue, physicalDevice, display);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(call_info, returnValue, device, pDeviceEventInfo, pAllocator, pFence);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(call_info, returnValue, device, display, pDisplayEventInfo, pAllocator, pFence);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    format::HandleId handle = *pMessenger->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pMessenger);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if messenger is in allocatedLoopResources

    // Call Process_vkDestroyDebugUtilsMessengerEXT if:
    //    We are not looping
    //    We are looping and messenger is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(messenger) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, instance, messenger, pAllocator);
        // Remove messenger from allocatedLoopResources
        if (inAllocatedLoopResources(messenger))
        {
            allocatedLoopResources.erase(messenger);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    format::HandleId handle = *pValidationCache->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(call_info, returnValue, device, pCreateInfo, pAllocator, pValidationCache);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if validationCache is in allocatedLoopResources

    // Call Process_vkDestroyValidationCacheEXT if:
    //    We are not looping
    //    We are looping and validationCache is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(validationCache) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, device, validationCache, pAllocator);
        // Remove validationCache from allocatedLoopResources
        if (inAllocatedLoopResources(validationCache))
        {
            allocatedLoopResources.erase(validationCache);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    format::HandleId handle = *pAccelerationStructure->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(call_info, returnValue, device, pCreateInfo, pAllocator, pAccelerationStructure);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(call_info, device, accelerationStructure, pAllocator);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindAccelerationStructureMemoryNV(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < createInfoCount; i++)
        {
            format::HandleId handle = *(pPipelines[i].GetPointer());
            if (!inAllocatedLoopResources(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesNV(call_info, returnValue, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < createInfoCount; i++)
            {
                format::HandleId handle = *(pPipelines[i].GetPointer());
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(call_info, returnValue, device, configuration);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(call_info, returnValue, device, swapchain);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoKHR>* pReleaseInfo)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseSwapchainImagesEXT(call_info, returnValue, device, pReleaseInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    format::HandleId handle = *pIndirectCommandsLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNV(call_info, returnValue, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if indirectCommandsLayout is in allocatedLoopResources

    // Call Process_vkDestroyIndirectCommandsLayoutNV if:
    //    We are not looping
    //    We are looping and indirectCommandsLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(indirectCommandsLayout) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, device, indirectCommandsLayout, pAllocator);
        // Remove indirectCommandsLayout from allocatedLoopResources
        if (inAllocatedLoopResources(indirectCommandsLayout))
        {
            allocatedLoopResources.erase(indirectCommandsLayout);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    format::HandleId handle = *pPrivateDataSlot->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePrivateDataSlotEXT(call_info, returnValue, device, pCreateInfo, pAllocator, pPrivateDataSlot);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if privateDataSlot is in allocatedLoopResources

    // Call Process_vkDestroyPrivateDataSlotEXT if:
    //    We are not looping
    //    We are looping and privateDataSlot is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(privateDataSlot) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, device, privateDataSlot, pAllocator);
        // Remove privateDataSlot from allocatedLoopResources
        if (inAllocatedLoopResources(privateDataSlot))
        {
            allocatedLoopResources.erase(privateDataSlot);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    format::HandleId handle = *pMicromap->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMicromapEXT(call_info, returnValue, device, pCreateInfo, pAllocator, pMicromap);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if micromap is in allocatedLoopResources

    // Call Process_vkDestroyMicromapEXT if:
    //    We are not looping
    //    We are looping and micromap is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(micromap) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, device, micromap, pAllocator);
        // Remove micromap from allocatedLoopResources
        if (inAllocatedLoopResources(micromap))
        {
            allocatedLoopResources.erase(micromap);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    format::HandleId handle = *pSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateOpticalFlowSessionNV(call_info, returnValue, device, pCreateInfo, pAllocator, pSession);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if session is in allocatedLoopResources

    // Call Process_vkDestroyOpticalFlowSessionNV if:
    //    We are not looping
    //    We are looping and session is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(session) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, device, session, pAllocator);
        // Remove session from allocatedLoopResources
        if (inAllocatedLoopResources(session))
        {
            allocatedLoopResources.erase(session);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindOpticalFlowSessionImageNV(call_info, returnValue, device, session, bindingPoint, view, layout);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    format::HandleId handle = *pShaders->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateShadersEXT(call_info, returnValue, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if shader is in allocatedLoopResources

    // Call Process_vkDestroyShaderEXT if:
    //    We are not looping
    //    We are looping and shader is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(shader) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, device, shader, pAllocator);
        // Remove shader from allocatedLoopResources
        if (inAllocatedLoopResources(shader))
        {
            allocatedLoopResources.erase(shader);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkDataGraphPipelineCreateInfoARM>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < createInfoCount; i++)
        {
            format::HandleId handle = *(pPipelines[i].GetPointer());
            if (!inAllocatedLoopResources(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateDataGraphPipelinesARM(call_info, returnValue, device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < createInfoCount; i++)
            {
                format::HandleId handle = *(pPipelines[i].GetPointer());
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDataGraphPipelineSessionCreateInfoARM>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDataGraphPipelineSessionARM>* pSession)
{
    format::HandleId handle = *pSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDataGraphPipelineSessionARM(call_info, returnValue, device, pCreateInfo, pAllocator, pSession);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM>* pBindInfos)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(call_info, returnValue, device, bindInfoCount, pBindInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if session is in allocatedLoopResources

    // Call Process_vkDestroyDataGraphPipelineSessionARM if:
    //    We are not looping
    //    We are looping and session is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(session) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, device, session, pAllocator);
        // Remove session from allocatedLoopResources
        if (inAllocatedLoopResources(session))
        {
            allocatedLoopResources.erase(session);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT>* pIndirectCommandsLayout)
{
    format::HandleId handle = *pIndirectCommandsLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutEXT(call_info, returnValue, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if indirectCommandsLayout is in allocatedLoopResources

    // Call Process_vkDestroyIndirectCommandsLayoutEXT if:
    //    We are not looping
    //    We are looping and indirectCommandsLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(indirectCommandsLayout) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, device, indirectCommandsLayout, pAllocator);
        // Remove indirectCommandsLayout from allocatedLoopResources
        if (inAllocatedLoopResources(indirectCommandsLayout))
        {
            allocatedLoopResources.erase(indirectCommandsLayout);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectExecutionSetCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectExecutionSetEXT>* pIndirectExecutionSet)
{
    format::HandleId handle = *pIndirectExecutionSet->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectExecutionSetEXT(call_info, returnValue, device, pCreateInfo, pAllocator, pIndirectExecutionSet);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectExecutionSet,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if indirectExecutionSet is in allocatedLoopResources

    // Call Process_vkDestroyIndirectExecutionSetEXT if:
    //    We are not looping
    //    We are looping and indirectExecutionSet is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping() ||
        inAllocatedLoopResources(indirectExecutionSet) ||
        getFrameLoopInfo().IsFinalIteration())
    {
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, device, indirectExecutionSet, pAllocator);
        // Remove indirectExecutionSet from allocatedLoopResources
        if (inAllocatedLoopResources(indirectExecutionSet))
        {
            allocatedLoopResources.erase(indirectExecutionSet);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    format::HandleId handle = *pAccelerationStructure->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !inAllocatedLoopResources(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAccelerationStructureKHR(call_info, returnValue, device, pCreateInfo, pAllocator, pAccelerationStructure);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkDestroyAccelerationStructureKHR(call_info, device, accelerationStructure, pAllocator);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
