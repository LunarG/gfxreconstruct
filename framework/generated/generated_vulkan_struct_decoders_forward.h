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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_FORWARD_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_FORWARD_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdint>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkApplicationInfo;
struct Decoded_VkInstanceCreateInfo;
struct Decoded_VkAllocationCallbacks;
struct Decoded_VkPhysicalDeviceFeatures;
struct Decoded_VkFormatProperties;
struct Decoded_VkExtent3D;
struct Decoded_VkImageFormatProperties;
struct Decoded_VkPhysicalDeviceLimits;
struct Decoded_VkPhysicalDeviceSparseProperties;
struct Decoded_VkPhysicalDeviceProperties;
struct Decoded_VkQueueFamilyProperties;
struct Decoded_VkMemoryType;
struct Decoded_VkMemoryHeap;
struct Decoded_VkPhysicalDeviceMemoryProperties;
struct Decoded_VkDeviceQueueCreateInfo;
struct Decoded_VkDeviceCreateInfo;
struct Decoded_VkExtensionProperties;
struct Decoded_VkLayerProperties;
struct Decoded_VkSubmitInfo;
struct Decoded_VkMemoryAllocateInfo;
struct Decoded_VkMappedMemoryRange;
struct Decoded_VkMemoryRequirements;
struct Decoded_VkSparseImageFormatProperties;
struct Decoded_VkSparseImageMemoryRequirements;
struct Decoded_VkSparseMemoryBind;
struct Decoded_VkSparseBufferMemoryBindInfo;
struct Decoded_VkSparseImageOpaqueMemoryBindInfo;
struct Decoded_VkImageSubresource;
struct Decoded_VkOffset3D;
struct Decoded_VkSparseImageMemoryBind;
struct Decoded_VkSparseImageMemoryBindInfo;
struct Decoded_VkBindSparseInfo;
struct Decoded_VkFenceCreateInfo;
struct Decoded_VkSemaphoreCreateInfo;
struct Decoded_VkEventCreateInfo;
struct Decoded_VkQueryPoolCreateInfo;
struct Decoded_VkBufferCreateInfo;
struct Decoded_VkBufferViewCreateInfo;
struct Decoded_VkImageCreateInfo;
struct Decoded_VkSubresourceLayout;
struct Decoded_VkComponentMapping;
struct Decoded_VkImageSubresourceRange;
struct Decoded_VkImageViewCreateInfo;
struct Decoded_VkShaderModuleCreateInfo;
struct Decoded_VkPipelineCacheCreateInfo;
struct Decoded_VkSpecializationMapEntry;
struct Decoded_VkSpecializationInfo;
struct Decoded_VkPipelineShaderStageCreateInfo;
struct Decoded_VkVertexInputBindingDescription;
struct Decoded_VkVertexInputAttributeDescription;
struct Decoded_VkPipelineVertexInputStateCreateInfo;
struct Decoded_VkPipelineInputAssemblyStateCreateInfo;
struct Decoded_VkPipelineTessellationStateCreateInfo;
struct Decoded_VkViewport;
struct Decoded_VkOffset2D;
struct Decoded_VkExtent2D;
struct Decoded_VkRect2D;
struct Decoded_VkPipelineViewportStateCreateInfo;
struct Decoded_VkPipelineRasterizationStateCreateInfo;
struct Decoded_VkPipelineMultisampleStateCreateInfo;
struct Decoded_VkStencilOpState;
struct Decoded_VkPipelineDepthStencilStateCreateInfo;
struct Decoded_VkPipelineColorBlendAttachmentState;
struct Decoded_VkPipelineColorBlendStateCreateInfo;
struct Decoded_VkPipelineDynamicStateCreateInfo;
struct Decoded_VkGraphicsPipelineCreateInfo;
struct Decoded_VkComputePipelineCreateInfo;
struct Decoded_VkPushConstantRange;
struct Decoded_VkPipelineLayoutCreateInfo;
struct Decoded_VkSamplerCreateInfo;
struct Decoded_VkDescriptorSetLayoutBinding;
struct Decoded_VkDescriptorSetLayoutCreateInfo;
struct Decoded_VkDescriptorPoolSize;
struct Decoded_VkDescriptorPoolCreateInfo;
struct Decoded_VkDescriptorSetAllocateInfo;
struct Decoded_VkDescriptorImageInfo;
struct Decoded_VkDescriptorBufferInfo;
struct Decoded_VkWriteDescriptorSet;
struct Decoded_VkCopyDescriptorSet;
struct Decoded_VkFramebufferCreateInfo;
struct Decoded_VkAttachmentDescription;
struct Decoded_VkAttachmentReference;
struct Decoded_VkSubpassDescription;
struct Decoded_VkSubpassDependency;
struct Decoded_VkRenderPassCreateInfo;
struct Decoded_VkCommandPoolCreateInfo;
struct Decoded_VkCommandBufferAllocateInfo;
struct Decoded_VkCommandBufferInheritanceInfo;
struct Decoded_VkCommandBufferBeginInfo;
struct Decoded_VkBufferCopy;
struct Decoded_VkImageSubresourceLayers;
struct Decoded_VkImageCopy;
struct Decoded_VkImageBlit;
struct Decoded_VkBufferImageCopy;
struct Decoded_VkClearDepthStencilValue;
struct Decoded_VkClearAttachment;
struct Decoded_VkClearRect;
struct Decoded_VkImageResolve;
struct Decoded_VkMemoryBarrier;
struct Decoded_VkBufferMemoryBarrier;
struct Decoded_VkImageMemoryBarrier;
struct Decoded_VkRenderPassBeginInfo;
struct Decoded_VkDispatchIndirectCommand;
struct Decoded_VkDrawIndexedIndirectCommand;
struct Decoded_VkDrawIndirectCommand;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkApplicationInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkInstanceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAllocationCallbacks* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtent3D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceLimits* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryType* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryHeap* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtensionProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkLayerProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMappedMemoryRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseMemoryBind* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseBufferMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresource* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOffset3D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBind* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryBindInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindSparseInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkEventCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueryPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferViewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubresourceLayout* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkComponentMapping* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresourceRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderModuleCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCacheCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSpecializationMapEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSpecializationInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineShaderStageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputBindingDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputAttributeDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineVertexInputStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineInputAssemblyStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineTessellationStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewport* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkOffset2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExtent2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRect2D* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineMultisampleStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkStencilOpState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDepthStencilStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAttachmentState* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDynamicStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGraphicsPipelineCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkComputePipelineCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPushConstantRange* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineLayoutCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBinding* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolSize* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorBufferInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCopyDescriptorSet* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFramebufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentReference* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescription* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDependency* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandPoolCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSubresourceLayers* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageBlit* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferImageCopy* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearDepthStencilValue* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearAttachment* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkClearRect* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageResolve* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageMemoryBarrier* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDispatchIndirectCommand* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawIndexedIndirectCommand* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawIndirectCommand* wrapper);

