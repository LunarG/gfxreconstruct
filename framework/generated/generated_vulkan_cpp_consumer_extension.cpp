/*
** Copyright (c) 2021 Samsung
** Copyright (c) 2023 Google
** Copyright (c) 2023 LunarG, Inc.
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

#include "generated/generated_vulkan_cpp_consumer_extension.h"
#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_cpp_structs.h"
#include "decode/vulkan_cpp_structs.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <iostream>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
typedef std::string (*PFN_GenerateExtensionStruct)(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer);

static std::string GenerateExtensionStruct_VkPipelineLayoutCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineLayoutCreateInfo(
        out,
        reinterpret_cast<const VkPipelineLayoutCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineLayoutCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkShaderModuleCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkShaderModuleCreateInfo(
        out,
        reinterpret_cast<const VkShaderModuleCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkShaderModuleCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBindBufferMemoryDeviceGroupInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBindBufferMemoryDeviceGroupInfo(
        out,
        reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(struct_info),
        reinterpret_cast<Decoded_VkBindBufferMemoryDeviceGroupInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBindImageMemoryDeviceGroupInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBindImageMemoryDeviceGroupInfo(
        out,
        reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(struct_info),
        reinterpret_cast<Decoded_VkBindImageMemoryDeviceGroupInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBindImagePlaneMemoryInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBindImagePlaneMemoryInfo(
        out,
        reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(struct_info),
        reinterpret_cast<Decoded_VkBindImagePlaneMemoryInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupBindSparseInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupBindSparseInfo(
        out,
        reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupBindSparseInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupCommandBufferBeginInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupCommandBufferBeginInfo(
        out,
        reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupCommandBufferBeginInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupDeviceCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupDeviceCreateInfo(
        out,
        reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupRenderPassBeginInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupRenderPassBeginInfo(
        out,
        reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupRenderPassBeginInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupSubmitInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupSubmitInfo(
        out,
        reinterpret_cast<const VkDeviceGroupSubmitInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupSubmitInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportFenceCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportFenceCreateInfo(
        out,
        reinterpret_cast<const VkExportFenceCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkExportFenceCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportMemoryAllocateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportMemoryAllocateInfo(
        out,
        reinterpret_cast<const VkExportMemoryAllocateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkExportMemoryAllocateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportSemaphoreCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportSemaphoreCreateInfo(
        out,
        reinterpret_cast<const VkExportSemaphoreCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkExportSemaphoreCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalImageFormatProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalImageFormatProperties(
        out,
        reinterpret_cast<const VkExternalImageFormatProperties*>(struct_info),
        reinterpret_cast<Decoded_VkExternalImageFormatProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalMemoryBufferCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalMemoryBufferCreateInfo(
        out,
        reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkExternalMemoryBufferCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalMemoryImageCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalMemoryImageCreateInfo(
        out,
        reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImagePlaneMemoryRequirementsInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImagePlaneMemoryRequirementsInfo(
        out,
        reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(struct_info),
        reinterpret_cast<Decoded_VkImagePlaneMemoryRequirementsInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewUsageCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewUsageCreateInfo(
        out,
        reinterpret_cast<const VkImageViewUsageCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewUsageCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryAllocateFlagsInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryAllocateFlagsInfo(
        out,
        reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryAllocateFlagsInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryDedicatedAllocateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryDedicatedAllocateInfo(
        out,
        reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryDedicatedRequirements(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryDedicatedRequirements(
        out,
        reinterpret_cast<const VkMemoryDedicatedRequirements*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryDedicatedRequirements*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevice16BitStorageFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevice16BitStorageFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevice16BitStorageFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExternalImageFormatInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExternalImageFormatInfo(
        out,
        reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFeatures2(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFeatures2(
        out,
        reinterpret_cast<const VkPhysicalDeviceFeatures2*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFeatures2*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceIDProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceIDProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceIDProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceIDProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance3Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance3Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance3Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiviewFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiviewFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiviewProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiviewProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePointClippingProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePointClippingProperties(
        out,
        reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePointClippingProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceProtectedMemoryFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceProtectedMemoryFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceProtectedMemoryProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceProtectedMemoryProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderDrawParametersFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderDrawParametersFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSubgroupProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSubgroupProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVariablePointersFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVariablePointersFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVariablePointersFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineTessellationDomainOriginStateCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineTessellationDomainOriginStateCreateInfo(
        out,
        reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkProtectedSubmitInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkProtectedSubmitInfo(
        out,
        reinterpret_cast<const VkProtectedSubmitInfo*>(struct_info),
        reinterpret_cast<Decoded_VkProtectedSubmitInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassInputAttachmentAspectCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassInputAttachmentAspectCreateInfo(
        out,
        reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassMultiviewCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassMultiviewCreateInfo(
        out,
        reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassMultiviewCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerYcbcrConversionImageFormatProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerYcbcrConversionImageFormatProperties(
        out,
        reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerYcbcrConversionInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerYcbcrConversionInfo(
        out,
        reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAttachmentDescriptionStencilLayout(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAttachmentDescriptionStencilLayout(
        out,
        reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(struct_info),
        reinterpret_cast<Decoded_VkAttachmentDescriptionStencilLayout*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAttachmentReferenceStencilLayout(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAttachmentReferenceStencilLayout(
        out,
        reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(struct_info),
        reinterpret_cast<Decoded_VkAttachmentReferenceStencilLayout*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBufferOpaqueCaptureAddressCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBufferOpaqueCaptureAddressCreateInfo(
        out,
        reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo(
        out,
        reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo(
        out,
        reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport(
        out,
        reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFramebufferAttachmentsCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFramebufferAttachmentsCreateInfo(
        out,
        reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkFramebufferAttachmentsCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageFormatListCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageFormatListCreateInfo(
        out,
        reinterpret_cast<const VkImageFormatListCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkImageFormatListCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageStencilUsageCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageStencilUsageCreateInfo(
        out,
        reinterpret_cast<const VkImageStencilUsageCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkImageStencilUsageCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryOpaqueCaptureAddressAllocateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryOpaqueCaptureAddressAllocateInfo(
        out,
        reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevice8BitStorageFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevice8BitStorageFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevice8BitStorageFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceBufferDeviceAddressFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthStencilResolveProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthStencilResolveProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorIndexingFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorIndexingFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorIndexingProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorIndexingProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorIndexingProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDriverProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDriverProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDriverProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFloatControlsProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFloatControlsProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFloatControlsProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceHostQueryResetFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceHostQueryResetFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImagelessFramebufferFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImagelessFramebufferFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceScalarBlockLayoutFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceScalarBlockLayoutFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicInt64Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAtomicInt64Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderFloat16Int8Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderFloat16Int8Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTimelineSemaphoreFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTimelineSemaphoreFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTimelineSemaphoreProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTimelineSemaphoreProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTimelineSemaphoreProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan11Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan11Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan11Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan11Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan11Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan12Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan12Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan12Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan12Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan12Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkanMemoryModelFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkanMemoryModelFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassAttachmentBeginInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassAttachmentBeginInfo(
        out,
        reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassAttachmentBeginInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerReductionModeCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerReductionModeCreateInfo(
        out,
        reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerReductionModeCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSemaphoreTypeCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSemaphoreTypeCreateInfo(
        out,
        reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkSemaphoreTypeCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSubpassDescriptionDepthStencilResolve(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSubpassDescriptionDepthStencilResolve(
        out,
        reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(struct_info),
        reinterpret_cast<Decoded_VkSubpassDescriptionDepthStencilResolve*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTimelineSemaphoreSubmitInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTimelineSemaphoreSubmitInfo(
        out,
        reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(struct_info),
        reinterpret_cast<Decoded_VkTimelineSemaphoreSubmitInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCommandBufferInheritanceRenderingInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCommandBufferInheritanceRenderingInfo(
        out,
        reinterpret_cast<const VkCommandBufferInheritanceRenderingInfo*>(struct_info),
        reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderingInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorPoolInlineUniformBlockCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorPoolInlineUniformBlockCreateInfo(
        out,
        reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDevicePrivateDataCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDevicePrivateDataCreateInfo(
        out,
        reinterpret_cast<const VkDevicePrivateDataCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDevicePrivateDataCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFormatProperties3(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFormatProperties3(
        out,
        reinterpret_cast<const VkFormatProperties3*>(struct_info),
        reinterpret_cast<Decoded_VkFormatProperties3*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryBarrier2(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryBarrier2(
        out,
        reinterpret_cast<const VkMemoryBarrier2*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryBarrier2*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDynamicRenderingFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageRobustnessFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageRobustnessFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceInlineUniformBlockFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceInlineUniformBlockFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceInlineUniformBlockProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceInlineUniformBlockProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceInlineUniformBlockProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance4Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance4Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance4Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance4Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance4Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance4Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance4Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePrivateDataFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePrivateDataFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevicePrivateDataFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePrivateDataFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerDotProductProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderIntegerDotProductProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSubgroupSizeControlFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSubgroupSizeControlFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSubgroupSizeControlProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSubgroupSizeControlProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSubgroupSizeControlProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSynchronization2Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSynchronization2Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceSynchronization2Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSynchronization2Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTexelBufferAlignmentProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan13Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan13Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan13Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan13Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan13Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan13Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan13Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCreationFeedbackCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCreationFeedbackCreateInfo(
        out,
        reinterpret_cast<const VkPipelineCreationFeedbackCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCreationFeedbackCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRenderingCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRenderingCreateInfo(
        out,
        reinterpret_cast<const VkPipelineRenderingCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRenderingCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo(
        out,
        reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWriteDescriptorSetInlineUniformBlock(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWriteDescriptorSetInlineUniformBlock(
        out,
        reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlock*>(struct_info),
        reinterpret_cast<Decoded_VkWriteDescriptorSetInlineUniformBlock*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBindMemoryStatus(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBindMemoryStatus(
        out,
        reinterpret_cast<const VkBindMemoryStatus*>(struct_info),
        reinterpret_cast<Decoded_VkBindMemoryStatus*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBufferUsageFlags2CreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBufferUsageFlags2CreateInfo(
        out,
        reinterpret_cast<const VkBufferUsageFlags2CreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkBufferUsageFlags2CreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceQueueGlobalPriorityCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceQueueGlobalPriorityCreateInfo(
        out,
        reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceQueueGlobalPriorityCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkHostImageCopyDevicePerformanceQuery(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkHostImageCopyDevicePerformanceQuery(
        out,
        reinterpret_cast<const VkHostImageCopyDevicePerformanceQuery*>(struct_info),
        reinterpret_cast<Decoded_VkHostImageCopyDevicePerformanceQuery*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDynamicRenderingLocalReadFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGlobalPriorityQueryFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGlobalPriorityQueryFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceHostImageCopyFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceHostImageCopyFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceHostImageCopyFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceHostImageCopyProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceHostImageCopyProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceHostImageCopyProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceHostImageCopyProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceIndexTypeUint8Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceIndexTypeUint8Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceIndexTypeUint8Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLineRasterizationFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLineRasterizationFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLineRasterizationProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLineRasterizationProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceLineRasterizationProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLineRasterizationProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance5Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance5Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance5Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance5Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance5Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance5Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance5Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance6Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance6Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance6Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance6Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance6Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance6Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance6Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineProtectedAccessFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineProtectedAccessFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineProtectedAccessFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineRobustnessFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineRobustnessFeatures(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineRobustnessFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineRobustnessProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineRobustnessProperties(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineRobustnessProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineRobustnessProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePushDescriptorProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePushDescriptorProperties(
        out,
        reinterpret_cast<const VkPhysicalDevicePushDescriptorProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePushDescriptorProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderExpectAssumeFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderExpectAssumeFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderExpectAssumeFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderFloatControls2Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderFloatControls2Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderFloatControls2Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloatControls2Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupRotateFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSubgroupRotateFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSubgroupRotateFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorFeatures(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorFeatures(
        out,
        reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeatures*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorProperties(
        out,
        reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorProperties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan14Features(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan14Features(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan14Features*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Features*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVulkan14Properties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVulkan14Properties(
        out,
        reinterpret_cast<const VkPhysicalDeviceVulkan14Properties*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVulkan14Properties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCreateFlags2CreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCreateFlags2CreateInfo(
        out,
        reinterpret_cast<const VkPipelineCreateFlags2CreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCreateFlags2CreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationLineStateCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationLineStateCreateInfo(
        out,
        reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationLineStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRobustnessCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRobustnessCreateInfo(
        out,
        reinterpret_cast<const VkPipelineRobustnessCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRobustnessCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineVertexInputDivisorStateCreateInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineVertexInputDivisorStateCreateInfo(
        out,
        reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfo*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineVertexInputDivisorStateCreateInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyGlobalPriorityProperties(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyGlobalPriorityProperties(
        out,
        reinterpret_cast<const VkQueueFamilyGlobalPriorityProperties*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyGlobalPriorityProperties*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderingAttachmentLocationInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderingAttachmentLocationInfo(
        out,
        reinterpret_cast<const VkRenderingAttachmentLocationInfo*>(struct_info),
        reinterpret_cast<Decoded_VkRenderingAttachmentLocationInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderingInputAttachmentIndexInfo(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderingInputAttachmentIndexInfo(
        out,
        reinterpret_cast<const VkRenderingInputAttachmentIndexInfo*>(struct_info),
        reinterpret_cast<Decoded_VkRenderingInputAttachmentIndexInfo*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSubresourceHostMemcpySize(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSubresourceHostMemcpySize(
        out,
        reinterpret_cast<const VkSubresourceHostMemcpySize*>(struct_info),
        reinterpret_cast<Decoded_VkSubresourceHostMemcpySize*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBindImageMemorySwapchainInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBindImageMemorySwapchainInfoKHR(
        out,
        reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupPresentInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupPresentInfoKHR(
        out,
        reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupPresentInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceGroupSwapchainCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceGroupSwapchainCreateInfoKHR(
        out,
        reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageSwapchainCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageSwapchainCreateInfoKHR(
        out,
        reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDisplayPresentInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDisplayPresentInfoKHR(
        out,
        reinterpret_cast<const VkDisplayPresentInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkDisplayPresentInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyQueryResultStatusPropertiesKHR(
        out,
        reinterpret_cast<const VkQueueFamilyQueryResultStatusPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyVideoPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyVideoPropertiesKHR(
        out,
        reinterpret_cast<const VkQueueFamilyVideoPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyVideoPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoProfileListInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoProfileListInfoKHR(
        out,
        reinterpret_cast<const VkVideoProfileListInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoProfileListInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoDecodeCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeUsageInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeUsageInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeUsageInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeUsageInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264DpbSlotInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264DpbSlotInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264DpbSlotInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264GopRemainingFrameInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264GopRemainingFrameInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264GopRemainingFrameInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264PictureInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264PictureInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264PictureInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264ProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264ProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264ProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264QualityLevelPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264QualityLevelPropertiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264QualityLevelPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264RateControlInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264RateControlInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264RateControlInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264RateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264RateControlLayerInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264RateControlLayerInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264RateControlLayerInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264RateControlLayerInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264SessionCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264SessionCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264SessionCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264SessionCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264SessionParametersAddInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264SessionParametersAddInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264SessionParametersAddInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264SessionParametersCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264SessionParametersCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264SessionParametersCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264SessionParametersFeedbackInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264SessionParametersGetInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264SessionParametersGetInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264SessionParametersGetInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264DpbSlotInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264DpbSlotInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264DpbSlotInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264PictureInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264PictureInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264PictureInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264ProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264ProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264ProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264SessionParametersAddInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264SessionParametersAddInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeH264SessionParametersCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportMemoryWin32HandleInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportMemoryWin32HandleInfoKHR(
        out,
        reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryWin32HandleInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryWin32HandleInfoKHR(
        out,
        reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryFdInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryFdInfoKHR(
        out,
        reinterpret_cast<const VkImportMemoryFdInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryFdInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR(
        out,
        reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkD3D12FenceSubmitInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkD3D12FenceSubmitInfoKHR(
        out,
        reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkD3D12FenceSubmitInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportSemaphoreWin32HandleInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportSemaphoreWin32HandleInfoKHR(
        out,
        reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentRegionsKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentRegionsKHR(
        out,
        reinterpret_cast<const VkPresentRegionsKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPresentRegionsKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSharedPresentSurfaceCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSharedPresentSurfaceCapabilitiesKHR(
        out,
        reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportFenceWin32HandleInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportFenceWin32HandleInfoKHR(
        out,
        reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkExportFenceWin32HandleInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPerformanceQuerySubmitInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPerformanceQuerySubmitInfoKHR(
        out,
        reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPerformanceQuerySubmitInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueryPoolPerformanceCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueryPoolPerformanceCreateInfoKHR(
        out,
        reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderBfloat16FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderBfloat16FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderClockFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderClockFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFragmentShadingRateAttachmentInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFragmentShadingRateAttachmentInfoKHR(
        out,
        reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR(
        out,
        reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR(
        out,
        reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderConstantDataFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderConstantDataFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderConstantDataFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderConstantDataFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceFaultShaderAbortMessageInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceFaultShaderAbortMessageInfoKHR(
        out,
        reinterpret_cast<const VkDeviceFaultShaderAbortMessageInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceFaultShaderAbortMessageInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAbortFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAbortFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAbortFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAbortFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAbortPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAbortPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAbortPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAbortPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderQuadControlFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderQuadControlFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceProtectedCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceProtectedCapabilitiesKHR(
        out,
        reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceProtectedCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentWaitFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentWaitFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineLibraryCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineLibraryCreateInfoKHR(
        out,
        reinterpret_cast<const VkPipelineLibraryCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineLibraryCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentIdFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentIdFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentIdKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentIdKHR(
        out,
        reinterpret_cast<const VkPresentIdKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPresentIdKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR(
        out,
        reinterpret_cast<const VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeQualityLevelInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeQualityLevelInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeQualityLevelInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeQualityLevelInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeRateControlInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeRateControlInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeRateControlInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeRateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeUsageInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeUsageInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeUsageInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeUsageInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryRangeBarriersInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryRangeBarriersInfoKHR(
        out,
        reinterpret_cast<const VkMemoryRangeBarriersInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryRangeBarriersInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentId2FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentId2FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentId2FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentId2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentId2KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentId2KHR(
        out,
        reinterpret_cast<const VkPresentId2KHR*>(struct_info),
        reinterpret_cast<Decoded_VkPresentId2KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceCapabilitiesPresentId2KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceCapabilitiesPresentId2KHR(
        out,
        reinterpret_cast<const VkSurfaceCapabilitiesPresentId2KHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentId2KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentWait2FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentWait2FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentWait2FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentWait2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceCapabilitiesPresentWait2KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceCapabilitiesPresentWait2KHR(
        out,
        reinterpret_cast<const VkSurfaceCapabilitiesPresentWait2KHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentWait2KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDevicePipelineBinaryInternalCacheControlKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDevicePipelineBinaryInternalCacheControlKHR(
        out,
        reinterpret_cast<const VkDevicePipelineBinaryInternalCacheControlKHR*>(struct_info),
        reinterpret_cast<Decoded_VkDevicePipelineBinaryInternalCacheControlKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineBinaryFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineBinaryFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineBinaryFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineBinaryPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineBinaryPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineBinaryPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineBinaryInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineBinaryInfoKHR(
        out,
        reinterpret_cast<const VkPipelineBinaryInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineBinaryInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfacePresentModeCompatibilityKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfacePresentModeCompatibilityKHR(
        out,
        reinterpret_cast<const VkSurfacePresentModeCompatibilityKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfacePresentModeCompatibilityKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfacePresentModeKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfacePresentModeKHR(
        out,
        reinterpret_cast<const VkSurfacePresentModeKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfacePresentModeKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfacePresentScalingCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfacePresentScalingCapabilitiesKHR(
        out,
        reinterpret_cast<const VkSurfacePresentScalingCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSurfacePresentScalingCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainPresentFenceInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainPresentFenceInfoKHR(
        out,
        reinterpret_cast<const VkSwapchainPresentFenceInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainPresentFenceInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainPresentModeInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainPresentModeInfoKHR(
        out,
        reinterpret_cast<const VkSwapchainPresentModeInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainPresentModeInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainPresentModesCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainPresentModesCreateInfoKHR(
        out,
        reinterpret_cast<const VkSwapchainPresentModesCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainPresentModesCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainPresentScalingCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainPresentScalingCreateInfoKHR(
        out,
        reinterpret_cast<const VkSwapchainPresentScalingCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainPresentScalingCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeAV1CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeAV1CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoDecodeAV1CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeAV1CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeAV1DpbSlotInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeAV1DpbSlotInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeAV1DpbSlotInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeAV1DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeAV1PictureInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeAV1PictureInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeAV1PictureInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeAV1PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeAV1ProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeAV1ProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeAV1ProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeAV1ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeAV1SessionParametersCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeAV1SessionParametersCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1DpbSlotInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1DpbSlotInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1DpbSlotInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1DpbSlotInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1GopRemainingFrameInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1GopRemainingFrameInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1PictureInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1PictureInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1PictureInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1ProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1ProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1ProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1QualityLevelPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1QualityLevelPropertiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1QualityLevelPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1RateControlInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1RateControlInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1RateControlInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1RateControlLayerInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1RateControlLayerInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1RateControlLayerInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1SessionCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1SessionCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1SessionCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1SessionCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1SessionParametersCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1SessionParametersCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeVP9CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeVP9CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoDecodeVP9CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeVP9CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeVP9PictureInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeVP9PictureInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeVP9PictureInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeVP9PictureInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoDecodeVP9ProfileInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoDecodeVP9ProfileInfoKHR(
        out,
        reinterpret_cast<const VkVideoDecodeVP9ProfileInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoDecodeVP9ProfileInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoMaintenance1FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoInlineQueryInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoInlineQueryInfoKHR(
        out,
        reinterpret_cast<const VkVideoInlineQueryInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoInlineQueryInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAttachmentFeedbackLoopInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAttachmentFeedbackLoopInfoEXT(
        out,
        reinterpret_cast<const VkAttachmentFeedbackLoopInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkAttachmentFeedbackLoopInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeIntraRefreshCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeIntraRefreshCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeIntraRefreshCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeIntraRefreshInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeIntraRefreshInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeIntraRefreshInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeIntraRefreshInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeSessionIntraRefreshCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoReferenceIntraRefreshInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoReferenceIntraRefreshInfoKHR(
        out,
        reinterpret_cast<const VkVideoReferenceIntraRefreshInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoReferenceIntraRefreshInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH264QuantizationMapCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeH265QuantizationMapCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeQuantizationMapCapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeQuantizationMapCapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeQuantizationMapCapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeQuantizationMapInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeQuantizationMapInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeQuantizationMapInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR(
        out,
        reinterpret_cast<const VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoFormatAV1QuantizationMapPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoFormatAV1QuantizationMapPropertiesKHR(
        out,
        reinterpret_cast<const VkVideoFormatAV1QuantizationMapPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoFormatH265QuantizationMapPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoFormatH265QuantizationMapPropertiesKHR(
        out,
        reinterpret_cast<const VkVideoFormatH265QuantizationMapPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoFormatQuantizationMapPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoFormatQuantizationMapPropertiesKHR(
        out,
        reinterpret_cast<const VkVideoFormatQuantizationMapPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoFormatQuantizationMapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLayeredApiPropertiesListKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLayeredApiPropertiesListKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceLayeredApiPropertiesListKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance7FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance7FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance7FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance7PropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance7PropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance7PropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFaultFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFaultFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFaultFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFaultPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFaultPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceFaultPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFaultPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryBarrierAccessFlags3KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryBarrierAccessFlags3KHR(
        out,
        reinterpret_cast<const VkMemoryBarrierAccessFlags3KHR*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryBarrierAccessFlags3KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance8FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance8FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance8FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderFmaFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderFmaFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderFmaFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance9FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance9FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance9FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance9PropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance9PropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance9PropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyOwnershipTransferPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyOwnershipTransferPropertiesKHR(
        out,
        reinterpret_cast<const VkQueueFamilyOwnershipTransferPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR(
        out,
        reinterpret_cast<const VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeFeedback2CapabilitiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeFeedback2CapabilitiesKHR(
        out,
        reinterpret_cast<const VkVideoEncodeFeedback2CapabilitiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeFeedback2CapabilitiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRobustness2FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRobustness2FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRobustness2PropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRobustness2PropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRobustness2PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureGeometryMicromapDataKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureGeometryMicromapDataKHR(
        out,
        reinterpret_cast<const VkAccelerationStructureGeometryMicromapDataKHR*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureGeometryMicromapDataKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureTrianglesOpacityMicromapKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapKHR(
        out,
        reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapKHR*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance10FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance10FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance10FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance10PropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance10PropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance10PropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderingAttachmentFlagsInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderingAttachmentFlagsInfoKHR(
        out,
        reinterpret_cast<const VkRenderingAttachmentFlagsInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkRenderingAttachmentFlagsInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkResolveImageModeInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkResolveImageModeInfoKHR(
        out,
        reinterpret_cast<const VkResolveImageModeInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkResolveImageModeInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMaintenance11FeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMaintenance11FeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceMaintenance11FeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMaintenance11FeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR(
        out,
        reinterpret_cast<const VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFormatProperties4KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFormatProperties4KHR(
        out,
        reinterpret_cast<const VkFormatProperties4KHR*>(struct_info),
        reinterpret_cast<Decoded_VkFormatProperties4KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageCreateFlags2CreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageCreateFlags2CreateInfoKHR(
        out,
        reinterpret_cast<const VkImageCreateFlags2CreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImageCreateFlags2CreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageStencilUsage2CreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageStencilUsage2CreateInfoKHR(
        out,
        reinterpret_cast<const VkImageStencilUsage2CreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImageStencilUsage2CreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageUsageFlags2CreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageUsageFlags2CreateInfoKHR(
        out,
        reinterpret_cast<const VkImageUsageFlags2CreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImageUsageFlags2CreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewUsage2CreateInfoKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewUsage2CreateInfoKHR(
        out,
        reinterpret_cast<const VkImageViewUsage2CreateInfoKHR*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewUsage2CreateInfoKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedFlagsFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedFlagsFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedFlagsFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedFlagsFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSharedPresentSurfaceCapabilities2KHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSharedPresentSurfaceCapabilities2KHR(
        out,
        reinterpret_cast<const VkSharedPresentSurfaceCapabilities2KHR*>(struct_info),
        reinterpret_cast<Decoded_VkSharedPresentSurfaceCapabilities2KHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDebugReportCallbackCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDebugReportCallbackCreateInfoEXT(
        out,
        reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDebugReportCallbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationStateRasterizationOrderAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationStateRasterizationOrderAMD(
        out,
        reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDedicatedAllocationBufferCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDedicatedAllocationBufferCreateInfoNV(
        out,
        reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDedicatedAllocationImageCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDedicatedAllocationImageCreateInfoNV(
        out,
        reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkDedicatedAllocationImageCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDedicatedAllocationMemoryAllocateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDedicatedAllocationMemoryAllocateInfoNV(
        out,
        reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationStateStreamCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTextureLODGatherFormatPropertiesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTextureLODGatherFormatPropertiesAMD(
        out,
        reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkTextureLODGatherFormatPropertiesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportMemoryAllocateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportMemoryAllocateInfoNV(
        out,
        reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkExportMemoryAllocateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalMemoryImageCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalMemoryImageCreateInfoNV(
        out,
        reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkExternalMemoryImageCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExportMemoryWin32HandleInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExportMemoryWin32HandleInfoNV(
        out,
        reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkExportMemoryWin32HandleInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryWin32HandleInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryWin32HandleInfoNV(
        out,
        reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryWin32HandleInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWin32KeyedMutexAcquireReleaseInfoNV(
        out,
        reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkValidationFlagsEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkValidationFlagsEXT(
        out,
        reinterpret_cast<const VkValidationFlagsEXT*>(struct_info),
        reinterpret_cast<Decoded_VkValidationFlagsEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewASTCDecodeModeEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewASTCDecodeModeEXT(
        out,
        reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewASTCDecodeModeEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT(
        out,
        reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportWScalingStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportWScalingStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainCounterCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainCounterCreateInfoEXT(
        out,
        reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainCounterCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentTimesInfoGOOGLE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentTimesInfoGOOGLE(
        out,
        reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(struct_info),
        reinterpret_cast<Decoded_VkPresentTimesInfoGOOGLE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMultiviewPerViewAttributesInfoNVX(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMultiviewPerViewAttributesInfoNVX(
        out,
        reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(struct_info),
        reinterpret_cast<Decoded_VkMultiviewPerViewAttributesInfoNVX*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportSwizzleStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportSwizzleStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineDiscardRectangleStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG(
        out,
        reinterpret_cast<const VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDebugUtilsMessengerCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDebugUtilsMessengerCreateInfoEXT(
        out,
        reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDebugUtilsObjectNameInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDebugUtilsObjectNameInfoEXT(
        out,
        reinterpret_cast<const VkDebugUtilsObjectNameInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDebugUtilsObjectNameInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAndroidHardwareBufferFormatProperties2ANDROID(
        out,
        reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAndroidHardwareBufferFormatPropertiesANDROID(
        out,
        reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAndroidHardwareBufferUsageANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAndroidHardwareBufferUsageANDROID(
        out,
        reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkAndroidHardwareBufferUsageANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalFormatANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalFormatANDROID(
        out,
        reinterpret_cast<const VkExternalFormatANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkExternalFormatANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportAndroidHardwareBufferInfoANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportAndroidHardwareBufferInfoANDROID(
        out,
        reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGpaFeaturesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGpaFeaturesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceGpaFeaturesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGpaFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGpaProperties2AMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGpaProperties2AMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceGpaProperties2AMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGpaProperties2AMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGpaPropertiesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGpaPropertiesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceGpaPropertiesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGpaPropertiesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAttachmentSampleCountInfoAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAttachmentSampleCountInfoAMD(
        out,
        reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(struct_info),
        reinterpret_cast<Decoded_VkAttachmentSampleCountInfoAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineSampleLocationsStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineSampleLocationsStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassSampleLocationsBeginInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassSampleLocationsBeginInfoEXT(
        out,
        reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSampleLocationsInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSampleLocationsInfoEXT(
        out,
        reinterpret_cast<const VkSampleLocationsInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSampleLocationsInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCoverageToColorStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCoverageToColorStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCoverageModulationStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCoverageModulationStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDrmFormatModifierPropertiesList2EXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDrmFormatModifierPropertiesList2EXT(
        out,
        reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(struct_info),
        reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesList2EXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDrmFormatModifierPropertiesListEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDrmFormatModifierPropertiesListEXT(
        out,
        reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDrmFormatModifierPropertiesListEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT(
        out,
        reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageDrmFormatModifierListCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageDrmFormatModifierListCreateInfoEXT(
        out,
        reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkShaderModuleValidationCacheCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkShaderModuleValidationCacheCreateInfoEXT(
        out,
        reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShadingRateImageFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShadingRateImagePropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWriteDescriptorSetAccelerationStructureNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWriteDescriptorSetAccelerationStructureNV(
        out,
        reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(struct_info),
        reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFilterCubicImageViewImageFormatPropertiesEXT(
        out,
        reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryHostPointerInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryHostPointerInfoEXT(
        out,
        reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryHostPointerInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCompilerControlCreateInfoAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCompilerControlCreateInfoAMD(
        out,
        reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCompilerControlCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderCorePropertiesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderCorePropertiesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceMemoryOverallocationCreateInfoAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceMemoryOverallocationCreateInfoAMD(
        out,
        reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentFrameTokenGGP(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentFrameTokenGGP(
        out,
        reinterpret_cast<const VkPresentFrameTokenGGP*>(struct_info),
        reinterpret_cast<Decoded_VkPresentFrameTokenGGP*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMeshShaderFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMeshShaderPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyCheckpointProperties2NV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyCheckpointProperties2NV(
        out,
        reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyCheckpointProperties2NV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueueFamilyCheckpointPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueueFamilyCheckpointPropertiesNV(
        out,
        reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkQueueFamilyCheckpointPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentTimingFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentTimingFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentTimingFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentTimingFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentTimingSurfaceCapabilitiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentTimingSurfaceCapabilitiesEXT(
        out,
        reinterpret_cast<const VkPresentTimingSurfaceCapabilitiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPresentTimingSurfaceCapabilitiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPresentTimingsInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPresentTimingsInfoEXT(
        out,
        reinterpret_cast<const VkPresentTimingsInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPresentTimingsInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainCalibratedTimestampInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainCalibratedTimestampInfoEXT(
        out,
        reinterpret_cast<const VkSwapchainCalibratedTimestampInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainCalibratedTimestampInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL(
        out,
        reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(struct_info),
        reinterpret_cast<Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD(
        out,
        reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD(
        out,
        reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassFragmentDensityMapCreateInfoEXT(
        out,
        reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT(
        out,
        reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderCoreProperties2AMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderCoreProperties2AMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryPriorityAllocateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryPriorityAllocateInfoEXT(
        out,
        reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryPriorityAllocateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBufferDeviceAddressCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBufferDeviceAddressCreateInfoEXT(
        out,
        reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkBufferDeviceAddressCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkValidationFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkValidationFeaturesEXT(
        out,
        reinterpret_cast<const VkValidationFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkValidationFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineCoverageReductionStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineCoverageReductionStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT(
        out,
        reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceFullScreenExclusiveInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceFullScreenExclusiveInfoEXT(
        out,
        reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT(
        out,
        reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryMapPlacedInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryMapPlacedInfoEXT(
        out,
        reinterpret_cast<const VkMemoryMapPlacedInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryMapPlacedInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV(
        out,
        reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCommandBufferInheritanceViewportScissorInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCommandBufferInheritanceViewportScissorInfoNV(
        out,
        reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM(
        out,
        reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassTransformBeginInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassTransformBeginInfoQCOM(
        out,
        reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassTransformBeginInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDepthBiasRepresentationInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDepthBiasRepresentationInfoEXT(
        out,
        reinterpret_cast<const VkDepthBiasRepresentationInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDepthBiasRepresentationInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceDeviceMemoryReportCreateInfoEXT(
        out,
        reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerCustomBorderColorCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerCustomBorderColorCreateInfoEXT(
        out,
        reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentBarrierFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentBarrierFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentBarrierFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSurfaceCapabilitiesPresentBarrierNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSurfaceCapabilitiesPresentBarrierNV(
        out,
        reinterpret_cast<const VkSurfaceCapabilitiesPresentBarrierNV*>(struct_info),
        reinterpret_cast<Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainPresentBarrierCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainPresentBarrierCreateInfoNV(
        out,
        reinterpret_cast<const VkSwapchainPresentBarrierCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceDiagnosticsConfigCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceDiagnosticsConfigCreateInfoNV(
        out,
        reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceQueuePerfHintFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceQueuePerfHintFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceQueuePerfHintFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceQueuePerfHintFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceQueuePerfHintPropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceQueuePerfHintPropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceQueuePerfHintPropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceQueuePerfHintPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageProcessing3FeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageProcessing3FeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageProcessing3FeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing3FeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSplitBarrierFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSplitBarrierFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSplitBarrierFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSplitBarrierFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSplitBarrierPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSplitBarrierPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSplitBarrierPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSplitBarrierPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTileShadingFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTileShadingFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTileShadingFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTileShadingPropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTileShadingPropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTileShadingPropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassTileShadingCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassTileShadingCreateInfoQCOM(
        out,
        reinterpret_cast<const VkRenderPassTileShadingCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassTileShadingCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT(
        out,
        reinterpret_cast<const VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkOpaqueCaptureDescriptorDataCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkOpaqueCaptureDescriptorDataCreateInfoEXT(
        out,
        reinterpret_cast<const VkOpaqueCaptureDescriptorDataCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkOpaqueCaptureDescriptorDataCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorBufferFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorBufferPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorBufferPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkGraphicsPipelineLibraryCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkGraphicsPipelineLibraryCreateInfoEXT(
        out,
        reinterpret_cast<const VkGraphicsPipelineLibraryCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV(
        out,
        reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV(
        out,
        reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureMotionInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureMotionInfoNV(
        out,
        reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureMotionInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCopyCommandTransformInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCopyCommandTransformInfoQCOM(
        out,
        reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkCopyCommandTransformInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageCompressionControlEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageCompressionControlEXT(
        out,
        reinterpret_cast<const VkImageCompressionControlEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageCompressionControlEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageCompressionPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageCompressionPropertiesEXT(
        out,
        reinterpret_cast<const VkImageCompressionPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageCompressionPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevice4444FormatsFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevice4444FormatsFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFaultFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFaultFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFaultFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMutableDescriptorTypeCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMutableDescriptorTypeCreateInfoEXT(
        out,
        reinterpret_cast<const VkMutableDescriptorTypeCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDrmPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDrmPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceAddressBindingCallbackDataEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceAddressBindingCallbackDataEXT(
        out,
        reinterpret_cast<const VkDeviceAddressBindingCallbackDataEXT*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceAddressBindingCallbackDataEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthClipControlFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportDepthClipControlCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineViewportDepthClipControlCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryZirconHandleInfoFUCHSIA(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryZirconHandleInfoFUCHSIA(
        out,
        reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI(
        out,
        reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFrameBoundaryEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFrameBoundaryEXT(
        out,
        reinterpret_cast<const VkFrameBoundaryEXT*>(struct_info),
        reinterpret_cast<Decoded_VkFrameBoundaryEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMultisampledRenderToSingleSampledInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMultisampledRenderToSingleSampledInfoEXT(
        out,
        reinterpret_cast<const VkMultisampledRenderToSingleSampledInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSubpassResolvePerformanceQueryEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSubpassResolvePerformanceQueryEXT(
        out,
        reinterpret_cast<const VkSubpassResolvePerformanceQueryEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSubpassResolvePerformanceQueryEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineColorWriteCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineColorWriteCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineColorWriteCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE(
        out,
        reinterpret_cast<const VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeProfileRgbConversionInfoVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeProfileRgbConversionInfoVALVE(
        out,
        reinterpret_cast<const VkVideoEncodeProfileRgbConversionInfoVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeRgbConversionCapabilitiesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeRgbConversionCapabilitiesVALVE(
        out,
        reinterpret_cast<const VkVideoEncodeRgbConversionCapabilitiesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkVideoEncodeSessionRgbConversionCreateInfoVALVE(
        out,
        reinterpret_cast<const VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewMinLodCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewMinLodCreateInfoEXT(
        out,
        reinterpret_cast<const VkImageViewMinLodCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewMinLodCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiDrawFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiDrawPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderTileImageFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderTileImagePropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT(
        out,
        reinterpret_cast<const VkAccelerationStructureTrianglesOpacityMicromapEXT*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV(
        out,
        reinterpret_cast<const VkAccelerationStructureTrianglesDisplacementMicromapNV*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI(
        out,
        reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI(
        out,
        reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(
        out,
        reinterpret_cast<const VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT(
        out,
        reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderCorePropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderCorePropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDeviceQueueShaderCoreControlCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDeviceQueueShaderCoreControlCreateInfoARM(
        out,
        reinterpret_cast<const VkDeviceQueueShaderCoreControlCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSchedulingControlsFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceSchedulingControlsFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSchedulingControlsPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceSchedulingControlsPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewSlicedCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewSlicedCreateInfoEXT(
        out,
        reinterpret_cast<const VkImageViewSlicedCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewSlicedCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRenderPassStripedFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRenderPassStripedFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceRenderPassStripedFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRenderPassStripedPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRenderPassStripedPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceRenderPassStripedPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassStripeBeginInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassStripeBeginInfoARM(
        out,
        reinterpret_cast<const VkRenderPassStripeBeginInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassStripeBeginInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassStripeSubmitInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassStripeSubmitInfoARM(
        out,
        reinterpret_cast<const VkRenderPassStripeSubmitInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassStripeSubmitInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassFragmentDensityMapOffsetEndInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassFragmentDensityMapOffsetEndInfoEXT(
        out,
        reinterpret_cast<const VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkComputePipelineIndirectBufferInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkComputePipelineIndirectBufferInfoNV(
        out,
        reinterpret_cast<const VkComputePipelineIndirectBufferInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkComputePipelineIndirectBufferInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureGeometryLinearSweptSpheresDataNV(
        out,
        reinterpret_cast<const VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAccelerationStructureGeometrySpheresDataNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAccelerationStructureGeometrySpheresDataNV(
        out,
        reinterpret_cast<const VkAccelerationStructureGeometrySpheresDataNV*>(struct_info),
        reinterpret_cast<Decoded_VkAccelerationStructureGeometrySpheresDataNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageViewSampleWeightCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageViewSampleWeightCreateInfoQCOM(
        out,
        reinterpret_cast<const VkImageViewSampleWeightCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageProcessingFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageProcessingPropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalMemoryAcquireUnmodifiedEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalMemoryAcquireUnmodifiedEXT(
        out,
        reinterpret_cast<const VkExternalMemoryAcquireUnmodifiedEXT*>(struct_info),
        reinterpret_cast<Decoded_VkExternalMemoryAcquireUnmodifiedEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassCreationControlEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassCreationControlEXT(
        out,
        reinterpret_cast<const VkRenderPassCreationControlEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassCreationControlEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassCreationFeedbackCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassCreationFeedbackCreateInfoEXT(
        out,
        reinterpret_cast<const VkRenderPassCreationFeedbackCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassSubpassFeedbackCreateInfoEXT(
        out,
        reinterpret_cast<const VkRenderPassSubpassFeedbackCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDirectDriverLoadingListLUNARG(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDirectDriverLoadingListLUNARG(
        out,
        reinterpret_cast<const VkDirectDriverLoadingListLUNARG*>(struct_info),
        reinterpret_cast<Decoded_VkDirectDriverLoadingListLUNARG*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDescriptorGetTensorInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDescriptorGetTensorInfoARM(
        out,
        reinterpret_cast<const VkDescriptorGetTensorInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDescriptorGetTensorInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkExternalMemoryTensorCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkExternalMemoryTensorCreateInfoARM(
        out,
        reinterpret_cast<const VkExternalMemoryTensorCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkExternalMemoryTensorCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkFrameBoundaryTensorsARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkFrameBoundaryTensorsARM(
        out,
        reinterpret_cast<const VkFrameBoundaryTensorsARM*>(struct_info),
        reinterpret_cast<Decoded_VkFrameBoundaryTensorsARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMemoryDedicatedAllocateInfoTensorARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMemoryDedicatedAllocateInfoTensorARM(
        out,
        reinterpret_cast<const VkMemoryDedicatedAllocateInfoTensorARM*>(struct_info),
        reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfoTensorARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorBufferTensorPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTensorFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTensorFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTensorFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTensorFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTensorPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTensorPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTensorPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTensorPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorDependencyInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorDependencyInfoARM(
        out,
        reinterpret_cast<const VkTensorDependencyInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorDependencyInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorDescriptionARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorDescriptionARM(
        out,
        reinterpret_cast<const VkTensorDescriptionARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorDescriptionARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorFormatPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorFormatPropertiesARM(
        out,
        reinterpret_cast<const VkTensorFormatPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorFormatPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorMemoryBarrierARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorMemoryBarrierARM(
        out,
        reinterpret_cast<const VkTensorMemoryBarrierARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorMemoryBarrierARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWriteDescriptorSetTensorARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWriteDescriptorSetTensorARM(
        out,
        reinterpret_cast<const VkWriteDescriptorSetTensorARM*>(struct_info),
        reinterpret_cast<Decoded_VkWriteDescriptorSetTensorARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkOpticalFlowImageFormatInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkOpticalFlowImageFormatInfoNV(
        out,
        reinterpret_cast<const VkOpticalFlowImageFormatInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkOpticalFlowImageFormatInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV(
        out,
        reinterpret_cast<const VkOpticalFlowSessionCreatePrivateDataInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpticalFlowFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpticalFlowFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceOpticalFlowPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceOpticalFlowPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID(
        out,
        reinterpret_cast<const VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID(
        out,
        reinterpret_cast<const VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID(
        out,
        reinterpret_cast<const VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAntiLagFeaturesAMD(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAntiLagFeaturesAMD(
        out,
        reinterpret_cast<const VkPhysicalDeviceAntiLagFeaturesAMD*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAntiLagFeaturesAMD*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderObjectFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderObjectFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderObjectPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderObjectPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkAmigoProfilingSubmitInfoSEC(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkAmigoProfilingSubmitInfoSEC(
        out,
        reinterpret_cast<const VkAmigoProfilingSubmitInfoSEC*>(struct_info),
        reinterpret_cast<Decoded_VkAmigoProfilingSubmitInfoSEC*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC(
        out,
        reinterpret_cast<const VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeVectorFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeVectorFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeVectorFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeVectorPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeVectorPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeVectorPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkLayerSettingsCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkLayerSettingsCreateInfoEXT(
        out,
        reinterpret_cast<const VkLayerSettingsCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkLayerSettingsCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkLatencySubmissionPresentIdNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkLatencySubmissionPresentIdNV(
        out,
        reinterpret_cast<const VkLatencySubmissionPresentIdNV*>(struct_info),
        reinterpret_cast<Decoded_VkLatencySubmissionPresentIdNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkLatencySurfaceCapabilitiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkLatencySurfaceCapabilitiesNV(
        out,
        reinterpret_cast<const VkLatencySurfaceCapabilitiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkLatencySurfaceCapabilitiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainLatencyCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainLatencyCreateInfoNV(
        out,
        reinterpret_cast<const VkSwapchainLatencyCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainLatencyCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineCompilerControlCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineCompilerControlCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineCompilerControlCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineCompilerControlCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineIdentifierCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineIdentifierCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineIdentifierCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineIdentifierCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineShaderModuleCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineShaderModuleCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineShaderModuleCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineShaderModuleCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphProcessingEngineCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphProcessingEngineCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphProcessingEngineCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphProcessingEngineCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDataGraphFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDataGraphFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDataGraphFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(
        out,
        reinterpret_cast<const VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePerStageDescriptorSetFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerBlockMatchWindowCreateInfoQCOM(
        out,
        reinterpret_cast<const VkSamplerBlockMatchWindowCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkBlitImageCubicWeightsInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkBlitImageCubicWeightsInfoQCOM(
        out,
        reinterpret_cast<const VkBlitImageCubicWeightsInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkBlitImageCubicWeightsInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerCubicWeightsCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerCubicWeightsCreateInfoQCOM(
        out,
        reinterpret_cast<const VkSamplerCubicWeightsCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(
        out,
        reinterpret_cast<const VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCubicClampFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceCubicClampFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT(
        out,
        reinterpret_cast<const VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTileMemoryBindInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTileMemoryBindInfoQCOM(
        out,
        reinterpret_cast<const VkTileMemoryBindInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkTileMemoryBindInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTileMemoryRequirementsQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTileMemoryRequirementsQCOM(
        out,
        reinterpret_cast<const VkTileMemoryRequirementsQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkTileMemoryRequirementsQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTileMemorySizeInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTileMemorySizeInfoQCOM(
        out,
        reinterpret_cast<const VkTileMemorySizeInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkTileMemorySizeInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMemoryDecompressionFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMemoryDecompressionFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMemoryDecompressionPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMemoryDecompressionPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDisplayModeStereoPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDisplayModeStereoPropertiesNV(
        out,
        reinterpret_cast<const VkDisplayModeStereoPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkDisplayModeStereoPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDisplaySurfaceStereoCreateInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDisplaySurfaceStereoCreateInfoNV(
        out,
        reinterpret_cast<const VkDisplaySurfaceStereoCreateInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkDisplaySurfaceStereoCreateInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRawAccessChainsFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRawAccessChainsFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRawAccessChainsFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorExplicitTilingFormatPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorExplicitTilingFormatPropertiesARM(
        out,
        reinterpret_cast<const VkTensorExplicitTilingFormatPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorExplicitTilingFormatPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkTensorRollingBackingCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkTensorRollingBackingCreateInfoARM(
        out,
        reinterpret_cast<const VkTensorRollingBackingCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkTensorRollingBackingCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderFloat8FeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderFloat8FeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderFloat8FeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingValidationFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingValidationFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingValidationFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPartitionedAccelerationStructureFlagsNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPartitionedAccelerationStructureFlagsNV(
        out,
        reinterpret_cast<const VkPartitionedAccelerationStructureFlagsNV*>(struct_info),
        reinterpret_cast<Decoded_VkPartitionedAccelerationStructureFlagsNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWriteDescriptorSetPartitionedAccelerationStructureNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWriteDescriptorSetPartitionedAccelerationStructureNV(
        out,
        reinterpret_cast<const VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(struct_info),
        reinterpret_cast<Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkGeneratedCommandsPipelineInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkGeneratedCommandsPipelineInfoEXT(
        out,
        reinterpret_cast<const VkGeneratedCommandsPipelineInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkGeneratedCommandsPipelineInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkGeneratedCommandsShaderInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkGeneratedCommandsShaderInfoEXT(
        out,
        reinterpret_cast<const VkGeneratedCommandsShaderInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkGeneratedCommandsShaderInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImageAlignmentControlCreateInfoMESA(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImageAlignmentControlCreateInfoMESA(
        out,
        reinterpret_cast<const VkImageAlignmentControlCreateInfoMESA*>(struct_info),
        reinterpret_cast<Decoded_VkImageAlignmentControlCreateInfoMESA*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageAlignmentControlFeaturesMESA(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceImageAlignmentControlPropertiesMESA(
        out,
        reinterpret_cast<const VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePushConstantBankFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePushConstantBankFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePushConstantBankFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePushConstantBankFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePushConstantBankPropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePushConstantBankPropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePushConstantBankPropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePushConstantBankPropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPushConstantBankInfoNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPushConstantBankInfoNV(
        out,
        reinterpret_cast<const VkPushConstantBankInfoNV*>(struct_info),
        reinterpret_cast<Decoded_VkPushConstantBankInfoNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDepthClampControlFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDepthClampControlFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceDepthClampControlFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineViewportDepthClampControlCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineViewportDepthClampControlCreateInfoEXT(
        out,
        reinterpret_cast<const VkPipelineViewportDepthClampControlCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkHdrVividDynamicMetadataHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkHdrVividDynamicMetadataHUAWEI(
        out,
        reinterpret_cast<const VkHdrVividDynamicMetadataHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkHdrVividDynamicMetadataHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceHdrVividFeaturesHUAWEI(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceHdrVividFeaturesHUAWEI(
        out,
        reinterpret_cast<const VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrix2FeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrix2PropertiesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkImportMemoryMetalHandleInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkImportMemoryMetalHandleInfoEXT(
        out,
        reinterpret_cast<const VkImportMemoryMetalHandleInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkImportMemoryMetalHandleInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM(
        out,
        reinterpret_cast<const VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkRenderPassPerformanceCountersByRegionBeginInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkRenderPassPerformanceCountersByRegionBeginInfoARM(
        out,
        reinterpret_cast<const VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFormatPackFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFormatPackFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceFormatPackFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFormatPackFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE(
        out,
        reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE(
        out,
        reinterpret_cast<const VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePresentMeteringFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePresentMeteringFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDevicePresentMeteringFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePresentMeteringFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSetPresentConfigNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSetPresentConfigNV(
        out,
        reinterpret_cast<const VkSetPresentConfigNV*>(struct_info),
        reinterpret_cast<Decoded_VkSetPresentConfigNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkSwapchainFlagsSurfaceCapabilitiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkSwapchainFlagsSurfaceCapabilitiesEXT(
        out,
        reinterpret_cast<const VkSwapchainFlagsSurfaceCapabilitiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkSwapchainFlagsSurfaceCapabilitiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShader64BitIndexingFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkCustomResolveCreateInfoEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkCustomResolveCreateInfoEXT(
        out,
        reinterpret_cast<const VkCustomResolveCreateInfoEXT*>(struct_info),
        reinterpret_cast<Decoded_VkCustomResolveCreateInfoEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCustomResolveFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCustomResolveFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceCustomResolveFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineBuiltinModelCreateInfoQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineBuiltinModelCreateInfoQCOM(
        out,
        reinterpret_cast<const VkDataGraphPipelineBuiltinModelCreateInfoQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDataGraphModelFeaturesQCOM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDataGraphModelFeaturesQCOM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphOpticalFlowImageFormatInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphOpticalFlowImageFormatInfoARM(
        out,
        reinterpret_cast<const VkDataGraphOpticalFlowImageFormatInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphOpticalFlowImageFormatInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineOpticalFlowCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineOpticalFlowCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineOpticalFlowCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineOpticalFlowCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineOpticalFlowDispatchInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineOpticalFlowDispatchInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineOpticalFlowDispatchInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineOpticalFlowDispatchInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineResourceInfoImageLayoutARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineResourceInfoImageLayoutARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineResourceInfoImageLayoutARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineResourceInfoImageLayoutARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineSingleNodeCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineSingleNodeCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineSingleNodeCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineSingleNodeCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderLongVectorFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderLongVectorFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderLongVectorFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderLongVectorFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderLongVectorPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderLongVectorPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderLongVectorPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderLongVectorPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC(
        out,
        reinterpret_cast<const VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE(
        out,
        reinterpret_cast<const VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceThrottleHintFeaturesSEC(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceThrottleHintFeaturesSEC(
        out,
        reinterpret_cast<const VkPhysicalDeviceThrottleHintFeaturesSEC*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceThrottleHintFeaturesSEC*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkThrottleHintSubmitInfoSEC(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkThrottleHintSubmitInfoSEC(
        out,
        reinterpret_cast<const VkThrottleHintSubmitInfoSEC*>(struct_info),
        reinterpret_cast<Decoded_VkThrottleHintSubmitInfoSEC*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineNeuralStatisticsCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineNeuralStatisticsCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineNeuralStatisticsCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineNeuralStatisticsCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM(
        out,
        reinterpret_cast<const VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*>(struct_info),
        reinterpret_cast<Decoded_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM(
        out,
        reinterpret_cast<const VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV(
        out,
        reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkWriteDescriptorSetAccelerationStructureKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkWriteDescriptorSetAccelerationStructureKHR(
        out,
        reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(struct_info),
        reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceRayQueryFeaturesKHR(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceRayQueryFeaturesKHR(
        out,
        reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMeshShaderFeaturesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

static std::string GenerateExtensionStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(
    std::ostream& out, const void* struct_info, PNextNode* pnext_meta_data, VulkanCppConsumerBase& consumer)
{
    return "&" + GenerateStruct_VkPhysicalDeviceMeshShaderPropertiesEXT(
        out,
        reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesEXT*>(struct_info),
        reinterpret_cast<Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(pnext_meta_data->GetMetaStructPointer()),
        consumer);
}

std::string GenerateExtension(std::ostream& out, const void* struct_info, void* meta_info, VulkanCppConsumerBase& consumer) {
    std::string next_var_name = "NULL";
    if (struct_info != nullptr && meta_info != nullptr) {
        const VkBaseInStructure* base_struct = reinterpret_cast<const VkBaseInStructure*>(struct_info);
        PNextNode* pnext_meta_data = reinterpret_cast<PNextNode*>(meta_info);
        PFN_GenerateExtensionStruct next_struct_generator = nullptr;
        switch (base_struct->sType) {
            case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineLayoutCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkShaderModuleCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkBindBufferMemoryDeviceGroupInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkBindImageMemoryDeviceGroupInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkBindImagePlaneMemoryInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupBindSparseInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupCommandBufferBeginInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupDeviceCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupRenderPassBeginInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupSubmitInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkExportFenceCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkExportMemoryAllocateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkExportSemaphoreCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkExternalImageFormatProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkExternalMemoryBufferCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkExternalMemoryImageCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkImagePlaneMemoryRequirementsInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewUsageCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryAllocateFlagsInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryDedicatedAllocateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryDedicatedRequirements;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevice16BitStorageFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExternalImageFormatInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFeatures2;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceIDProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance3Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiviewFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiviewProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePointClippingProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceProtectedMemoryFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceProtectedMemoryProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSamplerYcbcrConversionFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderDrawParametersFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSubgroupProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVariablePointersFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineTessellationDomainOriginStateCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkProtectedSubmitInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassInputAttachmentAspectCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassMultiviewCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerYcbcrConversionImageFormatProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerYcbcrConversionInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: {
                next_struct_generator = GenerateExtensionStruct_VkAttachmentDescriptionStencilLayout;
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: {
                next_struct_generator = GenerateExtensionStruct_VkAttachmentReferenceStencilLayout;
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkBufferOpaqueCaptureAddressCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorSetLayoutBindingFlagsCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorSetVariableDescriptorCountAllocateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorSetVariableDescriptorCountLayoutSupport;
                break;
            }
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkFramebufferAttachmentsCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkImageFormatListCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkImageStencilUsageCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryOpaqueCaptureAddressAllocateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevice8BitStorageFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceBufferDeviceAddressFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthStencilResolveProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorIndexingFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorIndexingProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDriverProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFloatControlsProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceHostQueryResetFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImagelessFramebufferFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSamplerFilterMinmaxProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceScalarBlockLayoutFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicInt64Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderFloat16Int8Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTimelineSemaphoreFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTimelineSemaphoreProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceUniformBufferStandardLayoutFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan11Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan11Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan12Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan12Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkanMemoryModelFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassAttachmentBeginInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerReductionModeCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkSemaphoreTypeCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: {
                next_struct_generator = GenerateExtensionStruct_VkSubpassDescriptionDepthStencilResolve;
                break;
            }
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkTimelineSemaphoreSubmitInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkCommandBufferInheritanceRenderingInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorPoolInlineUniformBlockCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDevicePrivateDataCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3: {
                next_struct_generator = GenerateExtensionStruct_VkFormatProperties3;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryBarrier2;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageRobustnessFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceInlineUniformBlockFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceInlineUniformBlockProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance4Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance4Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineCreationCacheControlFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePrivateDataFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerDotProductFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerDotProductProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderTerminateInvocationFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSubgroupSizeControlFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSubgroupSizeControlProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSynchronization2Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTexelBufferAlignmentProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTextureCompressionASTCHDRFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan13Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan13Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCreationFeedbackCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRenderingCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK: {
                next_struct_generator = GenerateExtensionStruct_VkWriteDescriptorSetInlineUniformBlock;
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS: {
                next_struct_generator = GenerateExtensionStruct_VkBindMemoryStatus;
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkBufferUsageFlags2CreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceQueueGlobalPriorityCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY: {
                next_struct_generator = GenerateExtensionStruct_VkHostImageCopyDevicePerformanceQuery;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingLocalReadFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGlobalPriorityQueryFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceHostImageCopyFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceHostImageCopyProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceIndexTypeUint8Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLineRasterizationFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLineRasterizationProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance5Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance5Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance6Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance6Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineProtectedAccessFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineRobustnessFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineRobustnessProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePushDescriptorProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderExpectAssumeFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderFloatControls2Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupRotateFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorFeatures;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan14Features;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVulkan14Properties;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCreateFlags2CreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationLineStateCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRobustnessCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineVertexInputDivisorStateCreateInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyGlobalPriorityProperties;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkRenderingAttachmentLocationInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO: {
                next_struct_generator = GenerateExtensionStruct_VkRenderingInputAttachmentIndexInfo;
                break;
            }
            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE: {
                next_struct_generator = GenerateExtensionStruct_VkSubresourceHostMemcpySize;
                break;
            }
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkBindImageMemorySwapchainInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupPresentInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceGroupSwapchainCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImageSwapchainCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkDisplayPresentInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyQueryResultStatusPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyVideoPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoProfileListInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeUsageInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264DpbSlotInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264GopRemainingFrameInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264PictureInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264ProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264QualityLevelPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264RateControlInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264RateControlLayerInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264SessionCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264SessionParametersAddInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264SessionParametersCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264SessionParametersFeedbackInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264SessionParametersGetInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264DpbSlotInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264PictureInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264ProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264SessionParametersAddInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeH264SessionParametersCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkExportMemoryWin32HandleInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryWin32HandleInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryFdInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkWin32KeyedMutexAcquireReleaseInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkD3D12FenceSubmitInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkExportSemaphoreWin32HandleInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPresentRegionsKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSharedPresentSurfaceCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkExportFenceWin32HandleInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPerformanceQuerySubmitInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePerformanceQueryFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePerformanceQueryPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueryPoolPerformanceCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderBfloat16FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePortabilitySubsetFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePortabilitySubsetPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderClockFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkFragmentShadingRateAttachmentInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRatePropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineFragmentShadingRateStateCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkRenderingFragmentShadingRateAttachmentInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CONSTANT_DATA_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderConstantDataFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_FAULT_SHADER_ABORT_MESSAGE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceFaultShaderAbortMessageInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAbortFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ABORT_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAbortPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderQuadControlFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceProtectedCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentWaitFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineLibraryCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentIdFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPresentIdKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeQualityLevelInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeRateControlInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeUsageInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_RANGE_BARRIERS_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryRangeBarriersInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_ADDRESS_COMMANDS_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentId2FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPresentId2KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceCapabilitiesPresentId2KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentWait2FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceCapabilitiesPresentWait2KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkDevicePipelineBinaryInternalCacheControlKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineBinaryFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineBinaryPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineBinaryInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfacePresentModeCompatibilityKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfacePresentModeKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSurfacePresentScalingCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainPresentFenceInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainPresentModeInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainPresentModesCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainPresentScalingCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INTERNALLY_SYNCHRONIZED_QUEUES_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeAV1CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeAV1DpbSlotInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeAV1PictureInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeAV1ProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeAV1SessionParametersCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1DpbSlotInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1GopRemainingFrameInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1PictureInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1ProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1QualityLevelPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1RateControlInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1RateControlLayerInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1SessionCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1SessionParametersCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeVP9CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeVP9PictureInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoDecodeVP9ProfileInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoMaintenance1FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoInlineQueryInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkAttachmentFeedbackLoopInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeIntraRefreshCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeIntraRefreshInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeSessionIntraRefreshCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoReferenceIntraRefreshInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH264QuantizationMapCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeH265QuantizationMapCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeQuantizationMapCapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeQuantizationMapInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoFormatAV1QuantizationMapPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoFormatH265QuantizationMapPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoFormatQuantizationMapPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLayeredApiPropertiesListKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance7FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance7PropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFaultFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFaultPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryBarrierAccessFlags3KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance8FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderFmaFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance9FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance9PropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyOwnershipTransferPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_FEEDBACK_2_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_PER_PARTITION_FEEDBACK_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_FEEDBACK_2_CAPABILITIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeFeedback2CapabilitiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRobustness2FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRobustness2PropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MICROMAP_DATA_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureGeometryMicromapDataKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureTrianglesOpacityMicromapKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance10FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance10PropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkRenderingAttachmentFlagsInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkResolveImageModeInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_11_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMaintenance11FeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OPTIMAL_IMAGE_TRANSFER_GRANULARITY_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_4_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkFormatProperties4KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_CREATE_FLAGS_2_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImageCreateFlags2CreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_2_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImageStencilUsage2CreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_USAGE_FLAGS_2_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImageUsageFlags2CreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_2_CREATE_INFO_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewUsage2CreateInfoKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_FLAGS_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedFlagsFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_2_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkSharedPresentSurfaceCapabilities2KHR;
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDebugReportCallbackCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationStateRasterizationOrderAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDedicatedAllocationBufferCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDedicatedAllocationImageCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDedicatedAllocationMemoryAllocateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTransformFeedbackFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTransformFeedbackPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationStateStreamCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkTextureLODGatherFormatPropertiesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCornerSampledImageFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkExportMemoryAllocateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkExternalMemoryImageCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkExportMemoryWin32HandleInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryWin32HandleInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkWin32KeyedMutexAcquireReleaseInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkValidationFlagsEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewASTCDecodeModeEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceASTCDecodeFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkCommandBufferInheritanceConditionalRenderingInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceConditionalRenderingFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportWScalingStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainCounterCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: {
                next_struct_generator = GenerateExtensionStruct_VkPresentTimesInfoGOOGLE;
                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX: {
                next_struct_generator = GenerateExtensionStruct_VkMultiviewPerViewAttributesInfoNVX;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportSwizzleStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDiscardRectanglePropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineDiscardRectangleStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceConservativeRasterizationPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationConservativeStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthClipEnableFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationDepthClipStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG;
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDebugUtilsMessengerCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDebugUtilsObjectNameInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkAndroidHardwareBufferFormatProperties2ANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkAndroidHardwareBufferFormatPropertiesANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkAndroidHardwareBufferUsageANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkExternalFormatANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkImportAndroidHardwareBufferInfoANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_FEATURES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGpaFeaturesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_2_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGpaProperties2AMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GPA_PROPERTIES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGpaPropertiesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkAttachmentSampleCountInfoAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSampleLocationsPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineSampleLocationsStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassSampleLocationsBeginInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSampleLocationsInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineColorBlendAdvancedStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCoverageToColorStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCoverageModulationStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDrmFormatModifierPropertiesList2EXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDrmFormatModifierPropertiesListEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageDrmFormatModifierExplicitCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageDrmFormatModifierListCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageDrmFormatModifierInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkShaderModuleValidationCacheCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShadingRateImageFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShadingRateImagePropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportShadingRateImageStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: {
                next_struct_generator = GenerateExtensionStruct_VkWriteDescriptorSetAccelerationStructureNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRepresentativeFragmentTestStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkFilterCubicImageViewImageFormatPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageViewImageFormatInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_CONVERSION_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ELAPSED_TIMER_QUERY_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryHostPointerInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExternalMemoryHostPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCompilerControlCreateInfoAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderCorePropertiesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceMemoryOverallocationCreateInfoAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: {
                next_struct_generator = GenerateExtensionStruct_VkPresentFrameTokenGGP;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMeshShaderFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMeshShaderPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderImageFootprintFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExclusiveScissorFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportExclusiveScissorStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyCheckpointProperties2NV;
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkQueueFamilyCheckpointPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentTimingFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPresentTimingSurfaceCapabilitiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPresentTimingsInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainCalibratedTimestampInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
                break;
            }
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: {
                next_struct_generator = GenerateExtensionStruct_VkQueryPoolPerformanceQueryCreateInfoINTEL;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePCIBusInfoPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkDisplayNativeHdrSurfaceCapabilitiesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainDisplayNativeHdrCreateInfoAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassFragmentDensityMapCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderingFragmentDensityMapAttachmentInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderCoreProperties2AMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCoherentMemoryFeaturesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMemoryBudgetPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryPriorityAllocateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMemoryPriorityFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkBufferDeviceAddressCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkValidationFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCoverageReductionModeFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineCoverageReductionStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceProvokingVertexFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceProvokingVertexPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceCapabilitiesFullScreenExclusiveEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceFullScreenExclusiveInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceFullScreenExclusiveWin32InfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryMapPlacedInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkGraphicsPipelineShaderGroupsCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkCommandBufferInheritanceViewportScissorInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceInheritedViewportScissorFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkCommandBufferInheritanceRenderPassTransformInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassTransformBeginInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDepthBiasRepresentationInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthBiasControlFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceDeviceMemoryReportCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCustomBorderColorFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCustomBorderColorPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerCustomBorderColorCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_3D_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentBarrierFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV: {
                next_struct_generator = GenerateExtensionStruct_VkSurfaceCapabilitiesPresentBarrierNV;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainPresentBarrierCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceDiagnosticsConfigCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDiagnosticsConfigFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceQueuePerfHintFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_PERF_HINT_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceQueuePerfHintPropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_3_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageProcessing3FeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MULTIPLE_WAIT_QUEUES_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSplitBarrierFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SPLIT_BARRIER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSplitBarrierPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTileShadingFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTileShadingPropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassTileShadingCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkOpaqueCaptureDescriptorDataCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkGraphicsPipelineLibraryCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineFragmentShadingRateEnumStateCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureGeometryMotionTrianglesDataNV;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureMotionInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkCopyCommandTransformInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageCompressionControlEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageCompressionPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageCompressionControlFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevice4444FormatsFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFaultFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkMutableDescriptorTypeCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDrmPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceAddressBindingCallbackDataEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAddressBindingReportFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthClipControlFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportDepthClipControlCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryZirconHandleInfoFUCHSIA;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkFrameBoundaryEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFrameBoundaryFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkMultisampledRenderToSingleSampledInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSubpassResolvePerformanceQueryEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceColorWriteEnableFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineColorWriteCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeProfileRgbConversionInfoVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeRgbConversionCapabilitiesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkVideoEncodeSessionRgbConversionCreateInfoVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewMinLodCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageViewMinLodFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiDrawFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiDrawPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderTileImageFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderTileImagePropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureTrianglesOpacityMicromapEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpacityMicromapPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureTrianglesDisplacementMicromapNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDisplacementMicromapFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDisplacementMicromapPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerBorderColorComponentMappingCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderCorePropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDeviceQueueShaderCoreControlCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_DISPATCH_PARAMETERS_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSchedulingControlsPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewSlicedCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRenderPassStripedFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRenderPassStripedPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassStripeBeginInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassStripeSubmitInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassFragmentDensityMapOffsetEndInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkComputePipelineIndirectBufferInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureGeometryLinearSweptSpheresDataNV;
                break;
            }
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV: {
                next_struct_generator = GenerateExtensionStruct_VkAccelerationStructureGeometrySpheresDataNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLinearColorAttachmentFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkImageViewSampleWeightCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageProcessingFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageProcessingPropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceNestedCommandBufferFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceNestedCommandBufferPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkExternalMemoryAcquireUnmodifiedEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassCreationControlEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassCreationFeedbackCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassSubpassFeedbackCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG: {
                next_struct_generator = GenerateExtensionStruct_VkDirectDriverLoadingListLUNARG;
                break;
            }
            case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDescriptorGetTensorInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkExternalMemoryTensorCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkFrameBoundaryTensorsARM;
                break;
            }
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkMemoryDedicatedAllocateInfoTensorARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTensorFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTensorPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorDependencyInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorDescriptionARM;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorFormatPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorMemoryBarrierARM;
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkWriteDescriptorSetTensorARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineShaderStageModuleIdentifierCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkOpticalFlowImageFormatInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkOpticalFlowSessionCreatePrivateDataInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpticalFlowFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceOpticalFlowPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLegacyDitheringFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkAndroidHardwareBufferFormatResolvePropertiesANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAntiLagFeaturesAMD;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderObjectFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderObjectPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTilePropertiesFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC: {
                next_struct_generator = GenerateExtensionStruct_VkAmigoProfilingSubmitInfoSEC;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAmigoProfilingFeaturesSEC;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeVectorFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeVectorPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkLayerSettingsCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV: {
                next_struct_generator = GenerateExtensionStruct_VkLatencySubmissionPresentIdNV;
                break;
            }
            case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkLatencySurfaceCapabilitiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainLatencyCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineCompilerControlCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineIdentifierCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineShaderModuleCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphProcessingEngineCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDataGraphFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePerStageDescriptorSetFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageProcessing2FeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageProcessing2PropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerBlockMatchWindowCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkBlitImageCubicWeightsInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCubicWeightsFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerCubicWeightsCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCubicClampFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceLayeredDriverPropertiesMSFT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkTileMemoryBindInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkTileMemoryRequirementsQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkTileMemorySizeInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMemoryDecompressionFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMemoryDecompressionPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDisplayModeStereoPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkDisplaySurfaceStereoCreateInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRawAccessChainsFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_EXPLICIT_TILING_FORMAT_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorExplicitTilingFormatPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_TENSOR_ROLLING_BACKING_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkTensorRollingBackingCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderFloat8FeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingValidationFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPartitionedAccelerationStructureFlagsNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV: {
                next_struct_generator = GenerateExtensionStruct_VkWriteDescriptorSetPartitionedAccelerationStructureNV;
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkGeneratedCommandsPipelineInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkGeneratedCommandsShaderInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA: {
                next_struct_generator = GenerateExtensionStruct_VkImageAlignmentControlCreateInfoMESA;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageAlignmentControlFeaturesMESA;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceImageAlignmentControlPropertiesMESA;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePushConstantBankFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_CONSTANT_BANK_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePushConstantBankPropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PUSH_CONSTANT_BANK_INFO_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPushConstantBankInfoNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDepthClampControlFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineViewportDepthClampControlCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkHdrVividDynamicMetadataHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceHdrVividFeaturesHUAWEI;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrix2FeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrix2PropertiesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkImportMemoryMetalHandleInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkRenderPassPerformanceCountersByRegionBeginInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFormatPackFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePresentMeteringFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV: {
                next_struct_generator = GenerateExtensionStruct_VkSetPresentConfigNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SWAPCHAIN_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_SWAPCHAIN_FLAGS_SURFACE_CAPABILITIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkSwapchainFlagsSurfaceCapabilitiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShader64BitIndexingFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkCustomResolveCreateInfoEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCustomResolveFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineBuiltinModelCreateInfoQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDataGraphModelFeaturesQCOM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_OPTICAL_FLOW_IMAGE_FORMAT_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphOpticalFlowImageFormatInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineOpticalFlowCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_OPTICAL_FLOW_DISPATCH_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineOpticalFlowDispatchInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_IMAGE_LAYOUT_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineResourceInfoImageLayoutARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SINGLE_NODE_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineSingleNodeCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_OPTICAL_FLOW_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderLongVectorFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_LONG_VECTOR_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderLongVectorPropertiesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_OCCUPANCY_PRIORITY_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_PARTITIONED_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OCP_MICROSCALING_TYPES_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MIXED_FLOAT_DOT_PRODUCT_FEATURES_VALVE: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_THROTTLE_HINT_FEATURES_SEC: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceThrottleHintFeaturesSEC;
                break;
            }
            case VK_STRUCTURE_TYPE_THROTTLE_HINT_SUBMIT_INFO_SEC: {
                next_struct_generator = GenerateExtensionStruct_VkThrottleHintSubmitInfoSEC;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_NEURAL_STATISTICS_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineNeuralStatisticsCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_NEURAL_STATISTICS_CREATE_INFO_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_NEURAL_ACCELERATOR_STATISTICS_FEATURES_ARM: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_RESTART_INDEX_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_DECODE_VECTOR_FEATURES_NV: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAccelerationStructureFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceAccelerationStructurePropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkWriteDescriptorSetAccelerationStructureKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingPipelineFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayTracingPipelinePropertiesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceRayQueryFeaturesKHR;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMeshShaderFeaturesEXT;
                break;
            }
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT: {
                next_struct_generator = GenerateExtensionStruct_VkPhysicalDeviceMeshShaderPropertiesEXT;
                break;
            }
            default: {
                break;
            }
        }
        if (next_struct_generator != nullptr) {
            next_var_name = next_struct_generator(out, struct_info, pnext_meta_data, consumer);
        }
    }
    return next_var_name;
}


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
