/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_EXTENSION_H
#define  GFXRECON_GENERATED_VULKAN_CPP_PRE_PROCESS_CONSUMER_EXTENSION_H

#include "generated/generated_vulkan_cpp_pre_process_consumer.h"
#include "util/defines.h"
#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanCppPreProcessConsumer::Process_vkAllocateCommandBuffers(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->commandPool);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pCommandBuffers->GetPointer(),
                                      pAllocateInfo->GetPointer()->commandBufferCount);
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers);
}
void VulkanCppPreProcessConsumer::Process_vkAllocateDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>* pAllocateInfo,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->descriptorPool);
    }

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->pSetLayouts.GetPointer(),
                                          pAllocateInfo->GetMetaStructPointer()->pSetLayouts.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pDescriptorSets->GetPointer(),
                                      pAllocateInfo->GetPointer()->descriptorSetCount);
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateDescriptorSets);
}
void VulkanCppPreProcessConsumer::Process_vkAllocateMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryAllocateInfo>* pAllocateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeviceMemory>*       pMemory)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pMemory->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkAllocateMemory);
}
void VulkanCppPreProcessConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer()->renderPass);
    }

    if (pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer()->framebuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBeginCommandBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkBindBufferMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            buffer,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    Intercept_vkBindBufferMemory(returnValue, device, buffer, memory, memoryOffset);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory);
}
void VulkanCppPreProcessConsumer::Process_vkBindImageMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    format::HandleId                            memory,
    VkDeviceSize                                memoryOffset)
{
    Intercept_vkBindImageMemory(returnValue, device, image, memory, memoryOffset);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQuery);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->renderPass);
    }

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->framebuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindDescriptorSets(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      layout);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pDescriptorSets->GetPointer(),
                                      descriptorSetCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindDescriptorSets);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipeline);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pBuffers->GetPointer(),
                                      bindingCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBlitImage(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstImage);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearAttachments);
}
void VulkanCppPreProcessConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearColorImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdClearDepthStencilImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstImage);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstImage);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyQueryPoolResults(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyQueryPoolResults);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatch);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchIndirect);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDraw);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexed);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirect);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirect);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass);
}
void VulkanCppPreProcessConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pCommandBuffers->GetPointer(),
                                      commandBufferCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteCommands);
}
void VulkanCppPreProcessConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPipelineBarrier(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < bufferMemoryBarrierCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < imageMemoryBarrierCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      layout);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushConstants);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetQueryPool);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstImage);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetBlendConstants);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBounds);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineWidth);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissor);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilCompareMask);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilReference);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilWriteMask);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewport);
}
void VulkanCppPreProcessConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdateBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWaitEvents(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pEvents->GetPointer(),
                                      eventCount);

    for (uint32_t idx = 0; idx < bufferMemoryBarrierCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < imageMemoryBarrierCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp);
}
void VulkanCppPreProcessConsumer::Process_vkCreateBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBuffer>*             pBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pBuffer->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCreateBufferView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkBufferView>*         pView)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->buffer);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pView->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateBufferView);
}
void VulkanCppPreProcessConsumer::Process_vkCreateCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkCommandPool>*        pCommandPool)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pCommandPool->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateCommandPool);
}
void VulkanCppPreProcessConsumer::Process_vkCreateComputePipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    if (pCreateInfos->GetMetaStructPointer()->stage != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->stage->module);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pPipelines->GetPointer(),
                                      createInfoCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateComputePipelines);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDescriptorPool->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorPool);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pCreateInfo->GetPointer()->bindingCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetPointer(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSetLayout->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorSetLayout);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDevice(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDeviceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDevice>*             pDevice)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDevice->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDevice);
}
void VulkanCppPreProcessConsumer::Process_vkCreateEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkEventCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkEvent>*              pEvent)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pEvent->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateEvent);
}
void VulkanCppPreProcessConsumer::Process_vkCreateFence(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pFence->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFence);
}
void VulkanCppPreProcessConsumer::Process_vkCreateFramebuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFramebufferCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFramebuffer>*        pFramebuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->renderPass);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pAttachments.GetPointer(),
                                          pCreateInfo->GetMetaStructPointer()->pAttachments.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pFramebuffer->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateFramebuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCreateGraphicsPipelines(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    for (uint32_t idx = 0; idx < pCreateInfos->GetPointer()->stageCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->pStages->GetMetaStructPointer()[idx].module);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].renderPass);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pPipelines->GetPointer(),
                                      createInfoCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateGraphicsPipelines);
}
void VulkanCppPreProcessConsumer::Process_vkCreateImage(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImage>*              pImage)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pImage->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImage);
}
void VulkanCppPreProcessConsumer::Process_vkCreateImageView(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkImageView>*          pView)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->image);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pView->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImageView);
}
void VulkanCppPreProcessConsumer::Process_vkCreateInstance(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    StructPointerDecoder<Decoded_VkInstanceCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkInstance>*           pInstance)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pInstance->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateInstance);
}
void VulkanCppPreProcessConsumer::Process_vkCreatePipelineCache(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineCache>*      pPipelineCache)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pPipelineCache->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineCache);
}
void VulkanCppPreProcessConsumer::Process_vkCreatePipelineLayout(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pSetLayouts.GetPointer(),
                                          pCreateInfo->GetMetaStructPointer()->pSetLayouts.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pPipelineLayout->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePipelineLayout);
}
void VulkanCppPreProcessConsumer::Process_vkCreateQueryPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkQueryPool>*          pQueryPool)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pQueryPool->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateQueryPool);
}
void VulkanCppPreProcessConsumer::Process_vkCreateRenderPass(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pRenderPass->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSampler(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSampler>*            pSampler)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSampler->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSampler);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSemaphore>*          pSemaphore)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSemaphore->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSemaphore);
}
void VulkanCppPreProcessConsumer::Process_vkCreateShaderModule(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderModule>*       pShaderModule)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pShaderModule->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShaderModule);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            bufferView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      bufferView);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyBufferView);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyCommandPool);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDescriptorPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorPool);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorPool);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDescriptorSetLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSetLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorSetLayout);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDevice);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyEvent);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            fence,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFence);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyFramebuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      framebuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyFramebuffer);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImage);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyImageView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      imageView);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyInstance);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipeline);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyPipelineCache(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineCache);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyPipelineLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            pipelineLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineLayout);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPipelineLayout);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyQueryPool);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      renderPass);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyRenderPass);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            sampler,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      sampler);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySampler);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySemaphore(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySemaphore);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyShaderModule(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      shaderModule);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}
void VulkanCppPreProcessConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}
void VulkanCppPreProcessConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkEndCommandBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkEnumeratePhysicalDevices(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
    HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pPhysicalDevices->GetPointer(),
                                      pPhysicalDeviceCount);
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDevices);
}
void VulkanCppPreProcessConsumer::Process_vkFlushMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < memoryRangeCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pMemoryRanges->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkFlushMappedMemoryRanges);
}
void VulkanCppPreProcessConsumer::Process_vkFreeCommandBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pCommandBuffers->GetPointer(),
                                      commandBufferCount);
    Post_APICall(format::ApiCallId::ApiCall_vkFreeCommandBuffers);
}
void VulkanCppPreProcessConsumer::Process_vkFreeDescriptorSets(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorPool);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pDescriptorSets->GetPointer(),
                                      descriptorSetCount);
    Post_APICall(format::ApiCallId::ApiCall_vkFreeDescriptorSets);
}
void VulkanCppPreProcessConsumer::Process_vkFreeMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkFreeMemory);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            buffer,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceMemoryCommitment(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryCommitment);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pQueue->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue);
}
void VulkanCppPreProcessConsumer::Process_vkGetEventStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkGetEventStatus);
}
void VulkanCppPreProcessConsumer::Process_vkGetFenceStatus(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            fence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceStatus);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSubresourceLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceImageFormatProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineCacheData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineCacheData);
}
void VulkanCppPreProcessConsumer::Process_vkGetQueryPoolResults(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueryPoolResults);
}
void VulkanCppPreProcessConsumer::Process_vkGetRenderAreaGranularity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            renderPass,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      renderPass);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderAreaGranularity);
}
void VulkanCppPreProcessConsumer::Process_vkInvalidateMappedMemoryRanges(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    memoryRangeCount,
    StructPointerDecoder<Decoded_VkMappedMemoryRange>* pMemoryRanges)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < memoryRangeCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pMemoryRanges->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkInvalidateMappedMemoryRanges);
}
void VulkanCppPreProcessConsumer::Process_vkMapMemory(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory);
}
void VulkanCppPreProcessConsumer::Process_vkMergePipelineCaches(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkPipelineCache>*      pSrcCaches)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstCache);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pSrcCaches->GetPointer(),
                                      srcCacheCount);
    Post_APICall(format::ApiCallId::ApiCall_vkMergePipelineCaches);
}
void VulkanCppPreProcessConsumer::Process_vkQueueBindSparse(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindSparseInfo>* pBindInfo,
    format::HandleId                            fence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfo->GetMetaStructPointer()[idx].pWaitSemaphores.GetPointer(),
                                          pBindInfo->GetMetaStructPointer()[idx].pWaitSemaphores.GetLength());
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->bufferBindCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pBufferBinds->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pBufferBinds->GetPointer()->bindCount; idx++) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pBufferBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->imageOpaqueBindCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetPointer()->bindCount; idx++) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->imageBindCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pImageBinds->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pImageBinds->GetPointer()->bindCount; idx++) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pImageBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfo->GetMetaStructPointer()[idx].pSignalSemaphores.GetPointer(),
                                          pBindInfo->GetMetaStructPointer()[idx].pSignalSemaphores.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBindSparse);
}
void VulkanCppPreProcessConsumer::Process_vkQueueSubmit(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo>* pSubmits,
    format::HandleId                            fence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pWaitSemaphores.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pWaitSemaphores.GetLength());
    }

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pCommandBuffers.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pCommandBuffers.GetLength());
    }

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pSignalSemaphores.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pSignalSemaphores.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}
void VulkanCppPreProcessConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueWaitIdle);
}
void VulkanCppPreProcessConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkResetCommandPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolResetFlags                     flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);
    Post_APICall(format::ApiCallId::ApiCall_vkResetCommandPool);
}
void VulkanCppPreProcessConsumer::Process_vkResetDescriptorPool(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorPool);
    Post_APICall(format::ApiCallId::ApiCall_vkResetDescriptorPool);
}
void VulkanCppPreProcessConsumer::Process_vkResetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkResetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkResetFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pFences->GetPointer(),
                                      fenceCount);
    Post_APICall(format::ApiCallId::ApiCall_vkResetFences);
}
void VulkanCppPreProcessConsumer::Process_vkSetEvent(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            event)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkSetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory);
}
void VulkanCppPreProcessConsumer::Process_vkUpdateDescriptorSets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    StructPointerDecoder<Decoded_VkCopyDescriptorSet>* pDescriptorCopies)
{
    AddHandles_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateDescriptorSets);
}
void VulkanCppPreProcessConsumer::Process_vkWaitForFences(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    fenceCount,
    HandlePointerDecoder<VkFence>*              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pFences->GetPointer(),
                                      fenceCount);
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForFences);
}
void VulkanCppPreProcessConsumer::Process_vkBindBufferMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    Intercept_vkBindBufferMemory2(returnValue, device, bindInfoCount, pBindInfos);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2);
}
void VulkanCppPreProcessConsumer::Process_vkBindImageMemory2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    Intercept_vkBindImageMemory2(returnValue, device, bindInfoCount, pBindInfos);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBase);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMask);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->descriptorSetLayout);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pipelineLayout);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDescriptorUpdateTemplate->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplate);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pYcbcrConversion->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversion);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDescriptorUpdateTemplate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorUpdateTemplate);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplate);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySamplerYcbcrConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      ycbcrConversion);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversion);
}
void VulkanCppPreProcessConsumer::Process_vkEnumeratePhysicalDeviceGroups(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    for (uint32_t idx = 0; idx < *(pPhysicalDeviceGroupCount->GetPointer()); idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPhysicalDeviceGroupProperties->GetMetaStructPointer()[idx].physicalDevices.GetPointer(),
                                          pPhysicalDeviceGroupProperties->GetMetaStructPointer()[idx].physicalDevices.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroups);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2);
}
void VulkanCppPreProcessConsumer::Process_vkGetDescriptorSetLayoutSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pCreateInfo->GetPointer()->bindingCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetPointer(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupport);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceGroupPeerMemoryFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeatures);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceQueue2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceQueueInfo2>* pQueueInfo,
    HandlePointerDecoder<VkQueue>*              pQueue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pQueue->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceQueue2);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSparseMemoryRequirements2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalBufferProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalFenceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFenceProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphoreProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFeatures2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMemoryProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2);
}
void VulkanCppPreProcessConsumer::Process_vkTrimCommandPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPool);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->renderPass);
    }

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->framebuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCount);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCount);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2);
}
void VulkanCppPreProcessConsumer::Process_vkCreateRenderPass2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pRenderPass->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferDeviceAddress(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddress);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddress);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddress(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddress);
}
void VulkanCppPreProcessConsumer::Process_vkGetSemaphoreCounterValue(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValue);
}
void VulkanCppPreProcessConsumer::Process_vkResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPool);
}
void VulkanCppPreProcessConsumer::Process_vkSignalSemaphore(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pSignalInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSignalInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphore);
}
void VulkanCppPreProcessConsumer::Process_vkWaitSemaphores(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pWaitInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pWaitInfo->GetMetaStructPointer()->pSemaphores.GetPointer(),
                                          pWaitInfo->GetMetaStructPointer()->pSemaphores.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphores);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].imageView);
    }

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->resolveImageView);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRendering);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pBuffers->GetPointer(),
                                      bindingCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pBlitImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBlitImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pBlitImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBlitImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferInfo->GetMetaStructPointer()->srcBuffer);
    }

    if (pCopyBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferInfo->GetMetaStructPointer()->dstBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyBufferToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferToImageInfo->GetMetaStructPointer()->srcBuffer);
    }

    if (pCopyBufferToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferToImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pCopyImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyImageToBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToBufferInfo->GetMetaStructPointer()->srcImage);
    }

    if (pCopyImageToBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToBufferInfo->GetMetaStructPointer()->dstBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRendering);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pResolveImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pResolveImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pResolveImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pResolveImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullMode);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOp);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFace);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopology);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCount);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOp);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnable);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCount);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pEvents->GetPointer(),
                                      eventCount);

    for (uint32_t idx = 0; idx < pDependencyInfos->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfos->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfos->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfos->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2);
}
void VulkanCppPreProcessConsumer::Process_vkCreatePrivateDataSlot(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pPrivateDataSlot->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlot);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyPrivateDataSlot(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlot);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceBufferMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceImageMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceImageSparseMemoryRequirements(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirements);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceToolProperties(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateData);
}
void VulkanCppPreProcessConsumer::Process_vkQueueSubmit2(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->waitSemaphoreInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pWaitSemaphoreInfos->GetMetaStructPointer()[idx].semaphore);
    }

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->commandBufferInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pCommandBufferInfos->GetMetaStructPointer()[idx].commandBuffer);
    }

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->signalSemaphoreInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pSignalSemaphoreInfos->GetMetaStructPointer()[idx].semaphore);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2);
}
void VulkanCppPreProcessConsumer::Process_vkSetPrivateData(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateData);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceSupportKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    format::HandleId                            surface,
    PointerDecoder<VkBool32>*                   pSupported)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireNextImage2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>* pAcquireInfo,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAcquireInfo->GetMetaStructPointer()->swapchain);
    }

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAcquireInfo->GetMetaStructPointer()->semaphore);
    }

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAcquireInfo->GetMetaStructPointer()->fence);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImage2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireNextImageKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    timeout,
    format::HandleId                            semaphore,
    format::HandleId                            fence,
    PointerDecoder<uint32_t>*                   pImageIndex)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireNextImageKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSwapchainKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain)
{
    Intercept_vkCreateSwapchainKHR(returnValue, device, pCreateInfo, pAllocator, pSwapchain);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->surface);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->oldSwapchain);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSwapchain->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSwapchainKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySwapchainKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySwapchainKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceGroupPresentCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPresentCapabilitiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceGroupSurfacePresentModesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            surface,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDevicePresentRectanglesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    PointerDecoder<uint32_t>*                   pRectCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pRects)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDevicePresentRectanglesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetSwapchainImagesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pSwapchainImageCount,
    HandlePointerDecoder<VkImage>*              pSwapchainImages)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pSwapchainImages->GetPointer(),
                                      pSwapchainImageCount);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkQueuePresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkPresentInfoKHR>* pPresentInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    if (pPresentInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPresentInfo->GetMetaStructPointer()->pWaitSemaphores.GetPointer(),
                                          pPresentInfo->GetMetaStructPointer()->pWaitSemaphores.GetLength());
    }

    if (pPresentInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPresentInfo->GetMetaStructPointer()->pSwapchains.GetPointer(),
                                          pPresentInfo->GetMetaStructPointer()->pSwapchains.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkQueuePresentKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDisplayModeKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDisplayModeKHR>*     pMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pMode->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayModeKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDisplayPlaneSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->displayMode);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDisplayPlaneSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDisplayModePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);

    for (uint32_t idx = 0; idx < *(pPropertyCount->GetPointer()); idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pProperties->GetMetaStructPointer()[idx].displayMode);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDisplayPlaneCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            mode,
    uint32_t                                    planeIndex,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      mode);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilitiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDisplayPlaneSupportedDisplaysKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    planeIndex,
    PointerDecoder<uint32_t>*                   pDisplayCount,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplays)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pDisplays->GetPointer(),
                                      pDisplayCount);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneSupportedDisplaysKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    for (uint32_t idx = 0; idx < *(pPropertyCount->GetPointer()); idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pProperties->GetMetaStructPointer()[idx].currentDisplay);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    for (uint32_t idx = 0; idx < *(pPropertyCount->GetPointer()); idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pProperties->GetMetaStructPointer()[idx].display);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSharedSwapchainsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < swapchainCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].surface);
    }

    for (uint32_t idx = 0; idx < swapchainCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].oldSwapchain);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pSwapchains->GetPointer(),
                                      swapchainCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSharedSwapchainsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateXlibSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXlibSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dpy,
    size_t                                      visualID)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXlibPresentationSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateXcbSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    connection,
    uint32_t                                    visual_id)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceXcbPresentationSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateWaylandSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWaylandSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateAndroidSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateWin32SurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateWin32SurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceWin32PresentationSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkBindVideoSessionMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    uint32_t                                    bindSessionMemoryInfoCount,
    StructPointerDecoder<Decoded_VkBindVideoSessionMemoryInfoKHR>* pBindSessionMemoryInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      videoSession);

    for (uint32_t idx = 0; idx < bindSessionMemoryInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindSessionMemoryInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindVideoSessionMemoryKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pBeginInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBeginInfo->GetMetaStructPointer()->videoSession);
    }

    if (pBeginInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBeginInfo->GetMetaStructPointer()->videoSessionParameters);
    }

    if (pBeginInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer() != nullptr) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBeginInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer()->imageViewBinding);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginVideoCodingKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdControlVideoCodingKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndVideoCodingKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionKHR>*    pVideoSession)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pVideoSession->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoSessionParametersCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkVideoSessionParametersKHR>* pVideoSessionParameters)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->videoSessionParametersTemplate);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->videoSession);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pVideoSessionParameters->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateVideoSessionParametersKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyVideoSessionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      videoSession);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      videoSessionParameters);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyVideoSessionParametersKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceVideoCapabilitiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile,
    StructPointerDecoder<Decoded_VkVideoCapabilitiesKHR>* pCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoCapabilitiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceVideoFormatPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoFormatInfoKHR>* pVideoFormatInfo,
    PointerDecoder<uint32_t>*                   pVideoFormatPropertyCount,
    StructPointerDecoder<Decoded_VkVideoFormatPropertiesKHR>* pVideoFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoFormatPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetVideoSessionMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSession,
    PointerDecoder<uint32_t>*                   pMemoryRequirementsCount,
    StructPointerDecoder<Decoded_VkVideoSessionMemoryRequirementsKHR>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      videoSession);
    Post_APICall(format::ApiCallId::ApiCall_vkGetVideoSessionMemoryRequirementsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkUpdateVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            videoSessionParameters,
    StructPointerDecoder<Decoded_VkVideoSessionParametersUpdateInfoKHR>* pUpdateInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      videoSessionParameters);
    Post_APICall(format::ApiCallId::ApiCall_vkUpdateVideoSessionParametersKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pDecodeInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pDecodeInfo->GetMetaStructPointer()->srcBuffer);
    }

    if (pDecodeInfo->GetMetaStructPointer()->dstPictureResource != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDecodeInfo->GetMetaStructPointer()->dstPictureResource->imageViewBinding);
    }

    if (pDecodeInfo->GetMetaStructPointer()->pSetupReferenceSlot->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer() != nullptr) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pDecodeInfo->GetMetaStructPointer()->pSetupReferenceSlot->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer()->imageViewBinding);
    }

    if (pDecodeInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer() != nullptr) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pDecodeInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer()->imageViewBinding);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDecodeVideoKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].imageView);
    }

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->resolveImageView);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderingKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderingKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFeatures2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFormatProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>* pImageFormatInfo,
    StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
    StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>* pFormatInfo,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDispatchBaseKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDeviceMaskKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupPeerMemoryFeaturesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
}
void VulkanCppPreProcessConsumer::Process_vkEnumeratePhysicalDeviceGroupsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    for (uint32_t idx = 0; idx < *(pPhysicalDeviceGroupCount->GetPointer()); idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPhysicalDeviceGroupProperties->GetMetaStructPointer()[idx].physicalDevices.GetPointer(),
                                          pPhysicalDeviceGroupProperties->GetMetaStructPointer()[idx].physicalDevices.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceGroupsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>* pExternalBufferInfo,
    StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetWin32HandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetWin32HandleInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryWin32HandlePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    handle,
    StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandlePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetFdInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetFdInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryFdPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryFdPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>* pExternalSemaphoreInfo,
    StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetWin32HandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetWin32HandleInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreWin32HandleKHR);
}
void VulkanCppPreProcessConsumer::Process_vkImportSemaphoreWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>* pImportSemaphoreWin32HandleInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pImportSemaphoreWin32HandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImportSemaphoreWin32HandleInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreWin32HandleKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetFdInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetFdInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreFdKHR);
}
void VulkanCppPreProcessConsumer::Process_vkImportSemaphoreFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>* pImportSemaphoreFdInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pImportSemaphoreFdInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImportSemaphoreFdInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreFdKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      layout);

    for (uint32_t idx = 0; idx < descriptorWriteCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pDescriptorWrites->GetMetaStructPointer()[idx].dstSet);
    }

    for (uint32_t idx = 0; idx < pDescriptorWrites->GetPointer()->descriptorCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDescriptorWrites->GetMetaStructPointer()->pImageInfo->GetMetaStructPointer()[idx].sampler);
    }

    for (uint32_t idx = 0; idx < pDescriptorWrites->GetPointer()->descriptorCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDescriptorWrites->GetMetaStructPointer()->pImageInfo->GetMetaStructPointer()[idx].imageView);
    }

    for (uint32_t idx = 0; idx < pDescriptorWrites->GetPointer()->descriptorCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDescriptorWrites->GetMetaStructPointer()->pBufferInfo->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < descriptorWriteCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pDescriptorWrites->GetMetaStructPointer()[idx].pTexelBufferView.GetPointer(),
                                          pDescriptorWrites->GetMetaStructPointer()[idx].pTexelBufferView.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPushDescriptorSetKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->descriptorSetLayout);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pipelineLayout);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDescriptorUpdateTemplate->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDescriptorUpdateTemplateKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorUpdateTemplate,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorUpdateTemplate);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorUpdateTemplateKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->renderPass);
    }

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->framebuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginRenderPass2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndRenderPass2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdNextSubpass2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderPassCreateInfo2>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkRenderPass>*         pRenderPass)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pRenderPass->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetSwapchainStatusKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainStatusKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>* pExternalFenceInfo,
    StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalFencePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>* pGetWin32HandleInfo,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetWin32HandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetWin32HandleInfo->GetMetaStructPointer()->fence);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceWin32HandleKHR);
}
void VulkanCppPreProcessConsumer::Process_vkImportFenceWin32HandleKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>* pImportFenceWin32HandleInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pImportFenceWin32HandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImportFenceWin32HandleInfo->GetMetaStructPointer()->fence);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceWin32HandleKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>* pGetFdInfo,
    PointerDecoder<int>*                        pFd)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetFdInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetFdInfo->GetMetaStructPointer()->fence);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetFenceFdKHR);
}
void VulkanCppPreProcessConsumer::Process_vkImportFenceFdKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>* pImportFenceFdInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pImportFenceFdInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImportFenceFdInfo->GetMetaStructPointer()->fence);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkImportFenceFdKHR);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAcquireProfilingLockInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireProfilingLockKHR);
}
void VulkanCppPreProcessConsumer::Process_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    PointerDecoder<uint32_t>*                   pCounterCount,
    StructPointerDecoder<Decoded_VkPerformanceCounterKHR>* pCounters,
    StructPointerDecoder<Decoded_VkPerformanceCounterDescriptionKHR>* pCounterDescriptions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkQueryPoolPerformanceCreateInfoKHR>* pPerformanceQueryCreateInfo,
    PointerDecoder<uint32_t>*                   pNumPasses)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkReleaseProfilingLockKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseProfilingLockKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pSurfaceInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSurfaceInfo->GetMetaStructPointer()->surface);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
    StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pSurfaceInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSurfaceInfo->GetMetaStructPointer()->surface);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDisplayModeProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);

    if (pProperties->GetMetaStructPointer()->displayModeProperties != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pProperties->GetMetaStructPointer()->displayModeProperties->displayMode);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayModeProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDisplayPlaneCapabilities2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>* pDisplayPlaneInfo,
    StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pDisplayPlaneInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pDisplayPlaneInfo->GetMetaStructPointer()->mode);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDisplayPlaneCapabilities2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pProperties->GetMetaStructPointer()->displayPlaneProperties != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pProperties->GetMetaStructPointer()->displayPlaneProperties->currentDisplay);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceDisplayProperties2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pProperties->GetMetaStructPointer()->displayProperties != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pProperties->GetMetaStructPointer()->displayProperties->display);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDisplayProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageMemoryRequirements2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSparseMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateSamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pYcbcrConversion->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateSamplerYcbcrConversionKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySamplerYcbcrConversionKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            ycbcrConversion,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      ycbcrConversion);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroySamplerYcbcrConversionKHR);
}
void VulkanCppPreProcessConsumer::Process_vkBindBufferMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>* pBindInfos)
{
    Intercept_vkBindBufferMemory2KHR(returnValue, device, bindInfoCount, pBindInfos);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindBufferMemory2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkBindImageMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindImageMemoryInfo>* pBindInfos)
{
    Intercept_vkBindImageMemory2KHR(returnValue, device, bindInfoCount, pBindInfos);
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindImageMemory2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDescriptorSetLayoutSupportKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pCreateInfo->GetPointer()->bindingCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetPointer(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutSupportKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetSemaphoreCounterValueKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    PointerDecoder<uint64_t>*                   pValue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreCounterValueKHR);
}
void VulkanCppPreProcessConsumer::Process_vkSignalSemaphoreKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreSignalInfo>* pSignalInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pSignalInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSignalInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkSignalSemaphoreKHR);
}
void VulkanCppPreProcessConsumer::Process_vkWaitSemaphoresKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreWaitInfo>* pWaitInfo,
    uint64_t                                    timeout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pWaitInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pWaitInfo->GetMetaStructPointer()->pSemaphores.GetPointer(),
                                          pWaitInfo->GetMetaStructPointer()->pSemaphores.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkWaitSemaphoresKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFragmentShadingRatesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pFragmentShadingRateCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFragmentShadingRateKHR>* pFragmentShadingRates)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceFragmentShadingRatesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkWaitForPresentKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    uint64_t                                    presentId,
    uint64_t                                    timeout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForPresentKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferOpaqueCaptureAddressKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceMemoryOpaqueCaptureAddressKHR(
    const ApiCallInfo&                          call_info,
    uint64_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMemoryOpaqueCaptureAddressKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDeferredOperationKHR>* pDeferredOperation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDeferredOperation->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDeferredOperationKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDeferredOperationJoinKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      operation);
    Post_APICall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDeferredOperationKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            operation,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      operation);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDeferredOperationKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeferredOperationMaxConcurrencyKHR(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      operation);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationMaxConcurrencyKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeferredOperationResultKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            operation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      operation);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeferredOperationResultKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineExecutableInternalRepresentationsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pExecutableInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pExecutableInfo->GetMetaStructPointer()->pipeline);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableInternalRepresentationsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineExecutablePropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineInfoKHR>* pPipelineInfo,
    PointerDecoder<uint32_t>*                   pExecutableCount,
    StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pPipelineInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPipelineInfo->GetMetaStructPointer()->pipeline);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutablePropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineExecutableStatisticsKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>* pExecutableInfo,
    PointerDecoder<uint32_t>*                   pStatisticCount,
    StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pExecutableInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pExecutableInfo->GetMetaStructPointer()->pipeline);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineExecutableStatisticsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkMapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryMapInfoKHR>* pMemoryMapInfo,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pMemoryMapInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pMemoryMapInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkMapMemory2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkUnmapMemory2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryUnmapInfoKHR>* pMemoryUnmapInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pMemoryUnmapInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pMemoryUnmapInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkUnmapMemory2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pEncodeInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pEncodeInfo->GetMetaStructPointer()->dstBuffer);
    }

    if (pEncodeInfo->GetMetaStructPointer()->srcPictureResource != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pEncodeInfo->GetMetaStructPointer()->srcPictureResource->imageViewBinding);
    }

    if (pEncodeInfo->GetMetaStructPointer()->pSetupReferenceSlot->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer() != nullptr) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pEncodeInfo->GetMetaStructPointer()->pSetupReferenceSlot->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer()->imageViewBinding);
    }

    if (pEncodeInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer() != nullptr) {
                resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pEncodeInfo->GetMetaStructPointer()->pReferenceSlots->GetMetaStructPointer()->pPictureResource->GetMetaStructPointer()->imageViewBinding);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEncodeVideoKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetEncodedVideoSessionParametersKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersGetInfoKHR>* pVideoSessionParametersInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR>* pFeedbackInfo,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pVideoSessionParametersInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pVideoSessionParametersInfo->GetMetaStructPointer()->videoSessionParameters);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetEncodedVideoSessionParametersKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR>* pQualityLevelInfo,
    StructPointerDecoder<Decoded_VkVideoEncodeQualityLevelPropertiesKHR>* pQualityLevelProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPipelineBarrier2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResetEvent2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfo->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfo->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pEvents->GetPointer(),
                                      eventCount);

    for (uint32_t idx = 0; idx < pDependencyInfos->GetPointer()->bufferMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfos->GetMetaStructPointer()->pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pDependencyInfos->GetPointer()->imageMemoryBarrierCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pDependencyInfos->GetMetaStructPointer()->pImageMemoryBarriers->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWaitEvents2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarker2AMD);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetQueueCheckpointData2NV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointData2NV>* pCheckpointData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointData2NV);
}
void VulkanCppPreProcessConsumer::Process_vkQueueSubmit2KHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    uint32_t                                    submitCount,
    StructPointerDecoder<Decoded_VkSubmitInfo2>* pSubmits,
    format::HandleId                            fence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->waitSemaphoreInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pWaitSemaphoreInfos->GetMetaStructPointer()[idx].semaphore);
    }

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->commandBufferInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pCommandBufferInfos->GetMetaStructPointer()[idx].commandBuffer);
    }

    for (uint32_t idx = 0; idx < pSubmits->GetPointer()->signalSemaphoreInfoCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pSubmits->GetMetaStructPointer()->pSignalSemaphoreInfos->GetMetaStructPointer()[idx].semaphore);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pBlitImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBlitImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pBlitImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBlitImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBlitImage2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferInfo->GetMetaStructPointer()->srcBuffer);
    }

    if (pCopyBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferInfo->GetMetaStructPointer()->dstBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBuffer2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyBufferToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferToImageInfo->GetMetaStructPointer()->srcBuffer);
    }

    if (pCopyBufferToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyBufferToImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyBufferToImage2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pCopyImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImage2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pCopyImageToBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToBufferInfo->GetMetaStructPointer()->srcImage);
    }

    if (pCopyImageToBufferInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToBufferInfo->GetMetaStructPointer()->dstBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyImageToBuffer2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pResolveImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pResolveImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pResolveImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pResolveImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirect2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceBufferMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceBufferMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceBufferMemoryRequirementsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceImageMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageMemoryRequirementsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceImageSparseMemoryRequirementsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageMemoryRequirements>* pInfo,
    PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
    StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSparseMemoryRequirementsKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindIndexBuffer2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceImageSubresourceLayoutKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceImageSubresourceInfoKHR>* pInfo,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceImageSubresourceLayoutKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSubresourceLayout2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetRenderingAreaGranularityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingAreaInfoKHR>* pRenderingAreaInfo,
    StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRenderingAreaGranularityKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesKHR>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkFrameBoundaryANDROID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            semaphore,
    format::HandleId                            image)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkFrameBoundaryANDROID);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pCallback->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugReportCallbackEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDebugReportMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    StringDecoder*                              pLayerPrefix,
    StringDecoder*                              pMessage)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugReportMessageEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDebugReportCallbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            callback,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      callback);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugReportCallbackEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerBeginEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerEndEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDebugMarkerInsertEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDebugMarkerSetObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>* pNameInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectNameEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDebugMarkerSetObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>* pTagInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkDebugMarkerSetObjectTagEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pCounterBuffers->GetPointer(),
                                      counterBufferCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginTransformFeedbackEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pBuffers->GetPointer(),
                                      bindingCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindTransformFeedbackBuffersEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      counterBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectByteCountEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pCounterBuffers->GetPointer(),
                                      counterBufferCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndTransformFeedbackEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageViewAddressNVX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            imageView,
    StructPointerDecoder<Decoded_VkImageViewAddressPropertiesNVX>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      imageView);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewAddressNVX);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageViewHandleNVX(
    const ApiCallInfo&                          call_info,
    uint32_t                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->imageView);
    }

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->sampler);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageViewHandleNVX);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndexedIndirectCountAMD);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountAMD);
}
void VulkanCppPreProcessConsumer::Process_vkGetShaderInfoAMD(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    PointerDecoder<size_t>*                     pInfoSize,
    PointerDecoder<uint8_t>*                    pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderInfoAMD);
}
void VulkanCppPreProcessConsumer::Process_vkCreateStreamDescriptorSurfaceGGP(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateStreamDescriptorSurfaceGGP);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryWin32HandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryWin32HandleNV);
}
void VulkanCppPreProcessConsumer::Process_vkCreateViSurfaceNN(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateViSurfaceNN);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pConditionalRenderingBegin->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pConditionalRenderingBegin->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginConditionalRenderingEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndConditionalRenderingEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingNV);
}
void VulkanCppPreProcessConsumer::Process_vkReleaseDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseDisplayEXT);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireXlibDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    format::HandleId                            display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireXlibDisplayEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetRandROutputDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint64_t                                    dpy,
    size_t                                      rrOutput,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDisplay->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkGetRandROutputDisplayEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      surface);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkDisplayPowerControlEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>* pDisplayPowerInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);
    Post_APICall(format::ApiCallId::ApiCall_vkDisplayPowerControlEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetSwapchainCounterEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    PointerDecoder<uint64_t>*                   pCounterValue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkGetSwapchainCounterEXT);
}
void VulkanCppPreProcessConsumer::Process_vkRegisterDeviceEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>* pDeviceEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pFence->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDeviceEventEXT);
}
void VulkanCppPreProcessConsumer::Process_vkRegisterDisplayEventEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            display,
    StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>* pDisplayEventInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkFence>*              pFence)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pFence->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkRegisterDisplayEventEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPastPresentationTimingGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    PointerDecoder<uint32_t>*                   pPresentationTimingCount,
    StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPastPresentationTimingGOOGLE);
}
void VulkanCppPreProcessConsumer::Process_vkGetRefreshCycleDurationGOOGLE(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain,
    StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRefreshCycleDurationGOOGLE);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDiscardRectangleModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkSetHdrMetadataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    uint32_t                                    swapchainCount,
    HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains,
    StructPointerDecoder<Decoded_VkHdrMetadataEXT>* pMetadata)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pSwapchains->GetPointer(),
                                      swapchainCount);
    Post_APICall(format::ApiCallId::ApiCall_vkSetHdrMetadataEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateIOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIOSSurfaceMVK);
}
void VulkanCppPreProcessConsumer::Process_vkCreateMacOSSurfaceMVK(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMacOSSurfaceMVK);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBeginDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdInsertDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pMessenger->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDebugUtilsMessengerEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDebugUtilsMessengerEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            messenger,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      messenger);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDebugUtilsMessengerEXT);
}
void VulkanCppPreProcessConsumer::Process_vkQueueBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueBeginDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkQueueEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueEndDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkQueueInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueInsertDebugUtilsLabelEXT);
}
void VulkanCppPreProcessConsumer::Process_vkSetDebugUtilsObjectNameEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pNameInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectNameEXT);
}
void VulkanCppPreProcessConsumer::Process_vkSetDebugUtilsObjectTagEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>* pTagInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDebugUtilsObjectTagEXT);
}
void VulkanCppPreProcessConsumer::Process_vkSubmitDebugUtilsMessageEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>* pCallbackData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);
    Post_APICall(format::ApiCallId::ApiCall_vkSubmitDebugUtilsMessageEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetAndroidHardwareBufferPropertiesANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint64_t                                    buffer,
    StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetAndroidHardwareBufferPropertiesANDROID);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryAndroidHardwareBufferANDROID(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>* pInfo,
    PointerDecoder<uint64_t, void*>*            pBuffer)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryAndroidHardwareBufferANDROID);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMultisamplePropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageDrmFormatModifierPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageDrmFormatModifierPropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pValidationCache->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateValidationCacheEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyValidationCacheEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      validationCache);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyValidationCacheEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetValidationCacheDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            validationCache,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      validationCache);
    Post_APICall(format::ApiCallId::ApiCall_vkGetValidationCacheDataEXT);
}
void VulkanCppPreProcessConsumer::Process_vkMergeValidationCachesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            dstCache,
    uint32_t                                    srcCacheCount,
    HandlePointerDecoder<VkValidationCacheEXT>* pSrcCaches)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstCache);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pSrcCaches->GetPointer(),
                                      srcCacheCount);
    Post_APICall(format::ApiCallId::ApiCall_vkMergeValidationCachesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      imageView);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadingRateImageNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoarseSampleOrderNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportShadingRatePaletteNV);
}
void VulkanCppPreProcessConsumer::Process_vkBindAccelerationStructureMemoryNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    bindInfoCount,
    StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>* pBindInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].accelerationStructure);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfos->GetMetaStructPointer()[idx].memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBindAccelerationStructureMemoryNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dst);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      src);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pAccelerationStructures->GetPointer(),
                                      accelerationStructureCount);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesNV);
}
void VulkanCppPreProcessConsumer::Process_vkCompileDeferredNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    shader)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkCompileDeferredNV);
}
void VulkanCppPreProcessConsumer::Process_vkCreateRayTracingPipelinesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    for (uint32_t idx = 0; idx < pCreateInfos->GetPointer()->stageCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->pStages->GetMetaStructPointer()[idx].module);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pPipelines->GetPointer(),
                                      createInfoCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesNV);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      accelerationStructure);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetAccelerationStructureHandleNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      accelerationStructure);
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureHandleNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetAccelerationStructureMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->accelerationStructure);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureMemoryRequirementsNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetRayTracingShaderGroupHandlesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupHandlesNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryHostPointerPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint64_t                                    pHostPointer,
    StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryHostPointerPropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteBufferMarkerAMD);
}
void VulkanCppPreProcessConsumer::Process_vkGetCalibratedTimestampsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    timestampCount,
    StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>* pTimestampInfos,
    PointerDecoder<uint64_t>*                   pTimestamps,
    PointerDecoder<uint64_t>*                   pMaxDeviation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetCalibratedTimestampsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pTimeDomainCount,
    PointerDecoder<VkTimeDomainEXT>*            pTimeDomains)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExclusiveScissorNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCheckpointNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetQueueCheckpointDataNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            queue,
    PointerDecoder<uint32_t>*                   pCheckpointDataCount,
    StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);
    Post_APICall(format::ApiCallId::ApiCall_vkGetQueueCheckpointDataNV);
}
void VulkanCppPreProcessConsumer::Process_vkAcquirePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>* pAcquireInfo,
    HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pConfiguration->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkAcquirePerformanceConfigurationINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceMarkerINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceOverrideINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPerformanceStreamMarkerINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkGetPerformanceParameterINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkPerformanceParameterTypeINTEL             parameter,
    StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPerformanceParameterINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkInitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>* pInitializeInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkInitializePerformanceApiINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkQueueSetPerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue,
    format::HandleId                            configuration)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      configuration);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSetPerformanceConfigurationINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkReleasePerformanceConfigurationINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            configuration)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      configuration);
    Post_APICall(format::ApiCallId::ApiCall_vkReleasePerformanceConfigurationINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkUninitializePerformanceApiINTEL(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkUninitializePerformanceApiINTEL);
}
void VulkanCppPreProcessConsumer::Process_vkSetLocalDimmingAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            swapChain,
    VkBool32                                    localDimmingEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapChain);
    Post_APICall(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD);
}
void VulkanCppPreProcessConsumer::Process_vkCreateImagePipeSurfaceFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateImagePipeSurfaceFUCHSIA);
}
void VulkanCppPreProcessConsumer::Process_vkCreateMetalSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMetalSurfaceEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferDeviceAddressEXT(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferDeviceAddressInfo>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->buffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetBufferDeviceAddressEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceToolPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pToolCount,
    StructPointerDecoder<Decoded_VkPhysicalDeviceToolProperties>* pToolProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceToolPropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pPropertyCount,
    StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    PointerDecoder<uint32_t>*                   pCombinationCount,
    StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceGroupSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pSurfaceInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSurfaceInfo->GetMetaStructPointer()->surface);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>* pSurfaceInfo,
    PointerDecoder<uint32_t>*                   pPresentModeCount,
    PointerDecoder<VkPresentModeKHR>*           pPresentModes)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    if (pSurfaceInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSurfaceInfo->GetMetaStructPointer()->surface);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkReleaseFullScreenExclusiveModeEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            swapchain)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateHeadlessSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateHeadlessSurfaceEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEXT);
}
void VulkanCppPreProcessConsumer::Process_vkResetQueryPoolEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkResetQueryPoolEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pBuffers->GetPointer(),
                                      bindingCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindVertexBuffers2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCullModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBoundsTestEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthCompareOpEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthTestEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthWriteEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFrontFaceEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveTopologyEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetScissorWithCountEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilOpEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetStencilTestEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWithCountEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyImageToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToImageInfoEXT>* pCopyImageToImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCopyImageToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToImageInfo->GetMetaStructPointer()->srcImage);
    }

    if (pCopyImageToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToImageEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyImageToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyImageToMemoryInfoEXT>* pCopyImageToMemoryInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCopyImageToMemoryInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyImageToMemoryInfo->GetMetaStructPointer()->srcImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyImageToMemoryEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyMemoryToImageEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageInfoEXT>* pCopyMemoryToImageInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCopyMemoryToImageInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCopyMemoryToImageInfo->GetMetaStructPointer()->dstImage);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToImageEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetImageSubresourceLayout2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            image,
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource,
    StructPointerDecoder<Decoded_VkSubresourceLayout2KHR>* pLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkTransitionImageLayoutEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    transitionCount,
    StructPointerDecoder<Decoded_VkHostImageLayoutTransitionInfoEXT>* pTransitions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < transitionCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pTransitions->GetMetaStructPointer()[idx].image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkTransitionImageLayoutEXT);
}
void VulkanCppPreProcessConsumer::Process_vkReleaseSwapchainImagesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkReleaseSwapchainImagesInfoEXT>* pReleaseInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pReleaseInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pReleaseInfo->GetMetaStructPointer()->swapchain);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkReleaseSwapchainImagesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindPipelineShaderGroupNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->pipeline);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->indirectCommandsLayout);
    }

    for (uint32_t idx = 0; idx < pGeneratedCommandsInfo->GetPointer()->streamCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pGeneratedCommandsInfo->GetMetaStructPointer()->pStreams->GetMetaStructPointer()[idx].buffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->preprocessBuffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->sequencesCountBuffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->sequencesIndexBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdExecuteGeneratedCommandsNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->pipeline);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->indirectCommandsLayout);
    }

    for (uint32_t idx = 0; idx < pGeneratedCommandsInfo->GetPointer()->streamCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pGeneratedCommandsInfo->GetMetaStructPointer()->pStreams->GetMetaStructPointer()[idx].buffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->preprocessBuffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->sequencesCountBuffer);
    }

    if (pGeneratedCommandsInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGeneratedCommandsInfo->GetMetaStructPointer()->sequencesIndexBuffer);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdPreprocessGeneratedCommandsNV);
}
void VulkanCppPreProcessConsumer::Process_vkCreateIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkIndirectCommandsLayoutNV>* pIndirectCommandsLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pCreateInfo->GetPointer()->tokenCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->pTokens->GetMetaStructPointer()[idx].pushconstantPipelineLayout);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pIndirectCommandsLayout->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateIndirectCommandsLayoutNV);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyIndirectCommandsLayoutNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            indirectCommandsLayout,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      indirectCommandsLayout);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyIndirectCommandsLayoutNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetGeneratedCommandsMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->pipeline);
    }

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->indirectCommandsLayout);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetGeneratedCommandsMemoryRequirementsNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBias2EXT);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    format::HandleId                            display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireDrmDisplayEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetDrmDisplayEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    int32_t                                     drmFd,
    uint32_t                                    connectorId,
    HandlePointerDecoder<VkDisplayKHR>*         display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *display->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkGetDrmDisplayEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreatePrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPrivateDataSlotCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPrivateDataSlot>*    pPrivateDataSlot)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pPrivateDataSlot->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreatePrivateDataSlotEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyPrivateDataSlotEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            privateDataSlot,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyPrivateDataSlotEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    PointerDecoder<uint64_t>*                   pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPrivateDataEXT);
}
void VulkanCppPreProcessConsumer::Process_vkSetPrivateDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkObjectType                                objectType,
    uint64_t                                    objectHandle,
    format::HandleId                            privateDataSlot,
    uint64_t                                    data)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      privateDataSlot);
    Post_APICall(format::ApiCallId::ApiCall_vkSetPrivateDataEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetFragmentShadingRateEnumNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceFaultInfoEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDeviceFaultCountsEXT>* pFaultCounts,
    StructPointerDecoder<Decoded_VkDeviceFaultInfoEXT>* pFaultInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceFaultInfoEXT);
}
void VulkanCppPreProcessConsumer::Process_vkAcquireWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    format::HandleId                            display)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      display);
    Post_APICall(format::ApiCallId::ApiCall_vkAcquireWinrtDisplayNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetWinrtDisplayNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    deviceRelativeId,
    HandlePointerDecoder<VkDisplayKHR>*         pDisplay)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pDisplay->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkGetWinrtDisplayNV);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDirectFBSurfaceEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkDirectFBSurfaceCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateDirectFBSurfaceEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceDirectFBPresentationSupportEXT(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    dfb)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetVertexInputEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetZirconHandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetZirconHandleInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandleFUCHSIA);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryZirconHandlePropertiesFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    uint32_t                                    zirconHandle,
    StructPointerDecoder<Decoded_VkMemoryZirconHandlePropertiesFUCHSIA>* pMemoryZirconHandleProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryZirconHandlePropertiesFUCHSIA);
}
void VulkanCppPreProcessConsumer::Process_vkGetSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA>* pGetZirconHandleInfo,
    PointerDecoder<uint32_t>*                   pZirconHandle)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pGetZirconHandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pGetZirconHandleInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetSemaphoreZirconHandleFUCHSIA);
}
void VulkanCppPreProcessConsumer::Process_vkImportSemaphoreZirconHandleFUCHSIA(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA>* pImportSemaphoreZirconHandleInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pImportSemaphoreZirconHandleInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pImportSemaphoreZirconHandleInfo->GetMetaStructPointer()->semaphore);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkImportSemaphoreZirconHandleFUCHSIA);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      imageView);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindInvocationMaskHUAWEI);
}
void VulkanCppPreProcessConsumer::Process_vkGetMemoryRemoteAddressNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMemoryGetRemoteAddressInfoNV>* pMemoryGetRemoteAddressInfo,
    PointerDecoder<uint64_t, void*>*            pAddress)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pMemoryGetRemoteAddressInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pMemoryGetRemoteAddressInfo->GetMetaStructPointer()->memory);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMemoryRemoteAddressNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthBiasEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPatchControlPointsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPrimitiveRestartEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizerDiscardEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateScreenSurfaceQNX(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkScreenSurfaceCreateInfoQNX>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateScreenSurfaceQNX);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceScreenPresentationSupportQNX(
    const ApiCallInfo&                          call_info,
    VkBool32                                    returnValue,
    format::HandleId                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    uint64_t                                    window)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceScreenPresentationSupportQNX);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMultiIndexedEXT);
}
void VulkanCppPreProcessConsumer::Process_vkBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].dstMicromap);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkBuildMicromapsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].dstMicromap);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildMicromapsEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMicromapToMemoryEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pMicromaps->GetPointer(),
                                      micromapCount);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteMicromapsPropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMicromapToMemoryEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateMicromapEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapCreateInfoEXT>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromap)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->buffer);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pMicromap->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            micromap,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      micromap);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyMicromapEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceMicromapCompatibilityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkMicromapVersionInfoEXT>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceMicromapCompatibilityEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetMicromapBuildSizesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pBuildInfo,
    StructPointerDecoder<Decoded_VkMicromapBuildSizesInfoEXT>* pSizeInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pBuildInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBuildInfo->GetMetaStructPointer()->dstMicromap);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetMicromapBuildSizesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pMicromaps->GetPointer(),
                                      micromapCount);
    Post_APICall(format::ApiCallId::ApiCall_vkWriteMicromapsPropertiesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterHUAWEI);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawClusterIndirectHUAWEI);
}
void VulkanCppPreProcessConsumer::Process_vkSetDeviceMemoryPriorityEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory,
    float                                       priority)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      memory);
    Post_APICall(format::ApiCallId::ApiCall_vkSetDeviceMemoryPriorityEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetDescriptorSetHostMappingVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            descriptorSet,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorSet);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetHostMappingVALVE);
}
void VulkanCppPreProcessConsumer::Process_vkGetDescriptorSetLayoutHostMappingInfoVALVE(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorSetBindingReferenceVALVE>* pBindingReference,
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE>* pHostMapping)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pBindingReference->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindingReference->GetMetaStructPointer()->descriptorSetLayout);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDescriptorSetLayoutHostMappingInfoVALVE);
}
void VulkanCppPreProcessConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdUpdatePipelineIndirectBufferNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineIndirectDeviceAddressNV(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkPipelineIndirectDeviceAddressInfoNV>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->pipeline);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectDeviceAddressNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetPipelineIndirectMemoryRequirementsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer()->stage != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->stage->module);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->layout);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->basePipelineHandle);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetPipelineIndirectMemoryRequirementsNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToCoverageEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAlphaToOneEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendAdvancedEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorBlendEquationEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetColorWriteMaskEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetConservativeRasterizationModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationModeNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageModulationTableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageReductionModeNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetCoverageToColorLocationNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClampEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetDepthClipNegativeOneToOneEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetExtraPrimitiveOverestimationSizeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineRasterizationModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLineStippleEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetLogicOpEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetPolygonModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetProvokingVertexModeEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationSamplesEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRasterizationStreamEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRepresentativeFragmentTestEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleLocationsEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetSampleMaskEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetShadingRateImageEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetTessellationDomainOriginEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportSwizzleNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetViewportWScalingEnableNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetShaderModuleCreateInfoIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleCreateInfoIdentifierEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetShaderModuleIdentifierEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shaderModule,
    StructPointerDecoder<Decoded_VkShaderModuleIdentifierEXT>* pIdentifier)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      shaderModule);
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderModuleIdentifierEXT);
}
void VulkanCppPreProcessConsumer::Process_vkBindOpticalFlowSessionImageNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            session,
    VkOpticalFlowSessionBindingPointNV          bindingPoint,
    format::HandleId                            view,
    VkImageLayout                               layout)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      session);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      view);
    Post_APICall(format::ApiCallId::ApiCall_vkBindOpticalFlowSessionImageNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      session);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdOpticalFlowExecuteNV);
}
void VulkanCppPreProcessConsumer::Process_vkCreateOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkOpticalFlowSessionCreateInfoNV>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkOpticalFlowSessionNV>* pSession)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSession->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateOpticalFlowSessionNV);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyOpticalFlowSessionNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      session);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyOpticalFlowSessionNV);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceOpticalFlowImageFormatsNV(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatInfoNV>* pOpticalFlowImageFormatInfo,
    PointerDecoder<uint32_t>*                   pFormatCount,
    StructPointerDecoder<Decoded_VkOpticalFlowImageFormatPropertiesNV>* pImageFormatProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pShaders->GetPointer(),
                                      stageCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBindShadersEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCreateShadersEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkShaderCreateInfoEXT>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].pSetLayouts.GetPointer(),
                                          pCreateInfos->GetMetaStructPointer()[idx].pSetLayouts.GetLength());
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pShaders->GetPointer(),
                                      createInfoCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateShadersEXT);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyShaderEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            shader,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      shader);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetShaderBinaryDataEXT(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            shader,
    PointerDecoder<size_t>*                     pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      shader);
    Post_APICall(format::ApiCallId::ApiCall_vkGetShaderBinaryDataEXT);
}
void VulkanCppPreProcessConsumer::Process_vkGetDynamicRenderingTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].imageView);
    }

    for (uint32_t idx = 0; idx < pRenderingInfo->GetPointer()->colorAttachmentCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pColorAttachments->GetMetaStructPointer()[idx].resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pDepthAttachment->GetMetaStructPointer()->resolveImageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->imageView);
    }

    if (pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pRenderingInfo->GetMetaStructPointer()->pStencilAttachment->GetMetaStructPointer()->resolveImageView);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetDynamicRenderingTilePropertiesQCOM);
}
void VulkanCppPreProcessConsumer::Process_vkGetFramebufferTilePropertiesQCOM(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            framebuffer,
    PointerDecoder<uint32_t>*                   pPropertiesCount,
    StructPointerDecoder<Decoded_VkTilePropertiesQCOM>* pProperties)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      framebuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkGetFramebufferTilePropertiesQCOM);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetAttachmentFeedbackLoopEnableEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].srcAccelerationStructure);
    }

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].dstAccelerationStructure);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresIndirectKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].srcAccelerationStructure);
    }

    for (uint32_t idx = 0; idx < infoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfos->GetMetaStructPointer()[idx].dstAccelerationStructure);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdBuildAccelerationStructuresKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyAccelerationStructureToMemoryKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCmdCopyMemoryToAccelerationStructureKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pAccelerationStructures->GetPointer(),
                                      accelerationStructureCount);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdWriteAccelerationStructuresPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->src);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyAccelerationStructureToMemoryKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->dst);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkCopyMemoryToAccelerationStructureKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructure)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->buffer);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pAccelerationStructure->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAccelerationStructureKHR);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            accelerationStructure,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      accelerationStructure);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyAccelerationStructureKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetAccelerationStructureBuildSizesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    VkAccelerationStructureBuildTypeKHR         buildType,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pBuildInfo,
    PointerDecoder<uint32_t>*                   pMaxPrimitiveCounts,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildSizesInfoKHR>* pSizeInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pBuildInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBuildInfo->GetMetaStructPointer()->srcAccelerationStructure);
    }

    if (pBuildInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBuildInfo->GetMetaStructPointer()->dstAccelerationStructure);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureBuildSizesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetAccelerationStructureDeviceAddressKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceAddress                             returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureDeviceAddressInfoKHR>* pInfo)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->accelerationStructure);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetDeviceAccelerationStructureCompatibilityKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAccelerationStructureVersionInfoKHR>* pVersionInfo,
    PointerDecoder<VkAccelerationStructureCompatibilityKHR>* pCompatibility)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkGetDeviceAccelerationStructureCompatibilityKHR);
}
void VulkanCppPreProcessConsumer::Process_vkWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData,
    size_t                                      stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pAccelerationStructures->GetPointer(),
                                      accelerationStructureCount);
    Post_APICall(format::ApiCallId::ApiCall_vkWriteAccelerationStructuresPropertiesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetRayTracingPipelineStackSizeKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysIndirectKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdTraceRaysKHR(
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
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdTraceRaysKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateRayTracingPipelinesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            deferredOperation,
    format::HandleId                            pipelineCache,
    uint32_t                                    createInfoCount,
    StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoKHR>* pCreateInfos,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkPipeline>*           pPipelines)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      deferredOperation);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    for (uint32_t idx = 0; idx < pCreateInfos->GetPointer()->stageCount; idx++) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->pStages->GetMetaStructPointer()[idx].module);
    }

    if (pCreateInfos->GetMetaStructPointer()->pLibraryInfo->GetMetaStructPointer() != nullptr) {
            resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->pLibraryInfo->GetMetaStructPointer()->pLibraries.GetPointer(),
                                              pCreateInfos->GetMetaStructPointer()->pLibraryInfo->GetMetaStructPointer()->pLibraries.GetLength());
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pPipelines->GetPointer(),
                                      createInfoCount);
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    firstGroup,
    uint32_t                                    groupCount,
    size_t                                      dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetRayTracingShaderGroupStackSizeKHR(
    const ApiCallInfo&                          call_info,
    VkDeviceSize                                returnValue,
    format::HandleId                            device,
    format::HandleId                            pipeline,
    uint32_t                                    group,
    VkShaderGroupShaderKHR                      groupShader)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipeline);
    Post_APICall(format::ApiCallId::ApiCall_vkGetRayTracingShaderGroupStackSizeKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectCountEXT);
}
void VulkanCppPreProcessConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    resource_tracker_->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawMeshTasksIndirectEXT);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