struct Decoded_VkPhysicalDeviceSubgroupProperties;
struct Decoded_VkBindBufferMemoryInfo;
struct Decoded_VkBindImageMemoryInfo;
struct Decoded_VkPhysicalDevice16BitStorageFeatures;
struct Decoded_VkMemoryDedicatedRequirements;
struct Decoded_VkMemoryDedicatedAllocateInfo;
struct Decoded_VkMemoryAllocateFlagsInfo;
struct Decoded_VkDeviceGroupRenderPassBeginInfo;
struct Decoded_VkDeviceGroupCommandBufferBeginInfo;
struct Decoded_VkDeviceGroupSubmitInfo;
struct Decoded_VkDeviceGroupBindSparseInfo;
struct Decoded_VkBindBufferMemoryDeviceGroupInfo;
struct Decoded_VkBindImageMemoryDeviceGroupInfo;
struct Decoded_VkPhysicalDeviceGroupProperties;
struct Decoded_VkDeviceGroupDeviceCreateInfo;
struct Decoded_VkBufferMemoryRequirementsInfo2;
struct Decoded_VkImageMemoryRequirementsInfo2;
struct Decoded_VkImageSparseMemoryRequirementsInfo2;
struct Decoded_VkMemoryRequirements2;
struct Decoded_VkSparseImageMemoryRequirements2;
struct Decoded_VkPhysicalDeviceFeatures2;
struct Decoded_VkPhysicalDeviceProperties2;
struct Decoded_VkFormatProperties2;
struct Decoded_VkImageFormatProperties2;
struct Decoded_VkPhysicalDeviceImageFormatInfo2;
struct Decoded_VkQueueFamilyProperties2;
struct Decoded_VkPhysicalDeviceMemoryProperties2;
struct Decoded_VkSparseImageFormatProperties2;
struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2;
struct Decoded_VkPhysicalDevicePointClippingProperties;
struct Decoded_VkInputAttachmentAspectReference;
struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo;
struct Decoded_VkImageViewUsageCreateInfo;
struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo;
struct Decoded_VkRenderPassMultiviewCreateInfo;
struct Decoded_VkPhysicalDeviceMultiviewFeatures;
struct Decoded_VkPhysicalDeviceMultiviewProperties;
struct Decoded_VkPhysicalDeviceVariablePointerFeatures;
struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures;
struct Decoded_VkPhysicalDeviceProtectedMemoryProperties;
struct Decoded_VkDeviceQueueInfo2;
struct Decoded_VkProtectedSubmitInfo;
struct Decoded_VkSamplerYcbcrConversionCreateInfo;
struct Decoded_VkSamplerYcbcrConversionInfo;
struct Decoded_VkBindImagePlaneMemoryInfo;
struct Decoded_VkImagePlaneMemoryRequirementsInfo;
struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures;
struct Decoded_VkSamplerYcbcrConversionImageFormatProperties;
struct Decoded_VkDescriptorUpdateTemplateEntry;
struct Decoded_VkDescriptorUpdateTemplateCreateInfo;
struct Decoded_VkExternalMemoryProperties;
struct Decoded_VkPhysicalDeviceExternalImageFormatInfo;
struct Decoded_VkExternalImageFormatProperties;
struct Decoded_VkPhysicalDeviceExternalBufferInfo;
struct Decoded_VkExternalBufferProperties;
struct Decoded_VkPhysicalDeviceIDProperties;
struct Decoded_VkExternalMemoryImageCreateInfo;
struct Decoded_VkExternalMemoryBufferCreateInfo;
struct Decoded_VkExportMemoryAllocateInfo;
struct Decoded_VkPhysicalDeviceExternalFenceInfo;
struct Decoded_VkExternalFenceProperties;
struct Decoded_VkExportFenceCreateInfo;
struct Decoded_VkExportSemaphoreCreateInfo;
struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo;
struct Decoded_VkExternalSemaphoreProperties;
struct Decoded_VkPhysicalDeviceMaintenance3Properties;
struct Decoded_VkDescriptorSetLayoutSupport;
struct Decoded_VkPhysicalDeviceShaderDrawParameterFeatures;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSubgroupProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindBufferMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevice16BitStorageFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryDedicatedRequirements* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryDedicatedAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryAllocateFlagsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupRenderPassBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupCommandBufferBeginInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupBindSparseInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindBufferMemoryDeviceGroupInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemoryDeviceGroupInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceGroupProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupDeviceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryRequirements2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageMemoryRequirements2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFeatures2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageFormatInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSparseImageFormatProperties2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSparseImageFormatInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePointClippingProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkInputAttachmentAspectReference* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassInputAttachmentAspectCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewUsageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassMultiviewCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVariablePointerFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceProtectedMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueInfo2* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkProtectedSubmitInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImagePlaneMemoryInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImagePlaneMemoryRequirementsInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerYcbcrConversionImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateEntry* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalImageFormatInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalImageFormatProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalBufferInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalBufferProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceIDProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryBufferCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalFenceInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalFenceProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportFenceCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportSemaphoreCreateInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalSemaphoreInfo* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalSemaphoreProperties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMaintenance3Properties* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutSupport* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderDrawParameterFeatures* wrapper);

