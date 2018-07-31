/*
** Copyright (c) 2018 LunarG, Inc.
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

#include <memory>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/pnext_node.h"
#include "format/pointer_decoder.h"
#include "format/string_array_decoder.h"
#include "format/string_decoder.h"
#include "format/struct_pointer_decoder.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

struct Decoded_VkApplicationInfo
{
    using struct_type = VkApplicationInfo;

    VkApplicationInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pApplicationName;
    StringDecoder pEngineName;
};

struct Decoded_VkInstanceCreateInfo
{
    using struct_type = VkInstanceCreateInfo;

    VkInstanceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkApplicationInfo> pApplicationInfo;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
};

struct Decoded_VkAllocationCallbacks
{
    using struct_type = VkAllocationCallbacks;

    VkAllocationCallbacks* value{ nullptr };

    uint64_t pUserData;
    uint64_t pfnAllocation;
    uint64_t pfnReallocation;
    uint64_t pfnFree;
    uint64_t pfnInternalAllocation;
    uint64_t pfnInternalFree;
};

struct Decoded_VkPhysicalDeviceFeatures
{
    using struct_type = VkPhysicalDeviceFeatures;

    VkPhysicalDeviceFeatures* value{ nullptr };
};

struct Decoded_VkFormatProperties
{
    using struct_type = VkFormatProperties;

    VkFormatProperties* value{ nullptr };
};

struct Decoded_VkExtent3D
{
    using struct_type = VkExtent3D;

    VkExtent3D* value{ nullptr };
};

struct Decoded_VkImageFormatProperties
{
    using struct_type = VkImageFormatProperties;

    VkImageFormatProperties* value{ nullptr };

    Decoded_VkExtent3D maxExtent;
};

struct Decoded_VkPhysicalDeviceLimits
{
    using struct_type = VkPhysicalDeviceLimits;

    VkPhysicalDeviceLimits* value{ nullptr };

    PointerDecoder<uint32_t> maxComputeWorkGroupCount;
    PointerDecoder<uint32_t> maxComputeWorkGroupSize;
    PointerDecoder<uint32_t> maxViewportDimensions;
    PointerDecoder<float> viewportBoundsRange;
    PointerDecoder<float> pointSizeRange;
    PointerDecoder<float> lineWidthRange;
};

struct Decoded_VkPhysicalDeviceSparseProperties
{
    using struct_type = VkPhysicalDeviceSparseProperties;

    VkPhysicalDeviceSparseProperties* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties
{
    using struct_type = VkPhysicalDeviceProperties;

    VkPhysicalDeviceProperties* value{ nullptr };

    StringDecoder deviceName;
    PointerDecoder<uint8_t> pipelineCacheUUID;
    Decoded_VkPhysicalDeviceLimits limits;
    Decoded_VkPhysicalDeviceSparseProperties sparseProperties;
};

struct Decoded_VkQueueFamilyProperties
{
    using struct_type = VkQueueFamilyProperties;

    VkQueueFamilyProperties* value{ nullptr };

    Decoded_VkExtent3D minImageTransferGranularity;
};

struct Decoded_VkMemoryType
{
    using struct_type = VkMemoryType;

    VkMemoryType* value{ nullptr };
};

struct Decoded_VkMemoryHeap
{
    using struct_type = VkMemoryHeap;

    VkMemoryHeap* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryProperties
{
    using struct_type = VkPhysicalDeviceMemoryProperties;

    VkPhysicalDeviceMemoryProperties* value{ nullptr };

    StructPointerDecoder<Decoded_VkMemoryType> memoryTypes;
    StructPointerDecoder<Decoded_VkMemoryHeap> memoryHeaps;
};

struct Decoded_VkDeviceQueueCreateInfo
{
    using struct_type = VkDeviceQueueCreateInfo;

    VkDeviceQueueCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pQueuePriorities;
};

struct Decoded_VkDeviceCreateInfo
{
    using struct_type = VkDeviceCreateInfo;

    VkDeviceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDeviceQueueCreateInfo> pQueueCreateInfos;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pEnabledFeatures;
};

struct Decoded_VkExtensionProperties
{
    using struct_type = VkExtensionProperties;

    VkExtensionProperties* value{ nullptr };

    StringDecoder extensionName;
};

struct Decoded_VkLayerProperties
{
    using struct_type = VkLayerProperties;

    VkLayerProperties* value{ nullptr };

    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_VkSubmitInfo
{
    using struct_type = VkSubmitInfo;

    VkSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pWaitSemaphores;
    PointerDecoder<VkPipelineStageFlags> pWaitDstStageMask;
    PointerDecoder<HandleId> pCommandBuffers;
    PointerDecoder<HandleId> pSignalSemaphores;
};

struct Decoded_VkMemoryAllocateInfo
{
    using struct_type = VkMemoryAllocateInfo;

    VkMemoryAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMappedMemoryRange
{
    using struct_type = VkMappedMemoryRange;

    VkMappedMemoryRange* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId memory;
};

struct Decoded_VkMemoryRequirements
{
    using struct_type = VkMemoryRequirements;

    VkMemoryRequirements* value{ nullptr };
};

struct Decoded_VkSparseImageFormatProperties
{
    using struct_type = VkSparseImageFormatProperties;

    VkSparseImageFormatProperties* value{ nullptr };

    Decoded_VkExtent3D imageGranularity;
};

struct Decoded_VkSparseImageMemoryRequirements
{
    using struct_type = VkSparseImageMemoryRequirements;

    VkSparseImageMemoryRequirements* value{ nullptr };

    Decoded_VkSparseImageFormatProperties formatProperties;
};

struct Decoded_VkSparseMemoryBind
{
    using struct_type = VkSparseMemoryBind;

    VkSparseMemoryBind* value{ nullptr };

    HandleId memory;
};

struct Decoded_VkSparseBufferMemoryBindInfo
{
    using struct_type = VkSparseBufferMemoryBindInfo;

    VkSparseBufferMemoryBindInfo* value{ nullptr };

    HandleId buffer;
    StructPointerDecoder<Decoded_VkSparseMemoryBind> pBinds;
};

struct Decoded_VkSparseImageOpaqueMemoryBindInfo
{
    using struct_type = VkSparseImageOpaqueMemoryBindInfo;

    VkSparseImageOpaqueMemoryBindInfo* value{ nullptr };

    HandleId image;
    StructPointerDecoder<Decoded_VkSparseMemoryBind> pBinds;
};

struct Decoded_VkImageSubresource
{
    using struct_type = VkImageSubresource;

    VkImageSubresource* value{ nullptr };
};

struct Decoded_VkOffset3D
{
    using struct_type = VkOffset3D;

    VkOffset3D* value{ nullptr };
};

struct Decoded_VkSparseImageMemoryBind
{
    using struct_type = VkSparseImageMemoryBind;

    VkSparseImageMemoryBind* value{ nullptr };

    Decoded_VkImageSubresource subresource;
    Decoded_VkOffset3D offset;
    Decoded_VkExtent3D extent;
    HandleId memory;
};

struct Decoded_VkSparseImageMemoryBindInfo
{
    using struct_type = VkSparseImageMemoryBindInfo;

    VkSparseImageMemoryBindInfo* value{ nullptr };

    HandleId image;
    StructPointerDecoder<Decoded_VkSparseImageMemoryBind> pBinds;
};

struct Decoded_VkBindSparseInfo
{
    using struct_type = VkBindSparseInfo;

    VkBindSparseInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pWaitSemaphores;
    StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo> pBufferBinds;
    StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo> pImageOpaqueBinds;
    StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo> pImageBinds;
    PointerDecoder<HandleId> pSignalSemaphores;
};

struct Decoded_VkFenceCreateInfo
{
    using struct_type = VkFenceCreateInfo;

    VkFenceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSemaphoreCreateInfo
{
    using struct_type = VkSemaphoreCreateInfo;

    VkSemaphoreCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkEventCreateInfo
{
    using struct_type = VkEventCreateInfo;

    VkEventCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueryPoolCreateInfo
{
    using struct_type = VkQueryPoolCreateInfo;

    VkQueryPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferCreateInfo
{
    using struct_type = VkBufferCreateInfo;

    VkBufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkBufferViewCreateInfo
{
    using struct_type = VkBufferViewCreateInfo;

    VkBufferViewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId buffer;
};

struct Decoded_VkImageCreateInfo
{
    using struct_type = VkImageCreateInfo;

    VkImageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent3D extent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkSubresourceLayout
{
    using struct_type = VkSubresourceLayout;

    VkSubresourceLayout* value{ nullptr };
};

struct Decoded_VkComponentMapping
{
    using struct_type = VkComponentMapping;

    VkComponentMapping* value{ nullptr };
};

struct Decoded_VkImageSubresourceRange
{
    using struct_type = VkImageSubresourceRange;

    VkImageSubresourceRange* value{ nullptr };
};

struct Decoded_VkImageViewCreateInfo
{
    using struct_type = VkImageViewCreateInfo;

    VkImageViewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
    Decoded_VkComponentMapping components;
    Decoded_VkImageSubresourceRange subresourceRange;
};

struct Decoded_VkShaderModuleCreateInfo
{
    using struct_type = VkShaderModuleCreateInfo;

    VkShaderModuleCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pCode;
};

struct Decoded_VkPipelineCacheCreateInfo
{
    using struct_type = VkPipelineCacheCreateInfo;

    VkPipelineCacheCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkSpecializationMapEntry
{
    using struct_type = VkSpecializationMapEntry;

    VkSpecializationMapEntry* value{ nullptr };
};

struct Decoded_VkSpecializationInfo
{
    using struct_type = VkSpecializationInfo;

    VkSpecializationInfo* value{ nullptr };

    StructPointerDecoder<Decoded_VkSpecializationMapEntry> pMapEntries;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineShaderStageCreateInfo
{
    using struct_type = VkPipelineShaderStageCreateInfo;

    VkPipelineShaderStageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId module;
    StringDecoder pName;
    StructPointerDecoder<Decoded_VkSpecializationInfo> pSpecializationInfo;
};

struct Decoded_VkVertexInputBindingDescription
{
    using struct_type = VkVertexInputBindingDescription;

    VkVertexInputBindingDescription* value{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription
{
    using struct_type = VkVertexInputAttributeDescription;

    VkVertexInputAttributeDescription* value{ nullptr };
};

struct Decoded_VkPipelineVertexInputStateCreateInfo
{
    using struct_type = VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription> pVertexBindingDescriptions;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription> pVertexAttributeDescriptions;
};

struct Decoded_VkPipelineInputAssemblyStateCreateInfo
{
    using struct_type = VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationStateCreateInfo
{
    using struct_type = VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewport
{
    using struct_type = VkViewport;

    VkViewport* value{ nullptr };
};

struct Decoded_VkOffset2D
{
    using struct_type = VkOffset2D;

    VkOffset2D* value{ nullptr };
};

struct Decoded_VkExtent2D
{
    using struct_type = VkExtent2D;

    VkExtent2D* value{ nullptr };
};

struct Decoded_VkRect2D
{
    using struct_type = VkRect2D;

    VkRect2D* value{ nullptr };

    Decoded_VkOffset2D offset;
    Decoded_VkExtent2D extent;
};

struct Decoded_VkPipelineViewportStateCreateInfo
{
    using struct_type = VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewport> pViewports;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;
};

struct Decoded_VkPipelineRasterizationStateCreateInfo
{
    using struct_type = VkPipelineRasterizationStateCreateInfo;

    VkPipelineRasterizationStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineMultisampleStateCreateInfo
{
    using struct_type = VkPipelineMultisampleStateCreateInfo;

    VkPipelineMultisampleStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkSampleMask> pSampleMask;
};

struct Decoded_VkStencilOpState
{
    using struct_type = VkStencilOpState;

    VkStencilOpState* value{ nullptr };
};

struct Decoded_VkPipelineDepthStencilStateCreateInfo
{
    using struct_type = VkPipelineDepthStencilStateCreateInfo;

    VkPipelineDepthStencilStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkStencilOpState front;
    Decoded_VkStencilOpState back;
};

struct Decoded_VkPipelineColorBlendAttachmentState
{
    using struct_type = VkPipelineColorBlendAttachmentState;

    VkPipelineColorBlendAttachmentState* value{ nullptr };
};

struct Decoded_VkPipelineColorBlendStateCreateInfo
{
    using struct_type = VkPipelineColorBlendStateCreateInfo;

    VkPipelineColorBlendStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState> pAttachments;
    PointerDecoder<float> blendConstants;
};

struct Decoded_VkPipelineDynamicStateCreateInfo
{
    using struct_type = VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDynamicState> pDynamicStates;
};

struct Decoded_VkGraphicsPipelineCreateInfo
{
    using struct_type = VkGraphicsPipelineCreateInfo;

    VkGraphicsPipelineCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo> pStages;
    StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo> pVertexInputState;
    StructPointerDecoder<Decoded_VkPipelineInputAssemblyStateCreateInfo> pInputAssemblyState;
    StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo> pTessellationState;
    StructPointerDecoder<Decoded_VkPipelineViewportStateCreateInfo> pViewportState;
    StructPointerDecoder<Decoded_VkPipelineRasterizationStateCreateInfo> pRasterizationState;
    StructPointerDecoder<Decoded_VkPipelineMultisampleStateCreateInfo> pMultisampleState;
    StructPointerDecoder<Decoded_VkPipelineDepthStencilStateCreateInfo> pDepthStencilState;
    StructPointerDecoder<Decoded_VkPipelineColorBlendStateCreateInfo> pColorBlendState;
    StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo> pDynamicState;
    HandleId layout;
    HandleId renderPass;
    HandleId basePipelineHandle;
};

struct Decoded_VkComputePipelineCreateInfo
{
    using struct_type = VkComputePipelineCreateInfo;

    VkComputePipelineCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPipelineShaderStageCreateInfo stage;
    HandleId layout;
    HandleId basePipelineHandle;
};

struct Decoded_VkPushConstantRange
{
    using struct_type = VkPushConstantRange;

    VkPushConstantRange* value{ nullptr };
};

struct Decoded_VkPipelineLayoutCreateInfo
{
    using struct_type = VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange> pPushConstantRanges;
};

struct Decoded_VkSamplerCreateInfo
{
    using struct_type = VkSamplerCreateInfo;

    VkSamplerCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutBinding
{
    using struct_type = VkDescriptorSetLayoutBinding;

    VkDescriptorSetLayoutBinding* value{ nullptr };

    PointerDecoder<HandleId> pImmutableSamplers;
};

struct Decoded_VkDescriptorSetLayoutCreateInfo
{
    using struct_type = VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding> pBindings;
};

struct Decoded_VkDescriptorPoolSize
{
    using struct_type = VkDescriptorPoolSize;

    VkDescriptorPoolSize* value{ nullptr };
};

struct Decoded_VkDescriptorPoolCreateInfo
{
    using struct_type = VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorPoolSize> pPoolSizes;
};

struct Decoded_VkDescriptorSetAllocateInfo
{
    using struct_type = VkDescriptorSetAllocateInfo;

    VkDescriptorSetAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId descriptorPool;
    PointerDecoder<HandleId> pSetLayouts;
};

struct Decoded_VkDescriptorImageInfo
{
    using struct_type = VkDescriptorImageInfo;

    VkDescriptorImageInfo* value{ nullptr };

    HandleId sampler;
    HandleId imageView;
};

struct Decoded_VkDescriptorBufferInfo
{
    using struct_type = VkDescriptorBufferInfo;

    VkDescriptorBufferInfo* value{ nullptr };

    HandleId buffer;
};

struct Decoded_VkWriteDescriptorSet
{
    using struct_type = VkWriteDescriptorSet;

    VkWriteDescriptorSet* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId dstSet;
    StructPointerDecoder<Decoded_VkDescriptorImageInfo> pImageInfo;
    StructPointerDecoder<Decoded_VkDescriptorBufferInfo> pBufferInfo;
    PointerDecoder<HandleId> pTexelBufferView;
};

struct Decoded_VkCopyDescriptorSet
{
    using struct_type = VkCopyDescriptorSet;

    VkCopyDescriptorSet* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId srcSet;
    HandleId dstSet;
};

struct Decoded_VkFramebufferCreateInfo
{
    using struct_type = VkFramebufferCreateInfo;

    VkFramebufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId renderPass;
    PointerDecoder<HandleId> pAttachments;
};

struct Decoded_VkAttachmentDescription
{
    using struct_type = VkAttachmentDescription;

    VkAttachmentDescription* value{ nullptr };
};

struct Decoded_VkAttachmentReference
{
    using struct_type = VkAttachmentReference;

    VkAttachmentReference* value{ nullptr };
};

struct Decoded_VkSubpassDescription
{
    using struct_type = VkSubpassDescription;

    VkSubpassDescription* value{ nullptr };

    StructPointerDecoder<Decoded_VkAttachmentReference> pInputAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pColorAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pResolveAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency
{
    using struct_type = VkSubpassDependency;

    VkSubpassDependency* value{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo
{
    using struct_type = VkRenderPassCreateInfo;

    VkRenderPassCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentDescription> pAttachments;
    StructPointerDecoder<Decoded_VkSubpassDescription> pSubpasses;
    StructPointerDecoder<Decoded_VkSubpassDependency> pDependencies;
};

struct Decoded_VkCommandPoolCreateInfo
{
    using struct_type = VkCommandPoolCreateInfo;

    VkCommandPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferAllocateInfo
{
    using struct_type = VkCommandBufferAllocateInfo;

    VkCommandBufferAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId commandPool;
};

struct Decoded_VkCommandBufferInheritanceInfo
{
    using struct_type = VkCommandBufferInheritanceInfo;

    VkCommandBufferInheritanceInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId renderPass;
    HandleId framebuffer;
};

struct Decoded_VkCommandBufferBeginInfo
{
    using struct_type = VkCommandBufferBeginInfo;

    VkCommandBufferBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo> pInheritanceInfo;
};

struct Decoded_VkBufferCopy
{
    using struct_type = VkBufferCopy;

    VkBufferCopy* value{ nullptr };
};

struct Decoded_VkImageSubresourceLayers
{
    using struct_type = VkImageSubresourceLayers;

    VkImageSubresourceLayers* value{ nullptr };
};

struct Decoded_VkImageCopy
{
    using struct_type = VkImageCopy;

    VkImageCopy* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    Decoded_VkOffset3D srcOffset;
    Decoded_VkImageSubresourceLayers dstSubresource;
    Decoded_VkOffset3D dstOffset;
    Decoded_VkExtent3D extent;
};

struct Decoded_VkImageBlit
{
    using struct_type = VkImageBlit;

    VkImageBlit* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    StructPointerDecoder<Decoded_VkOffset3D> srcOffsets;
    Decoded_VkImageSubresourceLayers dstSubresource;
    StructPointerDecoder<Decoded_VkOffset3D> dstOffsets;
};

struct Decoded_VkBufferImageCopy
{
    using struct_type = VkBufferImageCopy;

    VkBufferImageCopy* value{ nullptr };

    Decoded_VkImageSubresourceLayers imageSubresource;
    Decoded_VkOffset3D imageOffset;
    Decoded_VkExtent3D imageExtent;
};

struct Decoded_VkClearColorValue
{
    using struct_type = VkClearColorValue;

    VkClearColorValue* value{ nullptr };

    PointerDecoder<float> float32;
    PointerDecoder<int32_t> int32;
    PointerDecoder<uint32_t> uint32;
};

struct Decoded_VkClearDepthStencilValue
{
    using struct_type = VkClearDepthStencilValue;

    VkClearDepthStencilValue* value{ nullptr };
};

struct Decoded_VkClearValue
{
    using struct_type = VkClearValue;

    VkClearValue* value{ nullptr };

    Decoded_VkClearColorValue color;
    Decoded_VkClearDepthStencilValue depthStencil;
};

struct Decoded_VkClearAttachment
{
    using struct_type = VkClearAttachment;

    VkClearAttachment* value{ nullptr };

    Decoded_VkClearValue clearValue;
};

struct Decoded_VkClearRect
{
    using struct_type = VkClearRect;

    VkClearRect* value{ nullptr };

    Decoded_VkRect2D rect;
};

struct Decoded_VkImageResolve
{
    using struct_type = VkImageResolve;

    VkImageResolve* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    Decoded_VkOffset3D srcOffset;
    Decoded_VkImageSubresourceLayers dstSubresource;
    Decoded_VkOffset3D dstOffset;
    Decoded_VkExtent3D extent;
};

struct Decoded_VkMemoryBarrier
{
    using struct_type = VkMemoryBarrier;

    VkMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferMemoryBarrier
{
    using struct_type = VkBufferMemoryBarrier;

    VkBufferMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId buffer;
};

struct Decoded_VkImageMemoryBarrier
{
    using struct_type = VkImageMemoryBarrier;

    VkImageMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
    Decoded_VkImageSubresourceRange subresourceRange;
};

struct Decoded_VkRenderPassBeginInfo
{
    using struct_type = VkRenderPassBeginInfo;

    VkRenderPassBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId renderPass;
    HandleId framebuffer;
    Decoded_VkRect2D renderArea;
    StructPointerDecoder<Decoded_VkClearValue> pClearValues;
};

struct Decoded_VkDispatchIndirectCommand
{
    using struct_type = VkDispatchIndirectCommand;

    VkDispatchIndirectCommand* value{ nullptr };
};

struct Decoded_VkDrawIndexedIndirectCommand
{
    using struct_type = VkDrawIndexedIndirectCommand;

    VkDrawIndexedIndirectCommand* value{ nullptr };
};

struct Decoded_VkDrawIndirectCommand
{
    using struct_type = VkDrawIndirectCommand;

    VkDrawIndirectCommand* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupProperties
{
    using struct_type = VkPhysicalDeviceSubgroupProperties;

    VkPhysicalDeviceSubgroupProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryInfo
{
    using struct_type = VkBindBufferMemoryInfo;

    VkBindBufferMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId buffer;
    HandleId memory;
};

struct Decoded_VkBindImageMemoryInfo
{
    using struct_type = VkBindImageMemoryInfo;

    VkBindImageMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
    HandleId memory;
};

struct Decoded_VkPhysicalDevice16BitStorageFeatures
{
    using struct_type = VkPhysicalDevice16BitStorageFeatures;

    VkPhysicalDevice16BitStorageFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedRequirements
{
    using struct_type = VkMemoryDedicatedRequirements;

    VkMemoryDedicatedRequirements* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedAllocateInfo
{
    using struct_type = VkMemoryDedicatedAllocateInfo;

    VkMemoryDedicatedAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
    HandleId buffer;
};

struct Decoded_VkMemoryAllocateFlagsInfo
{
    using struct_type = VkMemoryAllocateFlagsInfo;

    VkMemoryAllocateFlagsInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupRenderPassBeginInfo
{
    using struct_type = VkDeviceGroupRenderPassBeginInfo;

    VkDeviceGroupRenderPassBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkRect2D> pDeviceRenderAreas;
};

struct Decoded_VkDeviceGroupCommandBufferBeginInfo
{
    using struct_type = VkDeviceGroupCommandBufferBeginInfo;

    VkDeviceGroupCommandBufferBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupSubmitInfo
{
    using struct_type = VkDeviceGroupSubmitInfo;

    VkDeviceGroupSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pWaitSemaphoreDeviceIndices;
    PointerDecoder<uint32_t> pCommandBufferDeviceMasks;
    PointerDecoder<uint32_t> pSignalSemaphoreDeviceIndices;
};

struct Decoded_VkDeviceGroupBindSparseInfo
{
    using struct_type = VkDeviceGroupBindSparseInfo;

    VkDeviceGroupBindSparseInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryDeviceGroupInfo
{
    using struct_type = VkBindBufferMemoryDeviceGroupInfo;

    VkBindBufferMemoryDeviceGroupInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkBindImageMemoryDeviceGroupInfo
{
    using struct_type = VkBindImageMemoryDeviceGroupInfo;

    VkBindImageMemoryDeviceGroupInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
    StructPointerDecoder<Decoded_VkRect2D> pSplitInstanceBindRegions;
};

struct Decoded_VkPhysicalDeviceGroupProperties
{
    using struct_type = VkPhysicalDeviceGroupProperties;

    VkPhysicalDeviceGroupProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkPhysicalDevice> physicalDevices;
};

struct Decoded_VkDeviceGroupDeviceCreateInfo
{
    using struct_type = VkDeviceGroupDeviceCreateInfo;

    VkDeviceGroupDeviceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pPhysicalDevices;
};

struct Decoded_VkBufferMemoryRequirementsInfo2
{
    using struct_type = VkBufferMemoryRequirementsInfo2;

    VkBufferMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId buffer;
};

struct Decoded_VkImageMemoryRequirementsInfo2
{
    using struct_type = VkImageMemoryRequirementsInfo2;

    VkImageMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
};

struct Decoded_VkImageSparseMemoryRequirementsInfo2
{
    using struct_type = VkImageSparseMemoryRequirementsInfo2;

    VkImageSparseMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
};

struct Decoded_VkMemoryRequirements2
{
    using struct_type = VkMemoryRequirements2;

    VkMemoryRequirements2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkMemoryRequirements memoryRequirements;
};

struct Decoded_VkSparseImageMemoryRequirements2
{
    using struct_type = VkSparseImageMemoryRequirements2;

    VkSparseImageMemoryRequirements2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSparseImageMemoryRequirements memoryRequirements;
};

struct Decoded_VkPhysicalDeviceFeatures2
{
    using struct_type = VkPhysicalDeviceFeatures2;

    VkPhysicalDeviceFeatures2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceFeatures features;
};

struct Decoded_VkPhysicalDeviceProperties2
{
    using struct_type = VkPhysicalDeviceProperties2;

    VkPhysicalDeviceProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceProperties properties;
};

struct Decoded_VkFormatProperties2
{
    using struct_type = VkFormatProperties2;

    VkFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkFormatProperties formatProperties;
};

struct Decoded_VkImageFormatProperties2
{
    using struct_type = VkImageFormatProperties2;

    VkImageFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkImageFormatProperties imageFormatProperties;
};

struct Decoded_VkPhysicalDeviceImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceImageFormatInfo2;

    VkPhysicalDeviceImageFormatInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueueFamilyProperties2
{
    using struct_type = VkQueueFamilyProperties2;

    VkQueueFamilyProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkQueueFamilyProperties queueFamilyProperties;
};

struct Decoded_VkPhysicalDeviceMemoryProperties2
{
    using struct_type = VkPhysicalDeviceMemoryProperties2;

    VkPhysicalDeviceMemoryProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceMemoryProperties memoryProperties;
};

struct Decoded_VkSparseImageFormatProperties2
{
    using struct_type = VkSparseImageFormatProperties2;

    VkSparseImageFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSparseImageFormatProperties properties;
};

struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceSparseImageFormatInfo2;

    VkPhysicalDeviceSparseImageFormatInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePointClippingProperties
{
    using struct_type = VkPhysicalDevicePointClippingProperties;

    VkPhysicalDevicePointClippingProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkInputAttachmentAspectReference
{
    using struct_type = VkInputAttachmentAspectReference;

    VkInputAttachmentAspectReference* value{ nullptr };
};

struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo
{
    using struct_type = VkRenderPassInputAttachmentAspectCreateInfo;

    VkRenderPassInputAttachmentAspectCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkInputAttachmentAspectReference> pAspectReferences;
};

struct Decoded_VkImageViewUsageCreateInfo
{
    using struct_type = VkImageViewUsageCreateInfo;

    VkImageViewUsageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo
{
    using struct_type = VkPipelineTessellationDomainOriginStateCreateInfo;

    VkPipelineTessellationDomainOriginStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassMultiviewCreateInfo
{
    using struct_type = VkRenderPassMultiviewCreateInfo;

    VkRenderPassMultiviewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pViewMasks;
    PointerDecoder<int32_t> pViewOffsets;
    PointerDecoder<uint32_t> pCorrelationMasks;
};

struct Decoded_VkPhysicalDeviceMultiviewFeatures
{
    using struct_type = VkPhysicalDeviceMultiviewFeatures;

    VkPhysicalDeviceMultiviewFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMultiviewProperties
{
    using struct_type = VkPhysicalDeviceMultiviewProperties;

    VkPhysicalDeviceMultiviewProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVariablePointerFeatures
{
    using struct_type = VkPhysicalDeviceVariablePointerFeatures;

    VkPhysicalDeviceVariablePointerFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures
{
    using struct_type = VkPhysicalDeviceProtectedMemoryFeatures;

    VkPhysicalDeviceProtectedMemoryFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryProperties
{
    using struct_type = VkPhysicalDeviceProtectedMemoryProperties;

    VkPhysicalDeviceProtectedMemoryProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueInfo2
{
    using struct_type = VkDeviceQueueInfo2;

    VkDeviceQueueInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkProtectedSubmitInfo
{
    using struct_type = VkProtectedSubmitInfo;

    VkProtectedSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionCreateInfo
{
    using struct_type = VkSamplerYcbcrConversionCreateInfo;

    VkSamplerYcbcrConversionCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkComponentMapping components;
};

struct Decoded_VkSamplerYcbcrConversionInfo
{
    using struct_type = VkSamplerYcbcrConversionInfo;

    VkSamplerYcbcrConversionInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId conversion;
};

struct Decoded_VkBindImagePlaneMemoryInfo
{
    using struct_type = VkBindImagePlaneMemoryInfo;

    VkBindImagePlaneMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImagePlaneMemoryRequirementsInfo
{
    using struct_type = VkImagePlaneMemoryRequirementsInfo;

    VkImagePlaneMemoryRequirementsInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
    using struct_type = VkPhysicalDeviceSamplerYcbcrConversionFeatures;

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionImageFormatProperties
{
    using struct_type = VkSamplerYcbcrConversionImageFormatProperties;

    VkSamplerYcbcrConversionImageFormatProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorUpdateTemplateEntry
{
    using struct_type = VkDescriptorUpdateTemplateEntry;

    VkDescriptorUpdateTemplateEntry* value{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateCreateInfo
{
    using struct_type = VkDescriptorUpdateTemplateCreateInfo;

    VkDescriptorUpdateTemplateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry> pDescriptorUpdateEntries;
    HandleId descriptorSetLayout;
    HandleId pipelineLayout;
};

struct Decoded_VkExternalMemoryProperties
{
    using struct_type = VkExternalMemoryProperties;

    VkExternalMemoryProperties* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalImageFormatInfo
{
    using struct_type = VkPhysicalDeviceExternalImageFormatInfo;

    VkPhysicalDeviceExternalImageFormatInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalImageFormatProperties
{
    using struct_type = VkExternalImageFormatProperties;

    VkExternalImageFormatProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExternalMemoryProperties externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceExternalBufferInfo
{
    using struct_type = VkPhysicalDeviceExternalBufferInfo;

    VkPhysicalDeviceExternalBufferInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalBufferProperties
{
    using struct_type = VkExternalBufferProperties;

    VkExternalBufferProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExternalMemoryProperties externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceIDProperties
{
    using struct_type = VkPhysicalDeviceIDProperties;

    VkPhysicalDeviceIDProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkExternalMemoryImageCreateInfo
{
    using struct_type = VkExternalMemoryImageCreateInfo;

    VkExternalMemoryImageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalMemoryBufferCreateInfo
{
    using struct_type = VkExternalMemoryBufferCreateInfo;

    VkExternalMemoryBufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfo
{
    using struct_type = VkExportMemoryAllocateInfo;

    VkExportMemoryAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalFenceInfo
{
    using struct_type = VkPhysicalDeviceExternalFenceInfo;

    VkPhysicalDeviceExternalFenceInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalFenceProperties
{
    using struct_type = VkExternalFenceProperties;

    VkExternalFenceProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportFenceCreateInfo
{
    using struct_type = VkExportFenceCreateInfo;

    VkExportFenceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportSemaphoreCreateInfo
{
    using struct_type = VkExportSemaphoreCreateInfo;

    VkExportSemaphoreCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo
{
    using struct_type = VkPhysicalDeviceExternalSemaphoreInfo;

    VkPhysicalDeviceExternalSemaphoreInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalSemaphoreProperties
{
    using struct_type = VkExternalSemaphoreProperties;

    VkExternalSemaphoreProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMaintenance3Properties
{
    using struct_type = VkPhysicalDeviceMaintenance3Properties;

    VkPhysicalDeviceMaintenance3Properties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutSupport
{
    using struct_type = VkDescriptorSetLayoutSupport;

    VkDescriptorSetLayoutSupport* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderDrawParameterFeatures
{
    using struct_type = VkPhysicalDeviceShaderDrawParameterFeatures;

    VkPhysicalDeviceShaderDrawParameterFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSurfaceCapabilitiesKHR
{
    using struct_type = VkSurfaceCapabilitiesKHR;

    VkSurfaceCapabilitiesKHR* value{ nullptr };

    Decoded_VkExtent2D currentExtent;
    Decoded_VkExtent2D minImageExtent;
    Decoded_VkExtent2D maxImageExtent;
};

struct Decoded_VkSurfaceFormatKHR
{
    using struct_type = VkSurfaceFormatKHR;

    VkSurfaceFormatKHR* value{ nullptr };
};

struct Decoded_VkSwapchainCreateInfoKHR
{
    using struct_type = VkSwapchainCreateInfoKHR;

    VkSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId surface;
    Decoded_VkExtent2D imageExtent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
    HandleId oldSwapchain;
};

struct Decoded_VkPresentInfoKHR
{
    using struct_type = VkPresentInfoKHR;

    VkPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pWaitSemaphores;
    PointerDecoder<HandleId> pSwapchains;
    PointerDecoder<uint32_t> pImageIndices;
    PointerDecoder<VkResult> pResults;
};

struct Decoded_VkImageSwapchainCreateInfoKHR
{
    using struct_type = VkImageSwapchainCreateInfoKHR;

    VkImageSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId swapchain;
};

struct Decoded_VkBindImageMemorySwapchainInfoKHR
{
    using struct_type = VkBindImageMemorySwapchainInfoKHR;

    VkBindImageMemorySwapchainInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId swapchain;
};

struct Decoded_VkAcquireNextImageInfoKHR
{
    using struct_type = VkAcquireNextImageInfoKHR;

    VkAcquireNextImageInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId swapchain;
    HandleId semaphore;
    HandleId fence;
};

struct Decoded_VkDeviceGroupPresentCapabilitiesKHR
{
    using struct_type = VkDeviceGroupPresentCapabilitiesKHR;

    VkDeviceGroupPresentCapabilitiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> presentMask;
};

struct Decoded_VkDeviceGroupPresentInfoKHR
{
    using struct_type = VkDeviceGroupPresentInfoKHR;

    VkDeviceGroupPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceMasks;
};

struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR
{
    using struct_type = VkDeviceGroupSwapchainCreateInfoKHR;

    VkDeviceGroupSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayPropertiesKHR
{
    using struct_type = VkDisplayPropertiesKHR;

    VkDisplayPropertiesKHR* value{ nullptr };

    HandleId display;
    StringDecoder displayName;
    Decoded_VkExtent2D physicalDimensions;
    Decoded_VkExtent2D physicalResolution;
};

struct Decoded_VkDisplayModeParametersKHR
{
    using struct_type = VkDisplayModeParametersKHR;

    VkDisplayModeParametersKHR* value{ nullptr };

    Decoded_VkExtent2D visibleRegion;
};

struct Decoded_VkDisplayModePropertiesKHR
{
    using struct_type = VkDisplayModePropertiesKHR;

    VkDisplayModePropertiesKHR* value{ nullptr };

    HandleId displayMode;
    Decoded_VkDisplayModeParametersKHR parameters;
};

struct Decoded_VkDisplayModeCreateInfoKHR
{
    using struct_type = VkDisplayModeCreateInfoKHR;

    VkDisplayModeCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayModeParametersKHR parameters;
};

struct Decoded_VkDisplayPlaneCapabilitiesKHR
{
    using struct_type = VkDisplayPlaneCapabilitiesKHR;

    VkDisplayPlaneCapabilitiesKHR* value{ nullptr };

    Decoded_VkOffset2D minSrcPosition;
    Decoded_VkOffset2D maxSrcPosition;
    Decoded_VkExtent2D minSrcExtent;
    Decoded_VkExtent2D maxSrcExtent;
    Decoded_VkOffset2D minDstPosition;
    Decoded_VkOffset2D maxDstPosition;
    Decoded_VkExtent2D minDstExtent;
    Decoded_VkExtent2D maxDstExtent;
};

struct Decoded_VkDisplayPlanePropertiesKHR
{
    using struct_type = VkDisplayPlanePropertiesKHR;

    VkDisplayPlanePropertiesKHR* value{ nullptr };

    HandleId currentDisplay;
};

struct Decoded_VkDisplaySurfaceCreateInfoKHR
{
    using struct_type = VkDisplaySurfaceCreateInfoKHR;

    VkDisplaySurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId displayMode;
    Decoded_VkExtent2D imageExtent;
};

struct Decoded_VkDisplayPresentInfoKHR
{
    using struct_type = VkDisplayPresentInfoKHR;

    VkDisplayPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkRect2D srcRect;
    Decoded_VkRect2D dstRect;
};

#ifdef VK_USE_PLATFORM_XLIB_KHR
struct Decoded_VkXlibSurfaceCreateInfoKHR
{
    using struct_type = VkXlibSurfaceCreateInfoKHR;

    VkXlibSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<Display> dpy;
};
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
struct Decoded_VkXcbSurfaceCreateInfoKHR
{
    using struct_type = VkXcbSurfaceCreateInfoKHR;

    VkXcbSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<xcb_connection_t> connection;
};
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
struct Decoded_VkWaylandSurfaceCreateInfoKHR
{
    using struct_type = VkWaylandSurfaceCreateInfoKHR;

    VkWaylandSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<wl_display> display;
    PointerDecoder<wl_surface> surface;
};
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
struct Decoded_VkMirSurfaceCreateInfoKHR
{
    using struct_type = VkMirSurfaceCreateInfoKHR;

    VkMirSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<MirConnection> connection;
    PointerDecoder<MirSurface> mirSurface;
};
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct Decoded_VkAndroidSurfaceCreateInfoKHR
{
    using struct_type = VkAndroidSurfaceCreateInfoKHR;

    VkAndroidSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<ANativeWindow> window;
};
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkWin32SurfaceCreateInfoKHR
{
    using struct_type = VkWin32SurfaceCreateInfoKHR;

    VkWin32SurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkImportMemoryWin32HandleInfoKHR
{
    using struct_type = VkImportMemoryWin32HandleInfoKHR;

    VkImportMemoryWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryWin32HandleInfoKHR
{
    using struct_type = VkExportMemoryWin32HandleInfoKHR;

    VkExportMemoryWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<SECURITY_ATTRIBUTES> pAttributes;
};

struct Decoded_VkMemoryWin32HandlePropertiesKHR
{
    using struct_type = VkMemoryWin32HandlePropertiesKHR;

    VkMemoryWin32HandlePropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetWin32HandleInfoKHR
{
    using struct_type = VkMemoryGetWin32HandleInfoKHR;

    VkMemoryGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId memory;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

struct Decoded_VkImportMemoryFdInfoKHR
{
    using struct_type = VkImportMemoryFdInfoKHR;

    VkImportMemoryFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryFdPropertiesKHR
{
    using struct_type = VkMemoryFdPropertiesKHR;

    VkMemoryFdPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetFdInfoKHR
{
    using struct_type = VkMemoryGetFdInfoKHR;

    VkMemoryGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId memory;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoKHR;

    VkWin32KeyedMutexAcquireReleaseInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeouts;
    PointerDecoder<HandleId> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkImportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkImportSemaphoreWin32HandleInfoKHR;

    VkImportSemaphoreWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId semaphore;
};

struct Decoded_VkExportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkExportSemaphoreWin32HandleInfoKHR;

    VkExportSemaphoreWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<SECURITY_ATTRIBUTES> pAttributes;
};

struct Decoded_VkD3D12FenceSubmitInfoKHR
{
    using struct_type = VkD3D12FenceSubmitInfoKHR;

    VkD3D12FenceSubmitInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreGetWin32HandleInfoKHR
{
    using struct_type = VkSemaphoreGetWin32HandleInfoKHR;

    VkSemaphoreGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId semaphore;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

struct Decoded_VkImportSemaphoreFdInfoKHR
{
    using struct_type = VkImportSemaphoreFdInfoKHR;

    VkImportSemaphoreFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId semaphore;
};

struct Decoded_VkSemaphoreGetFdInfoKHR
{
    using struct_type = VkSemaphoreGetFdInfoKHR;

    VkSemaphoreGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId semaphore;
};

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR
{
    using struct_type = VkPhysicalDevicePushDescriptorPropertiesKHR;

    VkPhysicalDevicePushDescriptorPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRectLayerKHR
{
    using struct_type = VkRectLayerKHR;

    VkRectLayerKHR* value{ nullptr };

    Decoded_VkOffset2D offset;
    Decoded_VkExtent2D extent;
};

struct Decoded_VkPresentRegionKHR
{
    using struct_type = VkPresentRegionKHR;

    VkPresentRegionKHR* value{ nullptr };

    StructPointerDecoder<Decoded_VkRectLayerKHR> pRectangles;
};

struct Decoded_VkPresentRegionsKHR
{
    using struct_type = VkPresentRegionsKHR;

    VkPresentRegionsKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPresentRegionKHR> pRegions;
};

struct Decoded_VkAttachmentDescription2KHR
{
    using struct_type = VkAttachmentDescription2KHR;

    VkAttachmentDescription2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAttachmentReference2KHR
{
    using struct_type = VkAttachmentReference2KHR;

    VkAttachmentReference2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassDescription2KHR
{
    using struct_type = VkSubpassDescription2KHR;

    VkSubpassDescription2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pInputAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pColorAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pResolveAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency2KHR
{
    using struct_type = VkSubpassDependency2KHR;

    VkSubpassDependency2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassCreateInfo2KHR
{
    using struct_type = VkRenderPassCreateInfo2KHR;

    VkRenderPassCreateInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentDescription2KHR> pAttachments;
    StructPointerDecoder<Decoded_VkSubpassDescription2KHR> pSubpasses;
    StructPointerDecoder<Decoded_VkSubpassDependency2KHR> pDependencies;
    PointerDecoder<uint32_t> pCorrelatedViewMasks;
};

struct Decoded_VkSubpassBeginInfoKHR
{
    using struct_type = VkSubpassBeginInfoKHR;

    VkSubpassBeginInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassEndInfoKHR
{
    using struct_type = VkSubpassEndInfoKHR;

    VkSubpassEndInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR
{
    using struct_type = VkSharedPresentSurfaceCapabilitiesKHR;

    VkSharedPresentSurfaceCapabilitiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkImportFenceWin32HandleInfoKHR
{
    using struct_type = VkImportFenceWin32HandleInfoKHR;

    VkImportFenceWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId fence;
};

struct Decoded_VkExportFenceWin32HandleInfoKHR
{
    using struct_type = VkExportFenceWin32HandleInfoKHR;

    VkExportFenceWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<SECURITY_ATTRIBUTES> pAttributes;
};

struct Decoded_VkFenceGetWin32HandleInfoKHR
{
    using struct_type = VkFenceGetWin32HandleInfoKHR;

    VkFenceGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId fence;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

struct Decoded_VkImportFenceFdInfoKHR
{
    using struct_type = VkImportFenceFdInfoKHR;

    VkImportFenceFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId fence;
};

struct Decoded_VkFenceGetFdInfoKHR
{
    using struct_type = VkFenceGetFdInfoKHR;

    VkFenceGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId fence;
};

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR
{
    using struct_type = VkPhysicalDeviceSurfaceInfo2KHR;

    VkPhysicalDeviceSurfaceInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId surface;
};

struct Decoded_VkSurfaceCapabilities2KHR
{
    using struct_type = VkSurfaceCapabilities2KHR;

    VkSurfaceCapabilities2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSurfaceCapabilitiesKHR surfaceCapabilities;
};

struct Decoded_VkSurfaceFormat2KHR
{
    using struct_type = VkSurfaceFormat2KHR;

    VkSurfaceFormat2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSurfaceFormatKHR surfaceFormat;
};

struct Decoded_VkDisplayProperties2KHR
{
    using struct_type = VkDisplayProperties2KHR;

    VkDisplayProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPropertiesKHR displayProperties;
};

struct Decoded_VkDisplayPlaneProperties2KHR
{
    using struct_type = VkDisplayPlaneProperties2KHR;

    VkDisplayPlaneProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPlanePropertiesKHR displayPlaneProperties;
};

struct Decoded_VkDisplayModeProperties2KHR
{
    using struct_type = VkDisplayModeProperties2KHR;

    VkDisplayModeProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayModePropertiesKHR displayModeProperties;
};

struct Decoded_VkDisplayPlaneInfo2KHR
{
    using struct_type = VkDisplayPlaneInfo2KHR;

    VkDisplayPlaneInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId mode;
};

struct Decoded_VkDisplayPlaneCapabilities2KHR
{
    using struct_type = VkDisplayPlaneCapabilities2KHR;

    VkDisplayPlaneCapabilities2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPlaneCapabilitiesKHR capabilities;
};

struct Decoded_VkImageFormatListCreateInfoKHR
{
    using struct_type = VkImageFormatListCreateInfoKHR;

    VkImageFormatListCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkPhysicalDevice8BitStorageFeaturesKHR
{
    using struct_type = VkPhysicalDevice8BitStorageFeaturesKHR;

    VkPhysicalDevice8BitStorageFeaturesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDebugReportCallbackCreateInfoEXT
{
    using struct_type = VkDebugReportCallbackCreateInfoEXT;

    VkDebugReportCallbackCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnCallback;
    uint64_t pUserData;
};

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD
{
    using struct_type = VkPipelineRasterizationStateRasterizationOrderAMD;

    VkPipelineRasterizationStateRasterizationOrderAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDebugMarkerObjectNameInfoEXT
{
    using struct_type = VkDebugMarkerObjectNameInfoEXT;

    VkDebugMarkerObjectNameInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugMarkerObjectTagInfoEXT
{
    using struct_type = VkDebugMarkerObjectTagInfoEXT;

    VkDebugMarkerObjectTagInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugMarkerMarkerInfoEXT
{
    using struct_type = VkDebugMarkerMarkerInfoEXT;

    VkDebugMarkerMarkerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMarkerName;
    PointerDecoder<float> color;
};

struct Decoded_VkDedicatedAllocationImageCreateInfoNV
{
    using struct_type = VkDedicatedAllocationImageCreateInfoNV;

    VkDedicatedAllocationImageCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationBufferCreateInfoNV
{
    using struct_type = VkDedicatedAllocationBufferCreateInfoNV;

    VkDedicatedAllocationBufferCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV
{
    using struct_type = VkDedicatedAllocationMemoryAllocateInfoNV;

    VkDedicatedAllocationMemoryAllocateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId image;
    HandleId buffer;
};

struct Decoded_VkTextureLODGatherFormatPropertiesAMD
{
    using struct_type = VkTextureLODGatherFormatPropertiesAMD;

    VkTextureLODGatherFormatPropertiesAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkShaderResourceUsageAMD
{
    using struct_type = VkShaderResourceUsageAMD;

    VkShaderResourceUsageAMD* value{ nullptr };
};

struct Decoded_VkShaderStatisticsInfoAMD
{
    using struct_type = VkShaderStatisticsInfoAMD;

    VkShaderStatisticsInfoAMD* value{ nullptr };

    Decoded_VkShaderResourceUsageAMD resourceUsage;
    PointerDecoder<uint32_t> computeWorkGroupSize;
};

struct Decoded_VkExternalImageFormatPropertiesNV
{
    using struct_type = VkExternalImageFormatPropertiesNV;

    VkExternalImageFormatPropertiesNV* value{ nullptr };

    Decoded_VkImageFormatProperties imageFormatProperties;
};

struct Decoded_VkExternalMemoryImageCreateInfoNV
{
    using struct_type = VkExternalMemoryImageCreateInfoNV;

    VkExternalMemoryImageCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfoNV
{
    using struct_type = VkExportMemoryAllocateInfoNV;

    VkExportMemoryAllocateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkImportMemoryWin32HandleInfoNV
{
    using struct_type = VkImportMemoryWin32HandleInfoNV;

    VkImportMemoryWin32HandleInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryWin32HandleInfoNV
{
    using struct_type = VkExportMemoryWin32HandleInfoNV;

    VkExportMemoryWin32HandleInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<SECURITY_ATTRIBUTES> pAttributes;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoNV;

    VkWin32KeyedMutexAcquireReleaseInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<HandleId> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeoutMilliseconds;
    PointerDecoder<HandleId> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};
#endif /* VK_USE_PLATFORM_WIN32_KHR */

