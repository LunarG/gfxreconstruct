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
    // Check for null cases
    if (pInstance == nullptr || pInstance->IsNull())
    {
        return;
    }
    format::HandleId handle = *pInstance->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(instance))
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, instance, pAllocator);
    }
    else if (allocatedLoopResources.contains(instance))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, instance, pAllocator);
        allocatedLoopResources.erase(instance);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, instance, pAllocator);
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
    // Check for null cases
    if (pDevice == nullptr || pDevice->IsNull())
    {
        return;
    }
    format::HandleId handle = *pDevice->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(device))
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, device, pAllocator);
    }
    else if (allocatedLoopResources.contains(device))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, device, pAllocator);
        allocatedLoopResources.erase(device);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, device, pAllocator);
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
    // Check for null cases
    if (pMemory == nullptr || pMemory->IsNull())
    {
        return;
    }
    format::HandleId handle = *pMemory->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(memory))
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, device, memory, pAllocator);
    }
    else if (allocatedLoopResources.contains(memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, device, memory, pAllocator);
        allocatedLoopResources.erase(memory);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, device, memory, pAllocator);
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
    // Check for null cases
    if (pFence == nullptr || pFence->IsNull())
    {
        return;
    }
    format::HandleId handle = *pFence->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(fence))
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, device, fence, pAllocator);
    }
    else if (allocatedLoopResources.contains(fence))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, device, fence, pAllocator);
        allocatedLoopResources.erase(fence);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, device, fence, pAllocator);
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
    // Check for null cases
    if (pSemaphore == nullptr || pSemaphore->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSemaphore->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(semaphore))
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, device, semaphore, pAllocator);
    }
    else if (allocatedLoopResources.contains(semaphore))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, device, semaphore, pAllocator);
        allocatedLoopResources.erase(semaphore);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, device, semaphore, pAllocator);
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
    // Check for null cases
    if (pQueryPool == nullptr || pQueryPool->IsNull())
    {
        return;
    }
    format::HandleId handle = *pQueryPool->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(queryPool))
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, device, queryPool, pAllocator);
    }
    else if (allocatedLoopResources.contains(queryPool))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, device, queryPool, pAllocator);
        allocatedLoopResources.erase(queryPool);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, device, queryPool, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkGetQueryPoolResults(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkGetQueryPoolResults(call_info, returnValue, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    // Check for null cases
    if (pBuffer == nullptr || pBuffer->IsNull())
    {
        return;
    }
    format::HandleId handle = *pBuffer->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(buffer))
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, device, buffer, pAllocator);
    }
    else if (allocatedLoopResources.contains(buffer))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, device, buffer, pAllocator);
        allocatedLoopResources.erase(buffer);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, device, buffer, pAllocator);
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
    // Check for null cases
    if (pImage == nullptr || pImage->IsNull())
    {
        return;
    }
    format::HandleId handle = *pImage->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(image))
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, device, image, pAllocator);
    }
    else if (allocatedLoopResources.contains(image))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, device, image, pAllocator);
        allocatedLoopResources.erase(image);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, device, image, pAllocator);
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
    // Check for null cases
    if (pView == nullptr || pView->IsNull())
    {
        return;
    }
    format::HandleId handle = *pView->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(imageView))
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, device, imageView, pAllocator);
    }
    else if (allocatedLoopResources.contains(imageView))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, device, imageView, pAllocator);
        allocatedLoopResources.erase(imageView);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, device, imageView, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    // Check for null cases
    if (pCommandPool == nullptr || pCommandPool->IsNull())
    {
        return;
    }
    format::HandleId handle = *pCommandPool->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateCommandPool(call_info, returnValue, device, pCreateInfo, pAllocator, pCommandPool);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(commandPool))
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, device, commandPool, pAllocator);
    }
    else if (allocatedLoopResources.contains(commandPool))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, device, commandPool, pAllocator);
        allocatedLoopResources.erase(commandPool);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, device, commandPool, pAllocator);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer(call_info, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(call_info, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(call_info, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdateBuffer(call_info, commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdFillBuffer(call_info, commandBuffer, dstBuffer, dstOffset, size, data);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier(call_info, commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginQuery(call_info, commandBuffer, queryPool, query, flags);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndQuery(call_info, commandBuffer, queryPool, query);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetQueryPool(call_info, commandBuffer, queryPool, firstQuery, queryCount);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp(call_info, commandBuffer, pipelineStage, queryPool, query);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(call_info, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteCommands(call_info, commandBuffer, commandBufferCount, pCommandBuffers);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    // Check for null cases
    if (pEvent == nullptr || pEvent->IsNull())
    {
        return;
    }
    format::HandleId handle = *pEvent->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(event))
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
    }
    else if (allocatedLoopResources.contains(event))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
        allocatedLoopResources.erase(event);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, device, event, pAllocator);
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
    // Check for null cases
    if (pView == nullptr || pView->IsNull())
    {
        return;
    }
    format::HandleId handle = *pView->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(bufferView))
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, device, bufferView, pAllocator);
    }
    else if (allocatedLoopResources.contains(bufferView))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, device, bufferView, pAllocator);
        allocatedLoopResources.erase(bufferView);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, device, bufferView, pAllocator);
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
    // Check for null cases
    if (pShaderModule == nullptr || pShaderModule->IsNull())
    {
        return;
    }
    format::HandleId handle = *pShaderModule->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(shaderModule))
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, device, shaderModule, pAllocator);
    }
    else if (allocatedLoopResources.contains(shaderModule))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, device, shaderModule, pAllocator);
        allocatedLoopResources.erase(shaderModule);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, device, shaderModule, pAllocator);
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
    // Check for null cases
    if (pPipelineCache == nullptr || pPipelineCache->IsNull())
    {
        return;
    }
    format::HandleId handle = *pPipelineCache->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(pipelineCache))
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, device, pipelineCache, pAllocator);
    }
    else if (allocatedLoopResources.contains(pipelineCache))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, device, pipelineCache, pAllocator);
        allocatedLoopResources.erase(pipelineCache);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, device, pipelineCache, pAllocator);
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
            format::HandleId handle = pPipelines->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
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
                format::HandleId handle = pPipelines->GetPointer()[i];
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(pipeline))
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, device, pipeline, pAllocator);
    }
    else if (allocatedLoopResources.contains(pipeline))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, device, pipeline, pAllocator);
        allocatedLoopResources.erase(pipeline);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, device, pipeline, pAllocator);
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
    // Check for null cases
    if (pPipelineLayout == nullptr || pPipelineLayout->IsNull())
    {
        return;
    }
    format::HandleId handle = *pPipelineLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(pipelineLayout))
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, device, pipelineLayout, pAllocator);
    }
    else if (allocatedLoopResources.contains(pipelineLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, device, pipelineLayout, pAllocator);
        allocatedLoopResources.erase(pipelineLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, device, pipelineLayout, pAllocator);
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
    // Check for null cases
    if (pSampler == nullptr || pSampler->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSampler->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(sampler))
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, device, sampler, pAllocator);
    }
    else if (allocatedLoopResources.contains(sampler))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, device, sampler, pAllocator);
        allocatedLoopResources.erase(sampler);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, device, sampler, pAllocator);
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
    // Check for null cases
    if (pSetLayout == nullptr || pSetLayout->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSetLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(descriptorSetLayout))
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, device, descriptorSetLayout, pAllocator);
    }
    else if (allocatedLoopResources.contains(descriptorSetLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, device, descriptorSetLayout, pAllocator);
        allocatedLoopResources.erase(descriptorSetLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, device, descriptorSetLayout, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindPipeline(call_info, commandBuffer, pipelineBindPoint, pipeline);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    PointerDecoder<uint32_t>*                   pDynamicOffsets)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(call_info, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearColorImage(call_info, commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatch(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchIndirect(call_info, commandBuffer, buffer, offset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent(call_info, commandBuffer, event, stageMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent(call_info, commandBuffer, event, stageMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    StructPointerDecoder<Decoded_VkMemoryBarrier>* pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier>* pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents(call_info, commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants(call_info, commandBuffer, layout, stageFlags, offset, size, pValues);
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
            format::HandleId handle = pPipelines->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
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
                format::HandleId handle = pPipelines->GetPointer()[i];
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
    // Check for null cases
    if (pFramebuffer == nullptr || pFramebuffer->IsNull())
    {
        return;
    }
    format::HandleId handle = *pFramebuffer->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(framebuffer))
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, device, framebuffer, pAllocator);
    }
    else if (allocatedLoopResources.contains(framebuffer))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, device, framebuffer, pAllocator);
        allocatedLoopResources.erase(framebuffer);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, device, framebuffer, pAllocator);
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
    // Check for null cases
    if (pRenderPass == nullptr || pRenderPass->IsNull())
    {
        return;
    }
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(renderPass))
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, device, renderPass, pAllocator);
    }
    else if (allocatedLoopResources.contains(renderPass))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, device, renderPass, pAllocator);
        allocatedLoopResources.erase(renderPass);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, device, renderPass, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewport(call_info, commandBuffer, firstViewport, viewportCount, pViewports);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissor(call_info, commandBuffer, firstScissor, scissorCount, pScissors);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineWidth(call_info, commandBuffer, lineWidth);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBias(call_info, commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetBlendConstants(call_info, commandBuffer, blendConstants);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBounds(call_info, commandBuffer, minDepthBounds, maxDepthBounds);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(call_info, commandBuffer, faceMask, compareMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(call_info, commandBuffer, faceMask, writeMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilReference(call_info, commandBuffer, faceMask, reference);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(call_info, commandBuffer, buffer, offset, indexType);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(call_info, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDraw(call_info, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexed(call_info, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirect(call_info, commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(call_info, commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(call_info, commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearAttachments(call_info, commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage(call_info, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass(call_info, commandBuffer, pRenderPassBegin, contents);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass(call_info, commandBuffer, contents);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass(call_info, commandBuffer);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDeviceMask(call_info, commandBuffer, deviceMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchBase(call_info, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    // Check for null cases
    if (pDescriptorUpdateTemplate == nullptr || pDescriptorUpdateTemplate->IsNull())
    {
        return;
    }
    format::HandleId handle = *pDescriptorUpdateTemplate->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(descriptorUpdateTemplate))
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, device, descriptorUpdateTemplate, pAllocator);
    }
    else if (allocatedLoopResources.contains(descriptorUpdateTemplate))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, device, descriptorUpdateTemplate, pAllocator);
        allocatedLoopResources.erase(descriptorUpdateTemplate);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, device, descriptorUpdateTemplate, pAllocator);
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
    // Check for null cases
    if (pYcbcrConversion == nullptr || pYcbcrConversion->IsNull())
    {
        return;
    }
    format::HandleId handle = *pYcbcrConversion->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(ycbcrConversion))
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, device, ycbcrConversion, pAllocator);
    }
    else if (allocatedLoopResources.contains(ycbcrConversion))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, device, ycbcrConversion, pAllocator);
        allocatedLoopResources.erase(ycbcrConversion);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, device, ycbcrConversion, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkResetQueryPool(call_info, device, queryPool, firstQuery, queryCount);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCount(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    // Check for null cases
    if (pRenderPass == nullptr || pRenderPass->IsNull())
    {
        return;
    }
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2(call_info, returnValue, device, pCreateInfo, pAllocator, pRenderPass);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(call_info, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass2(call_info, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass2(call_info, commandBuffer, pSubpassEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    // Check for null cases
    if (pPrivateDataSlot == nullptr || pPrivateDataSlot->IsNull())
    {
        return;
    }
    format::HandleId handle = *pPrivateDataSlot->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(privateDataSlot))
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, device, privateDataSlot, pAllocator);
    }
    else if (allocatedLoopResources.contains(privateDataSlot))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, device, privateDataSlot, pAllocator);
        allocatedLoopResources.erase(privateDataSlot);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, device, privateDataSlot, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(call_info, commandBuffer, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp2(call_info, commandBuffer, stage, queryPool, query);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2(call_info, commandBuffer, pCopyBufferInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage2(call_info, commandBuffer, pCopyImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(call_info, commandBuffer, pCopyBufferToImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(call_info, commandBuffer, pCopyImageToBufferInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent2(call_info, commandBuffer, event, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent2(call_info, commandBuffer, event, stageMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents2(call_info, commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage2(call_info, commandBuffer, pBlitImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage2(call_info, commandBuffer, pResolveImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRendering(call_info, commandBuffer, pRenderingInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCullMode(call_info, commandBuffer, cullMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFrontFace(call_info, commandBuffer, frontFace);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopology(call_info, commandBuffer, primitiveTopology);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWithCount(call_info, commandBuffer, viewportCount, pViewports);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissorWithCount(call_info, commandBuffer, scissorCount, pScissors);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2(call_info, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthTestEnable(call_info, commandBuffer, depthTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnable(call_info, commandBuffer, depthWriteEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthCompareOp(call_info, commandBuffer, depthCompareOp);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnable(call_info, commandBuffer, depthBoundsTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilTestEnable(call_info, commandBuffer, stencilTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilOp(call_info, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnable(call_info, commandBuffer, rasterizerDiscardEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnable(call_info, commandBuffer, depthBiasEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnable(call_info, commandBuffer, primitiveRestartEnable);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet(call_info, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2(call_info, commandBuffer, pBindDescriptorSetsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants2(call_info, commandBuffer, pPushConstantsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2(call_info, commandBuffer, pPushDescriptorSetInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStipple(call_info, commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2(call_info, commandBuffer, buffer, offset, size, indexType);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocations(call_info, commandBuffer, pLocationInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(call_info, commandBuffer, pInputAttachmentIndexInfo);
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(surface))
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, instance, surface, pAllocator);
    }
    else if (allocatedLoopResources.contains(surface))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, instance, surface, pAllocator);
        allocatedLoopResources.erase(surface);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, instance, surface, pAllocator);
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
    // Check for null cases
    if (pSwapchain == nullptr || pSwapchain->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSwapchain->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(swapchain))
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, device, swapchain, pAllocator);
    }
    else if (allocatedLoopResources.contains(swapchain))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, device, swapchain, pAllocator);
        allocatedLoopResources.erase(swapchain);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, device, swapchain, pAllocator);
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
    // Check for null cases
    if (pMode == nullptr || pMode->IsNull())
    {
        return;
    }
    format::HandleId handle = *pMode->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < swapchainCount; i++)
        {
            format::HandleId handle = pSwapchains->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(call_info, returnValue, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < swapchainCount; i++)
            {
                format::HandleId handle = pSwapchains->GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pVideoSession == nullptr || pVideoSession->IsNull())
    {
        return;
    }
    format::HandleId handle = *pVideoSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(videoSession))
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, device, videoSession, pAllocator);
    }
    else if (allocatedLoopResources.contains(videoSession))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, device, videoSession, pAllocator);
        allocatedLoopResources.erase(videoSession);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, device, videoSession, pAllocator);
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
    // Check for null cases
    if (pVideoSessionParameters == nullptr || pVideoSessionParameters->IsNull())
    {
        return;
    }
    format::HandleId handle = *pVideoSessionParameters->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(videoSessionParameters))
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, device, videoSessionParameters, pAllocator);
    }
    else if (allocatedLoopResources.contains(videoSessionParameters))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, device, videoSessionParameters, pAllocator);
        allocatedLoopResources.erase(videoSessionParameters);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, device, videoSessionParameters, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginVideoCodingKHR(call_info, commandBuffer, pBeginInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndVideoCodingKHR(call_info, commandBuffer, pEndCodingInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdControlVideoCodingKHR(call_info, commandBuffer, pCodingControlInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecodeVideoKHR(call_info, commandBuffer, pDecodeInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(call_info, commandBuffer, pRenderingInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderingKHR(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(call_info, commandBuffer, deviceMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(call_info, commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(call_info, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    // Check for null cases
    if (pDescriptorUpdateTemplate == nullptr || pDescriptorUpdateTemplate->IsNull())
    {
        return;
    }
    format::HandleId handle = *pDescriptorUpdateTemplate->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(descriptorUpdateTemplate))
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, device, descriptorUpdateTemplate, pAllocator);
    }
    else if (allocatedLoopResources.contains(descriptorUpdateTemplate))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, device, descriptorUpdateTemplate, pAllocator);
        allocatedLoopResources.erase(descriptorUpdateTemplate);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, device, descriptorUpdateTemplate, pAllocator);
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
    // Check for null cases
    if (pRenderPass == nullptr || pRenderPass->IsNull())
    {
        return;
    }
    format::HandleId handle = *pRenderPass->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(call_info, returnValue, device, pCreateInfo, pAllocator, pRenderPass);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(call_info, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(call_info, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(call_info, commandBuffer, pSubpassEndInfo);
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
    // Check for null cases
    if (pYcbcrConversion == nullptr || pYcbcrConversion->IsNull())
    {
        return;
    }
    format::HandleId handle = *pYcbcrConversion->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(ycbcrConversion))
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, device, ycbcrConversion, pAllocator);
    }
    else if (allocatedLoopResources.contains(ycbcrConversion))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, device, ycbcrConversion, pAllocator);
        allocatedLoopResources.erase(ycbcrConversion);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, device, ycbcrConversion, pAllocator);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateKHR(call_info, commandBuffer, pFragmentSize, combinerOps);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(call_info, commandBuffer, pLocationInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, commandBuffer, pInputAttachmentIndexInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    // Check for null cases
    if (pDeferredOperation == nullptr || pDeferredOperation->IsNull())
    {
        return;
    }
    format::HandleId handle = *pDeferredOperation->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(operation))
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, device, operation, pAllocator);
    }
    else if (allocatedLoopResources.contains(operation))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, device, operation, pAllocator);
        allocatedLoopResources.erase(operation);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, device, operation, pAllocator);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEncodeVideoKHR(call_info, commandBuffer, pEncodeInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(call_info, commandBuffer, event, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent2KHR(call_info, commandBuffer, event, stageMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(call_info, commandBuffer, eventCount, pEvents, pDependencyInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(call_info, commandBuffer, pDependencyInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp2KHR(call_info, commandBuffer, stage, queryPool, query);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindIndexBuffer3InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer3KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    StructPointerDecoder<Decoded_VkBindVertexBuffer3InfoKHR>* pBindingInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers3KHR(call_info, commandBuffer, firstBinding, bindingCount, pBindingInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirect2KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect2KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchIndirect2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchIndirect2KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryInfoKHR>* pCopyMemoryInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryKHR(call_info, commandBuffer, pCopyMemoryInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR>* pCopyMemoryInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageKHR(call_info, commandBuffer, pCopyMemoryInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyDeviceMemoryImageInfoKHR>* pCopyMemoryInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToMemoryKHR(call_info, commandBuffer, pCopyMemoryInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdateMemoryKHR(call_info, commandBuffer, pDstRange, dstFlags, dataSize, pData);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    uint32_t                                    data)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdFillMemoryKHR(call_info, commandBuffer, pDstRange, dstFlags, data);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkQueryResultFlags                          queryResultFlags)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(call_info, commandBuffer, queryPool, firstQuery, queryCount, pDstRange, dstFlags, queryResultFlags);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCount2KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfo2EXT>* pConditionalRenderingBegin)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginConditionalRendering2EXT(call_info, commandBuffer, pConditionalRenderingBegin);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pBindingInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(call_info, commandBuffer, firstBinding, bindingCount, pBindingInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginTransformFeedback2EXT(call_info, commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndTransformFeedback2EXT(call_info, commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    StructPointerDecoder<Decoded_VkBindTransformFeedbackBuffer2InfoEXT>* pCounterInfo,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCount2EXT(call_info, commandBuffer, instanceCount, firstInstance, pCounterInfo, counterOffset, vertexStride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirect2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDrawIndirectCount2InfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkMemoryMarkerInfoAMD>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteMarkerToMemoryAMD(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(call_info, commandBuffer, pCopyBufferInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage2KHR(call_info, commandBuffer, pCopyImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(call_info, commandBuffer, pCopyBufferToImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(call_info, commandBuffer, pCopyImageToBufferInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage2KHR(call_info, commandBuffer, pBlitImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage2KHR(call_info, commandBuffer, pResolveImageInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysIndirect2KHR(call_info, commandBuffer, indirectDeviceAddress);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2KHR(call_info, commandBuffer, buffer, offset, size, indexType);
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(pipelineBinary))
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, device, pipelineBinary, pAllocator);
    }
    else if (allocatedLoopResources.contains(pipelineBinary))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, device, pipelineBinary, pAllocator);
        allocatedLoopResources.erase(pipelineBinary);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, device, pipelineBinary, pAllocator);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleKHR(call_info, commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2KHR(call_info, commandBuffer, pBindDescriptorSetsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants2KHR(call_info, commandBuffer, pPushConstantsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2KHR(call_info, commandBuffer, pPushDescriptorSetInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(call_info, commandBuffer, pSetDescriptorBufferOffsetsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR>* pCopyMemoryIndirectInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryIndirectKHR(call_info, commandBuffer, pCopyMemoryIndirectInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR>* pCopyMemoryToImageIndirectInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(call_info, commandBuffer, pCopyMemoryToImageIndirectInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering2KHR(call_info, commandBuffer, pRenderingEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    // Check for null cases
    if (pCallback == nullptr || pCallback->IsNull())
    {
        return;
    }
    format::HandleId handle = *pCallback->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(callback))
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, instance, callback, pAllocator);
    }
    else if (allocatedLoopResources.contains(callback))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, instance, callback, pAllocator);
        allocatedLoopResources.erase(callback);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, instance, callback, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(call_info, commandBuffer, pMarkerInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(call_info, commandBuffer, pMarkerInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(call_info, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(call_info, commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(call_info, commandBuffer, queryPool, query, flags, index);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(call_info, commandBuffer, queryPool, query, index);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(call_info, commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateViSurfaceNN(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(call_info, commandBuffer, pConditionalRenderingBegin);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(call_info, commandBuffer, firstViewport, viewportCount, pViewportWScalings);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(call_info, commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(call_info, commandBuffer, discardRectangleEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleModeEXT(call_info, commandBuffer, discardRectangleMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(call_info, commandBuffer, pLabelInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(call_info, commandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(call_info, commandBuffer, pLabelInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    // Check for null cases
    if (pMessenger == nullptr || pMessenger->IsNull())
    {
        return;
    }
    format::HandleId handle = *pMessenger->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(messenger))
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, instance, messenger, pAllocator);
    }
    else if (allocatedLoopResources.contains(messenger))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, instance, messenger, pAllocator);
        allocatedLoopResources.erase(messenger);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, instance, messenger, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(call_info, commandBuffer, pSampleLocationsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    // Check for null cases
    if (pValidationCache == nullptr || pValidationCache->IsNull())
    {
        return;
    }
    format::HandleId handle = *pValidationCache->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(validationCache))
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, device, validationCache, pAllocator);
    }
    else if (allocatedLoopResources.contains(validationCache))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, device, validationCache, pAllocator);
        allocatedLoopResources.erase(validationCache);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, device, validationCache, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(call_info, commandBuffer, imageView, imageLayout);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(call_info, commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(call_info, commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure)
{
    // Check for null cases
    if (pAccelerationStructure == nullptr || pAccelerationStructure->IsNull())
    {
        return;
    }
    format::HandleId handle = *pAccelerationStructure->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
    format::HandleId                            instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    format::HandleId                            dst,
    format::HandleId                            src,
    format::HandleId                            scratch,
    VkDeviceSize                                scratchOffset)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(call_info, commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(call_info, commandBuffer, dst, src, mode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    format::HandleId                            missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    format::HandleId                            hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    format::HandleId                            callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysNV(call_info, commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
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
            format::HandleId handle = pPipelines->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
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
                format::HandleId handle = pPipelines->GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(call_info, commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(call_info, commandBuffer, stage, dstBuffer, dstOffset, marker);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(call_info, commandBuffer, taskCount, firstTask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(call_info, commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorEnableNV(call_info, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(call_info, commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(call_info, commandBuffer, pCheckpointMarker);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(call_info, returnValue, commandBuffer, pMarkerInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(call_info, returnValue, commandBuffer, pMarkerInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(call_info, returnValue, commandBuffer, pOverrideInfo);
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(call_info, commandBuffer, lineStippleFactor, lineStipplePattern);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    if (getFrameLoopInfo().IsLooping())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkResetQueryPoolEXT(call_info, device, queryPool, firstQuery, queryCount);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCullModeEXT(call_info, commandBuffer, cullMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFrontFaceEXT(call_info, commandBuffer, frontFace);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopologyEXT(call_info, commandBuffer, primitiveTopology);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWithCountEXT(call_info, commandBuffer, viewportCount, pViewports);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissorWithCountEXT(call_info, commandBuffer, scissorCount, pScissors);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2EXT(call_info, commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthTestEnableEXT(call_info, commandBuffer, depthTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnableEXT(call_info, commandBuffer, depthWriteEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthCompareOpEXT(call_info, commandBuffer, depthCompareOp);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(call_info, commandBuffer, depthBoundsTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilTestEnableEXT(call_info, commandBuffer, stencilTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilOpEXT(call_info, commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(call_info, commandBuffer, pGeneratedCommandsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(call_info, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindPipelineShaderGroupNV(call_info, commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    // Check for null cases
    if (pIndirectCommandsLayout == nullptr || pIndirectCommandsLayout->IsNull())
    {
        return;
    }
    format::HandleId handle = *pIndirectCommandsLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(indirectCommandsLayout))
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, device, indirectCommandsLayout, pAllocator);
    }
    else if (allocatedLoopResources.contains(indirectCommandsLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, device, indirectCommandsLayout, pAllocator);
        allocatedLoopResources.erase(indirectCommandsLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, device, indirectCommandsLayout, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBias2EXT(call_info, commandBuffer, pDepthBiasInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    // Check for null cases
    if (pPrivateDataSlot == nullptr || pPrivateDataSlot->IsNull())
    {
        return;
    }
    format::HandleId handle = *pPrivateDataSlot->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(privateDataSlot))
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, device, privateDataSlot, pAllocator);
    }
    else if (allocatedLoopResources.contains(privateDataSlot))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, device, privateDataSlot, pAllocator);
        allocatedLoopResources.erase(privateDataSlot);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, device, privateDataSlot, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM>* pDispatchTileInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchTileQCOM(call_info, commandBuffer, pDispatchTileInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM>* pPerTileBeginInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginPerTileExecutionQCOM(call_info, commandBuffer, pPerTileBeginInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM>* pPerTileEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndPerTileExecutionQCOM(call_info, commandBuffer, pPerTileEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    bufferCount,
    StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT>* pBindingInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBuffersEXT(call_info, commandBuffer, bufferCount, pBindingInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    PointerDecoder<uint32_t>*                   pBufferIndices,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(call_info, commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(call_info, commandBuffer, pipelineBindPoint, layout, set);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(call_info, commandBuffer, shadingRate, combinerOps);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetVertexInputEXT(call_info, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindInvocationMaskHUAWEI(call_info, commandBuffer, imageView, imageLayout);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPatchControlPointsEXT(call_info, commandBuffer, patchControlPoints);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(call_info, commandBuffer, rasterizerDiscardEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnableEXT(call_info, commandBuffer, depthBiasEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLogicOpEXT(call_info, commandBuffer, logicOp);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(call_info, commandBuffer, primitiveRestartEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    // Check for null cases
    if (pSurface == nullptr || pSurface->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSurface->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(call_info, returnValue, instance, pCreateInfo, pAllocator, pSurface);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorWriteEnableEXT(call_info, commandBuffer, attachmentCount, pColorWriteEnables);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMultiEXT(call_info, commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMultiIndexedEXT(call_info, commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    // Check for null cases
    if (pMicromap == nullptr || pMicromap->IsNull())
    {
        return;
    }
    format::HandleId handle = *pMicromap->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(micromap))
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, device, micromap, pAllocator);
    }
    else if (allocatedLoopResources.contains(micromap))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, device, micromap, pAllocator);
        allocatedLoopResources.erase(micromap);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, device, micromap, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildMicromapsEXT(call_info, commandBuffer, infoCount, pInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMicromapEXT(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMicromapToMemoryEXT(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToMicromapEXT(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(call_info, commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawClusterHUAWEI(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(call_info, commandBuffer, buffer, offset);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchParametersARM>* pDispatchParameters)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDispatchParametersARM(call_info, commandBuffer, pDispatchParameters);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(call_info, commandBuffer, pipelineBindPoint, pipeline);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClampEnableEXT(call_info, commandBuffer, depthClampEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPolygonModeEXT(call_info, commandBuffer, polygonMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizationSamplesEXT(call_info, commandBuffer, rasterizationSamples);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleMaskEXT(call_info, commandBuffer, samples, pSampleMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(call_info, commandBuffer, alphaToCoverageEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAlphaToOneEnableEXT(call_info, commandBuffer, alphaToOneEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLogicOpEnableEXT(call_info, commandBuffer, logicOpEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendEnableEXT(call_info, commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendEquationEXT(call_info, commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorWriteMaskEXT(call_info, commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetTessellationDomainOriginEXT(call_info, commandBuffer, domainOrigin);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizationStreamEXT(call_info, commandBuffer, rasterizationStream);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(call_info, commandBuffer, conservativeRasterizationMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, commandBuffer, extraPrimitiveOverestimationSize);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClipEnableEXT(call_info, commandBuffer, depthClipEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEnableEXT(call_info, commandBuffer, sampleLocationsEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendAdvancedEXT(call_info, commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetProvokingVertexModeEXT(call_info, commandBuffer, provokingVertexMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineRasterizationModeEXT(call_info, commandBuffer, lineRasterizationMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleEnableEXT(call_info, commandBuffer, stippledLineEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, commandBuffer, negativeOneToOne);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWScalingEnableNV(call_info, commandBuffer, viewportWScalingEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportSwizzleNV(call_info, commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageToColorEnableNV(call_info, commandBuffer, coverageToColorEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageToColorLocationNV(call_info, commandBuffer, coverageToColorLocation);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationModeNV(call_info, commandBuffer, coverageModulationMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(call_info, commandBuffer, coverageModulationTableEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableNV(call_info, commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetShadingRateImageEnableNV(call_info, commandBuffer, shadingRateImageEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, commandBuffer, representativeFragmentTestEnable);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageReductionModeNV(call_info, commandBuffer, coverageReductionMode);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    // Check for null cases
    if (pSession == nullptr || pSession->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(session))
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, device, session, pAllocator);
    }
    else if (allocatedLoopResources.contains(session))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, device, session, pAllocator);
        allocatedLoopResources.erase(session);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, device, session, pAllocator);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdOpticalFlowExecuteNV(call_info, commandBuffer, session, pExecuteInfo);
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
            format::HandleId handle = pShaders->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateShadersEXT(call_info, returnValue, device, createInfoCount, pCreateInfos, pAllocator, pShaders);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < createInfoCount; i++)
            {
                format::HandleId handle = pShaders->GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(shader))
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, device, shader, pAllocator);
    }
    else if (allocatedLoopResources.contains(shader))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, device, shader, pAllocator);
        allocatedLoopResources.erase(shader);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, device, shader, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindShadersEXT(call_info, commandBuffer, stageCount, pStages, pShaders);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClampRangeEXT(call_info, commandBuffer, depthClampMode, pDepthClampRange);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV>* pInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(call_info, commandBuffer, infoCount, pInfos);
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
            format::HandleId handle = pPipelines->GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
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
                format::HandleId handle = pPipelines->GetPointer()[i];
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
    // Check for null cases
    if (pSession == nullptr || pSession->IsNull())
    {
        return;
    }
    format::HandleId handle = *pSession->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(session))
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, device, session, pAllocator);
    }
    else if (allocatedLoopResources.contains(session))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, device, session, pAllocator);
        allocatedLoopResources.erase(session);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, device, session, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchDataGraphARM(call_info, commandBuffer, session, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, commandBuffer, aspectMask);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM>* pTileMemoryBindInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTileMemoryQCOM(call_info, commandBuffer, pTileMemoryBindInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT>* pDecompressMemoryInfoEXT)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecompressMemoryEXT(call_info, commandBuffer, pDecompressMemoryInfoEXT);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkMemoryDecompressionMethodFlagsEXT         decompressionMethod,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    maxDecompressionCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(call_info, commandBuffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV>* pBuildInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(call_info, commandBuffer, pBuildInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
    format::HandleId                            stateCommandBuffer)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(call_info, commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(call_info, commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutEXT>* pIndirectCommandsLayout)
{
    // Check for null cases
    if (pIndirectCommandsLayout == nullptr || pIndirectCommandsLayout->IsNull())
    {
        return;
    }
    format::HandleId handle = *pIndirectCommandsLayout->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(indirectCommandsLayout))
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, device, indirectCommandsLayout, pAllocator);
    }
    else if (allocatedLoopResources.contains(indirectCommandsLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, device, indirectCommandsLayout, pAllocator);
        allocatedLoopResources.erase(indirectCommandsLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, device, indirectCommandsLayout, pAllocator);
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
    // Check for null cases
    if (pIndirectExecutionSet == nullptr || pIndirectExecutionSet->IsNull())
    {
        return;
    }
    format::HandleId handle = *pIndirectExecutionSet->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(indirectExecutionSet))
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, device, indirectExecutionSet, pAllocator);
    }
    else if (allocatedLoopResources.contains(indirectExecutionSet))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, device, indirectExecutionSet, pAllocator);
        allocatedLoopResources.erase(indirectExecutionSet);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, device, indirectExecutionSet, pAllocator);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering2EXT(call_info, commandBuffer, pRenderingEndInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT>* pBeginCustomResolveInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginCustomResolveEXT(call_info, commandBuffer, pBeginCustomResolveInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV>* pParameters)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(call_info, commandBuffer, pParameters);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    primitiveRestartIndex)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(call_info, commandBuffer, primitiveRestartIndex);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    // Check for null cases
    if (pAccelerationStructure == nullptr || pAccelerationStructure->IsNull())
    {
        return;
    }
    format::HandleId handle = *pAccelerationStructure->GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresKHR(call_info, commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureKHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, commandBuffer, pInfo);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysKHR(call_info, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysIndirectKHR(call_info, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, commandBuffer, pipelineStackSize);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksEXT(call_info, commandBuffer, groupCountX, groupCountY, groupCountZ);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(call_info, commandBuffer, buffer, offset, drawCount, stride);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (ShouldIgnoreRecordingCommand(commandBuffer))
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
