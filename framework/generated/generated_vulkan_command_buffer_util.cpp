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

void TrackBeginCommandBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if (pBeginInfo->pInheritanceInfo != nullptr)
        {
            if(pBeginInfo->pInheritanceInfo->renderPass != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::RenderPassHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::RenderPassWrapper>(pBeginInfo->pInheritanceInfo->renderPass));
            if(pBeginInfo->pInheritanceInfo->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::FramebufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::FramebufferWrapper>(pBeginInfo->pInheritanceInfo->framebuffer));
        }
    }
}

void TrackCmdBindPipelineHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineWrapper>(pipeline));
}

void TrackCmdBindDescriptorSetsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(layout));

    if (pDescriptorSets != nullptr)
    {
        for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < descriptorSetCount; ++pDescriptorSets_index)
        {
            if(pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetWrapper>(pDescriptorSets[pDescriptorSets_index]));
        }
    }
}

void TrackCmdBindIndexBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdBindVertexBuffersHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdDrawIndexedIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdDispatchIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdCopyBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(srcBuffer));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdCopyImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(dstImage));
}

void TrackCmdBlitImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(dstImage));
}

void TrackCmdCopyBufferToImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(srcBuffer));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(dstImage));
}

void TrackCmdCopyImageToBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(srcImage));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdUpdateBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdFillBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdClearColorImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(image));
}

void TrackCmdClearDepthStencilImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    if(image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(image));
}

void TrackCmdResolveImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    if(srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(srcImage));
    if(dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(dstImage));
}

void TrackCmdSetEventHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));
}

void TrackCmdResetEventHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));
}

void TrackCmdWaitEventsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(pEvents[pEvents_index]));
        }
    }

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdPipelineBarrierHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdBeginQueryHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdResetQueryPoolHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteTimestampHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdCopyQueryPoolResultsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdPushConstantsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout)
{
    assert(wrapper != nullptr);

    if(layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(layout));
}

void TrackCmdBeginRenderPassHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::RenderPassHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::FramebufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdExecuteCommandsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(wrapper != nullptr);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t pCommandBuffers_index = 0; pCommandBuffers_index < commandBufferCount; ++pCommandBuffers_index)
        {
            if(pCommandBuffers[pCommandBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::CommandBufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::CommandBufferWrapper>(pCommandBuffers[pCommandBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectCountHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdBeginRenderPass2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::RenderPassHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::FramebufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdSetEvent2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));
}

void TrackCmdWaitEvents2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(pEvents[pEvents_index]));
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
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdCopyBuffer2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBeginRenderingHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
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
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBindVertexBuffers2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginVideoCodingKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
        if(pBeginInfo->videoSession != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::VideoSessionKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::VideoSessionKHRWrapper>(pBeginInfo->videoSession));
        if(pBeginInfo->videoSessionParameters != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::VideoSessionParametersKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::VideoSessionParametersKHRWrapper>(pBeginInfo->videoSessionParameters));

        if (pBeginInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pBeginInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdDecodeVideoKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo)
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
                    if(pnext_value->queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(pnext_value->queryPool));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pDecodeInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDecodeInfo->srcBuffer));
        if(pDecodeInfo->dstPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pDecodeInfo->dstPictureResource.imageViewBinding));

        if (pDecodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pDecodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pDecodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdBeginRenderingKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo)
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
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);
                    if(pnext_value->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->imageView));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
            }
        }

        if (pRenderingInfo->pDepthAttachment != nullptr)
        {
            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pDepthAttachment->imageView));
            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pDepthAttachment->resolveImageView));
        }

        if (pRenderingInfo->pStencilAttachment != nullptr)
        {
            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pStencilAttachment->imageView));
            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pRenderingInfo->pStencilAttachment->resolveImageView));
        }
    }
}

