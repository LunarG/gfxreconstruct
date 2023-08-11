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

void TrackBeginCommandBufferHandles(CommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if (pBeginInfo->pInheritanceInfo != nullptr)
        {
            if(pBeginInfo->pInheritanceInfo->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<RenderPassWrapper>(pBeginInfo->pInheritanceInfo->renderPass));
            if(pBeginInfo->pInheritanceInfo->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<FramebufferWrapper>(pBeginInfo->pInheritanceInfo->framebuffer));
        }
    }
}

void TrackCmdBindPipelineHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<PipelineWrapper>(pipeline));
}

void TrackCmdBindDescriptorSetsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<PipelineLayoutWrapper>(layout));

    if (pDescriptorSets != nullptr)
    {
        for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < descriptorSetCount; ++pDescriptorSets_index)
        {
            if(pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId<DescriptorSetWrapper>(pDescriptorSets[pDescriptorSets_index]));
        }
    }
}

void TrackCmdBindIndexBufferHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdBindVertexBuffersHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdDrawIndexedIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdDispatchIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdCopyBufferHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(srcBuffer));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdCopyImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(dstImage));
}

void TrackCmdBlitImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(dstImage));
}

void TrackCmdCopyBufferToImageHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(srcBuffer));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(dstImage));
}

void TrackCmdCopyImageToBufferHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(srcImage));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdUpdateBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdFillBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdClearColorImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(image));
}

void TrackCmdClearDepthStencilImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(image));
}

void TrackCmdResolveImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(dstImage));
}

void TrackCmdSetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));
}

void TrackCmdResetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));
}

void TrackCmdWaitEventsHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(pEvents[pEvents_index]));
        }
    }

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdPipelineBarrierHandles(CommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdBeginQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdResetQueryPoolHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteTimestampHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdCopyQueryPoolResultsHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdPushConstantsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId<PipelineLayoutWrapper>(layout));
}

void TrackCmdBeginRenderPassHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdExecuteCommandsHandles(CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(wrapper != nullptr);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t pCommandBuffers_index = 0; pCommandBuffers_index < commandBufferCount; ++pCommandBuffers_index)
        {
            if(pCommandBuffers[pCommandBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::CommandBufferHandle].insert(GetWrappedId<CommandBufferWrapper>(pCommandBuffers[pCommandBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdBeginRenderPass2Handles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdSetEvent2Handles(CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2Handles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));
}

void TrackCmdWaitEvents2Handles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(pEvents[pEvents_index]));
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
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2Handles(CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2Handles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdCopyBuffer2Handles(CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2Handles(CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2Handles(CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2Handles(CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2Handles(CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2Handles(CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBeginRenderingHandles(CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
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
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBindVertexBuffers2Handles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginVideoCodingKHRHandles(CommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if(pBeginInfo->videoSession != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::VideoSessionKHRHandle].insert(GetWrappedId<VideoSessionKHRWrapper>(pBeginInfo->videoSession));
        if(pBeginInfo->videoSessionParameters != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::VideoSessionParametersKHRHandle].insert(GetWrappedId<VideoSessionParametersKHRWrapper>(pBeginInfo->videoSessionParameters));

        if (pBeginInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pBeginInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdDecodeVideoKHRHandles(CommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo)
{
    assert(wrapper != nullptr);

    if (pDecodeInfo != nullptr)
    {
        if(pDecodeInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDecodeInfo->srcBuffer));
        if(pDecodeInfo->dstPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pDecodeInfo->dstPictureResource.imageViewBinding));

        if (pDecodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pDecodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pDecodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdBeginRenderingKHRHandles(CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
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
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBeginRenderPass2KHRHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId<RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId<FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdDrawIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdEncodeVideoKHRHandles(CommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo)
{
    assert(wrapper != nullptr);

    if (pEncodeInfo != nullptr)
    {
        if(pEncodeInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pEncodeInfo->dstBuffer));
        if(pEncodeInfo->srcPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pEncodeInfo->srcPictureResource.imageViewBinding));

        if (pEncodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pEncodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pEncodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdSetEvent2KHRHandles(CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2KHRHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(event));
}

void TrackCmdWaitEvents2KHRHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId<EventWrapper>(pEvents[pEvents_index]));
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
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2KHRHandles(CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2KHRHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarker2AMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdCopyBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2KHRHandles(CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2KHRHandles(CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId<ImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBindIndexBuffer2KHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdBindTransformFeedbackBuffersEXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdEndTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdBeginQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawIndirectByteCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer counterBuffer)
{
    assert(wrapper != nullptr);

    if(counterBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(counterBuffer));
}

void TrackCmdDrawIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdBeginConditionalRenderingEXTHandles(CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    assert(wrapper != nullptr);

    if (pConditionalRenderingBegin != nullptr)
    {
        if(pConditionalRenderingBegin->buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pConditionalRenderingBegin->buffer));
    }
}

void TrackCmdBindShadingRateImageNVHandles(CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(imageView));
}

void TrackCmdBuildAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if (pInfo->pGeometries != nullptr)
        {
            for (uint32_t pGeometries_index = 0; pGeometries_index < pInfo->geometryCount; ++pGeometries_index)
            {
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData));
                if(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData));
            }
        }
    }
    if(instanceData != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(instanceData));
    if(dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<AccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<AccelerationStructureNVWrapper>(src));
    if(scratch != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(scratch));
}

void TrackCmdCopyAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src)
{
    assert(wrapper != nullptr);

    if(dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<AccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<AccelerationStructureNVWrapper>(src));
}

void TrackCmdTraceRaysNVHandles(CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer)
{
    assert(wrapper != nullptr);

    if(raygenShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(raygenShaderBindingTableBuffer));
    if(missShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(missShaderBindingTableBuffer));
    if(hitShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(hitShaderBindingTableBuffer));
    if(callableShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(callableShaderBindingTableBuffer));
}

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId<AccelerationStructureNVWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarkerAMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(dstBuffer));
}

void TrackCmdDrawMeshTasksIndirectNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

void TrackCmdBindVertexBuffers2EXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdPreprocessGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<PipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId<IndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdExecuteGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<PipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId<IndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdBindPipelineShaderGroupNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<PipelineWrapper>(pipeline));
}

void TrackCmdBindInvocationMaskHUAWEIHandles(CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId<ImageViewWrapper>(imageView));
}

void TrackCmdBuildMicromapsEXTHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].dstMicromap != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pInfos[pInfos_index].dstMicromap));
        }
    }
}

void TrackCmdCopyMicromapEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyMicromapToMemoryEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToMicromapEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteMicromapsPropertiesEXTHandles(CommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pMicromaps != nullptr)
    {
        for (uint32_t pMicromaps_index = 0; pMicromaps_index < micromapCount; ++pMicromaps_index)
        {
            if(pMicromaps[pMicromaps_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::MicromapEXTHandle].insert(GetWrappedId<MicromapEXTWrapper>(pMicromaps[pMicromaps_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawClusterIndirectHUAWEIHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdUpdatePipelineIndirectBufferNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId<PipelineWrapper>(pipeline));
}

void TrackCmdOpticalFlowExecuteNVHandles(CommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session)
{
    assert(wrapper != nullptr);

    if(session != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::OpticalFlowSessionNVHandle].insert(GetWrappedId<OpticalFlowSessionNVWrapper>(session));
}

void TrackCmdBindShadersEXTHandles(CommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders)
{
    assert(wrapper != nullptr);

    if (pShaders != nullptr)
    {
        for (uint32_t pShaders_index = 0; pShaders_index < stageCount; ++pShaders_index)
        {
            if(pShaders[pShaders_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::ShaderEXTHandle].insert(GetWrappedId<ShaderEXTWrapper>(pShaders[pShaders_index]));
        }
    }
}

void TrackCmdBuildAccelerationStructuresKHRHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdCopyAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId<AccelerationStructureKHRWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId<QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawMeshTasksIndirectEXTHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId<BufferWrapper>(countBuffer));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
