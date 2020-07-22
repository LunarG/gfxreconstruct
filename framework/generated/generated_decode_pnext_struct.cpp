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

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/pnext_node.h"
#include "decode/pnext_typed_node.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* parameter_buffer, size_t buffer_size,  std::unique_ptr<PNextNode>* pNext)
{
    assert(pNext != nullptr);

    size_t bytes_read = 0;
    uint32_t attrib = 0;

    if ((parameter_buffer != nullptr) && (buffer_size >= sizeof(attrib)))
    {
        size_t stype_offset = 0;

        // Peek at the pointer attribute mask to make sure we have a non-NULL value that can be decoded.
        attrib = *(reinterpret_cast<const uint32_t*>(parameter_buffer));

        if ((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull)
        {
            // Offset to VkStructureType, after the pointer encoding preamble.
            stype_offset = sizeof(attrib);

            if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
            {
                stype_offset += sizeof(format::AddressEncodeType);
            }
        }

        if ((stype_offset != 0) && ((buffer_size - stype_offset) >= sizeof(VkStructureType)))
        {
            const VkStructureType* sType = reinterpret_cast<const VkStructureType*>(parameter_buffer + stype_offset);

            switch (*sType)
            {
            default:
                // TODO: This may need to be a fatal error
                GFXRECON_LOG_ERROR("Failed to decode pNext value with unrecognized VkStructurType = %d", (*sType));
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupProperties>>();
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
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupDeviceCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFeatures2>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVariablePointersFeatures>>();
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
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkProtectedSubmitInfo>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalImageFormatInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalImageFormatProperties>>();
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
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportFenceCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportSemaphoreCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMaintenance3Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan11Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan11Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan12Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan12Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageFormatListCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevice8BitStorageFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDriverProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderAtomicInt64Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderFloat16Int8Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFloatControlsProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSubpassDescriptionDepthStencilResolve>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDepthStencilResolveProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageStencilUsageCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerReductionModeCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFramebufferAttachmentsCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassAttachmentBeginInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAttachmentReferenceStencilLayout>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAttachmentDescriptionStencilLayout>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceHostQueryResetFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTimelineSemaphoreProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSemaphoreTypeCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkTimelineSemaphoreSubmitInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferOpaqueCaptureAddressCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo>>();
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
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupPresentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceGroupSwapchainCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayPresentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryFdInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPresentRegionsKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSharedPresentSurfaceCapabilitiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportFenceWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkQueryPoolPerformanceCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPerformanceQuerySubmitInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceProtectedCapabilitiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEFERRED_OPERATION_INFO_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeferredOperationInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkTextureLODGatherFormatPropertiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV>>();
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
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkValidationFlagsEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageViewASTCDecodeModeEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT>>();
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
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportWScalingStateCreateInfoNV>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDebugUtilsMessengerCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkAndroidHardwareBufferUsageANDROID>>();
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
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkExternalFormatANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWriteDescriptorSetInlineUniformBlockEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDrmFormatModifierPropertiesListEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageDrmFormatModifierListCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkShaderModuleValidationCacheCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCompilerControlCreateInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD>>();
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
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPresentFrameTokenGGP>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCreationFeedbackCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkQueueFamilyCheckpointPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkMemoryPriorityAllocateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkBufferDeviceAddressCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkValidationFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineCoverageReductionStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceFullScreenExclusiveInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPipelineRasterizationLineStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkRenderPassTransformBeginInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRobustness2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRobustness2PropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkSamplerCustomBorderColorCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePrivateDataFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDevicePrivateDataCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceImageRobustnessFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_FEATURES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR:
                (*pNext) = std::make_unique<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            }
        }
    }

    if ((bytes_read == 0) && (attrib != 0))
    {
        // The encoded pointer attribute mask included kIsNull, or the sType was unrecognized.
        // We will report that we read the attribute mask, but nothing else was decoded.
        bytes_read = sizeof(attrib);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
