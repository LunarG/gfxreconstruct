/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
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
    format::HandleId                            commandBuffer,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    GetTable().AddResourceToUser(commandBuffer, buffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer(
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    VkSubpassContents                           contents)
{
    GFXRECON_UNREFERENCED_PARAMETER(contents);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        const VkBaseInStructure* pnext_header = nullptr;
        if (pRenderPassBegin_ptr->pNext != nullptr)
        {
            pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin_ptr->pNext->GetPointer());
        }
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const Decoded_VkRenderPassAttachmentBeginInfo*>(pRenderPassBegin_ptr->pNext->GetPointer());
                    if (!pnext_value->pAttachments.IsNull() && (pnext_value->pAttachments.HasData()))
                    {
                        auto pAttachments_ptr = pnext_value->pAttachments.GetPointer();
                        size_t pAttachments_count = pnext_value->pAttachments.GetLength();
                        for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                        {
                            GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdExecuteCommands(
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        const VkBaseInStructure* pnext_header = nullptr;
        if (pRenderPassBegin_ptr->pNext != nullptr)
        {
            pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin_ptr->pNext->GetPointer());
        }
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const Decoded_VkRenderPassAttachmentBeginInfo*>(pRenderPassBegin_ptr->pNext->GetPointer());
                    if (!pnext_value->pAttachments.IsNull() && (pnext_value->pAttachments.HasData()))
                    {
                        auto pAttachments_ptr = pnext_value->pAttachments.GetPointer();
                        size_t pAttachments_count = pnext_value->pAttachments.GetLength();
                        for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                        {
                            GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdPushDescriptorSetKHR(
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkRenderPassBeginInfo>* pRenderPassBegin,
    StructPointerDecoder<Decoded_VkSubpassBeginInfo>* pSubpassBeginInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(pSubpassBeginInfo);

    assert(pRenderPassBegin != nullptr);

    if (!pRenderPassBegin->IsNull() && (pRenderPassBegin->HasData()))
    {
        auto pRenderPassBegin_ptr = pRenderPassBegin->GetMetaStructPointer();
        const VkBaseInStructure* pnext_header = nullptr;
        if (pRenderPassBegin_ptr->pNext != nullptr)
        {
            pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin_ptr->pNext->GetPointer());
        }
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const Decoded_VkRenderPassAttachmentBeginInfo*>(pRenderPassBegin_ptr->pNext->GetPointer());
                    if (!pnext_value->pAttachments.IsNull() && (pnext_value->pAttachments.HasData()))
                    {
                        auto pAttachments_ptr = pnext_value->pAttachments.GetPointer();
                        size_t pAttachments_count = pnext_value->pAttachments.GetLength();
                        for (size_t pAttachments_index = 0; pAttachments_index < pAttachments_count; ++pAttachments_index)
                        {
                            GetTable().AddResourceToUser(commandBuffer, pAttachments_ptr[pAttachments_index]);
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        GetTable().AddResourceToUser(commandBuffer, pRenderPassBegin_ptr->framebuffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdDrawIndirectCountKHR(
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

void VulkanReferencedResourceConsumer::Process_vkCmdCopyBuffer2KHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferInfo2KHR>* pCopyBufferInfo)
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageInfo2KHR>* pCopyImageInfo)
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2KHR>* pCopyBufferToImageInfo)
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2KHR>* pCopyImageToBufferInfo)
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkBlitImageInfo2KHR>* pBlitImageInfo)
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
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkResolveImageInfo2KHR>* pResolveImageInfo)
{
    assert(pResolveImageInfo != nullptr);

    if (!pResolveImageInfo->IsNull() && (pResolveImageInfo->HasData()))
    {
        auto pResolveImageInfo_ptr = pResolveImageInfo->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->srcImage);
        GetTable().AddResourceToUser(commandBuffer, pResolveImageInfo_ptr->dstImage);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdBindTransformFeedbackBuffersEXT(
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
    format::HandleId                            commandBuffer,
    format::HandleId                            imageView,
    VkImageLayout                               imageLayout)
{
    GFXRECON_UNREFERENCED_PARAMETER(imageLayout);

    GetTable().AddResourceToUser(commandBuffer, imageView);
}

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructureNV(
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

void VulkanReferencedResourceConsumer::Process_vkCmdDrawMeshTasksIndirectNV(
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

void VulkanReferencedResourceConsumer::Process_vkCmdBuildAccelerationStructureIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfo,
    format::HandleId                            indirectBuffer,
    VkDeviceSize                                indirectOffset,
    uint32_t                                    indirectStride)
{
    GFXRECON_UNREFERENCED_PARAMETER(indirectOffset);
    GFXRECON_UNREFERENCED_PARAMETER(indirectStride);

    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
    }
    GetTable().AddResourceToUser(commandBuffer, indirectBuffer);
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyAccelerationStructureToMemoryKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyAccelerationStructureToMemoryInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdCopyMemoryToAccelerationStructureKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkCopyMemoryToAccelerationStructureInfoKHR>* pInfo)
{
    assert(pInfo != nullptr);

    if (!pInfo->IsNull() && (pInfo->HasData()))
    {
        auto pInfo_ptr = pInfo->GetMetaStructPointer();
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdTraceRaysKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    uint32_t                                    width,
    uint32_t                                    height,
    uint32_t                                    depth)
{
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);
    GFXRECON_UNREFERENCED_PARAMETER(depth);

    assert(pRaygenShaderBindingTable != nullptr);

    if (!pRaygenShaderBindingTable->IsNull() && (pRaygenShaderBindingTable->HasData()))
    {
        auto pRaygenShaderBindingTable_ptr = pRaygenShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pRaygenShaderBindingTable_ptr->buffer);
    }

    assert(pMissShaderBindingTable != nullptr);

    if (!pMissShaderBindingTable->IsNull() && (pMissShaderBindingTable->HasData()))
    {
        auto pMissShaderBindingTable_ptr = pMissShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pMissShaderBindingTable_ptr->buffer);
    }

    assert(pHitShaderBindingTable != nullptr);

    if (!pHitShaderBindingTable->IsNull() && (pHitShaderBindingTable->HasData()))
    {
        auto pHitShaderBindingTable_ptr = pHitShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pHitShaderBindingTable_ptr->buffer);
    }

    assert(pCallableShaderBindingTable != nullptr);

    if (!pCallableShaderBindingTable->IsNull() && (pCallableShaderBindingTable->HasData()))
    {
        auto pCallableShaderBindingTable_ptr = pCallableShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCallableShaderBindingTable_ptr->buffer);
    }
}

void VulkanReferencedResourceConsumer::Process_vkCmdTraceRaysIndirectKHR(
    format::HandleId                            commandBuffer,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pRaygenShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pMissShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pHitShaderBindingTable,
    StructPointerDecoder<Decoded_VkStridedBufferRegionKHR>* pCallableShaderBindingTable,
    format::HandleId                            buffer,
    VkDeviceSize                                offset)
{
    GFXRECON_UNREFERENCED_PARAMETER(offset);

    assert(pRaygenShaderBindingTable != nullptr);

    if (!pRaygenShaderBindingTable->IsNull() && (pRaygenShaderBindingTable->HasData()))
    {
        auto pRaygenShaderBindingTable_ptr = pRaygenShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pRaygenShaderBindingTable_ptr->buffer);
    }

    assert(pMissShaderBindingTable != nullptr);

    if (!pMissShaderBindingTable->IsNull() && (pMissShaderBindingTable->HasData()))
    {
        auto pMissShaderBindingTable_ptr = pMissShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pMissShaderBindingTable_ptr->buffer);
    }

    assert(pHitShaderBindingTable != nullptr);

    if (!pHitShaderBindingTable->IsNull() && (pHitShaderBindingTable->HasData()))
    {
        auto pHitShaderBindingTable_ptr = pHitShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pHitShaderBindingTable_ptr->buffer);
    }

    assert(pCallableShaderBindingTable != nullptr);

    if (!pCallableShaderBindingTable->IsNull() && (pCallableShaderBindingTable->HasData()))
    {
        auto pCallableShaderBindingTable_ptr = pCallableShaderBindingTable->GetMetaStructPointer();
        GetTable().AddResourceToUser(commandBuffer, pCallableShaderBindingTable_ptr->buffer);
    }
    GetTable().AddResourceToUser(commandBuffer, buffer);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
