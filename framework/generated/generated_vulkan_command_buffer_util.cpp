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

#include "generated/generated_vulkan_command_buffer_util.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void TrackBeginCommandBufferHandles(VulkanCommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if (pBeginInfo->pInheritanceInfo != nullptr)
        {
            if(pBeginInfo->pInheritanceInfo->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<VulkanRenderPassWrapper>(pBeginInfo->pInheritanceInfo->renderPass));
            if(pBeginInfo->pInheritanceInfo->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<VulkanFramebufferWrapper>(pBeginInfo->pInheritanceInfo->framebuffer));
        }
    }
}

void TrackCmdBindPipelineHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<VulkanPipelineWrapper>(pipeline));
}

void TrackCmdBindDescriptorSetsHandles(VulkanCommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(layout));

    if (pDescriptorSets != nullptr)
    {
        for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < descriptorSetCount; ++pDescriptorSets_index)
        {
            if(pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId<VulkanDescriptorSetWrapper>(pDescriptorSets[pDescriptorSets_index]));
        }
    }
}

void TrackCmdBindIndexBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdBindVertexBuffersHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdDrawIndexedIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdDispatchIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdCopyBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(srcBuffer));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdCopyImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(dstImage));
}

void TrackCmdBlitImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(dstImage));
}

void TrackCmdCopyBufferToImageHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(srcBuffer));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(dstImage));
}

void TrackCmdCopyImageToBufferHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(srcImage));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdUpdateBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdFillBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdClearColorImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(image));
}

void TrackCmdClearDepthStencilImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(image));
}

void TrackCmdResolveImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(dstImage));
}

void TrackCmdSetEventHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));
}

void TrackCmdResetEventHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));
}

void TrackCmdWaitEventsHandles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(pEvents[pEvents_index]));
        }
    }

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdPipelineBarrierHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdBeginQueryHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdResetQueryPoolHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdWriteTimestampHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdCopyQueryPoolResultsHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdPushConstantsHandles(VulkanCommandBufferWrapper* wrapper, VkPipelineLayout layout)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(layout));
}

void TrackCmdBeginRenderPassHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
{
    assert(wrapper != nullptr);

    if (pRenderPassBegin != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(pnext_header);
                    if (pnext_value->pAttachments != nullptr)
                    {
                        for (uint32_t pAttachments_index = 0; pAttachments_index < pnext_value->attachmentCount; ++pAttachments_index)
                        {
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<VulkanRenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<VulkanFramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdExecuteCommandsHandles(VulkanCommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(wrapper != nullptr);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t pCommandBuffers_index = 0; pCommandBuffers_index < commandBufferCount; ++pCommandBuffers_index)
        {
            if(pCommandBuffers[pCommandBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::CommandBufferHandle].insert(GetWrappedId<VulkanCommandBufferWrapper>(pCommandBuffers[pCommandBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectCountHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdBeginRenderPass2Handles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
{
    assert(wrapper != nullptr);

    if (pRenderPassBegin != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(pnext_header);
                    if (pnext_value->pAttachments != nullptr)
                    {
                        for (uint32_t pAttachments_index = 0; pAttachments_index < pnext_value->attachmentCount; ++pAttachments_index)
                        {
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<VulkanRenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<VulkanFramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdSetEvent2Handles(VulkanCommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2Handles(VulkanCommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));
}

void TrackCmdWaitEvents2Handles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(pEvents[pEvents_index]));
        }
    }

    if (pDependencyInfos != nullptr)
    {
        for (uint32_t pDependencyInfos_index = 0; pDependencyInfos_index < eventCount; ++pDependencyInfos_index)
        {
            if (pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers != nullptr)
            {
                for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2Handles(VulkanCommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2Handles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdCopyBuffer2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBeginRenderingHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
{
    assert(wrapper != nullptr);

    if (pRenderingInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderingInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBindVertexBuffers2Handles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginVideoCodingKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if(pBeginInfo->videoSession != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::VideoSessionKHRHandle].insert(GetWrappedId<VulkanVideoSessionKHRWrapper>(pBeginInfo->videoSession));
        if(pBeginInfo->videoSessionParameters != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::VideoSessionParametersKHRHandle].insert(GetWrappedId<VulkanVideoSessionParametersKHRWrapper>(pBeginInfo->videoSessionParameters));

        if (pBeginInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pBeginInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdDecodeVideoKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo)
{
    assert(wrapper != nullptr);

    if (pDecodeInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pDecodeInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(pnext_header);
                    if(pnext_value->queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(pnext_value->queryPool));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pDecodeInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDecodeInfo->srcBuffer));
        if(pDecodeInfo->dstPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pDecodeInfo->dstPictureResource.imageViewBinding));

        if (pDecodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pDecodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pDecodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdBeginRenderingKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
{
    assert(wrapper != nullptr);

    if (pRenderingInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderingInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBeginRenderPass2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
{
    assert(wrapper != nullptr);

    if (pRenderPassBegin != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pRenderPassBegin->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(pnext_header);
                    if (pnext_value->pAttachments != nullptr)
                    {
                        for (uint32_t pAttachments_index = 0; pAttachments_index < pnext_value->attachmentCount; ++pAttachments_index)
                        {
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<VulkanRenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<VulkanFramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdDrawIndirectCountKHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountKHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdEncodeVideoKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo)
{
    assert(wrapper != nullptr);

    if (pEncodeInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pEncodeInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(pnext_header);
                    if(pnext_value->queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(pnext_value->queryPool));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pEncodeInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pEncodeInfo->dstBuffer));
        if(pEncodeInfo->srcPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pEncodeInfo->srcPictureResource.imageViewBinding));

        if (pEncodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pEncodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pEncodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdSetEvent2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(event));
}

void TrackCmdWaitEvents2KHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<VulkanEventWrapper>(pEvents[pEvents_index]));
        }
    }

    if (pDependencyInfos != nullptr)
    {
        for (uint32_t pDependencyInfos_index = 0; pDependencyInfos_index < eventCount; ++pDependencyInfos_index)
        {
            if (pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers != nullptr)
            {
                for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarker2AMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdCopyBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<VulkanImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBindIndexBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdBindDescriptorSets2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    assert(wrapper != nullptr);

    if (pBindDescriptorSetsInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pBindDescriptorSetsInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pBindDescriptorSetsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pBindDescriptorSetsInfo->layout));

        if (pBindDescriptorSetsInfo->pDescriptorSets != nullptr)
        {
            for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < pBindDescriptorSetsInfo->descriptorSetCount; ++pDescriptorSets_index)
            {
                if(pBindDescriptorSetsInfo->pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId<VulkanDescriptorSetWrapper>(pBindDescriptorSetsInfo->pDescriptorSets[pDescriptorSets_index]));
            }
        }
    }
}

void TrackCmdPushConstants2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushConstantsInfoKHR* pPushConstantsInfo)
{
    assert(wrapper != nullptr);

    if (pPushConstantsInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pPushConstantsInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushConstantsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pPushConstantsInfo->layout));
    }
}

void TrackCmdPushDescriptorSet2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo)
{
    assert(wrapper != nullptr);

    if (pPushDescriptorSetInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pPushDescriptorSetInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushDescriptorSetInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pPushDescriptorSetInfo->layout));

        if (pPushDescriptorSetInfo->pDescriptorWrites != nullptr)
        {
            for (uint32_t pDescriptorWrites_index = 0; pDescriptorWrites_index < pPushDescriptorSetInfo->descriptorWriteCount; ++pDescriptorWrites_index)
            {
                auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pPushDescriptorSetInfo->pDescriptorWrites->pNext);
                while (pnext_header)
                {
                    switch (pnext_header->sType)
                    {
                        default:
                            break;
                        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
                        {
                            auto pnext_value = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(pnext_header);
                            if (pnext_value->pAccelerationStructures != nullptr)
                            {
                                for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pnext_value->accelerationStructureCount; ++pAccelerationStructures_index)
                                {
                                    if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                            break;
                        }
                        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
                        {
                            auto pnext_value = reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(pnext_header);
                            if (pnext_value->pAccelerationStructures != nullptr)
                            {
                                for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < pnext_value->accelerationStructureCount; ++pAccelerationStructures_index)
                                {
                                    if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                            break;
                        }
                    }
                    pnext_header = pnext_header->pNext;
                }
                if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].dstSet != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId<VulkanDescriptorSetWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].dstSet));

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo != nullptr)
                {
                    for (uint32_t pImageInfo_index = 0; pImageInfo_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pImageInfo_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::SamplerHandle].insert(GetWrappedId<VulkanSamplerWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler));
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView));
                    }
                }

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo != nullptr)
                {
                    for (uint32_t pBufferInfo_index = 0; pBufferInfo_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pBufferInfo_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer));
                    }
                }

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView != nullptr)
                {
                    for (uint32_t pTexelBufferView_index = 0; pTexelBufferView_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pTexelBufferView_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferViewHandle].insert(GetWrappedId<VulkanBufferViewWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index]));
                    }
                }
            }
        }
    }
}

void TrackCmdPushDescriptorSetWithTemplate2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo)
{
    assert(wrapper != nullptr);

    if (pPushDescriptorSetWithTemplateInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pPushDescriptorSetWithTemplateInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorUpdateTemplateHandle].insert(GetWrappedId<VulkanDescriptorUpdateTemplateWrapper>(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate));
        if(pPushDescriptorSetWithTemplateInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pPushDescriptorSetWithTemplateInfo->layout));
    }
}

void TrackCmdSetDescriptorBufferOffsets2EXTHandles(VulkanCommandBufferWrapper* wrapper, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo)
{
    assert(wrapper != nullptr);

    if (pSetDescriptorBufferOffsetsInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pSetDescriptorBufferOffsetsInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pSetDescriptorBufferOffsetsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pSetDescriptorBufferOffsetsInfo->layout));
    }
}

