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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_ENCODERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_ENCODERS_H

#include "encode/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value);

void EncodeStruct(ParameterEncoder* encoder, const VkExtent2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExtent3D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOffset2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkOffset3D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRect2D& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDispatchIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawIndexedIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawIndirectCommand& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresourceRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryBarrier& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAllocationCallbacks& value);
void EncodeStruct(ParameterEncoder* encoder, const VkApplicationInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkInstanceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryHeap& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryType& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLimits& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExtensionProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkLayerProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMappedMemoryRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseMemoryBind& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseBufferMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageOpaqueMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresource& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryBind& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryBindInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindSparseInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkEventCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferViewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubresourceLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkComponentMapping& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderModuleCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCacheCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSpecializationMapEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSpecializationInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineShaderStageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkComputePipelineCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputBindingDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputAttributeDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineVertexInputStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineInputAssemblyStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineTessellationStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkViewport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineMultisampleStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkStencilOpState& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDepthStencilStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendAttachmentState& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDynamicStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsPipelineCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPushConstantRange& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineLayoutCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyDescriptorSet& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorBufferInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolSize& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBinding& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReference& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescription& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDependency& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandPoolCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSubresourceLayers& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferImageCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearDepthStencilValue& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearAttachment& value);
void EncodeStruct(ParameterEncoder* encoder, const VkClearRect& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageBlit& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageCopy& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageResolve& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassBeginInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindBufferMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevice16BitStorageFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryDedicatedRequirements& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryDedicatedAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryAllocateFlagsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupRenderPassBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupCommandBufferBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupBindSparseInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindBufferMemoryDeviceGroupInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemoryDeviceGroupInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceGroupProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupDeviceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSparseMemoryRequirementsInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryRequirements2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageMemoryRequirements2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFeatures2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageFormatInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSparseImageFormatProperties2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSparseImageFormatInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePointClippingProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkInputAttachmentAspectReference& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassInputAttachmentAspectCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewUsageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineTessellationDomainOriginStateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassMultiviewCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVariablePointersFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceProtectedMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkProtectedSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImagePlaneMemoryInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImagePlaneMemoryRequirementsInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerYcbcrConversionFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerYcbcrConversionImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateEntry& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorUpdateTemplateCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalImageFormatInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalImageFormatProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalBufferInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalBufferProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceIDProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryBufferCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalFenceInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalFenceProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportFenceCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportSemaphoreCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalSemaphoreInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalSemaphoreProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMaintenance3Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutSupport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderDrawParametersFeatures& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan11Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan11Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan12Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkConformanceVersion& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkan12Properties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageFormatListCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescription2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReference2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescription2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDependency2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassCreateInfo2& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassEndInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevice8BitStorageFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDriverProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicInt64Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderFloat16Int8Features& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFloatControlsProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetLayoutBindingFlagsCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDescriptorIndexingProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorSetVariableDescriptorCountLayoutSupport& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassDescriptionDepthStencilResolve& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthStencilResolveProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceScalarBlockLayoutFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageStencilUsageCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSamplerReductionModeCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSamplerFilterMinmaxProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVulkanMemoryModelFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImagelessFramebufferFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferAttachmentImageInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferAttachmentsCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassAttachmentBeginInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentReferenceStencilLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentDescriptionStencilLayout& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceHostQueryResetFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTimelineSemaphoreFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTimelineSemaphoreProperties& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreTypeCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTimelineSemaphoreSubmitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreWaitInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreSignalInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBufferDeviceAddressFeatures& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferDeviceAddressInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferOpaqueCaptureAddressCreateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryOpaqueCaptureAddressAllocateInfo& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceMemoryOpaqueCaptureAddressInfo& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFormatKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageSwapchainCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindImageMemorySwapchainInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAcquireNextImageInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupPresentCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupPresentInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceGroupSwapchainCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeParametersKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilitiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlanePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplaySurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPresentInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXlibSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXcbSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWaylandSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAndroidSurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32SurfaceCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryWin32HandlePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryFdPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportSemaphoreWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportSemaphoreWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkD3D12FenceSubmitInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportSemaphoreFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSemaphoreGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePushDescriptorPropertiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRectLayerKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentRegionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentRegionsKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSharedPresentSurfaceCapabilitiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportFenceWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportFenceWin32HandleInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceGetWin32HandleInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportFenceFdInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFenceGetFdInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePerformanceQueryFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePerformanceQueryPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceCounterKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceCounterDescriptionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolPerformanceCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAcquireProfilingLockInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceQuerySubmitInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSurfaceInfo2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilities2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFormat2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayModeProperties2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneInfo2KHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPlaneCapabilities2KHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderClockFeaturesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceProtectedCapabilitiesKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDeferredOperationInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutablePropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableStatisticKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableInternalRepresentationKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineLibraryCreateInfoKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugReportCallbackCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateRasterizationOrderAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerObjectNameInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerObjectTagInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugMarkerMarkerInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationImageCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationBufferCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDedicatedAllocationMemoryAllocateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTransformFeedbackFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTransformFeedbackPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationStateStreamCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImageViewHandleInfoNVX& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageViewAddressPropertiesNVX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkTextureLODGatherFormatPropertiesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkShaderResourceUsageAMD& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderStatisticsInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkStreamDescriptorSurfaceCreateInfoGGP& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCornerSampledImageFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkExternalImageFormatPropertiesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkExternalMemoryImageCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryAllocateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryWin32HandleInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExportMemoryWin32HandleInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkWin32KeyedMutexAcquireReleaseInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationFlagsEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViSurfaceCreateInfoNN& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImageViewASTCDecodeModeEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceASTCDecodeFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkConditionalRenderingBeginInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceConditionalRenderingFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceConditionalRenderingInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViewportWScalingNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportWScalingStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilities2EXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayPowerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceEventInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDisplayEventInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainCounterCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRefreshCycleDurationGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPastPresentationTimingGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentTimeGOOGLE& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPresentTimesInfoGOOGLE& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX& value);

