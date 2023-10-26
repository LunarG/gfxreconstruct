/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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

#include "generated/generated_vulkan_dr_command_buffer_util.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

enum DRCommandHandleType : uint32_t
{
    BufferHandle = 0,
    BufferViewHandle,
    CommandBufferHandle,
    DescriptorSetHandle,
    EventHandle,
    FramebufferHandle,
    ImageHandle,
    ImageViewHandle,
    PipelineHandle,
    PipelineLayoutHandle,
    QueryPoolHandle,
    RenderPassHandle,
    SamplerHandle,
    AccelerationStructureKHRHandle,
    AccelerationStructureNVHandle,
    IndirectCommandsLayoutNVHandle,
    DeferredOperationKHRHandle,
    MicromapEXTHandle,
    OpticalFlowSessionNVHandle,
    VideoSessionKHRHandle,
    VideoSessionParametersKHRHandle,
    NumHandleTypes,
    ShaderEXTHandle             //TODO: Need to add code to handle this case
};

std::set<format::HandleId> dr_command_handles[NumHandleTypes];
struct handlesetstruct  {
    std::set<format::HandleId> dr_command_handles[NumHandleTypes];
};
std::map<VkCommandBuffer, handlesetstruct> handleset;

void TrackDRCmdBindPipelineHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline) //@@@DLO
{
    assert(commandBuffer);

    if(pipeline != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineHandle].insert(reinterpret_cast<format::HandleId>(pipeline));
    }
}

void TrackDRCmdBindDescriptorSetsHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) //@@@DLO
{
    assert(commandBuffer);

    if(layout != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineLayoutHandle].insert(reinterpret_cast<format::HandleId>(layout));
    }


    if (pDescriptorSets != nullptr)
    {
        for (uint32_t pDescriptorSets_index = 0; pDescriptorSets_index < descriptorSetCount; ++pDescriptorSets_index)
        {
            if(pDescriptorSets[pDescriptorSets_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[DescriptorSetHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorSets[pDescriptorSets_index]));
            }
        }
    }
}

void TrackDRCmdBindIndexBufferHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdBindVertexBuffersHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBuffers[pBuffers_index]));
            }
        }
    }
}

void TrackDRCmdDrawIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdDrawIndexedIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdDispatchIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdCopyBufferHandles(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(srcBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(srcBuffer));
    }

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdCopyImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage) //@@@DLO
{
    assert(commandBuffer);

    if(srcImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(srcImage));
    }

    if(dstImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(dstImage));
    }
}

void TrackDRCmdBlitImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage) //@@@DLO
{
    assert(commandBuffer);

    if(srcImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(srcImage));
    }

    if(dstImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(dstImage));
    }
}

void TrackDRCmdCopyBufferToImageHandles(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage) //@@@DLO
{
    assert(commandBuffer);

    if(srcBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(srcBuffer));
    }

    if(dstImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(dstImage));
    }
}

void TrackDRCmdCopyImageToBufferHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(srcImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(srcImage));
    }

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdUpdateBufferHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdFillBufferHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdClearColorImageHandles(VkCommandBuffer commandBuffer, VkImage image) //@@@DLO
{
    assert(commandBuffer);

    if(image != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(image));
    }
}

void TrackDRCmdClearDepthStencilImageHandles(VkCommandBuffer commandBuffer, VkImage image) //@@@DLO
{
    assert(commandBuffer);

    if(image != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(image));
    }
}

void TrackDRCmdResolveImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage) //@@@DLO
{
    assert(commandBuffer);

    if(srcImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(srcImage));
    }

    if(dstImage != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(dstImage));
    }
}

void TrackDRCmdSetEventHandles(VkCommandBuffer commandBuffer, VkEvent event) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }
}

void TrackDRCmdResetEventHandles(VkCommandBuffer commandBuffer, VkEvent event) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }
}

void TrackDRCmdWaitEventsHandles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) //@@@DLO
{
    assert(commandBuffer);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(pEvents[pEvents_index]));
            }
        }
    }


    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {

            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }
    }


    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {

            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackDRCmdPipelineBarrierHandles(VkCommandBuffer commandBuffer, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) //@@@DLO
{
    assert(commandBuffer);

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
        {

            if(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
            }
        }
    }


    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
        {

            if(pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pImageMemoryBarriers[pImageMemoryBarriers_index].image));
            }
        }
    }
}

void TrackDRCmdBeginQueryHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdEndQueryHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdResetQueryPoolHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdWriteTimestampHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdCopyQueryPoolResultsHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdPushConstantsHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout) //@@@DLO
{
    assert(commandBuffer);

    if(layout != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineLayoutHandle].insert(reinterpret_cast<format::HandleId>(layout));
    }
}

void TrackDRCmdBeginRenderPassHandles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin) //@@@DLO
{
    assert(commandBuffer);

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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE)
                            {
                                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->pAttachments[pAttachments_index]));
                            }
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[RenderPassHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->renderPass));
        }

        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[FramebufferHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->framebuffer));
        }
    }
}

void TrackDRCmdExecuteCommandsHandles(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t pCommandBuffers_index = 0; pCommandBuffers_index < commandBufferCount; ++pCommandBuffers_index)
        {
            if(pCommandBuffers[pCommandBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[CommandBufferHandle].insert(reinterpret_cast<format::HandleId>(pCommandBuffers[pCommandBuffers_index]));
            }
        }
    }
}

void TrackDRCmdDrawIndirectCountHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdDrawIndexedIndirectCountHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdBeginRenderPass2Handles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin) //@@@DLO
{
    assert(commandBuffer);

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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE)
                            {
                                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->pAttachments[pAttachments_index]));
                            }
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[RenderPassHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->renderPass));
        }

        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[FramebufferHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->framebuffer));
        }
    }
}

void TrackDRCmdSetEvent2Handles(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }


    if (pDependencyInfo != nullptr)
    {

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {

                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }
        }


        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {

                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackDRCmdResetEvent2Handles(VkCommandBuffer commandBuffer, VkEvent event) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }
}

void TrackDRCmdWaitEvents2Handles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) //@@@DLO
{
    assert(commandBuffer);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(pEvents[pEvents_index]));
            }
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

                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                    }
                }
            }


            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {

                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                    }
                }
            }
        }
    }
}

void TrackDRCmdPipelineBarrier2Handles(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pDependencyInfo != nullptr)
    {

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {

                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }
        }


        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {

                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackDRCmdWriteTimestamp2Handles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdCopyBuffer2Handles(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyBufferInfo != nullptr)
    {

        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferInfo->srcBuffer));
        }

        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferInfo->dstBuffer));
        }
    }
}

void TrackDRCmdCopyImage2Handles(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyImageInfo != nullptr)
    {

        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageInfo->srcImage));
        }

        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageInfo->dstImage));
        }
    }
}

void TrackDRCmdCopyBufferToImage2Handles(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyBufferToImageInfo != nullptr)
    {

        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferToImageInfo->srcBuffer));
        }

        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferToImageInfo->dstImage));
        }
    }
}

void TrackDRCmdCopyImageToBuffer2Handles(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyImageToBufferInfo != nullptr)
    {

        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageToBufferInfo->srcImage));
        }

        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageToBufferInfo->dstBuffer));
        }
    }
}

void TrackDRCmdBlitImage2Handles(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pBlitImageInfo != nullptr)
    {

        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pBlitImageInfo->srcImage));
        }

        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pBlitImageInfo->dstImage));
        }
    }
}

void TrackDRCmdResolveImage2Handles(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pResolveImageInfo != nullptr)
    {

        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pResolveImageInfo->srcImage));
        }

        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pResolveImageInfo->dstImage));
        }
    }
}

void TrackDRCmdBeginRenderingHandles(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) //@@@DLO
{
    assert(commandBuffer);

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


                    if(pnext_value->imageView != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->imageView));
                    }
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);


                    if(pnext_value->imageView != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->imageView));
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }


        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {

                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                }

                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
                }
            }
        }


        if (pRenderingInfo->pDepthAttachment != nullptr)
        {

            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pDepthAttachment->imageView));
            }

            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pDepthAttachment->resolveImageView));
            }
        }


        if (pRenderingInfo->pStencilAttachment != nullptr)
        {

            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pStencilAttachment->imageView));
            }

            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pStencilAttachment->resolveImageView));
            }
        }
    }
}