struct Decoded_VkSurfaceCapabilitiesKHR;
struct Decoded_VkSurfaceFormatKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFormatKHR* wrapper);

struct Decoded_VkSwapchainCreateInfoKHR;
struct Decoded_VkPresentInfoKHR;
struct Decoded_VkImageSwapchainCreateInfoKHR;
struct Decoded_VkBindImageMemorySwapchainInfoKHR;
struct Decoded_VkAcquireNextImageInfoKHR;
struct Decoded_VkDeviceGroupPresentCapabilitiesKHR;
struct Decoded_VkDeviceGroupPresentInfoKHR;
struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageSwapchainCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAcquireNextImageInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupPresentInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGroupSwapchainCreateInfoKHR* wrapper);

struct Decoded_VkDisplayPropertiesKHR;
struct Decoded_VkDisplayModeParametersKHR;
struct Decoded_VkDisplayModePropertiesKHR;
struct Decoded_VkDisplayModeCreateInfoKHR;
struct Decoded_VkDisplayPlaneCapabilitiesKHR;
struct Decoded_VkDisplayPlanePropertiesKHR;
struct Decoded_VkDisplaySurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeParametersKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeCreateInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilitiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlanePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper);

struct Decoded_VkDisplayPresentInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPresentInfoKHR* wrapper);