void EncodeStruct(ParameterEncoder* encoder, const VkViewportSwizzleNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportSwizzleStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDiscardRectanglePropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineDiscardRectangleStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceConservativeRasterizationPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationConservativeStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDepthClipEnableFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationDepthClipStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkXYColorEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkHdrMetadataEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkIOSSurfaceCreateInfoMVK& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMacOSSurfaceCreateInfoMVK& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsLabelEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsObjectNameInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCallbackDataEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsMessengerCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDebugUtilsObjectTagInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferUsageANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferPropertiesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAndroidHardwareBufferFormatPropertiesANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImportAndroidHardwareBufferInfoANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryGetAndroidHardwareBufferInfoANDROID& value);
void EncodeStruct(ParameterEncoder* encoder, const VkExternalFormatANDROID& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceInlineUniformBlockPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSetInlineUniformBlockEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorPoolInlineUniformBlockCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSampleLocationEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSampleLocationsInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAttachmentSampleLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSubpassSampleLocationsEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassSampleLocationsBeginInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineSampleLocationsStateCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSampleLocationsPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMultisamplePropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineColorBlendAdvancedStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageToColorStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageModulationStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrmFormatModifierPropertiesListEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageDrmFormatModifierInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierListCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierExplicitCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkImageDrmFormatModifierPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationCacheCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkShaderModuleValidationCacheCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkShadingRatePaletteNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportShadingRateImageStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImageFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShadingRateImagePropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCoarseSampleLocationNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCoarseSampleOrderCustomNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingShaderGroupCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryTrianglesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryAABBNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryDataNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeometryNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindAccelerationStructureMemoryInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSetAccelerationStructureKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMemoryRequirementsInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTransformMatrixKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAabbPositionsKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureInstanceKHR& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRepresentativeFragmentTestStateCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageViewImageFormatInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFilterCubicImageViewImageFormatPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceQueueGlobalPriorityCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImportMemoryHostPointerInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryHostPointerPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExternalMemoryHostPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCompilerControlCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCalibratedTimestampInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCorePropertiesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceMemoryOverallocationCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkVertexInputBindingDivisorDescriptionEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineVertexInputDivisorStateCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPresentFrameTokenGGP& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCreationFeedbackEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCreationFeedbackCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMeshShaderPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDrawMeshTasksIndirectCommandNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderImageFootprintFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineViewportExclusiveScissorStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExclusiveScissorFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkQueueFamilyCheckpointPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCheckpointDataNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL& value);

void EncodeStruct(ParameterEncoder* encoder, const VkInitializePerformanceApiInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkQueryPoolPerformanceQueryCreateInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceMarkerInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceStreamMarkerInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceOverrideInfoINTEL& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceConfigurationAcquireInfoINTEL& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePCIBusInfoPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDisplayNativeHdrSurfaceCapabilitiesAMD& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSwapchainDisplayNativeHdrCreateInfoAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkImagePipeSurfaceCreateInfoFUCHSIA& value);

void EncodeStruct(ParameterEncoder* encoder, const VkMetalSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMapPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassFragmentDensityMapCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderCoreProperties2AMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCoherentMemoryFeaturesAMD& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryBudgetPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceMemoryPriorityFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkMemoryPriorityAllocateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBufferDeviceAddressCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceToolPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkValidationFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkCooperativeMatrixPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCooperativeMatrixPropertiesNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCoverageReductionModeFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineCoverageReductionStateCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkFramebufferMixedSamplesCombinationNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFullScreenExclusiveInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceCapabilitiesFullScreenExclusiveEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSurfaceFullScreenExclusiveWin32InfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkHeadlessSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLineRasterizationFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceLineRasterizationPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPipelineRasterizationLineStateCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceIndexTypeUint8FeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsShaderGroupCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGraphicsPipelineShaderGroupsCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindShaderGroupIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindIndexBufferIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkBindVertexBufferIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkSetStateFlagsIndirectCommandNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsStreamNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutCreateInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeneratedCommandsInfoNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkGeneratedCommandsMemoryRequirementsInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkRenderPassTransformBeginInfoQCOM& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCommandBufferInheritanceRenderPassTransformInfoQCOM& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRobustness2FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRobustness2PropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkSamplerCustomBorderColorCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCustomBorderColorPropertiesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceCustomBorderColorFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePrivateDataFeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDevicePrivateDataCreateInfoEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPrivateDataSlotCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceDiagnosticsConfigFeaturesNV& value);
void EncodeStruct(ParameterEncoder* encoder, const VkDeviceDiagnosticsConfigCreateInfoNV& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceImageRobustnessFeaturesEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkDirectFBSurfaceCreateInfoEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureBuildOffsetInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingShaderGroupCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineInterfaceCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkRayTracingPipelineCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryTrianglesDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryAabbsDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryInstancesDataKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureCreateGeometryTypeInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureCreateInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMemoryRequirementsInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingFeaturesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkPhysicalDeviceRayTracingPropertiesKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureDeviceAddressInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureVersionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkStridedBufferRegionKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkTraceRaysIndirectCommandKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyAccelerationStructureToMemoryInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToAccelerationStructureInfoKHR& value);
void EncodeStruct(ParameterEncoder* encoder, const VkCopyAccelerationStructureInfoKHR& value);

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
