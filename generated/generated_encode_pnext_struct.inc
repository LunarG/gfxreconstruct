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

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/parameter_encoder.h"
#include "format/trace_pnext_util.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

size_t encode_pnext_struct(format::ParameterEncoder* encoder, const void* value)
{
    size_t result = 0;

    const format::VulkanStructHeader* header = reinterpret_cast<const format::VulkanStructHeader*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    if ((header != nullptr) &&
        (header->sType != VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) &&
        (header->sType != VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))
    {
        switch (header->sType)
        {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkApplicationInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkInstanceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceQueueCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSubmitInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMappedMemoryRange*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindSparseInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkFenceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSemaphoreCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkEventCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkQueryPoolCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBufferCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBufferViewCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageViewCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkShaderModuleCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineCacheCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineShaderStageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineVertexInputStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineInputAssemblyStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineTessellationStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineViewportStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineRasterizationStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineMultisampleStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineDepthStencilStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineColorBlendStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineDynamicStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkGraphicsPipelineCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkComputePipelineCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineLayoutCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetLayoutCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorPoolCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkWriteDescriptorSet*>(value));
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCopyDescriptorSet*>(value));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkFramebufferCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCommandPoolCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCommandBufferAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCommandBufferInheritanceInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCommandBufferBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryBarrier*>(value));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBufferMemoryBarrier*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageMemoryBarrier*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindBufferMemoryInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindImageMemoryInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceGroupProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBufferMemoryRequirementsInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageMemoryRequirementsInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageSparseMemoryRequirementsInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryRequirements2*>(value));
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSparseImageMemoryRequirements2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkFormatProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageFormatProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceImageFormatInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkQueueFamilyProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSparseImageFormatProperties2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSparseImageFormatInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointerFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceQueueInfo2*>(value));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorUpdateTemplateCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalBufferInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalBufferProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalFenceInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalFenceProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalSemaphoreInfo*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalSemaphoreProperties*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetLayoutSupport*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParameterFeatures*>(value));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSwapchainCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPresentInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkAcquireNextImageInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupPresentCapabilitiesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDisplayModeCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDisplaySurfaceCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_XLIB_KHR
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkXlibSurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_XLIB_KHR */
#ifdef VK_USE_PLATFORM_XCB_KHR
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkXcbSurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_XCB_KHR */
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkWaylandSurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */
#ifdef VK_USE_PLATFORM_MIR_KHR
        case VK_STRUCTURE_TYPE_MIR_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMirSurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_MIR_KHR */
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidSurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkWin32SurfaceCreateInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryWin32HandlePropertiesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryGetWin32HandleInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryFdPropertiesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryGetFdInfoKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportSemaphoreWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSemaphoreGetWin32HandleInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportSemaphoreFdInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSemaphoreGetFdInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportFenceWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkFenceGetWin32HandleInfoKHR*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportFenceFdInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkFenceGetFdInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSurfaceInfo2KHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSurfaceCapabilities2KHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSurfaceFormat2KHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImageFormatListCreateInfoKHR*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugMarkerObjectNameInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugMarkerObjectTagInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugMarkerMarkerInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(value));
            break;
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
#ifdef VK_USE_PLATFORM_WIN32_KHR
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(value));
            break;
#endif /* VK_USE_PLATFORM_WIN32_KHR */
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(value));
            break;
#ifdef VK_USE_PLATFORM_VI_NN
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkViSurfaceCreateInfoNN*>(value));
            break;
#endif /* VK_USE_PLATFORM_VI_NN */
        case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGeneratedCommandsFeaturesNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceGeneratedCommandsLimitsNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkIndirectCommandsLayoutCreateInfoNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCmdProcessCommandsInfoNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkCmdReserveSpaceForCommandsInfoNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkObjectTableCreateInfoNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSurfaceCapabilities2EXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDisplayPowerInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceEventInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDisplayEventInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkHdrMetadataEXT*>(value));
            break;
#ifdef VK_USE_PLATFORM_IOS_MVK
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkIOSSurfaceCreateInfoMVK*>(value));
            break;
#endif /* VK_USE_PLATFORM_IOS_MVK */
#ifdef VK_USE_PLATFORM_MACOS_MVK
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMacOSSurfaceCreateInfoMVK*>(value));
            break;
#endif /* VK_USE_PLATFORM_MACOS_MVK */
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsObjectTagInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsLabelEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCallbackDataEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(value));
            break;
#ifdef VK_USE_PLATFORM_ANDROID_KHR
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidHardwareBufferPropertiesANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryGetAndroidHardwareBufferInfoANDROID*>(value));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(value));
            break;
#endif /* VK_USE_PLATFORM_ANDROID_KHR */
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMultisamplePropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(value));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkValidationCacheCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeaturesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupportEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkMemoryHostPointerPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(value));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(value));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            result = encode_struct_ptr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(value));
            break;
        }
    }

    return result;
}

BRIMSTONE_END_NAMESPACE(brimstone)