struct Decoded_VkXlibSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXlibSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkXcbSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXcbSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkWaylandSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWaylandSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkAndroidSurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidSurfaceCreateInfoKHR* wrapper);

struct Decoded_VkWin32SurfaceCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32SurfaceCreateInfoKHR* wrapper);

struct Decoded_VkImportMemoryWin32HandleInfoKHR;
struct Decoded_VkExportMemoryWin32HandleInfoKHR;
struct Decoded_VkMemoryWin32HandlePropertiesKHR;
struct Decoded_VkMemoryGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryWin32HandlePropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportMemoryFdInfoKHR;
struct Decoded_VkMemoryFdPropertiesKHR;
struct Decoded_VkMemoryGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryFdPropertiesKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetFdInfoKHR* wrapper);

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper);

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR;
struct Decoded_VkExportSemaphoreWin32HandleInfoKHR;
struct Decoded_VkD3D12FenceSubmitInfoKHR;
struct Decoded_VkSemaphoreGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportSemaphoreWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkD3D12FenceSubmitInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportSemaphoreFdInfoKHR;
struct Decoded_VkSemaphoreGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportSemaphoreFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSemaphoreGetFdInfoKHR* wrapper);

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* wrapper);

struct Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR* wrapper);

struct Decoded_VkRectLayerKHR;
struct Decoded_VkPresentRegionKHR;
struct Decoded_VkPresentRegionsKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRectLayerKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentRegionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentRegionsKHR* wrapper);

struct Decoded_VkAttachmentDescription2KHR;
struct Decoded_VkAttachmentReference2KHR;
struct Decoded_VkSubpassDescription2KHR;
struct Decoded_VkSubpassDependency2KHR;
struct Decoded_VkRenderPassCreateInfo2KHR;
struct Decoded_VkSubpassBeginInfoKHR;
struct Decoded_VkSubpassEndInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentDescription2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentReference2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescription2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDependency2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassCreateInfo2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassBeginInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassEndInfoKHR* wrapper);

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSharedPresentSurfaceCapabilitiesKHR* wrapper);

struct Decoded_VkImportFenceWin32HandleInfoKHR;
struct Decoded_VkExportFenceWin32HandleInfoKHR;
struct Decoded_VkFenceGetWin32HandleInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportFenceWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportFenceWin32HandleInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceGetWin32HandleInfoKHR* wrapper);

