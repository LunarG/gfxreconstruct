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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_HANDLE_WRAPPERS_H

#include "encode/custom_vulkan_struct_handle_wrappers.h"
#include "encode/vulkan_handle_wrapper_util.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void UnwrapStructHandles(const VkDeviceCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDeviceCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSubmitInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSubmitInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMemoryAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMemoryAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMappedMemoryRange* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMappedMemoryRange* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSparseMemoryBind* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSparseMemoryBind* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSparseBufferMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSparseBufferMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSparseImageOpaqueMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSparseImageOpaqueMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSparseImageMemoryBind* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSparseImageMemoryBind* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSparseImageMemoryBindInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSparseImageMemoryBindInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBindSparseInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBindSparseInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBufferViewCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBufferViewCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageViewCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageViewCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkShaderModuleCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkShaderModuleCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkPipelineShaderStageCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkPipelineShaderStageCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkGraphicsPipelineCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkGraphicsPipelineCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkComputePipelineCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkComputePipelineCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkPipelineLayoutCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkPipelineLayoutCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSamplerCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSamplerCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDescriptorSetLayoutBinding* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDescriptorSetLayoutBinding* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDescriptorSetLayoutCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDescriptorSetLayoutCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDescriptorSetAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDescriptorSetAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDescriptorBufferInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDescriptorBufferInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCopyDescriptorSet* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCopyDescriptorSet* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkFramebufferCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkFramebufferCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCommandBufferAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCommandBufferAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCommandBufferInheritanceInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCommandBufferInheritanceInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCommandBufferBeginInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCommandBufferBeginInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBufferMemoryBarrier* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBufferMemoryBarrier* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageMemoryBarrier* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageMemoryBarrier* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkRenderPassBeginInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkRenderPassBeginInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBindBufferMemoryInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBindBufferMemoryInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBindImageMemoryInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBindImageMemoryInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMemoryDedicatedAllocateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMemoryDedicatedAllocateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkPhysicalDeviceGroupProperties* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkPhysicalDeviceGroupProperties* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDeviceGroupDeviceCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDeviceGroupDeviceCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBufferMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBufferMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageSparseMemoryRequirementsInfo2* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageSparseMemoryRequirementsInfo2* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSamplerYcbcrConversionInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSamplerYcbcrConversionInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDescriptorUpdateTemplateCreateInfo* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDescriptorUpdateTemplateCreateInfo* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSwapchainCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSwapchainCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkPresentInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkPresentInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageSwapchainCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageSwapchainCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBindImageMemorySwapchainInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBindImageMemorySwapchainInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkAcquireNextImageInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkAcquireNextImageInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayPropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayPropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayModePropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayModePropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayPlanePropertiesKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayPlanePropertiesKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplaySurfaceCreateInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplaySurfaceCreateInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMemoryGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMemoryGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMemoryGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMemoryGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImportSemaphoreWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImportSemaphoreWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSemaphoreGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSemaphoreGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImportSemaphoreFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImportSemaphoreFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkSemaphoreGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkSemaphoreGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImportFenceWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImportFenceWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkFenceGetWin32HandleInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkFenceGetWin32HandleInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImportFenceFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImportFenceFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkFenceGetFdInfoKHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkFenceGetFdInfoKHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkPhysicalDeviceSurfaceInfo2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkPhysicalDeviceSurfaceInfo2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayPlaneProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayPlaneProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayModeProperties2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayModeProperties2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDisplayPlaneInfo2KHR* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDisplayPlaneInfo2KHR* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkDedicatedAllocationMemoryAllocateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkImageViewHandleInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkImageViewHandleInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkWin32KeyedMutexAcquireReleaseInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkConditionalRenderingBeginInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkConditionalRenderingBeginInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkIndirectCommandsTokenNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkIndirectCommandsTokenNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCmdProcessCommandsInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCmdProcessCommandsInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkCmdReserveSpaceForCommandsInfoNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkCmdReserveSpaceForCommandsInfoNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkObjectTablePipelineEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkObjectTablePipelineEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkObjectTableDescriptorSetEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkObjectTableDescriptorSetEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkObjectTableVertexBufferEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkObjectTableVertexBufferEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkObjectTableIndexBufferEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkObjectTableIndexBufferEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkObjectTablePushConstantEntryNVX* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkObjectTablePushConstantEntryNVX* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkMemoryGetAndroidHardwareBufferInfoANDROID* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkShaderModuleValidationCacheCreateInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkShaderModuleValidationCacheCreateInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkRayTracingPipelineCreateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkRayTracingPipelineCreateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkGeometryTrianglesNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkGeometryTrianglesNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkGeometryAABBNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkGeometryAABBNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkGeometryDataNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkGeometryDataNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkGeometryNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkGeometryNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkAccelerationStructureInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkAccelerationStructureInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkAccelerationStructureCreateInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkAccelerationStructureCreateInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBindAccelerationStructureMemoryInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBindAccelerationStructureMemoryInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkWriteDescriptorSetAccelerationStructureNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkWriteDescriptorSetAccelerationStructureNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkAccelerationStructureMemoryRequirementsInfoNV* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapStructHandles(const VkBufferDeviceAddressInfoEXT* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapStructHandles(const VkBufferDeviceAddressInfoEXT* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void UnwrapPNextStructHandles(const void* value, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory);
void RewrapPNextStructHandles(const void* value, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter);

void CreateWrappedStructHandles(VkPhysicalDeviceGroupProperties* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayPropertiesKHR* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayPlanePropertiesKHR* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayModePropertiesKHR* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayProperties2KHR* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayPlaneProperties2KHR* value, PFN_GetHandleId get_id);

void CreateWrappedStructHandles(VkDisplayModeProperties2KHR* value, PFN_GetHandleId get_id);

template <typename T>
void CreateWrappedStructArrayHandles(T* value, size_t len, PFN_GetHandleId get_id)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            CreateWrappedStructHandles(&value[i], get_id);
        }
    }
}

template <typename T>
void UnwrapStructArrayHandles(T* value, size_t len, HandleStore* handle_store, HandleArrayStore* handle_array_store, HandleArrayUnwrapMemory* handle_unwrap_memory)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            UnwrapStructHandles(&value[i], handle_store, handle_array_store, handle_unwrap_memory);
        }
    }
}

template <typename T>
void RewrapStructArrayHandles(T* value, size_t len, HandleStore::const_iterator* handle_store_iter, HandleArrayStore::const_iterator* handle_array_store_iter)
{
    if (value != nullptr)
    {
        for (size_t i = 0; i < len; ++i)
        {
            RewrapStructHandles(&value[i], handle_store_iter, handle_array_store_iter);
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
