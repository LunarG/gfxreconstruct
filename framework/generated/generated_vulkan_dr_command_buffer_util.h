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

#ifndef  GFXRECON_GENERATED_VULKAN_DR_COMMAND_BUFFER_UTIL_H
#define  GFXRECON_GENERATED_VULKAN_DR_COMMAND_BUFFER_UTIL_H

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
GFXRECON_BEGIN_NAMESPACE(decode)

//@@@Debug: return_type = VkResult
//@@@Debug: return_type = void

void TrackDRCmdBindPipelineHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: cmd= vkCmdSetBlendConstants
//@@@Debug: info[0]=void
//@@@Debug: info[1]=VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants
//@@@Debug: i=0
//@@@Debug: info[2][i].name=commandBuffer
//@@@Debug: info[2][i].base_type=VkCommandBuffer
//@@@Debug: info[2][i].full_type=VkCommandBuffer
//@@@Debug: info[2][i].pointer_count=0
//@@@Debug: info[2][i].array_length=None
//@@@Debug: info[2][i].array_capacity=None
//@@@Debug: info[2][i].array_dimension=0
//@@@Debug: info[2][i].platform_base_type=None
//@@@Debug: info[2][i].is_pointer=False
//@@@Debug: info[2][i].is_array=False
//@@@Debug: info[2][i].is_dynamic=True
//@@@Debug: info[2][i].is_const=False
//@@@Debug: i=1
//@@@Debug: info[2][i].name=blendConstants
//@@@Debug: info[2][i].base_type=float
//@@@Debug: info[2][i].full_type=const float
//@@@Debug: info[2][i].pointer_count=0
//@@@Debug: info[2][i].array_length=4
//@@@Debug: info[2][i].array_capacity=4
//@@@Debug: info[2][i].array_dimension=1
//@@@Debug: info[2][i].platform_base_type=None
//@@@Debug: info[2][i].is_pointer=False
//@@@Debug: info[2][i].is_array=True
//@@@Debug: info[2][i].is_dynamic=False
//@@@Debug: info[2][i].is_const=False
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindDescriptorSetsHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets);
//@@@Debug: return_type = void

void TrackDRCmdBindIndexBufferHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdBindVertexBuffersHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndexedIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDispatchIndirectHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdCopyBufferHandles(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdCopyImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage);
//@@@Debug: return_type = void

void TrackDRCmdBlitImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage);
//@@@Debug: return_type = void

void TrackDRCmdCopyBufferToImageHandles(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage);
//@@@Debug: return_type = void

void TrackDRCmdCopyImageToBufferHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdUpdateBufferHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdFillBufferHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdClearColorImageHandles(VkCommandBuffer commandBuffer, VkImage image);
//@@@Debug: return_type = void

void TrackDRCmdClearDepthStencilImageHandles(VkCommandBuffer commandBuffer, VkImage image);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdResolveImageHandles(VkCommandBuffer commandBuffer, VkImage srcImage, VkImage dstImage);
//@@@Debug: return_type = void

void TrackDRCmdSetEventHandles(VkCommandBuffer commandBuffer, VkEvent event);
//@@@Debug: return_type = void

void TrackDRCmdResetEventHandles(VkCommandBuffer commandBuffer, VkEvent event);
//@@@Debug: return_type = void

void TrackDRCmdWaitEventsHandles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
//@@@Debug: return_type = void

void TrackDRCmdPipelineBarrierHandles(VkCommandBuffer commandBuffer, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers);
//@@@Debug: return_type = void

void TrackDRCmdBeginQueryHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdEndQueryHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdResetQueryPoolHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdWriteTimestampHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdCopyQueryPoolResultsHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdPushConstantsHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout);
//@@@Debug: return_type = void