void TrackDRCmdBindVertexBuffers2Handles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBuffers[pBuffers_index]));
            }
        }
    }
}

void TrackDRCmdBeginVideoCodingKHRHandles(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pBeginInfo != nullptr)
    {

        if(pBeginInfo->videoSession != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[VideoSessionKHRHandle].insert(reinterpret_cast<format::HandleId>(pBeginInfo->videoSession));
        }

        if(pBeginInfo->videoSessionParameters != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[VideoSessionParametersKHRHandle].insert(reinterpret_cast<format::HandleId>(pBeginInfo->videoSessionParameters));
        }


        if (pBeginInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pBeginInfo->referenceSlotCount; ++pReferenceSlots_index)
            {

                if (pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {

                    if(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pBeginInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                    }
                }
            }
        }
    }
}

void TrackDRCmdDecodeVideoKHRHandles(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pDecodeInfo != nullptr)
    {

        if(pDecodeInfo->srcBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDecodeInfo->srcBuffer));
        }


        if(pDecodeInfo->dstPictureResource.imageViewBinding != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pDecodeInfo->dstPictureResource.imageViewBinding));
        }


        if (pDecodeInfo->pSetupReferenceSlot != nullptr)
        {

            if (pDecodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {

                if(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pDecodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
                }
            }
        }


        if (pDecodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pDecodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {

                if (pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {

                    if(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pDecodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                    }
                }
            }
        }
    }
}

void TrackDRCmdBeginRenderingKHRHandles(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) //@@@DLO
{
    assert(commandBuffer);

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


                    if(pnext_value->imageView != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->imageView));
                    }
                    break;
                }
                case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                {
                    auto pnext_value = reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_header);


                    if(pnext_value->imageView != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->imageView));
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }


        if (pRenderingInfo->pColorAttachments != nullptr)
        {
            for (uint32_t pColorAttachments_index = 0; pColorAttachments_index < pRenderingInfo->colorAttachmentCount; ++pColorAttachments_index)
            {

                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pColorAttachments[pColorAttachments_index].imageView));
                }

                if(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pColorAttachments[pColorAttachments_index].resolveImageView));
                }
            }
        }


        if (pRenderingInfo->pDepthAttachment != nullptr)
        {

            if(pRenderingInfo->pDepthAttachment->imageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pDepthAttachment->imageView));
            }

            if(pRenderingInfo->pDepthAttachment->resolveImageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pDepthAttachment->resolveImageView));
            }
        }


        if (pRenderingInfo->pStencilAttachment != nullptr)
        {

            if(pRenderingInfo->pStencilAttachment->imageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pStencilAttachment->imageView));
            }

            if(pRenderingInfo->pStencilAttachment->resolveImageView != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pRenderingInfo->pStencilAttachment->resolveImageView));
            }
        }
    }
}

void TrackDRCmdPushDescriptorSetKHRHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) //@@@DLO
{
    assert(commandBuffer);

    if(layout != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineLayoutHandle].insert(reinterpret_cast<format::HandleId>(layout));
    }


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
                                if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE)
                                {
                                    handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
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
                                if(pnext_value->pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE)
                                {
                                    handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->pAccelerationStructures[pAccelerationStructures_index]));
                                }
                            }
                        }
                        break;
                    }
                }
                pnext_header = pnext_header->pNext;
            }

            if(pDescriptorWrites[pDescriptorWrites_index].dstSet != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[DescriptorSetHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorWrites[pDescriptorWrites_index].dstSet));
            }


            if (pDescriptorWrites[pDescriptorWrites_index].pImageInfo != nullptr)
            {
                for (uint32_t pImageInfo_index = 0; pImageInfo_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pImageInfo_index)
                {

                    if(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[SamplerHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].sampler));
                    }

                    if(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorWrites[pDescriptorWrites_index].pImageInfo[pImageInfo_index].imageView));
                    }
                }
            }


            if (pDescriptorWrites[pDescriptorWrites_index].pBufferInfo != nullptr)
            {
                for (uint32_t pBufferInfo_index = 0; pBufferInfo_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pBufferInfo_index)
                {

                    if(pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorWrites[pDescriptorWrites_index].pBufferInfo[pBufferInfo_index].buffer));
                    }
                }
            }


            if (pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView != nullptr)
            {
                for (uint32_t pTexelBufferView_index = 0; pTexelBufferView_index < pDescriptorWrites[pDescriptorWrites_index].descriptorCount; ++pTexelBufferView_index)
                {
                    if(pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index] != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[BufferViewHandle].insert(reinterpret_cast<format::HandleId>(pDescriptorWrites[pDescriptorWrites_index].pTexelBufferView[pTexelBufferView_index]));
                    }
                }
            }
        }
    }
}