void TrackCmdBeginRenderPass2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::RenderPassHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::RenderPassWrapper>(pRenderPassBegin->renderPass));
        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::FramebufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::FramebufferWrapper>(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdDrawIndirectCountKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdEncodeVideoKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo)
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
                    if(pnext_value->queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(pnext_value->queryPool));
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pEncodeInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pEncodeInfo->dstBuffer));
        if(pEncodeInfo->srcPictureResource.imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pEncodeInfo->srcPictureResource.imageViewBinding));

        if (pEncodeInfo->pSetupReferenceSlot != nullptr)
        {
            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {
                if(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
            }
        }

        if (pEncodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pEncodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {
                if (pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {
                    if(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                }
            }
        }
    }
}

void TrackCmdSetEvent2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdResetEvent2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    if(event != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(event));
}

void TrackCmdWaitEvents2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::EventHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::EventWrapper>(pEvents[pEvents_index]));
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
                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }

            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {
                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackCmdPipelineBarrier2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo)
{
    assert(wrapper != nullptr);

    if (pDependencyInfo != nullptr)
    {
        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {
                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }

        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {
                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackCmdWriteTimestamp2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarker2AMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdCopyBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->srcBuffer));
        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->srcImage));
        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyBufferToImageInfo->srcBuffer));
        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pCopyImageToBufferInfo->srcImage));
        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->srcImage));
        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pResolveImageInfo->srcImage));
        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageWrapper>(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBindIndexBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdBindDescriptorSets2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pBindDescriptorSetsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pBindDescriptorSetsInfo->layout));

        if (pBindDescriptorSetsInfo->pDescriptorSets != nullptr)
        {
            for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < pBindDescriptorSetsInfo->descriptorSetCount; ++pDescriptorSets_index)
            {
                if(pBindDescriptorSetsInfo->pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetWrapper>(pBindDescriptorSetsInfo->pDescriptorSets[pDescriptorSets_index]));
            }
        }
    }
}

void TrackCmdPushConstants2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushConstantsInfoKHR* pPushConstantsInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushConstantsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pPushConstantsInfo->layout));
    }
}

void TrackCmdPushDescriptorSet2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushDescriptorSetInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pPushDescriptorSetInfo->layout));

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
                                    if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
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
                                    if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                            break;
                        }
                    }
                    pnext_header = pnext_header->pNext;
                }
                if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].dstSet != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].dstSet));

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo != nullptr)
                {
                    for (uint32_t pImageInfo_index = 0; pImageInfo_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pImageInfo_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::SamplerHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler));
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView));
                    }
                }

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo != nullptr)
                {
                    for (uint32_t pBufferInfo_index = 0; pBufferInfo_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pBufferInfo_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer));
                    }
                }

                if (pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView != nullptr)
                {
                    for (uint32_t pTexelBufferView_index = 0; pTexelBufferView_index < pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pTexelBufferView_index)
                    {
                        if(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(pPushDescriptorSetInfo->pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index]));
                    }
                }
            }
        }
    }
}

void TrackCmdPushDescriptorSetWithTemplate2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorUpdateTemplateHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(pPushDescriptorSetWithTemplateInfo->descriptorUpdateTemplate));
        if(pPushDescriptorSetWithTemplateInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pPushDescriptorSetWithTemplateInfo->layout));
    }
}

void TrackCmdSetDescriptorBufferOffsets2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pSetDescriptorBufferOffsetsInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pSetDescriptorBufferOffsetsInfo->layout));
    }
}

void TrackCmdBindDescriptorBufferEmbeddedSamplers2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo)
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
                            if(pnext_value->pSetLayouts[pSetLayouts_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::DescriptorSetLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::DescriptorSetLayoutWrapper>(pnext_value->pSetLayouts[pSetLayouts_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        if(pBindDescriptorBufferEmbeddedSamplersInfo->layout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineLayoutHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineLayoutWrapper>(pBindDescriptorBufferEmbeddedSamplersInfo->layout));
    }
}

void TrackCmdBindTransformFeedbackBuffersEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdBeginTransformFeedbackEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdEndTransformFeedbackEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdBeginQueryIndexedEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdEndQueryIndexedEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawIndirectByteCountEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer counterBuffer)
{
    assert(wrapper != nullptr);

    if(counterBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(counterBuffer));
}

void TrackCmdDrawIndirectCountAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdBeginConditionalRenderingEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    assert(wrapper != nullptr);

    if (pConditionalRenderingBegin != nullptr)
    {
        if(pConditionalRenderingBegin->buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pConditionalRenderingBegin->buffer));
    }
}

void TrackCmdBindShadingRateImageNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(imageView));
}

void TrackCmdBuildAccelerationStructureNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if (pInfo->pGeometries != nullptr)
        {
            for (uint32_t pGeometries_index = 0; pGeometries_index < pInfo->geometryCount; ++pGeometries_index)
            {
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData));
                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData));
                if(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData));
            }
        }
    }
    if(instanceData != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(instanceData));
    if(dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(src));
    if(scratch != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(scratch));
}

void TrackCmdCopyAccelerationStructureNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src)
{
    assert(wrapper != nullptr);

    if(dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(dst));
    if(src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(src));
}

void TrackCmdTraceRaysNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer)
{
    assert(wrapper != nullptr);

    if(raygenShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(raygenShaderBindingTableBuffer));
    if(missShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(missShaderBindingTableBuffer));
    if(hitShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(hitShaderBindingTableBuffer));
    if(callableShaderBindingTableBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(callableShaderBindingTableBuffer));
}

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureNVWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdWriteBufferMarkerAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    if(dstBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(dstBuffer));
}

void TrackCmdDrawMeshTasksIndirectNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

void TrackCmdBindVertexBuffers2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdPreprocessGeneratedCommandsNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::IndirectCommandsLayoutNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdExecuteGeneratedCommandsNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineWrapper>(pGeneratedCommandsInfo->pipeline));
        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::IndirectCommandsLayoutNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->preprocessBuffer));
        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->sequencesCountBuffer));
        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdBindPipelineShaderGroupNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineWrapper>(pipeline));
}

void TrackCmdBindInvocationMaskHUAWEIHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    if(imageView != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ImageViewHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(imageView));
}

void TrackCmdBuildMicromapsEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].dstMicromap != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pInfos[pInfos_index].dstMicromap));
        }
    }
}

void TrackCmdCopyMicromapEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyMicromapToMemoryEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToMicromapEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteMicromapsPropertiesEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pMicromaps != nullptr)
    {
        for (uint32_t pMicromaps_index = 0; pMicromaps_index < micromapCount; ++pMicromaps_index)
        {
            if(pMicromaps[pMicromaps_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::MicromapEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::MicromapEXTWrapper>(pMicromaps[pMicromaps_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawClusterIndirectHUAWEIHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdUpdatePipelineIndirectBufferNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    if(pipeline != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::PipelineHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::PipelineWrapper>(pipeline));
}

void TrackCmdOpticalFlowExecuteNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session)
{
    assert(wrapper != nullptr);

    if(session != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::OpticalFlowSessionNVHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::OpticalFlowSessionNVWrapper>(session));
}

void TrackCmdBindShadersEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders)
{
    assert(wrapper != nullptr);

    if (pShaders != nullptr)
    {
        for (uint32_t pShaders_index = 0; pShaders_index < stageCount; ++pShaders_index)
        {
            if(pShaders[pShaders_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::ShaderEXTHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::ShaderEXTWrapper>(pShaders[pShaders_index]));
        }
    }
}

void TrackCmdBuildAccelerationStructuresKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfos[pInfos_index].srcAccelerationStructure));
            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdCopyAccelerationStructureKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfo->src));
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->src != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfo->src));
    }
}

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        if(pInfo->dst != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pInfo->dst));
    }
}

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    if(queryPool != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::QueryPoolHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::QueryPoolWrapper>(queryPool));
}

void TrackCmdDrawMeshTasksIndirectEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    if(buffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer));
    if(countBuffer != VK_NULL_HANDLE) wrapper->command_handles[vulkan_state_info::CommandHandleType::BufferHandle].insert(vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(countBuffer));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
