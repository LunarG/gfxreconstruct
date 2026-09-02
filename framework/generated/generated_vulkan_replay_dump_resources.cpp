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

#include "generated/generated_vulkan_replay_dump_resources.h"

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayDumpResources::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->EndCommandBuffer;
        OverrideEndCommandBuffer(call_info, func, commandBuffer);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     srcBuffer,
    const VulkanBufferInfo*                     dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBuffer;
        OverrideCmdCopyBuffer(call_info, func, commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanImageInfo*                      srcImage,
    VkImageLayout                               srcImageLayout,
    const VulkanImageInfo*                      dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImage;
        OverrideCmdCopyImage(call_info, func, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     srcBuffer,
    const VulkanImageInfo*                      dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBufferToImage;
        OverrideCmdCopyBufferToImage(call_info, func, commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanImageInfo*                      srcImage,
    VkImageLayout                               srcImageLayout,
    const VulkanBufferInfo*                     dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImageToBuffer;
        OverrideCmdCopyImageToBuffer(call_info, func, commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdUpdateBuffer;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, dstBuffer, dstOffset, dataSize, pData);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, dstBuffer, dstOffset, dataSize, pData);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdFillBuffer;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, dstBuffer, dstOffset, size, data);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, dstBuffer, dstOffset, size, data);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPipelineBarrier;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginQuery;
        OverrideCmdBeginQuery(call_info, func, commandBuffer, queryPool, query, flags);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndQuery;
        OverrideCmdEndQuery(call_info, func, commandBuffer, queryPool, query);
    }
}

void VulkanReplayDumpResources::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdResetQueryPool;
        OverrideCmdResetQueryPool(call_info, func, commandBuffer, queryPool, firstQuery, queryCount);
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteTimestamp;
        OverrideCmdWriteTimestamp(call_info, func, commandBuffer, pipelineStage, queryPool, query);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    const VulkanBufferInfo*                     dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyQueryPoolResults;
        OverrideCmdCopyQueryPoolResults(call_info, func, commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
    }
}

void VulkanReplayDumpResources::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdExecuteCommands;
        OverrideCmdExecuteCommands(call_info, func, commandBuffer, commandBufferCount, pCommandBuffers);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineInfo*                   pipeline)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindPipeline;
        OverrideCmdBindPipeline(call_info, func, commandBuffer, pipelineBindPoint, pipeline);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineLayoutInfo*             layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindDescriptorSets;
        OverrideCmdBindDescriptorSets(call_info, func, commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets->GetPointer(), dynamicOffsetCount, pDynamicOffsets);
    }
}

void VulkanReplayDumpResources::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdClearColorImage;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, image, imageLayout, pColor, rangeCount, pRanges);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, image, imageLayout, pColor, rangeCount, pRanges);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDispatch;
        OverrideCmdDispatch(call_info, func, commandBuffer, groupCountX, groupCountY, groupCountZ);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDispatchIndirect;
        OverrideCmdDispatchIndirect(call_info, func, commandBuffer, buffer, offset);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetEvent;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, stageMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, stageMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResetEvent;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, stageMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, stageMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWaitEvents;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushConstants;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, layout, stageFlags, offset, size, pValues);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, layout, stageFlags, offset, size, pValues);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewport;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstViewport, viewportCount, pViewports);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewports);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetScissor;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstScissor, scissorCount, pScissors);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstScissor, scissorCount, pScissors);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineWidth;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, lineWidth);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, lineWidth);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBias;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const float*                                blendConstants)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetBlendConstants;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, blendConstants);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, blendConstants);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBounds;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, minDepthBounds, maxDepthBounds);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, minDepthBounds, maxDepthBounds);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilCompareMask;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, faceMask, compareMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, faceMask, compareMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilWriteMask;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, faceMask, writeMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, faceMask, writeMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilReference;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, faceMask, reference);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, faceMask, reference);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindIndexBuffer;
        OverrideCmdBindIndexBuffer(call_info, func, commandBuffer, buffer, offset, indexType);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindVertexBuffers;
        OverrideCmdBindVertexBuffers(call_info, func, commandBuffer, firstBinding, bindingCount, pBuffers->GetPointer(), pOffsets);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDraw;
        OverrideCmdDraw(call_info, func, commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndexed;
        OverrideCmdDrawIndexed(call_info, func, commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndirect;
        OverrideCmdDrawIndirect(call_info, func, commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndexedIndirect;
        OverrideCmdDrawIndexedIndirect(call_info, func, commandBuffer, buffer, offset, drawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanImageInfo*                      srcImage,
    VkImageLayout                               srcImageLayout,
    const VulkanImageInfo*                      dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
    VkFilter                                    filter,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBlitImage;
        OverrideCmdBlitImage(call_info, func, commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdClearDepthStencilImage;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, image, imageLayout, pDepthStencil, rangeCount, pRanges);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdClearAttachments;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, attachmentCount, pAttachments, rectCount, pRects);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, attachmentCount, pAttachments, rectCount, pRects);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResolveImage;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginRenderPass;
        OverrideCmdBeginRenderPass(call_info, func, commandBuffer, pRenderPassBegin, contents);
    }
}

