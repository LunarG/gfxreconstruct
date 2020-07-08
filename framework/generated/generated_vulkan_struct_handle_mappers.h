/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_MAPPERS_H

#include "decode/pnext_node.h"
#include "decode/vulkan_object_info_table.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

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

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

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

void MapStructHandles(Decoded_VkDeferredOperationInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineExecutableInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkPipelineLibraryCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsShaderGroupCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsStreamNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutTokenNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkAccelerationStructureDeviceAddressInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkStridedBufferRegionKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

void MapStructHandles(Decoded_VkCopyAccelerationStructureInfoKHR* wrapper, const VulkanObjectInfoTable& object_info_table);

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

void AddStructHandles(const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

void AddStructHandles(const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, VulkanObjectInfoTable* object_info_table);

template <typename T>
void AddStructArrayHandles(const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, VulkanObjectInfoTable* object_info_table)
{
    if (id_wrappers != nullptr && handle_structs != nullptr)
    {
        // TODO: Improved handling of array size mismatch.
        size_t len = std::min(id_len, handle_len);
        for (size_t i = 0; i < len; ++i)
        {
            AddStructHandles(&id_wrappers[i], &handle_structs[i], object_info_table);
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
