/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
            wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId(pBeginInfo->pInheritanceInfo->renderPass));
            wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId(pBeginInfo->pInheritanceInfo->framebuffer));
        }
    }
}

void TrackCmdBindPipelineHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId(pipeline));
}

void TrackCmdBindDescriptorSetsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId(layout));

    if (pDescriptorSets != nullptr)
    {
        for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < descriptorSetCount; ++pDescriptorSets_index)
        {
            wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId(pDescriptorSets[pDescriptorSets_index]));
        }
    }
}

void TrackCmdBindIndexBufferHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
}

void TrackCmdBindVertexBuffersHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
}

void TrackCmdDrawIndexedIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
}

void TrackCmdDispatchIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
}

void TrackCmdCopyBufferHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(srcBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdCopyImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(dstImage));
}

void TrackCmdBlitImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(dstImage));
}

void TrackCmdCopyBufferToImageHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(srcBuffer));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(dstImage));
}

void TrackCmdCopyImageToBufferHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(srcImage));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdUpdateBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdFillBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdClearColorImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(image));
}

void TrackCmdClearDepthStencilImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(image));
}

void TrackCmdResolveImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(dstImage));
}

void TrackCmdSetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId(event));
}

void TrackCmdResetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId(event));
}

void TrackCmdWaitEventsHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            wrapper->command_handles[CommandHandleType::EventHandle].insert(GetWrappedId(pEvents[pEvents_index]));
        }
    }

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
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
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {
            wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
        }
    }
}

void TrackCmdBeginQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdEndQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdResetQueryPoolHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdWriteTimestampHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdCopyQueryPoolResultsHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdPushConstantsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId(layout));
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
                            wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId(pRenderPassBegin->renderPass));
        wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdExecuteCommandsHandles(CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(wrapper != nullptr);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t pCommandBuffers_index = 0; pCommandBuffers_index < commandBufferCount; ++pCommandBuffers_index)
        {
            wrapper->command_handles[CommandHandleType::CommandBufferHandle].insert(GetWrappedId(pCommandBuffers[pCommandBuffers_index]));
        }
    }
}

void TrackCmdDrawIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
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
                            wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId(pRenderPassBegin->renderPass));
        wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdPushDescriptorSetKHRHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(GetWrappedId(layout));

    if (pDescriptorWrites != nullptr)
    {
        for (uint32_t pDescriptorWrites_index = 0; pDescriptorWrites_index < descriptorWriteCount; ++pDescriptorWrites_index)
        {
            auto pnext_header = reinterpret_cast<const VkBaseInStructure*>(pDescriptorWrites->pNext);
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
                                wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
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
                                wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                            }
                        }
                        break;
                    }
                }
                pnext_header = pnext_header->pNext;
            }
            wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(GetWrappedId(pDescriptorWrites[pDescriptorWrites_index].dstSet));

            if (pDescriptorWrites[pDescriptorWrites_index].pImageInfo != nullptr)
            {
                for (uint32_t pImageInfo_index = 0; pImageInfo_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pImageInfo_index)
                {
                    wrapper->command_handles[CommandHandleType::SamplerHandle].insert(GetWrappedId(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler));
                    wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView));
                }
            }

            if (pDescriptorWrites[pDescriptorWrites_index].pBufferInfo != nullptr)
            {
                for (uint32_t pBufferInfo_index = 0; pBufferInfo_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pBufferInfo_index)
                {
                    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer));
                }
            }

            if (pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView != nullptr)
            {
                for (uint32_t pTexelBufferView_index = 0; pTexelBufferView_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pTexelBufferView_index)
                {
                    wrapper->command_handles[CommandHandleType::BufferViewHandle].insert(GetWrappedId(pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index]));
                }
            }
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
                            wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId(pnext_value->pAttachments[pAttachments_index]));
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }
        wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(GetWrappedId(pRenderPassBegin->renderPass));
        wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(GetWrappedId(pRenderPassBegin->framebuffer));
    }
}

void TrackCmdDrawIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdCopyBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferInfo2KHR* pCopyBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCopyBufferInfo->srcBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCopyBufferInfo->dstBuffer));
    }
}

void TrackCmdCopyImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageInfo2KHR* pCopyImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pCopyImageInfo->srcImage));
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pCopyImageInfo->dstImage));
    }
}

void TrackCmdCopyBufferToImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2KHR* pCopyBufferToImageInfo)
{
    assert(wrapper != nullptr);

    if (pCopyBufferToImageInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCopyBufferToImageInfo->srcBuffer));
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pCopyBufferToImageInfo->dstImage));
    }
}

void TrackCmdCopyImageToBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2KHR* pCopyImageToBufferInfo)
{
    assert(wrapper != nullptr);

    if (pCopyImageToBufferInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pCopyImageToBufferInfo->srcImage));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCopyImageToBufferInfo->dstBuffer));
    }
}

void TrackCmdBlitImage2KHRHandles(CommandBufferWrapper* wrapper, const VkBlitImageInfo2KHR* pBlitImageInfo)
{
    assert(wrapper != nullptr);

    if (pBlitImageInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pBlitImageInfo->srcImage));
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pBlitImageInfo->dstImage));
    }
}

void TrackCmdResolveImage2KHRHandles(CommandBufferWrapper* wrapper, const VkResolveImageInfo2KHR* pResolveImageInfo)
{
    assert(wrapper != nullptr);

    if (pResolveImageInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pResolveImageInfo->srcImage));
        wrapper->command_handles[CommandHandleType::ImageHandle].insert(GetWrappedId(pResolveImageInfo->dstImage));
    }
}

void TrackCmdBindTransformFeedbackBuffersEXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pBuffers[pBuffers_index]));
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
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCounterBuffers[pCounterBuffers_index]));
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
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pCounterBuffers[pCounterBuffers_index]));
        }
    }
}

void TrackCmdBeginQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdEndQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdDrawIndirectByteCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer counterBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(counterBuffer));
}

void TrackCmdDrawIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdBeginConditionalRenderingEXTHandles(CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    assert(wrapper != nullptr);

    if (pConditionalRenderingBegin != nullptr)
    {
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pConditionalRenderingBegin->buffer));
    }
}

void TrackCmdBindShadingRateImageNVHandles(CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(GetWrappedId(imageView));
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
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData));
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData));
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData));
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData));
            }
        }
    }
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(instanceData));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(dst));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(src));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(scratch));
}

void TrackCmdCopyAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(dst));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(src));
}

void TrackCmdTraceRaysNVHandles(CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(raygenShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(missShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(hitShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(callableShaderBindingTableBuffer));
}

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(GetWrappedId(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

void TrackCmdWriteBufferMarkerAMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(dstBuffer));
}

void TrackCmdDrawMeshTasksIndirectNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(countBuffer));
}

void TrackCmdBindVertexBuffers2EXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pBuffers[pBuffers_index]));
        }
    }
}

void TrackCmdPreprocessGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId(pGeneratedCommandsInfo->pipeline));
        wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->preprocessBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->sequencesCountBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdExecuteGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pGeneratedCommandsInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId(pGeneratedCommandsInfo->pipeline));
        wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVHandle].insert(GetWrappedId(pGeneratedCommandsInfo->indirectCommandsLayout));

        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {
                wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
            }
        }
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->preprocessBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->sequencesCountBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(GetWrappedId(pGeneratedCommandsInfo->sequencesIndexBuffer));
    }
}

void TrackCmdBindPipelineShaderGroupNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineHandle].insert(GetWrappedId(pipeline));
}

void TrackCmdBuildAccelerationStructuresKHRHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos)
{
    assert(wrapper != nullptr);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {
            wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfos[pInfos_index].srcAccelerationStructure));
            wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfos[pInfos_index].dstAccelerationStructure));
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
            wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfos[pInfos_index].srcAccelerationStructure));
            wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfos[pInfos_index].dstAccelerationStructure));
        }
    }
}

void TrackCmdCopyAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfo->src));
        wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfo->dst));
    }
}

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfo->src));
    }
}

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pInfo->dst));
    }
}

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            wrapper->command_handles[CommandHandleType::AccelerationStructureKHRHandle].insert(GetWrappedId(pAccelerationStructures[pAccelerationStructures_index]));
        }
    }
    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(GetWrappedId(queryPool));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