void TrackDRCmdBeginRenderPass2KHRHandles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin) //@@@DLO
{
    assert(commandBuffer);

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
                            if(pnext_value->pAttachments[pAttachments_index] != VK_NULL_HANDLE)
                            {
                                handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pnext_value->pAttachments[pAttachments_index]));
                            }
                        }
                    }
                    break;
                }
            }
            pnext_header = pnext_header->pNext;
        }

        if(pRenderPassBegin->renderPass != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[RenderPassHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->renderPass));
        }

        if(pRenderPassBegin->framebuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[FramebufferHandle].insert(reinterpret_cast<format::HandleId>(pRenderPassBegin->framebuffer));
        }
    }
}

void TrackDRCmdDrawIndirectCountKHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdDrawIndexedIndirectCountKHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdEncodeVideoKHRHandles(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pEncodeInfo != nullptr)
    {

        if(pEncodeInfo->dstBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pEncodeInfo->dstBuffer));
        }


        if(pEncodeInfo->srcPictureResource.imageViewBinding != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pEncodeInfo->srcPictureResource.imageViewBinding));
        }


        if (pEncodeInfo->pSetupReferenceSlot != nullptr)
        {

            if (pEncodeInfo->pSetupReferenceSlot->pPictureResource != nullptr)
            {

                if(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pEncodeInfo->pSetupReferenceSlot->pPictureResource->imageViewBinding));
                }
            }
        }


        if (pEncodeInfo->pReferenceSlots != nullptr)
        {
            for (uint32_t pReferenceSlots_index = 0; pReferenceSlots_index < pEncodeInfo->referenceSlotCount; ++pReferenceSlots_index)
            {

                if (pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource != nullptr)
                {

                    if(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(pEncodeInfo->pReferenceSlots[pReferenceSlots_index].pPictureResource->imageViewBinding));
                    }
                }
            }
        }
    }
}

void TrackDRCmdSetEvent2KHRHandles(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }


    if (pDependencyInfo != nullptr)
    {

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {

                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }
        }


        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {

                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackDRCmdResetEvent2KHRHandles(VkCommandBuffer commandBuffer, VkEvent event) //@@@DLO
{
    assert(commandBuffer);

    if(event != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(event));
    }
}

void TrackDRCmdWaitEvents2KHRHandles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) //@@@DLO
{
    assert(commandBuffer);

    if (pEvents != nullptr)
    {
        for (uint32_t pEvents_index = 0; pEvents_index < eventCount; ++pEvents_index)
        {
            if(pEvents[pEvents_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[EventHandle].insert(reinterpret_cast<format::HandleId>(pEvents[pEvents_index]));
            }
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

                    if(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfos[pDependencyInfos_index].pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                    }
                }
            }


            if (pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers != nullptr)
            {
                for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfos[pDependencyInfos_index].imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
                {

                    if(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                    {
                        handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfos[pDependencyInfos_index].pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                    }
                }
            }
        }
    }
}

void TrackDRCmdPipelineBarrier2KHRHandles(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pDependencyInfo != nullptr)
    {

        if (pDependencyInfo->pBufferMemoryBarriers != nullptr)
        {
            for (uint32_t pBufferMemoryBarriers_index = 0; pBufferMemoryBarriers_index < pDependencyInfo->bufferMemoryBarrierCount; ++pBufferMemoryBarriers_index)
            {

                if(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pBufferMemoryBarriers[pBufferMemoryBarriers_index].buffer));
                }
            }
        }


        if (pDependencyInfo->pImageMemoryBarriers != nullptr)
        {
            for (uint32_t pImageMemoryBarriers_index = 0; pImageMemoryBarriers_index < pDependencyInfo->imageMemoryBarrierCount; ++pImageMemoryBarriers_index)
            {

                if(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pDependencyInfo->pImageMemoryBarriers[pImageMemoryBarriers_index].image));
                }
            }
        }
    }
}

