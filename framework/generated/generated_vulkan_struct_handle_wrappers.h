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

void UnwrapVulkanStructHandles(VkBufferMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageMemoryBarrier* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMappedMemoryRange* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSparseMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSparseBufferMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSparseImageOpaqueMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSparseImageMemoryBind* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSparseImageMemoryBindInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindSparseInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBufferViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageViewCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkShaderModuleCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineShaderStageCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkComputePipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGraphicsPipelineCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSamplerCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyDescriptorSet* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorBufferInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorSetAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorSetLayoutBinding* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorSetLayoutCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkFramebufferCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCommandBufferAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCommandBufferInheritanceInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCommandBufferBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderPassBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindBufferMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindImageMemoryInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryDedicatedAllocateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPhysicalDeviceGroupProperties* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDeviceGroupDeviceCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBufferMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageSparseMemoryRequirementsInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSamplerYcbcrConversionInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorUpdateTemplateCreateInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderPassAttachmentBeginInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreWaitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreSignalInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBufferDeviceAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDeviceMemoryOpaqueCaptureAddressInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBufferMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageMemoryBarrier2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDependencyInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCommandBufferSubmitInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSubmitInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyBufferToImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyImageToBufferInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBlitImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkResolveImageInfo2* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderingAttachmentInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderingInfo* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDeviceImageMemoryRequirements* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPresentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageSwapchainCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindImageMemorySwapchainInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAcquireNextImageInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayModePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayPlanePropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayPropertiesKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplaySurfaceCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoPictureResourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoReferenceSlotInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindVideoSessionMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoSessionParametersCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoBeginCodingInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoDecodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderingFragmentShadingRateAttachmentInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderingFragmentDensityMapAttachmentInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImportSemaphoreWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImportSemaphoreFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImportFenceWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkFenceGetWin32HandleInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImportFenceFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkFenceGetFdInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPhysicalDeviceSurfaceInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayPlaneProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayModeProperties2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDisplayPlaneInfo2KHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineExecutableInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryMapInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryUnmapInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineLibraryCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoEncodeInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoEncodeSessionParametersGetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDeviceImageSubresourceInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkVideoInlineQueryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindDescriptorSetsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPushConstantsInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPushDescriptorSetInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPushDescriptorSetWithTemplateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSetDescriptorBufferOffsetsInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindDescriptorBufferEmbeddedSamplersInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDebugMarkerObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDebugMarkerObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImageViewHandleInfoNVX* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkConditionalRenderingBeginInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDebugUtilsObjectNameInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDebugUtilsObjectTagInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkShaderModuleValidationCacheCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRayTracingPipelineCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeometryTrianglesNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeometryAABBNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeometryDataNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeometryNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkBindAccelerationStructureMemoryInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkWriteDescriptorSetAccelerationStructureNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyMemoryToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyImageToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyImageToImageInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkHostImageLayoutTransitionInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSwapchainPresentFenceInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkReleaseSwapchainImagesInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGraphicsShaderGroupCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGraphicsPipelineShaderGroupsCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkIndirectCommandsStreamNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkIndirectCommandsLayoutTokenNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkIndirectCommandsLayoutCreateInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeneratedCommandsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkGeneratedCommandsMemoryRequirementsInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkImportSemaphoreZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkSemaphoreGetZirconHandleInfoFUCHSIA* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMemoryGetRemoteAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkFrameBoundaryEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMicromapBuildInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkMicromapCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyMicromapToMemoryInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyMemoryToMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyMicromapInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureTrianglesOpacityMicromapEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureTrianglesDisplacementMicromapNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkDescriptorSetBindingReferenceVALVE* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRenderPassStripeSubmitInfoARM* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkPipelineIndirectDeviceAddressInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkShaderCreateInfoEXT* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkLatencySleepInfoNV* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureGeometryTrianglesDataKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureBuildGeometryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkWriteDescriptorSetAccelerationStructureKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkAccelerationStructureDeviceAddressInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyAccelerationStructureToMemoryInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyMemoryToAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkCopyAccelerationStructureInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

void UnwrapVulkanStructHandles(VkRayTracingPipelineCreateInfoKHR* value, HandleUnwrapMemory* unwrap_memory);

VkBaseInStructure* CopyPNextStruct(const VkBaseInStructure* base, HandleUnwrapMemory* unwrap_memory);

const void* UnwrapPNextStructHandles(const void* value, HandleUnwrapMemory* unwrap_memory);

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanHandles<VulkanParentWrapper, VulkanCoParentWrapper, vulkan_wrappers::PhysicalDeviceWrapper>(parent, co_parent, value->physicalDevices, value->physicalDeviceCount, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanHandle<VulkanParentWrapper, VulkanCoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->display, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanHandle<VulkanParentWrapper, VulkanCoParentWrapper, vulkan_wrappers::DisplayKHRWrapper>(parent, co_parent, &value->currentDisplay, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanHandle<VulkanParentWrapper, VulkanCoParentWrapper, vulkan_wrappers::DisplayModeKHRWrapper>(parent, co_parent, &value->displayMode, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanStructHandles<VulkanParentWrapper, VulkanCoParentWrapper>(parent, co_parent, &value->displayProperties, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanStructHandles<VulkanParentWrapper, VulkanCoParentWrapper>(parent, co_parent, &value->displayPlaneProperties, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper>
void CreateWrappedVulkanStructHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        CreateWrappedVulkanStructHandles<VulkanParentWrapper, VulkanCoParentWrapper>(parent, co_parent, &value->displayModeProperties, get_id);
    }
}

template <typename VulkanParentWrapper, typename VulkanCoParentWrapper, typename T>
void CreateWrappedVulkanStructArrayHandles(typename VulkanParentWrapper::HandleType parent, typename VulkanCoParentWrapper::HandleType co_parent, T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedVulkanStructHandles<VulkanParentWrapper, VulkanCoParentWrapper>(parent, co_parent, &value[i], get_id);
        }
    }
}

template <typename T>
T* MakeUnwrapVulkanStructs(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    assert((values != nullptr) && (len > 0) && (unwrap_memory != nullptr));

    const uint8_t* bytes     = reinterpret_cast<const uint8_t*>(values);
    size_t         num_bytes = len * sizeof(T);

    return reinterpret_cast<T*>(unwrap_memory->GetFilledBuffer(bytes, num_bytes));
}

template <typename T>
const T* UnwrapVulkanStructPtrHandles(const T* value, HandleUnwrapMemory* unwrap_memory)
{
    T* unwrapped_struct = nullptr;

    if (value != nullptr)
    {
        unwrapped_struct = MakeUnwrapVulkanStructs(value, 1, unwrap_memory);
        UnwrapVulkanStructHandles(unwrapped_struct, unwrap_memory);
    }

    return unwrapped_struct;
}

template <typename T>
const T* UnwrapVulkanStructArrayHandles(const T* values, size_t len, HandleUnwrapMemory* unwrap_memory)
{
    if ((values != nullptr) && (len > 0))
    {
        auto unwrapped_structs = MakeUnwrapVulkanStructs(values, len, unwrap_memory);

        for (size_t i = 0; i < len; ++i)
        {
            UnwrapVulkanStructHandles(&unwrapped_structs[i], unwrap_memory);
        }

        return unwrapped_structs;
    }

    // Leave the original memory in place when the pointer is not null, but size is zero.
    return values;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
