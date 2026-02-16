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

#include "generated/generated_vulkan_referenced_block_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReferencedBlockConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkEndCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkResetCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageCopy>*  pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(srcImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(dstImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(dstImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferImageCopy>* pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(srcImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdUpdateBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    GFXRECON_UNREFERENCED_PARAMETER(dstOffset);
    GFXRECON_UNREFERENCED_PARAMETER(dataSize);
    GFXRECON_UNREFERENCED_PARAMETER(pData);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdFillBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    GFXRECON_UNREFERENCED_PARAMETER(dstOffset);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_UNREFERENCED_PARAMETER(data);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier(
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
    GFXRECON_UNREFERENCED_PARAMETER(srcStageMask);
    GFXRECON_UNREFERENCED_PARAMETER(dstStageMask);
    GFXRECON_UNREFERENCED_PARAMETER(dependencyFlags);
    GFXRECON_UNREFERENCED_PARAMETER(memoryBarrierCount);
    GFXRECON_UNREFERENCED_PARAMETER(pMemoryBarriers);
    GFXRECON_UNREFERENCED_PARAMETER(bufferMemoryBarrierCount);
    GFXRECON_UNREFERENCED_PARAMETER(imageMemoryBarrierCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetQueryPool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);
    GFXRECON_UNREFERENCED_PARAMETER(queryCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineStage);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyQueryPoolResults(
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
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);
    GFXRECON_UNREFERENCED_PARAMETER(queryCount);
    GFXRECON_UNREFERENCED_PARAMETER(dstOffset);
    GFXRECON_UNREFERENCED_PARAMETER(stride);
    GFXRECON_UNREFERENCED_PARAMETER(flags);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    GFXRECON_UNREFERENCED_PARAMETER(commandBufferCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets(
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
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(firstSet);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorSetCount);
    GFXRECON_UNREFERENCED_PARAMETER(dynamicOffsetCount);
    GFXRECON_UNREFERENCED_PARAMETER(pDynamicOffsets);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearColorImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearColorValue>* pColor,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(pColor);
    GFXRECON_UNREFERENCED_PARAMETER(rangeCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRanges);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    GFXRECON_UNREFERENCED_PARAMETER(groupCountX);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountY);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountZ);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);
    GFXRECON_UNREFERENCED_PARAMETER(stageMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags                        stageMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);
    GFXRECON_UNREFERENCED_PARAMETER(stageMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents(
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
    GFXRECON_UNREFERENCED_PARAMETER(eventCount);
    GFXRECON_UNREFERENCED_PARAMETER(pEvents);
    GFXRECON_UNREFERENCED_PARAMETER(srcStageMask);
    GFXRECON_UNREFERENCED_PARAMETER(dstStageMask);
    GFXRECON_UNREFERENCED_PARAMETER(memoryBarrierCount);
    GFXRECON_UNREFERENCED_PARAMETER(pMemoryBarriers);
    GFXRECON_UNREFERENCED_PARAMETER(bufferMemoryBarrierCount);
    GFXRECON_UNREFERENCED_PARAMETER(imageMemoryBarrierCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    PointerDecoder<uint8_t>*                    pValues)
{
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(stageFlags);
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_UNREFERENCED_PARAMETER(pValues);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstViewport);
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pViewports);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstScissor);
    GFXRECON_UNREFERENCED_PARAMETER(scissorCount);
    GFXRECON_UNREFERENCED_PARAMETER(pScissors);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineWidth(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       lineWidth)
{
    GFXRECON_UNREFERENCED_PARAMETER(lineWidth);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthBiasConstantFactor);
    GFXRECON_UNREFERENCED_PARAMETER(depthBiasClamp);
    GFXRECON_UNREFERENCED_PARAMETER(depthBiasSlopeFactor);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetBlendConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    PointerDecoder<float>*                      blendConstants)
{
    GFXRECON_UNREFERENCED_PARAMETER(blendConstants);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    GFXRECON_UNREFERENCED_PARAMETER(minDepthBounds);
    GFXRECON_UNREFERENCED_PARAMETER(maxDepthBounds);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilCompareMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(faceMask);
    GFXRECON_UNREFERENCED_PARAMETER(compareMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilWriteMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(faceMask);
    GFXRECON_UNREFERENCED_PARAMETER(writeMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilReference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    GFXRECON_UNREFERENCED_PARAMETER(faceMask);
    GFXRECON_UNREFERENCED_PARAMETER(reference);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(indexType);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstBinding);
    GFXRECON_UNREFERENCED_PARAMETER(bindingCount);
    GFXRECON_UNREFERENCED_PARAMETER(pOffsets);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDraw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(vertexCount);
    GFXRECON_UNREFERENCED_PARAMETER(instanceCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstVertex);
    GFXRECON_UNREFERENCED_PARAMETER(firstInstance);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    GFXRECON_UNREFERENCED_PARAMETER(indexCount);
    GFXRECON_UNREFERENCED_PARAMETER(instanceCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstIndex);
    GFXRECON_UNREFERENCED_PARAMETER(vertexOffset);
    GFXRECON_UNREFERENCED_PARAMETER(firstInstance);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage(
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
    GFXRECON_UNREFERENCED_PARAMETER(srcImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(dstImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);
    GFXRECON_UNREFERENCED_PARAMETER(filter);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearDepthStencilImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            image,
    VkImageLayout                               imageLayout,
    StructPointerDecoder<Decoded_VkClearDepthStencilValue>* pDepthStencil,
    uint32_t                                    rangeCount,
    StructPointerDecoder<Decoded_VkImageSubresourceRange>* pRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(pDepthStencil);
    GFXRECON_UNREFERENCED_PARAMETER(rangeCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRanges);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdClearAttachments(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkClearAttachment>* pAttachments,
    uint32_t                                    rectCount,
    StructPointerDecoder<Decoded_VkClearRect>*  pRects)
{
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pAttachments);
    GFXRECON_UNREFERENCED_PARAMETER(rectCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRects);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcImage,
    VkImageLayout                               srcImageLayout,
    format::HandleId                            dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkImageResolve>* pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(srcImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(dstImageLayout);
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    GFXRECON_UNREFERENCED_PARAMETER(contents);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSubpassContents                           contents)
{
    GFXRECON_UNREFERENCED_PARAMETER(contents);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDeviceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(deviceMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchBase(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupX);
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupY);
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupZ);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountX);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountY);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountZ);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    GFXRECON_UNREFERENCED_PARAMETER(stage);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);
    GFXRECON_UNREFERENCED_PARAMETER(stageMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(eventCount);
    GFXRECON_UNREFERENCED_PARAMETER(pEvents);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCullMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(cullMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFrontFace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    GFXRECON_UNREFERENCED_PARAMETER(frontFace);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    GFXRECON_UNREFERENCED_PARAMETER(primitiveTopology);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pViewports);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissorWithCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    GFXRECON_UNREFERENCED_PARAMETER(scissorCount);
    GFXRECON_UNREFERENCED_PARAMETER(pScissors);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstBinding);
    GFXRECON_UNREFERENCED_PARAMETER(bindingCount);
    GFXRECON_UNREFERENCED_PARAMETER(pOffsets);
    GFXRECON_UNREFERENCED_PARAMETER(pSizes);
    GFXRECON_UNREFERENCED_PARAMETER(pStrides);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthWriteEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthWriteEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthCompareOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthCompareOp);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBoundsTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthBoundsTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilTestEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(stencilTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilOp(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    GFXRECON_UNREFERENCED_PARAMETER(faceMask);
    GFXRECON_UNREFERENCED_PARAMETER(failOp);
    GFXRECON_UNREFERENCED_PARAMETER(passOp);
    GFXRECON_UNREFERENCED_PARAMETER(depthFailOp);
    GFXRECON_UNREFERENCED_PARAMETER(compareOp);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizerDiscardEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(rasterizerDiscardEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBiasEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthBiasEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveRestartEnable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(primitiveRestartEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorWriteCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pPushConstantsInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStipple(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    GFXRECON_UNREFERENCED_PARAMETER(lineStippleFactor);
    GFXRECON_UNREFERENCED_PARAMETER(lineStipplePattern);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_UNREFERENCED_PARAMETER(indexType);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingAttachmentLocations(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pLocationInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingInputAttachmentIndices(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pInputAttachmentIndexInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEndCodingInfoKHR>* pEndCodingInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pEndCodingInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdControlVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoCodingControlInfoKHR>* pCodingControlInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pCodingControlInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDeviceMaskKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    deviceMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(deviceMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchBaseKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupX);
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupY);
    GFXRECON_UNREFERENCED_PARAMETER(baseGroupZ);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountX);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountY);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountZ);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSetKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);
    GFXRECON_UNREFERENCED_PARAMETER(descriptorWriteCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdNextSubpass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSubpassEndInfo>* pSubpassEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFragmentShadingRateKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkExtent2D>*   pFragmentSize,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    GFXRECON_UNREFERENCED_PARAMETER(pFragmentSize);
    GFXRECON_UNREFERENCED_PARAMETER(combinerOps);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingAttachmentLocationsKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingAttachmentLocationInfo>* pLocationInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pLocationInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRenderingInputAttachmentIndicesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInputAttachmentIndexInfo>* pInputAttachmentIndexInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pInputAttachmentIndexInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    VkPipelineStageFlags2                       stageMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);
    GFXRECON_UNREFERENCED_PARAMETER(stageMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(eventCount);
    GFXRECON_UNREFERENCED_PARAMETER(pEvents);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteTimestamp2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            queryPool,
    uint32_t                                    query)
{
    GFXRECON_UNREFERENCED_PARAMETER(stage);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysIndirect2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDeviceAddress                             indirectDeviceAddress)
{
    GFXRECON_UNREFERENCED_PARAMETER(indirectDeviceAddress);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindIndexBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkIndexType                                 indexType)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_UNREFERENCED_PARAMETER(indexType);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    GFXRECON_UNREFERENCED_PARAMETER(lineStippleFactor);
    GFXRECON_UNREFERENCED_PARAMETER(lineStipplePattern);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushConstants2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushConstantsInfo>* pPushConstantsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pPushConstantsInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDescriptorBufferOffsets2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSetDescriptorBufferOffsetsInfoEXT>* pSetDescriptorBufferOffsetsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSetDescriptorBufferOffsetsInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT>* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pBindDescriptorBufferEmbeddedSamplersInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryIndirectInfoKHR>* pCopyMemoryIndirectInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pCopyMemoryIndirectInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR>* pCopyMemoryToImageIndirectInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pRenderingEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerBeginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pMarkerInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerEndEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDebugMarkerInsertEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>* pMarkerInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pMarkerInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstBinding);
    GFXRECON_UNREFERENCED_PARAMETER(bindingCount);
    GFXRECON_UNREFERENCED_PARAMETER(pOffsets);
    GFXRECON_UNREFERENCED_PARAMETER(pSizes);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstCounterBuffer);
    GFXRECON_UNREFERENCED_PARAMETER(counterBufferCount);
    GFXRECON_UNREFERENCED_PARAMETER(pCounterBufferOffsets);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndTransformFeedbackEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstCounterBuffer,
    uint32_t                                    counterBufferCount,
    HandlePointerDecoder<VkBuffer>*             pCounterBuffers,
    PointerDecoder<VkDeviceSize>*               pCounterBufferOffsets)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstCounterBuffer);
    GFXRECON_UNREFERENCED_PARAMETER(counterBufferCount);
    GFXRECON_UNREFERENCED_PARAMETER(pCounterBufferOffsets);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags,
    uint32_t                                    index)
{
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);
    GFXRECON_UNREFERENCED_PARAMETER(flags);
    GFXRECON_UNREFERENCED_PARAMETER(index);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndQueryIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            queryPool,
    uint32_t                                    query,
    uint32_t                                    index)
{
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(query);
    GFXRECON_UNREFERENCED_PARAMETER(index);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectByteCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    format::HandleId                            counterBuffer,
    VkDeviceSize                                counterBufferOffset,
    uint32_t                                    counterOffset,
    uint32_t                                    vertexStride)
{
    GFXRECON_UNREFERENCED_PARAMETER(instanceCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstInstance);
    GFXRECON_UNREFERENCED_PARAMETER(counterBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(counterOffset);
    GFXRECON_UNREFERENCED_PARAMETER(vertexStride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWScalingNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstViewport);
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pViewportWScalings);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pDiscardRectangles)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstDiscardRectangle);
    GFXRECON_UNREFERENCED_PARAMETER(discardRectangleCount);
    GFXRECON_UNREFERENCED_PARAMETER(pDiscardRectangles);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    discardRectangleEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(discardRectangleEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDiscardRectangleModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDiscardRectangleModeEXT                   discardRectangleMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(discardRectangleMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pLabelInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdInsertDebugUtilsLabelEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pLabelInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pLabelInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleLocationsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>* pSampleLocationsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSampleLocationsInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportShadingRatePaletteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstViewport);
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pShadingRatePalettes);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoarseSampleOrderNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoarseSampleOrderTypeNV                   sampleOrderType,
    uint32_t                                    customSampleOrderCount,
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders)
{
    GFXRECON_UNREFERENCED_PARAMETER(sampleOrderType);
    GFXRECON_UNREFERENCED_PARAMETER(customSampleOrderCount);
    GFXRECON_UNREFERENCED_PARAMETER(pCustomSampleOrders);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructureNV(
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
    GFXRECON_UNREFERENCED_PARAMETER(instanceOffset);
    GFXRECON_UNREFERENCED_PARAMETER(update);
    GFXRECON_UNREFERENCED_PARAMETER(dst);
    GFXRECON_UNREFERENCED_PARAMETER(src);
    GFXRECON_UNREFERENCED_PARAMETER(scratchOffset);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            dst,
    format::HandleId                            src,
    VkCopyAccelerationStructureModeKHR          mode)
{
    GFXRECON_UNREFERENCED_PARAMETER(dst);
    GFXRECON_UNREFERENCED_PARAMETER(src);
    GFXRECON_UNREFERENCED_PARAMETER(mode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysNV(
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
    GFXRECON_UNREFERENCED_PARAMETER(raygenShaderBindingOffset);
    GFXRECON_UNREFERENCED_PARAMETER(missShaderBindingOffset);
    GFXRECON_UNREFERENCED_PARAMETER(missShaderBindingStride);
    GFXRECON_UNREFERENCED_PARAMETER(hitShaderBindingOffset);
    GFXRECON_UNREFERENCED_PARAMETER(hitShaderBindingStride);
    GFXRECON_UNREFERENCED_PARAMETER(callableShaderBindingOffset);
    GFXRECON_UNREFERENCED_PARAMETER(callableShaderBindingStride);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(depth);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    GFXRECON_UNREFERENCED_PARAMETER(accelerationStructureCount);
    GFXRECON_UNREFERENCED_PARAMETER(pAccelerationStructures);
    GFXRECON_UNREFERENCED_PARAMETER(queryType);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteBufferMarkerAMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineStage);
    GFXRECON_UNREFERENCED_PARAMETER(dstOffset);
    GFXRECON_UNREFERENCED_PARAMETER(marker);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteBufferMarker2AMD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineStageFlags2                       stage,
    format::HandleId                            dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    GFXRECON_UNREFERENCED_PARAMETER(stage);
    GFXRECON_UNREFERENCED_PARAMETER(dstOffset);
    GFXRECON_UNREFERENCED_PARAMETER(marker);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    taskCount,
    uint32_t                                    firstTask)
{
    GFXRECON_UNREFERENCED_PARAMETER(taskCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstTask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExclusiveScissorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    PointerDecoder<VkBool32>*                   pExclusiveScissorEnables)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstExclusiveScissor);
    GFXRECON_UNREFERENCED_PARAMETER(exclusiveScissorCount);
    GFXRECON_UNREFERENCED_PARAMETER(pExclusiveScissorEnables);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExclusiveScissorNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstExclusiveScissor,
    uint32_t                                    exclusiveScissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pExclusiveScissors)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstExclusiveScissor);
    GFXRECON_UNREFERENCED_PARAMETER(exclusiveScissorCount);
    GFXRECON_UNREFERENCED_PARAMETER(pExclusiveScissors);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCheckpointNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint64_t                                    pCheckpointMarker)
{
    GFXRECON_UNREFERENCED_PARAMETER(pCheckpointMarker);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>* pMarkerInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pMarkerInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceStreamMarkerINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>* pMarkerInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pMarkerInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPerformanceOverrideINTEL(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>* pOverrideInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pOverrideInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    lineStippleFactor,
    uint16_t                                    lineStipplePattern)
{
    GFXRECON_UNREFERENCED_PARAMETER(lineStippleFactor);
    GFXRECON_UNREFERENCED_PARAMETER(lineStipplePattern);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCullModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCullModeFlags                             cullMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(cullMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFrontFaceEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFrontFace                                 frontFace)
{
    GFXRECON_UNREFERENCED_PARAMETER(frontFace);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveTopologyEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPrimitiveTopology                         primitiveTopology)
{
    GFXRECON_UNREFERENCED_PARAMETER(primitiveTopology);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewport>*   pViewports)
{
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pViewports);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetScissorWithCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    scissorCount,
    StructPointerDecoder<Decoded_VkRect2D>*     pScissors)
{
    GFXRECON_UNREFERENCED_PARAMETER(scissorCount);
    GFXRECON_UNREFERENCED_PARAMETER(pScissors);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindVertexBuffers2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    HandlePointerDecoder<VkBuffer>*             pBuffers,
    PointerDecoder<VkDeviceSize>*               pOffsets,
    PointerDecoder<VkDeviceSize>*               pSizes,
    PointerDecoder<VkDeviceSize>*               pStrides)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstBinding);
    GFXRECON_UNREFERENCED_PARAMETER(bindingCount);
    GFXRECON_UNREFERENCED_PARAMETER(pOffsets);
    GFXRECON_UNREFERENCED_PARAMETER(pSizes);
    GFXRECON_UNREFERENCED_PARAMETER(pStrides);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthWriteEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthWriteEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthCompareOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCompareOp                                 depthCompareOp)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthCompareOp);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBoundsTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBoundsTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthBoundsTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilTestEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stencilTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(stencilTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetStencilOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkStencilFaceFlags                          faceMask,
    VkStencilOp                                 failOp,
    VkStencilOp                                 passOp,
    VkStencilOp                                 depthFailOp,
    VkCompareOp                                 compareOp)
{
    GFXRECON_UNREFERENCED_PARAMETER(faceMask);
    GFXRECON_UNREFERENCED_PARAMETER(failOp);
    GFXRECON_UNREFERENCED_PARAMETER(passOp);
    GFXRECON_UNREFERENCED_PARAMETER(depthFailOp);
    GFXRECON_UNREFERENCED_PARAMETER(compareOp);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(isPreprocessed);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindPipelineShaderGroupNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline,
    uint32_t                                    groupIndex)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(groupIndex);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBias2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDepthBiasInfoEXT>* pDepthBiasInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pDepthBiasInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchTileQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDispatchTileInfoQCOM>* pDispatchTileInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pDispatchTileInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileBeginInfoQCOM>* pPerTileBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pPerTileBeginInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndPerTileExecutionQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPerTileEndInfoQCOM>* pPerTileEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pPerTileEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBuffersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    bufferCount,
    StructPointerDecoder<Decoded_VkDescriptorBufferBindingInfoEXT>* pBindingInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(bufferCount);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDescriptorBufferOffsetsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    setCount,
    PointerDecoder<uint32_t>*                   pBufferIndices,
    PointerDecoder<VkDeviceSize>*               pOffsets)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(firstSet);
    GFXRECON_UNREFERENCED_PARAMETER(setCount);
    GFXRECON_UNREFERENCED_PARAMETER(pBufferIndices);
    GFXRECON_UNREFERENCED_PARAMETER(pOffsets);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindDescriptorBufferEmbeddedSamplersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            layout,
    uint32_t                                    set)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);
    GFXRECON_UNREFERENCED_PARAMETER(layout);
    GFXRECON_UNREFERENCED_PARAMETER(set);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetFragmentShadingRateEnumNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkFragmentShadingRateNV                     shadingRate,
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR>* combinerOps)
{
    GFXRECON_UNREFERENCED_PARAMETER(shadingRate);
    GFXRECON_UNREFERENCED_PARAMETER(combinerOps);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetVertexInputEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    vertexBindingDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription2EXT>* pVertexBindingDescriptions,
    uint32_t                                    vertexAttributeDescriptionCount,
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription2EXT>* pVertexAttributeDescriptions)
{
    GFXRECON_UNREFERENCED_PARAMETER(vertexBindingDescriptionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pVertexBindingDescriptions);
    GFXRECON_UNREFERENCED_PARAMETER(vertexAttributeDescriptionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pVertexAttributeDescriptions);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPatchControlPointsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    patchControlPoints)
{
    GFXRECON_UNREFERENCED_PARAMETER(patchControlPoints);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizerDiscardEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    rasterizerDiscardEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(rasterizerDiscardEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthBiasEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthBiasEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthBiasEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLogicOpEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLogicOp                                   logicOp)
{
    GFXRECON_UNREFERENCED_PARAMETER(logicOp);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPrimitiveRestartEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    primitiveRestartEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(primitiveRestartEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorWriteEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorWriteEnables)
{
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pColorWriteEnables);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMultiEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawInfoEXT>* pVertexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(pVertexInfo);
    GFXRECON_UNREFERENCED_PARAMETER(instanceCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstInstance);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMultiIndexedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    drawCount,
    StructPointerDecoder<Decoded_VkMultiDrawIndexedInfoEXT>* pIndexInfo,
    uint32_t                                    instanceCount,
    uint32_t                                    firstInstance,
    uint32_t                                    stride,
    PointerDecoder<int32_t>*                    pVertexOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(pIndexInfo);
    GFXRECON_UNREFERENCED_PARAMETER(instanceCount);
    GFXRECON_UNREFERENCED_PARAMETER(firstInstance);
    GFXRECON_UNREFERENCED_PARAMETER(stride);
    GFXRECON_UNREFERENCED_PARAMETER(pVertexOffset);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildMicromapsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkMicromapBuildInfoEXT>* pInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(infoCount);
    GFXRECON_UNREFERENCED_PARAMETER(pInfos);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapInfoEXT>* pInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMicromapToMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMicromapToMemoryInfoEXT>* pInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToMicromapEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToMicromapInfoEXT>* pInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteMicromapsPropertiesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    micromapCount,
    HandlePointerDecoder<VkMicromapEXT>*        pMicromaps,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    GFXRECON_UNREFERENCED_PARAMETER(micromapCount);
    GFXRECON_UNREFERENCED_PARAMETER(pMicromaps);
    GFXRECON_UNREFERENCED_PARAMETER(queryType);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawClusterHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    GFXRECON_UNREFERENCED_PARAMETER(groupCountX);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountY);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountZ);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdUpdatePipelineIndirectBufferNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    format::HandleId                            pipeline)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineBindPoint);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClampEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClampEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthClampEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetPolygonModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkPolygonMode                               polygonMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(polygonMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizationSamplesEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       rasterizationSamples)
{
    GFXRECON_UNREFERENCED_PARAMETER(rasterizationSamples);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkSampleCountFlagBits                       samples,
    PointerDecoder<VkSampleMask>*               pSampleMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(samples);
    GFXRECON_UNREFERENCED_PARAMETER(pSampleMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAlphaToCoverageEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToCoverageEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(alphaToCoverageEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAlphaToOneEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    alphaToOneEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(alphaToOneEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLogicOpEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    logicOpEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(logicOpEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkBool32>*                   pColorBlendEnables)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstAttachment);
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pColorBlendEnables);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendEquationEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendEquationEXT>* pColorBlendEquations)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstAttachment);
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pColorBlendEquations);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorWriteMaskEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    PointerDecoder<VkColorComponentFlags>*      pColorWriteMasks)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstAttachment);
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pColorWriteMasks);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetTessellationDomainOriginEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkTessellationDomainOrigin                  domainOrigin)
{
    GFXRECON_UNREFERENCED_PARAMETER(domainOrigin);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRasterizationStreamEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    rasterizationStream)
{
    GFXRECON_UNREFERENCED_PARAMETER(rasterizationStream);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetConservativeRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkConservativeRasterizationModeEXT          conservativeRasterizationMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(conservativeRasterizationMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetExtraPrimitiveOverestimationSizeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    float                                       extraPrimitiveOverestimationSize)
{
    GFXRECON_UNREFERENCED_PARAMETER(extraPrimitiveOverestimationSize);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClipEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    depthClipEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthClipEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetSampleLocationsEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    sampleLocationsEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(sampleLocationsEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetColorBlendAdvancedEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstAttachment,
    uint32_t                                    attachmentCount,
    StructPointerDecoder<Decoded_VkColorBlendAdvancedEXT>* pColorBlendAdvanced)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstAttachment);
    GFXRECON_UNREFERENCED_PARAMETER(attachmentCount);
    GFXRECON_UNREFERENCED_PARAMETER(pColorBlendAdvanced);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetProvokingVertexModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkProvokingVertexModeEXT                    provokingVertexMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(provokingVertexMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineRasterizationModeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkLineRasterizationModeEXT                  lineRasterizationMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(lineRasterizationMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetLineStippleEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    stippledLineEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(stippledLineEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClipNegativeOneToOneEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    negativeOneToOne)
{
    GFXRECON_UNREFERENCED_PARAMETER(negativeOneToOne);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportWScalingEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    viewportWScalingEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(viewportWScalingEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetViewportSwizzleNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles)
{
    GFXRECON_UNREFERENCED_PARAMETER(firstViewport);
    GFXRECON_UNREFERENCED_PARAMETER(viewportCount);
    GFXRECON_UNREFERENCED_PARAMETER(pViewportSwizzles);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageToColorEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageToColorEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageToColorEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageToColorLocationNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageToColorLocation)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageToColorLocation);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageModulationModeNV                  coverageModulationMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageModulationMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationTableEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    coverageModulationTableEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageModulationTableEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageModulationTableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    coverageModulationTableCount,
    PointerDecoder<float>*                      pCoverageModulationTable)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageModulationTableCount);
    GFXRECON_UNREFERENCED_PARAMETER(pCoverageModulationTable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetShadingRateImageEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    shadingRateImageEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(shadingRateImageEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRepresentativeFragmentTestEnableNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    representativeFragmentTestEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(representativeFragmentTestEnable);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetCoverageReductionModeNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkCoverageReductionModeNV                   coverageReductionMode)
{
    GFXRECON_UNREFERENCED_PARAMETER(coverageReductionMode);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdOpticalFlowExecuteNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkOpticalFlowExecuteInfoNV>* pExecuteInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(session);
    GFXRECON_UNREFERENCED_PARAMETER(pExecuteInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindShadersEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    stageCount,
    PointerDecoder<VkShaderStageFlagBits>*      pStages,
    HandlePointerDecoder<VkShaderEXT>*          pShaders)
{
    GFXRECON_UNREFERENCED_PARAMETER(stageCount);
    GFXRECON_UNREFERENCED_PARAMETER(pStages);
    GFXRECON_UNREFERENCED_PARAMETER(pShaders);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetDepthClampRangeEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkDepthClampModeEXT                         depthClampMode,
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange)
{
    GFXRECON_UNREFERENCED_PARAMETER(depthClampMode);
    GFXRECON_UNREFERENCED_PARAMETER(pDepthClampRange);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdConvertCooperativeVectorMatrixNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkConvertCooperativeVectorMatrixInfoNV>* pInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(infoCount);
    GFXRECON_UNREFERENCED_PARAMETER(pInfos);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDispatchDataGraphARM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            session,
    StructPointerDecoder<Decoded_VkDataGraphPipelineDispatchInfoARM>* pInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(session);
    GFXRECON_UNREFERENCED_PARAMETER(pInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetAttachmentFeedbackLoopEnableEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkImageAspectFlags                          aspectMask)
{
    GFXRECON_UNREFERENCED_PARAMETER(aspectMask);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBindTileMemoryQCOM(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkTileMemoryBindInfoQCOM>* pTileMemoryBindInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pTileMemoryBindInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecompressMemoryEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDecompressMemoryInfoEXT>* pDecompressMemoryInfoEXT)
{
    GFXRECON_UNREFERENCED_PARAMETER(pDecompressMemoryInfoEXT);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDecompressMemoryIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkMemoryDecompressionMethodFlagsEXT         decompressionMethod,
    VkDeviceAddress                             indirectCommandsAddress,
    VkDeviceAddress                             indirectCommandsCountAddress,
    uint32_t                                    maxDecompressionCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(decompressionMethod);
    GFXRECON_UNREFERENCED_PARAMETER(indirectCommandsAddress);
    GFXRECON_UNREFERENCED_PARAMETER(indirectCommandsCountAddress);
    GFXRECON_UNREFERENCED_PARAMETER(maxDecompressionCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildPartitionedAccelerationStructuresNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBuildPartitionedAccelerationStructureInfoNV>* pBuildInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pBuildInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
    format::HandleId                            stateCommandBuffer)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdExecuteGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(isPreprocessed);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdEndRendering2EXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingEndInfoKHR>* pRenderingEndInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pRenderingEndInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBeginCustomResolveEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBeginCustomResolveInfoEXT>* pBeginCustomResolveInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pBeginCustomResolveInfo);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetComputeOccupancyPriorityNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkComputeOccupancyPriorityParametersNV>* pParameters)
{
    GFXRECON_UNREFERENCED_PARAMETER(pParameters);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(infoCount);
    GFXRECON_UNREFERENCED_PARAMETER(ppBuildRangeInfos);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    PointerDecoder<VkDeviceAddress>*            pIndirectDeviceAddresses,
    PointerDecoder<uint32_t>*                   pIndirectStrides,
    PointerDecoder<uint32_t*>*                  ppMaxPrimitiveCounts)
{
    GFXRECON_UNREFERENCED_PARAMETER(infoCount);
    GFXRECON_UNREFERENCED_PARAMETER(pIndirectDeviceAddresses);
    GFXRECON_UNREFERENCED_PARAMETER(pIndirectStrides);
    GFXRECON_UNREFERENCED_PARAMETER(ppMaxPrimitiveCounts);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    accelerationStructureCount,
    HandlePointerDecoder<VkAccelerationStructureKHR>* pAccelerationStructures,
    VkQueryType                                 queryType,
    format::HandleId                            queryPool,
    uint32_t                                    firstQuery)
{
    GFXRECON_UNREFERENCED_PARAMETER(accelerationStructureCount);
    GFXRECON_UNREFERENCED_PARAMETER(queryType);
    GFXRECON_UNREFERENCED_PARAMETER(queryPool);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysKHR(
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
    GFXRECON_UNREFERENCED_PARAMETER(pRaygenShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pMissShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pHitShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pCallableShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(depth);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdTraceRaysIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedDeviceAddressRegionKHR>* pCallableShaderBindingTable,
    VkDeviceAddress                             indirectDeviceAddress)
{
    GFXRECON_UNREFERENCED_PARAMETER(pRaygenShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pMissShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pHitShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(pCallableShaderBindingTable);
    GFXRECON_UNREFERENCED_PARAMETER(indirectDeviceAddress);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdSetRayTracingPipelineStackSizeKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    pipelineStackSize)
{
    GFXRECON_UNREFERENCED_PARAMETER(pipelineStackSize);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    GFXRECON_UNREFERENCED_PARAMETER(groupCountX);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountY);
    GFXRECON_UNREFERENCED_PARAMETER(groupCountZ);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(drawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

void VulkanReferencedBlockConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    format::HandleId                            countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(countBufferOffset);
    GFXRECON_UNREFERENCED_PARAMETER(maxDrawCount);
    GFXRECON_UNREFERENCED_PARAMETER(stride);

    if (check_handle_id_unused(commandBuffer)){ set_block_index_unused(call_info.index); }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