void VulkanReplayDumpResources::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdNextSubpass;
        OverrideCmdNextSubpass(call_info, func, commandBuffer, contents);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndRenderPass;
        OverrideCmdEndRenderPass(call_info, func, commandBuffer);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDeviceMask;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, deviceMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, deviceMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDispatchBase;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndirectCount;
        OverrideCmdDrawIndirectCount(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndexedIndirectCount;
        OverrideCmdDrawIndexedIndirectCount(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginRenderPass2;
        OverrideCmdBeginRenderPass2(call_info, func, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdNextSubpass2;
        OverrideCmdNextSubpass2(call_info, func, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndRenderPass2;
        OverrideCmdEndRenderPass2(call_info, func, commandBuffer, pSubpassEndInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPipelineBarrier2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDependencyInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDependencyInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteTimestamp2;
        OverrideCmdWriteTimestamp2(call_info, func, commandBuffer, stage, queryPool, query);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBuffer2;
        OverrideCmdCopyBuffer2(call_info, func, commandBuffer, pCopyBufferInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImage2;
        OverrideCmdCopyImage2(call_info, func, commandBuffer, pCopyImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBufferToImage2;
        OverrideCmdCopyBufferToImage2(call_info, func, commandBuffer, pCopyBufferToImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImageToBuffer2;
        OverrideCmdCopyImageToBuffer2(call_info, func, commandBuffer, pCopyImageToBufferInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetEvent2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, pDependencyInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, pDependencyInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResetEvent2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, stageMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, stageMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWaitEvents2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, eventCount, pEvents, pDependencyInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, eventCount, pEvents, pDependencyInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBlitImage2;
        OverrideCmdBlitImage2(call_info, func, commandBuffer, pBlitImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResolveImage2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pResolveImageInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pResolveImageInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginRendering;
        OverrideCmdBeginRendering(call_info, func, commandBuffer, pRenderingInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndRendering;
        OverrideCmdEndRendering(call_info, func, commandBuffer);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCullMode;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, cullMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, cullMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetFrontFace;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, frontFace);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, frontFace);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPrimitiveTopology;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, primitiveTopology);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, primitiveTopology);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportWithCount;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, viewportCount, pViewports);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, viewportCount, pViewports);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetScissorWithCount;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, scissorCount, pScissors);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, scissorCount, pScissors);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindVertexBuffers2;
        OverrideCmdBindVertexBuffers2(call_info, func, commandBuffer, firstBinding, bindingCount, pBuffers->GetPointer(), pOffsets, pSizes, pStrides);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthTestEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthWriteEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthWriteEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthWriteEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthCompareOp;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthCompareOp);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthCompareOp);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBoundsTestEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthBoundsTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthBoundsTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilTestEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, stencilTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, stencilTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilOp;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, faceMask, failOp, passOp, depthFailOp, compareOp);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRasterizerDiscardEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, rasterizerDiscardEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, rasterizerDiscardEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBiasEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthBiasEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthBiasEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPrimitiveRestartEnable;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, primitiveRestartEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, primitiveRestartEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineLayoutInfo*             layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdPushDescriptorSet;
        OverrideCmdPushDescriptorSet(call_info, func, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSetWithTemplate(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushDescriptorSetWithTemplate;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, descriptorUpdateTemplate, layout, set, pData);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, descriptorUpdateTemplate, layout, set, pData);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindDescriptorSets2;
        OverrideCmdBindDescriptorSets2(call_info, func, commandBuffer, pBindDescriptorSetsInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPushConstantsInfo*                  pPushConstantsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushConstants2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPushConstantsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPushConstantsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdPushDescriptorSet2;
        OverrideCmdPushDescriptorSet2(call_info, func, commandBuffer, pPushDescriptorSetInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSetWithTemplate2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetWithTemplateInfo*  pPushDescriptorSetWithTemplateInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushDescriptorSetWithTemplate2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPushDescriptorSetWithTemplateInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPushDescriptorSetWithTemplateInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineStipple;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, lineStippleFactor, lineStipplePattern);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, lineStippleFactor, lineStipplePattern);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindIndexBuffer2;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset, size, indexType);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset, size, indexType);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingAttachmentLocationInfo*    pLocationInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRenderingAttachmentLocations;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pLocationInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pLocationInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInputAttachmentIndexInfo*  pInputAttachmentIndexInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRenderingInputAttachmentIndices;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInputAttachmentIndexInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInputAttachmentIndexInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginVideoCodingKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pBeginInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pBeginInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndVideoCodingKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pEndCodingInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pEndCodingInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdControlVideoCodingKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCodingControlInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCodingControlInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDecodeVideoKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDecodeInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDecodeInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginRenderingKHR;
        OverrideCmdBeginRenderingKHR(call_info, func, commandBuffer, pRenderingInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndRenderingKHR;
        OverrideCmdEndRenderingKHR(call_info, func, commandBuffer);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDeviceMaskKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, deviceMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, deviceMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDispatchBaseKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineLayoutInfo*             layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdPushDescriptorSetKHR;
        OverrideCmdPushDescriptorSetKHR(call_info, func, commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushDescriptorSetWithTemplateKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, descriptorUpdateTemplate, layout, set, pData);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, descriptorUpdateTemplate, layout, set, pData);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginRenderPass2KHR;
        OverrideCmdBeginRenderPass2(call_info, func, commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdNextSubpass2KHR;
        OverrideCmdNextSubpass2(call_info, func, commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndRenderPass2KHR;
        OverrideCmdEndRenderPass2(call_info, func, commandBuffer, pSubpassEndInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndirectCountKHR;
        OverrideCmdDrawIndirectCountKHR(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndexedIndirectCountKHR;
        OverrideCmdDrawIndexedIndirectCountKHR(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetFragmentShadingRateKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pFragmentSize, combinerOps);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pFragmentSize, combinerOps);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingAttachmentLocationInfo*    pLocationInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRenderingAttachmentLocationsKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pLocationInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pLocationInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInputAttachmentIndexInfo*  pInputAttachmentIndexInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRenderingInputAttachmentIndicesKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInputAttachmentIndexInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInputAttachmentIndexInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEncodeVideoKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pEncodeInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pEncodeInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetEvent2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, pDependencyInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, pDependencyInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResetEvent2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, event, stageMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, event, stageMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWaitEvents2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, eventCount, pEvents, pDependencyInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, eventCount, pEvents, pDependencyInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPipelineBarrier2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDependencyInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDependencyInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteTimestamp2KHR;
        OverrideCmdWriteTimestamp2KHR(call_info, func, commandBuffer, stage, queryPool, query);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindIndexBuffer3KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkBindIndexBuffer3InfoKHR*            pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindIndexBuffer3KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindVertexBuffers3KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBindVertexBuffer3InfoKHR*           pBindingInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindVertexBuffers3KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstBinding, bindingCount, pBindingInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBindingInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirect2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirect2InfoKHR*               pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndirect2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirect2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirect2InfoKHR*               pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndexedIndirect2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchIndirect2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDispatchIndirect2InfoKHR*           pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDispatchIndirect2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyDeviceMemoryInfoKHR*            pCopyMemoryInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyMemoryInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyMemoryInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryToImageKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyDeviceMemoryImageInfoKHR*       pCopyMemoryInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryToImageKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyMemoryInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyMemoryInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImageToMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyDeviceMemoryImageInfoKHR*       pCopyMemoryInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyImageToMemoryKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyMemoryInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyMemoryInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdUpdateMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDeviceAddressRangeKHR*              pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdUpdateMemoryKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDstRange, dstFlags, dataSize, pData);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDstRange, dstFlags, dataSize, pData);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdFillMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDeviceAddressRangeKHR*              pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    uint32_t                                    data)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdFillMemoryKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDstRange, dstFlags, data);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDstRange, dstFlags, data);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyQueryPoolResultsToMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRangeKHR>* pDstRange,
    VkAddressCommandFlagsKHR                    dstFlags,
    VkQueryResultFlags                          queryResultFlags)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyQueryPoolResultsToMemoryKHR;
        OverrideCmdCopyQueryPoolResultsToMemoryKHR(call_info, func, commandBuffer, queryPool, firstQuery, queryCount, pDstRange, dstFlags, queryResultFlags);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirectCount2InfoKHR*          pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndirectCount2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirectCount2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirectCount2InfoKHR*          pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndexedIndirectCount2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginConditionalRendering2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfo2EXT*  pConditionalRenderingBegin)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginConditionalRendering2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pConditionalRenderingBegin);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pConditionalRenderingBegin);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindTransformFeedbackBuffers2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBindTransformFeedbackBuffer2InfoEXT* pBindingInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindTransformFeedbackBuffers2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstBinding, bindingCount, pBindingInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBindingInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginTransformFeedback2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstCounterRange, counterRangeCount, pCounterInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstCounterRange, counterRangeCount, pCounterInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndTransformFeedback2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterRange,
    uint32_t                                    counterRangeCount,
    const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndTransformFeedback2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstCounterRange, counterRangeCount, pCounterInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstCounterRange, counterRangeCount, pCounterInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectByteCount2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfo,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndirectByteCount2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, instanceCount, firstInstance, pCounterInfo, counterOffset, vertexStride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, instanceCount, firstInstance, pCounterInfo, counterOffset, vertexStride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirect2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirect2InfoKHR*               pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirect2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirectCount2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDrawIndirectCount2InfoKHR*          pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirectCount2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteMarkerToMemoryAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkMemoryMarkerInfoAMD*                pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWriteMarkerToMemoryAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBuffer2KHR;
        OverrideCmdCopyBuffer2KHR(call_info, func, commandBuffer, pCopyBufferInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImage2KHR;
        OverrideCmdCopyImage2KHR(call_info, func, commandBuffer, pCopyImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyBufferToImage2KHR;
        OverrideCmdCopyBufferToImage2KHR(call_info, func, commandBuffer, pCopyBufferToImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyImageToBuffer2KHR;
        OverrideCmdCopyImageToBuffer2KHR(call_info, func, commandBuffer, pCopyImageToBufferInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBlitImage2KHR;
        OverrideCmdBlitImage2KHR(call_info, func, commandBuffer, pBlitImageInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdResolveImage2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pResolveImageInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pResolveImageInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdTraceRaysIndirect2KHR;
        OverrideCmdTraceRaysIndirect2KHR(call_info, func, commandBuffer, indirectDeviceAddress);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindIndexBuffer2KHR;
        OverrideCmdBindIndexBuffer2KHR(call_info, func, commandBuffer, buffer, offset, size, indexType);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineStippleKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, lineStippleFactor, lineStipplePattern);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, lineStippleFactor, lineStipplePattern);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindDescriptorSets2KHR;
        OverrideCmdBindDescriptorSets2(call_info, func, commandBuffer, pBindDescriptorSetsInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPushConstantsInfo*                  pPushConstantsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushConstants2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPushConstantsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPushConstantsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdPushDescriptorSet2KHR;
        OverrideCmdPushDescriptorSet2KHR(call_info, func, commandBuffer, pPushDescriptorSetInfo);
    }
}

void VulkanReplayDumpResources::Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetWithTemplateInfo*  pPushDescriptorSetWithTemplateInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPushDescriptorSetWithTemplate2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPushDescriptorSetWithTemplateInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPushDescriptorSetWithTemplateInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkSetDescriptorBufferOffsetsInfoEXT*  pSetDescriptorBufferOffsetsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDescriptorBufferOffsets2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pSetDescriptorBufferOffsetsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pSetDescriptorBufferOffsetsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindDescriptorBufferEmbeddedSamplers2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pBindDescriptorBufferEmbeddedSamplersInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pBindDescriptorBufferEmbeddedSamplersInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryIndirectInfoKHR*          pCopyMemoryIndirectInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryIndirectKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyMemoryIndirectInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyMemoryIndirectInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToImageIndirectInfoKHR*   pCopyMemoryToImageIndirectInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryToImageIndirectKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyMemoryToImageIndirectInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyMemoryToImageIndirectInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingEndInfoKHR*                pRenderingEndInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndRendering2KHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pRenderingEndInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pRenderingEndInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDebugMarkerBeginEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pMarkerInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pMarkerInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDebugMarkerEndEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDebugMarkerInsertEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pMarkerInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pMarkerInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindTransformFeedbackBuffersEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginTransformFeedbackEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndTransformFeedbackEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBeginQueryIndexedEXT;
        OverrideCmdBeginQueryIndexedEXT(call_info, func, commandBuffer, queryPool, query, flags, index);
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdEndQueryIndexedEXT;
        OverrideCmdEndQueryIndexedEXT(call_info, func, commandBuffer, queryPool, query, index);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawIndirectByteCountEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndirectCountAMD;
        OverrideCmdDrawIndirectCountAMD(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdDrawIndexedIndirectCountAMD;
        OverrideCmdDrawIndexedIndirectCountAMD(call_info, func, commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginConditionalRenderingEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pConditionalRenderingBegin);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pConditionalRenderingBegin);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndConditionalRenderingEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportWScalingNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstViewport, viewportCount, pViewportWScalings);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewportWScalings);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDiscardRectangleEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDiscardRectangleEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, discardRectangleEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, discardRectangleEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDiscardRectangleModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, discardRectangleMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, discardRectangleMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginDebugUtilsLabelEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pLabelInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pLabelInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndDebugUtilsLabelEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdInsertDebugUtilsLabelEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pLabelInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pLabelInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginGpaSessionAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, gpaSession);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, gpaSession);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndGpaSessionAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndGpaSessionAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, gpaSession);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, gpaSession);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession,
    const VkGpaSampleBeginInfoAMD*              pGpaSampleBeginInfo,
    uint32_t*                                   pSampleID)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginGpaSampleAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, gpaSession, pGpaSampleBeginInfo, pSampleID);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, gpaSession, pGpaSampleBeginInfo, pSampleID);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndGpaSampleAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession,
    uint32_t                                    sampleID)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndGpaSampleAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, gpaSession, sampleID);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, gpaSession, sampleID);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyGpaSessionResultsAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkGpaSessionAMD                             gpaSession)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyGpaSessionResultsAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, gpaSession);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, gpaSession);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetSampleLocationsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pSampleLocationsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pSampleLocationsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindShadingRateImageNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, imageView, imageLayout);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, imageView, imageLayout);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportShadingRatePaletteNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstViewport, viewportCount, pShadingRatePalettes);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstViewport, viewportCount, pShadingRatePalettes);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoarseSampleOrderNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBuildAccelerationStructureNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyAccelerationStructureNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, dst, src, mode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, dst, src, mode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    raygenShaderBindingTableBuffer,
    VkDeviceSize                                raygenShaderBindingOffset,
    VkBuffer                                    missShaderBindingTableBuffer,
    VkDeviceSize                                missShaderBindingOffset,
    VkDeviceSize                                missShaderBindingStride,
    VkBuffer                                    hitShaderBindingTableBuffer,
    VkDeviceSize                                hitShaderBindingOffset,
    VkDeviceSize                                hitShaderBindingStride,
    VkBuffer                                    callableShaderBindingTableBuffer,
    VkDeviceSize                                callableShaderBindingOffset,
    VkDeviceSize                                callableShaderBindingStride,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdTraceRaysNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteAccelerationStructuresPropertiesNV;
        OverrideCmdWriteAccelerationStructuresPropertiesNV(call_info, func, commandBuffer, accelerationStructureCount, pAccelerationStructures->GetPointer(), queryType, queryPool, firstQuery);
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWriteBufferMarkerAMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineStage, dstBuffer, dstOffset, marker);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineStage, dstBuffer, dstOffset, marker);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdWriteBufferMarker2AMD;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, stage, dstBuffer, dstOffset, marker);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, stage, dstBuffer, dstOffset, marker);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, taskCount, firstTask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, taskCount, firstTask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirectNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset, drawCount, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset, drawCount, stride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirectCountNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetExclusiveScissorEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetExclusiveScissorNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCheckpointNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCheckpointMarker);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCheckpointMarker);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPerformanceMarkerINTEL;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pMarkerInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pMarkerInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPerformanceStreamMarkerINTEL;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pMarkerInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pMarkerInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPerformanceOverrideINTEL;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pOverrideInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pOverrideInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineStippleEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, lineStippleFactor, lineStipplePattern);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, lineStippleFactor, lineStipplePattern);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCullModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, cullMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, cullMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetFrontFaceEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, frontFace);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, frontFace);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPrimitiveTopologyEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, primitiveTopology);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, primitiveTopology);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportWithCountEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, viewportCount, pViewports);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, viewportCount, pViewports);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetScissorWithCountEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, scissorCount, pScissors);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, scissorCount, pScissors);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBindVertexBuffers2EXT;
        OverrideCmdBindVertexBuffers2EXT(call_info, func, commandBuffer, firstBinding, bindingCount, pBuffers->GetPointer(), pOffsets, pSizes, pStrides);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthTestEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthWriteEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthWriteEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthWriteEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthCompareOpEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthCompareOp);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthCompareOp);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBoundsTestEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthBoundsTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthBoundsTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilTestEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, stencilTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, stencilTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetStencilOpEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, faceMask, failOp, passOp, depthFailOp, compareOp);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, faceMask, failOp, passOp, depthFailOp, compareOp);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPreprocessGeneratedCommandsNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pGeneratedCommandsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pGeneratedCommandsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdExecuteGeneratedCommandsNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, isPreprocessed, pGeneratedCommandsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, isPreprocessed, pGeneratedCommandsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindPipelineShaderGroupNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineBindPoint, pipeline, groupIndex);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline, groupIndex);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBias2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDepthBiasInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDepthBiasInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDispatchTileInfoQCOM*               pDispatchTileInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDispatchTileQCOM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDispatchTileInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDispatchTileInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPerTileBeginInfoQCOM*               pPerTileBeginInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginPerTileExecutionQCOM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPerTileBeginInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPerTileBeginInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkPerTileEndInfoQCOM*                 pPerTileEndInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndPerTileExecutionQCOM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pPerTileEndInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pPerTileEndInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    bufferCount,
    const VkDescriptorBufferBindingInfoEXT*     pBindingInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindDescriptorBuffersEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, bufferCount, pBindingInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, bufferCount, pBindingInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    const uint32_t*                             pBufferIndices,
    const VkDeviceSize*                         pOffsets)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDescriptorBufferOffsetsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindDescriptorBufferEmbeddedSamplersEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineBindPoint, layout, set);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineBindPoint, layout, set);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetFragmentShadingRateEnumNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, shadingRate, combinerOps);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, shadingRate, combinerOps);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdSetVertexInputEXT;
        OverrideCmdSetVertexInputEXT(call_info, func, commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindInvocationMaskHUAWEI;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, imageView, imageLayout);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, imageView, imageLayout);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPatchControlPointsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, patchControlPoints);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, patchControlPoints);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRasterizerDiscardEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, rasterizerDiscardEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, rasterizerDiscardEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthBiasEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthBiasEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthBiasEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLogicOpEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, logicOp);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, logicOp);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPrimitiveRestartEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, primitiveRestartEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, primitiveRestartEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetColorWriteEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, attachmentCount, pColorWriteEnables);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, attachmentCount, pColorWriteEnables);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMultiEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMultiIndexedEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBuildMicromapsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, infoCount, pInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, infoCount, pInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMicromapEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMicromapToMemoryEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryToMicromapEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteMicromapsPropertiesEXT;
        OverrideCmdWriteMicromapsPropertiesEXT(call_info, func, commandBuffer, micromapCount, pMicromaps->GetPointer(), queryType, queryPool, firstQuery);
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawClusterHUAWEI;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, groupCountX, groupCountY, groupCountZ);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawClusterIndirectHUAWEI;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDispatchParametersARM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDispatchParametersARM*              pDispatchParameters)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDispatchParametersARM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDispatchParameters);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDispatchParameters);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdUpdatePipelineIndirectBufferNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineBindPoint, pipeline);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineBindPoint, pipeline);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthClampEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthClampEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthClampEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPolygonModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, polygonMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, polygonMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRasterizationSamplesEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, rasterizationSamples);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, rasterizationSamples);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetSampleMaskEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, samples, pSampleMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, samples, pSampleMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetAlphaToCoverageEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, alphaToCoverageEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, alphaToCoverageEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetAlphaToOneEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, alphaToOneEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, alphaToOneEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLogicOpEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, logicOpEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, logicOpEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetColorBlendEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstAttachment, attachmentCount, pColorBlendEnables);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendEnables);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetColorBlendEquationEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstAttachment, attachmentCount, pColorBlendEquations);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendEquations);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetColorWriteMaskEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstAttachment, attachmentCount, pColorWriteMasks);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorWriteMasks);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetTessellationDomainOriginEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, domainOrigin);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, domainOrigin);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRasterizationStreamEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, rasterizationStream);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, rasterizationStream);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetConservativeRasterizationModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, conservativeRasterizationMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, conservativeRasterizationMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetExtraPrimitiveOverestimationSizeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, extraPrimitiveOverestimationSize);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, extraPrimitiveOverestimationSize);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthClipEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthClipEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthClipEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetSampleLocationsEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, sampleLocationsEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, sampleLocationsEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetColorBlendAdvancedEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstAttachment, attachmentCount, pColorBlendAdvanced);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetProvokingVertexModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, provokingVertexMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, provokingVertexMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineRasterizationModeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, lineRasterizationMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, lineRasterizationMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetLineStippleEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, stippledLineEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, stippledLineEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthClipNegativeOneToOneEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, negativeOneToOne);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, negativeOneToOne);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportWScalingEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, viewportWScalingEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, viewportWScalingEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetViewportSwizzleNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, firstViewport, viewportCount, pViewportSwizzles);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, firstViewport, viewportCount, pViewportSwizzles);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageToColorEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageToColorEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageToColorEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageToColorLocationNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageToColorLocation);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageToColorLocation);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageModulationModeNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageModulationMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageModulationMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageModulationTableEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageModulationTableEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageModulationTableEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageModulationTableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageModulationTableCount, pCoverageModulationTable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageModulationTableCount, pCoverageModulationTable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetShadingRateImageEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, shadingRateImageEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, shadingRateImageEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRepresentativeFragmentTestEnableNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, representativeFragmentTestEnable);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, representativeFragmentTestEnable);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetCoverageReductionModeNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, coverageReductionMode);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, coverageReductionMode);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyTensorARM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyTensorInfoARM*                  pCopyTensorInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyTensorARM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pCopyTensorInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pCopyTensorInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdOpticalFlowExecuteNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, session, pExecuteInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, session, pExecuteInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindShadersEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, stageCount, pStages, pShaders);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, stageCount, pStages, pShaders);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    const VkDepthClampRangeEXT*                 pDepthClampRange)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetDepthClampRangeEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, depthClampMode, pDepthClampRange);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, depthClampMode, pDepthClampRange);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkConvertCooperativeVectorMatrixInfoNV* pInfos)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdConvertCooperativeVectorMatrixNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, infoCount, pInfos);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, infoCount, pInfos);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkDataGraphPipelineSessionARM               session,
    const VkDataGraphPipelineDispatchInfoARM*   pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDispatchDataGraphARM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, session, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, session, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetAttachmentFeedbackLoopEnableEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, aspectMask);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, aspectMask);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkTileMemoryBindInfoQCOM*             pTileMemoryBindInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBindTileMemoryQCOM;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pTileMemoryBindInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pTileMemoryBindInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkDecompressMemoryInfoEXT*            pDecompressMemoryInfoEXT)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDecompressMemoryEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pDecompressMemoryInfoEXT);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pDecompressMemoryInfoEXT);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkMemoryDecompressionMethodFlagsEXT         decompressionMethod,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    maxDecompressionCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDecompressMemoryIndirectCountEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBuildPartitionedAccelerationStructuresNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pBuildInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pBuildInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoEXT*           pGeneratedCommandsInfo,
    VkCommandBuffer                             stateCommandBuffer)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdPreprocessGeneratedCommandsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pGeneratedCommandsInfo, stateCommandBuffer);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pGeneratedCommandsInfo, stateCommandBuffer);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoEXT*           pGeneratedCommandsInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdExecuteGeneratedCommandsEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, isPreprocessed, pGeneratedCommandsInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, isPreprocessed, pGeneratedCommandsInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingEndInfoKHR*                pRenderingEndInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdEndRendering2EXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pRenderingEndInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pRenderingEndInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkBeginCustomResolveInfoEXT*          pBeginCustomResolveInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBeginCustomResolveEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pBeginCustomResolveInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pBeginCustomResolveInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkComputeOccupancyPriorityParametersNV* pParameters)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetComputeOccupancyPriorityNV;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pParameters);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pParameters);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetPrimitiveRestartIndexEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    primitiveRestartIndex)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetPrimitiveRestartIndexEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, primitiveRestartIndex);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, primitiveRestartIndex);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdBuildAccelerationStructuresKHR;
        OverrideCmdBuildAccelerationStructuresKHR(call_info, func, commandBuffer, infoCount, pInfos, ppBuildRangeInfos, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const *                     ppMaxPrimitiveCounts)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdBuildAccelerationStructuresIndirectKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo,
    bool before_command)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdCopyAccelerationStructureKHR;
        OverrideCmdCopyAccelerationStructureKHR(call_info, func, commandBuffer, pInfo, before_command);
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyAccelerationStructureToMemoryKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdCopyMemoryToAccelerationStructureKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pInfo);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pInfo);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    const VulkanQueryPoolInfo*                  queryPool,
    uint32_t                                    firstQuery)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdWriteAccelerationStructuresPropertiesKHR;
        OverrideCmdWriteAccelerationStructuresPropertiesKHR(call_info, func, commandBuffer, accelerationStructureCount, pAccelerationStructures->GetPointer(), queryType, queryPool, firstQuery);
    }
}

