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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->commandPool);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->descriptorPool);
    }

    if (pAllocateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAllocateInfo->GetMetaStructPointer()->pSetLayouts.GetPointer(),
                                          pAllocateInfo->GetMetaStructPointer()->pSetLayouts.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer() != nullptr) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer()->renderPass);
    }

    if (pBeginInfo->GetMetaStructPointer()->pInheritanceInfo->GetMetaStructPointer() != nullptr) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->renderPass);
    }

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      layout);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queryPool);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdEndQuery);
}
void VulkanCppPreProcessConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdFillBuffer);
}
void VulkanCppPreProcessConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    for (uint32_t idx = 0; idx < bufferMemoryBarrierCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < imageMemoryBarrierCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      srcImage);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstImage);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdResolveImage);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdSetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pEvents->GetPointer(),
                                      eventCount);

    for (uint32_t idx = 0; idx < bufferMemoryBarrierCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBufferMemoryBarriers->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < imageMemoryBarrierCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->buffer);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    if (pCreateInfos->GetMetaStructPointer()->stage != nullptr) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->stage->module);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < pCreateInfo->GetPointer()->bindingCount; idx++) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetPointer(),
                                              pCreateInfo->GetMetaStructPointer()->pBindings->GetMetaStructPointer()[idx].pImmutableSamplers.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->renderPass);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pAttachments.GetPointer(),
                                          pCreateInfo->GetMetaStructPointer()->pAttachments.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pipelineCache);

    for (uint32_t idx = 0; idx < pCreateInfos->GetPointer()->stageCount; idx++) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pCreateInfos->GetMetaStructPointer()->pStages->GetMetaStructPointer()[idx].module);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].layout);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].renderPass);
    }

    for (uint32_t idx = 0; idx < createInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfos->GetMetaStructPointer()[idx].basePipelineHandle);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->image);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pSetLayouts.GetPointer(),
                                          pCreateInfo->GetMetaStructPointer()->pSetLayouts.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorSetLayout);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyDescriptorSetLayout);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      imageView);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyImageView);
}
void VulkanCppPreProcessConsumer::Process_vkDestroyInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      shaderModule);
    Post_APICall(format::ApiCallId::ApiCall_vkDestroyShaderModule);
}
void VulkanCppPreProcessConsumer::Process_vkDeviceWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);
    Post_APICall(format::ApiCallId::ApiCall_vkDeviceWaitIdle);
}
void VulkanCppPreProcessConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < memoryRangeCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      descriptorPool);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      image);
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSubresourceLayout);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMemoryProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    for (uint32_t idx = 0; idx < memoryRangeCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      dstCache);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfo->GetMetaStructPointer()[idx].pWaitSemaphores.GetPointer(),
                                          pBindInfo->GetMetaStructPointer()[idx].pWaitSemaphores.GetLength());
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->bufferBindCount; idx++) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pBufferBinds->GetMetaStructPointer()[idx].buffer);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pBufferBinds->GetPointer()->bindCount; idx++) {
                m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pBufferBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->imageOpaqueBindCount; idx++) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetPointer()->bindCount; idx++) {
                m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pImageOpaqueBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetPointer()->imageBindCount; idx++) {
            m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                              GetCurrentFrameSplitNumber(),
                                              pBindInfo->GetMetaStructPointer()->pImageBinds->GetMetaStructPointer()[idx].image);
    }

    for (uint32_t idx = 0; idx < pBindInfo->GetMetaStructPointer()->pImageBinds->GetPointer()->bindCount; idx++) {
                m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                                  GetCurrentFrameSplitNumber(),
                                                  pBindInfo->GetMetaStructPointer()->pImageBinds->GetMetaStructPointer()->pBinds->GetMetaStructPointer()[idx].memory);
    }

    for (uint32_t idx = 0; idx < bindInfoCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pBindInfo->GetMetaStructPointer()[idx].pSignalSemaphores.GetPointer(),
                                          pBindInfo->GetMetaStructPointer()[idx].pSignalSemaphores.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pWaitSemaphores.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pWaitSemaphores.GetLength());
    }

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pCommandBuffers.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pCommandBuffers.GetLength());
    }

    for (uint32_t idx = 0; idx < submitCount; idx++) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pSubmits->GetMetaStructPointer()[idx].pSignalSemaphores.GetPointer(),
                                          pSubmits->GetMetaStructPointer()[idx].pSignalSemaphores.GetLength());
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      fence);
    Post_APICall(format::ApiCallId::ApiCall_vkQueueSubmit);
}
void VulkanCppPreProcessConsumer::Process_vkQueueWaitIdle(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            queue)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      event);
    Post_APICall(format::ApiCallId::ApiCall_vkSetEvent);
}
void VulkanCppPreProcessConsumer::Process_vkUnmapMemory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            memory)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      pFences->GetPointer(),
                                      fenceCount);
    Post_APICall(format::ApiCallId::ApiCall_vkWaitForFences);
}
void VulkanCppPreProcessConsumer::Process_vkDestroySurfaceKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            instance,
    format::HandleId                            surface,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAcquireInfo->GetMetaStructPointer()->swapchain);
    }

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pAcquireInfo->GetMetaStructPointer()->semaphore);
    }

    if (pAcquireInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      semaphore);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->surface);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->oldSwapchain);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      swapchain);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      queue);

    if (pPresentInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPresentInfo->GetMetaStructPointer()->pWaitSemaphores.GetPointer(),
                                          pPresentInfo->GetMetaStructPointer()->pWaitSemaphores.GetLength());
    }

    if (pPresentInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pPresentInfo->GetMetaStructPointer()->pSwapchains.GetPointer(),
                                          pPresentInfo->GetMetaStructPointer()->pSwapchains.GetLength());
    }
    Post_APICall(format::ApiCallId::ApiCall_vkQueuePresentKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateXcbSurfaceKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            instance,
    StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkSurfaceKHR>*         pSurface)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      instance);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pSurface->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateAndroidSurfaceKHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceFeatures2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceImageFormatProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceMemoryProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceMemoryProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetPhysicalDeviceProperties2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            physicalDevice,
    StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      physicalDevice);
    Post_APICall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkTrimCommandPoolKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    format::HandleId                            commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandPool);
    Post_APICall(format::ApiCallId::ApiCall_vkTrimCommandPoolKHR);
}
void VulkanCppPreProcessConsumer::Process_vkCreateDescriptorUpdateTemplateKHR(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>* pCreateInfo,
    StructPointerDecoder<Decoded_VkAllocationCallbacks>* pAllocator,
    HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->descriptorSetLayout);
    }

    if (pCreateInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pCreateInfo->GetMetaStructPointer()->pipelineLayout);
    }

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pRenderPassBegin->GetMetaStructPointer()->renderPass);
    }

    if (pRenderPassBegin->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      *pRenderPass->GetPointer());
    Post_APICall(format::ApiCallId::ApiCall_vkCreateRenderPass2KHR);
}
void VulkanCppPreProcessConsumer::Process_vkGetBufferMemoryRequirements2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            device,
    StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>* pInfo,
    StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements)
{
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      device);

    if (pInfo->GetMetaStructPointer() != nullptr) {
        m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                          GetCurrentFrameSplitNumber(),
                                          pInfo->GetMetaStructPointer()->image);
    }
    Post_APICall(format::ApiCallId::ApiCall_vkGetImageSparseMemoryRequirements2KHR);
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
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
    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      commandBuffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      buffer);

    m_resourceTracker->AddHandleUsage(GetCurrentFrameNumber(),
                                      GetCurrentFrameSplitNumber(),
                                      countBuffer);
    Post_APICall(format::ApiCallId::ApiCall_vkCmdDrawIndirectCountKHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
