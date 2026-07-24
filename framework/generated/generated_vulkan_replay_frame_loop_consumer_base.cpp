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
    args::CreateInstance&                       args)
{
    // Check for null cases
    if (args.pInstance.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pInstance.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateInstance(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    args::DestroyInstance&                      args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.instance is in allocatedLoopResources

    // Call Process_vkDestroyInstance if:
    //    We are not looping
    //    We are looping and args.instance is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.instance))
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.instance))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, args);
        allocatedLoopResources.erase(args.instance);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyInstance(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    args::CreateDevice&                         args)
{
    // Check for null cases
    if (args.pDevice.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pDevice.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDevice(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    args::DestroyDevice&                        args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.device is in allocatedLoopResources

    // Call Process_vkDestroyDevice if:
    //    We are not looping
    //    We are looping and args.device is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.device))
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.device))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, args);
        allocatedLoopResources.erase(args.device);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDevice(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    args::AllocateMemory&                       args)
{
    // Check for null cases
    if (args.pMemory.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pMemory.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkAllocateMemory(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    args::FreeMemory&                           args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.memory is in allocatedLoopResources

    // Call Process_vkFreeMemory if:
    //    We are not looping
    //    We are looping and args.memory is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.memory))
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.memory))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);
        allocatedLoopResources.erase(args.memory);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkFreeMemory(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory&                     args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory&                      args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    args::QueueBindSparse&                      args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkQueueBindSparse(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    args::CreateFence&                          args)
{
    // Check for null cases
    if (args.pFence.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pFence.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateFence(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    args::DestroyFence&                         args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.fence is in allocatedLoopResources

    // Call Process_vkDestroyFence if:
    //    We are not looping
    //    We are looping and args.fence is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.fence))
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.fence))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, args);
        allocatedLoopResources.erase(args.fence);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyFence(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    args::CreateSemaphore&                      args)
{
    // Check for null cases
    if (args.pSemaphore.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSemaphore.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSemaphore(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    args::DestroySemaphore&                     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.semaphore is in allocatedLoopResources

    // Call Process_vkDestroySemaphore if:
    //    We are not looping
    //    We are looping and args.semaphore is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.semaphore))
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.semaphore))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, args);
        allocatedLoopResources.erase(args.semaphore);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySemaphore(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    args::CreateQueryPool&                      args)
{
    // Check for null cases
    if (args.pQueryPool.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pQueryPool.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateQueryPool(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    args::DestroyQueryPool&                     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.queryPool is in allocatedLoopResources

    // Call Process_vkDestroyQueryPool if:
    //    We are not looping
    //    We are looping and args.queryPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.queryPool))
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.queryPool))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, args);
        allocatedLoopResources.erase(args.queryPool);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyQueryPool(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    args::CreateBuffer&                         args)
{
    // Check for null cases
    if (args.pBuffer.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pBuffer.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateBuffer(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyBuffer&                        args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.buffer is in allocatedLoopResources

    // Call Process_vkDestroyBuffer if:
    //    We are not looping
    //    We are looping and args.buffer is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.buffer))
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.buffer))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, args);
        allocatedLoopResources.erase(args.buffer);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyBuffer(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    args::CreateImage&                          args)
{
    // Check for null cases
    if (args.pImage.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pImage.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImage(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    args::DestroyImage&                         args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.image is in allocatedLoopResources

    // Call Process_vkDestroyImage if:
    //    We are not looping
    //    We are looping and args.image is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.image))
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.image))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, args);
        allocatedLoopResources.erase(args.image);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyImage(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    args::CreateImageView&                      args)
{
    // Check for null cases
    if (args.pView.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pView.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImageView(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    args::DestroyImageView&                     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.imageView is in allocatedLoopResources

    // Call Process_vkDestroyImageView if:
    //    We are not looping
    //    We are looping and args.imageView is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.imageView))
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.imageView))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, args);
        allocatedLoopResources.erase(args.imageView);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyImageView(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    args::DestroyCommandPool&                   args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.commandPool is in allocatedLoopResources

    // Call Process_vkDestroyCommandPool if:
    //    We are not looping
    //    We are looping and args.commandPool is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.commandPool))
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.commandPool))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, args);
        allocatedLoopResources.erase(args.commandPool);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyCommandPool(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::AllocateCommandBuffers&               args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkAllocateCommandBuffers(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    args::FreeCommandBuffers&                   args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkFreeCommandBuffers(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    args::CreateEvent&                          args)
{
    // Check for null cases
    if (args.pEvent.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pEvent.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateEvent(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    args::DestroyEvent&                         args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.event is in allocatedLoopResources

    // Call Process_vkDestroyEvent if:
    //    We are not looping
    //    We are looping and args.event is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.event))
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.event))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, args);
        allocatedLoopResources.erase(args.event);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyEvent(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    args::CreateBufferView&                     args)
{
    // Check for null cases
    if (args.pView.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pView.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateBufferView(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    args::DestroyBufferView&                    args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.bufferView is in allocatedLoopResources

    // Call Process_vkDestroyBufferView if:
    //    We are not looping
    //    We are looping and args.bufferView is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.bufferView))
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.bufferView))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, args);
        allocatedLoopResources.erase(args.bufferView);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyBufferView(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    args::CreateShaderModule&                   args)
{
    // Check for null cases
    if (args.pShaderModule.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pShaderModule.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateShaderModule(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderModule&                  args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.shaderModule is in allocatedLoopResources

    // Call Process_vkDestroyShaderModule if:
    //    We are not looping
    //    We are looping and args.shaderModule is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.shaderModule))
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.shaderModule))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, args);
        allocatedLoopResources.erase(args.shaderModule);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyShaderModule(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineCache&                  args)
{
    // Check for null cases
    if (args.pPipelineCache.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pPipelineCache.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePipelineCache(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineCache&                 args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.pipelineCache is in allocatedLoopResources

    // Call Process_vkDestroyPipelineCache if:
    //    We are not looping
    //    We are looping and args.pipelineCache is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.pipelineCache))
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.pipelineCache))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, args);
        allocatedLoopResources.erase(args.pipelineCache);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineCache(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    args::MergePipelineCaches&                  args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMergePipelineCaches(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    args::CreateComputePipelines&               args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.createInfoCount; i++)
        {
            format::HandleId handle = args.pPipelines.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateComputePipelines(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.createInfoCount; i++)
            {
                format::HandleId handle = args.pPipelines.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    args::DestroyPipeline&                      args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.pipeline is in allocatedLoopResources

    // Call Process_vkDestroyPipeline if:
    //    We are not looping
    //    We are looping and args.pipeline is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.pipeline))
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.pipeline))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, args);
        allocatedLoopResources.erase(args.pipeline);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipeline(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineLayout&                 args)
{
    // Check for null cases
    if (args.pPipelineLayout.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pPipelineLayout.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePipelineLayout(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineLayout&                args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.pipelineLayout is in allocatedLoopResources

    // Call Process_vkDestroyPipelineLayout if:
    //    We are not looping
    //    We are looping and args.pipelineLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.pipelineLayout))
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.pipelineLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, args);
        allocatedLoopResources.erase(args.pipelineLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineLayout(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    args::CreateSampler&                        args)
{
    // Check for null cases
    if (args.pSampler.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSampler.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSampler(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    args::DestroySampler&                       args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.sampler is in allocatedLoopResources

    // Call Process_vkDestroySampler if:
    //    We are not looping
    //    We are looping and args.sampler is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.sampler))
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.sampler))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, args);
        allocatedLoopResources.erase(args.sampler);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySampler(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorSetLayout&            args)
{
    // Check for null cases
    if (args.pSetLayout.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSetLayout.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorSetLayout(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorSetLayout&           args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.descriptorSetLayout is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorSetLayout if:
    //    We are not looping
    //    We are looping and args.descriptorSetLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.descriptorSetLayout))
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.descriptorSetLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, args);
        allocatedLoopResources.erase(args.descriptorSetLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorSetLayout(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorPool&                 args)
{
    // Check for null cases
    if (args.pDescriptorPool.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pDescriptorPool.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorPool(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    args::CreateGraphicsPipelines&              args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.createInfoCount; i++)
        {
            format::HandleId handle = args.pPipelines.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateGraphicsPipelines(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.createInfoCount; i++)
            {
                format::HandleId handle = args.pPipelines.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    args::CreateFramebuffer&                    args)
{
    // Check for null cases
    if (args.pFramebuffer.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pFramebuffer.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateFramebuffer(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    args::DestroyFramebuffer&                   args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.framebuffer is in allocatedLoopResources

    // Call Process_vkDestroyFramebuffer if:
    //    We are not looping
    //    We are looping and args.framebuffer is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.framebuffer))
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.framebuffer))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, args);
        allocatedLoopResources.erase(args.framebuffer);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyFramebuffer(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass&                     args)
{
    // Check for null cases
    if (args.pRenderPass.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pRenderPass.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    args::DestroyRenderPass&                    args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.renderPass is in allocatedLoopResources

    // Call Process_vkDestroyRenderPass if:
    //    We are not looping
    //    We are looping and args.renderPass is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.renderPass))
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.renderPass))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, args);
        allocatedLoopResources.erase(args.renderPass);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyRenderPass(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2&                    args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2&                     args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplate&       args)
{
    // Check for null cases
    if (args.pDescriptorUpdateTemplate.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pDescriptorUpdateTemplate.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplate(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplate&      args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.descriptorUpdateTemplate is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorUpdateTemplate if:
    //    We are not looping
    //    We are looping and args.descriptorUpdateTemplate is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.descriptorUpdateTemplate))
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.descriptorUpdateTemplate))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, args);
        allocatedLoopResources.erase(args.descriptorUpdateTemplate);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplate(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversion&         args)
{
    // Check for null cases
    if (args.pYcbcrConversion.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pYcbcrConversion.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversion(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversion&        args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.ycbcrConversion is in allocatedLoopResources

    // Call Process_vkDestroySamplerYcbcrConversion if:
    //    We are not looping
    //    We are looping and args.ycbcrConversion is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.ycbcrConversion))
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.ycbcrConversion))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, args);
        allocatedLoopResources.erase(args.ycbcrConversion);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversion(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2&                    args)
{
    // Check for null cases
    if (args.pRenderPass.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pRenderPass.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlot&                args)
{
    // Check for null cases
    if (args.pPrivateDataSlot.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pPrivateDataSlot.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePrivateDataSlot(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlot&               args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.privateDataSlot is in allocatedLoopResources

    // Call Process_vkDestroyPrivateDataSlot if:
    //    We are not looping
    //    We are looping and args.privateDataSlot is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.privateDataSlot))
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.privateDataSlot))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, args);
        allocatedLoopResources.erase(args.privateDataSlot);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlot(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMapMemory2(
    const ApiCallInfo&                          call_info,
    args::MapMemory2&                           args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMapMemory2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkUnmapMemory2(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2&                         args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkUnmapMemory2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkTransitionImageLayout(
    const ApiCallInfo&                          call_info,
    args::TransitionImageLayout&                args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkTransitionImageLayout(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySurfaceKHR&                    args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.surface is in allocatedLoopResources

    // Call Process_vkDestroySurfaceKHR if:
    //    We are not looping
    //    We are looping and args.surface is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.surface))
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.surface))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, args);
        allocatedLoopResources.erase(args.surface);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySurfaceKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSwapchainKHR&                   args)
{
    // Check for null cases
    if (args.pSwapchain.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSwapchain.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSwapchainKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySwapchainKHR&                  args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.swapchain is in allocatedLoopResources

    // Call Process_vkDestroySwapchainKHR if:
    //    We are not looping
    //    We are looping and args.swapchain is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.swapchain))
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.swapchain))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, args);
        allocatedLoopResources.erase(args.swapchain);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySwapchainKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayModeKHR&                 args)
{
    // Check for null cases
    if (args.pMode.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pMode.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDisplayModeKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDisplayPlaneSurfaceKHR&         args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSharedSwapchainsKHR&            args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.swapchainCount; i++)
        {
            format::HandleId handle = args.pSwapchains.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateSharedSwapchainsKHR(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.swapchainCount; i++)
            {
                format::HandleId handle = args.pSwapchains.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXlibSurfaceKHR&                 args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateXlibSurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateXcbSurfaceKHR&                  args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateXcbSurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWaylandSurfaceKHR&              args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateWaylandSurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAndroidSurfaceKHR&              args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAndroidSurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    args::CreateWin32SurfaceKHR&                args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateWin32SurfaceKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionKHR&                args)
{
    // Check for null cases
    if (args.pVideoSession.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pVideoSession.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateVideoSessionKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionKHR&               args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.videoSession is in allocatedLoopResources

    // Call Process_vkDestroyVideoSessionKHR if:
    //    We are not looping
    //    We are looping and args.videoSession is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.videoSession))
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.videoSession))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, args);
        allocatedLoopResources.erase(args.videoSession);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::BindVideoSessionMemoryKHR&            args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindVideoSessionMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::CreateVideoSessionParametersKHR&      args)
{
    // Check for null cases
    if (args.pVideoSessionParameters.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pVideoSessionParameters.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateVideoSessionParametersKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyVideoSessionParametersKHR&     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.videoSessionParameters is in allocatedLoopResources

    // Call Process_vkDestroyVideoSessionParametersKHR if:
    //    We are not looping
    //    We are looping and args.videoSessionParameters is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.videoSessionParameters))
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.videoSessionParameters))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, args);
        allocatedLoopResources.erase(args.videoSessionParameters);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyVideoSessionParametersKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportSemaphoreFdKHR&                 args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkImportSemaphoreFdKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDescriptorUpdateTemplateKHR&    args)
{
    // Check for null cases
    if (args.pDescriptorUpdateTemplate.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pDescriptorUpdateTemplate.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDescriptorUpdateTemplateKHR&   args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.descriptorUpdateTemplate is in allocatedLoopResources

    // Call Process_vkDestroyDescriptorUpdateTemplateKHR if:
    //    We are not looping
    //    We are looping and args.descriptorUpdateTemplate is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.descriptorUpdateTemplate))
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.descriptorUpdateTemplate))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, args);
        allocatedLoopResources.erase(args.descriptorUpdateTemplate);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CreateRenderPass2KHR&                 args)
{
    // Check for null cases
    if (args.pRenderPass.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pRenderPass.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateRenderPass2KHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    args::ImportFenceFdKHR&                     args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkImportFenceFdKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::CreateSamplerYcbcrConversionKHR&      args)
{
    // Check for null cases
    if (args.pYcbcrConversion.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pYcbcrConversion.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateSamplerYcbcrConversionKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    args::DestroySamplerYcbcrConversionKHR&     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.ycbcrConversion is in allocatedLoopResources

    // Call Process_vkDestroySamplerYcbcrConversionKHR if:
    //    We are not looping
    //    We are looping and args.ycbcrConversion is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.ycbcrConversion))
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.ycbcrConversion))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, args);
        allocatedLoopResources.erase(args.ycbcrConversion);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroySamplerYcbcrConversionKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindBufferMemory2KHR&                 args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindBufferMemory2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::BindImageMemory2KHR&                  args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindImageMemory2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::CreateDeferredOperationKHR&           args)
{
    // Check for null cases
    if (args.pDeferredOperation.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pDeferredOperation.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDeferredOperationKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyDeferredOperationKHR&          args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.operation is in allocatedLoopResources

    // Call Process_vkDestroyDeferredOperationKHR if:
    //    We are not looping
    //    We are looping and args.operation is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.operation))
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.operation))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, args);
        allocatedLoopResources.erase(args.operation);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDeferredOperationKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::MapMemory2KHR&                        args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkMapMemory2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    args::UnmapMemory2KHR&                      args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkUnmapMemory2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePipelineBinariesKHR(
    const ApiCallInfo&                          call_info,
    args::CreatePipelineBinariesKHR&            args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCreatePipelineBinariesKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPipelineBinaryKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyPipelineBinaryKHR&             args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.pipelineBinary is in allocatedLoopResources

    // Call Process_vkDestroyPipelineBinaryKHR if:
    //    We are not looping
    //    We are looping and args.pipelineBinary is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.pipelineBinary))
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.pipelineBinary))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, args);
        allocatedLoopResources.erase(args.pipelineBinary);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPipelineBinaryKHR(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseCapturedPipelineDataKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseCapturedPipelineDataKHR&       args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseCapturedPipelineDataKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesKHR&            args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseSwapchainImagesKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugReportCallbackEXT&         args)
{
    // Check for null cases
    if (args.pCallback.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pCallback.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDebugReportCallbackEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugReportCallbackEXT&        args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.callback is in allocatedLoopResources

    // Call Process_vkDestroyDebugReportCallbackEXT if:
    //    We are not looping
    //    We are looping and args.callback is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.callback))
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.callback))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, args);
        allocatedLoopResources.erase(args.callback);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDebugReportCallbackEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    args::CreateStreamDescriptorSurfaceGGP&     args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    args::CreateViSurfaceNN&                    args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateViSurfaceNN(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseDisplayEXT&                    args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseDisplayEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDeviceEventEXT&               args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkRegisterDeviceEventEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    args::RegisterDisplayEventEXT&              args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkRegisterDisplayEventEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateIOSSurfaceMVK&                  args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIOSSurfaceMVK(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    args::CreateMacOSSurfaceMVK&                args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMacOSSurfaceMVK(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDebugUtilsMessengerEXT&         args)
{
    // Check for null cases
    if (args.pMessenger.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pMessenger.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDebugUtilsMessengerEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyDebugUtilsMessengerEXT&        args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.messenger is in allocatedLoopResources

    // Call Process_vkDestroyDebugUtilsMessengerEXT if:
    //    We are not looping
    //    We are looping and args.messenger is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.messenger))
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.messenger))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, args);
        allocatedLoopResources.erase(args.messenger);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDebugUtilsMessengerEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::CreateValidationCacheEXT&             args)
{
    // Check for null cases
    if (args.pValidationCache.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pValidationCache.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateValidationCacheEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyValidationCacheEXT&            args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.validationCache is in allocatedLoopResources

    // Call Process_vkDestroyValidationCacheEXT if:
    //    We are not looping
    //    We are looping and args.validationCache is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.validationCache))
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.validationCache))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, args);
        allocatedLoopResources.erase(args.validationCache);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyValidationCacheEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureNV&        args)
{
    // Check for null cases
    if (args.pAccelerationStructure.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pAccelerationStructure.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAccelerationStructureNV(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureNV&       args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkDestroyAccelerationStructureNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    args::BindAccelerationStructureMemoryNV&    args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindAccelerationStructureMemoryNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    args::CreateRayTracingPipelinesNV&          args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.createInfoCount; i++)
        {
            format::HandleId handle = args.pPipelines.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateRayTracingPipelinesNV(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.createInfoCount; i++)
            {
                format::HandleId handle = args.pPipelines.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    args::ReleasePerformanceConfigurationINTEL& args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleasePerformanceConfigurationINTEL(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    args::CreateImagePipeSurfaceFUCHSIA&        args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMetalSurfaceEXT&                args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMetalSurfaceEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseFullScreenExclusiveModeEXT&    args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateHeadlessSurfaceEXT&             args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateHeadlessSurfaceEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    args::ReleaseSwapchainImagesEXT&            args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkReleaseSwapchainImagesEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutNV&       args)
{
    // Check for null cases
    if (args.pIndirectCommandsLayout.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pIndirectCommandsLayout.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutNV(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutNV&      args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.indirectCommandsLayout is in allocatedLoopResources

    // Call Process_vkDestroyIndirectCommandsLayoutNV if:
    //    We are not looping
    //    We are looping and args.indirectCommandsLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.indirectCommandsLayout))
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.indirectCommandsLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, args);
        allocatedLoopResources.erase(args.indirectCommandsLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutNV(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::CreatePrivateDataSlotEXT&             args)
{
    // Check for null cases
    if (args.pPrivateDataSlot.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pPrivateDataSlot.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreatePrivateDataSlotEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyPrivateDataSlotEXT&            args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.privateDataSlot is in allocatedLoopResources

    // Call Process_vkDestroyPrivateDataSlotEXT if:
    //    We are not looping
    //    We are looping and args.privateDataSlot is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.privateDataSlot))
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.privateDataSlot))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, args);
        allocatedLoopResources.erase(args.privateDataSlot);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyPrivateDataSlotEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    args::CreateDirectFBSurfaceEXT&             args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDirectFBSurfaceEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    args::CreateScreenSurfaceQNX&               args)
{
    // Check for null cases
    if (args.pSurface.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSurface.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateScreenSurfaceQNX(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CreateMicromapEXT&                    args)
{
    // Check for null cases
    if (args.pMicromap.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pMicromap.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateMicromapEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyMicromapEXT&                   args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.micromap is in allocatedLoopResources

    // Call Process_vkDestroyMicromapEXT if:
    //    We are not looping
    //    We are looping and args.micromap is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.micromap))
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.micromap))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, args);
        allocatedLoopResources.erase(args.micromap);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyMicromapEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateTensorARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorARM&                      args)
{
    // Check for null cases
    if (args.pTensor.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pTensor.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateTensorARM(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyTensorARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorARM&                     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.tensor is in allocatedLoopResources

    // Call Process_vkDestroyTensorARM if:
    //    We are not looping
    //    We are looping and args.tensor is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.tensor))
        VulkanReplayConsumer::Process_vkDestroyTensorARM(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.tensor))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyTensorARM(call_info, args);
        allocatedLoopResources.erase(args.tensor);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyTensorARM(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::CreateTensorViewARM&                  args)
{
    // Check for null cases
    if (args.pView.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pView.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateTensorViewARM(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyTensorViewARM(
    const ApiCallInfo&                          call_info,
    args::DestroyTensorViewARM&                 args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.tensorView is in allocatedLoopResources

    // Call Process_vkDestroyTensorViewARM if:
    //    We are not looping
    //    We are looping and args.tensorView is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.tensorView))
        VulkanReplayConsumer::Process_vkDestroyTensorViewARM(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.tensorView))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyTensorViewARM(call_info, args);
        allocatedLoopResources.erase(args.tensorView);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyTensorViewARM(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindTensorMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindTensorMemoryARM&                  args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindTensorMemoryARM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::CreateOpticalFlowSessionNV&           args)
{
    // Check for null cases
    if (args.pSession.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSession.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateOpticalFlowSessionNV(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    args::DestroyOpticalFlowSessionNV&          args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.session is in allocatedLoopResources

    // Call Process_vkDestroyOpticalFlowSessionNV if:
    //    We are not looping
    //    We are looping and args.session is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.session))
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.session))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, args);
        allocatedLoopResources.erase(args.session);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyOpticalFlowSessionNV(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    args::BindOpticalFlowSessionImageNV&        args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindOpticalFlowSessionImageNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CreateShadersEXT&                     args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.createInfoCount; i++)
        {
            format::HandleId handle = args.pShaders.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateShadersEXT(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.createInfoCount; i++)
            {
                format::HandleId handle = args.pShaders.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyShaderEXT&                     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.shader is in allocatedLoopResources

    // Call Process_vkDestroyShaderEXT if:
    //    We are not looping
    //    We are looping and args.shader is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.shader))
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.shader))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, args);
        allocatedLoopResources.erase(args.shader);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyShaderEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDataGraphPipelinesARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelinesARM&          args)
{
    // Pass the call along if we are not looping or if all the handles are not in allocatedLoopResources.
    bool doReplay = false;
    if (!getFrameLoopInfo().IsLooping())
    {
        doReplay = true;
    }
    else
    {
        for (uint32_t i=0; i < args.createInfoCount; i++)
        {
            format::HandleId handle = args.pPipelines.GetPointer()[i];
            if (!allocatedLoopResources.contains(handle))
            {
                doReplay = true;
                break;
            }
        }
    }
    if (doReplay)
    {
        VulkanReplayConsumer::Process_vkCreateDataGraphPipelinesARM(call_info, args);
        // If we are looping, save the handles in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            for (uint32_t i=0; i < args.createInfoCount; i++)
            {
                format::HandleId handle = args.pPipelines.GetPointer()[i];
                allocatedLoopResources.insert(handle);
            }
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::CreateDataGraphPipelineSessionARM&    args)
{
    // Check for null cases
    if (args.pSession.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pSession.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateDataGraphPipelineSessionARM(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const ApiCallInfo&                          call_info,
    args::BindDataGraphPipelineSessionMemoryARM& args)
{
    // Return if not the first time through loop
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkBindDataGraphPipelineSessionMemoryARM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyDataGraphPipelineSessionARM(
    const ApiCallInfo&                          call_info,
    args::DestroyDataGraphPipelineSessionARM&   args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.session is in allocatedLoopResources

    // Call Process_vkDestroyDataGraphPipelineSessionARM if:
    //    We are not looping
    //    We are looping and args.session is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.session))
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.session))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, args);
        allocatedLoopResources.erase(args.session);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyDataGraphPipelineSessionARM(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectCommandsLayoutEXT&      args)
{
    // Check for null cases
    if (args.pIndirectCommandsLayout.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pIndirectCommandsLayout.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectCommandsLayoutEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectCommandsLayoutEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectCommandsLayoutEXT&     args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.indirectCommandsLayout is in allocatedLoopResources

    // Call Process_vkDestroyIndirectCommandsLayoutEXT if:
    //    We are not looping
    //    We are looping and args.indirectCommandsLayout is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.indirectCommandsLayout))
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.indirectCommandsLayout))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, args);
        allocatedLoopResources.erase(args.indirectCommandsLayout);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectCommandsLayoutEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::CreateIndirectExecutionSetEXT&        args)
{
    // Check for null cases
    if (args.pIndirectExecutionSet.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pIndirectExecutionSet.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateIndirectExecutionSetEXT(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyIndirectExecutionSetEXT(
    const ApiCallInfo&                          call_info,
    args::DestroyIndirectExecutionSetEXT&       args)
{
    // Skip for loop iterations 1-(n-1).
    // Skip if looping and if not final iteration
    // Execute if args.indirectExecutionSet is in allocatedLoopResources

    // Call Process_vkDestroyIndirectExecutionSetEXT if:
    //    We are not looping
    //    We are looping and args.indirectExecutionSet is in allocatedLoopResources
    //    We are looping and this is the last iteration
    if (!getFrameLoopInfo().IsLooping())
    {
        GFXRECON_ASSERT(!allocatedLoopResources.contains(args.indirectExecutionSet))
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, args);
    }
    else if (allocatedLoopResources.contains(args.indirectExecutionSet))
    {
        // Looping special case:
        // This resource has been allocated WITHIN the loop range.
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, args);
        allocatedLoopResources.erase(args.indirectExecutionSet);
    }
    else if (getFrameLoopInfo().IsFinalIteration())
    {
        // Looping special case:
        // This resource has been allocated BEFORE the loop range.
        // Since it might still be in use during the loop range, ONLY free it in the last iteration.
        VulkanReplayConsumer::Process_vkDestroyIndirectExecutionSetEXT(call_info, args);
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CreateAccelerationStructureKHR&       args)
{
    // Check for null cases
    if (args.pAccelerationStructure.IsNull())
    {
        return;
    }
    format::HandleId handle = *args.pAccelerationStructure.GetPointer();

    // Pass the call along if we are not looping or
    // if we are looping and the handle is not in allocatedLoopResources
    if (!getFrameLoopInfo().IsLooping() || !allocatedLoopResources.contains(handle))
    {
        VulkanReplayConsumer::Process_vkCreateAccelerationStructureKHR(call_info, args);
        // If we are looping, save the handle in allocatedLoopResources
        if (getFrameLoopInfo().IsLooping())
        {
            allocatedLoopResources.insert(handle);
        }
    }
}

void VulkanReplayFrameLoopConsumerBase::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::DestroyAccelerationStructureKHR&      args)
{
    if (getFrameLoopInfo().IsLooping() && !getFrameLoopInfo().IsFinalIteration())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkDestroyAccelerationStructureKHR(call_info, args);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