void VulkanReplayDumpResources::Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdTraceRaysKHR;
        OverrideCmdTraceRaysKHR(call_info, func, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
    }
}

void VulkanReplayDumpResources::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    if (IsRecording())
    {
        auto injected = device_table.Open();
        const auto func = injected->CmdTraceRaysIndirectKHR;
        OverrideCmdTraceRaysIndirectKHR(call_info, func, commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
    }
}

void VulkanReplayDumpResources::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdSetRayTracingPipelineStackSizeKHR;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, pipelineStackSize);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, pipelineStackSize);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, groupCountX, groupCountY, groupCountZ);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, groupCountX, groupCountY, groupCountZ);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirectEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset, drawCount, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset, drawCount, stride);
                }
            }
        }
    }
}

void VulkanReplayDumpResources::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    const graphics::VulkanInjectedDeviceCalls&  device_table,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    if (IsRecording())
    {
        const std::vector<std::shared_ptr<DrawCallsDumpingContext>> dc_contexts = FindDrawCallDumpingContexts(commandBuffer);
        const std::vector<std::shared_ptr<DispatchTraceRaysDumpingContext>> dr_contexts = FindDispatchTraceRaysContexts(commandBuffer);
        if (!dc_contexts.empty() || !dr_contexts.empty())
        {
            auto injected = device_table.Open();
            const auto func = injected->CmdDrawMeshTasksIndirectCountEXT;
            for (auto dc_context : dc_contexts)
            {
                CommandBufferIterator first, last;
                dc_context->GetDrawCallActiveCommandBuffers(first, last);
                for (CommandBufferIterator it = first; it < last; ++it)
                {
                    func(*it, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                }
            }

            for (auto dr_context : dr_contexts)
            {
                VkCommandBuffer dispatch_rays_command_buffer = dr_context->GetDispatchRaysCommandBuffer();
                if (dispatch_rays_command_buffer != VK_NULL_HANDLE)
                {
                    func(dispatch_rays_command_buffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
                }
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
