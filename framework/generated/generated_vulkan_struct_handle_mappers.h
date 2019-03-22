/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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
#include "decode/vulkan_object_mapper.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorImageInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkIndirectCommandsTokenNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCmdProcessCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTablePipelineEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableVertexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableIndexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTablePushConstantEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectMapper& object_mapper);

template <typename T>
void MapStructArrayHandles(T* structs, size_t len, const VulkanObjectMapper& object_mapper)
{
    if (structs != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            MapStructHandles(&structs[i], object_mapper);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
