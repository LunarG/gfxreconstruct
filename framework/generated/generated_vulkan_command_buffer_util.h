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

void TrackCmdSetEvent2Handles(CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2Handles(CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2Handles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdPipelineBarrier2Handles(CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2Handles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdCopyBuffer2Handles(CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2Handles(CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2Handles(CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2Handles(CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdBlitImage2Handles(CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2Handles(CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBeginRenderingHandles(CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdBindVertexBuffers2Handles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdBeginVideoCodingKHRHandles(CommandBufferWrapper* wrapper, const VkVideoBeginCodingInfoKHR* pBeginInfo);

void TrackCmdDecodeVideoKHRHandles(CommandBufferWrapper* wrapper, const VkVideoDecodeInfoKHR* pDecodeInfo);

void TrackCmdBeginRenderingKHRHandles(CommandBufferWrapper* wrapper, const VkRenderingInfo* pRenderingInfo);

void TrackCmdPushDescriptorSetKHRHandles(CommandBufferWrapper* wrapper, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);

void TrackCmdBeginRenderPass2KHRHandles(CommandBufferWrapper* wrapper, const VkRenderPassBeginInfo* pRenderPassBegin);

void TrackCmdDrawIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdDrawIndexedIndirectCountKHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdEncodeVideoKHRHandles(CommandBufferWrapper* wrapper, const VkVideoEncodeInfoKHR* pEncodeInfo);

void TrackCmdSetEvent2KHRHandles(CommandBufferWrapper* wrapper, VkEvent event, const VkDependencyInfo* pDependencyInfo);

void TrackCmdResetEvent2KHRHandles(CommandBufferWrapper* wrapper, VkEvent event);

void TrackCmdWaitEvents2KHRHandles(CommandBufferWrapper* wrapper, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);

void TrackCmdPipelineBarrier2KHRHandles(CommandBufferWrapper* wrapper, const VkDependencyInfo* pDependencyInfo);

void TrackCmdWriteTimestamp2KHRHandles(CommandBufferWrapper* wrapper, VkQueryPool queryPool);

void TrackCmdWriteBufferMarker2AMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdCopyBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferInfo2* pCopyBufferInfo);

void TrackCmdCopyImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageInfo2* pCopyImageInfo);

void TrackCmdCopyBufferToImage2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);

void TrackCmdCopyImageToBuffer2KHRHandles(CommandBufferWrapper* wrapper, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);

void TrackCmdBlitImage2KHRHandles(CommandBufferWrapper* wrapper, const VkBlitImageInfo2* pBlitImageInfo);

void TrackCmdResolveImage2KHRHandles(CommandBufferWrapper* wrapper, const VkResolveImageInfo2* pResolveImageInfo);

void TrackCmdBindIndexBuffer2KHRHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

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

void TrackCmdBuildAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch);

void TrackCmdCopyAccelerationStructureNVHandles(CommandBufferWrapper* wrapper, VkAccelerationStructureNV dst, VkAccelerationStructureNV src);

void TrackCmdTraceRaysNVHandles(CommandBufferWrapper* wrapper, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer);

void TrackCmdWriteAccelerationStructuresPropertiesNVHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdWriteBufferMarkerAMDHandles(CommandBufferWrapper* wrapper, VkBuffer dstBuffer);

void TrackCmdDrawMeshTasksIndirectNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountNVHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

void TrackCmdBindVertexBuffers2EXTHandles(CommandBufferWrapper* wrapper, uint32_t bindingCount, const VkBuffer* pBuffers);

void TrackCmdPreprocessGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdExecuteGeneratedCommandsNVHandles(CommandBufferWrapper* wrapper, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);

void TrackCmdBindPipelineShaderGroupNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdBindInvocationMaskHUAWEIHandles(CommandBufferWrapper* wrapper, VkImageView imageView);

void TrackCmdBuildMicromapsEXTHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);

void TrackCmdCopyMicromapEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMicromapInfoEXT* pInfo);

void TrackCmdCopyMicromapToMemoryEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMicromapToMemoryInfoEXT* pInfo);

void TrackCmdCopyMemoryToMicromapEXTHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToMicromapInfoEXT* pInfo);

void TrackCmdWriteMicromapsPropertiesEXTHandles(CommandBufferWrapper* wrapper, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool);

void TrackCmdDrawClusterIndirectHUAWEIHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdUpdatePipelineIndirectBufferNVHandles(CommandBufferWrapper* wrapper, VkPipeline pipeline);

void TrackCmdOpticalFlowExecuteNVHandles(CommandBufferWrapper* wrapper, VkOpticalFlowSessionNV session);

void TrackCmdBindShadersEXTHandles(CommandBufferWrapper* wrapper, uint32_t stageCount, const VkShaderEXT* pShaders);

void TrackCmdBuildAccelerationStructuresKHRHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdBuildAccelerationStructuresIndirectKHRHandles(CommandBufferWrapper* wrapper, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);

void TrackCmdCopyAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureInfoKHR* pInfo);

void TrackCmdCopyAccelerationStructureToMemoryKHRHandles(CommandBufferWrapper* wrapper, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);

void TrackCmdCopyMemoryToAccelerationStructureKHRHandles(CommandBufferWrapper* wrapper, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);

void TrackCmdWriteAccelerationStructuresPropertiesKHRHandles(CommandBufferWrapper* wrapper, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);

void TrackCmdDrawMeshTasksIndirectEXTHandles(CommandBufferWrapper* wrapper, VkBuffer buffer);

void TrackCmdDrawMeshTasksIndirectCountEXTHandles(CommandBufferWrapper* wrapper, VkBuffer buffer, VkBuffer countBuffer);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