void TrackCmdBindDescriptorBufferEmbeddedSamplers2EXTHandles(VulkanCommandBufferWrapper* wrapper, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
{
    assert(wrapper != nullptr);

    if (pBindDescriptorBufferEmbeddedSamplersInfo != nullptr)
    {
        auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pBindDescriptorBufferEmbeddedSamplersInfo->pNext);
        while (pnext_header)
        {
            switch (pnext_header->sType)
            {
                default:
                    break;
                case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
                {
                    auto pnext_value = reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pnext_header);
                    if (pnext_value->pSetLayouts != nullptr)
                    {
                        for (uint32_t pSetLayouts_index = 0; pSetLayouts_index < pnext_value->setLayoutCount; ++pSetLayouts_index)
                        {
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetLayoutHandle].insert(GetWrappedId<VulkanDescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pBindDescriptorBufferEmbeddedSamplersInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<VulkanPipelineLayoutWrapper>(pBindDescriptorBufferEmbeddedSamplersInfo->layout));
    }
}

void TrackCmdBindTransformFeedbackBuffersEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginTransformFeedbackEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdEndTransformFeedbackEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdBeginQueryIndexedEXTHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryIndexedEXTHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdDrawIndirectByteCountEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer counterBuffer)
{
    assert(wrapper != nullptr);

    if(counterBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(counterBuffer));
}

void TrackCmdDrawIndirectCountAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdBeginConditionalRenderingEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    assert(wrapper != nullptr);

    if (pConditionalRenderingBegin != nullptr)
    {
        if(pConditionalRenderingBegin->buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pConditionalRenderingBegin->buffer));
    }
}

void TrackCmdBindShadingRateImageNVHandles(VulkanCommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(imageView));
}

void TrackCmdBuildAccelerationStructureNVHandles(VulkanCommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if (pInfo->pGeometries != nullptr)
        {
            for (uint32_t pGeometries_index = 0; pGeometries_index < pInfo->geometryCount; ++pGeometries_index)
            {
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData));
                if(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData));
            }
        }
    }
    if(instanceData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(instanceData));
    if(dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(src));
    if(scratch != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(scratch));
}

void TrackCmdCopyAccelerationStructureNVHandles(VulkanCommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src)
{
    assert(wrapper != nullptr);

    if(dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(src));
}

void TrackCmdTraceRaysNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer)
{
    assert(wrapper != nullptr);

    if(raygenShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(raygenShaderBindingTableBuffer));
    if(missShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(missShaderBindingTableBuffer));
    if(hitShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(hitShaderBindingTableBuffer));
    if(callableShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(callableShaderBindingTableBuffer));
}

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(VulkanCommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<VulkanAccelerationStructureNVWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarkerAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(dstBuffer));
}

void TrackCmdDrawMeshTasksIndirectNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

void TrackCmdBindVertexBuffers2EXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdPreprocessGeneratedCommandsNVHandles(VulkanCommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<VulkanPipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId<VulkanIndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdExecuteGeneratedCommandsNVHandles(VulkanCommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<VulkanPipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId<VulkanIndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdBindPipelineShaderGroupNVHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<VulkanPipelineWrapper>(pipeline));
}

void TrackCmdBindInvocationMaskHUAWEIHandles(VulkanCommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<VulkanImageViewWrapper>(imageView));
}

void TrackCmdBuildMicromapsEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].dstMicromap != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pInfos[pInfos_index].dstMicromap));
        }
    }
}

void TrackCmdCopyMicromapEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyMicromapToMemoryEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToMicromapEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteMicromapsPropertiesEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pMicromaps != nullptr)
    {
        for (uint32_t pMicromaps_index = 0; pMicromaps_index < micromapCount; ++pMicromaps_index)
        {
            if(pMicromaps[pMicromaps_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<VulkanMicromapEXTWrapper>(pMicromaps[pMicromaps_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdDrawClusterIndirectHUAWEIHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdUpdatePipelineIndirectBufferNVHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<VulkanPipelineWrapper>(pipeline));
}

void TrackCmdOpticalFlowExecuteNVHandles(VulkanCommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session)
{
    assert(wrapper != nullptr);

    if(session != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::OpticalFlowSessionNVHandle].insert(GetWrappedId<VulkanOpticalFlowSessionNVWrapper>(session));
}

void TrackCmdBindShadersEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders)
{
    assert(wrapper != nullptr);

    if (pShaders != nullptr)
    {
        for (uint32_t pShaders_index = 0; pShaders_index < stageCount; ++pShaders_index)
        {
            if(pShaders[pShaders_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ShaderEXTHandle].insert(GetWrappedId<VulkanShaderEXTWrapper>(pShaders[pShaders_index]));
        }
    }
}

void TrackCmdBuildAccelerationStructuresKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdCopyAccelerationStructureKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<VulkanAccelerationStructureKHRWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<VulkanQueryPoolWrapper>(queryPool));
}

void TrackCmdDrawMeshTasksIndirectEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<VulkanBufferWrapper>(countBuffer));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
