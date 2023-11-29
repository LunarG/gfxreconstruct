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

#ifndef  GFXRECON_GENERATED_VULKAN_ENUM_TO_STRING_H
#define  GFXRECON_GENERATED_VULKAN_ENUM_TO_STRING_H

#include "format/platform_types.h"
#include "util/to_string.h"
#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
std::string ToString(const StdVideoDecodeH264FieldOrderCount& value);
std::string ToString(const StdVideoH264AspectRatioIdc& value);
std::string ToString(const StdVideoH264CabacInitIdc& value);
std::string ToString(const StdVideoH264ChromaFormatIdc& value);
std::string ToString(const StdVideoH264DisableDeblockingFilterIdc& value);
std::string ToString(const StdVideoH264LevelIdc& value);
std::string ToString(const StdVideoH264MemMgmtControlOp& value);
std::string ToString(const StdVideoH264ModificationOfPicNumsIdc& value);
std::string ToString(const StdVideoH264NonVclNaluType& value);
std::string ToString(const StdVideoH264PictureType& value);
std::string ToString(const StdVideoH264PocType& value);
std::string ToString(const StdVideoH264ProfileIdc& value);
std::string ToString(const StdVideoH264SliceType& value);
std::string ToString(const StdVideoH264WeightedBipredIdc& value);
std::string ToString(const StdVideoH265AspectRatioIdc& value);
std::string ToString(const StdVideoH265ChromaFormatIdc& value);
std::string ToString(const StdVideoH265LevelIdc& value);
std::string ToString(const StdVideoH265PictureType& value);
std::string ToString(const StdVideoH265ProfileIdc& value);
std::string ToString(const StdVideoH265SliceType& value);
std::string ToString(const VkAccessFlagBits& value);
std::string VkAccessFlagsToString(VkFlags vkFlags);
std::string ToString(const VkAttachmentDescriptionFlagBits& value);
std::string VkAttachmentDescriptionFlagsToString(VkFlags vkFlags);
std::string ToString(const VkAttachmentLoadOp& value);
std::string ToString(const VkAttachmentStoreOp& value);
std::string ToString(const VkBlendFactor& value);
std::string ToString(const VkBlendOp& value);
std::string ToString(const VkBorderColor& value);
std::string ToString(const VkBufferCreateFlagBits& value);
std::string VkBufferCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkBufferUsageFlagBits& value);
std::string VkBufferUsageFlagsToString(VkFlags vkFlags);
std::string ToString(const VkColorComponentFlagBits& value);
std::string VkColorComponentFlagsToString(VkFlags vkFlags);
std::string ToString(const VkCommandBufferLevel& value);
std::string ToString(const VkCommandBufferResetFlagBits& value);
std::string VkCommandBufferResetFlagsToString(VkFlags vkFlags);
std::string ToString(const VkCommandBufferUsageFlagBits& value);
std::string VkCommandBufferUsageFlagsToString(VkFlags vkFlags);
std::string ToString(const VkCommandPoolCreateFlagBits& value);
std::string VkCommandPoolCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkCommandPoolResetFlagBits& value);
std::string VkCommandPoolResetFlagsToString(VkFlags vkFlags);
std::string ToString(const VkCompareOp& value);
std::string ToString(const VkComponentSwizzle& value);
std::string ToString(const VkCullModeFlagBits& value);
std::string VkCullModeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDependencyFlagBits& value);
std::string VkDependencyFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDescriptorPoolCreateFlagBits& value);
std::string VkDescriptorPoolCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDescriptorSetLayoutCreateFlagBits& value);
std::string VkDescriptorSetLayoutCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDescriptorType& value);
std::string ToString(const VkDeviceQueueCreateFlagBits& value);
std::string VkDeviceQueueCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDynamicState& value);
std::string ToString(const VkEventCreateFlagBits& value);
std::string VkEventCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkFenceCreateFlagBits& value);
std::string VkFenceCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkFilter& value);
std::string ToString(const VkFormat& value);
std::string ToString(const VkFormatFeatureFlagBits& value);
std::string VkFormatFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkFramebufferCreateFlagBits& value);
std::string VkFramebufferCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkFrontFace& value);
std::string ToString(const VkImageAspectFlagBits& value);
std::string VkImageAspectFlagsToString(VkFlags vkFlags);
std::string ToString(const VkImageCreateFlagBits& value);
std::string VkImageCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkImageLayout& value);
std::string ToString(const VkImageTiling& value);
std::string ToString(const VkImageType& value);
std::string ToString(const VkImageUsageFlagBits& value);
std::string VkImageUsageFlagsToString(VkFlags vkFlags);
std::string ToString(const VkImageViewCreateFlagBits& value);
std::string VkImageViewCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkImageViewType& value);
std::string ToString(const VkIndexType& value);
std::string ToString(const VkInstanceCreateFlagBits& value);
std::string VkInstanceCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkInternalAllocationType& value);
std::string ToString(const VkLogicOp& value);
std::string ToString(const VkMemoryHeapFlagBits& value);
std::string VkMemoryHeapFlagsToString(VkFlags vkFlags);
std::string ToString(const VkMemoryPropertyFlagBits& value);
std::string VkMemoryPropertyFlagsToString(VkFlags vkFlags);
std::string ToString(const VkObjectType& value);
std::string ToString(const VkPhysicalDeviceType& value);
std::string ToString(const VkPipelineBindPoint& value);
std::string ToString(const VkPipelineCacheCreateFlagBits& value);
std::string VkPipelineCacheCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineCacheHeaderVersion& value);
std::string ToString(const VkPipelineColorBlendStateCreateFlagBits& value);
std::string VkPipelineColorBlendStateCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineCreateFlagBits& value);
std::string VkPipelineCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineDepthStencilStateCreateFlagBits& value);
std::string VkPipelineDepthStencilStateCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineLayoutCreateFlagBits& value);
std::string VkPipelineLayoutCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineShaderStageCreateFlagBits& value);
std::string VkPipelineShaderStageCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPipelineStageFlagBits& value);
std::string VkPipelineStageFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPolygonMode& value);
std::string ToString(const VkPrimitiveTopology& value);
std::string ToString(const VkQueryControlFlagBits& value);
std::string VkQueryControlFlagsToString(VkFlags vkFlags);
std::string ToString(const VkQueryPipelineStatisticFlagBits& value);
std::string VkQueryPipelineStatisticFlagsToString(VkFlags vkFlags);
std::string ToString(const VkQueryResultFlagBits& value);
std::string VkQueryResultFlagsToString(VkFlags vkFlags);
std::string ToString(const VkQueryType& value);
std::string ToString(const VkQueueFlagBits& value);
std::string VkQueueFlagsToString(VkFlags vkFlags);
std::string ToString(const VkRenderPassCreateFlagBits& value);
std::string VkRenderPassCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkResult& value);
std::string ToString(const VkSampleCountFlagBits& value);
std::string VkSampleCountFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSamplerAddressMode& value);
std::string ToString(const VkSamplerCreateFlagBits& value);
std::string VkSamplerCreateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSamplerMipmapMode& value);
std::string ToString(const VkShaderStageFlagBits& value);
std::string VkShaderStageFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSharingMode& value);
std::string ToString(const VkSparseImageFormatFlagBits& value);
std::string VkSparseImageFormatFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSparseMemoryBindFlagBits& value);
std::string VkSparseMemoryBindFlagsToString(VkFlags vkFlags);
std::string ToString(const VkStencilFaceFlagBits& value);
std::string VkStencilFaceFlagsToString(VkFlags vkFlags);
std::string ToString(const VkStencilOp& value);
std::string ToString(const VkStructureType& value);
std::string ToString(const VkSubpassContents& value);
std::string ToString(const VkSubpassDescriptionFlagBits& value);
std::string VkSubpassDescriptionFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSystemAllocationScope& value);
std::string ToString(const VkVendorId& value);
std::string ToString(const VkVertexInputRate& value);
std::string ToString(const VkChromaLocation& value);
std::string ToString(const VkDescriptorUpdateTemplateType& value);
std::string ToString(const VkExternalFenceFeatureFlagBits& value);
std::string VkExternalFenceFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkExternalFenceHandleTypeFlagBits& value);
std::string VkExternalFenceHandleTypeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkExternalMemoryFeatureFlagBits& value);
std::string VkExternalMemoryFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkExternalMemoryHandleTypeFlagBits& value);
std::string VkExternalMemoryHandleTypeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkExternalSemaphoreFeatureFlagBits& value);
std::string VkExternalSemaphoreFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkExternalSemaphoreHandleTypeFlagBits& value);
std::string VkExternalSemaphoreHandleTypeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkFenceImportFlagBits& value);
std::string VkFenceImportFlagsToString(VkFlags vkFlags);
std::string ToString(const VkMemoryAllocateFlagBits& value);
std::string VkMemoryAllocateFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPeerMemoryFeatureFlagBits& value);
std::string VkPeerMemoryFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkPointClippingBehavior& value);
std::string ToString(const VkSamplerYcbcrModelConversion& value);
std::string ToString(const VkSamplerYcbcrRange& value);
std::string ToString(const VkSemaphoreImportFlagBits& value);
std::string VkSemaphoreImportFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSubgroupFeatureFlagBits& value);
std::string VkSubgroupFeatureFlagsToString(VkFlags vkFlags);
std::string ToString(const VkTessellationDomainOrigin& value);
std::string ToString(const VkDescriptorBindingFlagBits& value);
std::string VkDescriptorBindingFlagsToString(VkFlags vkFlags);
std::string ToString(const VkDriverId& value);
std::string ToString(const VkResolveModeFlagBits& value);
std::string VkResolveModeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSamplerReductionMode& value);
std::string ToString(const VkSemaphoreType& value);
std::string ToString(const VkSemaphoreWaitFlagBits& value);
std::string VkSemaphoreWaitFlagsToString(VkFlags vkFlags);
std::string ToString(const VkShaderFloatControlsIndependence& value);
std::string VkAccessFlagBits2ToString(const VkAccessFlagBits2 value);
std::string VkAccessFlags2ToString(VkFlags64 vkFlags);
std::string VkFormatFeatureFlagBits2ToString(const VkFormatFeatureFlagBits2 value);
std::string VkFormatFeatureFlags2ToString(VkFlags64 vkFlags);
std::string ToString(const VkPipelineCreationFeedbackFlagBits& value);
std::string VkPipelineCreationFeedbackFlagsToString(VkFlags vkFlags);
std::string VkPipelineStageFlagBits2ToString(const VkPipelineStageFlagBits2 value);
std::string VkPipelineStageFlags2ToString(VkFlags64 vkFlags);
std::string ToString(const VkRenderingFlagBits& value);
std::string VkRenderingFlagsToString(VkFlags vkFlags);
std::string ToString(const VkSubmitFlagBits& value);
std::string VkSubmitFlagsToString(VkFlags vkFlags);
std::string ToString(const VkToolPurposeFlagBits& value);
std::string VkToolPurposeFlagsToString(VkFlags vkFlags);
std::string ToString(const VkColorSpaceKHR& value);
std::string ToString(const VkCompositeAlphaFlagBitsKHR& value);
std::string VkCompositeAlphaFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkPresentModeKHR& value);
std::string ToString(const VkSurfaceTransformFlagBitsKHR& value);
std::string VkSurfaceTransformFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkDeviceGroupPresentModeFlagBitsKHR& value);
std::string VkDeviceGroupPresentModeFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkSwapchainCreateFlagBitsKHR& value);
std::string VkSwapchainCreateFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkDisplayPlaneAlphaFlagBitsKHR& value);
std::string VkDisplayPlaneAlphaFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkQueryResultStatusKHR& value);
std::string ToString(const VkVideoCapabilityFlagBitsKHR& value);
std::string VkVideoCapabilityFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoChromaSubsamplingFlagBitsKHR& value);
std::string VkVideoChromaSubsamplingFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoCodecOperationFlagBitsKHR& value);
std::string VkVideoCodecOperationFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoCodingControlFlagBitsKHR& value);
std::string VkVideoCodingControlFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoComponentBitDepthFlagBitsKHR& value);
std::string VkVideoComponentBitDepthFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoSessionCreateFlagBitsKHR& value);
std::string VkVideoSessionCreateFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoDecodeCapabilityFlagBitsKHR& value);
std::string VkVideoDecodeCapabilityFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoDecodeUsageFlagBitsKHR& value);
std::string VkVideoDecodeUsageFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value);
std::string VkVideoDecodeH264PictureLayoutFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkAcquireProfilingLockFlagBitsKHR& value);
std::string VkAcquireProfilingLockFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkPerformanceCounterDescriptionFlagBitsKHR& value);
std::string VkPerformanceCounterDescriptionFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkPerformanceCounterScopeKHR& value);
std::string ToString(const VkPerformanceCounterStorageKHR& value);
std::string ToString(const VkPerformanceCounterUnitKHR& value);
std::string ToString(const VkQueueGlobalPriorityKHR& value);
std::string ToString(const VkFragmentShadingRateCombinerOpKHR& value);
std::string ToString(const VkPipelineExecutableStatisticFormatKHR& value);
std::string ToString(const VkVideoEncodeCapabilityFlagBitsKHR& value);
std::string VkVideoEncodeCapabilityFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeContentFlagBitsKHR& value);
std::string VkVideoEncodeContentFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeFeedbackFlagBitsKHR& value);
std::string VkVideoEncodeFeedbackFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeRateControlModeFlagBitsKHR& value);
std::string VkVideoEncodeRateControlModeFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeTuningModeKHR& value);
std::string ToString(const VkVideoEncodeUsageFlagBitsKHR& value);
std::string VkVideoEncodeUsageFlagBitsKHRToString(VkFlags vkFlags);
std::string VkBufferUsageFlagBits2KHRToString(const VkBufferUsageFlagBits2KHR value);
std::string VkBufferUsageFlags2KHRToString(VkFlags64 vkFlags);
std::string VkPipelineCreateFlagBits2KHRToString(const VkPipelineCreateFlagBits2KHR value);
std::string VkPipelineCreateFlags2KHRToString(VkFlags64 vkFlags);
std::string ToString(const VkComponentTypeKHR& value);
std::string ToString(const VkScopeKHR& value);
std::string ToString(const VkDebugReportFlagBitsEXT& value);
std::string VkDebugReportFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkDebugReportObjectTypeEXT& value);
std::string ToString(const VkRasterizationOrderAMD& value);
std::string ToString(const VkVideoEncodeH264CapabilityFlagBitsEXT& value);
std::string VkVideoEncodeH264CapabilityFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH264RateControlFlagBitsEXT& value);
std::string VkVideoEncodeH264RateControlFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH264StdFlagBitsEXT& value);
std::string VkVideoEncodeH264StdFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH265CapabilityFlagBitsEXT& value);
std::string VkVideoEncodeH265CapabilityFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH265CtbSizeFlagBitsEXT& value);
std::string VkVideoEncodeH265CtbSizeFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH265RateControlFlagBitsEXT& value);
std::string VkVideoEncodeH265RateControlFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH265StdFlagBitsEXT& value);
std::string VkVideoEncodeH265StdFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkVideoEncodeH265TransformBlockSizeFlagBitsEXT& value);
std::string VkVideoEncodeH265TransformBlockSizeFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkShaderInfoTypeAMD& value);
std::string ToString(const VkExternalMemoryFeatureFlagBitsNV& value);
std::string VkExternalMemoryFeatureFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkExternalMemoryHandleTypeFlagBitsNV& value);
std::string VkExternalMemoryHandleTypeFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkValidationCheckEXT& value);
std::string ToString(const VkPipelineRobustnessBufferBehaviorEXT& value);
std::string ToString(const VkPipelineRobustnessImageBehaviorEXT& value);
std::string ToString(const VkConditionalRenderingFlagBitsEXT& value);
std::string VkConditionalRenderingFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkSurfaceCounterFlagBitsEXT& value);
std::string VkSurfaceCounterFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkDeviceEventTypeEXT& value);
std::string ToString(const VkDisplayEventTypeEXT& value);
std::string ToString(const VkDisplayPowerStateEXT& value);
std::string ToString(const VkViewportCoordinateSwizzleNV& value);
std::string ToString(const VkDiscardRectangleModeEXT& value);
std::string ToString(const VkConservativeRasterizationModeEXT& value);
std::string ToString(const VkDebugUtilsMessageSeverityFlagBitsEXT& value);
std::string VkDebugUtilsMessageSeverityFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkDebugUtilsMessageTypeFlagBitsEXT& value);
std::string VkDebugUtilsMessageTypeFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkBlendOverlapEXT& value);
std::string ToString(const VkCoverageModulationModeNV& value);
std::string ToString(const VkValidationCacheHeaderVersionEXT& value);
std::string ToString(const VkCoarseSampleOrderTypeNV& value);
std::string ToString(const VkShadingRatePaletteEntryNV& value);
std::string ToString(const VkAccelerationStructureMemoryRequirementsTypeNV& value);
std::string ToString(const VkAccelerationStructureTypeKHR& value);
std::string ToString(const VkBuildAccelerationStructureFlagBitsKHR& value);
std::string VkBuildAccelerationStructureFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkCopyAccelerationStructureModeKHR& value);
std::string ToString(const VkGeometryFlagBitsKHR& value);
std::string VkGeometryFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkGeometryInstanceFlagBitsKHR& value);
std::string VkGeometryInstanceFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkGeometryTypeKHR& value);
std::string ToString(const VkRayTracingShaderGroupTypeKHR& value);
std::string ToString(const VkPipelineCompilerControlFlagBitsAMD& value);
std::string VkPipelineCompilerControlFlagBitsAMDToString(VkFlags vkFlags);
std::string ToString(const VkTimeDomainEXT& value);
std::string ToString(const VkMemoryOverallocationBehaviorAMD& value);
std::string ToString(const VkPerformanceConfigurationTypeINTEL& value);
std::string ToString(const VkPerformanceOverrideTypeINTEL& value);
std::string ToString(const VkPerformanceParameterTypeINTEL& value);
std::string ToString(const VkPerformanceValueTypeINTEL& value);
std::string ToString(const VkQueryPoolSamplingModeINTEL& value);
std::string ToString(const VkShaderCorePropertiesFlagBitsAMD& value);
std::string VkShaderCorePropertiesFlagBitsAMDToString(VkFlags vkFlags);
std::string ToString(const VkValidationFeatureDisableEXT& value);
std::string ToString(const VkValidationFeatureEnableEXT& value);
std::string ToString(const VkCoverageReductionModeNV& value);
std::string ToString(const VkProvokingVertexModeEXT& value);
std::string ToString(const VkFullScreenExclusiveEXT& value);
std::string ToString(const VkLineRasterizationModeEXT& value);
std::string ToString(const VkHostImageCopyFlagBitsEXT& value);
std::string VkHostImageCopyFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkPresentGravityFlagBitsEXT& value);
std::string VkPresentGravityFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkPresentScalingFlagBitsEXT& value);
std::string VkPresentScalingFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkIndirectCommandsLayoutUsageFlagBitsNV& value);
std::string VkIndirectCommandsLayoutUsageFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkIndirectCommandsTokenTypeNV& value);
std::string ToString(const VkIndirectStateFlagBitsNV& value);
std::string VkIndirectStateFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkDepthBiasRepresentationEXT& value);
std::string ToString(const VkDeviceMemoryReportEventTypeEXT& value);
std::string ToString(const VkDeviceDiagnosticsConfigFlagBitsNV& value);
std::string VkDeviceDiagnosticsConfigFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkGraphicsPipelineLibraryFlagBitsEXT& value);
std::string VkGraphicsPipelineLibraryFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkFragmentShadingRateNV& value);
std::string ToString(const VkFragmentShadingRateTypeNV& value);
std::string ToString(const VkAccelerationStructureMotionInstanceTypeNV& value);
std::string ToString(const VkImageCompressionFixedRateFlagBitsEXT& value);
std::string VkImageCompressionFixedRateFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkImageCompressionFlagBitsEXT& value);
std::string VkImageCompressionFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkDeviceFaultAddressTypeEXT& value);
std::string ToString(const VkDeviceFaultVendorBinaryHeaderVersionEXT& value);
std::string ToString(const VkDeviceAddressBindingFlagBitsEXT& value);
std::string VkDeviceAddressBindingFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkDeviceAddressBindingTypeEXT& value);
std::string ToString(const VkFrameBoundaryFlagBitsEXT& value);
std::string VkFrameBoundaryFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkAccelerationStructureBuildTypeKHR& value);
std::string ToString(const VkAccelerationStructureCompatibilityKHR& value);
std::string ToString(const VkBuildMicromapFlagBitsEXT& value);
std::string VkBuildMicromapFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkBuildMicromapModeEXT& value);
std::string ToString(const VkCopyMicromapModeEXT& value);
std::string ToString(const VkMicromapCreateFlagBitsEXT& value);
std::string VkMicromapCreateFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkMicromapTypeEXT& value);
std::string ToString(const VkOpacityMicromapFormatEXT& value);
std::string ToString(const VkOpacityMicromapSpecialIndexEXT& value);
std::string ToString(const VkDisplacementMicromapFormatNV& value);
std::string ToString(const VkSubpassMergeStatusEXT& value);
std::string ToString(const VkDirectDriverLoadingModeLUNARG& value);
std::string ToString(const VkOpticalFlowExecuteFlagBitsNV& value);
std::string VkOpticalFlowExecuteFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkOpticalFlowGridSizeFlagBitsNV& value);
std::string VkOpticalFlowGridSizeFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkOpticalFlowPerformanceLevelNV& value);
std::string ToString(const VkOpticalFlowSessionBindingPointNV& value);
std::string ToString(const VkOpticalFlowSessionCreateFlagBitsNV& value);
std::string VkOpticalFlowSessionCreateFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkOpticalFlowUsageFlagBitsNV& value);
std::string VkOpticalFlowUsageFlagBitsNVToString(VkFlags vkFlags);
std::string ToString(const VkShaderCodeTypeEXT& value);
std::string ToString(const VkShaderCreateFlagBitsEXT& value);
std::string VkShaderCreateFlagBitsEXTToString(VkFlags vkFlags);
std::string ToString(const VkRayTracingInvocationReorderModeNV& value);
std::string ToString(const VkBlockMatchWindowCompareModeQCOM& value);
std::string ToString(const VkCubicFilterWeightsQCOM& value);
std::string ToString(const VkLayeredDriverUnderlyingApiMSFT& value);
std::string ToString(const VkAccelerationStructureCreateFlagBitsKHR& value);
std::string VkAccelerationStructureCreateFlagBitsKHRToString(VkFlags vkFlags);
std::string ToString(const VkBuildAccelerationStructureModeKHR& value);
std::string ToString(const VkShaderGroupShaderKHR& value);
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
