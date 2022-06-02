/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#include "generated/generated_vulkan_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = base->pNext;
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatListCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryBarrier2*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRenderingCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFormatProperties3*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentIdKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentFrameTokenGGP*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionControlEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageCompressionPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMutableDescriptorTypeCreateInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreationControlEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base));
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
