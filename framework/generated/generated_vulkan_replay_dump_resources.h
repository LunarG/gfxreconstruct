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

#ifndef  GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_H
#define  GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_H

#include "decode/vulkan_replay_dump_resources.h"
#include "decode/struct_pointer_decoder.h"
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

class VulkanReplayDumpResources : public VulkanReplayDumpResourcesBase
{
  public:
    VulkanReplayDumpResources(const VulkanReplayOptions& options, VulkanObjectInfoTable& object_info_table) : VulkanReplayDumpResourcesBase(options, object_info_table) { }

    ~VulkanReplayDumpResources() { }

void Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkEndCommandBuffer                      func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer);

void Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindPipeline                       func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineInfo*                   pipeline);

void Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewport                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports);

void Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissor                         func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors);

void Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineWidth                       func,
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth);

void Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBias                       func,
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor);

void Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetBlendConstants                  func,
    VkCommandBuffer                             commandBuffer,
    const float*                                blendConstants);

void Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBounds                     func,
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds);

void Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilCompareMask              func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask);

void Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilWriteMask                func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask);

void Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilReference                func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference);

void Process_vkCmdBindDescriptorSets(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorSets                 func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    const VulkanPipelineLayoutInfo*             layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets);

void Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindIndexBuffer                    func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType);

void Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    const VkDeviceSize*                         pOffsets);

void Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDraw                               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance);

void Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexed                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance);

void Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirect                       func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirect                func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride);

void Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatch                           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ);

void Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchIndirect                   func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset);

void Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer                         func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions);

void Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage                          func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions);

void Process_vkCmdBlitImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage                          func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter);

void Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage                  func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions);

void Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer                  func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions);

void Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdUpdateBuffer                       func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData);

void Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdFillBuffer                         func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data);

void Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearColorImage                    func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges);

void Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearDepthStencilImage             func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges);

void Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdClearAttachments                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects);

void Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage                       func,
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions);

void Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent                           func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask);

void Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent                         func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask);

void Process_vkCmdWaitEvents(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents                         func,
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
    const VkImageMemoryBarrier*                 pImageMemoryBarriers);

void Process_vkCmdPipelineBarrier(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier                    func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers);

void Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginQuery                         func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags);

void Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndQuery                           func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query);

void Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetQueryPool                     func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount);

void Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp                     func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query);

void Process_vkCmdCopyQueryPoolResults(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyQueryPoolResults               func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags);

void Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushConstants                      func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues);

void Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass                    func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents);

void Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass                        func,
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents);

void Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass                      func,
    VkCommandBuffer                             commandBuffer);

void Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdExecuteCommands                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers);


void Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDeviceMask                      func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask);

void Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchBase                       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ);


void Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCount                  func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCount           func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);

void Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass2                   func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);

void Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass2                       func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);

void Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass2                     func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);


void Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent2                          func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo);

void Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent2                        func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask);

void Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents2                        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos);

void Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier2                   func,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo);

void Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp2                    func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query);

void Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer2                        func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo);

void Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage2                         func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo);

void Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage2                 func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo);

void Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer2                 func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo);

void Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage2                         func,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo);

void Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage2                      func,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo);

void Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRendering                     func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);

void Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRendering                       func,
    VkCommandBuffer                             commandBuffer);

void Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCullMode                        func,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode);

void Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFrontFace                       func,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace);

void Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveTopology               func,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology);

void Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWithCount               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports);

void Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissorWithCount                func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors);

void Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers2                 func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides);

void Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthTestEnable                 func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable);

void Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthWriteEnable                func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable);

void Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthCompareOp                  func,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp);

void Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBoundsTestEnable           func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable);

void Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilTestEnable               func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable);

void Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilOp                       func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp);

void Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizerDiscardEnable         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable);

void Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBiasEnable                 func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable);

void Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveRestartEnable          func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable);











void Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginVideoCodingKHR                func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoBeginCodingInfoKHR*            pBeginInfo);

void Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndVideoCodingKHR                  func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEndCodingInfoKHR*              pEndCodingInfo);

void Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdControlVideoCodingKHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoCodingControlInfoKHR*          pCodingControlInfo);


void Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDecodeVideoKHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoDecodeInfoKHR*                 pDecodeInfo);


void Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderingKHR                  func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo);

void Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderingKHR                    func,
    VkCommandBuffer                             commandBuffer);



void Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDeviceMaskKHR                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask);

void Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDispatchBaseKHR                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ);










void Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSetKHR               func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites);

void Process_vkCmdPushDescriptorSetWithTemplateKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSetWithTemplateKHR   func,
    VkCommandBuffer                             commandBuffer,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    const void*                                 pData);



void Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginRenderPass2KHR                func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo);

void Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdNextSubpass2KHR                    func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);

void Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndRenderPass2KHR                  func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo);













void Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCountKHR               func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCountKHR        func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    const VulkanBufferInfo*                     countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);



void Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFragmentShadingRateKHR          func,
    VkCommandBuffer                             commandBuffer,
    const VkExtent2D*                           pFragmentSize,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps);


void Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRenderingAttachmentLocationsKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingAttachmentLocationInfoKHR* pLocationInfo);

void Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRenderingInputAttachmentIndicesKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkRenderingInputAttachmentIndexInfoKHR* pInputAttachmentIndexInfo);







void Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEncodeVideoKHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkVideoEncodeInfoKHR*                 pEncodeInfo);


void Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetEvent2KHR                       func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    const VkDependencyInfo*                     pDependencyInfo);

void Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResetEvent2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags2                       stageMask);

void Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWaitEvents2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    const VkDependencyInfo*                     pDependencyInfos);

void Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPipelineBarrier2KHR                func,
    VkCommandBuffer                             commandBuffer,
    const VkDependencyInfo*                     pDependencyInfo);

void Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteTimestamp2KHR                 func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query);

void Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteBufferMarker2AMD              func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags2                       stage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker);


void Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBuffer2KHR                     func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferInfo2*                    pCopyBufferInfo);

void Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImage2KHR                      func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageInfo2*                     pCopyImageInfo);

void Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyBufferToImage2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyBufferToImageInfo2*             pCopyBufferToImageInfo);

void Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyImageToBuffer2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyImageToBufferInfo2*             pCopyImageToBufferInfo);

void Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBlitImage2KHR                      func,
    VkCommandBuffer                             commandBuffer,
    const VkBlitImageInfo2*                     pBlitImageInfo);

void Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdResolveImage2KHR                   func,
    VkCommandBuffer                             commandBuffer,
    const VkResolveImageInfo2*                  pResolveImageInfo);


void Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysIndirect2KHR              func,
    VkCommandBuffer                             commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress);



void Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindIndexBuffer2KHR                func,
    VkCommandBuffer                             commandBuffer,
    const VulkanBufferInfo*                     buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType);




void Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineStippleKHR                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern);



void Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorSets2KHR             func,
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorSetsInfoKHR*          pBindDescriptorSetsInfo);

void Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushConstants2KHR                  func,
    VkCommandBuffer                             commandBuffer,
    const VkPushConstantsInfoKHR*               pPushConstantsInfo);

void Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSet2KHR              func,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetInfoKHR*           pPushDescriptorSetInfo);

void Process_vkCmdPushDescriptorSetWithTemplate2KHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPushDescriptorSetWithTemplate2KHR  func,
    VkCommandBuffer                             commandBuffer,
    const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

void Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDescriptorBufferOffsets2EXT     func,
    VkCommandBuffer                             commandBuffer,
    const VkSetDescriptorBufferOffsetsInfoEXT*  pSetDescriptorBufferOffsetsInfo);

void Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT func,
    VkCommandBuffer                             commandBuffer,
    const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);




void Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerBeginEXT                func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo);

void Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerEndEXT                  func,
    VkCommandBuffer                             commandBuffer);

void Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDebugMarkerInsertEXT               func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo);


void Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindTransformFeedbackBuffersEXT    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes);

void Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginTransformFeedbackEXT          func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets);

void Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndTransformFeedbackEXT            func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    const VkBuffer*                             pCounterBuffers,
    const VkDeviceSize*                         pCounterBufferOffsets);

void Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginQueryIndexedEXT               func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index);

void Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndQueryIndexedEXT                 func,
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    uint32_t                                    index);

void Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectByteCountEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    VkBuffer                                    counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride);



void Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndirectCountAMD               func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawIndexedIndirectCountAMD        func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);







void Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginConditionalRenderingEXT       func,
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin);

void Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndConditionalRenderingEXT         func,
    VkCommandBuffer                             commandBuffer);


void Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWScalingNV              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings);







void Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles);

void Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleEnableEXT       func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    discardRectangleEnable);

void Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDiscardRectangleModeEXT         func,
    VkCommandBuffer                             commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode);





void Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBeginDebugUtilsLabelEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo);

void Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdEndDebugUtilsLabelEXT              func,
    VkCommandBuffer                             commandBuffer);

void Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdInsertDebugUtilsLabelEXT           func,
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo);



void Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleLocationsEXT              func,
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo);




void Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindShadingRateImageNV             func,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout);

void Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportShadingRatePaletteNV    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkShadingRatePaletteNV*               pShadingRatePalettes);

void Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoarseSampleOrderNV             func,
    VkCommandBuffer                             commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    const VkCoarseSampleOrderCustomNV*          pCustomSampleOrders);


