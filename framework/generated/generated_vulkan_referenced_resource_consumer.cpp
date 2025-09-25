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

#include "generated/generated_vulkan_referenced_resource_consumer.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReferencedResourceConsumer::Process_vkBeginCommandBuffer(
    const ApiCallInfo&                          call_info,
    VkResult                                    returnValue,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>* pBeginInfo)
{
    assert(pBeginInfo != nullptr);

    if (!pBeginInfo->IsNull() && (pBeginInfo->HasData()))
    {
        auto pBeginInfo_ptr = pBeginInfo->GetMetaStructPointer();
        if (!pBeginInfo_ptr->pInheritanceInfo->IsNull() && (pBeginInfo_ptr->pInheritanceInfo->HasData()))
        {
            auto pInheritanceInfo_ptr = pBeginInfo_ptr->pInheritanceInfo->GetMetaStructPointer();
            GetTable().AddResourceToUser(commandBuffer, pInheritanceInfo_ptr->framebuffer);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets(
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

    assert(pDescriptorSets != nullptr);

    if (!pDescriptorSets->IsNull() && (pDescriptorSets->HasData()))
    {
        auto pDescriptorSets_ptr = pDescriptorSets->GetPointer();
        size_t pDescriptorSets_count = pDescriptorSets->GetLength();
        for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
        {
            GetTable().AddContainerToUser(commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);
    GFXRECON_UNREFERENCED_PARAMETER(indexType);

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers(
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

    assert(pBuffers != nullptr);

    if (!pBuffers->IsNull() && (pBuffers->HasData()))
    {
        auto pBuffers_ptr = pBuffers->GetPointer();
        size_t pBuffers_count = pBuffers->GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirect(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirect(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            srcBuffer,
    format::HandleId                            dstBuffer,
    uint32_t                                    regionCount,
    StructPointerDecoder<Decoded_VkBufferCopy>* pRegions)
{
    GFXRECON_UNREFERENCED_PARAMETER(regionCount);
    GFXRECON_UNREFERENCED_PARAMETER(pRegions);

    GetTable().AddResourceToUser(commandBuffer, srcBuffer);
    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage(
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

    GetTable().AddResourceToUser(commandBuffer, srcImage);
    GetTable().AddResourceToUser(commandBuffer, dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage(
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

    GetTable().AddResourceToUser(commandBuffer, srcImage);
    GetTable().AddResourceToUser(commandBuffer, dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage(
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

    GetTable().AddResourceToUser(commandBuffer, srcBuffer);
    GetTable().AddResourceToUser(commandBuffer, dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer(
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

    GetTable().AddResourceToUser(commandBuffer, srcImage);
    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdUpdateBuffer(
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

    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdFillBuffer(
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

    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdClearColorImage(
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

    GetTable().AddResourceToUser(commandBuffer, image);
}

void VulkanReferencedResourceConsumer::Process_vkCmdClearDepthStencilImage(
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

    GetTable().AddResourceToUser(commandBuffer, image);
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage(
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

    GetTable().AddResourceToUser(commandBuffer, srcImage);
    GetTable().AddResourceToUser(commandBuffer, dstImage);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents(
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

    assert(pBufferMemoryBarriers != nullptr);

    if (!pBufferMemoryBarriers->IsNull() && (pBufferMemoryBarriers->HasData()))
    {
        auto pBufferMemoryBarriers_ptr = pBufferMemoryBarriers->GetMetaStructPointer();
        size_t pBufferMemoryBarriers_count = pBufferMemoryBarriers->GetLength();
        for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
        }
    }

    assert(pImageMemoryBarriers != nullptr);

    if (!pImageMemoryBarriers->IsNull() && (pImageMemoryBarriers->HasData()))
    {
        auto pImageMemoryBarriers_ptr = pImageMemoryBarriers->GetMetaStructPointer();
        size_t pImageMemoryBarriers_count = pImageMemoryBarriers->GetLength();
        for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier(
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

    assert(pBufferMemoryBarriers != nullptr);

    if (!pBufferMemoryBarriers->IsNull() && (pBufferMemoryBarriers->HasData()))
    {
        auto pBufferMemoryBarriers_ptr = pBufferMemoryBarriers->GetMetaStructPointer();
        size_t pBufferMemoryBarriers_count = pBufferMemoryBarriers->GetLength();
        for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
        }
    }

    assert(pImageMemoryBarriers != nullptr);

    if (!pImageMemoryBarriers->IsNull() && (pImageMemoryBarriers->HasData()))
    {
        auto pImageMemoryBarriers_ptr = pImageMemoryBarriers->GetMetaStructPointer();
        size_t pImageMemoryBarriers_count = pImageMemoryBarriers->GetLength();
        for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyQueryPoolResults(
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

    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    GFXRECON_UNREFERENCED_PARAMETER(contents);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    commandBufferCount,
    HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers)
{
    GFXRECON_UNREFERENCED_PARAMETER(commandBufferCount);

    assert(pCommandBuffers != nullptr);

    if (!pCommandBuffers->IsNull() && (pCommandBuffers->HasData()))
    {
        auto pCommandBuffers_ptr = pCommandBuffers->GetPointer();
        size_t pCommandBuffers_count = pCommandBuffers->GetLength();
        for (size_t pCommandBuffers_index = 0; pCommandBuffers_index < pCommandBuffers_count; ++pCommandBuffers_index)
        {
            GetTable().AddUserToUser(commandBuffer, pCommandBuffers_ptr[pCommandBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCount(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCount(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdSetEvent2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);

    assert(pDependencyInfo != nullptr);

    if (!pDependencyInfo->IsNull() && (pDependencyInfo->HasData()))
    {
        auto pDependencyInfo_ptr = pDependencyInfo->GetMetaStructPointer();
        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(eventCount);
    GFXRECON_UNREFERENCED_PARAMETER(pEvents);

    assert(pDependencyInfos != nullptr);

    if (!pDependencyInfos->IsNull() && (pDependencyInfos->HasData()))
    {
        auto pDependencyInfos_ptr = pDependencyInfos->GetMetaStructPointer();
        size_t pDependencyInfos_count = pDependencyInfos->GetLength();
        for (size_t pDependencyInfos_index = 0; pDependencyInfos_index < pDependencyInfos_count; ++pDependencyInfos_index)
        {
            if (!pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->HasData()))
            {
                auto pBufferMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetMetaStructPointer();
                size_t pBufferMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetLength();
                for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->HasData()))
            {
                auto pImageMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetMetaStructPointer();
                size_t pImageMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetLength();
                for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    assert(pDependencyInfo != nullptr);

    if (!pDependencyInfo->IsNull() && (pDependencyInfo->HasData()))
    {
        auto pDependencyInfo_ptr = pDependencyInfo->GetMetaStructPointer();
        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    assert(pCopyBufferInfo != nullptr);

    if (!pCopyBufferInfo->IsNull() && (pCopyBufferInfo->HasData()))
    {
        auto pCopyBufferInfo_ptr = pCopyBufferInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    assert(pCopyImageInfo != nullptr);

    if (!pCopyImageInfo->IsNull() && (pCopyImageInfo->HasData()))
    {
        auto pCopyImageInfo_ptr = pCopyImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pCopyImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    assert(pCopyBufferToImageInfo != nullptr);

    if (!pCopyBufferToImageInfo->IsNull() && (pCopyBufferToImageInfo->HasData()))
    {
        auto pCopyBufferToImageInfo_ptr = pCopyBufferToImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferToImageInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferToImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    assert(pCopyImageToBufferInfo != nullptr);

    if (!pCopyImageToBufferInfo->IsNull() && (pCopyImageToBufferInfo->HasData()))
    {
        auto pCopyImageToBufferInfo_ptr = pCopyImageToBufferInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyImageToBufferInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pCopyImageToBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    assert(pBlitImageInfo != nullptr);

    if (!pBlitImageInfo->IsNull() && (pBlitImageInfo->HasData()))
    {
        auto pBlitImageInfo_ptr = pBlitImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pBlitImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pBlitImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    assert(pResolveImageInfo != nullptr);

    if (!pResolveImageInfo->IsNull() && (pResolveImageInfo->HasData()))
    {
        auto pResolveImageInfo_ptr = pResolveImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRendering(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    assert(pRenderingInfo != nullptr);

    if (!pRenderingInfo->IsNull() && (pRenderingInfo->HasData()))
    {
        auto pRenderingInfo_ptr = pRenderingInfo->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(commandBuffer, ext_struct_info->imageView);
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(commandBuffer, ext_struct_info->imageView);
            }
        }

        if (!pRenderingInfo_ptr->pColorAttachments->IsNull() && (pRenderingInfo_ptr->pColorAttachments->HasData()))
        {
            auto pColorAttachments_ptr = pRenderingInfo_ptr->pColorAttachments->GetMetaStructPointer();
            size_t pColorAttachments_count = pRenderingInfo_ptr->pColorAttachments->GetLength();
            for (size_t pColorAttachments_index = 0; pColorAttachments_index < pColorAttachments_count; ++pColorAttachments_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pColorAttachments_ptr[pColorAttachments_index].imageView);
                GetTable().AddResourceToUser(commandBuffer, pColorAttachments_ptr[pColorAttachments_index].resolveImageView);
            }
        }

        if (!pRenderingInfo_ptr->pDepthAttachment->IsNull() && (pRenderingInfo_ptr->pDepthAttachment->HasData()))
        {
            auto pDepthAttachment_ptr = pRenderingInfo_ptr->pDepthAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(commandBuffer, pDepthAttachment_ptr->imageView);
            GetTable().AddResourceToUser(commandBuffer, pDepthAttachment_ptr->resolveImageView);
        }

        if (!pRenderingInfo_ptr->pStencilAttachment->IsNull() && (pRenderingInfo_ptr->pStencilAttachment->HasData()))
        {
            auto pStencilAttachment_ptr = pRenderingInfo_ptr->pStencilAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(commandBuffer, pStencilAttachment_ptr->imageView);
            GetTable().AddResourceToUser(commandBuffer, pStencilAttachment_ptr->resolveImageView);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers2(
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

    assert(pBuffers != nullptr);

    if (!pBuffers->IsNull() && (pBuffers->HasData()))
    {
        auto pBuffers_ptr = pBuffers->GetPointer();
        size_t pBuffers_count = pBuffers->GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer2(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet(
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

    assert(pDescriptorWrites != nullptr);

    if (!pDescriptorWrites->IsNull() && (pDescriptorWrites->HasData()))
    {
        auto pDescriptorWrites_ptr = pDescriptorWrites->GetMetaStructPointer();
        size_t pDescriptorWrites_count = pDescriptorWrites->GetLength();
        for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr->pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                    {
                        auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                        size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                        {
                            GetTable().AddResourceToUser(commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                        }
                    }
                }
            }
            GetTable().AddContainerToUser(commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
            {
                auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
            {
                auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
            {
                auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    assert(pBindDescriptorSetsInfo != nullptr);

    if (!pBindDescriptorSetsInfo->IsNull() && (pBindDescriptorSetsInfo->HasData()))
    {
        auto pBindDescriptorSetsInfo_ptr = pBindDescriptorSetsInfo->GetMetaStructPointer();
        if (!pBindDescriptorSetsInfo_ptr->pDescriptorSets.IsNull() && (pBindDescriptorSetsInfo_ptr->pDescriptorSets.HasData()))
        {
            auto pDescriptorSets_ptr = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetPointer();
            size_t pDescriptorSets_count = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetLength();
            for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
            {
                GetTable().AddContainerToUser(commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    assert(pPushDescriptorSetInfo != nullptr);

    if (!pPushDescriptorSetInfo->IsNull() && (pPushDescriptorSetInfo->HasData()))
    {
        auto pPushDescriptorSetInfo_ptr = pPushDescriptorSetInfo->GetMetaStructPointer();
        if (!pPushDescriptorSetInfo_ptr->pDescriptorWrites->IsNull() && (pPushDescriptorSetInfo_ptr->pDescriptorWrites->HasData()))
        {
            auto pDescriptorWrites_ptr = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetMetaStructPointer();
            size_t pDescriptorWrites_count = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetLength();
            for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
            {
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr->pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                        {
                            auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                            size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                            for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                            {
                                GetTable().AddResourceToUser(commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                            }
                        }
                    }
                }
                GetTable().AddContainerToUser(commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
                {
                    auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                    size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                    for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
                {
                    auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                    size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                    for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
                {
                    auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                    size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                    for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                    }
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginVideoCodingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoBeginCodingInfoKHR>* pBeginInfo)
{
    assert(pBeginInfo != nullptr);

    if (!pBeginInfo->IsNull() && (pBeginInfo->HasData()))
    {
        auto pBeginInfo_ptr = pBeginInfo->GetMetaStructPointer();
        if (!pBeginInfo_ptr->pReferenceSlots->IsNull() && (pBeginInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pBeginInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pBeginInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDecodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoDecodeInfoKHR>* pDecodeInfo)
{
    assert(pDecodeInfo != nullptr);

    if (!pDecodeInfo->IsNull() && (pDecodeInfo->HasData()))
    {
        auto pDecodeInfo_ptr = pDecodeInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pDecodeInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(commandBuffer, pDecodeInfo_ptr->dstPictureResource->imageViewBinding);

        if (!pDecodeInfo_ptr->pSetupReferenceSlot->IsNull() && (pDecodeInfo_ptr->pSetupReferenceSlot->HasData()))
        {
            auto pSetupReferenceSlot_ptr = pDecodeInfo_ptr->pSetupReferenceSlot->GetMetaStructPointer();
            if (!pSetupReferenceSlot_ptr->pPictureResource->IsNull() && (pSetupReferenceSlot_ptr->pPictureResource->HasData()))
            {
                auto pPictureResource_ptr = pSetupReferenceSlot_ptr->pPictureResource->GetMetaStructPointer();
                GetTable().AddResourceToUser(commandBuffer, pPictureResource_ptr->imageViewBinding);
            }
        }

        if (!pDecodeInfo_ptr->pReferenceSlots->IsNull() && (pDecodeInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pDecodeInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pDecodeInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderingKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderingInfo>* pRenderingInfo)
{
    assert(pRenderingInfo != nullptr);

    if (!pRenderingInfo->IsNull() && (pRenderingInfo->HasData()))
    {
        auto pRenderingInfo_ptr = pRenderingInfo->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(commandBuffer, ext_struct_info->imageView);
            }
        }
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR>(pRenderingInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(commandBuffer, ext_struct_info->imageView);
            }
        }

        if (!pRenderingInfo_ptr->pColorAttachments->IsNull() && (pRenderingInfo_ptr->pColorAttachments->HasData()))
        {
            auto pColorAttachments_ptr = pRenderingInfo_ptr->pColorAttachments->GetMetaStructPointer();
            size_t pColorAttachments_count = pRenderingInfo_ptr->pColorAttachments->GetLength();
            for (size_t pColorAttachments_index = 0; pColorAttachments_index < pColorAttachments_count; ++pColorAttachments_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pColorAttachments_ptr[pColorAttachments_index].imageView);
                GetTable().AddResourceToUser(commandBuffer, pColorAttachments_ptr[pColorAttachments_index].resolveImageView);
            }
        }

        if (!pRenderingInfo_ptr->pDepthAttachment->IsNull() && (pRenderingInfo_ptr->pDepthAttachment->HasData()))
        {
            auto pDepthAttachment_ptr = pRenderingInfo_ptr->pDepthAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(commandBuffer, pDepthAttachment_ptr->imageView);
            GetTable().AddResourceToUser(commandBuffer, pDepthAttachment_ptr->resolveImageView);
        }

        if (!pRenderingInfo_ptr->pStencilAttachment->IsNull() && (pRenderingInfo_ptr->pStencilAttachment->HasData()))
        {
            auto pStencilAttachment_ptr = pRenderingInfo_ptr->pStencilAttachment->GetMetaStructPointer();
            GetTable().AddResourceToUser(commandBuffer, pStencilAttachment_ptr->imageView);
            GetTable().AddResourceToUser(commandBuffer, pStencilAttachment_ptr->resolveImageView);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSetKHR(
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

    assert(pDescriptorWrites != nullptr);

    if (!pDescriptorWrites->IsNull() && (pDescriptorWrites->HasData()))
    {
        auto pDescriptorWrites_ptr = pDescriptorWrites->GetMetaStructPointer();
        size_t pDescriptorWrites_count = pDescriptorWrites->GetLength();
        for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
        {
            {
                const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr->pNext);
                if (ext_struct_info != nullptr)
                {
                    if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                    {
                        auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                        size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                        {
                            GetTable().AddResourceToUser(commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                        }
                    }
                }
            }
            GetTable().AddContainerToUser(commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
            {
                auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
            {
                auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                }
            }

            if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
            {
                auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginRenderPass2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkRenderPassAttachmentBeginInfo>(pRenderPassBegin_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                if (!ext_struct_info->pAttachments.IsNull() && (ext_struct_info->pAttachments.HasData()))
                {
                    auto pAttachments_ptr = ext_struct_info->pAttachments.GetPointer();
                    size_t pAttachments_count = ext_struct_info->pAttachments.GetLength();
                    for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                    }
                }
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCountKHR(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCountKHR(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdEncodeVideoKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkVideoEncodeInfoKHR>* pEncodeInfo)
{
    assert(pEncodeInfo != nullptr);

    if (!pEncodeInfo->IsNull() && (pEncodeInfo->HasData()))
    {
        auto pEncodeInfo_ptr = pEncodeInfo->GetMetaStructPointer();
        {
            const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkVideoEncodeQuantizationMapInfoKHR>(pEncodeInfo_ptr->pNext);
            if (ext_struct_info != nullptr)
            {
                GetTable().AddResourceToUser(commandBuffer, ext_struct_info->quantizationMap);
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pEncodeInfo_ptr->dstBuffer);
        GetTable().AddResourceToUser(commandBuffer, pEncodeInfo_ptr->srcPictureResource->imageViewBinding);

        if (!pEncodeInfo_ptr->pSetupReferenceSlot->IsNull() && (pEncodeInfo_ptr->pSetupReferenceSlot->HasData()))
        {
            auto pSetupReferenceSlot_ptr = pEncodeInfo_ptr->pSetupReferenceSlot->GetMetaStructPointer();
            if (!pSetupReferenceSlot_ptr->pPictureResource->IsNull() && (pSetupReferenceSlot_ptr->pPictureResource->HasData()))
            {
                auto pPictureResource_ptr = pSetupReferenceSlot_ptr->pPictureResource->GetMetaStructPointer();
                GetTable().AddResourceToUser(commandBuffer, pPictureResource_ptr->imageViewBinding);
            }
        }

        if (!pEncodeInfo_ptr->pReferenceSlots->IsNull() && (pEncodeInfo_ptr->pReferenceSlots->HasData()))
        {
            auto pReferenceSlots_ptr = pEncodeInfo_ptr->pReferenceSlots->GetMetaStructPointer();
            size_t pReferenceSlots_count = pEncodeInfo_ptr->pReferenceSlots->GetLength();
            for (size_t pReferenceSlots_index = 0; pReferenceSlots_index < pReferenceSlots_count; ++pReferenceSlots_index)
            {
                if (!pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->IsNull() && (pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->HasData()))
                {
                    auto pPictureResource_ptr = pReferenceSlots_ptr[pReferenceSlots_index].pPictureResource->GetMetaStructPointer();
                    GetTable().AddResourceToUser(commandBuffer, pPictureResource_ptr->imageViewBinding);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdSetEvent2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            event,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(event);

    assert(pDependencyInfo != nullptr);

    if (!pDependencyInfo->IsNull() && (pDependencyInfo->HasData()))
    {
        auto pDependencyInfo_ptr = pDependencyInfo->GetMetaStructPointer();
        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWaitEvents2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    eventCount,
    HandlePointerDecoder<VkEvent>*              pEvents,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(eventCount);
    GFXRECON_UNREFERENCED_PARAMETER(pEvents);

    assert(pDependencyInfos != nullptr);

    if (!pDependencyInfos->IsNull() && (pDependencyInfos->HasData()))
    {
        auto pDependencyInfos_ptr = pDependencyInfos->GetMetaStructPointer();
        size_t pDependencyInfos_count = pDependencyInfos->GetLength();
        for (size_t pDependencyInfos_index = 0; pDependencyInfos_index < pDependencyInfos_count; ++pDependencyInfos_index)
        {
            if (!pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->HasData()))
            {
                auto pBufferMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetMetaStructPointer();
                size_t pBufferMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pBufferMemoryBarriers->GetLength();
                for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
                }
            }

            if (!pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->IsNull() && (pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->HasData()))
            {
                auto pImageMemoryBarriers_ptr = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetMetaStructPointer();
                size_t pImageMemoryBarriers_count = pDependencyInfos_ptr[pDependencyInfos_index].pImageMemoryBarriers->GetLength();
                for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
                {
                    GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPipelineBarrier2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkDependencyInfo>* pDependencyInfo)
{
    assert(pDependencyInfo != nullptr);

    if (!pDependencyInfo->IsNull() && (pDependencyInfo->HasData()))
    {
        auto pDependencyInfo_ptr = pDependencyInfo->GetMetaStructPointer();
        if (!pDependencyInfo_ptr->pBufferMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pBufferMemoryBarriers->HasData()))
        {
            auto pBufferMemoryBarriers_ptr = pDependencyInfo_ptr->pBufferMemoryBarriers->GetMetaStructPointer();
            size_t pBufferMemoryBarriers_count = pDependencyInfo_ptr->pBufferMemoryBarriers->GetLength();
            for (size_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pBufferMemoryBarriers_count; ++pBufferMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pBufferMemoryBarriers_ptr[pBufferMemoryBarriers_index].buffer);
            }
        }

        if (!pDependencyInfo_ptr->pImageMemoryBarriers->IsNull() && (pDependencyInfo_ptr->pImageMemoryBarriers->HasData()))
        {
            auto pImageMemoryBarriers_ptr = pDependencyInfo_ptr->pImageMemoryBarriers->GetMetaStructPointer();
            size_t pImageMemoryBarriers_count = pDependencyInfo_ptr->pImageMemoryBarriers->GetLength();
            for (size_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pImageMemoryBarriers_count; ++pImageMemoryBarriers_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pImageMemoryBarriers_ptr[pImageMemoryBarriers_index].image);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo)
{
    assert(pCopyBufferInfo != nullptr);

    if (!pCopyBufferInfo->IsNull() && (pCopyBufferInfo->HasData()))
    {
        auto pCopyBufferInfo_ptr = pCopyBufferInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo)
{
    assert(pCopyImageInfo != nullptr);

    if (!pCopyImageInfo->IsNull() && (pCopyImageInfo->HasData()))
    {
        auto pCopyImageInfo_ptr = pCopyImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pCopyImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBufferToImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo)
{
    assert(pCopyBufferToImageInfo != nullptr);

    if (!pCopyBufferToImageInfo->IsNull() && (pCopyBufferToImageInfo->HasData()))
    {
        auto pCopyBufferToImageInfo_ptr = pCopyBufferToImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferToImageInfo_ptr->srcBuffer);
        GetTable().AddResourceToUser(commandBuffer, pCopyBufferToImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyImageToBuffer2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo)
{
    assert(pCopyImageToBufferInfo != nullptr);

    if (!pCopyImageToBufferInfo->IsNull() && (pCopyImageToBufferInfo->HasData()))
    {
        auto pCopyImageToBufferInfo_ptr = pCopyImageToBufferInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyImageToBufferInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pCopyImageToBufferInfo_ptr->dstBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBlitImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo)
{
    assert(pBlitImageInfo != nullptr);

    if (!pBlitImageInfo->IsNull() && (pBlitImageInfo->HasData()))
    {
        auto pBlitImageInfo_ptr = pBlitImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pBlitImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pBlitImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdResolveImage2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2>* pResolveImageInfo)
{
    assert(pResolveImageInfo != nullptr);

    if (!pResolveImageInfo->IsNull() && (pResolveImageInfo->HasData()))
    {
        auto pResolveImageInfo_ptr = pResolveImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindIndexBuffer2KHR(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindDescriptorSets2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBindDescriptorSetsInfo>* pBindDescriptorSetsInfo)
{
    assert(pBindDescriptorSetsInfo != nullptr);

    if (!pBindDescriptorSetsInfo->IsNull() && (pBindDescriptorSetsInfo->HasData()))
    {
        auto pBindDescriptorSetsInfo_ptr = pBindDescriptorSetsInfo->GetMetaStructPointer();
        if (!pBindDescriptorSetsInfo_ptr->pDescriptorSets.IsNull() && (pBindDescriptorSetsInfo_ptr->pDescriptorSets.HasData()))
        {
            auto pDescriptorSets_ptr = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetPointer();
            size_t pDescriptorSets_count = pBindDescriptorSetsInfo_ptr->pDescriptorSets.GetLength();
            for (size_t pDescriptorSets_index = 0; pDescriptorSets_index < pDescriptorSets_count; ++pDescriptorSets_index)
            {
                GetTable().AddContainerToUser(commandBuffer, pDescriptorSets_ptr[pDescriptorSets_index]);
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSet2KHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkPushDescriptorSetInfo>* pPushDescriptorSetInfo)
{
    assert(pPushDescriptorSetInfo != nullptr);

    if (!pPushDescriptorSetInfo->IsNull() && (pPushDescriptorSetInfo->HasData()))
    {
        auto pPushDescriptorSetInfo_ptr = pPushDescriptorSetInfo->GetMetaStructPointer();
        if (!pPushDescriptorSetInfo_ptr->pDescriptorWrites->IsNull() && (pPushDescriptorSetInfo_ptr->pDescriptorWrites->HasData()))
        {
            auto pDescriptorWrites_ptr = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetMetaStructPointer();
            size_t pDescriptorWrites_count = pPushDescriptorSetInfo_ptr->pDescriptorWrites->GetLength();
            for (size_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pDescriptorWrites_count; ++pDescriptorWrites_index)
            {
                {
                    const auto* ext_struct_info = GetPNextMetaStruct<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>(pDescriptorWrites_ptr->pNext);
                    if (ext_struct_info != nullptr)
                    {
                        if (!ext_struct_info->pAccelerationStructures.IsNull() && (ext_struct_info->pAccelerationStructures.HasData()))
                        {
                            auto pAccelerationStructures_ptr = ext_struct_info->pAccelerationStructures.GetPointer();
                            size_t pAccelerationStructures_count = ext_struct_info->pAccelerationStructures.GetLength();
                            for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
                            {
                                GetTable().AddResourceToUser(commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
                            }
                        }
                    }
                }
                GetTable().AddContainerToUser(commandBuffer, pDescriptorWrites_ptr[pDescriptorWrites_index].dstSet);

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->HasData()))
                {
                    auto pImageInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetMetaStructPointer();
                    size_t pImageInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pImageInfo->GetLength();
                    for (size_t pImageInfo_index = 0; pImageInfo_index < pImageInfo_count; ++pImageInfo_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pImageInfo_ptr[pImageInfo_index].imageView);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->HasData()))
                {
                    auto pBufferInfo_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetMetaStructPointer();
                    size_t pBufferInfo_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pBufferInfo->GetLength();
                    for (size_t pBufferInfo_index = 0; pBufferInfo_index < pBufferInfo_count; ++pBufferInfo_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pBufferInfo_ptr[pBufferInfo_index].buffer);
                    }
                }

                if (!pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.IsNull() && (pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.HasData()))
                {
                    auto pTexelBufferView_ptr = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetPointer();
                    size_t pTexelBufferView_count = pDescriptorWrites_ptr[pDescriptorWrites_index].pTexelBufferView.GetLength();
                    for (size_t pTexelBufferView_index = 0; pTexelBufferView_index < pTexelBufferView_count; ++pTexelBufferView_index)
                    {
                        GetTable().AddResourceToUser(commandBuffer, pTexelBufferView_ptr[pTexelBufferView_index]);
                    }
                }
            }
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToImageIndirectKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToImageIndirectInfoKHR>* pCopyMemoryToImageIndirectInfo)
{
    assert(pCopyMemoryToImageIndirectInfo != nullptr);

    if (!pCopyMemoryToImageIndirectInfo->IsNull() && (pCopyMemoryToImageIndirectInfo->HasData()))
    {
        auto pCopyMemoryToImageIndirectInfo_ptr = pCopyMemoryToImageIndirectInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCopyMemoryToImageIndirectInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
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

    assert(pBuffers != nullptr);

    if (!pBuffers->IsNull() && (pBuffers->HasData()))
    {
        auto pBuffers_ptr = pBuffers->GetPointer();
        size_t pBuffers_count = pBuffers->GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginTransformFeedbackEXT(
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

    assert(pCounterBuffers != nullptr);

    if (!pCounterBuffers->IsNull() && (pCounterBuffers->HasData()))
    {
        auto pCounterBuffers_ptr = pCounterBuffers->GetPointer();
        size_t pCounterBuffers_count = pCounterBuffers->GetLength();
        for (size_t pCounterBuffers_index = 0; pCounterBuffers_index < pCounterBuffers_count; ++pCounterBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pCounterBuffers_ptr[pCounterBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdEndTransformFeedbackEXT(
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

    assert(pCounterBuffers != nullptr);

    if (!pCounterBuffers->IsNull() && (pCounterBuffers->HasData()))
    {
        auto pCounterBuffers_ptr = pCounterBuffers->GetPointer();
        size_t pCounterBuffers_count = pCounterBuffers->GetLength();
        for (size_t pCounterBuffers_index = 0; pCounterBuffers_index < pCounterBuffers_count; ++pCounterBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pCounterBuffers_ptr[pCounterBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectByteCountEXT(
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

    GetTable().AddResourceToUser(commandBuffer, counterBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCountAMD(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndexedIndirectCountAMD(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBeginConditionalRenderingEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>* pConditionalRenderingBegin)
{
    assert(pConditionalRenderingBegin != nullptr);

    if (!pConditionalRenderingBegin->IsNull() && (pConditionalRenderingBegin->HasData()))
    {
        auto pConditionalRenderingBegin_ptr = pConditionalRenderingBegin->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pConditionalRenderingBegin_ptr->buffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindShadingRateImageNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);

    GetTable().AddResourceToUser(commandBuffer, imageView);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructureNV(
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

    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
        if (!pInfo_ptr->pGeometries->IsNull() && (pInfo_ptr->pGeometries->HasData()))
        {
            auto pGeometries_ptr = pInfo_ptr->pGeometries->GetMetaStructPointer();
            size_t pGeometries_count = pInfo_ptr->pGeometries->GetLength();
            for (size_t pGeometries_index = 0; pGeometries_index < pGeometries_count; ++pGeometries_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->vertexData);
                GetTable().AddResourceToUser(commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->indexData);
                GetTable().AddResourceToUser(commandBuffer, pGeometries_ptr[pGeometries_index].geometry->triangles->transformData);
                GetTable().AddResourceToUser(commandBuffer, pGeometries_ptr[pGeometries_index].geometry->aabbs->aabbData);
            }
        }
    }
    GetTable().AddResourceToUser(commandBuffer, instanceData);
    GetTable().AddResourceToUser(commandBuffer, scratch);
}

void VulkanReferencedResourceConsumer::Process_vkCmdTraceRaysNV(
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

    GetTable().AddResourceToUser(commandBuffer, raygenShaderBindingTableBuffer);
    GetTable().AddResourceToUser(commandBuffer, missShaderBindingTableBuffer);
    GetTable().AddResourceToUser(commandBuffer, hitShaderBindingTableBuffer);
    GetTable().AddResourceToUser(commandBuffer, callableShaderBindingTableBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteBufferMarkerAMD(
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

    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteBufferMarker2AMD(
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

    GetTable().AddResourceToUser(commandBuffer, dstBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectCountNV(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindVertexBuffers2EXT(
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

    assert(pBuffers != nullptr);

    if (!pBuffers->IsNull() && (pBuffers->HasData()))
    {
        auto pBuffers_ptr = pBuffers->GetPointer();
        size_t pBuffers_count = pBuffers->GetLength();
        for (size_t pBuffers_index = 0; pBuffers_index < pBuffers_count; ++pBuffers_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pBuffers_ptr[pBuffers_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPreprocessGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    assert(pGeneratedCommandsInfo != nullptr);

    if (!pGeneratedCommandsInfo->IsNull() && (pGeneratedCommandsInfo->HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = pGeneratedCommandsInfo->GetMetaStructPointer();
        if (!pGeneratedCommandsInfo_ptr->pStreams->IsNull() && (pGeneratedCommandsInfo_ptr->pStreams->HasData()))
        {
            auto pStreams_ptr = pGeneratedCommandsInfo_ptr->pStreams->GetMetaStructPointer();
            size_t pStreams_count = pGeneratedCommandsInfo_ptr->pStreams->GetLength();
            for (size_t pStreams_index = 0; pStreams_index < pStreams_count; ++pStreams_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pStreams_ptr[pStreams_index].buffer);
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->preprocessBuffer);
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->sequencesCountBuffer);
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->sequencesIndexBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteGeneratedCommandsNV(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    VkBool32                                    isPreprocessed,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoNV>* pGeneratedCommandsInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(isPreprocessed);

    assert(pGeneratedCommandsInfo != nullptr);

    if (!pGeneratedCommandsInfo->IsNull() && (pGeneratedCommandsInfo->HasData()))
    {
        auto pGeneratedCommandsInfo_ptr = pGeneratedCommandsInfo->GetMetaStructPointer();
        if (!pGeneratedCommandsInfo_ptr->pStreams->IsNull() && (pGeneratedCommandsInfo_ptr->pStreams->HasData()))
        {
            auto pStreams_ptr = pGeneratedCommandsInfo_ptr->pStreams->GetMetaStructPointer();
            size_t pStreams_count = pGeneratedCommandsInfo_ptr->pStreams->GetLength();
            for (size_t pStreams_index = 0; pStreams_index < pStreams_count; ++pStreams_index)
            {
                GetTable().AddResourceToUser(commandBuffer, pStreams_ptr[pStreams_index].buffer);
            }
        }
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->preprocessBuffer);
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->sequencesCountBuffer);
        GetTable().AddResourceToUser(commandBuffer, pGeneratedCommandsInfo_ptr->sequencesIndexBuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindInvocationMaskHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);

    GetTable().AddResourceToUser(commandBuffer, imageView);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawClusterIndirectHUAWEI(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdPreprocessGeneratedCommandsEXT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkGeneratedCommandsInfoEXT>* pGeneratedCommandsInfo,
    format::HandleId                            stateCommandBuffer)
{
    GFXRECON_UNREFERENCED_PARAMETER(pGeneratedCommandsInfo);

    GetTable().AddUserToUser(commandBuffer, stateCommandBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructuresKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    uint32_t                                    infoCount,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>* ppBuildRangeInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(infoCount);
    GFXRECON_UNREFERENCED_PARAMETER(ppBuildRangeInfos);

    assert(pInfos != nullptr);

    if (!pInfos->IsNull() && (pInfos->HasData()))
    {
        auto pInfos_ptr = pInfos->GetMetaStructPointer();
        size_t pInfos_count = pInfos->GetLength();
        for (size_t pInfos_index = 0; pInfos_index < pInfos_count; ++pInfos_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pInfos_ptr[pInfos_index].srcAccelerationStructure);
            GetTable().AddResourceToUser(commandBuffer, pInfos_ptr[pInfos_index].dstAccelerationStructure);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructuresIndirectKHR(
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

    assert(pInfos != nullptr);

    if (!pInfos->IsNull() && (pInfos->HasData()))
    {
        auto pInfos_ptr = pInfos->GetMetaStructPointer();
        size_t pInfos_count = pInfos->GetLength();
        for (size_t pInfos_index = 0; pInfos_index < pInfos_count; ++pInfos_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pInfos_ptr[pInfos_index].srcAccelerationStructure);
            GetTable().AddResourceToUser(commandBuffer, pInfos_ptr[pInfos_index].dstAccelerationStructure);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pInfo_ptr->src);
        GetTable().AddResourceToUser(commandBuffer, pInfo_ptr->dst);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pInfo_ptr->src);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    const ApiCallInfo&                          call_info,
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pInfo_ptr->dst);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdWriteAccelerationStructuresPropertiesKHR(
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

    assert(pAccelerationStructures != nullptr);

    if (!pAccelerationStructures->IsNull() && (pAccelerationStructures->HasData()))
    {
        auto pAccelerationStructures_ptr = pAccelerationStructures->GetPointer();
        size_t pAccelerationStructures_count = pAccelerationStructures->GetLength();
        for (size_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pAccelerationStructures_count; ++pAccelerationStructures_index)
        {
            GetTable().AddResourceToUser(commandBuffer, pAccelerationStructures_ptr[pAccelerationStructures_index]);
        }
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectEXT(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectCountEXT(
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

    GetTable().AddResourceToUser(commandBuffer, buffer);
    GetTable().AddResourceToUser(commandBuffer, countBuffer);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
