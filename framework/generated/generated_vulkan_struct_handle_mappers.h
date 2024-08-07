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

#include "decode/common_object_info_table.h"
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

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMapInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryUnmapInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorSetsInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantsInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushDescriptorSetInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToImageInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToImageInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const CommonObjectInfoTable& object_info_table);

void MapPNextStructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void AddStructHandles(format::HandleId parent_id, const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, CommonObjectInfoTable* object_info_table);

void SetStructHandleLengths(Decoded_VkPhysicalDeviceGroupProperties* wrapper);

#include "decode/common_struct_handle_mappers.h"
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
