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

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassAttachmentBeginInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreWaitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSignalInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBufferMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageMemoryBarrier2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDependencyInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCommandBufferSubmitInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSubmitInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyBufferToImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToBufferInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBlitImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkResolveImageInfo2* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingAttachmentInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingInfo* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageMemoryRequirements* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoPictureResourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoReferenceSlotInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindVideoSessionMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoSessionParametersCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoBeginCodingInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoDecodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryMapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryUnmapInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoEncodeSessionParametersGetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDeviceImageSubresourceInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkVideoInlineQueryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorSetsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushConstantsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushDescriptorSetInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPushDescriptorSetWithTemplateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSetDescriptorBufferOffsetsInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

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

void MapStructHandles(Decoded_VkCopyMemoryToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyImageToImageInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkHostImageLayoutTransitionInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSwapchainPresentFenceInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkReleaseSwapchainImagesInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetRemoteAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkFrameBoundaryEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapBuildInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMicromapCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapToMemoryInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMicromapInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDescriptorSetBindingReferenceVALVE* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRenderPassStripeSubmitInfoARM* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineIndirectDeviceAddressInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkLatencySleepInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

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