void TrackDRCmdWriteTimestamp2KHRHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdWriteBufferMarker2AMDHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdCopyBuffer2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyBufferInfo != nullptr)
    {

        if(pCopyBufferInfo->srcBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferInfo->srcBuffer));
        }

        if(pCopyBufferInfo->dstBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferInfo->dstBuffer));
        }
    }
}

void TrackDRCmdCopyImage2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyImageInfo != nullptr)
    {

        if(pCopyImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageInfo->srcImage));
        }

        if(pCopyImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageInfo->dstImage));
        }
    }
}

void TrackDRCmdCopyBufferToImage2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyBufferToImageInfo != nullptr)
    {

        if(pCopyBufferToImageInfo->srcBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferToImageInfo->srcBuffer));
        }

        if(pCopyBufferToImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyBufferToImageInfo->dstImage));
        }
    }
}

void TrackDRCmdCopyImageToBuffer2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pCopyImageToBufferInfo != nullptr)
    {

        if(pCopyImageToBufferInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageToBufferInfo->srcImage));
        }

        if(pCopyImageToBufferInfo->dstBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCopyImageToBufferInfo->dstBuffer));
        }
    }
}

void TrackDRCmdBlitImage2KHRHandles(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pBlitImageInfo != nullptr)
    {

        if(pBlitImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pBlitImageInfo->srcImage));
        }

        if(pBlitImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pBlitImageInfo->dstImage));
        }
    }
}

void TrackDRCmdResolveImage2KHRHandles(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pResolveImageInfo != nullptr)
    {

        if(pResolveImageInfo->srcImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pResolveImageInfo->srcImage));
        }

        if(pResolveImageInfo->dstImage != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[ImageHandle].insert(reinterpret_cast<format::HandleId>(pResolveImageInfo->dstImage));
        }
    }
}

void TrackDRCmdBindIndexBuffer2KHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdBindTransformFeedbackBuffersEXTHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBuffers[pBuffers_index]));
            }
        }
    }
}

void TrackDRCmdBeginTransformFeedbackEXTHandles(VkCommandBuffer commandBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCounterBuffers[pCounterBuffers_index]));
            }
        }
    }
}

void TrackDRCmdEndTransformFeedbackEXTHandles(VkCommandBuffer commandBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t pCounterBuffers_index = 0; pCounterBuffers_index < counterBufferCount; ++pCounterBuffers_index)
        {
            if(pCounterBuffers[pCounterBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pCounterBuffers[pCounterBuffers_index]));
            }
        }
    }
}

void TrackDRCmdBeginQueryIndexedEXTHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdEndQueryIndexedEXTHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdDrawIndirectByteCountEXTHandles(VkCommandBuffer commandBuffer, VkBuffer counterBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(counterBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(counterBuffer));
    }
}

void TrackDRCmdDrawIndirectCountAMDHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdDrawIndexedIndirectCountAMDHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdBeginConditionalRenderingEXTHandles(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) //@@@DLO
{
    assert(commandBuffer);

    if (pConditionalRenderingBegin != nullptr)
    {

        if(pConditionalRenderingBegin->buffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pConditionalRenderingBegin->buffer));
        }
    }
}

void TrackDRCmdBindShadingRateImageNVHandles(VkCommandBuffer commandBuffer, VkImageView imageView) //@@@DLO
{
    assert(commandBuffer);

    if(imageView != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(imageView));
    }
}

void TrackDRCmdBuildAccelerationStructureNVHandles(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if (pInfo->pGeometries != nullptr)
        {
            for (uint32_t pGeometries_index = 0; pGeometries_index < pInfo->geometryCount; ++pGeometries_index)
            {



                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pInfo->pGeometries[pGeometries_index].geometry.triangles.vertexData));
                }

                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pInfo->pGeometries[pGeometries_index].geometry.triangles.indexData));
                }

                if(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pInfo->pGeometries[pGeometries_index].geometry.triangles.transformData));
                }


                if(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pInfo->pGeometries[pGeometries_index].geometry.aabbs.aabbData));
                }
            }
        }
    }

    if(instanceData != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(instanceData));
    }

    if(dst != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(dst));
    }

    if(src != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(src));
    }

    if(scratch != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(scratch));
    }
}

