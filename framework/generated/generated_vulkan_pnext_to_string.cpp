/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

#include "util/custom_vulkan_to_string.h"
#include "generated_vulkan_struct_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string PNextToString(const void* pNext, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if (pNext)
    {
        switch (reinterpret_cast<const VkBaseInStructure*>(pNext)->sType)
        {
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkShaderModuleCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            return ToString(*reinterpret_cast<const VkMemoryDedicatedRequirements*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            return ToString(*reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            return ToString(*reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            return ToString(*reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const VkDeviceGroupSubmitInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            return ToString(*reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            return ToString(*reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            return ToString(*reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFeatures2*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkImageViewUsageCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const VkProtectedSubmitInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return ToString(*reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            return ToString(*reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            return ToString(*reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            return ToString(*reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            return ToString(*reinterpret_cast<const VkExternalImageFormatProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceIDProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const VkExportMemoryAllocateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkExportFenceCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkExportSemaphoreCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkImageFormatListCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            return ToString(*reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            return ToString(*reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkImageStencilUsageCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return ToString(*reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            return ToString(*reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            return ToString(*reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            return ToString(*reinterpret_cast<const VkMemoryBarrier2*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            return ToString(*reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            return ToString(*reinterpret_cast<const VkPipelineRenderingCreateInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            return ToString(*reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            return ToString(*reinterpret_cast<const VkFormatProperties3*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return ToString(*reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkDisplayPresentInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return ToString(*reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            return ToString(*reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            return ToString(*reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            return ToString(*reinterpret_cast<const VkImportMemoryFdInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            return ToString(*reinterpret_cast<const VkPresentRegionsKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return ToString(*reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            return ToString(*reinterpret_cast<const VkPresentIdKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            return ToString(*reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            return ToString(*reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return ToString(*reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return ToString(*reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return ToString(*reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            return ToString(*reinterpret_cast<const VkValidationFlagsEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            return ToString(*reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRobustnessCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            return ToString(*reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            return ToString(*reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return ToString(*reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            return ToString(*reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            return ToString(*reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return ToString(*reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            return ToString(*reinterpret_cast<const VkExternalFormatANDROID*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            return ToString(*reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSampleLocationsInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            return ToString(*reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            return ToString(*reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            return ToString(*reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return ToString(*reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            return ToString(*reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            return ToString(*reinterpret_cast<const VkPresentFrameTokenGGP*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            return ToString(*reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            return ToString(*reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkValidationFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            return ToString(*reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            return ToString(*reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            return ToString(*reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            return ToString(*reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            return ToString(*reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            return ToString(*reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            return ToString(*reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            return ToString(*reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            return ToString(*reinterpret_cast<const VkImageCompressionControlEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkImageCompressionPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            return ToString(*reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            return ToString(*reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            return ToString(*reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            return ToString(*reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return ToString(*reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            return ToString(*reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            return ToString(*reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            return ToString(*reinterpret_cast<const VkRenderPassCreationControlEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            return ToString(*reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            return ToString(*reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            return ToString(*reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return ToString(*reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(pNext), toStringFlags, tabCount, tabSize);
        default: break;
        }
    }
    return "null";
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