void TrackDRCmdBeginRenderPassHandles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdExecuteCommandsHandles(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawIndirectCountHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndexedIndirectCountHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void

void TrackDRCmdBeginRenderPass2Handles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdSetEvent2Handles(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
//@@@Debug: return_type = void

void TrackDRCmdResetEvent2Handles(VkCommandBuffer commandBuffer, VkEvent event);
//@@@Debug: return_type = void

void TrackDRCmdWaitEvents2Handles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
//@@@Debug: return_type = void

void TrackDRCmdPipelineBarrier2Handles(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
//@@@Debug: return_type = void

void TrackDRCmdWriteTimestamp2Handles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdCopyBuffer2Handles(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyImage2Handles(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyBufferToImage2Handles(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyImageToBuffer2Handles(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
//@@@Debug: return_type = void

void TrackDRCmdBlitImage2Handles(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdResolveImage2Handles(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdBeginRenderingHandles(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindVertexBuffers2Handles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBeginVideoCodingKHRHandles(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDecodeVideoKHRHandles(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo);
//@@@Debug: return_type = void

void TrackDRCmdBeginRenderingKHRHandles(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdPushDescriptorSetKHRHandles(VkCommandBuffer commandBuffer, VkPipelineLayout layout, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites);
//@@@Debug: return_type = void

void TrackDRCmdBeginRenderPass2KHRHandles(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawIndirectCountKHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndexedIndirectCountKHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdEncodeVideoKHRHandles(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo);
//@@@Debug: return_type = void

void TrackDRCmdSetEvent2KHRHandles(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo);
//@@@Debug: return_type = void

void TrackDRCmdResetEvent2KHRHandles(VkCommandBuffer commandBuffer, VkEvent event);
//@@@Debug: return_type = void

void TrackDRCmdWaitEvents2KHRHandles(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos);
//@@@Debug: return_type = void

void TrackDRCmdPipelineBarrier2KHRHandles(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo);
//@@@Debug: return_type = void

void TrackDRCmdWriteTimestamp2KHRHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdWriteBufferMarker2AMDHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer);
//@@@Debug: return_type = void

void TrackDRCmdCopyBuffer2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyImage2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyBufferToImage2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyImageToBuffer2KHRHandles(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo);
//@@@Debug: return_type = void

void TrackDRCmdBlitImage2KHRHandles(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo);
//@@@Debug: return_type = void

void TrackDRCmdResolveImage2KHRHandles(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindIndexBuffer2KHRHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindTransformFeedbackBuffersEXTHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers);
//@@@Debug: return_type = void

void TrackDRCmdBeginTransformFeedbackEXTHandles(VkCommandBuffer commandBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);
//@@@Debug: return_type = void

void TrackDRCmdEndTransformFeedbackEXTHandles(VkCommandBuffer commandBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers);
//@@@Debug: return_type = void

void TrackDRCmdBeginQueryIndexedEXTHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdEndQueryIndexedEXTHandles(VkCommandBuffer commandBuffer, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndirectByteCountEXTHandles(VkCommandBuffer commandBuffer, VkBuffer counterBuffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndirectCountAMDHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawIndexedIndirectCountAMDHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void

void TrackDRCmdBeginConditionalRenderingEXTHandles(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindShadingRateImageNVHandles(VkCommandBuffer commandBuffer, VkImageView imageView);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBuildAccelerationStructureNVHandles(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch);
//@@@Debug: return_type = void

void TrackDRCmdCopyAccelerationStructureNVHandles(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src);
//@@@Debug: return_type = void

void TrackDRCmdTraceRaysNVHandles(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkBuffer missShaderBindingTableBuffer, VkBuffer hitShaderBindingTableBuffer, VkBuffer callableShaderBindingTableBuffer);
//@@@Debug: return_type = void

void TrackDRCmdWriteAccelerationStructuresPropertiesNVHandles(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryPool queryPool);
//@@@Debug: return_type = void

void TrackDRCmdWriteBufferMarkerAMDHandles(VkCommandBuffer commandBuffer, VkBuffer dstBuffer);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawMeshTasksIndirectNVHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawMeshTasksIndirectCountNVHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = VkResult
//@@@Debug: return_type = VkResult
//@@@Debug: return_type = VkResult
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindVertexBuffers2EXTHandles(VkCommandBuffer commandBuffer, uint32_t bindingCount, const VkBuffer* pBuffers);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdPreprocessGeneratedCommandsNVHandles(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
//@@@Debug: return_type = void

void TrackDRCmdExecuteGeneratedCommandsNVHandles(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo);
//@@@Debug: return_type = void

void TrackDRCmdBindPipelineShaderGroupNVHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBindInvocationMaskHUAWEIHandles(VkCommandBuffer commandBuffer, VkImageView imageView);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBuildMicromapsEXTHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos);
//@@@Debug: return_type = void

void TrackDRCmdCopyMicromapEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyMicromapToMemoryEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyMemoryToMicromapEXTHandles(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdWriteMicromapsPropertiesEXTHandles(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryPool queryPool);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawClusterIndirectHUAWEIHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdUpdatePipelineIndirectBufferNVHandles(VkCommandBuffer commandBuffer, VkPipeline pipeline);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdOpticalFlowExecuteNVHandles(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session);
//@@@Debug: return_type = void

void TrackDRCmdBindShadersEXTHandles(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderEXT* pShaders);
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdBuildAccelerationStructuresKHRHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);
//@@@Debug: return_type = void

void TrackDRCmdBuildAccelerationStructuresIndirectKHRHandles(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos);
//@@@Debug: return_type = void

void TrackDRCmdCopyAccelerationStructureKHRHandles(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyAccelerationStructureToMemoryKHRHandles(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdCopyMemoryToAccelerationStructureKHRHandles(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo);
//@@@Debug: return_type = void

void TrackDRCmdWriteAccelerationStructuresPropertiesKHRHandles(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryPool queryPool);
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void
//@@@Debug: return_type = void

void TrackDRCmdDrawMeshTasksIndirectEXTHandles(VkCommandBuffer commandBuffer, VkBuffer buffer);
//@@@Debug: return_type = void

void TrackDRCmdDrawMeshTasksIndirectCountEXTHandles(VkCommandBuffer commandBuffer, VkBuffer buffer, VkBuffer countBuffer);
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