void TrackDRCmdCopyAccelerationStructureNVHandles(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src) //@@@DLO
{
    assert(commandBuffer);

    if(dst != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(dst));
    }

    if(src != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(src));
    }
}

void TrackDRCmdTraceRaysNVHandles(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(raygenShaderBindingTableBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(raygenShaderBindingTableBuffer));
    }

    if(missShaderBindingTableBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(missShaderBindingTableBuffer));
    }

    if(hitShaderBindingTableBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(hitShaderBindingTableBuffer));
    }

    if(callableShaderBindingTableBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(callableShaderBindingTableBuffer));
    }
}

void TrackDRCmdWriteAccelerationStructuresPropertiesNVHandles(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureNVHandle].insert(reinterpret_cast<format::HandleId>(pAccelerationStructures[pAccelerationStructures_index]));
            }
        }
    }

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdWriteBufferMarkerAMDHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(dstBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(dstBuffer));
    }
}

void TrackDRCmdDrawMeshTasksIndirectNVHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdDrawMeshTasksIndirectCountNVHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

void TrackDRCmdBindVertexBuffers2EXTHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers) //@@@DLO
{
    assert(commandBuffer);

    if (pBuffers != nullptr)
    {
        for (uint32_t pBuffers_index = 0; pBuffers_index < bindingCount; ++pBuffers_index)
        {
            if(pBuffers[pBuffers_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pBuffers[pBuffers_index]));
            }
        }
    }
}

void TrackDRCmdPreprocessGeneratedCommandsNVHandles(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pGeneratedCommandsInfo != nullptr)
    {

        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[PipelineHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->pipeline));
        }

        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[IndirectCommandsLayoutNVHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->indirectCommandsLayout));
        }


        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {

                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
                }
            }
        }

        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->preprocessBuffer));
        }

        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->sequencesCountBuffer));
        }

        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->sequencesIndexBuffer));
        }
    }
}

void TrackDRCmdExecuteGeneratedCommandsNVHandles(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pGeneratedCommandsInfo != nullptr)
    {

        if(pGeneratedCommandsInfo->pipeline != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[PipelineHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->pipeline));
        }

        if(pGeneratedCommandsInfo->indirectCommandsLayout != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[IndirectCommandsLayoutNVHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->indirectCommandsLayout));
        }


        if (pGeneratedCommandsInfo->pStreams != nullptr)
        {
            for (uint32_t pStreams_index = 0; pStreams_index < pGeneratedCommandsInfo->streamCount; ++pStreams_index)
            {

                if(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer != VK_NULL_HANDLE)
                {
                    handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->pStreams[pStreams_index].buffer));
                }
            }
        }

        if(pGeneratedCommandsInfo->preprocessBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->preprocessBuffer));
        }

        if(pGeneratedCommandsInfo->sequencesCountBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->sequencesCountBuffer));
        }

        if(pGeneratedCommandsInfo->sequencesIndexBuffer != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(pGeneratedCommandsInfo->sequencesIndexBuffer));
        }
    }
}

void TrackDRCmdBindPipelineShaderGroupNVHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline) //@@@DLO
{
    assert(commandBuffer);

    if(pipeline != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineHandle].insert(reinterpret_cast<format::HandleId>(pipeline));
    }
}

void TrackDRCmdBindInvocationMaskHUAWEIHandles(VkCommandBuffer commandBuffer, VkImageView imageView) //@@@DLO
{
    assert(commandBuffer);

    if(imageView != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[ImageViewHandle].insert(reinterpret_cast<format::HandleId>(imageView));
    }
}

void TrackDRCmdBuildMicromapsEXTHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) //@@@DLO
{
    assert(commandBuffer);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {

            if(pInfos[pInfos_index].dstMicromap != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pInfos[pInfos_index].dstMicromap));
            }
        }
    }
}

void TrackDRCmdCopyMicromapEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->src != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pInfo->src));
        }

        if(pInfo->dst != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pInfo->dst));
        }
    }
}

void TrackDRCmdCopyMicromapToMemoryEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->src != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pInfo->src));
        }
    }
}