struct Decoded_VkValidationFlagsEXT
{
    using struct_type = VkValidationFlagsEXT;

    VkValidationFlagsEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkValidationCheckEXT> pDisabledValidationChecks;
};

#ifdef VK_USE_PLATFORM_VI_NN
struct Decoded_VkViSurfaceCreateInfoNN
{
    using struct_type = VkViSurfaceCreateInfoNN;

    VkViSurfaceCreateInfoNN* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t window;
};
#endif /* VK_USE_PLATFORM_VI_NN */

struct Decoded_VkConditionalRenderingBeginInfoEXT
{
    using struct_type = VkConditionalRenderingBeginInfoEXT;

    VkConditionalRenderingBeginInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId buffer;
};

struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceConditionalRenderingFeaturesEXT;

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT
{
    using struct_type = VkCommandBufferInheritanceConditionalRenderingInfoEXT;

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGeneratedCommandsFeaturesNVX
{
    using struct_type = VkDeviceGeneratedCommandsFeaturesNVX;

    VkDeviceGeneratedCommandsFeaturesNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGeneratedCommandsLimitsNVX
{
    using struct_type = VkDeviceGeneratedCommandsLimitsNVX;

    VkDeviceGeneratedCommandsLimitsNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkIndirectCommandsTokenNVX
{
    using struct_type = VkIndirectCommandsTokenNVX;

    VkIndirectCommandsTokenNVX* value{ nullptr };

    HandleId buffer;
};

struct Decoded_VkIndirectCommandsLayoutTokenNVX
{
    using struct_type = VkIndirectCommandsLayoutTokenNVX;

    VkIndirectCommandsLayoutTokenNVX* value{ nullptr };
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoNVX
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoNVX;

    VkIndirectCommandsLayoutCreateInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNVX> pTokens;
};

struct Decoded_VkCmdProcessCommandsInfoNVX
{
    using struct_type = VkCmdProcessCommandsInfoNVX;

    VkCmdProcessCommandsInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId objectTable;
    HandleId indirectCommandsLayout;
    StructPointerDecoder<Decoded_VkIndirectCommandsTokenNVX> pIndirectCommandsTokens;
    HandleId targetCommandBuffer;
    HandleId sequencesCountBuffer;
    HandleId sequencesIndexBuffer;
};

struct Decoded_VkCmdReserveSpaceForCommandsInfoNVX
{
    using struct_type = VkCmdReserveSpaceForCommandsInfoNVX;

    VkCmdReserveSpaceForCommandsInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId objectTable;
    HandleId indirectCommandsLayout;
};

struct Decoded_VkObjectTableCreateInfoNVX
{
    using struct_type = VkObjectTableCreateInfoNVX;

    VkObjectTableCreateInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkObjectEntryTypeNVX> pObjectEntryTypes;
    PointerDecoder<uint32_t> pObjectEntryCounts;
    PointerDecoder<VkObjectEntryUsageFlagsNVX> pObjectEntryUsageFlags;
};

struct Decoded_VkObjectTableEntryNVX
{
    using struct_type = VkObjectTableEntryNVX;

    VkObjectTableEntryNVX* value{ nullptr };
};

struct Decoded_VkObjectTablePipelineEntryNVX
{
    using struct_type = VkObjectTablePipelineEntryNVX;

    VkObjectTablePipelineEntryNVX* value{ nullptr };

    HandleId pipeline;
};

struct Decoded_VkObjectTableDescriptorSetEntryNVX
{
    using struct_type = VkObjectTableDescriptorSetEntryNVX;

    VkObjectTableDescriptorSetEntryNVX* value{ nullptr };

    HandleId pipelineLayout;
    HandleId descriptorSet;
};

struct Decoded_VkObjectTableVertexBufferEntryNVX
{
    using struct_type = VkObjectTableVertexBufferEntryNVX;

    VkObjectTableVertexBufferEntryNVX* value{ nullptr };

    HandleId buffer;
};

struct Decoded_VkObjectTableIndexBufferEntryNVX
{
    using struct_type = VkObjectTableIndexBufferEntryNVX;

    VkObjectTableIndexBufferEntryNVX* value{ nullptr };

    HandleId buffer;
};

struct Decoded_VkObjectTablePushConstantEntryNVX
{
    using struct_type = VkObjectTablePushConstantEntryNVX;

    VkObjectTablePushConstantEntryNVX* value{ nullptr };

    HandleId pipelineLayout;
};

struct Decoded_VkViewportWScalingNV
{
    using struct_type = VkViewportWScalingNV;

    VkViewportWScalingNV* value{ nullptr };
};

struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV
{
    using struct_type = VkPipelineViewportWScalingStateCreateInfoNV;

    VkPipelineViewportWScalingStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;
};

struct Decoded_VkSurfaceCapabilities2EXT
{
    using struct_type = VkSurfaceCapabilities2EXT;

    VkSurfaceCapabilities2EXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D currentExtent;
    Decoded_VkExtent2D minImageExtent;
    Decoded_VkExtent2D maxImageExtent;
};

struct Decoded_VkDisplayPowerInfoEXT
{
    using struct_type = VkDisplayPowerInfoEXT;

    VkDisplayPowerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceEventInfoEXT
{
    using struct_type = VkDeviceEventInfoEXT;

    VkDeviceEventInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayEventInfoEXT
{
    using struct_type = VkDisplayEventInfoEXT;

    VkDisplayEventInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSwapchainCounterCreateInfoEXT
{
    using struct_type = VkSwapchainCounterCreateInfoEXT;

    VkSwapchainCounterCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRefreshCycleDurationGOOGLE
{
    using struct_type = VkRefreshCycleDurationGOOGLE;

    VkRefreshCycleDurationGOOGLE* value{ nullptr };
};

struct Decoded_VkPastPresentationTimingGOOGLE
{
    using struct_type = VkPastPresentationTimingGOOGLE;

    VkPastPresentationTimingGOOGLE* value{ nullptr };
};

struct Decoded_VkPresentTimeGOOGLE
{
    using struct_type = VkPresentTimeGOOGLE;

    VkPresentTimeGOOGLE* value{ nullptr };
};

struct Decoded_VkPresentTimesInfoGOOGLE
{
    using struct_type = VkPresentTimesInfoGOOGLE;

    VkPresentTimesInfoGOOGLE* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPresentTimeGOOGLE> pTimes;
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewportSwizzleNV
{
    using struct_type = VkViewportSwizzleNV;

    VkViewportSwizzleNV* value{ nullptr };
};

struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV
{
    using struct_type = VkPipelineViewportSwizzleStateCreateInfoNV;

    VkPipelineViewportSwizzleStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;
};

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
    using struct_type = VkPhysicalDeviceDiscardRectanglePropertiesEXT;

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT
{
    using struct_type = VkPipelineDiscardRectangleStateCreateInfoEXT;

    VkPipelineDiscardRectangleStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;
};

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceConservativeRasterizationPropertiesEXT;

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationConservativeStateCreateInfoEXT;

    VkPipelineRasterizationConservativeStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkXYColorEXT
{
    using struct_type = VkXYColorEXT;

    VkXYColorEXT* value{ nullptr };
};

struct Decoded_VkHdrMetadataEXT
{
    using struct_type = VkHdrMetadataEXT;

    VkHdrMetadataEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkXYColorEXT displayPrimaryRed;
    Decoded_VkXYColorEXT displayPrimaryGreen;
    Decoded_VkXYColorEXT displayPrimaryBlue;
    Decoded_VkXYColorEXT whitePoint;
};

#ifdef VK_USE_PLATFORM_IOS_MVK
struct Decoded_VkIOSSurfaceCreateInfoMVK
{
    using struct_type = VkIOSSurfaceCreateInfoMVK;

    VkIOSSurfaceCreateInfoMVK* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView;
};
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
struct Decoded_VkMacOSSurfaceCreateInfoMVK
{
    using struct_type = VkMacOSSurfaceCreateInfoMVK;

    VkMacOSSurfaceCreateInfoMVK* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView;
};
#endif /* VK_USE_PLATFORM_MACOS_MVK */

struct Decoded_VkDebugUtilsObjectNameInfoEXT
{
    using struct_type = VkDebugUtilsObjectNameInfoEXT;

    VkDebugUtilsObjectNameInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugUtilsObjectTagInfoEXT
{
    using struct_type = VkDebugUtilsObjectTagInfoEXT;

    VkDebugUtilsObjectTagInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugUtilsLabelEXT
{
    using struct_type = VkDebugUtilsLabelEXT;

    VkDebugUtilsLabelEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pLabelName;
    PointerDecoder<float> color;
};

struct Decoded_VkDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = VkDebugUtilsMessengerCallbackDataEXT;

    VkDebugUtilsMessengerCallbackDataEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMessageIdName;
    StringDecoder pMessage;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pQueueLabels;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pCmdBufLabels;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pObjects;
};

struct Decoded_VkDebugUtilsMessengerCreateInfoEXT
{
    using struct_type = VkDebugUtilsMessengerCreateInfoEXT;

    VkDebugUtilsMessengerCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnUserCallback;
    uint64_t pUserData;
};

#ifdef VK_USE_PLATFORM_ANDROID_KHR
struct Decoded_VkAndroidHardwareBufferUsageANDROID
{
    using struct_type = VkAndroidHardwareBufferUsageANDROID;

    VkAndroidHardwareBufferUsageANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferPropertiesANDROID;

    VkAndroidHardwareBufferPropertiesANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatPropertiesANDROID;

    VkAndroidHardwareBufferFormatPropertiesANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkComponentMapping samplerYcbcrConversionComponents;
};

struct Decoded_VkImportAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkImportAndroidHardwareBufferInfoANDROID;

    VkImportAndroidHardwareBufferInfoANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<AHardwareBuffer> buffer;
};

struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkMemoryGetAndroidHardwareBufferInfoANDROID;

    VkMemoryGetAndroidHardwareBufferInfoANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId memory;
};

struct Decoded_VkExternalFormatANDROID
{
    using struct_type = VkExternalFormatANDROID;

    VkExternalFormatANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

struct Decoded_VkSamplerReductionModeCreateInfoEXT
{
    using struct_type = VkSamplerReductionModeCreateInfoEXT;

    VkSamplerReductionModeCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

    VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSampleLocationEXT
{
    using struct_type = VkSampleLocationEXT;

    VkSampleLocationEXT* value{ nullptr };
};

struct Decoded_VkSampleLocationsInfoEXT
{
    using struct_type = VkSampleLocationsInfoEXT;

    VkSampleLocationsInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D sampleLocationGridSize;
    StructPointerDecoder<Decoded_VkSampleLocationEXT> pSampleLocations;
};

struct Decoded_VkAttachmentSampleLocationsEXT
{
    using struct_type = VkAttachmentSampleLocationsEXT;

    VkAttachmentSampleLocationsEXT* value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkSubpassSampleLocationsEXT
{
    using struct_type = VkSubpassSampleLocationsEXT;

    VkSubpassSampleLocationsEXT* value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT
{
    using struct_type = VkRenderPassSampleLocationsBeginInfoEXT;

    VkRenderPassSampleLocationsBeginInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT> pAttachmentInitialSampleLocations;
    StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT> pPostSubpassSampleLocations;
};

struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT
{
    using struct_type = VkPipelineSampleLocationsStateCreateInfoEXT;

    VkPipelineSampleLocationsStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSampleLocationsPropertiesEXT;

    VkPhysicalDeviceSampleLocationsPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D maxSampleLocationGridSize;
    PointerDecoder<float> sampleLocationCoordinateRange;
};

struct Decoded_VkMultisamplePropertiesEXT
{
    using struct_type = VkMultisamplePropertiesEXT;

    VkMultisamplePropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D maxSampleLocationGridSize;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
    using struct_type = VkPipelineColorBlendAdvancedStateCreateInfoEXT;

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageToColorStateCreateInfoNV;

    VkPipelineCoverageToColorStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageModulationStateCreateInfoNV;

    VkPipelineCoverageModulationStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pCoverageModulationTable;
};

struct Decoded_VkValidationCacheCreateInfoEXT
{
    using struct_type = VkValidationCacheCreateInfoEXT;

    VkValidationCacheCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT
{
    using struct_type = VkShaderModuleValidationCacheCreateInfoEXT;

    VkShaderModuleValidationCacheCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandleId validationCache;
};

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT
{
    using struct_type = VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;

    VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDescriptorBindingFlagsEXT> pBindingFlags;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingFeaturesEXT;

    VkPhysicalDeviceDescriptorIndexingFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingPropertiesEXT;

    VkPhysicalDeviceDescriptorIndexingPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT
{
    using struct_type = VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;

    VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDescriptorCounts;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT
{
    using struct_type = VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

    VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT
{
    using struct_type = VkDeviceQueueGlobalPriorityCreateInfoEXT;

    VkDeviceQueueGlobalPriorityCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImportMemoryHostPointerInfoEXT
{
    using struct_type = VkImportMemoryHostPointerInfoEXT;

    VkImportMemoryHostPointerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pHostPointer;
};

struct Decoded_VkMemoryHostPointerPropertiesEXT
{
    using struct_type = VkMemoryHostPointerPropertiesEXT;

    VkMemoryHostPointerPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
    using struct_type = VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesAMD;

    VkPhysicalDeviceShaderCorePropertiesAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkVertexInputBindingDivisorDescriptionEXT
{
    using struct_type = VkVertexInputBindingDivisorDescriptionEXT;

    VkVertexInputBindingDivisorDescriptionEXT* value{ nullptr };
};

struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT
{
    using struct_type = VkPipelineVertexInputDivisorStateCreateInfoEXT;

    VkPipelineVertexInputDivisorStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescriptionEXT> pVertexBindingDivisors;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