struct Decoded_VkImportFenceFdInfoKHR;
struct Decoded_VkFenceGetFdInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportFenceFdInfoKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFenceGetFdInfoKHR* wrapper);

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR;
struct Decoded_VkSurfaceCapabilities2KHR;
struct Decoded_VkSurfaceFormat2KHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceFormat2KHR* wrapper);

struct Decoded_VkDisplayProperties2KHR;
struct Decoded_VkDisplayPlaneProperties2KHR;
struct Decoded_VkDisplayModeProperties2KHR;
struct Decoded_VkDisplayPlaneInfo2KHR;
struct Decoded_VkDisplayPlaneCapabilities2KHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayModeProperties2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneInfo2KHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPlaneCapabilities2KHR* wrapper);

struct Decoded_VkImageFormatListCreateInfoKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageFormatListCreateInfoKHR* wrapper);

struct Decoded_VkPhysicalDevice8BitStorageFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevice8BitStorageFeaturesKHR* wrapper);

struct Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* wrapper);

struct Decoded_VkConformanceVersionKHR;
struct Decoded_VkPhysicalDeviceDriverPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkConformanceVersionKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDriverPropertiesKHR* wrapper);

struct Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR* wrapper);

struct Decoded_VkSubpassDescriptionDepthStencilResolveKHR;
struct Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassDescriptionDepthStencilResolveKHR* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR* wrapper);

struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* wrapper);

struct Decoded_VkDebugReportCallbackCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugReportCallbackCreateInfoEXT* wrapper);

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* wrapper);

struct Decoded_VkDebugMarkerObjectNameInfoEXT;
struct Decoded_VkDebugMarkerObjectTagInfoEXT;
struct Decoded_VkDebugMarkerMarkerInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectNameInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerObjectTagInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugMarkerMarkerInfoEXT* wrapper);

struct Decoded_VkDedicatedAllocationImageCreateInfoNV;
struct Decoded_VkDedicatedAllocationBufferCreateInfoNV;
struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationImageCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationBufferCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT;
struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT;
struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* wrapper);

struct Decoded_VkImageViewHandleInfoNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewHandleInfoNVX* wrapper);

struct Decoded_VkTextureLODGatherFormatPropertiesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkTextureLODGatherFormatPropertiesAMD* wrapper);

struct Decoded_VkShaderResourceUsageAMD;
struct Decoded_VkShaderStatisticsInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderResourceUsageAMD* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderStatisticsInfoAMD* wrapper);

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* wrapper);

struct Decoded_VkExternalImageFormatPropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalImageFormatPropertiesNV* wrapper);

struct Decoded_VkExternalMemoryImageCreateInfoNV;
struct Decoded_VkExportMemoryAllocateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalMemoryImageCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryAllocateInfoNV* wrapper);

struct Decoded_VkImportMemoryWin32HandleInfoNV;
struct Decoded_VkExportMemoryWin32HandleInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryWin32HandleInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExportMemoryWin32HandleInfoNV* wrapper);

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper);

struct Decoded_VkValidationFlagsEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationFlagsEXT* wrapper);

struct Decoded_VkViSurfaceCreateInfoNN;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViSurfaceCreateInfoNN* wrapper);

struct Decoded_VkImageViewASTCDecodeModeEXT;
struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageViewASTCDecodeModeEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* wrapper);

struct Decoded_VkConditionalRenderingBeginInfoEXT;
struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT;
struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkConditionalRenderingBeginInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* wrapper);