void Process_vkCmdBuildAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructureNV       func,
    VkCommandBuffer                             commandBuffer,
    const VkAccelerationStructureInfoNV*        pInfo,
    VkBuffer                                    instanceData,
    VkDeviceSize                                instanceOffset,
    VkBool32                                    update,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkBuffer                                    scratch,
    VkDeviceSize                                scratchOffset);

void Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureNV        func,
    VkCommandBuffer                             commandBuffer,
    VkAccelerationStructureNV                   dst,
    VkAccelerationStructureNV                   src,
    VkCopyAccelerationStructureModeKHR          mode);

void Process_vkCmdTraceRaysNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysNV                        func,
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
    uint32_t                                    depth);

void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesNV func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureNV*            pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery);



void Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteBufferMarkerAMD               func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker);



void Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksNV                    func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask);

void Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectNV            func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectCountNV       func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);


void Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExclusiveScissorEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkBool32*                             pExclusiveScissorEnables);

void Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExclusiveScissorNV              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    const VkRect2D*                             pExclusiveScissors);


void Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCheckpointNV                    func,
    VkCommandBuffer                             commandBuffer,
    const void*                                 pCheckpointMarker);


void Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceMarkerINTEL          func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceMarkerInfoINTEL*         pMarkerInfo);

void Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceStreamMarkerINTEL    func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceStreamMarkerInfoINTEL*   pMarkerInfo);

void Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPerformanceOverrideINTEL        func,
    VkResult                                    returnValue,
    VkCommandBuffer                             commandBuffer,
    const VkPerformanceOverrideInfoINTEL*       pOverrideInfo);











void Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineStippleEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern);



void Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCullModeEXT                     func,
    VkCommandBuffer                             commandBuffer,
    VkCullModeFlags                             cullMode);

void Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFrontFaceEXT                    func,
    VkCommandBuffer                             commandBuffer,
    VkFrontFace                                 frontFace);

void Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveTopologyEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkPrimitiveTopology                         primitiveTopology);

void Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWithCountEXT            func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports);

void Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetScissorWithCountEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors);

void Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindVertexBuffers2EXT              func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets,
    const VkDeviceSize*                         pSizes,
    const VkDeviceSize*                         pStrides);

void Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthTestEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthTestEnable);

void Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthWriteEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthWriteEnable);

void Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthCompareOpEXT               func,
    VkCommandBuffer                             commandBuffer,
    VkCompareOp                                 depthCompareOp);

void Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBoundsTestEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBoundsTestEnable);

void Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilTestEnableEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stencilTestEnable);

void Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetStencilOpEXT                    func,
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp);




void Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPreprocessGeneratedCommandsNV      func,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo);

void Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdExecuteGeneratedCommandsNV         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoNV*            pGeneratedCommandsInfo);

void Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindPipelineShaderGroupNV          func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline,
    uint32_t                                    groupIndex);


void Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBias2EXT                   func,
    VkCommandBuffer                             commandBuffer,
    const VkDepthBiasInfoEXT*                   pDepthBiasInfo);




void Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetFragmentShadingRateEnumNV       func,
    VkCommandBuffer                             commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    const VkFragmentShadingRateCombinerOpKHR*   combinerOps);





void Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetVertexInputEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions);




void Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindInvocationMaskHUAWEI           func,
    VkCommandBuffer                             commandBuffer,
    VkImageView                                 imageView,
    VkImageLayout                               imageLayout);



void Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPatchControlPointsEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    patchControlPoints);

void Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizerDiscardEnableEXT      func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    rasterizerDiscardEnable);

void Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthBiasEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthBiasEnable);

void Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLogicOpEXT                      func,
    VkCommandBuffer                             commandBuffer,
    VkLogicOp                                   logicOp);

void Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPrimitiveRestartEnableEXT       func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    primitiveRestartEnable);



void Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorWriteEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorWriteEnables);


void Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMultiEXT                       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawInfoEXT*                   pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride);

void Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMultiIndexedEXT                func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    drawCount,
    const VkMultiDrawIndexedInfoEXT*            pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    const int32_t*                              pVertexOffset);


void Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildMicromapsEXT                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkMicromapBuildInfoEXT*               pInfos);

void Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMicromapEXT                    func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapInfoEXT*                pInfo);

void Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMicromapToMemoryEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMicromapToMemoryInfoEXT*        pInfo);

void Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMemoryToMicromapEXT            func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToMicromapInfoEXT*        pInfo);

void Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteMicromapsPropertiesEXT        func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    micromapCount,
    const VkMicromapEXT*                        pMicromaps,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery);


void Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawClusterHUAWEI                  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ);

void Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawClusterIndirectHUAWEI          func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset);




void Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdUpdatePipelineIndirectBufferNV     func,
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline);


void Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClampEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClampEnable);

void Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetPolygonModeEXT                  func,
    VkCommandBuffer                             commandBuffer,
    VkPolygonMode                               polygonMode);

void Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizationSamplesEXT         func,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples);

void Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleMaskEXT                   func,
    VkCommandBuffer                             commandBuffer,
    VkSampleCountFlagBits                       samples,
    const VkSampleMask*                         pSampleMask);

void Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAlphaToCoverageEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToCoverageEnable);

void Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAlphaToOneEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    alphaToOneEnable);

void Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLogicOpEnableEXT                func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    logicOpEnable);

void Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendEnableEXT             func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkBool32*                             pColorBlendEnables);

void Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendEquationEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendEquationEXT*              pColorBlendEquations);

void Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorWriteMaskEXT               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorComponentFlags*                pColorWriteMasks);

void Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetTessellationDomainOriginEXT     func,
    VkCommandBuffer                             commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin);

void Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRasterizationStreamEXT          func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    rasterizationStream);

void Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetConservativeRasterizationModeEXT func,
    VkCommandBuffer                             commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode);

void Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT func,
    VkCommandBuffer                             commandBuffer,
    float                                       extraPrimitiveOverestimationSize);

void Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClipEnableEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    depthClipEnable);

void Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetSampleLocationsEnableEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    sampleLocationsEnable);

void Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetColorBlendAdvancedEXT           func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    const VkColorBlendAdvancedEXT*              pColorBlendAdvanced);

void Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetProvokingVertexModeEXT          func,
    VkCommandBuffer                             commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode);

void Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineRasterizationModeEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode);

void Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetLineStippleEnableEXT            func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    stippledLineEnable);

void Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClipNegativeOneToOneEXT    func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    negativeOneToOne);

void Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportWScalingEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    viewportWScalingEnable);

void Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetViewportSwizzleNV               func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportSwizzleNV*                  pViewportSwizzles);

void Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageToColorEnableNV         func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageToColorEnable);

void Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageToColorLocationNV       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageToColorLocation);

void Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationModeNV        func,
    VkCommandBuffer                             commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode);

void Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationTableEnableNV func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    coverageModulationTableEnable);

void Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageModulationTableNV       func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    const float*                                pCoverageModulationTable);

void Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetShadingRateImageEnableNV        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    shadingRateImageEnable);

void Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRepresentativeFragmentTestEnableNV func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    representativeFragmentTestEnable);

void Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetCoverageReductionModeNV         func,
    VkCommandBuffer                             commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode);



void Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdOpticalFlowExecuteNV               func,
    VkCommandBuffer                             commandBuffer,
    VkOpticalFlowSessionNV                      session,
    const VkOpticalFlowExecuteInfoNV*           pExecuteInfo);



void Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBindShadersEXT                     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    stageCount,
    const VkShaderStageFlagBits*                pStages,
    const VkShaderEXT*                          pShaders);

void Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetDepthClampRangeEXT              func,
    VkCommandBuffer                             commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    const VkDepthClampRangeEXT*                 pDepthClampRange);




void Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT func,
    VkCommandBuffer                             commandBuffer,
    VkImageAspectFlags                          aspectMask);


void Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdPreprocessGeneratedCommandsEXT     func,
    VkCommandBuffer                             commandBuffer,
    const VkGeneratedCommandsInfoEXT*           pGeneratedCommandsInfo,
    VkCommandBuffer                             stateCommandBuffer);

void Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdExecuteGeneratedCommandsEXT        func,
    VkCommandBuffer                             commandBuffer,
    VkBool32                                    isPreprocessed,
    const VkGeneratedCommandsInfoEXT*           pGeneratedCommandsInfo);


void Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructuresKHR     func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const * ppBuildRangeInfos);

void Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdBuildAccelerationStructuresIndirectKHR func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR* pInfos,
    const VkDeviceAddress*                      pIndirectDeviceAddresses,
    const uint32_t*                             pIndirectStrides,
    const uint32_t* const *                     ppMaxPrimitiveCounts);

void Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureKHR       func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureInfoKHR*   pInfo);

void Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyAccelerationStructureToMemoryKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdCopyMemoryToAccelerationStructureKHR func,
    VkCommandBuffer                             commandBuffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdWriteAccelerationStructuresPropertiesKHR func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    accelerationStructureCount,
    const VkAccelerationStructureKHR*           pAccelerationStructures,
    VkQueryType                                 queryType,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery);


void Process_vkCmdTraceRaysKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysKHR                       func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth);

void Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdTraceRaysIndirectKHR               func,
    VkCommandBuffer                             commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress);

void Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdSetRayTracingPipelineStackSizeKHR  func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    pipelineStackSize);


void Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksEXT                   func,
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ);

void Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectEXT           func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride);

void Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    PFN_vkCmdDrawMeshTasksIndirectCountEXT      func,
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride);

};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