void TrackDRCmdCopyMemoryToMicromapEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->dst != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pInfo->dst));
        }
    }
}

void TrackDRCmdWriteMicromapsPropertiesEXTHandles(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if (pMicromaps != nullptr)
    {
        for (uint32_t pMicromaps_index = 0; pMicromaps_index < micromapCount; ++pMicromaps_index)
        {
            if(pMicromaps[pMicromaps_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[MicromapEXTHandle].insert(reinterpret_cast<format::HandleId>(pMicromaps[pMicromaps_index]));
            }
        }
    }

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdDrawClusterIndirectHUAWEIHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdUpdatePipelineIndirectBufferNVHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline) //@@@DLO
{
    assert(commandBuffer);

    if(pipeline != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[PipelineHandle].insert(reinterpret_cast<format::HandleId>(pipeline));
    }
}

void TrackDRCmdOpticalFlowExecuteNVHandles(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session) //@@@DLO
{
    assert(commandBuffer);

    if(session != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[OpticalFlowSessionNVHandle].insert(reinterpret_cast<format::HandleId>(session));
    }
}

void TrackDRCmdBindShadersEXTHandles(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderEXT* pShaders) //@@@DLO
{
    assert(commandBuffer);

    if (pShaders != nullptr)
    {
        for (uint32_t pShaders_index = 0; pShaders_index < stageCount; ++pShaders_index)
        {
            if(pShaders[pShaders_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[ShaderEXTHandle].insert(reinterpret_cast<format::HandleId>(pShaders[pShaders_index]));
            }
        }
    }
}

void TrackDRCmdBuildAccelerationStructuresKHRHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos) //@@@DLO
{
    assert(commandBuffer);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {

            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfos[pInfos_index].srcAccelerationStructure));
            }

            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfos[pInfos_index].dstAccelerationStructure));
            }
        }
    }
}

void TrackDRCmdBuildAccelerationStructuresIndirectKHRHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos) //@@@DLO
{
    assert(commandBuffer);

    if (pInfos != nullptr)
    {
        for (uint32_t pInfos_index = 0; pInfos_index < infoCount; ++pInfos_index)
        {

            if(pInfos[pInfos_index].srcAccelerationStructure != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfos[pInfos_index].srcAccelerationStructure));
            }

            if(pInfos[pInfos_index].dstAccelerationStructure != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfos[pInfos_index].dstAccelerationStructure));
            }
        }
    }
}

void TrackDRCmdCopyAccelerationStructureKHRHandles(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->src != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfo->src));
        }

        if(pInfo->dst != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfo->dst));
        }
    }
}

void TrackDRCmdCopyAccelerationStructureToMemoryKHRHandles(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->src != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfo->src));
        }
    }
}

void TrackDRCmdCopyMemoryToAccelerationStructureKHRHandles(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) //@@@DLO
{
    assert(commandBuffer);

    if (pInfo != nullptr)
    {

        if(pInfo->dst != VK_NULL_HANDLE)
        {
            handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pInfo->dst));
        }
    }
}

void TrackDRCmdWriteAccelerationStructuresPropertiesKHRHandles(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool) //@@@DLO
{
    assert(commandBuffer);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t pAccelerationStructures_index = 0; pAccelerationStructures_index < accelerationStructureCount; ++pAccelerationStructures_index)
        {
            if(pAccelerationStructures[pAccelerationStructures_index] != VK_NULL_HANDLE)
            {
                handleset[commandBuffer].dr_command_handles[AccelerationStructureKHRHandle].insert(reinterpret_cast<format::HandleId>(pAccelerationStructures[pAccelerationStructures_index]));
            }
        }
    }

    if(queryPool != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[QueryPoolHandle].insert(reinterpret_cast<format::HandleId>(queryPool));
    }
}

void TrackDRCmdDrawMeshTasksIndirectEXTHandles(VkCommandBuffer commandBuffer, VkBuffer buffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }
}

void TrackDRCmdDrawMeshTasksIndirectCountEXTHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer) //@@@DLO
{
    assert(commandBuffer);

    if(buffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(buffer));
    }

    if(countBuffer != VK_NULL_HANDLE)
    {
        handleset[commandBuffer].dr_command_handles[BufferHandle].insert(reinterpret_cast<format::HandleId>(countBuffer));
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
