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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H

#include "decode/vulkan_object_info_table.h"
#include "decode/vulkan_pnext_node.h"
#include "format/platform_types.h"
#include "decode/custom_vulkan_struct_handle_mappers.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
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

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointersFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan11Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan12Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageFormatListCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloat16Int8Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHostQueryResetFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkTimelineSemaphoreSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkan13Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreationFeedbackCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrivateDataFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDevicePrivateDataCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSynchronization2Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageRobustnessFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlock* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRenderingCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance4Features* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoProfileListInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH264PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeH265PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH264PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAttachmentSampleCountInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiviewPerViewAttributesInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPerformanceQuerySubmitInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeH265PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentLocationInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInputAttachmentIndexInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryUnmapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentIdKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentIdFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCreateFlags2CreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeAV1PictureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindMemoryStatusKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorSetsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushDescriptorSetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRobustnessCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineCompilerControlCreateInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentFrameTokenGGP* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentModeInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassTransformBeginInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCustomBorderColorCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCompressionControlEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFaultFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultisampledRenderToSingleSampledInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewMinLodCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewSlicedCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeBeginInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewSampleWeightCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkOpticalFlowImageFormatInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAmigoProfilingSubmitInfoSEC* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySubmissionPresentIdNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCubicWeightsCreateInfoQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectInfoTable& object_info_table);

template <typename T>
void MapStructArrayHandles(T* structs, size_t len, const VulkanObjectInfoTable& object_info_table)
{
    if (structs != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            MapStructHandles(&structs[i], object_info_table);
        }
    }
}

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

template <typename T>
void AddStructArrayHandles(format::HandleId parent_id, const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrappers != nullptr && handle_structs != nullptr)
    {
        // TODO: Improved handling of array size mismatch.
        size_t len = std::min(id_len, handle_len);
        for (size_t i = 0; i < len; ++i)
        {
            AddStructHandles(parent_id, &id_wrappers[i], &handle_structs[i], object_info_table);
        }
    }
}

void SetStructHandleLengths(Decoded_VkPhysicalDeviceGroupProperties* wrapper);

template <typename T>
void SetStructArrayHandleLengths(T* wrappers, size_t len)
{
    if (wrappers != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            SetStructHandleLengths(&wrappers[i]);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
