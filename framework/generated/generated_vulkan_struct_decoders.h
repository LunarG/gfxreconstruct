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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pnext_node.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkExtent2D
{
    using struct_type = VkExtent2D;

    VkExtent2D* decoded_value{ nullptr };
};

struct Decoded_VkExtent3D
{
    using struct_type = VkExtent3D;

    VkExtent3D* decoded_value{ nullptr };
};

struct Decoded_VkOffset2D
{
    using struct_type = VkOffset2D;

    VkOffset2D* decoded_value{ nullptr };
};

struct Decoded_VkOffset3D
{
    using struct_type = VkOffset3D;

    VkOffset3D* decoded_value{ nullptr };
};

struct Decoded_VkRect2D
{
    using struct_type = VkRect2D;

    VkRect2D* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkOffset2D> offset;
    std::unique_ptr<Decoded_VkExtent2D> extent;
};

struct Decoded_VkBufferMemoryBarrier
{
    using struct_type = VkBufferMemoryBarrier;

    VkBufferMemoryBarrier* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkDispatchIndirectCommand
{
    using struct_type = VkDispatchIndirectCommand;

    VkDispatchIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkDrawIndexedIndirectCommand
{
    using struct_type = VkDrawIndexedIndirectCommand;

    VkDrawIndexedIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkDrawIndirectCommand
{
    using struct_type = VkDrawIndirectCommand;

    VkDrawIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceRange
{
    using struct_type = VkImageSubresourceRange;

    VkImageSubresourceRange* decoded_value{ nullptr };
};

struct Decoded_VkImageMemoryBarrier
{
    using struct_type = VkImageMemoryBarrier;

    VkImageMemoryBarrier* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkImageSubresourceRange> subresourceRange;
};

struct Decoded_VkMemoryBarrier
{
    using struct_type = VkMemoryBarrier;

    VkMemoryBarrier* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAllocationCallbacks
{
    using struct_type = VkAllocationCallbacks;

    VkAllocationCallbacks* decoded_value{ nullptr };

    uint64_t pUserData{ 0 };
    uint64_t pfnAllocation{ 0 };
    uint64_t pfnReallocation{ 0 };
    uint64_t pfnFree{ 0 };
    uint64_t pfnInternalAllocation{ 0 };
    uint64_t pfnInternalFree{ 0 };
};

struct Decoded_VkApplicationInfo
{
    using struct_type = VkApplicationInfo;

    VkApplicationInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pApplicationName;
    StringDecoder pEngineName;
};

struct Decoded_VkFormatProperties
{
    using struct_type = VkFormatProperties;

    VkFormatProperties* decoded_value{ nullptr };
};

struct Decoded_VkImageFormatProperties
{
    using struct_type = VkImageFormatProperties;

    VkImageFormatProperties* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkExtent3D> maxExtent;
};

struct Decoded_VkInstanceCreateInfo
{
    using struct_type = VkInstanceCreateInfo;

    VkInstanceCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkApplicationInfo>> pApplicationInfo;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
};

struct Decoded_VkMemoryHeap
{
    using struct_type = VkMemoryHeap;

    VkMemoryHeap* decoded_value{ nullptr };
};

struct Decoded_VkMemoryType
{
    using struct_type = VkMemoryType;

    VkMemoryType* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceFeatures
{
    using struct_type = VkPhysicalDeviceFeatures;

    VkPhysicalDeviceFeatures* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceLimits
{
    using struct_type = VkPhysicalDeviceLimits;

    VkPhysicalDeviceLimits* decoded_value{ nullptr };

    PointerDecoder<uint32_t> maxComputeWorkGroupCount;
    PointerDecoder<uint32_t> maxComputeWorkGroupSize;
    PointerDecoder<uint32_t> maxViewportDimensions;
    PointerDecoder<float> viewportBoundsRange;
    PointerDecoder<float> pointSizeRange;
    PointerDecoder<float> lineWidthRange;
};

struct Decoded_VkPhysicalDeviceMemoryProperties
{
    using struct_type = VkPhysicalDeviceMemoryProperties;

    VkPhysicalDeviceMemoryProperties* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_VkMemoryType>> memoryTypes;
    std::unique_ptr<StructPointerDecoder<Decoded_VkMemoryHeap>> memoryHeaps;
};

struct Decoded_VkPhysicalDeviceSparseProperties
{
    using struct_type = VkPhysicalDeviceSparseProperties;

    VkPhysicalDeviceSparseProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties
{
    using struct_type = VkPhysicalDeviceProperties;

    VkPhysicalDeviceProperties* decoded_value{ nullptr };

    StringDecoder deviceName;
    PointerDecoder<uint8_t> pipelineCacheUUID;
    std::unique_ptr<Decoded_VkPhysicalDeviceLimits> limits;
    std::unique_ptr<Decoded_VkPhysicalDeviceSparseProperties> sparseProperties;
};

struct Decoded_VkQueueFamilyProperties
{
    using struct_type = VkQueueFamilyProperties;

    VkQueueFamilyProperties* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkExtent3D> minImageTransferGranularity;
};

struct Decoded_VkDeviceQueueCreateInfo
{
    using struct_type = VkDeviceQueueCreateInfo;

    VkDeviceQueueCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pQueuePriorities;
};

struct Decoded_VkDeviceCreateInfo
{
    using struct_type = VkDeviceCreateInfo;

    VkDeviceCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDeviceQueueCreateInfo>> pQueueCreateInfos;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>> pEnabledFeatures;
};

struct Decoded_VkExtensionProperties
{
    using struct_type = VkExtensionProperties;

    VkExtensionProperties* decoded_value{ nullptr };

    StringDecoder extensionName;
};

struct Decoded_VkLayerProperties
{
    using struct_type = VkLayerProperties;

    VkLayerProperties* decoded_value{ nullptr };

    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_VkSubmitInfo
{
    using struct_type = VkSubmitInfo;

    VkSubmitInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    PointerDecoder<VkPipelineStageFlags> pWaitDstStageMask;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkMappedMemoryRange
{
    using struct_type = VkMappedMemoryRange;

    VkMappedMemoryRange* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateInfo
{
    using struct_type = VkMemoryAllocateInfo;

    VkMemoryAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryRequirements
{
    using struct_type = VkMemoryRequirements;

    VkMemoryRequirements* decoded_value{ nullptr };
};

struct Decoded_VkSparseMemoryBind
{
    using struct_type = VkSparseMemoryBind;

    VkSparseMemoryBind* decoded_value{ nullptr };

    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseBufferMemoryBindInfo
{
    using struct_type = VkSparseBufferMemoryBindInfo;

    VkSparseBufferMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseMemoryBind>> pBinds;
};

struct Decoded_VkSparseImageOpaqueMemoryBindInfo
{
    using struct_type = VkSparseImageOpaqueMemoryBindInfo;

    VkSparseImageOpaqueMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseMemoryBind>> pBinds;
};

struct Decoded_VkImageSubresource
{
    using struct_type = VkImageSubresource;

    VkImageSubresource* decoded_value{ nullptr };
};

struct Decoded_VkSparseImageMemoryBind
{
    using struct_type = VkSparseImageMemoryBind;

    VkSparseImageMemoryBind* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageSubresource> subresource;
    std::unique_ptr<Decoded_VkOffset3D> offset;
    std::unique_ptr<Decoded_VkExtent3D> extent;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseImageMemoryBindInfo
{
    using struct_type = VkSparseImageMemoryBindInfo;

    VkSparseImageMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseImageMemoryBind>> pBinds;
};

struct Decoded_VkBindSparseInfo
{
    using struct_type = VkBindSparseInfo;

    VkBindSparseInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo>> pBufferBinds;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo>> pImageOpaqueBinds;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo>> pImageBinds;
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkSparseImageFormatProperties
{
    using struct_type = VkSparseImageFormatProperties;

    VkSparseImageFormatProperties* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkExtent3D> imageGranularity;
};

struct Decoded_VkSparseImageMemoryRequirements
{
    using struct_type = VkSparseImageMemoryRequirements;

    VkSparseImageMemoryRequirements* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkSparseImageFormatProperties> formatProperties;
};

struct Decoded_VkFenceCreateInfo
{
    using struct_type = VkFenceCreateInfo;

    VkFenceCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSemaphoreCreateInfo
{
    using struct_type = VkSemaphoreCreateInfo;

    VkSemaphoreCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkEventCreateInfo
{
    using struct_type = VkEventCreateInfo;

    VkEventCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueryPoolCreateInfo
{
    using struct_type = VkQueryPoolCreateInfo;

    VkQueryPoolCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferCreateInfo
{
    using struct_type = VkBufferCreateInfo;

    VkBufferCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkBufferViewCreateInfo
{
    using struct_type = VkBufferViewCreateInfo;

    VkBufferViewCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageCreateInfo
{
    using struct_type = VkImageCreateInfo;

    VkImageCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent3D> extent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkSubresourceLayout
{
    using struct_type = VkSubresourceLayout;

    VkSubresourceLayout* decoded_value{ nullptr };
};

struct Decoded_VkComponentMapping
{
    using struct_type = VkComponentMapping;

    VkComponentMapping* decoded_value{ nullptr };
};

struct Decoded_VkImageViewCreateInfo
{
    using struct_type = VkImageViewCreateInfo;

    VkImageViewCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkComponentMapping> components;
    std::unique_ptr<Decoded_VkImageSubresourceRange> subresourceRange;
};

struct Decoded_VkShaderModuleCreateInfo
{
    using struct_type = VkShaderModuleCreateInfo;

    VkShaderModuleCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pCode;
};

struct Decoded_VkPipelineCacheCreateInfo
{
    using struct_type = VkPipelineCacheCreateInfo;

    VkPipelineCacheCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkSpecializationMapEntry
{
    using struct_type = VkSpecializationMapEntry;

    VkSpecializationMapEntry* decoded_value{ nullptr };
};

struct Decoded_VkSpecializationInfo
{
    using struct_type = VkSpecializationInfo;

    VkSpecializationInfo* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_VkSpecializationMapEntry>> pMapEntries;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineShaderStageCreateInfo
{
    using struct_type = VkPipelineShaderStageCreateInfo;

    VkPipelineShaderStageCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId module{ format::kNullHandleId };
    StringDecoder pName;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSpecializationInfo>> pSpecializationInfo;
};

struct Decoded_VkComputePipelineCreateInfo
{
    using struct_type = VkComputePipelineCreateInfo;

    VkComputePipelineCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkPipelineShaderStageCreateInfo> stage;
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkVertexInputBindingDescription
{
    using struct_type = VkVertexInputBindingDescription;

    VkVertexInputBindingDescription* decoded_value{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription
{
    using struct_type = VkVertexInputAttributeDescription;

    VkVertexInputAttributeDescription* decoded_value{ nullptr };
};

struct Decoded_VkPipelineVertexInputStateCreateInfo
{
    using struct_type = VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkVertexInputBindingDescription>> pVertexBindingDescriptions;
    std::unique_ptr<StructPointerDecoder<Decoded_VkVertexInputAttributeDescription>> pVertexAttributeDescriptions;
};

struct Decoded_VkPipelineInputAssemblyStateCreateInfo
{
    using struct_type = VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationStateCreateInfo
{
    using struct_type = VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewport
{
    using struct_type = VkViewport;

    VkViewport* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportStateCreateInfo
{
    using struct_type = VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkViewport>> pViewports;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRect2D>> pScissors;
};

struct Decoded_VkPipelineRasterizationStateCreateInfo
{
    using struct_type = VkPipelineRasterizationStateCreateInfo;

    VkPipelineRasterizationStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineMultisampleStateCreateInfo
{
    using struct_type = VkPipelineMultisampleStateCreateInfo;

    VkPipelineMultisampleStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkSampleMask> pSampleMask;
};

struct Decoded_VkStencilOpState
{
    using struct_type = VkStencilOpState;

    VkStencilOpState* decoded_value{ nullptr };
};

struct Decoded_VkPipelineDepthStencilStateCreateInfo
{
    using struct_type = VkPipelineDepthStencilStateCreateInfo;

    VkPipelineDepthStencilStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkStencilOpState> front;
    std::unique_ptr<Decoded_VkStencilOpState> back;
};

struct Decoded_VkPipelineColorBlendAttachmentState
{
    using struct_type = VkPipelineColorBlendAttachmentState;

    VkPipelineColorBlendAttachmentState* decoded_value{ nullptr };
};

struct Decoded_VkPipelineColorBlendStateCreateInfo
{
    using struct_type = VkPipelineColorBlendStateCreateInfo;

    VkPipelineColorBlendStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState>> pAttachments;
    PointerDecoder<float> blendConstants;
};

struct Decoded_VkPipelineDynamicStateCreateInfo
{
    using struct_type = VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDynamicState> pDynamicStates;
};

struct Decoded_VkGraphicsPipelineCreateInfo
{
    using struct_type = VkGraphicsPipelineCreateInfo;

    VkGraphicsPipelineCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>> pStages;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>> pVertexInputState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineInputAssemblyStateCreateInfo>> pInputAssemblyState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>> pTessellationState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineViewportStateCreateInfo>> pViewportState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineRasterizationStateCreateInfo>> pRasterizationState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineMultisampleStateCreateInfo>> pMultisampleState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineDepthStencilStateCreateInfo>> pDepthStencilState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineColorBlendStateCreateInfo>> pColorBlendState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo>> pDynamicState;
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkPushConstantRange
{
    using struct_type = VkPushConstantRange;

    VkPushConstantRange* decoded_value{ nullptr };
};

struct Decoded_VkPipelineLayoutCreateInfo
{
    using struct_type = VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPushConstantRange>> pPushConstantRanges;
};

struct Decoded_VkSamplerCreateInfo
{
    using struct_type = VkSamplerCreateInfo;

    VkSamplerCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCopyDescriptorSet
{
    using struct_type = VkCopyDescriptorSet;

    VkCopyDescriptorSet* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId srcSet{ format::kNullHandleId };
    format::HandleId dstSet{ format::kNullHandleId };
};

struct Decoded_VkDescriptorBufferInfo
{
    using struct_type = VkDescriptorBufferInfo;

    VkDescriptorBufferInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkDescriptorPoolSize
{
    using struct_type = VkDescriptorPoolSize;

    VkDescriptorPoolSize* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorPoolCreateInfo
{
    using struct_type = VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDescriptorPoolSize>> pPoolSizes;
};

struct Decoded_VkDescriptorSetAllocateInfo
{
    using struct_type = VkDescriptorSetAllocateInfo;

    VkDescriptorSetAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId descriptorPool{ format::kNullHandleId };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
};

struct Decoded_VkDescriptorSetLayoutBinding
{
    using struct_type = VkDescriptorSetLayoutBinding;

    VkDescriptorSetLayoutBinding* decoded_value{ nullptr };

    HandlePointerDecoder<VkSampler> pImmutableSamplers;
};

struct Decoded_VkDescriptorSetLayoutCreateInfo
{
    using struct_type = VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding>> pBindings;
};

struct Decoded_VkAttachmentDescription
{
    using struct_type = VkAttachmentDescription;

    VkAttachmentDescription* decoded_value{ nullptr };
};

struct Decoded_VkAttachmentReference
{
    using struct_type = VkAttachmentReference;

    VkAttachmentReference* decoded_value{ nullptr };
};

struct Decoded_VkFramebufferCreateInfo
{
    using struct_type = VkFramebufferCreateInfo;

    VkFramebufferCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ format::kNullHandleId };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkSubpassDescription
{
    using struct_type = VkSubpassDescription;

    VkSubpassDescription* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference>> pInputAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference>> pColorAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference>> pResolveAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference>> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency
{
    using struct_type = VkSubpassDependency;

    VkSubpassDependency* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo
{
    using struct_type = VkRenderPassCreateInfo;

    VkRenderPassCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentDescription>> pAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubpassDescription>> pSubpasses;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubpassDependency>> pDependencies;
};

struct Decoded_VkCommandPoolCreateInfo
{
    using struct_type = VkCommandPoolCreateInfo;

    VkCommandPoolCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferAllocateInfo
{
    using struct_type = VkCommandBufferAllocateInfo;

    VkCommandBufferAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId commandPool{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferInheritanceInfo
{
    using struct_type = VkCommandBufferInheritanceInfo;

    VkCommandBufferInheritanceInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferBeginInfo
{
    using struct_type = VkCommandBufferBeginInfo;

    VkCommandBufferBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo>> pInheritanceInfo;
};

struct Decoded_VkBufferCopy
{
    using struct_type = VkBufferCopy;

    VkBufferCopy* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceLayers
{
    using struct_type = VkImageSubresourceLayers;

    VkImageSubresourceLayers* decoded_value{ nullptr };
};

struct Decoded_VkBufferImageCopy
{
    using struct_type = VkBufferImageCopy;

    VkBufferImageCopy* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageSubresourceLayers> imageSubresource;
    std::unique_ptr<Decoded_VkOffset3D> imageOffset;
    std::unique_ptr<Decoded_VkExtent3D> imageExtent;
};

struct Decoded_VkClearDepthStencilValue
{
    using struct_type = VkClearDepthStencilValue;

    VkClearDepthStencilValue* decoded_value{ nullptr };
};

struct Decoded_VkClearAttachment
{
    using struct_type = VkClearAttachment;

    VkClearAttachment* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkClearValue> clearValue;
};

struct Decoded_VkClearRect
{
    using struct_type = VkClearRect;

    VkClearRect* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkRect2D> rect;
};

struct Decoded_VkImageBlit
{
    using struct_type = VkImageBlit;

    VkImageBlit* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageSubresourceLayers> srcSubresource;
    std::unique_ptr<StructPointerDecoder<Decoded_VkOffset3D>> srcOffsets;
    std::unique_ptr<Decoded_VkImageSubresourceLayers> dstSubresource;
    std::unique_ptr<StructPointerDecoder<Decoded_VkOffset3D>> dstOffsets;
};

struct Decoded_VkImageCopy
{
    using struct_type = VkImageCopy;

    VkImageCopy* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageSubresourceLayers> srcSubresource;
    std::unique_ptr<Decoded_VkOffset3D> srcOffset;
    std::unique_ptr<Decoded_VkImageSubresourceLayers> dstSubresource;
    std::unique_ptr<Decoded_VkOffset3D> dstOffset;
    std::unique_ptr<Decoded_VkExtent3D> extent;
};

struct Decoded_VkImageResolve
{
    using struct_type = VkImageResolve;

    VkImageResolve* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageSubresourceLayers> srcSubresource;
    std::unique_ptr<Decoded_VkOffset3D> srcOffset;
    std::unique_ptr<Decoded_VkImageSubresourceLayers> dstSubresource;
    std::unique_ptr<Decoded_VkOffset3D> dstOffset;
    std::unique_ptr<Decoded_VkExtent3D> extent;
};

struct Decoded_VkRenderPassBeginInfo
{
    using struct_type = VkRenderPassBeginInfo;

    VkRenderPassBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkRect2D> renderArea;
    std::unique_ptr<StructPointerDecoder<Decoded_VkClearValue>> pClearValues;
};

struct Decoded_VkPhysicalDeviceSubgroupProperties
{
    using struct_type = VkPhysicalDeviceSubgroupProperties;

    VkPhysicalDeviceSubgroupProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryInfo
{
    using struct_type = VkBindBufferMemoryInfo;

    VkBindBufferMemoryInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemoryInfo
{
    using struct_type = VkBindImageMemoryInfo;

    VkBindImageMemoryInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevice16BitStorageFeatures
{
    using struct_type = VkPhysicalDevice16BitStorageFeatures;

    VkPhysicalDevice16BitStorageFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedRequirements
{
    using struct_type = VkMemoryDedicatedRequirements;

    VkMemoryDedicatedRequirements* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedAllocateInfo
{
    using struct_type = VkMemoryDedicatedAllocateInfo;

    VkMemoryDedicatedAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateFlagsInfo
{
    using struct_type = VkMemoryAllocateFlagsInfo;

    VkMemoryAllocateFlagsInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupRenderPassBeginInfo
{
    using struct_type = VkDeviceGroupRenderPassBeginInfo;

    VkDeviceGroupRenderPassBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRect2D>> pDeviceRenderAreas;
};

struct Decoded_VkDeviceGroupCommandBufferBeginInfo
{
    using struct_type = VkDeviceGroupCommandBufferBeginInfo;

    VkDeviceGroupCommandBufferBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupSubmitInfo
{
    using struct_type = VkDeviceGroupSubmitInfo;

    VkDeviceGroupSubmitInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pWaitSemaphoreDeviceIndices;
    PointerDecoder<uint32_t> pCommandBufferDeviceMasks;
    PointerDecoder<uint32_t> pSignalSemaphoreDeviceIndices;
};

struct Decoded_VkDeviceGroupBindSparseInfo
{
    using struct_type = VkDeviceGroupBindSparseInfo;

    VkDeviceGroupBindSparseInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryDeviceGroupInfo
{
    using struct_type = VkBindBufferMemoryDeviceGroupInfo;

    VkBindBufferMemoryDeviceGroupInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkBindImageMemoryDeviceGroupInfo
{
    using struct_type = VkBindImageMemoryDeviceGroupInfo;

    VkBindImageMemoryDeviceGroupInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRect2D>> pSplitInstanceBindRegions;
};

struct Decoded_VkPhysicalDeviceGroupProperties
{
    using struct_type = VkPhysicalDeviceGroupProperties;

    VkPhysicalDeviceGroupProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkPhysicalDevice> physicalDevices;
};

struct Decoded_VkDeviceGroupDeviceCreateInfo
{
    using struct_type = VkDeviceGroupDeviceCreateInfo;

    VkDeviceGroupDeviceCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
};

struct Decoded_VkBufferMemoryRequirementsInfo2
{
    using struct_type = VkBufferMemoryRequirementsInfo2;

    VkBufferMemoryRequirementsInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryRequirementsInfo2
{
    using struct_type = VkImageMemoryRequirementsInfo2;

    VkImageMemoryRequirementsInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkImageSparseMemoryRequirementsInfo2
{
    using struct_type = VkImageSparseMemoryRequirementsInfo2;

    VkImageSparseMemoryRequirementsInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkMemoryRequirements2
{
    using struct_type = VkMemoryRequirements2;

    VkMemoryRequirements2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkMemoryRequirements> memoryRequirements;
};

struct Decoded_VkSparseImageMemoryRequirements2
{
    using struct_type = VkSparseImageMemoryRequirements2;

    VkSparseImageMemoryRequirements2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkSparseImageMemoryRequirements> memoryRequirements;
};

struct Decoded_VkPhysicalDeviceFeatures2
{
    using struct_type = VkPhysicalDeviceFeatures2;

    VkPhysicalDeviceFeatures2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkPhysicalDeviceFeatures> features;
};

struct Decoded_VkPhysicalDeviceProperties2
{
    using struct_type = VkPhysicalDeviceProperties2;

    VkPhysicalDeviceProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkPhysicalDeviceProperties> properties;
};

struct Decoded_VkFormatProperties2
{
    using struct_type = VkFormatProperties2;

    VkFormatProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkFormatProperties> formatProperties;
};

struct Decoded_VkImageFormatProperties2
{
    using struct_type = VkImageFormatProperties2;

    VkImageFormatProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkImageFormatProperties> imageFormatProperties;
};

struct Decoded_VkPhysicalDeviceImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceImageFormatInfo2;

    VkPhysicalDeviceImageFormatInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueueFamilyProperties2
{
    using struct_type = VkQueueFamilyProperties2;

    VkQueueFamilyProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkQueueFamilyProperties> queueFamilyProperties;
};

struct Decoded_VkPhysicalDeviceMemoryProperties2
{
    using struct_type = VkPhysicalDeviceMemoryProperties2;

    VkPhysicalDeviceMemoryProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkPhysicalDeviceMemoryProperties> memoryProperties;
};

struct Decoded_VkSparseImageFormatProperties2
{
    using struct_type = VkSparseImageFormatProperties2;

    VkSparseImageFormatProperties2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkSparseImageFormatProperties> properties;
};

struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceSparseImageFormatInfo2;

    VkPhysicalDeviceSparseImageFormatInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePointClippingProperties
{
    using struct_type = VkPhysicalDevicePointClippingProperties;

    VkPhysicalDevicePointClippingProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkInputAttachmentAspectReference
{
    using struct_type = VkInputAttachmentAspectReference;

    VkInputAttachmentAspectReference* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo
{
    using struct_type = VkRenderPassInputAttachmentAspectCreateInfo;

    VkRenderPassInputAttachmentAspectCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkInputAttachmentAspectReference>> pAspectReferences;
};

struct Decoded_VkImageViewUsageCreateInfo
{
    using struct_type = VkImageViewUsageCreateInfo;

    VkImageViewUsageCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo
{
    using struct_type = VkPipelineTessellationDomainOriginStateCreateInfo;

    VkPipelineTessellationDomainOriginStateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassMultiviewCreateInfo
{
    using struct_type = VkRenderPassMultiviewCreateInfo;

    VkRenderPassMultiviewCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pViewMasks;
    PointerDecoder<int32_t> pViewOffsets;
    PointerDecoder<uint32_t> pCorrelationMasks;
};

struct Decoded_VkPhysicalDeviceMultiviewFeatures
{
    using struct_type = VkPhysicalDeviceMultiviewFeatures;

    VkPhysicalDeviceMultiviewFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMultiviewProperties
{
    using struct_type = VkPhysicalDeviceMultiviewProperties;

    VkPhysicalDeviceMultiviewProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVariablePointersFeatures
{
    using struct_type = VkPhysicalDeviceVariablePointersFeatures;

    VkPhysicalDeviceVariablePointersFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures
{
    using struct_type = VkPhysicalDeviceProtectedMemoryFeatures;

    VkPhysicalDeviceProtectedMemoryFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryProperties
{
    using struct_type = VkPhysicalDeviceProtectedMemoryProperties;

    VkPhysicalDeviceProtectedMemoryProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueInfo2
{
    using struct_type = VkDeviceQueueInfo2;

    VkDeviceQueueInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkProtectedSubmitInfo
{
    using struct_type = VkProtectedSubmitInfo;

    VkProtectedSubmitInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionCreateInfo
{
    using struct_type = VkSamplerYcbcrConversionCreateInfo;

    VkSamplerYcbcrConversionCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkComponentMapping> components;
};

struct Decoded_VkSamplerYcbcrConversionInfo
{
    using struct_type = VkSamplerYcbcrConversionInfo;

    VkSamplerYcbcrConversionInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId conversion{ format::kNullHandleId };
};

struct Decoded_VkBindImagePlaneMemoryInfo
{
    using struct_type = VkBindImagePlaneMemoryInfo;

    VkBindImagePlaneMemoryInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImagePlaneMemoryRequirementsInfo
{
    using struct_type = VkImagePlaneMemoryRequirementsInfo;

    VkImagePlaneMemoryRequirementsInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
    using struct_type = VkPhysicalDeviceSamplerYcbcrConversionFeatures;

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionImageFormatProperties
{
    using struct_type = VkSamplerYcbcrConversionImageFormatProperties;

    VkSamplerYcbcrConversionImageFormatProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorUpdateTemplateEntry
{
    using struct_type = VkDescriptorUpdateTemplateEntry;

    VkDescriptorUpdateTemplateEntry* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateCreateInfo
{
    using struct_type = VkDescriptorUpdateTemplateCreateInfo;

    VkDescriptorUpdateTemplateCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry>> pDescriptorUpdateEntries;
    format::HandleId descriptorSetLayout{ format::kNullHandleId };
    format::HandleId pipelineLayout{ format::kNullHandleId };
};

struct Decoded_VkExternalMemoryProperties
{
    using struct_type = VkExternalMemoryProperties;

    VkExternalMemoryProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalImageFormatInfo
{
    using struct_type = VkPhysicalDeviceExternalImageFormatInfo;

    VkPhysicalDeviceExternalImageFormatInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalImageFormatProperties
{
    using struct_type = VkExternalImageFormatProperties;

    VkExternalImageFormatProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExternalMemoryProperties> externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceExternalBufferInfo
{
    using struct_type = VkPhysicalDeviceExternalBufferInfo;

    VkPhysicalDeviceExternalBufferInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalBufferProperties
{
    using struct_type = VkExternalBufferProperties;

    VkExternalBufferProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExternalMemoryProperties> externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceIDProperties
{
    using struct_type = VkPhysicalDeviceIDProperties;

    VkPhysicalDeviceIDProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkExternalMemoryImageCreateInfo
{
    using struct_type = VkExternalMemoryImageCreateInfo;

    VkExternalMemoryImageCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalMemoryBufferCreateInfo
{
    using struct_type = VkExternalMemoryBufferCreateInfo;

    VkExternalMemoryBufferCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfo
{
    using struct_type = VkExportMemoryAllocateInfo;

    VkExportMemoryAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalFenceInfo
{
    using struct_type = VkPhysicalDeviceExternalFenceInfo;

    VkPhysicalDeviceExternalFenceInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalFenceProperties
{
    using struct_type = VkExternalFenceProperties;

    VkExternalFenceProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportFenceCreateInfo
{
    using struct_type = VkExportFenceCreateInfo;

    VkExportFenceCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportSemaphoreCreateInfo
{
    using struct_type = VkExportSemaphoreCreateInfo;

    VkExportSemaphoreCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo
{
    using struct_type = VkPhysicalDeviceExternalSemaphoreInfo;

    VkPhysicalDeviceExternalSemaphoreInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalSemaphoreProperties
{
    using struct_type = VkExternalSemaphoreProperties;

    VkExternalSemaphoreProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMaintenance3Properties
{
    using struct_type = VkPhysicalDeviceMaintenance3Properties;

    VkPhysicalDeviceMaintenance3Properties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutSupport
{
    using struct_type = VkDescriptorSetLayoutSupport;

    VkDescriptorSetLayoutSupport* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderDrawParametersFeatures
{
    using struct_type = VkPhysicalDeviceShaderDrawParametersFeatures;

    VkPhysicalDeviceShaderDrawParametersFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeatures;

typedef Decoded_VkPhysicalDeviceShaderDrawParametersFeatures Decoded_VkPhysicalDeviceShaderDrawParameterFeatures;

struct Decoded_VkPhysicalDeviceVulkan11Features
{
    using struct_type = VkPhysicalDeviceVulkan11Features;

    VkPhysicalDeviceVulkan11Features* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVulkan11Properties
{
    using struct_type = VkPhysicalDeviceVulkan11Properties;

    VkPhysicalDeviceVulkan11Properties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkPhysicalDeviceVulkan12Features
{
    using struct_type = VkPhysicalDeviceVulkan12Features;

    VkPhysicalDeviceVulkan12Features* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkConformanceVersion
{
    using struct_type = VkConformanceVersion;

    VkConformanceVersion* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan12Properties
{
    using struct_type = VkPhysicalDeviceVulkan12Properties;

    VkPhysicalDeviceVulkan12Properties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder driverName;
    StringDecoder driverInfo;
    std::unique_ptr<Decoded_VkConformanceVersion> conformanceVersion;
};

struct Decoded_VkImageFormatListCreateInfo
{
    using struct_type = VkImageFormatListCreateInfo;

    VkImageFormatListCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkAttachmentDescription2
{
    using struct_type = VkAttachmentDescription2;

    VkAttachmentDescription2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAttachmentReference2
{
    using struct_type = VkAttachmentReference2;

    VkAttachmentReference2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassDescription2
{
    using struct_type = VkSubpassDescription2;

    VkSubpassDescription2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference2>> pInputAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference2>> pColorAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference2>> pResolveAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference2>> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency2
{
    using struct_type = VkSubpassDependency2;

    VkSubpassDependency2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassCreateInfo2
{
    using struct_type = VkRenderPassCreateInfo2;

    VkRenderPassCreateInfo2* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentDescription2>> pAttachments;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubpassDescription2>> pSubpasses;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubpassDependency2>> pDependencies;
    PointerDecoder<uint32_t> pCorrelatedViewMasks;
};

struct Decoded_VkSubpassBeginInfo
{
    using struct_type = VkSubpassBeginInfo;

    VkSubpassBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassEndInfo
{
    using struct_type = VkSubpassEndInfo;

    VkSubpassEndInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevice8BitStorageFeatures
{
    using struct_type = VkPhysicalDevice8BitStorageFeatures;

    VkPhysicalDevice8BitStorageFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDriverProperties
{
    using struct_type = VkPhysicalDeviceDriverProperties;

    VkPhysicalDeviceDriverProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder driverName;
    StringDecoder driverInfo;
    std::unique_ptr<Decoded_VkConformanceVersion> conformanceVersion;
};

struct Decoded_VkPhysicalDeviceShaderAtomicInt64Features
{
    using struct_type = VkPhysicalDeviceShaderAtomicInt64Features;

    VkPhysicalDeviceShaderAtomicInt64Features* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderFloat16Int8Features
{
    using struct_type = VkPhysicalDeviceShaderFloat16Int8Features;

    VkPhysicalDeviceShaderFloat16Int8Features* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFloatControlsProperties
{
    using struct_type = VkPhysicalDeviceFloatControlsProperties;

    VkPhysicalDeviceFloatControlsProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo
{
    using struct_type = VkDescriptorSetLayoutBindingFlagsCreateInfo;

    VkDescriptorSetLayoutBindingFlagsCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDescriptorBindingFlags> pBindingFlags;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingFeatures
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingFeatures;

    VkPhysicalDeviceDescriptorIndexingFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingProperties
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingProperties;

    VkPhysicalDeviceDescriptorIndexingProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo
{
    using struct_type = VkDescriptorSetVariableDescriptorCountAllocateInfo;

    VkDescriptorSetVariableDescriptorCountAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDescriptorCounts;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport
{
    using struct_type = VkDescriptorSetVariableDescriptorCountLayoutSupport;

    VkDescriptorSetVariableDescriptorCountLayoutSupport* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassDescriptionDepthStencilResolve
{
    using struct_type = VkSubpassDescriptionDepthStencilResolve;

    VkSubpassDescriptionDepthStencilResolve* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentReference2>> pDepthStencilResolveAttachment;
};

struct Decoded_VkPhysicalDeviceDepthStencilResolveProperties
{
    using struct_type = VkPhysicalDeviceDepthStencilResolveProperties;

    VkPhysicalDeviceDepthStencilResolveProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures
{
    using struct_type = VkPhysicalDeviceScalarBlockLayoutFeatures;

    VkPhysicalDeviceScalarBlockLayoutFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImageStencilUsageCreateInfo
{
    using struct_type = VkImageStencilUsageCreateInfo;

    VkImageStencilUsageCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerReductionModeCreateInfo
{
    using struct_type = VkSamplerReductionModeCreateInfo;

    VkSamplerReductionModeCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties
{
    using struct_type = VkPhysicalDeviceSamplerFilterMinmaxProperties;

    VkPhysicalDeviceSamplerFilterMinmaxProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures
{
    using struct_type = VkPhysicalDeviceVulkanMemoryModelFeatures;

    VkPhysicalDeviceVulkanMemoryModelFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceImagelessFramebufferFeatures
{
    using struct_type = VkPhysicalDeviceImagelessFramebufferFeatures;

    VkPhysicalDeviceImagelessFramebufferFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkFramebufferAttachmentImageInfo
{
    using struct_type = VkFramebufferAttachmentImageInfo;

    VkFramebufferAttachmentImageInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkFramebufferAttachmentsCreateInfo
{
    using struct_type = VkFramebufferAttachmentsCreateInfo;

    VkFramebufferAttachmentsCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkFramebufferAttachmentImageInfo>> pAttachmentImageInfos;
};

struct Decoded_VkRenderPassAttachmentBeginInfo
{
    using struct_type = VkRenderPassAttachmentBeginInfo;

    VkRenderPassAttachmentBeginInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures
{
    using struct_type = VkPhysicalDeviceUniformBufferStandardLayoutFeatures;

    VkPhysicalDeviceUniformBufferStandardLayoutFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures
{
    using struct_type = VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;

    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures
{
    using struct_type = VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;

    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAttachmentReferenceStencilLayout
{
    using struct_type = VkAttachmentReferenceStencilLayout;

    VkAttachmentReferenceStencilLayout* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAttachmentDescriptionStencilLayout
{
    using struct_type = VkAttachmentDescriptionStencilLayout;

    VkAttachmentDescriptionStencilLayout* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceHostQueryResetFeatures
{
    using struct_type = VkPhysicalDeviceHostQueryResetFeatures;

    VkPhysicalDeviceHostQueryResetFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreFeatures;

    VkPhysicalDeviceTimelineSemaphoreFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreProperties
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreProperties;

    VkPhysicalDeviceTimelineSemaphoreProperties* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSemaphoreTypeCreateInfo
{
    using struct_type = VkSemaphoreTypeCreateInfo;

    VkSemaphoreTypeCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkTimelineSemaphoreSubmitInfo
{
    using struct_type = VkTimelineSemaphoreSubmitInfo;

    VkTimelineSemaphoreSubmitInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreWaitInfo
{
    using struct_type = VkSemaphoreWaitInfo;

    VkSemaphoreWaitInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pSemaphores;
    PointerDecoder<uint64_t> pValues;
};

struct Decoded_VkSemaphoreSignalInfo
{
    using struct_type = VkSemaphoreSignalInfo;

    VkSemaphoreSignalInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeatures;

    VkPhysicalDeviceBufferDeviceAddressFeatures* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferDeviceAddressInfo
{
    using struct_type = VkBufferDeviceAddressInfo;

    VkBufferDeviceAddressInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkBufferOpaqueCaptureAddressCreateInfo
{
    using struct_type = VkBufferOpaqueCaptureAddressCreateInfo;

    VkBufferOpaqueCaptureAddressCreateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo
{
    using struct_type = VkMemoryOpaqueCaptureAddressAllocateInfo;

    VkMemoryOpaqueCaptureAddressAllocateInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo
{
    using struct_type = VkDeviceMemoryOpaqueCaptureAddressInfo;

    VkDeviceMemoryOpaqueCaptureAddressInfo* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSurfaceCapabilitiesKHR
{
    using struct_type = VkSurfaceCapabilitiesKHR;

    VkSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkExtent2D> currentExtent;
    std::unique_ptr<Decoded_VkExtent2D> minImageExtent;
    std::unique_ptr<Decoded_VkExtent2D> maxImageExtent;
};

struct Decoded_VkSurfaceFormatKHR
{
    using struct_type = VkSurfaceFormatKHR;

    VkSurfaceFormatKHR* decoded_value{ nullptr };
};

struct Decoded_VkSwapchainCreateInfoKHR
{
    using struct_type = VkSwapchainCreateInfoKHR;

    VkSwapchainCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId surface{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkExtent2D> imageExtent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
    format::HandleId oldSwapchain{ format::kNullHandleId };
};

struct Decoded_VkPresentInfoKHR
{
    using struct_type = VkPresentInfoKHR;

    VkPresentInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    PointerDecoder<uint32_t> pImageIndices;
    PointerDecoder<VkResult> pResults;
};

struct Decoded_VkImageSwapchainCreateInfoKHR
{
    using struct_type = VkImageSwapchainCreateInfoKHR;

    VkImageSwapchainCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemorySwapchainInfoKHR
{
    using struct_type = VkBindImageMemorySwapchainInfoKHR;

    VkBindImageMemorySwapchainInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkAcquireNextImageInfoKHR
{
    using struct_type = VkAcquireNextImageInfoKHR;

    VkAcquireNextImageInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ format::kNullHandleId };
    format::HandleId semaphore{ format::kNullHandleId };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkDeviceGroupPresentCapabilitiesKHR
{
    using struct_type = VkDeviceGroupPresentCapabilitiesKHR;

    VkDeviceGroupPresentCapabilitiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> presentMask;
};

struct Decoded_VkDeviceGroupPresentInfoKHR
{
    using struct_type = VkDeviceGroupPresentInfoKHR;

    VkDeviceGroupPresentInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceMasks;
};

struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR
{
    using struct_type = VkDeviceGroupSwapchainCreateInfoKHR;

    VkDeviceGroupSwapchainCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayModeParametersKHR
{
    using struct_type = VkDisplayModeParametersKHR;

    VkDisplayModeParametersKHR* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkExtent2D> visibleRegion;
};

struct Decoded_VkDisplayModeCreateInfoKHR
{
    using struct_type = VkDisplayModeCreateInfoKHR;

    VkDisplayModeCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDisplayModeParametersKHR> parameters;
};

struct Decoded_VkDisplayModePropertiesKHR
{
    using struct_type = VkDisplayModePropertiesKHR;

    VkDisplayModePropertiesKHR* decoded_value{ nullptr };

    format::HandleId displayMode{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkDisplayModeParametersKHR> parameters;
};

struct Decoded_VkDisplayPlaneCapabilitiesKHR
{
    using struct_type = VkDisplayPlaneCapabilitiesKHR;

    VkDisplayPlaneCapabilitiesKHR* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkOffset2D> minSrcPosition;
    std::unique_ptr<Decoded_VkOffset2D> maxSrcPosition;
    std::unique_ptr<Decoded_VkExtent2D> minSrcExtent;
    std::unique_ptr<Decoded_VkExtent2D> maxSrcExtent;
    std::unique_ptr<Decoded_VkOffset2D> minDstPosition;
    std::unique_ptr<Decoded_VkOffset2D> maxDstPosition;
    std::unique_ptr<Decoded_VkExtent2D> minDstExtent;
    std::unique_ptr<Decoded_VkExtent2D> maxDstExtent;
};

struct Decoded_VkDisplayPlanePropertiesKHR
{
    using struct_type = VkDisplayPlanePropertiesKHR;

    VkDisplayPlanePropertiesKHR* decoded_value{ nullptr };

    format::HandleId currentDisplay{ format::kNullHandleId };
};

struct Decoded_VkDisplayPropertiesKHR
{
    using struct_type = VkDisplayPropertiesKHR;

    VkDisplayPropertiesKHR* decoded_value{ nullptr };

    format::HandleId display{ format::kNullHandleId };
    StringDecoder displayName;
    std::unique_ptr<Decoded_VkExtent2D> physicalDimensions;
    std::unique_ptr<Decoded_VkExtent2D> physicalResolution;
};

struct Decoded_VkDisplaySurfaceCreateInfoKHR
{
    using struct_type = VkDisplaySurfaceCreateInfoKHR;

    VkDisplaySurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId displayMode{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkExtent2D> imageExtent;
};

struct Decoded_VkDisplayPresentInfoKHR
{
    using struct_type = VkDisplayPresentInfoKHR;

    VkDisplayPresentInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkRect2D> srcRect;
    std::unique_ptr<Decoded_VkRect2D> dstRect;
};

struct Decoded_VkXlibSurfaceCreateInfoKHR
{
    using struct_type = VkXlibSurfaceCreateInfoKHR;

    VkXlibSurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t dpy{ 0 };
};

struct Decoded_VkXcbSurfaceCreateInfoKHR
{
    using struct_type = VkXcbSurfaceCreateInfoKHR;

    VkXcbSurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t connection{ 0 };
};

struct Decoded_VkWaylandSurfaceCreateInfoKHR
{
    using struct_type = VkWaylandSurfaceCreateInfoKHR;

    VkWaylandSurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t display{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkAndroidSurfaceCreateInfoKHR
{
    using struct_type = VkAndroidSurfaceCreateInfoKHR;

    VkAndroidSurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t window{ 0 };
};

struct Decoded_VkWin32SurfaceCreateInfoKHR
{
    using struct_type = VkWin32SurfaceCreateInfoKHR;

    VkWin32SurfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t hinstance{ 0 };
    uint64_t hwnd{ 0 };
};

typedef Decoded_VkRenderPassMultiviewCreateInfo Decoded_VkRenderPassMultiviewCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceMultiviewFeatures Decoded_VkPhysicalDeviceMultiviewFeaturesKHR;

typedef Decoded_VkPhysicalDeviceMultiviewProperties Decoded_VkPhysicalDeviceMultiviewPropertiesKHR;

typedef Decoded_VkPhysicalDeviceFeatures2 Decoded_VkPhysicalDeviceFeatures2KHR;

typedef Decoded_VkPhysicalDeviceProperties2 Decoded_VkPhysicalDeviceProperties2KHR;

typedef Decoded_VkFormatProperties2 Decoded_VkFormatProperties2KHR;

typedef Decoded_VkImageFormatProperties2 Decoded_VkImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceImageFormatInfo2 Decoded_VkPhysicalDeviceImageFormatInfo2KHR;

typedef Decoded_VkQueueFamilyProperties2 Decoded_VkQueueFamilyProperties2KHR;

typedef Decoded_VkPhysicalDeviceMemoryProperties2 Decoded_VkPhysicalDeviceMemoryProperties2KHR;

typedef Decoded_VkSparseImageFormatProperties2 Decoded_VkSparseImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceSparseImageFormatInfo2 Decoded_VkPhysicalDeviceSparseImageFormatInfo2KHR;

typedef Decoded_VkMemoryAllocateFlagsInfo Decoded_VkMemoryAllocateFlagsInfoKHR;

typedef Decoded_VkDeviceGroupRenderPassBeginInfo Decoded_VkDeviceGroupRenderPassBeginInfoKHR;

typedef Decoded_VkDeviceGroupCommandBufferBeginInfo Decoded_VkDeviceGroupCommandBufferBeginInfoKHR;

typedef Decoded_VkDeviceGroupSubmitInfo Decoded_VkDeviceGroupSubmitInfoKHR;

typedef Decoded_VkDeviceGroupBindSparseInfo Decoded_VkDeviceGroupBindSparseInfoKHR;

typedef Decoded_VkBindBufferMemoryDeviceGroupInfo Decoded_VkBindBufferMemoryDeviceGroupInfoKHR;

typedef Decoded_VkBindImageMemoryDeviceGroupInfo Decoded_VkBindImageMemoryDeviceGroupInfoKHR;

typedef Decoded_VkPhysicalDeviceGroupProperties Decoded_VkPhysicalDeviceGroupPropertiesKHR;

typedef Decoded_VkDeviceGroupDeviceCreateInfo Decoded_VkDeviceGroupDeviceCreateInfoKHR;

typedef Decoded_VkExternalMemoryProperties Decoded_VkExternalMemoryPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalImageFormatInfo Decoded_VkPhysicalDeviceExternalImageFormatInfoKHR;

typedef Decoded_VkExternalImageFormatProperties Decoded_VkExternalImageFormatPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalBufferInfo Decoded_VkPhysicalDeviceExternalBufferInfoKHR;

typedef Decoded_VkExternalBufferProperties Decoded_VkExternalBufferPropertiesKHR;

typedef Decoded_VkPhysicalDeviceIDProperties Decoded_VkPhysicalDeviceIDPropertiesKHR;

typedef Decoded_VkExternalMemoryImageCreateInfo Decoded_VkExternalMemoryImageCreateInfoKHR;

typedef Decoded_VkExternalMemoryBufferCreateInfo Decoded_VkExternalMemoryBufferCreateInfoKHR;

typedef Decoded_VkExportMemoryAllocateInfo Decoded_VkExportMemoryAllocateInfoKHR;

struct Decoded_VkImportMemoryWin32HandleInfoKHR
{
    using struct_type = VkImportMemoryWin32HandleInfoKHR;

    VkImportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportMemoryWin32HandleInfoKHR
{
    using struct_type = VkExportMemoryWin32HandleInfoKHR;

    VkExportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkMemoryWin32HandlePropertiesKHR
{
    using struct_type = VkMemoryWin32HandlePropertiesKHR;

    VkMemoryWin32HandlePropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetWin32HandleInfoKHR
{
    using struct_type = VkMemoryGetWin32HandleInfoKHR;

    VkMemoryGetWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkImportMemoryFdInfoKHR
{
    using struct_type = VkImportMemoryFdInfoKHR;

    VkImportMemoryFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryFdPropertiesKHR
{
    using struct_type = VkMemoryFdPropertiesKHR;

    VkMemoryFdPropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetFdInfoKHR
{
    using struct_type = VkMemoryGetFdInfoKHR;

    VkMemoryGetFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoKHR;

    VkWin32KeyedMutexAcquireReleaseInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeouts;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

typedef Decoded_VkPhysicalDeviceExternalSemaphoreInfo Decoded_VkPhysicalDeviceExternalSemaphoreInfoKHR;

typedef Decoded_VkExternalSemaphoreProperties Decoded_VkExternalSemaphorePropertiesKHR;

typedef Decoded_VkExportSemaphoreCreateInfo Decoded_VkExportSemaphoreCreateInfoKHR;

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkImportSemaphoreWin32HandleInfoKHR;

    VkImportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkExportSemaphoreWin32HandleInfoKHR;

    VkExportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkD3D12FenceSubmitInfoKHR
{
    using struct_type = VkD3D12FenceSubmitInfoKHR;

    VkD3D12FenceSubmitInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreGetWin32HandleInfoKHR
{
    using struct_type = VkSemaphoreGetWin32HandleInfoKHR;

    VkSemaphoreGetWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkImportSemaphoreFdInfoKHR
{
    using struct_type = VkImportSemaphoreFdInfoKHR;

    VkImportSemaphoreFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkSemaphoreGetFdInfoKHR
{
    using struct_type = VkSemaphoreGetFdInfoKHR;

    VkSemaphoreGetFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR
{
    using struct_type = VkPhysicalDevicePushDescriptorPropertiesKHR;

    VkPhysicalDevicePushDescriptorPropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceShaderFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDevice16BitStorageFeatures Decoded_VkPhysicalDevice16BitStorageFeaturesKHR;

struct Decoded_VkRectLayerKHR
{
    using struct_type = VkRectLayerKHR;

    VkRectLayerKHR* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkOffset2D> offset;
    std::unique_ptr<Decoded_VkExtent2D> extent;
};

struct Decoded_VkPresentRegionKHR
{
    using struct_type = VkPresentRegionKHR;

    VkPresentRegionKHR* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_VkRectLayerKHR>> pRectangles;
};

struct Decoded_VkPresentRegionsKHR
{
    using struct_type = VkPresentRegionsKHR;

    VkPresentRegionsKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPresentRegionKHR>> pRegions;
};

typedef Decoded_VkDescriptorUpdateTemplateEntry Decoded_VkDescriptorUpdateTemplateEntryKHR;

typedef Decoded_VkDescriptorUpdateTemplateCreateInfo Decoded_VkDescriptorUpdateTemplateCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceImagelessFramebufferFeatures Decoded_VkPhysicalDeviceImagelessFramebufferFeaturesKHR;

typedef Decoded_VkFramebufferAttachmentsCreateInfo Decoded_VkFramebufferAttachmentsCreateInfoKHR;

typedef Decoded_VkFramebufferAttachmentImageInfo Decoded_VkFramebufferAttachmentImageInfoKHR;

typedef Decoded_VkRenderPassAttachmentBeginInfo Decoded_VkRenderPassAttachmentBeginInfoKHR;

typedef Decoded_VkRenderPassCreateInfo2 Decoded_VkRenderPassCreateInfo2KHR;

typedef Decoded_VkAttachmentDescription2 Decoded_VkAttachmentDescription2KHR;

typedef Decoded_VkAttachmentReference2 Decoded_VkAttachmentReference2KHR;

typedef Decoded_VkSubpassDescription2 Decoded_VkSubpassDescription2KHR;

typedef Decoded_VkSubpassDependency2 Decoded_VkSubpassDependency2KHR;

typedef Decoded_VkSubpassBeginInfo Decoded_VkSubpassBeginInfoKHR;

typedef Decoded_VkSubpassEndInfo Decoded_VkSubpassEndInfoKHR;

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR
{
    using struct_type = VkSharedPresentSurfaceCapabilitiesKHR;

    VkSharedPresentSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceExternalFenceInfo Decoded_VkPhysicalDeviceExternalFenceInfoKHR;

typedef Decoded_VkExternalFenceProperties Decoded_VkExternalFencePropertiesKHR;

typedef Decoded_VkExportFenceCreateInfo Decoded_VkExportFenceCreateInfoKHR;

struct Decoded_VkImportFenceWin32HandleInfoKHR
{
    using struct_type = VkImportFenceWin32HandleInfoKHR;

    VkImportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportFenceWin32HandleInfoKHR
{
    using struct_type = VkExportFenceWin32HandleInfoKHR;

    VkExportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkFenceGetWin32HandleInfoKHR
{
    using struct_type = VkFenceGetWin32HandleInfoKHR;

    VkFenceGetWin32HandleInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkImportFenceFdInfoKHR
{
    using struct_type = VkImportFenceFdInfoKHR;

    VkImportFenceFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkFenceGetFdInfoKHR
{
    using struct_type = VkFenceGetFdInfoKHR;

    VkFenceGetFdInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryFeaturesKHR;

    VkPhysicalDevicePerformanceQueryFeaturesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryPropertiesKHR;

    VkPhysicalDevicePerformanceQueryPropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceCounterKHR
{
    using struct_type = VkPerformanceCounterKHR;

    VkPerformanceCounterKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> uuid;
};

struct Decoded_VkPerformanceCounterDescriptionKHR
{
    using struct_type = VkPerformanceCounterDescriptionKHR;

    VkPerformanceCounterDescriptionKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder name;
    StringDecoder category;
    StringDecoder description;
};

struct Decoded_VkQueryPoolPerformanceCreateInfoKHR
{
    using struct_type = VkQueryPoolPerformanceCreateInfoKHR;

    VkQueryPoolPerformanceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pCounterIndices;
};

struct Decoded_VkAcquireProfilingLockInfoKHR
{
    using struct_type = VkAcquireProfilingLockInfoKHR;

    VkAcquireProfilingLockInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceQuerySubmitInfoKHR
{
    using struct_type = VkPerformanceQuerySubmitInfoKHR;

    VkPerformanceQuerySubmitInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDevicePointClippingProperties Decoded_VkPhysicalDevicePointClippingPropertiesKHR;

typedef Decoded_VkRenderPassInputAttachmentAspectCreateInfo Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR;

typedef Decoded_VkInputAttachmentAspectReference Decoded_VkInputAttachmentAspectReferenceKHR;

typedef Decoded_VkImageViewUsageCreateInfo Decoded_VkImageViewUsageCreateInfoKHR;

typedef Decoded_VkPipelineTessellationDomainOriginStateCreateInfo Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR;

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR
{
    using struct_type = VkPhysicalDeviceSurfaceInfo2KHR;

    VkPhysicalDeviceSurfaceInfo2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId surface{ format::kNullHandleId };
};

struct Decoded_VkSurfaceCapabilities2KHR
{
    using struct_type = VkSurfaceCapabilities2KHR;

    VkSurfaceCapabilities2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkSurfaceCapabilitiesKHR> surfaceCapabilities;
};

struct Decoded_VkSurfaceFormat2KHR
{
    using struct_type = VkSurfaceFormat2KHR;

    VkSurfaceFormat2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkSurfaceFormatKHR> surfaceFormat;
};

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeaturesKHR;

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointersFeaturesKHR;

struct Decoded_VkDisplayProperties2KHR
{
    using struct_type = VkDisplayProperties2KHR;

    VkDisplayProperties2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDisplayPropertiesKHR> displayProperties;
};

struct Decoded_VkDisplayPlaneProperties2KHR
{
    using struct_type = VkDisplayPlaneProperties2KHR;

    VkDisplayPlaneProperties2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDisplayPlanePropertiesKHR> displayPlaneProperties;
};

struct Decoded_VkDisplayModeProperties2KHR
{
    using struct_type = VkDisplayModeProperties2KHR;

    VkDisplayModeProperties2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDisplayModePropertiesKHR> displayModeProperties;
};

struct Decoded_VkDisplayPlaneInfo2KHR
{
    using struct_type = VkDisplayPlaneInfo2KHR;

    VkDisplayPlaneInfo2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId mode{ format::kNullHandleId };
};

struct Decoded_VkDisplayPlaneCapabilities2KHR
{
    using struct_type = VkDisplayPlaneCapabilities2KHR;

    VkDisplayPlaneCapabilities2KHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDisplayPlaneCapabilitiesKHR> capabilities;
};

typedef Decoded_VkMemoryDedicatedRequirements Decoded_VkMemoryDedicatedRequirementsKHR;

typedef Decoded_VkMemoryDedicatedAllocateInfo Decoded_VkMemoryDedicatedAllocateInfoKHR;

typedef Decoded_VkBufferMemoryRequirementsInfo2 Decoded_VkBufferMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageMemoryRequirementsInfo2 Decoded_VkImageMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageSparseMemoryRequirementsInfo2 Decoded_VkImageSparseMemoryRequirementsInfo2KHR;

typedef Decoded_VkMemoryRequirements2 Decoded_VkMemoryRequirements2KHR;

typedef Decoded_VkSparseImageMemoryRequirements2 Decoded_VkSparseImageMemoryRequirements2KHR;

typedef Decoded_VkImageFormatListCreateInfo Decoded_VkImageFormatListCreateInfoKHR;

typedef Decoded_VkSamplerYcbcrConversionCreateInfo Decoded_VkSamplerYcbcrConversionCreateInfoKHR;

typedef Decoded_VkSamplerYcbcrConversionInfo Decoded_VkSamplerYcbcrConversionInfoKHR;

typedef Decoded_VkBindImagePlaneMemoryInfo Decoded_VkBindImagePlaneMemoryInfoKHR;

typedef Decoded_VkImagePlaneMemoryRequirementsInfo Decoded_VkImagePlaneMemoryRequirementsInfoKHR;

typedef Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR;

typedef Decoded_VkSamplerYcbcrConversionImageFormatProperties Decoded_VkSamplerYcbcrConversionImageFormatPropertiesKHR;

typedef Decoded_VkBindBufferMemoryInfo Decoded_VkBindBufferMemoryInfoKHR;

typedef Decoded_VkBindImageMemoryInfo Decoded_VkBindImageMemoryInfoKHR;

typedef Decoded_VkPhysicalDeviceMaintenance3Properties Decoded_VkPhysicalDeviceMaintenance3PropertiesKHR;

typedef Decoded_VkDescriptorSetLayoutSupport Decoded_VkDescriptorSetLayoutSupportKHR;

typedef Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR;

typedef Decoded_VkPhysicalDevice8BitStorageFeatures Decoded_VkPhysicalDevice8BitStorageFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderAtomicInt64Features Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR;

struct Decoded_VkPhysicalDeviceShaderClockFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderClockFeaturesKHR;

    VkPhysicalDeviceShaderClockFeaturesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkConformanceVersion Decoded_VkConformanceVersionKHR;

typedef Decoded_VkPhysicalDeviceDriverProperties Decoded_VkPhysicalDeviceDriverPropertiesKHR;

typedef Decoded_VkPhysicalDeviceFloatControlsProperties Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR;

typedef Decoded_VkSubpassDescriptionDepthStencilResolve Decoded_VkSubpassDescriptionDepthStencilResolveKHR;

typedef Decoded_VkPhysicalDeviceDepthStencilResolveProperties Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR;

typedef Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures Decoded_VkPhysicalDeviceTimelineSemaphoreFeaturesKHR;

typedef Decoded_VkPhysicalDeviceTimelineSemaphoreProperties Decoded_VkPhysicalDeviceTimelineSemaphorePropertiesKHR;

typedef Decoded_VkSemaphoreTypeCreateInfo Decoded_VkSemaphoreTypeCreateInfoKHR;

typedef Decoded_VkTimelineSemaphoreSubmitInfo Decoded_VkTimelineSemaphoreSubmitInfoKHR;

typedef Decoded_VkSemaphoreWaitInfo Decoded_VkSemaphoreWaitInfoKHR;

typedef Decoded_VkSemaphoreSignalInfo Decoded_VkSemaphoreSignalInfoKHR;

typedef Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR;

struct Decoded_VkSurfaceProtectedCapabilitiesKHR
{
    using struct_type = VkSurfaceProtectedCapabilitiesKHR;

    VkSurfaceProtectedCapabilitiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR;

typedef Decoded_VkAttachmentReferenceStencilLayout Decoded_VkAttachmentReferenceStencilLayoutKHR;

typedef Decoded_VkAttachmentDescriptionStencilLayout Decoded_VkAttachmentDescriptionStencilLayoutKHR;

typedef Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR;

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesKHR;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoKHR;

typedef Decoded_VkBufferOpaqueCaptureAddressCreateInfo Decoded_VkBufferOpaqueCaptureAddressCreateInfoKHR;

typedef Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo Decoded_VkMemoryOpaqueCaptureAddressAllocateInfoKHR;

typedef Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo Decoded_VkDeviceMemoryOpaqueCaptureAddressInfoKHR;

struct Decoded_VkDeferredOperationInfoKHR
{
    using struct_type = VkDeferredOperationInfoKHR;

    VkDeferredOperationInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId operationHandle{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR
{
    using struct_type = VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;

    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineInfoKHR
{
    using struct_type = VkPipelineInfoKHR;

    VkPipelineInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutablePropertiesKHR
{
    using struct_type = VkPipelineExecutablePropertiesKHR;

    VkPipelineExecutablePropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder name;
    StringDecoder description;
};

struct Decoded_VkPipelineExecutableInfoKHR
{
    using struct_type = VkPipelineExecutableInfoKHR;

    VkPipelineExecutableInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutableStatisticKHR
{
    using struct_type = VkPipelineExecutableStatisticKHR;

    VkPipelineExecutableStatisticKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder name;
    StringDecoder description;
    std::unique_ptr<Decoded_VkPipelineExecutableStatisticValueKHR> value;
};

struct Decoded_VkPipelineExecutableInternalRepresentationKHR
{
    using struct_type = VkPipelineExecutableInternalRepresentationKHR;

    VkPipelineExecutableInternalRepresentationKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder name;
    StringDecoder description;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineLibraryCreateInfoKHR
{
    using struct_type = VkPipelineLibraryCreateInfoKHR;

    VkPipelineLibraryCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkPipeline> pLibraries;
};

struct Decoded_VkDebugReportCallbackCreateInfoEXT
{
    using struct_type = VkDebugReportCallbackCreateInfoEXT;

    VkDebugReportCallbackCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD
{
    using struct_type = VkPipelineRasterizationStateRasterizationOrderAMD;

    VkPipelineRasterizationStateRasterizationOrderAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDebugMarkerObjectNameInfoEXT
{
    using struct_type = VkDebugMarkerObjectNameInfoEXT;

    VkDebugMarkerObjectNameInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugMarkerObjectTagInfoEXT
{
    using struct_type = VkDebugMarkerObjectTagInfoEXT;

    VkDebugMarkerObjectTagInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugMarkerMarkerInfoEXT
{
    using struct_type = VkDebugMarkerMarkerInfoEXT;

    VkDebugMarkerMarkerInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMarkerName;
    PointerDecoder<float> color;
};

struct Decoded_VkDedicatedAllocationImageCreateInfoNV
{
    using struct_type = VkDedicatedAllocationImageCreateInfoNV;

    VkDedicatedAllocationImageCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationBufferCreateInfoNV
{
    using struct_type = VkDedicatedAllocationBufferCreateInfoNV;

    VkDedicatedAllocationBufferCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV
{
    using struct_type = VkDedicatedAllocationMemoryAllocateInfoNV;

    VkDedicatedAllocationMemoryAllocateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackFeaturesEXT;

    VkPhysicalDeviceTransformFeedbackFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackPropertiesEXT;

    VkPhysicalDeviceTransformFeedbackPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationStateStreamCreateInfoEXT;

    VkPipelineRasterizationStateStreamCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImageViewHandleInfoNVX
{
    using struct_type = VkImageViewHandleInfoNVX;

    VkImageViewHandleInfoNVX* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId imageView{ format::kNullHandleId };
    format::HandleId sampler{ format::kNullHandleId };
};

struct Decoded_VkImageViewAddressPropertiesNVX
{
    using struct_type = VkImageViewAddressPropertiesNVX;

    VkImageViewAddressPropertiesNVX* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkTextureLODGatherFormatPropertiesAMD
{
    using struct_type = VkTextureLODGatherFormatPropertiesAMD;

    VkTextureLODGatherFormatPropertiesAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkShaderResourceUsageAMD
{
    using struct_type = VkShaderResourceUsageAMD;

    VkShaderResourceUsageAMD* decoded_value{ nullptr };
};

struct Decoded_VkShaderStatisticsInfoAMD
{
    using struct_type = VkShaderStatisticsInfoAMD;

    VkShaderStatisticsInfoAMD* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkShaderResourceUsageAMD> resourceUsage;
    PointerDecoder<uint32_t> computeWorkGroupSize;
};

struct Decoded_VkStreamDescriptorSurfaceCreateInfoGGP
{
    using struct_type = VkStreamDescriptorSurfaceCreateInfoGGP;

    VkStreamDescriptorSurfaceCreateInfoGGP* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceCornerSampledImageFeaturesNV;

    VkPhysicalDeviceCornerSampledImageFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalImageFormatPropertiesNV
{
    using struct_type = VkExternalImageFormatPropertiesNV;

    VkExternalImageFormatPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkImageFormatProperties> imageFormatProperties;
};

struct Decoded_VkExternalMemoryImageCreateInfoNV
{
    using struct_type = VkExternalMemoryImageCreateInfoNV;

    VkExternalMemoryImageCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfoNV
{
    using struct_type = VkExportMemoryAllocateInfoNV;

    VkExportMemoryAllocateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImportMemoryWin32HandleInfoNV
{
    using struct_type = VkImportMemoryWin32HandleInfoNV;

    VkImportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t handle{ 0 };
};

struct Decoded_VkExportMemoryWin32HandleInfoNV
{
    using struct_type = VkExportMemoryWin32HandleInfoNV;

    VkExportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>> pAttributes;
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoNV;

    VkWin32KeyedMutexAcquireReleaseInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeoutMilliseconds;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

struct Decoded_VkValidationFlagsEXT
{
    using struct_type = VkValidationFlagsEXT;

    VkValidationFlagsEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkValidationCheckEXT> pDisabledValidationChecks;
};

struct Decoded_VkViSurfaceCreateInfoNN
{
    using struct_type = VkViSurfaceCreateInfoNN;

    VkViSurfaceCreateInfoNN* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t window{ 0 };
};

struct Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT;

    VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImageViewASTCDecodeModeEXT
{
    using struct_type = VkImageViewASTCDecodeModeEXT;

    VkImageViewASTCDecodeModeEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceASTCDecodeFeaturesEXT;

    VkPhysicalDeviceASTCDecodeFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkConditionalRenderingBeginInfoEXT
{
    using struct_type = VkConditionalRenderingBeginInfoEXT;

    VkConditionalRenderingBeginInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceConditionalRenderingFeaturesEXT;

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT
{
    using struct_type = VkCommandBufferInheritanceConditionalRenderingInfoEXT;

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewportWScalingNV
{
    using struct_type = VkViewportWScalingNV;

    VkViewportWScalingNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV
{
    using struct_type = VkPipelineViewportWScalingStateCreateInfoNV;

    VkPipelineViewportWScalingStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkViewportWScalingNV>> pViewportWScalings;
};

struct Decoded_VkSurfaceCapabilities2EXT
{
    using struct_type = VkSurfaceCapabilities2EXT;

    VkSurfaceCapabilities2EXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> currentExtent;
    std::unique_ptr<Decoded_VkExtent2D> minImageExtent;
    std::unique_ptr<Decoded_VkExtent2D> maxImageExtent;
};

struct Decoded_VkDisplayPowerInfoEXT
{
    using struct_type = VkDisplayPowerInfoEXT;

    VkDisplayPowerInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceEventInfoEXT
{
    using struct_type = VkDeviceEventInfoEXT;

    VkDeviceEventInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayEventInfoEXT
{
    using struct_type = VkDisplayEventInfoEXT;

    VkDisplayEventInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSwapchainCounterCreateInfoEXT
{
    using struct_type = VkSwapchainCounterCreateInfoEXT;

    VkSwapchainCounterCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRefreshCycleDurationGOOGLE
{
    using struct_type = VkRefreshCycleDurationGOOGLE;

    VkRefreshCycleDurationGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPastPresentationTimingGOOGLE
{
    using struct_type = VkPastPresentationTimingGOOGLE;

    VkPastPresentationTimingGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimeGOOGLE
{
    using struct_type = VkPresentTimeGOOGLE;

    VkPresentTimeGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimesInfoGOOGLE
{
    using struct_type = VkPresentTimesInfoGOOGLE;

    VkPresentTimesInfoGOOGLE* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPresentTimeGOOGLE>> pTimes;
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewportSwizzleNV
{
    using struct_type = VkViewportSwizzleNV;

    VkViewportSwizzleNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV
{
    using struct_type = VkPipelineViewportSwizzleStateCreateInfoNV;

    VkPipelineViewportSwizzleStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkViewportSwizzleNV>> pViewportSwizzles;
};

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
    using struct_type = VkPhysicalDeviceDiscardRectanglePropertiesEXT;

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT
{
    using struct_type = VkPipelineDiscardRectangleStateCreateInfoEXT;

    VkPipelineDiscardRectangleStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRect2D>> pDiscardRectangles;
};

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceConservativeRasterizationPropertiesEXT;

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationConservativeStateCreateInfoEXT;

    VkPipelineRasterizationConservativeStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipEnableFeaturesEXT;

    VkPhysicalDeviceDepthClipEnableFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationDepthClipStateCreateInfoEXT;

    VkPipelineRasterizationDepthClipStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkXYColorEXT
{
    using struct_type = VkXYColorEXT;

    VkXYColorEXT* decoded_value{ nullptr };
};

struct Decoded_VkHdrMetadataEXT
{
    using struct_type = VkHdrMetadataEXT;

    VkHdrMetadataEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkXYColorEXT> displayPrimaryRed;
    std::unique_ptr<Decoded_VkXYColorEXT> displayPrimaryGreen;
    std::unique_ptr<Decoded_VkXYColorEXT> displayPrimaryBlue;
    std::unique_ptr<Decoded_VkXYColorEXT> whitePoint;
};

struct Decoded_VkIOSSurfaceCreateInfoMVK
{
    using struct_type = VkIOSSurfaceCreateInfoMVK;

    VkIOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView{ 0 };
};

struct Decoded_VkMacOSSurfaceCreateInfoMVK
{
    using struct_type = VkMacOSSurfaceCreateInfoMVK;

    VkMacOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView{ 0 };
};

struct Decoded_VkDebugUtilsLabelEXT
{
    using struct_type = VkDebugUtilsLabelEXT;

    VkDebugUtilsLabelEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pLabelName;
    PointerDecoder<float> color;
};

struct Decoded_VkDebugUtilsObjectNameInfoEXT
{
    using struct_type = VkDebugUtilsObjectNameInfoEXT;

    VkDebugUtilsObjectNameInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = VkDebugUtilsMessengerCallbackDataEXT;

    VkDebugUtilsMessengerCallbackDataEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMessageIdName;
    StringDecoder pMessage;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>> pQueueLabels;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>> pCmdBufLabels;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>> pObjects;
};

struct Decoded_VkDebugUtilsMessengerCreateInfoEXT
{
    using struct_type = VkDebugUtilsMessengerCreateInfoEXT;

    VkDebugUtilsMessengerCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkDebugUtilsObjectTagInfoEXT
{
    using struct_type = VkDebugUtilsObjectTagInfoEXT;

    VkDebugUtilsObjectTagInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkAndroidHardwareBufferUsageANDROID
{
    using struct_type = VkAndroidHardwareBufferUsageANDROID;

    VkAndroidHardwareBufferUsageANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferPropertiesANDROID;

    VkAndroidHardwareBufferPropertiesANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatPropertiesANDROID;

    VkAndroidHardwareBufferFormatPropertiesANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkComponentMapping> samplerYcbcrConversionComponents;
};

struct Decoded_VkImportAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkImportAndroidHardwareBufferInfoANDROID;

    VkImportAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t buffer{ 0 };
};

struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkMemoryGetAndroidHardwareBufferInfoANDROID;

    VkMemoryGetAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkExternalFormatANDROID
{
    using struct_type = VkExternalFormatANDROID;

    VkExternalFormatANDROID* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkSamplerReductionModeCreateInfo Decoded_VkSamplerReductionModeCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

struct Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockFeaturesEXT;

    VkPhysicalDeviceInlineUniformBlockFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockPropertiesEXT;

    VkPhysicalDeviceInlineUniformBlockPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkWriteDescriptorSetInlineUniformBlockEXT
{
    using struct_type = VkWriteDescriptorSetInlineUniformBlockEXT;

    VkWriteDescriptorSetInlineUniformBlockEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT
{
    using struct_type = VkDescriptorPoolInlineUniformBlockCreateInfoEXT;

    VkDescriptorPoolInlineUniformBlockCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSampleLocationEXT
{
    using struct_type = VkSampleLocationEXT;

    VkSampleLocationEXT* decoded_value{ nullptr };
};

struct Decoded_VkSampleLocationsInfoEXT
{
    using struct_type = VkSampleLocationsInfoEXT;

    VkSampleLocationsInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> sampleLocationGridSize;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSampleLocationEXT>> pSampleLocations;
};

struct Decoded_VkAttachmentSampleLocationsEXT
{
    using struct_type = VkAttachmentSampleLocationsEXT;

    VkAttachmentSampleLocationsEXT* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkSampleLocationsInfoEXT> sampleLocationsInfo;
};

struct Decoded_VkSubpassSampleLocationsEXT
{
    using struct_type = VkSubpassSampleLocationsEXT;

    VkSubpassSampleLocationsEXT* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkSampleLocationsInfoEXT> sampleLocationsInfo;
};

struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT
{
    using struct_type = VkRenderPassSampleLocationsBeginInfoEXT;

    VkRenderPassSampleLocationsBeginInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT>> pAttachmentInitialSampleLocations;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT>> pPostSubpassSampleLocations;
};

struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT
{
    using struct_type = VkPipelineSampleLocationsStateCreateInfoEXT;

    VkPipelineSampleLocationsStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkSampleLocationsInfoEXT> sampleLocationsInfo;
};

struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSampleLocationsPropertiesEXT;

    VkPhysicalDeviceSampleLocationsPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> maxSampleLocationGridSize;
    PointerDecoder<float> sampleLocationCoordinateRange;
};

struct Decoded_VkMultisamplePropertiesEXT
{
    using struct_type = VkMultisamplePropertiesEXT;

    VkMultisamplePropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> maxSampleLocationGridSize;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
    using struct_type = VkPipelineColorBlendAdvancedStateCreateInfoEXT;

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageToColorStateCreateInfoNV;

    VkPipelineCoverageToColorStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageModulationStateCreateInfoNV;

    VkPipelineCoverageModulationStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pCoverageModulationTable;
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;

    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;

    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDrmFormatModifierPropertiesEXT
{
    using struct_type = VkDrmFormatModifierPropertiesEXT;

    VkDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesListEXT
{
    using struct_type = VkDrmFormatModifierPropertiesListEXT;

    VkDrmFormatModifierPropertiesListEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkDrmFormatModifierPropertiesEXT>> pDrmFormatModifierProperties;
};

struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT
{
    using struct_type = VkPhysicalDeviceImageDrmFormatModifierInfoEXT;

    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierListCreateInfoEXT;

    VkImageDrmFormatModifierListCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pDrmFormatModifiers;
};

struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierExplicitCreateInfoEXT;

    VkImageDrmFormatModifierExplicitCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkSubresourceLayout>> pPlaneLayouts;
};

struct Decoded_VkImageDrmFormatModifierPropertiesEXT
{
    using struct_type = VkImageDrmFormatModifierPropertiesEXT;

    VkImageDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkValidationCacheCreateInfoEXT
{
    using struct_type = VkValidationCacheCreateInfoEXT;

    VkValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT
{
    using struct_type = VkShaderModuleValidationCacheCreateInfoEXT;

    VkShaderModuleValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId validationCache{ format::kNullHandleId };
};

typedef Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingFeatures Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingProperties Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

struct Decoded_VkShadingRatePaletteNV
{
    using struct_type = VkShadingRatePaletteNV;

    VkShadingRatePaletteNV* decoded_value{ nullptr };

    PointerDecoder<VkShadingRatePaletteEntryNV> pShadingRatePaletteEntries;
};

struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV
{
    using struct_type = VkPipelineViewportShadingRateImageStateCreateInfoNV;

    VkPipelineViewportShadingRateImageStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkShadingRatePaletteNV>> pShadingRatePalettes;
};

struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImageFeaturesNV;

    VkPhysicalDeviceShadingRateImageFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImagePropertiesNV;

    VkPhysicalDeviceShadingRateImagePropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> shadingRateTexelSize;
};

struct Decoded_VkCoarseSampleLocationNV
{
    using struct_type = VkCoarseSampleLocationNV;

    VkCoarseSampleLocationNV* decoded_value{ nullptr };
};

struct Decoded_VkCoarseSampleOrderCustomNV
{
    using struct_type = VkCoarseSampleOrderCustomNV;

    VkCoarseSampleOrderCustomNV* decoded_value{ nullptr };

    std::unique_ptr<StructPointerDecoder<Decoded_VkCoarseSampleLocationNV>> pSampleLocations;
};

struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV
{
    using struct_type = VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>> pCustomSampleOrders;
};

struct Decoded_VkRayTracingShaderGroupCreateInfoNV
{
    using struct_type = VkRayTracingShaderGroupCreateInfoNV;

    VkRayTracingShaderGroupCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRayTracingPipelineCreateInfoNV
{
    using struct_type = VkRayTracingPipelineCreateInfoNV;

    VkRayTracingPipelineCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>> pStages;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoNV>> pGroups;
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkGeometryTrianglesNV
{
    using struct_type = VkGeometryTrianglesNV;

    VkGeometryTrianglesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId vertexData{ format::kNullHandleId };
    format::HandleId indexData{ format::kNullHandleId };
    format::HandleId transformData{ format::kNullHandleId };
};

struct Decoded_VkGeometryAABBNV
{
    using struct_type = VkGeometryAABBNV;

    VkGeometryAABBNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId aabbData{ format::kNullHandleId };
};

struct Decoded_VkGeometryDataNV
{
    using struct_type = VkGeometryDataNV;

    VkGeometryDataNV* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkGeometryTrianglesNV> triangles;
    std::unique_ptr<Decoded_VkGeometryAABBNV> aabbs;
};

struct Decoded_VkGeometryNV
{
    using struct_type = VkGeometryNV;

    VkGeometryNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkGeometryDataNV> geometry;
};

struct Decoded_VkAccelerationStructureInfoNV
{
    using struct_type = VkAccelerationStructureInfoNV;

    VkAccelerationStructureInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkGeometryNV>> pGeometries;
};

struct Decoded_VkAccelerationStructureCreateInfoNV
{
    using struct_type = VkAccelerationStructureCreateInfoNV;

    VkAccelerationStructureCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkAccelerationStructureInfoNV> info;
};

struct Decoded_VkBindAccelerationStructureMemoryInfoKHR
{
    using struct_type = VkBindAccelerationStructureMemoryInfoKHR;

    VkBindAccelerationStructureMemoryInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureKHR
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureKHR;

    VkWriteDescriptorSetAccelerationStructureKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
};

struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV
{
    using struct_type = VkAccelerationStructureMemoryRequirementsInfoNV;

    VkAccelerationStructureMemoryRequirementsInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingPropertiesNV;

    VkPhysicalDeviceRayTracingPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkTransformMatrixKHR
{
    using struct_type = VkTransformMatrixKHR;

    VkTransformMatrixKHR* decoded_value{ nullptr };

    PointerDecoder<float> matrix;
};

struct Decoded_VkAabbPositionsKHR
{
    using struct_type = VkAabbPositionsKHR;

    VkAabbPositionsKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureInstanceKHR
{
    using struct_type = VkAccelerationStructureInstanceKHR;

    VkAccelerationStructureInstanceKHR* decoded_value{ nullptr };

    std::unique_ptr<Decoded_VkTransformMatrixKHR> transform;
};

typedef Decoded_VkBindAccelerationStructureMemoryInfoKHR Decoded_VkBindAccelerationStructureMemoryInfoNV;

typedef Decoded_VkWriteDescriptorSetAccelerationStructureKHR Decoded_VkWriteDescriptorSetAccelerationStructureNV;

typedef Decoded_VkTransformMatrixKHR Decoded_VkTransformMatrixNV;

typedef Decoded_VkAabbPositionsKHR Decoded_VkAabbPositionsNV;

typedef Decoded_VkAccelerationStructureInstanceKHR Decoded_VkAccelerationStructureInstanceNV;

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV
{
    using struct_type = VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;

    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV
{
    using struct_type = VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT
{
    using struct_type = VkPhysicalDeviceImageViewImageFormatInfoEXT;

    VkPhysicalDeviceImageViewImageFormatInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT
{
    using struct_type = VkFilterCubicImageViewImageFormatPropertiesEXT;

    VkFilterCubicImageViewImageFormatPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT
{
    using struct_type = VkDeviceQueueGlobalPriorityCreateInfoEXT;

    VkDeviceQueueGlobalPriorityCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImportMemoryHostPointerInfoEXT
{
    using struct_type = VkImportMemoryHostPointerInfoEXT;

    VkImportMemoryHostPointerInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pHostPointer{ 0 };
};

struct Decoded_VkMemoryHostPointerPropertiesEXT
{
    using struct_type = VkMemoryHostPointerPropertiesEXT;

    VkMemoryHostPointerPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
    using struct_type = VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCompilerControlCreateInfoAMD
{
    using struct_type = VkPipelineCompilerControlCreateInfoAMD;

    VkPipelineCompilerControlCreateInfoAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCalibratedTimestampInfoEXT
{
    using struct_type = VkCalibratedTimestampInfoEXT;

    VkCalibratedTimestampInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesAMD;

    VkPhysicalDeviceShaderCorePropertiesAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD
{
    using struct_type = VkDeviceMemoryOverallocationCreateInfoAMD;

    VkDeviceMemoryOverallocationCreateInfoAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkVertexInputBindingDivisorDescriptionEXT
{
    using struct_type = VkVertexInputBindingDivisorDescriptionEXT;

    VkVertexInputBindingDivisorDescriptionEXT* decoded_value{ nullptr };
};

struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT
{
    using struct_type = VkPipelineVertexInputDivisorStateCreateInfoEXT;

    VkPipelineVertexInputDivisorStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescriptionEXT>> pVertexBindingDivisors;
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;

    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPresentFrameTokenGGP
{
    using struct_type = VkPresentFrameTokenGGP;

    VkPresentFrameTokenGGP* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCreationFeedbackEXT
{
    using struct_type = VkPipelineCreationFeedbackEXT;

    VkPipelineCreationFeedbackEXT* decoded_value{ nullptr };
};

struct Decoded_VkPipelineCreationFeedbackCreateInfoEXT
{
    using struct_type = VkPipelineCreationFeedbackCreateInfoEXT;

    VkPipelineCreationFeedbackCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineCreationFeedbackEXT>> pPipelineCreationFeedback;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineCreationFeedbackEXT>> pPipelineStageCreationFeedbacks;
};

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV
{
    using struct_type = VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesNV;

    VkPhysicalDeviceMeshShaderFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesNV;

    VkPhysicalDeviceMeshShaderPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> maxTaskWorkGroupSize;
    PointerDecoder<uint32_t> maxMeshWorkGroupSize;
};

struct Decoded_VkDrawMeshTasksIndirectCommandNV
{
    using struct_type = VkDrawMeshTasksIndirectCommandNV;

    VkDrawMeshTasksIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;

    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderImageFootprintFeaturesNV;

    VkPhysicalDeviceShaderImageFootprintFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV
{
    using struct_type = VkPipelineViewportExclusiveScissorStateCreateInfoNV;

    VkPipelineViewportExclusiveScissorStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRect2D>> pExclusiveScissors;
};

struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceExclusiveScissorFeaturesNV;

    VkPhysicalDeviceExclusiveScissorFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueueFamilyCheckpointPropertiesNV
{
    using struct_type = VkQueueFamilyCheckpointPropertiesNV;

    VkQueueFamilyCheckpointPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCheckpointDataNV
{
    using struct_type = VkCheckpointDataNV;

    VkCheckpointDataNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pCheckpointMarker{ 0 };
};

struct Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL
{
    using struct_type = VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;

    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkInitializePerformanceApiInfoINTEL
{
    using struct_type = VkInitializePerformanceApiInfoINTEL;

    VkInitializePerformanceApiInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pUserData{ 0 };
};

struct Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL
{
    using struct_type = VkQueryPoolPerformanceQueryCreateInfoINTEL;

    VkQueryPoolPerformanceQueryCreateInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceMarkerInfoINTEL
{
    using struct_type = VkPerformanceMarkerInfoINTEL;

    VkPerformanceMarkerInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceStreamMarkerInfoINTEL
{
    using struct_type = VkPerformanceStreamMarkerInfoINTEL;

    VkPerformanceStreamMarkerInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceOverrideInfoINTEL
{
    using struct_type = VkPerformanceOverrideInfoINTEL;

    VkPerformanceOverrideInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPerformanceConfigurationAcquireInfoINTEL
{
    using struct_type = VkPerformanceConfigurationAcquireInfoINTEL;

    VkPerformanceConfigurationAcquireInfoINTEL* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL Decoded_VkQueryPoolCreateInfoINTEL;

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT
{
    using struct_type = VkPhysicalDevicePCIBusInfoPropertiesEXT;

    VkPhysicalDevicePCIBusInfoPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD
{
    using struct_type = VkDisplayNativeHdrSurfaceCapabilitiesAMD;

    VkDisplayNativeHdrSurfaceCapabilitiesAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD
{
    using struct_type = VkSwapchainDisplayNativeHdrCreateInfoAMD;

    VkSwapchainDisplayNativeHdrCreateInfoAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA
{
    using struct_type = VkImagePipeSurfaceCreateInfoFUCHSIA;

    VkImagePipeSurfaceCreateInfoFUCHSIA* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMetalSurfaceCreateInfoEXT
{
    using struct_type = VkMetalSurfaceCreateInfoEXT;

    VkMetalSurfaceCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pLayer{ 0 };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapFeaturesEXT;

    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapPropertiesEXT;

    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkExtent2D> minFragmentDensityTexelSize;
    std::unique_ptr<Decoded_VkExtent2D> maxFragmentDensityTexelSize;
};

struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT
{
    using struct_type = VkRenderPassFragmentDensityMapCreateInfoEXT;

    VkRenderPassFragmentDensityMapCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkAttachmentReference> fragmentDensityMapAttachment;
};

typedef Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT;

struct Decoded_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlFeaturesEXT;

    VkPhysicalDeviceSubgroupSizeControlFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlPropertiesEXT;

    VkPhysicalDeviceSubgroupSizeControlPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT
{
    using struct_type = VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT;

    VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderCoreProperties2AMD
{
    using struct_type = VkPhysicalDeviceShaderCoreProperties2AMD;

    VkPhysicalDeviceShaderCoreProperties2AMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD
{
    using struct_type = VkPhysicalDeviceCoherentMemoryFeaturesAMD;

    VkPhysicalDeviceCoherentMemoryFeaturesAMD* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMemoryBudgetPropertiesEXT;

    VkPhysicalDeviceMemoryBudgetPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDeviceSize> heapBudget;
    PointerDecoder<VkDeviceSize> heapUsage;
};

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMemoryPriorityFeaturesEXT;

    VkPhysicalDeviceMemoryPriorityFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryPriorityAllocateInfoEXT
{
    using struct_type = VkMemoryPriorityAllocateInfoEXT;

    VkMemoryPriorityAllocateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV
{
    using struct_type = VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;

    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferDeviceAddressCreateInfoEXT
{
    using struct_type = VkBufferDeviceAddressCreateInfoEXT;

    VkBufferDeviceAddressCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoEXT;

struct Decoded_VkPhysicalDeviceToolPropertiesEXT
{
    using struct_type = VkPhysicalDeviceToolPropertiesEXT;

    VkPhysicalDeviceToolPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder name;
    StringDecoder version;
    StringDecoder description;
    StringDecoder layer;
};

typedef Decoded_VkImageStencilUsageCreateInfo Decoded_VkImageStencilUsageCreateInfoEXT;

struct Decoded_VkValidationFeaturesEXT
{
    using struct_type = VkValidationFeaturesEXT;

    VkValidationFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkValidationFeatureEnableEXT> pEnabledValidationFeatures;
    PointerDecoder<VkValidationFeatureDisableEXT> pDisabledValidationFeatures;
};

struct Decoded_VkCooperativeMatrixPropertiesNV
{
    using struct_type = VkCooperativeMatrixPropertiesNV;

    VkCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesNV;

    VkPhysicalDeviceCooperativeMatrixFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesNV;

    VkPhysicalDeviceCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV
{
    using struct_type = VkPhysicalDeviceCoverageReductionModeFeaturesNV;

    VkPhysicalDeviceCoverageReductionModeFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageReductionStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageReductionStateCreateInfoNV;

    VkPipelineCoverageReductionStateCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkFramebufferMixedSamplesCombinationNV
{
    using struct_type = VkFramebufferMixedSamplesCombinationNV;

    VkFramebufferMixedSamplesCombinationNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;

    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSurfaceFullScreenExclusiveInfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveInfoEXT;

    VkSurfaceFullScreenExclusiveInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT
{
    using struct_type = VkSurfaceCapabilitiesFullScreenExclusiveEXT;

    VkSurfaceCapabilitiesFullScreenExclusiveEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveWin32InfoEXT;

    VkSurfaceFullScreenExclusiveWin32InfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t hmonitor{ 0 };
};

struct Decoded_VkHeadlessSurfaceCreateInfoEXT
{
    using struct_type = VkHeadlessSurfaceCreateInfoEXT;

    VkHeadlessSurfaceCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT
{
    using struct_type = VkPhysicalDeviceLineRasterizationFeaturesEXT;

    VkPhysicalDeviceLineRasterizationFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceLineRasterizationPropertiesEXT;

    VkPhysicalDeviceLineRasterizationPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationLineStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationLineStateCreateInfoEXT;

    VkPipelineRasterizationLineStateCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;

    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceHostQueryResetFeatures Decoded_VkPhysicalDeviceHostQueryResetFeaturesEXT;

struct Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT
{
    using struct_type = VkPhysicalDeviceIndexTypeUint8FeaturesEXT;

    VkPhysicalDeviceIndexTypeUint8FeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;

    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT;

    VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkGraphicsShaderGroupCreateInfoNV
{
    using struct_type = VkGraphicsShaderGroupCreateInfoNV;

    VkGraphicsShaderGroupCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>> pStages;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>> pVertexInputState;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>> pTessellationState;
};

struct Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV
{
    using struct_type = VkGraphicsPipelineShaderGroupsCreateInfoNV;

    VkGraphicsPipelineShaderGroupsCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkGraphicsShaderGroupCreateInfoNV>> pGroups;
    HandlePointerDecoder<VkPipeline> pPipelines;
};

struct Decoded_VkBindShaderGroupIndirectCommandNV
{
    using struct_type = VkBindShaderGroupIndirectCommandNV;

    VkBindShaderGroupIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindIndexBufferIndirectCommandNV
{
    using struct_type = VkBindIndexBufferIndirectCommandNV;

    VkBindIndexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindVertexBufferIndirectCommandNV
{
    using struct_type = VkBindVertexBufferIndirectCommandNV;

    VkBindVertexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkSetStateFlagsIndirectCommandNV
{
    using struct_type = VkSetStateFlagsIndirectCommandNV;

    VkSetStateFlagsIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsStreamNV
{
    using struct_type = VkIndirectCommandsStreamNV;

    VkIndirectCommandsStreamNV* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkIndirectCommandsLayoutTokenNV
{
    using struct_type = VkIndirectCommandsLayoutTokenNV;

    VkIndirectCommandsLayoutTokenNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId pushconstantPipelineLayout{ format::kNullHandleId };
    PointerDecoder<VkIndexType> pIndexTypes;
    PointerDecoder<uint32_t> pIndexTypeValues;
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoNV
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoNV;

    VkIndirectCommandsLayoutCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNV>> pTokens;
    PointerDecoder<uint32_t> pStreamStrides;
};

struct Decoded_VkGeneratedCommandsInfoNV
{
    using struct_type = VkGeneratedCommandsInfoNV;

    VkGeneratedCommandsInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId pipeline{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
    std::unique_ptr<StructPointerDecoder<Decoded_VkIndirectCommandsStreamNV>> pStreams;
    format::HandleId preprocessBuffer{ format::kNullHandleId };
    format::HandleId sequencesCountBuffer{ format::kNullHandleId };
    format::HandleId sequencesIndexBuffer{ format::kNullHandleId };
};

struct Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV
{
    using struct_type = VkGeneratedCommandsMemoryRequirementsInfoNV;

    VkGeneratedCommandsMemoryRequirementsInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId pipeline{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;

    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT;

    VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassTransformBeginInfoQCOM
{
    using struct_type = VkRenderPassTransformBeginInfoQCOM;

    VkRenderPassTransformBeginInfoQCOM* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM
{
    using struct_type = VkCommandBufferInheritanceRenderPassTransformInfoQCOM;

    VkCommandBufferInheritanceRenderPassTransformInfoQCOM* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkRect2D> renderArea;
};

struct Decoded_VkPhysicalDeviceRobustness2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceRobustness2FeaturesEXT;

    VkPhysicalDeviceRobustness2FeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceRobustness2PropertiesEXT
{
    using struct_type = VkPhysicalDeviceRobustness2PropertiesEXT;

    VkPhysicalDeviceRobustness2PropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerCustomBorderColorCreateInfoEXT
{
    using struct_type = VkSamplerCustomBorderColorCreateInfoEXT;

    VkSamplerCustomBorderColorCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkClearColorValue> customBorderColor;
};

struct Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorPropertiesEXT;

    VkPhysicalDeviceCustomBorderColorPropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorFeaturesEXT;

    VkPhysicalDeviceCustomBorderColorFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePrivateDataFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrivateDataFeaturesEXT;

    VkPhysicalDevicePrivateDataFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDevicePrivateDataCreateInfoEXT
{
    using struct_type = VkDevicePrivateDataCreateInfoEXT;

    VkDevicePrivateDataCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPrivateDataSlotCreateInfoEXT
{
    using struct_type = VkPrivateDataSlotCreateInfoEXT;

    VkPrivateDataSlotCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT
{
    using struct_type = VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT;

    VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV
{
    using struct_type = VkPhysicalDeviceDiagnosticsConfigFeaturesNV;

    VkPhysicalDeviceDiagnosticsConfigFeaturesNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceDiagnosticsConfigCreateInfoNV
{
    using struct_type = VkDeviceDiagnosticsConfigCreateInfoNV;

    VkDeviceDiagnosticsConfigCreateInfoNV* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;

    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;

    VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceImageRobustnessFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageRobustnessFeaturesEXT;

    VkPhysicalDeviceImageRobustnessFeaturesEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDirectFBSurfaceCreateInfoEXT
{
    using struct_type = VkDirectFBSurfaceCreateInfoEXT;

    VkDirectFBSurfaceCreateInfoEXT* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t dfb{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkAccelerationStructureBuildOffsetInfoKHR
{
    using struct_type = VkAccelerationStructureBuildOffsetInfoKHR;

    VkAccelerationStructureBuildOffsetInfoKHR* decoded_value{ nullptr };
};

struct Decoded_VkRayTracingShaderGroupCreateInfoKHR
{
    using struct_type = VkRayTracingShaderGroupCreateInfoKHR;

    VkRayTracingShaderGroupCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pShaderGroupCaptureReplayHandle{ 0 };
};

struct Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineInterfaceCreateInfoKHR;

    VkRayTracingPipelineInterfaceCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRayTracingPipelineCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineCreateInfoKHR;

    VkRayTracingPipelineCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>> pStages;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoKHR>> pGroups;
    std::unique_ptr<Decoded_VkPipelineLibraryCreateInfoKHR> libraries;
    std::unique_ptr<StructPointerDecoder<Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR>> pLibraryInterface;
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkAccelerationStructureGeometryTrianglesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryTrianglesDataKHR;

    VkAccelerationStructureGeometryTrianglesDataKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> vertexData;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> indexData;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> transformData;
};

struct Decoded_VkAccelerationStructureGeometryAabbsDataKHR
{
    using struct_type = VkAccelerationStructureGeometryAabbsDataKHR;

    VkAccelerationStructureGeometryAabbsDataKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> data;
};

struct Decoded_VkAccelerationStructureGeometryInstancesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryInstancesDataKHR;

    VkAccelerationStructureGeometryInstancesDataKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> data;
};

struct Decoded_VkAccelerationStructureGeometryKHR
{
    using struct_type = VkAccelerationStructureGeometryKHR;

    VkAccelerationStructureGeometryKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkAccelerationStructureGeometryDataKHR> geometry;
};

struct Decoded_VkAccelerationStructureCreateGeometryTypeInfoKHR
{
    using struct_type = VkAccelerationStructureCreateGeometryTypeInfoKHR;

    VkAccelerationStructureCreateGeometryTypeInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAccelerationStructureCreateInfoKHR
{
    using struct_type = VkAccelerationStructureCreateInfoKHR;

    VkAccelerationStructureCreateInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<StructPointerDecoder<Decoded_VkAccelerationStructureCreateGeometryTypeInfoKHR>> pGeometryInfos;
};

struct Decoded_VkAccelerationStructureMemoryRequirementsInfoKHR
{
    using struct_type = VkAccelerationStructureMemoryRequirementsInfoKHR;

    VkAccelerationStructureMemoryRequirementsInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceRayTracingFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingFeaturesKHR;

    VkPhysicalDeviceRayTracingFeaturesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceRayTracingPropertiesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPropertiesKHR;

    VkPhysicalDeviceRayTracingPropertiesKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAccelerationStructureDeviceAddressInfoKHR
{
    using struct_type = VkAccelerationStructureDeviceAddressInfoKHR;

    VkAccelerationStructureDeviceAddressInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkAccelerationStructureVersionKHR
{
    using struct_type = VkAccelerationStructureVersionKHR;

    VkAccelerationStructureVersionKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> versionData;
};

struct Decoded_VkStridedBufferRegionKHR
{
    using struct_type = VkStridedBufferRegionKHR;

    VkStridedBufferRegionKHR* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkTraceRaysIndirectCommandKHR
{
    using struct_type = VkTraceRaysIndirectCommandKHR;

    VkTraceRaysIndirectCommandKHR* decoded_value{ nullptr };
};

struct Decoded_VkCopyAccelerationStructureToMemoryInfoKHR
{
    using struct_type = VkCopyAccelerationStructureToMemoryInfoKHR;

    VkCopyAccelerationStructureToMemoryInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId src{ format::kNullHandleId };
    std::unique_ptr<Decoded_VkDeviceOrHostAddressKHR> dst;
};

struct Decoded_VkCopyMemoryToAccelerationStructureInfoKHR
{
    using struct_type = VkCopyMemoryToAccelerationStructureInfoKHR;

    VkCopyMemoryToAccelerationStructureInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    std::unique_ptr<Decoded_VkDeviceOrHostAddressConstKHR> src;
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkCopyAccelerationStructureInfoKHR
{
    using struct_type = VkCopyAccelerationStructureInfoKHR;

    VkCopyAccelerationStructureInfoKHR* decoded_value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId src{ format::kNullHandleId };
    format::HandleId dst{ format::kNullHandleId };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
