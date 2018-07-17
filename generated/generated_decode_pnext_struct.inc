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

#include <cassert>
#include <memory>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/pnext_node.h"
#include "format/pnext_typed_node.h"
#include "format/trace_pnext_util.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t decode_pnext_struct(const uint8_t* parameter_buffer, size_t buffer_size,  std::unique_ptr<PNextNode>* pNext)
{
    assert(pNext != nullptr);

    size_t bytes_read = 0;

    if ((parameter_buffer != nullptr) && (buffer_size >= sizeof(VkStructureType)))
    {
        const VkStructureType* sType = reinterpret_cast<const VkStructureType*>(parameter_buffer);

        switch (*sType)
        {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkApplicationInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkInstanceCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceQueueCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubmitInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryAllocateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMappedMemoryRange>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindSparseInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFenceCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSemaphoreCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkEventCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkQueryPoolCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferViewCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageViewCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkShaderModuleCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCacheCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineShaderStageCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineVertexInputStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineInputAssemblyStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineTessellationStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineMultisampleStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineDepthStencilStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineColorBlendStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineDynamicStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkGraphicsPipelineCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkComputePipelineCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineLayoutCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetLayoutCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorPoolCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetAllocateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWriteDescriptorSet>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCopyDescriptorSet>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFramebufferCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandPoolCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandBufferAllocateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandBufferInheritanceInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandBufferBeginInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryBarrier>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferMemoryBarrier>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageMemoryBarrier>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassBeginInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindBufferMemoryInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindImageMemoryInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevice16BitStorageFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryDedicatedRequirements>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryDedicatedAllocateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryAllocateFlagsInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupRenderPassBeginInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupCommandBufferBeginInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupSubmitInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupBindSparseInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindBufferMemoryDeviceGroupInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindImageMemoryDeviceGroupInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceGroupProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupDeviceCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferMemoryRequirementsInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageMemoryRequirementsInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageSparseMemoryRequirementsInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryRequirements2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSparseImageMemoryRequirements2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFeatures2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFormatProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageFormatProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceImageFormatInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkQueueFamilyProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMemoryProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSparseImageFormatProperties2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePointClippingProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassInputAttachmentAspectCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageViewUsageCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassMultiviewCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVariablePointerFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceProtectedMemoryFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceProtectedMemoryProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceQueueInfo2>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkProtectedSubmitInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerYcbcrConversionCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerYcbcrConversionInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindImagePlaneMemoryInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImagePlaneMemoryRequirementsInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerYcbcrConversionImageFormatProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorUpdateTemplateCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalImageFormatInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalImageFormatProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalBufferInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalBufferProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceIDProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalMemoryImageCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalMemoryBufferCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryAllocateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalFenceInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalFenceProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportFenceCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportSemaphoreCreateInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalSemaphoreProperties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMaintenance3Properties>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetLayoutSupport>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderDrawParameterFeatures>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSwapchainCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPresentInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageSwapchainCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBindImageMemorySwapchainInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAcquireNextImageInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupPresentCapabilitiesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupPresentInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupSwapchainCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayModeCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplaySurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPresentInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_XLIB_KHR
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkXlibSurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_XLIB_KHR */
#ifdef VK_USE_PLATFORM_XCB_KHR
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkXcbSurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_XCB_KHR */
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWaylandSurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */
#ifdef VK_USE_PLATFORM_MIR_KHR
        case VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMirSurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_MIR_KHR */
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAndroidSurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWin32SurfaceCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryWin32HandlePropertiesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryGetWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryFdPropertiesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryGetFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportSemaphoreWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportSemaphoreWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkD3D12FenceSubmitInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSemaphoreGetWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportSemaphoreFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSemaphoreGetFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPresentRegionsKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAttachmentDescription2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAttachmentReference2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubpassDescription2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubpassDependency2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassCreateInfo2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubpassBeginInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubpassEndInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSharedPresentSurfaceCapabilitiesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportFenceWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportFenceWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFenceGetWin32HandleInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportFenceFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFenceGetFdInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceCapabilities2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceFormat2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayProperties2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPlaneProperties2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayModeProperties2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPlaneInfo2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPlaneCapabilities2KHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageFormatListCreateInfoKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevice8BitStorageFeaturesKHR>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugReportCallbackCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugMarkerObjectNameInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugMarkerObjectTagInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugMarkerMarkerInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDedicatedAllocationImageCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDedicatedAllocationBufferCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkTextureLODGatherFormatPropertiesAMD>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalMemoryImageCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryAllocateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkValidationFlagsEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_VI_NN
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkViSurfaceCreateInfoNN>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_VI_NN */
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkConditionalRenderingBeginInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGeneratedCommandsLimitsNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCmdProcessCommandsInfoNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkObjectTableCreateInfoNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportWScalingStateCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceCapabilities2EXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPowerInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceEventInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayEventInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSwapchainCounterCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPresentTimesInfoGOOGLE>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkHdrMetadataEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_IOS_MVK
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkIOSSurfaceCreateInfoMVK>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_IOS_MVK */
#ifdef VK_USE_PLATFORM_MACOS_MVK
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMacOSSurfaceCreateInfoMVK>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_MACOS_MVK */
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsObjectNameInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsObjectTagInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsLabelEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsMessengerCallbackDataEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsMessengerCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAndroidHardwareBufferUsageANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAndroidHardwareBufferPropertiesANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportAndroidHardwareBufferInfoANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalFormatANDROID>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerReductionModeCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSampleLocationsInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassSampleLocationsBeginInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMultisamplePropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCoverageToColorStateCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCoverageModulationStateCreateInfoNV>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkValidationCacheCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkShaderModuleValidationCacheCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryHostPointerInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryHostPointerPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT>>();
            bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
            break;
        }
    }

    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)