struct Decoded_VkDeviceGeneratedCommandsFeaturesNVX;
struct Decoded_VkDeviceGeneratedCommandsLimitsNVX;
struct Decoded_VkIndirectCommandsTokenNVX;
struct Decoded_VkIndirectCommandsLayoutTokenNVX;
struct Decoded_VkIndirectCommandsLayoutCreateInfoNVX;
struct Decoded_VkCmdProcessCommandsInfoNVX;
struct Decoded_VkCmdReserveSpaceForCommandsInfoNVX;
struct Decoded_VkObjectTableCreateInfoNVX;
struct Decoded_VkObjectTablePipelineEntryNVX;
struct Decoded_VkObjectTableDescriptorSetEntryNVX;
struct Decoded_VkObjectTableVertexBufferEntryNVX;
struct Decoded_VkObjectTableIndexBufferEntryNVX;
struct Decoded_VkObjectTablePushConstantEntryNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsFeaturesNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceGeneratedCommandsLimitsNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsTokenNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutTokenNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutCreateInfoNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCmdProcessCommandsInfoNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTableCreateInfoNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTablePipelineEntryNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTableVertexBufferEntryNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTableIndexBufferEntryNVX* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkObjectTablePushConstantEntryNVX* wrapper);

struct Decoded_VkViewportWScalingNV;
struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewportWScalingNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportWScalingStateCreateInfoNV* wrapper);

struct Decoded_VkSurfaceCapabilities2EXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSurfaceCapabilities2EXT* wrapper);

struct Decoded_VkDisplayPowerInfoEXT;
struct Decoded_VkDeviceEventInfoEXT;
struct Decoded_VkDisplayEventInfoEXT;
struct Decoded_VkSwapchainCounterCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayPowerInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceEventInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDisplayEventInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSwapchainCounterCreateInfoEXT* wrapper);

struct Decoded_VkRefreshCycleDurationGOOGLE;
struct Decoded_VkPastPresentationTimingGOOGLE;
struct Decoded_VkPresentTimeGOOGLE;
struct Decoded_VkPresentTimesInfoGOOGLE;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRefreshCycleDurationGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPastPresentationTimingGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentTimeGOOGLE* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPresentTimesInfoGOOGLE* wrapper);

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* wrapper);

struct Decoded_VkViewportSwizzleNV;
struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkViewportSwizzleNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT;
struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT;
struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT;
struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* wrapper);

struct Decoded_VkXYColorEXT;
struct Decoded_VkHdrMetadataEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkXYColorEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkHdrMetadataEXT* wrapper);

struct Decoded_VkIOSSurfaceCreateInfoMVK;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkIOSSurfaceCreateInfoMVK* wrapper);

struct Decoded_VkMacOSSurfaceCreateInfoMVK;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMacOSSurfaceCreateInfoMVK* wrapper);

struct Decoded_VkDebugUtilsObjectNameInfoEXT;
struct Decoded_VkDebugUtilsObjectTagInfoEXT;
struct Decoded_VkDebugUtilsLabelEXT;
struct Decoded_VkDebugUtilsMessengerCallbackDataEXT;
struct Decoded_VkDebugUtilsMessengerCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectNameInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsObjectTagInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsLabelEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCallbackDataEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDebugUtilsMessengerCreateInfoEXT* wrapper);

struct Decoded_VkAndroidHardwareBufferUsageANDROID;
struct Decoded_VkAndroidHardwareBufferPropertiesANDROID;
struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID;
struct Decoded_VkImportAndroidHardwareBufferInfoANDROID;
struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID;
struct Decoded_VkExternalFormatANDROID;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferUsageANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferPropertiesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportAndroidHardwareBufferInfoANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkExternalFormatANDROID* wrapper);

struct Decoded_VkSamplerReductionModeCreateInfoEXT;
struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSamplerReductionModeCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT;
struct Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT;
struct Decoded_VkWriteDescriptorSetInlineUniformBlockEXT;
struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetInlineUniformBlockEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT* wrapper);

struct Decoded_VkSampleLocationEXT;
struct Decoded_VkSampleLocationsInfoEXT;
struct Decoded_VkAttachmentSampleLocationsEXT;
struct Decoded_VkSubpassSampleLocationsEXT;
struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT;
struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT;
struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT;
struct Decoded_VkMultisamplePropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSampleLocationEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSampleLocationsInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAttachmentSampleLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkSubpassSampleLocationsEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassSampleLocationsBeginInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMultisamplePropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;
struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* wrapper);

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCoverageToColorStateCreateInfoNV* wrapper);

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineCoverageModulationStateCreateInfoNV* wrapper);

