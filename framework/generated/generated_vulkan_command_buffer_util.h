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

#ifndef  GFXRECON_GENERATED_VULKAN_COMMAND_BUFFER_UTIL_H
#define  GFXRECON_GENERATED_VULKAN_COMMAND_BUFFER_UTIL_H

#include "encode/vulkan_handle_wrappers.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void TrackBeginCommandBufferHandles(CommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo);

void TrackCmdBindPipelineHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindDescriptorSetsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);

void TrackCmdBindIndexBufferHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBindVertexBuffersHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdDrawIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawIndexedIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDispatchIndirectHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdCopyBufferHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer);

void TrackCmdCopyImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdBlitImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdCopyBufferToImageHandles(CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage);

void TrackCmdCopyImageToBufferHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer);

void TrackCmdUpdateBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdFillBufferHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdClearColorImageHandles(CommandBufferWrapper* wrapper, VkImage image);

void TrackCmdClearDepthStencilImageHandles(CommandBufferWrapper* wrapper, VkImage image);

void TrackCmdResolveImageHandles(CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdSetEventHandles(CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdResetEventHandles(CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEventsHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdPipelineBarrierHandles(CommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdBeginQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdResetQueryPoolHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdWriteTimestampHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyQueryPoolResultsHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer);

void TrackCmdPushConstantsHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout);

void TrackCmdBeginRenderPassHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdExecuteCommandsHandles(CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

void TrackCmdDrawIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginRenderPass2Handles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdPushDescriptorSetKHRHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

void TrackCmdBeginRenderPass2KHRHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdDrawIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBindTransformFeedbackBuffersEXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdBeginTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdEndTransformFeedbackEXTHandles(CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdBeginQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryIndexedEXTHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdDrawIndirectByteCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer counterBuffer);

void TrackCmdDrawIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountAMDHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginConditionalRenderingEXTHandles(CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

void TrackCmdBindShadingRateImageNVHandles(CommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureKHR dst, VkAccelerationStructureKHR src, VkBuffer scratch);

void TrackCmdCopyAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, VkAccelerationStructureKHR dst, VkAccelerationStructureKHR src);

void TrackCmdTraceRaysNVHandles(CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer);

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdWriteBufferMarkerAMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdDrawMeshTasksIndirectNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBindVertexBuffers2EXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdPreprocessGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdExecuteGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdBindPipelineShaderGroupNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBuildAccelerationStructureIndirectKHRHandles(CommandBufferWrapper* wrapper, const VkAccelerationStructureBuildGeometryInfoKHR* pInfo, VkBuffer indirectBuffer);

void TrackCmdCopyAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo);

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void TrackCmdTraceRaysKHRHandles(CommandBufferWrapper* wrapper, const VkStridedBufferRegionKHR* pRaygenShaderBindingTable, const VkStridedBufferRegionKHR* pMissShaderBindingTable, const VkStridedBufferRegionKHR* pHitShaderBindingTable, const VkStridedBufferRegionKHR* pCallableShaderBindingTable);

void TrackCmdTraceRaysIndirectKHRHandles(CommandBufferWrapper* wrapper, const VkStridedBufferRegionKHR* pRaygenShaderBindingTable, const VkStridedBufferRegionKHR* pMissShaderBindingTable, const VkStridedBufferRegionKHR* pHitShaderBindingTable, const VkStridedBufferRegionKHR* pCallableShaderBindingTable, VkBuffer buffer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
