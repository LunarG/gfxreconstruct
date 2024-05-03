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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/handle_unwrap_memory.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "format/platform_types.h"
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
GFXRECON_BEGIN_NAMESPACE(vulkan_wrappers)

void UnwrapStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice16BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryAllocateFlagsInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemoryDeviceGroupInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVariablePointersFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProtectedMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkProtectedSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImagePlaneMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSamplerYcbcrConversionFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderDrawParametersFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan11Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan12Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageFormatListCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice8BitStorageFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicInt64Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFloat16Int8Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorIndexingFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceScalarBlockLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageStencilUsageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerReductionModeCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkanMemoryModelFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImagelessFramebufferFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceUniformBufferStandardLayoutFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHostQueryResetFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTimelineSemaphoreFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkTimelineSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryOpaqueCaptureAddressAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVulkan13Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCreationFeedbackCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderTerminateInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrivateDataFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDevicePrivateDataCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineCreationCacheControlFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSynchronization2Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageRobustnessFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubgroupSizeControlFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInlineUniformBlockFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetInlineUniformBlock* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTextureCompressionASTCHDRFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRenderingCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerDotProductFeatures* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance4Features* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceGroupPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoProfileListInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeH265PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH264PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAttachmentSampleCountInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultiviewPerViewAttributesInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkD3D12FenceSubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentRegionsKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerformanceQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPerformanceQuerySubmitInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePortabilitySubsetFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderClockFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeH265PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineFragmentShadingRateStateCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingAttachmentLocationInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderingInputAttachmentIndexInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderQuadControlFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentWaitFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryUnmapInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentIdKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentIdFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance5FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceImageSubresourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCreateFlags2CreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoDecodeAV1PictureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVideoMaintenance1FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderFloatControls2FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceIndexTypeUint8FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLineRasterizationFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMaintenance6FeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindMemoryStatusKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindDescriptorSetsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPushConstantsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPushDescriptorSetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTransformFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCornerSampledImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalMemoryImageCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExportMemoryWin32HandleInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewASTCDecodeModeEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceASTCDecodeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineRobustnessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRobustnessCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceConditionalRenderingFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentTimesInfoGOOGLE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineDiscardRectangleStateCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClipEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsMessengerCallbackDataEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkExternalFormatANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassSampleLocationsBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageDrmFormatModifierListCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageDrmFormatModifierExplicitCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShadingRateImageFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryHostPointerInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineCompilerControlCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceMemoryOverallocationCreateInfoAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPresentFrameTokenGGP* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderImageFootprintFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExclusiveScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCoherentMemoryFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMemoryPriorityFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryPriorityAllocateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCooperativeMatrixFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCoverageReductionModeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceProvokingVertexFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceHostImageCopyFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyImageToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkHostImageLayoutTransitionInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentFenceInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSwapchainPresentModeInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkReleaseSwapchainImagesInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInheritedViewportScissorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassTransformBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthBiasControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceDeviceMemoryReportCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRobustness2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCustomBorderColorCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCustomBorderColorFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePresentBarrierFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDiagnosticsConfigFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceDiagnosticsConfigCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkGraphicsPipelineLibraryCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineFragmentShadingRateEnumStateCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryMotionTrianglesDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageCompressionControlEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevice4444FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFaultFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAddressBindingReportFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClipControlFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportMemoryZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFrameBoundaryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultisampledRenderToSingleSampledInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceColorWriteEnableFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageViewMinLodFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewMinLodCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiDrawFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderTileImageFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpacityMicromapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDisplacementMicromapFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerBorderColorComponentMappingCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDeviceQueueShaderCoreControlCreateInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSchedulingControlsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewSlicedCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRenderPassStripedFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassStripeBeginInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLinearColorAttachmentFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkImageViewSampleWeightCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessingFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceNestedCommandBufferFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPipelineShaderStageModuleIdentifierCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceOpticalFlowFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkOpticalFlowImageFormatInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceLegacyDitheringFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderObjectFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceTilePropertiesFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAmigoProfilingFeaturesSEC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAmigoProfilingSubmitInfoSEC* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkLatencySubmissionPresentIdNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDevicePerStageDescriptorSetFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceImageProcessing2FeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerBlockMatchWindowCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCubicWeightsFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkSamplerCubicWeightsCreateInfoQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceCubicClampFeaturesQCOM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRawAccessChainsFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingValidationFeaturesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceAccelerationStructureFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayTracingPipelineFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceRayQueryFeaturesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapStructHandles(VkPhysicalDeviceMeshShaderFeaturesEXT* value, HandleUnwrapMemory* unwrap_memory);

VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandles<ParentWrapper, CoParentWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(parent, co_parent, value->physicalDevices, value->physicalDeviceCount, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->display, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->currentDisplay, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<ParentWrapper, CoParentWrapper, vulkan_wrappers::DisplayModeKHRWrapper>(parent, co_parent, &value->displayMode, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayPlaneProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper>
void CreateWrappedStructHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        vulkan_wrappers::CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value->displayModeProperties, get_id);
    }
}

template <typename ParentWrapper, typename CoParentWrapper, typename T>
void CreateWrappedStructArrayHandles(typename ParentWrapper::HandleType parent, typename CoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedStructHandles<ParentWrapper, CoParentWrapper>(parent, co_parent, &value[i], get_id);
        }
    }
}

template <typename T>
T* MakeUnwrapStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
const T* UnwrapStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapStructs(value, 1, unwrap_memory);
        UnwrapStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename T>
const T* UnwrapStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(vulkan_wrappers)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
