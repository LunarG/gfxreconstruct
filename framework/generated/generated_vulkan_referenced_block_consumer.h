/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#ifndef  GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H

#include "decode/vulkan_referenced_block_consumer_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanReferencedBlockConsumer : public VulkanReferencedBlockConsumerBase
{
  public:
    VulkanReferencedBlockConsumer(const std::unordered_set<format::HandleId>& unreferenced_ids):
        VulkanReferencedBlockConsumerBase(unreferenced_ids) { }


    void Process_vkBeginCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo) override;

    void Process_vkEndCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer) override;

    void Process_vkResetCommandBuffer(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        VkCommandBufferResetFlags                   flags) override;

    void Process_vkCmdCopyBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferCopy>* pRegions) override;

    void Process_vkCmdCopyImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageCopy>*  pRegions) override;

    void Process_vkCmdCopyBufferToImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    void Process_vkCmdCopyImageToBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions) override;

    void Process_vkCmdUpdateBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        PointerDecoder<uint8_t>*                    pData) override;

    void Process_vkCmdFillBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) override;

    void Process_vkCmdPipelineBarrier(
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
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) override;

    void Process_vkCmdBeginQuery(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) override;

    void Process_vkCmdEndQuery(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    void Process_vkCmdResetQueryPool(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) override;

    void Process_vkCmdWriteTimestamp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    void Process_vkCmdCopyQueryPoolResults(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) override;

    void Process_vkCmdExecuteCommands(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    commandBufferCount,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) override;

    void Process_vkCmdBindPipeline(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) override;

    void Process_vkCmdBindDescriptorSets(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        PointerDecoder<uint32_t>*                   pDynamicOffsets) override;

    void Process_vkCmdClearColorImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    void Process_vkCmdDispatch(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    void Process_vkCmdDispatchIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) override;

    void Process_vkCmdSetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    void Process_vkCmdResetEvent(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) override;

    void Process_vkCmdWaitEvents(
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
        StructPointerDecoder<Decoded_VkImageMemoryBarrier>* pImageMemoryBarriers) override;

    void Process_vkCmdPushConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        PointerDecoder<uint8_t>*                    pValues) override;

    void Process_vkCmdSetViewport(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    void Process_vkCmdSetScissor(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    void Process_vkCmdSetLineWidth(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       lineWidth) override;

    void Process_vkCmdSetDepthBias(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) override;

    void Process_vkCmdSetBlendConstants(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        PointerDecoder<float>*                      blendConstants) override;

    void Process_vkCmdSetDepthBounds(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) override;

    void Process_vkCmdSetStencilCompareMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) override;

    void Process_vkCmdSetStencilWriteMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) override;

    void Process_vkCmdSetStencilReference(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) override;

    void Process_vkCmdBindIndexBuffer(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) override;

    void Process_vkCmdBindVertexBuffers(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets) override;

    void Process_vkCmdDraw(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) override;

    void Process_vkCmdDrawIndexed(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) override;

    void Process_vkCmdDrawIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawIndexedIndirect(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdBlitImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageBlit>*  pRegions,
        VkFilter                                    filter) override;

    void Process_vkCmdClearDepthStencilImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
        uint32_t                                    rangeCount,
        StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges) override;

    void Process_vkCmdClearAttachments(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
        uint32_t                                    rectCount,
        StructPointerDecoder<Decoded_VkClearRect>*  pRects) override;

    void Process_vkCmdResolveImage(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        StructPointerDecoder<Decoded_VkImageResolve>* pRegions) override;

    void Process_vkCmdBeginRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        VkSubpassContents                           contents) override;

    void Process_vkCmdNextSubpass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSubpassContents                           contents) override;

    void Process_vkCmdEndRenderPass(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdSetDeviceMask(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) override;

    void Process_vkCmdDispatchBase(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    void Process_vkCmdDrawIndirectCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawIndexedIndirectCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdBeginRenderPass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) override;

    void Process_vkCmdNextSubpass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    void Process_vkCmdEndRenderPass2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    void Process_vkCmdPipelineBarrier2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) override;

    void Process_vkCmdWriteTimestamp2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    void Process_vkCmdCopyBuffer2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) override;

    void Process_vkCmdCopyImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) override;

    void Process_vkCmdCopyBufferToImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) override;

    void Process_vkCmdCopyImageToBuffer2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) override;

    void Process_vkCmdSetEvent2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) override;

    void Process_vkCmdResetEvent2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags2                       stageMask) override;

    void Process_vkCmdWaitEvents2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        HandlePointerDecoder<VkEvent>*              pEvents,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) override;

    void Process_vkCmdBlitImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) override;

    void Process_vkCmdResolveImage2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) override;

    void Process_vkCmdBeginRendering(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) override;

    void Process_vkCmdEndRendering(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdSetCullMode(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCullModeFlags                             cullMode) override;

    void Process_vkCmdSetFrontFace(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFrontFace                                 frontFace) override;

    void Process_vkCmdSetPrimitiveTopology(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPrimitiveTopology                         primitiveTopology) override;

    void Process_vkCmdSetViewportWithCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    void Process_vkCmdSetScissorWithCount(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    void Process_vkCmdBindVertexBuffers2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes,
        PointerDecoder<VkDeviceSize>*               pStrides) override;

    void Process_vkCmdSetDepthTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthTestEnable) override;

    void Process_vkCmdSetDepthWriteEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthWriteEnable) override;

    void Process_vkCmdSetDepthCompareOp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCompareOp                                 depthCompareOp) override;

    void Process_vkCmdSetDepthBoundsTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBoundsTestEnable) override;

    void Process_vkCmdSetStencilTestEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stencilTestEnable) override;

    void Process_vkCmdSetStencilOp(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        VkStencilOp                                 failOp,
        VkStencilOp                                 passOp,
        VkStencilOp                                 depthFailOp,
        VkCompareOp                                 compareOp) override;

    void Process_vkCmdSetRasterizerDiscardEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    rasterizerDiscardEnable) override;

    void Process_vkCmdSetDepthBiasEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBiasEnable) override;

    void Process_vkCmdSetPrimitiveRestartEnable(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    primitiveRestartEnable) override;

    void Process_vkCmdPushDescriptorSet(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) override;

    void Process_vkCmdBindDescriptorSets2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo) override;

    void Process_vkCmdPushConstants2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo) override;

    void Process_vkCmdPushDescriptorSet2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo) override;

    void Process_vkCmdSetLineStipple(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) override;

    void Process_vkCmdBindIndexBuffer2(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkIndexType                                 indexType) override;

    void Process_vkCmdSetRenderingAttachmentLocations(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo) override;

    void Process_vkCmdSetRenderingInputAttachmentIndices(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo) override;

    void Process_vkCmdBeginVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo) override;

    void Process_vkCmdEndVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo) override;

    void Process_vkCmdControlVideoCodingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo) override;

    void Process_vkCmdDecodeVideoKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo) override;

    void Process_vkCmdBeginRenderingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo) override;

    void Process_vkCmdEndRenderingKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdSetDeviceMaskKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) override;

    void Process_vkCmdDispatchBaseKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    void Process_vkCmdPushDescriptorSetKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites) override;

    void Process_vkCmdBeginRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo) override;

    void Process_vkCmdNextSubpass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    void Process_vkCmdEndRenderPass2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo) override;

    void Process_vkCmdDrawIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawIndexedIndirectCountKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdSetFragmentShadingRateKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
        PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) override;

    void Process_vkCmdSetRenderingAttachmentLocationsKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo) override;

    void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo) override;

    void Process_vkCmdEncodeVideoKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo) override;

    void Process_vkCmdSetEvent2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) override;

    void Process_vkCmdResetEvent2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags2                       stageMask) override;

    void Process_vkCmdWaitEvents2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        HandlePointerDecoder<VkEvent>*              pEvents,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos) override;

    void Process_vkCmdPipelineBarrier2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo) override;

    void Process_vkCmdWriteTimestamp2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            queryPool,
        uint32_t                                    query) override;

    void Process_vkCmdCopyBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo) override;

    void Process_vkCmdCopyImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo) override;

    void Process_vkCmdCopyBufferToImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo) override;

    void Process_vkCmdCopyImageToBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo) override;

    void Process_vkCmdBlitImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo) override;

    void Process_vkCmdResolveImage2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo) override;

    void Process_vkCmdTraceRaysIndirect2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkDeviceAddress                             indirectDeviceAddress) override;

    void Process_vkCmdBindIndexBuffer2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkIndexType                                 indexType) override;

    void Process_vkCmdSetLineStippleKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) override;

    void Process_vkCmdBindDescriptorSets2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo) override;

    void Process_vkCmdPushConstants2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo) override;

    void Process_vkCmdPushDescriptorSet2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo) override;

    void Process_vkCmdSetDescriptorBufferOffsets2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo) override;

    void Process_vkCmdCopyMemoryIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR>* pCopyMemoryIndirectInfo) override;

    void Process_vkCmdCopyMemoryToImageIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR>* pCopyMemoryToImageIndirectInfo) override;

    void Process_vkCmdEndRendering2KHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo) override;

    void Process_vkCmdDebugMarkerBeginEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) override;

    void Process_vkCmdDebugMarkerEndEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdDebugMarkerInsertEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo) override;

    void Process_vkCmdBindTransformFeedbackBuffersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes) override;

    void Process_vkCmdBeginTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) override;

    void Process_vkCmdEndTransformFeedbackEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
        PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets) override;

    void Process_vkCmdBeginQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags,
        uint32_t                                    index) override;

    void Process_vkCmdEndQueryIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        uint32_t                                    index) override;

    void Process_vkCmdDrawIndirectByteCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        format::HandleId                            counterBuffer,
        VkDeviceSize                                counterBufferOffset,
        uint32_t                                    counterOffset,
        uint32_t                                    vertexStride) override;

    void Process_vkCmdDrawIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawIndexedIndirectCountAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdBeginConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin) override;

    void Process_vkCmdEndConditionalRenderingEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdSetViewportWScalingNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings) override;

    void Process_vkCmdSetDiscardRectangleEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles) override;

    void Process_vkCmdSetDiscardRectangleEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    discardRectangleEnable) override;

    void Process_vkCmdSetDiscardRectangleModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkDiscardRectangleModeEXT                   discardRectangleMode) override;

    void Process_vkCmdBeginDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    void Process_vkCmdEndDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer) override;

    void Process_vkCmdInsertDebugUtilsLabelEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo) override;

    void Process_vkCmdSetSampleLocationsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo) override;

    void Process_vkCmdBindShadingRateImageNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) override;

    void Process_vkCmdSetViewportShadingRatePaletteNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes) override;

    void Process_vkCmdSetCoarseSampleOrderNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoarseSampleOrderTypeNV                   sampleOrderType,
        uint32_t                                    customSampleOrderCount,
        StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders) override;

    void Process_vkCmdBuildAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>* pInfo,
        format::HandleId                            instanceData,
        VkDeviceSize                                instanceOffset,
        VkBool32                                    update,
        format::HandleId                            dst,
        format::HandleId                            src,
        format::HandleId                            scratch,
        VkDeviceSize                                scratchOffset) override;

    void Process_vkCmdCopyAccelerationStructureNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            dst,
        format::HandleId                            src,
        VkCopyAccelerationStructureModeKHR          mode) override;

    void Process_vkCmdTraceRaysNV(
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
        uint32_t                                    depth) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) override;

    void Process_vkCmdWriteBufferMarkerAMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) override;

    void Process_vkCmdWriteBufferMarker2AMD(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags2                       stage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) override;

    void Process_vkCmdDrawMeshTasksNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    taskCount,
        uint32_t                                    firstTask) override;

    void Process_vkCmdDrawMeshTasksIndirectNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawMeshTasksIndirectCountNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdSetExclusiveScissorEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        PointerDecoder<VkBool32>*                   pExclusiveScissorEnables) override;

    void Process_vkCmdSetExclusiveScissorNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors) override;

    void Process_vkCmdSetCheckpointNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint64_t                                    pCheckpointMarker) override;

    void Process_vkCmdSetPerformanceMarkerINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo) override;

    void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo) override;

    void Process_vkCmdSetPerformanceOverrideINTEL(
        const ApiCallInfo&                          call_info,
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo) override;

    void Process_vkCmdSetLineStippleEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) override;

    void Process_vkCmdSetCullModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCullModeFlags                             cullMode) override;

    void Process_vkCmdSetFrontFaceEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFrontFace                                 frontFace) override;

    void Process_vkCmdSetPrimitiveTopologyEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPrimitiveTopology                         primitiveTopology) override;

    void Process_vkCmdSetViewportWithCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewport>*   pViewports) override;

    void Process_vkCmdSetScissorWithCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    scissorCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pScissors) override;

    void Process_vkCmdBindVertexBuffers2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        HandlePointerDecoder<VkBuffer>*             pBuffers,
        PointerDecoder<VkDeviceSize>*               pOffsets,
        PointerDecoder<VkDeviceSize>*               pSizes,
        PointerDecoder<VkDeviceSize>*               pStrides) override;

    void Process_vkCmdSetDepthTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthTestEnable) override;

    void Process_vkCmdSetDepthWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthWriteEnable) override;

    void Process_vkCmdSetDepthCompareOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCompareOp                                 depthCompareOp) override;

    void Process_vkCmdSetDepthBoundsTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBoundsTestEnable) override;

    void Process_vkCmdSetStencilTestEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stencilTestEnable) override;

    void Process_vkCmdSetStencilOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        VkStencilOp                                 failOp,
        VkStencilOp                                 passOp,
        VkStencilOp                                 depthFailOp,
        VkCompareOp                                 compareOp) override;

    void Process_vkCmdPreprocessGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) override;

    void Process_vkCmdExecuteGeneratedCommandsNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    isPreprocessed,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo) override;

    void Process_vkCmdBindPipelineShaderGroupNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline,
        uint32_t                                    groupIndex) override;

    void Process_vkCmdSetDepthBias2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo) override;

    void Process_vkCmdDispatchTileQCOM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM>* pDispatchTileInfo) override;

    void Process_vkCmdBeginPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM>* pPerTileBeginInfo) override;

    void Process_vkCmdEndPerTileExecutionQCOM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM>* pPerTileEndInfo) override;

    void Process_vkCmdBindDescriptorBuffersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    bufferCount,
        StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT>* pBindingInfos) override;

    void Process_vkCmdSetDescriptorBufferOffsetsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    setCount,
        PointerDecoder<uint32_t>*                   pBufferIndices,
        PointerDecoder<VkDeviceSize>*               pOffsets) override;

    void Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set) override;

    void Process_vkCmdSetFragmentShadingRateEnumNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkFragmentShadingRateNV                     shadingRate,
        PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps) override;

    void Process_vkCmdSetVertexInputEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexBindingDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
        uint32_t                                    vertexAttributeDescriptionCount,
        StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions) override;

    void Process_vkCmdBindInvocationMaskHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) override;

    void Process_vkCmdSetPatchControlPointsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    patchControlPoints) override;

    void Process_vkCmdSetRasterizerDiscardEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    rasterizerDiscardEnable) override;

    void Process_vkCmdSetDepthBiasEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthBiasEnable) override;

    void Process_vkCmdSetLogicOpEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkLogicOp                                   logicOp) override;

    void Process_vkCmdSetPrimitiveRestartEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    primitiveRestartEnable) override;

    void Process_vkCmdSetColorWriteEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkBool32>*                   pColorWriteEnables) override;

    void Process_vkCmdDrawMultiEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    drawCount,
        StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawMultiIndexedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    drawCount,
        StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        uint32_t                                    stride,
        PointerDecoder<int32_t>*                    pVertexOffset) override;

    void Process_vkCmdBuildMicromapsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos) override;

    void Process_vkCmdCopyMicromapEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo) override;

    void Process_vkCmdCopyMicromapToMemoryEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo) override;

    void Process_vkCmdCopyMemoryToMicromapEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo) override;

    void Process_vkCmdWriteMicromapsPropertiesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    micromapCount,
        HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) override;

    void Process_vkCmdDrawClusterHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    void Process_vkCmdDrawClusterIndirectHUAWEI(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) override;

    void Process_vkCmdUpdatePipelineIndirectBufferNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) override;

    void Process_vkCmdSetDepthClampEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthClampEnable) override;

    void Process_vkCmdSetPolygonModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkPolygonMode                               polygonMode) override;

    void Process_vkCmdSetRasterizationSamplesEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSampleCountFlagBits                       rasterizationSamples) override;

    void Process_vkCmdSetSampleMaskEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkSampleCountFlagBits                       samples,
        PointerDecoder<VkSampleMask>*               pSampleMask) override;

    void Process_vkCmdSetAlphaToCoverageEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    alphaToCoverageEnable) override;

    void Process_vkCmdSetAlphaToOneEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    alphaToOneEnable) override;

    void Process_vkCmdSetLogicOpEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    logicOpEnable) override;

    void Process_vkCmdSetColorBlendEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkBool32>*                   pColorBlendEnables) override;

    void Process_vkCmdSetColorBlendEquationEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations) override;

    void Process_vkCmdSetColorWriteMaskEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks) override;

    void Process_vkCmdSetTessellationDomainOriginEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkTessellationDomainOrigin                  domainOrigin) override;

    void Process_vkCmdSetRasterizationStreamEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    rasterizationStream) override;

    void Process_vkCmdSetConservativeRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkConservativeRasterizationModeEXT          conservativeRasterizationMode) override;

    void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        float                                       extraPrimitiveOverestimationSize) override;

    void Process_vkCmdSetDepthClipEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    depthClipEnable) override;

    void Process_vkCmdSetSampleLocationsEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    sampleLocationsEnable) override;

    void Process_vkCmdSetColorBlendAdvancedEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstAttachment,
        uint32_t                                    attachmentCount,
        StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced) override;

    void Process_vkCmdSetProvokingVertexModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkProvokingVertexModeEXT                    provokingVertexMode) override;

    void Process_vkCmdSetLineRasterizationModeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkLineRasterizationModeEXT                  lineRasterizationMode) override;

    void Process_vkCmdSetLineStippleEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    stippledLineEnable) override;

    void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    negativeOneToOne) override;

    void Process_vkCmdSetViewportWScalingEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    viewportWScalingEnable) override;

    void Process_vkCmdSetViewportSwizzleNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles) override;

    void Process_vkCmdSetCoverageToColorEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    coverageToColorEnable) override;

    void Process_vkCmdSetCoverageToColorLocationNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    coverageToColorLocation) override;

    void Process_vkCmdSetCoverageModulationModeNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoverageModulationModeNV                  coverageModulationMode) override;

    void Process_vkCmdSetCoverageModulationTableEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    coverageModulationTableEnable) override;

    void Process_vkCmdSetCoverageModulationTableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    coverageModulationTableCount,
        PointerDecoder<float>*                      pCoverageModulationTable) override;

    void Process_vkCmdSetShadingRateImageEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    shadingRateImageEnable) override;

    void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    representativeFragmentTestEnable) override;

    void Process_vkCmdSetCoverageReductionModeNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkCoverageReductionModeNV                   coverageReductionMode) override;

    void Process_vkCmdOpticalFlowExecuteNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo) override;

    void Process_vkCmdBindShadersEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    stageCount,
        PointerDecoder<VkShaderStageFlagBits>*      pStages,
        HandlePointerDecoder<VkShaderEXT>*          pShaders) override;

    void Process_vkCmdSetDepthClampRangeEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkDepthClampModeEXT                         depthClampMode,
        StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange) override;

    void Process_vkCmdConvertCooperativeVectorMatrixNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV>* pInfos) override;

    void Process_vkCmdDispatchDataGraphARM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            session,
        StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM>* pInfo) override;

    void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkImageAspectFlags                          aspectMask) override;

    void Process_vkCmdBindTileMemoryQCOM(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM>* pTileMemoryBindInfo) override;

    void Process_vkCmdDecompressMemoryEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT>* pDecompressMemoryInfoEXT) override;

    void Process_vkCmdDecompressMemoryIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkMemoryDecompressionMethodFlagsEXT         decompressionMethod,
        VkDeviceAddress                             indirectCommandsAddress,
        VkDeviceAddress                             indirectCommandsCountAddress,
        uint32_t                                    maxDecompressionCount,
        uint32_t                                    stride) override;

    void Process_vkCmdBuildPartitionedAccelerationStructuresNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV>* pBuildInfo) override;

    void Process_vkCmdPreprocessGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
        format::HandleId                            stateCommandBuffer) override;

    void Process_vkCmdExecuteGeneratedCommandsEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        VkBool32                                    isPreprocessed,
        StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo) override;

    void Process_vkCmdEndRendering2EXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo) override;

    void Process_vkCmdBeginCustomResolveEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT>* pBeginCustomResolveInfo) override;

    void Process_vkCmdSetComputeOccupancyPriorityNV(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV>* pParameters) override;

    void Process_vkCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos) override;

    void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
        PointerDecoder<uint32_t>*                   pIndirectStrides,
        PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts) override;

    void Process_vkCmdCopyAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo) override;

    void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo) override;

    void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo) override;

    void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) override;

    void Process_vkCmdTraceRaysKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        uint32_t                                    width,
        uint32_t                                    height,
        uint32_t                                    depth) override;

    void Process_vkCmdTraceRaysIndirectKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
        StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
        VkDeviceAddress                             indirectDeviceAddress) override;

    void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    pipelineStackSize) override;

    void Process_vkCmdDrawMeshTasksEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) override;

    void Process_vkCmdDrawMeshTasksIndirectEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) override;

    void Process_vkCmdDrawMeshTasksIndirectCountEXT(
        const ApiCallInfo&                          call_info,
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_REFERENCED_BLOCK_CONSUMER_H