struct Decoded_VkDrmFormatModifierPropertiesEXT;
struct Decoded_VkDrmFormatModifierPropertiesListEXT;
struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT;
struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT;
struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT;
struct Decoded_VkImageDrmFormatModifierPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrmFormatModifierPropertiesListEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierListCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageDrmFormatModifierPropertiesEXT* wrapper);

struct Decoded_VkValidationCacheCreateInfoEXT;
struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationCacheCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper);

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;
struct Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT;
struct Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT;
struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;
struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* wrapper);

struct Decoded_VkShadingRatePaletteNV;
struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV;
struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV;
struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV;
struct Decoded_VkCoarseSampleLocationNV;
struct Decoded_VkCoarseSampleOrderCustomNV;
struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkShadingRatePaletteNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCoarseSampleLocationNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCoarseSampleOrderCustomNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* wrapper);

struct Decoded_VkRayTracingShaderGroupCreateInfoNV;
struct Decoded_VkRayTracingPipelineCreateInfoNV;
struct Decoded_VkGeometryTrianglesNV;
struct Decoded_VkGeometryAABBNV;
struct Decoded_VkGeometryDataNV;
struct Decoded_VkGeometryNV;
struct Decoded_VkAccelerationStructureInfoNV;
struct Decoded_VkAccelerationStructureCreateInfoNV;
struct Decoded_VkBindAccelerationStructureMemoryInfoNV;
struct Decoded_VkWriteDescriptorSetAccelerationStructureNV;
struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV;
struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingShaderGroupCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRayTracingPipelineCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryTrianglesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryAABBNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryDataNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkGeometryNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRayTracingPropertiesNV* wrapper);

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;
struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* wrapper);

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT;
struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* wrapper);

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT* wrapper);

struct Decoded_VkImportMemoryHostPointerInfoEXT;
struct Decoded_VkMemoryHostPointerPropertiesEXT;
struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImportMemoryHostPointerInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryHostPointerPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* wrapper);

struct Decoded_VkCalibratedTimestampInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCalibratedTimestampInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* wrapper);

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* wrapper);

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;
struct Decoded_VkVertexInputBindingDivisorDescriptionEXT;
struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT;
struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkVertexInputBindingDivisorDescriptionEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV;
struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV;
struct Decoded_VkDrawMeshTasksIndirectCommandNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkDrawMeshTasksIndirectCommandNV* wrapper);

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* wrapper);

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV;
struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* wrapper);

struct Decoded_VkQueueFamilyCheckpointPropertiesNV;
struct Decoded_VkCheckpointDataNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkQueueFamilyCheckpointPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCheckpointDataNV* wrapper);

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* wrapper);

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* wrapper);

struct Decoded_VkMetalSurfaceCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMetalSurfaceCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT;
struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT;
struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* wrapper);

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* wrapper);

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT;
struct Decoded_VkMemoryPriorityAllocateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkMemoryPriorityAllocateInfoEXT* wrapper);

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* wrapper);

struct Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT;
struct Decoded_VkBufferDeviceAddressInfoEXT;
struct Decoded_VkBufferDeviceAddressCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressInfoEXT* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkBufferDeviceAddressCreateInfoEXT* wrapper);

struct Decoded_VkImageStencilUsageCreateInfoEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkImageStencilUsageCreateInfoEXT* wrapper);

struct Decoded_VkValidationFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkValidationFeaturesEXT* wrapper);

struct Decoded_VkCooperativeMatrixPropertiesNV;
struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV;
struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkCooperativeMatrixPropertiesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* wrapper);
size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* wrapper);

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

size_t DecodeStruct(const uint8_t* parameter_buffer, size_t buffer_size, Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* wrapper);

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
