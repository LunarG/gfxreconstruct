/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include "generated/generated_vulkan_command_buffer_util.h"

#include "format/format.h"
#include "format/format_util.h"
#include "encode/vulkan_state_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void TrackBeginCommandBufferHandles(CommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo)
{
    assert(wrapper != nullptr);

    if (pBeginInfo != nullptr)
    {
    }
}

void TrackCmdBindPipelineHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineHandle].insert(format::ToHandleId(pipeline));
}

void TrackCmdBindDescriptorSetsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(format::ToHandleId(layout));

    if (pDescriptorSets != nullptr)
    {
        for (uint32_t i = 0; i < descriptorSetCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(format::ToHandleId(pDescriptorSets[i]));
        }
    }
}

void TrackCmdBindIndexBufferHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
}

void TrackCmdBindVertexBuffersHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pBuffers[i]));
        }
    }
}

void TrackCmdDrawIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
}

void TrackCmdDrawIndexedIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
}

void TrackCmdDispatchIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
}

void TrackCmdCopyBufferHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(srcBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdCopyImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(dstImage));
}

void TrackCmdBlitImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(dstImage));
}

void TrackCmdCopyBufferToImageHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(srcBuffer));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(dstImage));
}

void TrackCmdCopyImageToBufferHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(srcImage));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdUpdateBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdFillBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdClearColorImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(image));
}

void TrackCmdClearDepthStencilImageHandles(CommandBufferWrapper* wrapper, VkImage image)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(image));
}

void TrackCmdResolveImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(srcImage));
    wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(dstImage));
}

void TrackCmdSetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::EventHandle].insert(format::ToHandleId(event));
}

void TrackCmdResetEventHandles(CommandBufferWrapper* wrapper, VkEvent event)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::EventHandle].insert(format::ToHandleId(event));
}

void TrackCmdWaitEventsHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pEvents != nullptr)
    {
        for (uint32_t i = 0; i < eventCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::EventHandle].insert(format::ToHandleId(pEvents[i]));
        }
    }

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t i = 0; i < bufferMemoryBarrierCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pBufferMemoryBarriers[i].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t i = 0; i < imageMemoryBarrierCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(pImageMemoryBarriers[i].image));
        }
    }
}

void TrackCmdPipelineBarrierHandles(CommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers)
{
    assert(wrapper != nullptr);

    if (pBufferMemoryBarriers != nullptr)
    {
        for (uint32_t i = 0; i < bufferMemoryBarrierCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pBufferMemoryBarriers[i].buffer));
        }
    }

    if (pImageMemoryBarriers != nullptr)
    {
        for (uint32_t i = 0; i < imageMemoryBarrierCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::ImageHandle].insert(format::ToHandleId(pImageMemoryBarriers[i].image));
        }
    }
}

void TrackCmdBeginQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdEndQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdResetQueryPoolHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdWriteTimestampHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdCopyQueryPoolResultsHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdPushConstantsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(format::ToHandleId(layout));
}

void TrackCmdBeginRenderPassHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
{
    assert(wrapper != nullptr);

    if (pRenderPassBegin != nullptr)
    {
        wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(format::ToHandleId((*pRenderPassBegin).renderPass));
        wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(format::ToHandleId((*pRenderPassBegin).framebuffer));
    }
}

void TrackCmdExecuteCommandsHandles(CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers)
{
    assert(wrapper != nullptr);

    if (pCommandBuffers != nullptr)
    {
        for (uint32_t i = 0; i < commandBufferCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::CommandBufferHandle].insert(format::ToHandleId(pCommandBuffers[i]));
        }
    }
}

void TrackCmdPushDescriptorSetKHRHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::PipelineLayoutHandle].insert(format::ToHandleId(layout));

    if (pDescriptorWrites != nullptr)
    {
        for (uint32_t i = 0; i < descriptorWriteCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::DescriptorSetHandle].insert(format::ToHandleId(pDescriptorWrites[i].dstSet));
        }
    }
}

void TrackCmdBeginRenderPass2KHRHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin)
{
    assert(wrapper != nullptr);

    if (pRenderPassBegin != nullptr)
    {
        wrapper->command_handles[CommandHandleType::RenderPassHandle].insert(format::ToHandleId((*pRenderPassBegin).renderPass));
        wrapper->command_handles[CommandHandleType::FramebufferHandle].insert(format::ToHandleId((*pRenderPassBegin).framebuffer));
    }
}

void TrackCmdDrawIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(countBuffer));
}

void TrackCmdBindTransformFeedbackBuffersEXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers)
{
    assert(wrapper != nullptr);

    if (pBuffers != nullptr)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pBuffers[i]));
        }
    }
}

void TrackCmdBeginTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t i = 0; i < counterBufferCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pCounterBuffers[i]));
        }
    }
}

void TrackCmdEndTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers)
{
    assert(wrapper != nullptr);

    if (pCounterBuffers != nullptr)
    {
        for (uint32_t i = 0; i < counterBufferCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(pCounterBuffers[i]));
        }
    }
}

void TrackCmdBeginQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdEndQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdDrawIndirectByteCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer counterBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(counterBuffer));
}

void TrackCmdDrawIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(countBuffer));
}

void TrackCmdDrawIndexedIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(countBuffer));
}

void TrackCmdBeginConditionalRenderingEXTHandles(CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin)
{
    assert(wrapper != nullptr);

    if (pConditionalRenderingBegin != nullptr)
    {
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId((*pConditionalRenderingBegin).buffer));
    }
}

void TrackCmdProcessCommandsNVXHandles(CommandBufferWrapper* wrapper, const VkCmdProcessCommandsInfoNVX* pProcessCommandsInfo)
{
    assert(wrapper != nullptr);

    if (pProcessCommandsInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ObjectTableNVXHandle].insert(format::ToHandleId((*pProcessCommandsInfo).objectTable));
        wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVXHandle].insert(format::ToHandleId((*pProcessCommandsInfo).indirectCommandsLayout));
        wrapper->command_handles[CommandHandleType::CommandBufferHandle].insert(format::ToHandleId((*pProcessCommandsInfo).targetCommandBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId((*pProcessCommandsInfo).sequencesCountBuffer));
        wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId((*pProcessCommandsInfo).sequencesIndexBuffer));
    }
}

void TrackCmdReserveSpaceForCommandsNVXHandles(CommandBufferWrapper* wrapper, const VkCmdReserveSpaceForCommandsInfoNVX* pReserveSpaceInfo)
{
    assert(wrapper != nullptr);

    if (pReserveSpaceInfo != nullptr)
    {
        wrapper->command_handles[CommandHandleType::ObjectTableNVXHandle].insert(format::ToHandleId((*pReserveSpaceInfo).objectTable));
        wrapper->command_handles[CommandHandleType::IndirectCommandsLayoutNVXHandle].insert(format::ToHandleId((*pReserveSpaceInfo).indirectCommandsLayout));
    }
}

void TrackCmdBindShadingRateImageNVHandles(CommandBufferWrapper* wrapper, VkImageView imageView)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::ImageViewHandle].insert(format::ToHandleId(imageView));
}

void TrackCmdBuildAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch)
{
    assert(wrapper != nullptr);

    if (pInfo != nullptr)
    {
    }
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(instanceData));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(format::ToHandleId(dst));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(format::ToHandleId(src));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(scratch));
}

void TrackCmdCopyAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(format::ToHandleId(dst));
    wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(format::ToHandleId(src));
}

void TrackCmdTraceRaysNVHandles(CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(raygenShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(missShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(hitShaderBindingTableBuffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(callableShaderBindingTableBuffer));
}

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool)
{
    assert(wrapper != nullptr);

    if (pAccelerationStructures != nullptr)
    {
        for (uint32_t i = 0; i < accelerationStructureCount; ++i)
        {
            wrapper->command_handles[CommandHandleType::AccelerationStructureNVHandle].insert(format::ToHandleId(pAccelerationStructures[i]));
        }
    }
    wrapper->command_handles[CommandHandleType::QueryPoolHandle].insert(format::ToHandleId(queryPool));
}

void TrackCmdWriteBufferMarkerAMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(dstBuffer));
}

void TrackCmdDrawMeshTasksIndirectNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
}

void TrackCmdDrawMeshTasksIndirectCountNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer)
{
    assert(wrapper != nullptr);

    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(buffer));
    wrapper->command_handles[CommandHandleType::BufferHandle].insert(format::ToHandleId(countBuffer));
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
