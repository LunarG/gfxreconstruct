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

void TrackBeginCommandBufferHandles(VulkanCommandBufferWrapper* wrapper, const VkCommandBufferBeginInfo* pBeginInfo);

void TrackCmdBindPipelineHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindDescriptorSetsHandles(VulkanCommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);

void TrackCmdBindIndexBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBindVertexBuffersHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdDrawIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawIndexedIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDispatchIndirectHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdCopyBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkBuffer dstBuffer);

void TrackCmdCopyImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdBlitImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdCopyBufferToImageHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer srcBuffer, VkImage dstImage);

void TrackCmdCopyImageToBufferHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkBuffer dstBuffer);

void TrackCmdUpdateBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdFillBufferHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdClearColorImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage image);

void TrackCmdClearDepthStencilImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage image);

void TrackCmdResolveImageHandles(VulkanCommandBufferWrapper* wrapper, VkImage srcImage, VkImage dstImage);

void TrackCmdSetEventHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdResetEventHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEventsHandles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdPipelineBarrierHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);

void TrackCmdBeginQueryHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdResetQueryPoolHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdWriteTimestampHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyQueryPoolResultsHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool, VkBuffer dstBuffer);

void TrackCmdPushConstantsHandles(VulkanCommandBufferWrapper* wrapper, VkPipelineLayout layout);

void TrackCmdBeginRenderPassHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdExecuteCommandsHandles(VulkanCommandBufferWrapper* wrapper, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);

void TrackCmdDrawIndirectCountHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginRenderPass2Handles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdSetEvent2Handles(VulkanCommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2Handles(VulkanCommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2Handles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdPipelineBarrier2Handles(VulkanCommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2Handles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyBuffer2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2Handles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdBlitImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2Handles(VulkanCommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBeginRenderingHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdBindVertexBuffers2Handles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdBeginVideoCodingKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo);

void TrackCmdDecodeVideoKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo);

void TrackCmdBeginRenderingKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdPushDescriptorSetKHRHandles(VulkanCommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

void TrackCmdBeginRenderPass2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdDrawIndirectCountKHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountKHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdEncodeVideoKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo);

void TrackCmdSetEvent2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2KHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdPipelineBarrier2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdWriteBufferMarker2AMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdCopyBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdBlitImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBindIndexBuffer2KHRHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdBindDescriptorSets2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo);

void TrackCmdPushConstants2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushConstantsInfoKHR* pPushConstantsInfo);

void TrackCmdPushDescriptorSet2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushDescriptorSetInfoKHR* pPushDescriptorSetInfo);

void TrackCmdPushDescriptorSetWithTemplate2KHRHandles(VulkanCommandBufferWrapper* wrapper, const VkPushDescriptorSetWithTemplateInfoKHR* pPushDescriptorSetWithTemplateInfo);

void TrackCmdSetDescriptorBufferOffsets2EXTHandles(VulkanCommandBufferWrapper* wrapper, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo);

void TrackCmdBindDescriptorBufferEmbeddedSamplers2EXTHandles(VulkanCommandBufferWrapper* wrapper, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo);

void TrackCmdBindTransformFeedbackBuffersEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdBeginTransformFeedbackEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdEndTransformFeedbackEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);

void TrackCmdBeginQueryIndexedEXTHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdEndQueryIndexedEXTHandles(VulkanCommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdDrawIndirectByteCountEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer counterBuffer);

void TrackCmdDrawIndirectCountAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBeginConditionalRenderingEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);

void TrackCmdBindShadingRateImageNVHandles(VulkanCommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildAccelerationStructureNVHandles(VulkanCommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch);

void TrackCmdCopyAccelerationStructureNVHandles(VulkanCommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src);

void TrackCmdTraceRaysNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer);

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(VulkanCommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdWriteBufferMarkerAMDHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdDrawMeshTasksIndirectNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountNVHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBindVertexBuffers2EXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdPreprocessGeneratedCommandsNVHandles(VulkanCommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdExecuteGeneratedCommandsNVHandles(VulkanCommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdBindPipelineShaderGroupNVHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindInvocationMaskHUAWEIHandles(VulkanCommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildMicromapsEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

void TrackCmdCopyMicromapEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo);

void TrackCmdCopyMicromapToMemoryEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo);

void TrackCmdCopyMemoryToMicromapEXTHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo);

void TrackCmdWriteMicromapsPropertiesEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool);

void TrackCmdDrawClusterIndirectHUAWEIHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdUpdatePipelineIndirectBufferNVHandles(VulkanCommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdOpticalFlowExecuteNVHandles(VulkanCommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session);

void TrackCmdBindShadersEXTHandles(VulkanCommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders);

void TrackCmdBuildAccelerationStructuresKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdCopyAccelerationStructureKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo);

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(VulkanCommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(VulkanCommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdDrawMeshTasksIndirectEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(VulkanCommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
