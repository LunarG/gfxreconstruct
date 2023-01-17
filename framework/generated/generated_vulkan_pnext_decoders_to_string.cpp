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

#include "generated_vulkan_struct_decoders_to_string.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

std::string PNextDecodedToString(const decode::PNextNode* pNext, ToStringFlags toStringFlags, uint32_t tabCount, uint32_t tabSize)
{
    if (pNext)
    {
        // Assumes decoded_value is always first member of Decoded_[VulkanStructX].
        const void* meta = pNext->GetMetaStructPointer();
        assert(nullptr != meta);
        if(nullptr == meta)
        {
            GFXRECON_LOG_ERROR("Attempt to follow pNext chain without a metastructure pointer via PNextNode at address %p.", pNext);
            return "null";
        }
        const VkBaseInStructure*const decoded_value = (*(reinterpret_cast<const VkBaseInStructure*const*>(meta)));
        assert(decoded_value);
        if(nullptr == decoded_value)
        {
            GFXRECON_LOG_ERROR("Attempt to follow pNext chain to a struct which has not been decoded at address %p.", meta);
            return "null";
        }
        const VkStructureType sType = decoded_value->sType;
        switch (sType)
        {
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkShaderModuleCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSubgroupProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevice16BitStorageFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryDedicatedRequirements*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryDedicatedAllocateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryAllocateFlagsInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupRenderPassBeginInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupCommandBufferBeginInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupSubmitInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupBindSparseInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBindBufferMemoryDeviceGroupInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBindImageMemoryDeviceGroupInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupDeviceCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFeatures2*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePointClippingProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageViewUsageCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassMultiviewCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiviewFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiviewProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVariablePointersFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkProtectedSubmitInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSamplerYcbcrConversionInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBindImagePlaneMemoryInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImagePlaneMemoryRequirementsInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExternalImageFormatProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceIDProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExternalMemoryImageCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExternalMemoryBufferCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportMemoryAllocateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportFenceCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportSemaphoreCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMaintenance3Properties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan11Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan11Properties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan12Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan12Properties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageFormatListCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevice8BitStorageFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDriverProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFloatControlsProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDescriptorIndexingProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSubpassDescriptionDepthStencilResolve*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageStencilUsageCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSamplerReductionModeCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkFramebufferAttachmentsCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassAttachmentBeginInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAttachmentReferenceStencilLayout*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAttachmentDescriptionStencilLayout*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTimelineSemaphoreProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSemaphoreTypeCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkTimelineSemaphoreSubmitInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan13Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVulkan13Properties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineCreationFeedbackCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePrivateDataFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDevicePrivateDataCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryBarrier2*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSynchronization2Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSubgroupSizeControlProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceInlineUniformBlockProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            return ToString(*reinterpret_cast<const decode::Decoded_VkWriteDescriptorSetInlineUniformBlock*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRenderingCreateInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            return ToString(*reinterpret_cast<const decode::Decoded_VkCommandBufferInheritanceRenderingInfo*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            return ToString(*reinterpret_cast<const decode::Decoded_VkFormatProperties3*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMaintenance4Features*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMaintenance4Properties*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageSwapchainCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBindImageMemorySwapchainInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupPresentInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDisplayPresentInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueueFamilyVideoPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoProfileInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoProfileListInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeCapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeUsageInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264ProfileInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264CapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264PictureInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAttachmentSampleCountInfoAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMultiviewPerViewAttributesInfoNVX*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportMemoryWin32HandleInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportMemoryWin32HandleInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportMemoryFdInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkD3D12FenceSubmitInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPresentRegionsKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportFenceWin32HandleInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPerformanceQuerySubmitInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265ProfileInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265CapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265PictureInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoDecodeH265DpbSlotInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfaceProtectedCapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineLibraryCreateInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPresentIdKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeCapabilitiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeUsageInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeRateControlLayerInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeRateControlInfoKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueueFamilyCheckpointProperties2NV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDebugReportCallbackCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDedicatedAllocationImageCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264CapabilitiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264SessionParametersAddInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264SessionParametersCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_VCL_FRAME_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264VclFrameInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_EMIT_PICTURE_PARAMETERS_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264EmitPictureParametersInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264ProfileInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264RateControlInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH264RateControlLayerInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265CapabilitiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265SessionParametersAddInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265SessionParametersCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_VCL_FRAME_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265VclFrameInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_EMIT_PICTURE_PARAMETERS_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265EmitPictureParametersInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265ProfileInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265RateControlInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkVideoEncodeH265RateControlLayerInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkTextureLODGatherFormatPropertiesAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExternalMemoryImageCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportMemoryAllocateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportMemoryWin32HandleInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExportMemoryWin32HandleInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkValidationFlagsEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageViewASTCDecodeModeEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRobustnessCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainCounterCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPresentTimesInfoGOOGLE*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDebugUtilsObjectNameInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAndroidHardwareBufferUsageANDROID*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            return ToString(*reinterpret_cast<const decode::Decoded_VkExternalFormatANDROID*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSampleLocationsInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDrmFormatModifierPropertiesListEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDrmFormatModifierPropertiesList2EXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportMemoryHostPointerInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineCompilerControlCreateInfoAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPresentFrameTokenGGP*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueueFamilyCheckpointPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            return ToString(*reinterpret_cast<const decode::Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMemoryPriorityAllocateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkBufferDeviceAddressCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkValidationFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineRasterizationLineStateCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfacePresentModeEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfacePresentScalingCapabilitiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfacePresentModeCompatibilityEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainPresentFenceInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainPresentModesCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainPresentModeInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainPresentScalingCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassTransformBeginInfoQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRobustness2FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRobustness2PropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAccelerationStructureMotionInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkCopyCommandTransformInfoQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageCompressionControlEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageCompressionPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDeviceAddressBindingCallbackDataEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSubpassResolvePerformanceQueryEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineColorWriteCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageViewMinLodCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassCreationControlEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            return ToString(*reinterpret_cast<const decode::Decoded_VkDirectDriverLoadingListLUNARG*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkOpticalFlowImageFormatInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            return ToString(*reinterpret_cast<const decode::Decoded_VkAmigoProfilingSubmitInfoSEC*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(meta), toStringFlags, tabCount, tabSize);
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            return ToString(*reinterpret_cast<const decode::Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(meta), toStringFlags, tabCount, tabSize);
        default:
            {
                std::string error_message{std::string("\"Unknown Struct in pNext chain. sType: ") + std::to_string(uint32_t(sType)) + "\""};
                GFXRECON_LOG_ERROR(error_message.c_str());
            }
        }
    }
    return "null";
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
