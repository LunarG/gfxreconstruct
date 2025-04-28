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

#include "graphics/vulkan_struct_deep_copy.h"
#include "format/platform_types.h"
#include "cstring"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

inline uint8_t* offset_ptr(uint8_t* ptr, uint64_t offset)
{
    return ptr != nullptr ? ptr + offset : nullptr;
}

size_t vulkan_struct_deep_copy_stype(const void* pNext, uint8_t* out_data)
{
    uint64_t offset = 0;
    auto     base    = reinterpret_cast<const VkBaseInStructure*>(pNext);
    uint8_t* out_ptr = offset_ptr(out_data, offset);
    switch (base->sType)
    {
        default:
            GFXRECON_LOG_WARNING("vulkan_struct_deep_copy_stype: unknown struct-type: %d", base->sType);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferMemoryBarrier*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageMemoryBarrier*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryBarrier*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkApplicationInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkInstanceCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceQueueCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMappedMemoryRange*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindSparseInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFenceCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkEventCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueryPoolCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferViewCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkShaderModuleCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCacheCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkComputePipelineCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineLayoutCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyDescriptorSet*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorPoolCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteDescriptorSet*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFramebufferCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandPoolCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferInheritanceInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindBufferMemoryInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindImageMemoryInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryDedicatedRequirements*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryRequirements2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSparseImageMemoryRequirements2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFeatures2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFormatProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageFormatProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSparseImageFormatProperties2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewUsageCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceQueueInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkProtectedSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalImageFormatProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalBufferProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceIDProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportMemoryAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalFenceProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportFenceCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportSemaphoreCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalSemaphoreProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetLayoutSupport*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageFormatListCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAttachmentDescription2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAttachmentReference2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassDescription2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassDependency2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassCreateInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassEndInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageStencilUsageCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFramebufferAttachmentImageInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreWaitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreSignalInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferDeviceAddressInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceMemoryOpaqueCaptureAddressInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceToolProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPrivateDataSlotCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryBarrier2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferMemoryBarrier2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageMemoryBarrier2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDependencyInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferSubmitInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubmitInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferCopy2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyBufferInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageCopy2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyImageInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferImageCopy2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyBufferToImageInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyImageToBufferInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageBlit2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBlitImageInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageResolve2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkResolveImageInfo2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingAttachmentInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRenderingCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFormatProperties3*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceBufferMemoryRequirements*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceImageMemoryRequirements*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVulkan14Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLineRasterizationProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryMapInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryUnmapInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance5Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingAreaInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageSubresource2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceImageSubresourceInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubresourceLayout2*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCreateFlags2CreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance6Properties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindMemoryStatus*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindDescriptorSetsInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPushConstantsInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPushDescriptorSetInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPushDescriptorSetWithTemplateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineRobustnessProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRobustnessCreateInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceHostImageCopyProperties*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryToImageCopy*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageToMemoryCopy*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyMemoryToImageInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyImageToMemoryInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyImageToImageInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkHostImageLayoutTransitionInfo*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubresourceHostMemcpySize*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPresentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAcquireNextImageInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayPresentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoProfileListInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoFormatInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoFormatPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoPictureResourceInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoReferenceSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoSessionMemoryRequirementsKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindVideoSessionMemoryInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoSessionCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoSessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoSessionParametersUpdateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoBeginCodingInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEndCodingInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoCodingControlInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264NaluSliceInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265SessionCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265QualityLevelPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265SessionParametersAddInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265SessionParametersGetInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265SessionParametersFeedbackInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265NaluSliceSegmentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265RateControlInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265RateControlLayerInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265GopRemainingFrameInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryFdPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPresentRegionsKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportFenceFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFenceGetFdInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceCounterKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceCounterDescriptionKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAcquireProfilingLockInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceCapabilities2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceFormat2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayProperties2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayPlaneProperties2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayModeProperties2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayPlaneInfo2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayPlaneCapabilities2KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265SessionParametersAddInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineExecutablePropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineExecutableInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineExecutableStatisticKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineExecutableInternalRepresentationKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPresentIdKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeRateControlLayerInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeQualityLevelPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeSessionParametersGetInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeSessionParametersFeedbackInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineBinaryPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineBinaryKeyKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineBinaryCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineBinaryInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkReleaseCapturedPipelineDataInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineBinaryDataInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineBinaryHandlesInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCooperativeMatrixPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1CapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1QualityLevelPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1SessionCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1PictureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1DpbSlotInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1ProfileInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1RateControlInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1RateControlLayerInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCalibratedTimestampInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSetDescriptorBufferOffsetsInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindDescriptorBufferEmbeddedSamplersInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeQuantizationMapCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance7PropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesListKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryBarrierAccessFlags3KHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVideoMaintenance2FeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH264InlineSessionParametersInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeH265InlineSessionParametersInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVideoDecodeAV1InlineSessionParametersInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewHandleInfoNVX*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewAddressPropertiesNVX*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkStreamDescriptorSurfaceCreateInfoGGP*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkValidationFlagsEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkViSurfaceCreateInfoNN*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkConditionalRenderingBeginInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceCapabilities2EXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayPowerInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceEventInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayEventInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkHdrMetadataEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugUtilsLabelEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalFormatANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSampleLocationsInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMultisamplePropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageDrmFormatModifierPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRayTracingShaderGroupCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRayTracingPipelineCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeometryTrianglesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeometryAABBNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeometryNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBindAccelerationStructureMemoryInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureMemoryRequirementsInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPresentFrameTokenGGP*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCheckpointDataNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCheckpointData2NV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkInitializePerformanceApiInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceMarkerInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceStreamMarkerInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceOverrideInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerformanceConfigurationAcquireInfoINTEL*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImagePipeSurfaceCreateInfoFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkValidationFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCooperativeMatrixPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFramebufferMixedSamplesCombinationNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkHeadlessSurfaceCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfacePresentModeEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfacePresentScalingCapabilitiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfacePresentModeCompatibilityEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainPresentFenceInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainPresentModesCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainPresentModeInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainPresentScalingCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkReleaseSwapchainImagesInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGraphicsShaderGroupCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectCommandsLayoutTokenNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDepthBiasInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceMemoryReportCallbackDataEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTileShadingPropertiesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassTileShadingCreateInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerTileBeginInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPerTileEndInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDispatchTileInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkQueryLowLatencySupportNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageCompressionControlEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageCompressionPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceFaultCountsEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceFaultInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVertexInputBindingDescription2EXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkVertexInputAttributeDescription2EXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryZirconHandlePropertiesFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetZirconHandleInfoFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportSemaphoreZirconHandleInfoFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSemaphoreGetZirconHandleInfoFUCHSIA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetRemoteAddressInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkFrameBoundaryEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMicromapBuildInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMicromapCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMicromapVersionInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyMicromapToMemoryInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyMemoryToMicromapInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyMicromapInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMicromapBuildSizesInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetBindingReferenceVALVE*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDescriptorSetLayoutHostMappingInfoVALVE*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassStripeInfoARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineIndirectDeviceAddressInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometrySpheresDataNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassCreationControlEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDirectDriverLoadingInfoLUNARG*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkShaderModuleIdentifierEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOpticalFlowImageFormatPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOpticalFlowSessionCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOpticalFlowExecuteInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAntiLagPresentationInfoAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAntiLagDataAMD*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkShaderCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTilePropertiesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeVectorPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCooperativeVectorPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkConvertCooperativeVectorMatrixInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLatencySleepModeInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLatencySleepInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSetLatencyMarkerInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLatencyTimingsFrameReportNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGetLatencyMarkerInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkOutOfBandQueueTypeInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTileMemoryRequirementsQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkTileMemorySizeInfoQCOM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplaySurfaceStereoCreateInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPartitionedAccelerationStructureInstancesInputNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkBuildPartitionedAccelerationStructureInfoNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureBuildSizesInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsMemoryRequirementsInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectExecutionSetPipelineInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectExecutionSetShaderLayoutInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectExecutionSetShaderInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectExecutionSetCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteIndirectExecutionSetPipelineEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectCommandsLayoutTokenEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteIndirectExecutionSetShaderEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPipelineViewportDepthClampControlCreateInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCooperativeMatrixFlexibleDimensionsPropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkImportMemoryMetalHandleInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryMetalHandlePropertiesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkMemoryGetMetalHandleInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkSetPresentConfigNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RENDERING_END_INFO_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRenderingEndInfoEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryTrianglesDataKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryAabbsDataKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryInstancesDataKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureGeometryKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureBuildGeometryInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureDeviceAddressInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkAccelerationStructureVersionInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyAccelerationStructureToMemoryInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyMemoryToAccelerationStructureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkCopyAccelerationStructureInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRayTracingShaderGroupCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRayTracingPipelineInterfaceCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkRayTracingPipelineCreateInfoKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(pNext), 1, out_ptr);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            offset += vulkan_struct_deep_copy(
                reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(pNext), 1, out_ptr);
            break;
    }
    return offset;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
