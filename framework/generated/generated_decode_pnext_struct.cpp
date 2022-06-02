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

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/decode_allocator.h"
#include "decode/pnext_node.h"
#include "decode/pnext_typed_node.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* parameter_buffer, size_t buffer_size,  PNextNode** pNext)
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
                GFXRECON_LOG_ERROR("Failed to decode pNext value with unrecognized VkStructureType = %s", (util::ToString(*sType).c_str()));
                break;
            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkShaderModuleCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevice16BitStorageFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryDedicatedRequirements>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryDedicatedAllocateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryAllocateFlagsInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupRenderPassBeginInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupCommandBufferBeginInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupSubmitInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupBindSparseInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBindBufferMemoryDeviceGroupInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBindImageMemoryDeviceGroupInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupDeviceCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFeatures2>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePointClippingProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassInputAttachmentAspectCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageViewUsageCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassMultiviewCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVariablePointersFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceProtectedMemoryFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceProtectedMemoryProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkProtectedSubmitInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSamplerYcbcrConversionInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBindImagePlaneMemoryInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImagePlaneMemoryRequirementsInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSamplerYcbcrConversionImageFormatProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExternalImageFormatInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExternalImageFormatProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceIDProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExternalMemoryImageCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExternalMemoryBufferCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportMemoryAllocateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportFenceCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportSemaphoreCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMaintenance3Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan11Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan11Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan12Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan12Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageFormatListCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevice8BitStorageFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDriverProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderAtomicInt64Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderFloat16Int8Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFloatControlsProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorIndexingProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSubpassDescriptionDepthStencilResolve>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDepthStencilResolveProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageStencilUsageCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSamplerReductionModeCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkFramebufferAttachmentsCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassAttachmentBeginInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAttachmentReferenceStencilLayout>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAttachmentDescriptionStencilLayout>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceHostQueryResetFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTimelineSemaphoreProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSemaphoreTypeCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkTimelineSemaphoreSubmitInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBufferOpaqueCaptureAddressCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan13Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVulkan13Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineCreationFeedbackCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePrivateDataFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDevicePrivateDataCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryBarrier2>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSynchronization2Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageRobustnessFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSubgroupSizeControlProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceInlineUniformBlockFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceInlineUniformBlockProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkWriteDescriptorSetInlineUniformBlock>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRenderingCreateInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDynamicRenderingFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkCommandBufferInheritanceRenderingInfo>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkFormatProperties3>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMaintenance4Features>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMaintenance4Properties>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageSwapchainCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBindImageMemorySwapchainInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupPresentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceGroupSwapchainCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDisplayPresentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAttachmentSampleCountInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMultiviewPerViewAttributesInfoNVX>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportMemoryFdInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportSemaphoreWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkD3D12FenceSubmitInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPresentRegionsKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSharedPresentSurfaceCapabilitiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportFenceWin32HandleInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkQueryPoolPerformanceCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPerformanceQuerySubmitInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkFragmentShadingRateAttachmentInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSurfaceProtectedCapabilitiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineLibraryCreateInfoKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPresentIdKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePresentIdFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkQueueFamilyCheckpointProperties2NV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDebugReportCallbackCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDedicatedAllocationImageCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDedicatedAllocationBufferCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkTextureLODGatherFormatPropertiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExternalMemoryImageCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportMemoryAllocateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportMemoryWin32HandleInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExportMemoryWin32HandleInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkValidationFlagsEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageViewASTCDecodeModeEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportWScalingStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSwapchainCounterCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPresentTimesInfoGOOGLE>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDebugUtilsObjectNameInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDebugUtilsMessengerCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAndroidHardwareBufferUsageANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportAndroidHardwareBufferInfoANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkExternalFormatANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSampleLocationsInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassSampleLocationsBeginInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineCoverageToColorStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineCoverageModulationStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDrmFormatModifierPropertiesListEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageDrmFormatModifierListCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDrmFormatModifierPropertiesList2EXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkShaderModuleValidationCacheCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkWriteDescriptorSetAccelerationStructureNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportMemoryHostPointerInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineCompilerControlCreateInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPresentFrameTokenGGP>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkQueueFamilyCheckpointPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMemoryPriorityAllocateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkBufferDeviceAddressCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkValidationFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineCoverageReductionStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSurfaceFullScreenExclusiveInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineRasterizationLineStateCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkCommandBufferInheritanceViewportScissorInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassTransformBeginInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRobustness2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRobustness2PropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSamplerCustomBorderColorCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkAccelerationStructureMotionInfoNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkCopyCommandTransformInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageCompressionControlEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageCompressionPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkMutableDescriptorTypeCreateInfoVALVE>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDrmPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPipelineColorWriteCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkImageViewMinLodCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassCreationControlEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassCreationFeedbackCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkWriteDescriptorSetAccelerationStructureKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR>>();
                bytes_read = (*pNext)->Decode(parameter_buffer, buffer_size);
                break;
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
                (*pNext) = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR>>();
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
