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
    // Only record command buffer commands on first iteration of looping frame.
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
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkFreeCommandBuffers(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    args::EndCommandBuffer&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkEndCommandBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage&                         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateBuffer&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdateBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdFillBuffer&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdFillBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQuery&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginQuery(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    args::CmdEndQuery&                          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndQuery(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    args::CmdResetQueryPool&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetQueryPool(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResults&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResults(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteCommands&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteCommands(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipeline&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindPipeline(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearColorImage&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearColorImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    args::CmdDispatch&                          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatch(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchIndirect(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent&                          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewport&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewport(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissor&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissor(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineWidth&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineWidth(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBias(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    args::CmdSetBlendConstants&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetBlendConstants(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBounds&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBounds(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilCompareMask&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilCompareMask(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilWriteMask&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilWriteMask(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilReference&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilReference(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    args::CmdDraw&                              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDraw(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexed&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexed(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirect(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage&                         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    args::CmdClearDepthStencilImage&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearDepthStencilImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    args::CmdClearAttachments&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdClearAttachments(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMask&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDeviceMask(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    args::TrimCommandPool&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkTrimCommandPool(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBase&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchBase(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCount(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass2(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2&                         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2&                        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRendering&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRendering(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullMode&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCullMode(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFace&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFrontFace(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopology&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopology(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCount&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWithCount(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCount&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissorWithCount(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnable&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthTestEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnable&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOp&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthCompareOp(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnable&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnable&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilTestEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOp&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilOp(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnable&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnable&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnable(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnable&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnable(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStipple&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStipple(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocations&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocations(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndices& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginVideoCodingKHR&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginVideoCodingKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndVideoCodingKHR&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndVideoCodingKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdControlVideoCodingKHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdControlVideoCodingKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDecodeVideoKHR&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecodeVideoKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderingKHR&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderingKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderingKHR&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderingKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetDeviceMaskKHR&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDeviceMaskKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchBaseKHR&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchBaseKHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSetKHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSetKHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBeginRenderPass2KHR&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginRenderPass2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdNextSubpass2KHR&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdNextSubpass2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRenderPass2KHR&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRenderPass2KHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountKHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountKHR&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateKHR&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingAttachmentLocationsKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRenderingInputAttachmentIndicesKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    args::CmdEncodeVideoKHR&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEncodeVideoKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetEvent2KHR&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetEvent2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResetEvent2KHR&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResetEvent2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWaitEvents2KHR&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWaitEvents2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPipelineBarrier2KHR&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPipelineBarrier2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteTimestamp2KHR&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteTimestamp2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer3KHR&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer3KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers3KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers3KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirect2KHR&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirect2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirect2KHR&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirect2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchIndirect2KHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchIndirect2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryKHR&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageKHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToMemoryKHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdUpdateMemoryKHR&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdateMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdFillMemoryKHR&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdFillMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyQueryPoolResultsToMemoryKHR&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCount2KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCount2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCount2KHR&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCount2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRendering2EXT&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginConditionalRendering2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffers2EXT&  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffers2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedback2EXT&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginTransformFeedback2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedback2EXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndTransformFeedback2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCount2EXT&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCount2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirect2EXT&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirect2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCount2EXT&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCount2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMarkerToMemoryAMD&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteMarkerToMemoryAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBuffer2KHR&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBuffer2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImage2KHR&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImage2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyBufferToImage2KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyBufferToImage2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyImageToBuffer2KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyImageToBuffer2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBlitImage2KHR&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBlitImage2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdResolveImage2KHR&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdResolveImage2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirect2KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysIndirect2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindIndexBuffer2KHR&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindIndexBuffer2KHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleKHR&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorSets2KHR&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorSets2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushConstants2KHR&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushConstants2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdPushDescriptorSet2KHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPushDescriptorSet2KHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsets2EXT&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplers2EXT& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryIndirectKHR&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryIndirectKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToImageIndirectKHR&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2KHR&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering2KHR(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerBeginEXT&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerBeginEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerEndEXT&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerEndEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDebugMarkerInsertEXT&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDebugMarkerInsertEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindTransformFeedbackBuffersEXT&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginTransformFeedbackEXT&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginTransformFeedbackEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndTransformFeedbackEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndTransformFeedbackEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginQueryIndexedEXT&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginQueryIndexedEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndQueryIndexedEXT&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndQueryIndexedEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectByteCountEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectByteCountEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndirectCountAMD&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndirectCountAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    args::CmdDrawIndexedIndirectCountAMD&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginConditionalRenderingEXT&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginConditionalRenderingEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndConditionalRenderingEXT&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndConditionalRenderingEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingNV&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWScalingNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleEnableEXT&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDiscardRectangleModeEXT&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDiscardRectangleModeEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginDebugUtilsLabelEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndDebugUtilsLabelEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndDebugUtilsLabelEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    args::CmdInsertDebugUtilsLabelEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSessionAMD&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginGpaSessionAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSessionAMD&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndGpaSessionAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdBeginGpaSampleAMD&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginGpaSampleAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    args::CmdEndGpaSampleAMD&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndGpaSampleAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    args::CmdCopyGpaSessionResultsAMD&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyGpaSessionResultsAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadingRateImageNV&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindShadingRateImageNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportShadingRatePaletteNV&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoarseSampleOrderNV&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoarseSampleOrderNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructureNV&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructureNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureNV&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysNV&                       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesNV& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarkerAMD&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarkerAMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    args::CmdWriteBufferMarker2AMD&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteBufferMarker2AMD(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksNV&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectNV&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountNV&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorEnableNV&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetExclusiveScissorNV&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExclusiveScissorNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCheckpointNV&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCheckpointNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceMarkerINTEL&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceMarkerINTEL(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceStreamMarkerINTEL&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    args::CmdSetPerformanceOverrideINTEL&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPerformanceOverrideINTEL(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEXT&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetCullModeEXT&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCullModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetFrontFaceEXT&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFrontFaceEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveTopologyEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveTopologyEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWithCountEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWithCountEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetScissorWithCountEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetScissorWithCountEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindVertexBuffers2EXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindVertexBuffers2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthTestEnableEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthTestEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthWriteEnableEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthWriteEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthCompareOpEXT&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthCompareOpEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBoundsTestEnableEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilTestEnableEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilTestEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetStencilOpEXT&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetStencilOpEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsNV&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsNV&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    args::CmdBindPipelineShaderGroupNV&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindPipelineShaderGroupNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBias2EXT&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBias2EXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchTileQCOM&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchTileQCOM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBeginPerTileExecutionQCOM&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginPerTileExecutionQCOM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdEndPerTileExecutionQCOM&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndPerTileExecutionQCOM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBuffersEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBuffersEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDescriptorBufferOffsetsEXT&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindDescriptorBufferEmbeddedSamplersEXT& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetFragmentShadingRateEnumNV&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetVertexInputEXT&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetVertexInputEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdBindInvocationMaskHUAWEI&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindInvocationMaskHUAWEI(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPatchControlPointsEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPatchControlPointsEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizerDiscardEnableEXT&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthBiasEnableEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthBiasEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEXT&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLogicOpEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartEnableEXT&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteEnableEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorWriteEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiEXT&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMultiEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMultiIndexedEXT&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMultiIndexedEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBuildMicromapsEXT&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildMicromapsEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapEXT&                   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMicromapEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMicromapToMemoryEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMicromapToMemoryEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToMicromapEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToMicromapEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdWriteMicromapsPropertiesEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterHUAWEI&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawClusterHUAWEI(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    args::CmdDrawClusterIndirectHUAWEI&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    args::CmdSetDispatchParametersARM&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDispatchParametersARM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    args::CmdUpdatePipelineIndirectBufferNV&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampEnableEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClampEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPolygonModeEXT&                 args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPolygonModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationSamplesEXT&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizationSamplesEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleMaskEXT&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleMaskEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToCoverageEnableEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAlphaToOneEnableEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAlphaToOneEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLogicOpEnableEXT&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLogicOpEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEnableEXT&            args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendEquationEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendEquationEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorWriteMaskEXT&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorWriteMaskEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetTessellationDomainOriginEXT&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetTessellationDomainOriginEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetRasterizationStreamEXT&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRasterizationStreamEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetConservativeRasterizationModeEXT& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetExtraPrimitiveOverestimationSizeEXT& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipEnableEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClipEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetSampleLocationsEnableEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetSampleLocationsEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetColorBlendAdvancedEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetColorBlendAdvancedEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetProvokingVertexModeEXT&         args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetProvokingVertexModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineRasterizationModeEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineRasterizationModeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetLineStippleEnableEXT&           args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetLineStippleEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClipNegativeOneToOneEXT&   args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportWScalingEnableNV&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportWScalingEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetViewportSwizzleNV&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetViewportSwizzleNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorEnableNV&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageToColorEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageToColorLocationNV&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageToColorLocationNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationModeNV&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationModeNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableEnableNV& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageModulationTableNV&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageModulationTableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetShadingRateImageEnableNV&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetShadingRateImageEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetRepresentativeFragmentTestEnableNV& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetCoverageReductionModeNV&        args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetCoverageReductionModeNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    args::CmdCopyTensorARM&                     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyTensorARM(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    args::CmdOpticalFlowExecuteNV&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdOpticalFlowExecuteNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBindShadersEXT&                    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindShadersEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetDepthClampRangeEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetDepthClampRangeEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    args::CmdConvertCooperativeVectorMatrixNV&  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    args::CmdDispatchDataGraphARM&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDispatchDataGraphARM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetAttachmentFeedbackLoopEnableEXT& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    args::CmdBindTileMemoryQCOM&                args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBindTileMemoryQCOM(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryEXT&               args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecompressMemoryEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDecompressMemoryIndirectCountEXT&  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    args::CmdBuildPartitionedAccelerationStructuresNV& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdPreprocessGeneratedCommandsEXT&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    args::CmdExecuteGeneratedCommandsEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    args::CmdEndRendering2EXT&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdEndRendering2EXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    args::CmdBeginCustomResolveEXT&             args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginCustomResolveEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    args::CmdSetComputeOccupancyPriorityNV&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    args::CmdSetPrimitiveRestartIndexEXT&       args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetPrimitiveRestartIndexEXT(call_info, args);
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

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresKHR&    args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdBuildAccelerationStructuresIndirectKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureKHR&      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyAccelerationStructureToMemoryKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    args::CmdCopyMemoryToAccelerationStructureKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    args::CmdWriteAccelerationStructuresPropertiesKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysKHR&                      args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    args::CmdTraceRaysIndirectKHR&              args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdTraceRaysIndirectKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    args::CmdSetRayTracingPipelineStackSizeKHR& args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksEXT&                  args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectEXT&          args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(call_info, args);
}

void VulkanReplayFrameLoopConsumerBase::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    args::CmdDrawMeshTasksIndirectCountEXT&     args)
{
    // Only record command buffer commands on first iteration of looping frame.
    if (getFrameLoopInfo().IsRepetition())
    {
        return;
    }
    VulkanReplayConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(call_info, args);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
