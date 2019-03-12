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

void MapStructHandles(Decoded_VkApplicationInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkInstanceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceQueueCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

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

void MapStructHandles(Decoded_VkFenceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSemaphoreCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkEventCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkQueryPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineCacheCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineVertexInputStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineTessellationStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRasterizationStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineMultisampleStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineColorBlendStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineDynamicStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorImageInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandPoolCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSubgroupProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryDedicatedRequirements* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryAllocateFlagsInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryRequirements2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseImageMemoryRequirements2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFeatures2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkQueueFamilyProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSparseImageFormatProperties2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDevicePointClippingProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewUsageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassMultiviewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceVariablePointerFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceQueueInfo2* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkProtectedSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImagePlaneMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalImageFormatProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalBufferProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceIDProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalMemoryBufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalFenceProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportFenceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportSemaphoreCreateInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalSemaphoreProperties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutSupport* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderDrawParameterFeatures* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayModeCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkXlibSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkXcbSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWin32SurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportMemoryFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryFdPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkD3D12FenceSubmitInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPresentRegionsKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAttachmentDescription2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAttachmentReference2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassDescription2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassDependency2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassCreateInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassBeginInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassEndInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSurfaceCapabilities2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSurfaceFormat2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPlaneCapabilities2KHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageFormatListCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDevice8BitStorageFeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDriverPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassDescriptionDepthStencilResolveKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugMarkerMarkerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalMemoryImageCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExportMemoryWin32HandleInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkValidationFlagsEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkViSurfaceCreateInfoNN* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageViewASTCDecodeModeEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGeneratedCommandsFeaturesNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceGeneratedCommandsLimitsNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkIndirectCommandsTokenNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkIndirectCommandsLayoutCreateInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCmdProcessCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableCreateInfoNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTablePipelineEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableVertexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTableIndexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkObjectTablePushConstantEntryNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSurfaceCapabilities2EXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayPowerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceEventInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDisplayEventInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSwapchainCounterCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPresentTimesInfoGOOGLE* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkHdrMetadataEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkIOSSurfaceCreateInfoMVK* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugUtilsLabelEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkExternalFormatANDROID* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSamplerReductionModeCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkWriteDescriptorSetInlineUniformBlockEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSampleLocationsInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkAttachmentSampleLocationsEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkSubpassSampleLocationsEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMultisamplePropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

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

void MapStructHandles(Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImportMemoryHostPointerInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryHostPointerPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCalibratedTimestampInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCheckpointDataNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMetalSurfaceCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferDeviceAddressInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkImageStencilUsageCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkValidationFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkCooperativeMatrixPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper, const VulkanObjectMapper& object_mapper);

void MapStructHandles(Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper, const VulkanObjectMapper& object_mapper);

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
