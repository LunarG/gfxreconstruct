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

#ifndef  GFXRECON_GENERATED_VULKAN_COMMAND_BUFFER_UTIL_H
#define  GFXRECON_GENERATED_VULKAN_COMMAND_BUFFER_UTIL_H

#include "encode/vulkan_handle_wrappers.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void TrackBeginCommandBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo);

void TrackCmdCopyBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer);

void TrackCmdCopyImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdCopyBufferToImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage);

void TrackCmdCopyImageToBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer);

void TrackCmdUpdateBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdFillBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdPipelineBarrierHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdBeginQueryHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdResetQueryPoolHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdWriteTimestampHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyQueryPoolResultsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer);

void TrackCmdExecuteCommandsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

void TrackCmdBindPipelineHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindDescriptorSetsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);

void TrackCmdClearColorImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage image);

void TrackCmdDispatchIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdSetEventHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdResetEventHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEventsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdPushConstantsHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout);

void TrackCmdBindIndexBufferHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBindVertexBuffersHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdDrawIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawIndexedIndirectHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBlitImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdClearDepthStencilImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage image);

void TrackCmdResolveImageHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdBeginRenderPassHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdDrawIndirectCountHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginRenderPass2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdPipelineBarrier2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyBuffer2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdSetEvent2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdBlitImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBeginRenderingHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdBindVertexBuffers2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdPushDescriptorSetHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

void TrackCmdBindDescriptorSets2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo);

void TrackCmdPushConstants2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushConstantsInfo* pPushConstantsInfo);

void TrackCmdPushDescriptorSet2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo);

void TrackCmdBindIndexBuffer2Handles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBeginVideoCodingKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo);

void TrackCmdDecodeVideoKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo);

void TrackCmdBeginRenderingKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdPushDescriptorSetKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

void TrackCmdBeginRenderPass2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdDrawIndirectCountKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdEncodeVideoKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo);

void TrackCmdSetEvent2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdPipelineBarrier2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdBlitImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBindIndexBuffer2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBindDescriptorSets2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo);

void TrackCmdPushConstants2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushConstantsInfo* pPushConstantsInfo);

void TrackCmdPushDescriptorSet2KHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo);

void TrackCmdSetDescriptorBufferOffsets2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

void TrackCmdBindDescriptorBufferEmbeddedSamplers2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

void TrackCmdCopyMemoryToImageIndirectKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo);

void TrackCmdBindTransformFeedbackBuffersEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdBeginTransformFeedbackEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdEndTransformFeedbackEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdBeginQueryIndexedEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryIndexedEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdDrawIndirectByteCountEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer counterBuffer);

void TrackCmdDrawIndirectCountAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginConditionalRenderingEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

void TrackCmdBindShadingRateImageNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildAccelerationStructureNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch);

void TrackCmdCopyAccelerationStructureNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src);

void TrackCmdTraceRaysNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer);

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdWriteBufferMarkerAMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdWriteBufferMarker2AMDHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdDrawMeshTasksIndirectNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBindVertexBuffers2EXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdPreprocessGeneratedCommandsNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdExecuteGeneratedCommandsNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdBindPipelineShaderGroupNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindInvocationMaskHUAWEIHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildMicromapsEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

void TrackCmdCopyMicromapEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo);

void TrackCmdCopyMicromapToMemoryEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo);

void TrackCmdCopyMemoryToMicromapEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo);

void TrackCmdWriteMicromapsPropertiesEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool);

void TrackCmdDrawClusterIndirectHUAWEIHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdUpdatePipelineIndirectBufferNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdOpticalFlowExecuteNVHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session);

void TrackCmdBindShadersEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders);

void TrackCmdBindTileMemoryQCOMHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo);

void TrackCmdPreprocessGeneratedCommandsEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer);

void TrackCmdExecuteGeneratedCommandsEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo);

void TrackCmdBuildAccelerationStructuresKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdCopyAccelerationStructureKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo);

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdDrawMeshTasksIndirectEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(vulkan_wrappers::CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_COMMAND_BUFFER_UTIL_H
