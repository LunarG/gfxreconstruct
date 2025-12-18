/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "encode/custom_vulkan_struct_encoders.h"
#include "encode/struct_pointer_encoder.h"
#include "graphics/vulkan_resources_util.h"
#include "util/logging.h"

#include <cassert>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeStruct(ParameterEncoder* encoder, VkDescriptorType type, const VkDescriptorImageInfo& value)
{
    // Conditional encoding for sampler handle based on descriptor type.
    if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
    {
        // TODO: This should be ignored if the descriptor set layout was created with an immutable sampler.
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::SamplerWrapper>(value.sampler);
    }
    else
    {
        // The sampler handle should be ignored by the driver and may not be a valid handle.
        // A value will still be encoded for the handle, but it will be the current handle value cast to an
        // integer type instead of the unique handle ID retrieved from the handle wrapper.
        encoder->EncodeHandleIdValue(format::ToHandleId(value.sampler));
    }

    // Conditional encoding for image view handle based on descriptor type.
    if (type != VK_DESCRIPTOR_TYPE_SAMPLER)
    {
        encoder->EncodeVulkanHandleValue<vulkan_wrappers::ImageViewWrapper>(value.imageView);
    }
    else
    {
        // The image view handle should be ignored by the driver and may not be a valid handle.
        // A value will still be encoded for the handle, but it will be the current handle value cast to an
        // integer type instead of the unique handle ID retrieved from the handle wrapper.
        encoder->EncodeHandleIdValue(format::ToHandleId(value.imageView));
    }

    encoder->EncodeEnumValue(value.imageLayout);
}

void EncodeStruct(ParameterEncoder* encoder, const VkClearColorValue& value)
{
    encoder->EncodeUInt32Array(value.uint32, 4);
}

void EncodeStruct(ParameterEncoder* encoder, const VkClearValue& value)
{
    // VkClearColorValue is used because it is the larger of the two union members.
    EncodeStruct(encoder, value.color);
}

void EncodeStruct(ParameterEncoder* encoder, const VkPipelineExecutableStatisticValueKHR& value)
{
    encoder->EncodeUInt64Value(value.u64);
}

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceOrHostAddressKHR& value)
{
    encoder->EncodeUInt64Value(value.deviceAddress);
}

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceOrHostAddressConstKHR& value)
{
    encoder->EncodeUInt64Value(value.deviceAddress);
}

void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureMotionInstanceNV& value)
{
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeFlagsValue(value.flags);

    switch (value.type)
    {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV:
            EncodeStruct(encoder, value.data.staticInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV:
            EncodeStruct(encoder, value.data.matrixMotionInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV:
            EncodeStruct(encoder, value.data.srtMotionInstance);
            break;
        default:
            break;
    }
}

// Encodes both VkWriteDescriptorSet and VkDescriptorImageInfo based on descriptor type.
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSet& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorSetWrapper>(value.dstSet);
    encoder->EncodeUInt32Value(value.dstBinding);
    encoder->EncodeUInt32Value(value.dstArrayElement);
    encoder->EncodeUInt32Value(value.descriptorCount);
    encoder->EncodeEnumValue(value.descriptorType);

    bool omit_image_data        = true;
    bool omit_buffer_data       = true;
    bool omit_texel_buffer_data = true;

    switch (value.descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            omit_image_data = false;
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            omit_buffer_data = false;
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            omit_texel_buffer_data = false;
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            // TODO
            break;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            // Handles are encoded in the VkWriteDescriptorSetInlineUniformBlock structure in the pNext chain
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            // Handles are encoded in the VkWriteDescriptorSetAccelerationStructureKHR structure in the pNext chain
            break;
        default:
            GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
            break;
    }

    encoder->EncodeStructArrayPreamble(value.pImageInfo, value.descriptorCount, omit_image_data);
    if (!omit_image_data && (value.pImageInfo != nullptr) && (value.descriptorCount > 0))
    {
        for (size_t i = 0; i < value.descriptorCount; ++i)
        {
            EncodeStruct(encoder, value.descriptorType, value.pImageInfo[i]);
        }
    }

    EncodeStructArray(encoder, value.pBufferInfo, value.descriptorCount, omit_buffer_data);
    encoder->EncodeVulkanHandleArray<vulkan_wrappers::BufferViewWrapper>(
        value.pTexelBufferView, value.descriptorCount, omit_texel_buffer_data);
}

// Encodes the VkPerformanceValueINTEL::data union based on the value of VkPerformanceValueINTEL::type.
void EncodeStruct(ParameterEncoder* encoder, const VkPerformanceValueINTEL& value)
{
    encoder->EncodeEnumValue(value.type);

    if (value.type == VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL)
    {
        encoder->EncodeString(value.data.valueString);
    }
    else
    {
        encoder->EncodeUInt64Value(value.data.value64);
    }
}

// Encodes the VkAccelerationStructureGeometryKHR::geometry union based on the value of geometryType
void EncodeStruct(ParameterEncoder* encoder, const VkAccelerationStructureGeometryKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.geometryType);
    switch (value.geometryType)
    {
        case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            EncodeStruct(encoder, value.geometry.triangles);
            break;
        case VK_GEOMETRY_TYPE_AABBS_KHR:
            EncodeStruct(encoder, value.geometry.aabbs);
            break;
        case VK_GEOMETRY_TYPE_INSTANCES_KHR:
            EncodeStruct(encoder, value.geometry.instances);
            break;
        default:
            break;
    }
    encoder->EncodeFlagsValue(value.flags);
}

// The WIN32 SID structure has a variable size, so will be encoded as an array of bytes instead of a struct.
static void pack_sid_struct(const SID* sid, std::vector<uint8_t>* buffer)
{
    assert((sid != nullptr) && (buffer != nullptr));

    const uint8_t* sub_authority      = reinterpret_cast<const uint8_t*>(sid->SubAuthority);
    size_t         sub_authority_size = sid->SubAuthorityCount * sizeof(uint32_t);

    // sizeof(SID) already includes the size of one of the SidAuthority elements,
    // so we can subtract 4 bytes from sid_authority_size.
    buffer->reserve(sizeof(SID) + (sub_authority_size - sizeof(uint32_t)));

    buffer->push_back(sid->Revision);
    buffer->push_back(sid->SubAuthorityCount);
    buffer->insert(buffer->end(), sid->IdentifierAuthority.Value, sid->IdentifierAuthority.Value + 6);
    buffer->insert(buffer->end(), sub_authority, sub_authority + sub_authority_size);
}

void EncodeStruct(ParameterEncoder* encoder, const ACL& value)
{
    encoder->EncodeUInt8Value(value.AclRevision);
    encoder->EncodeUInt8Value(value.Sbz1);
    encoder->EncodeUInt16Value(value.AclSize);
    encoder->EncodeUInt16Value(value.AceCount);
    encoder->EncodeUInt16Value(value.Sbz2);
}

void EncodeStruct(ParameterEncoder* encoder, const SECURITY_DESCRIPTOR& value)
{
    encoder->EncodeUInt8Value(value.Revision);
    encoder->EncodeUInt8Value(value.Sbz1);
    encoder->EncodeUInt16Value(value.Control);

    // The SID structure has a variable size, so will be packed into an array of bytes.
    std::vector<uint8_t> buffer;

    if (value.Owner != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Owner), &buffer);
        encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        encoder->EncodeUInt8Array(nullptr, 0);
    }

    buffer.clear();

    if (value.Group != nullptr)
    {
        pack_sid_struct(reinterpret_cast<SID*>(value.Group), &buffer);
        encoder->EncodeUInt8Array(buffer.data(), buffer.size());
    }
    else
    {
        encoder->EncodeUInt8Array(nullptr, 0);
    }

    EncodeStructPtr(encoder, value.Sacl);
    EncodeStructPtr(encoder, value.Dacl);
}

void EncodeStruct(ParameterEncoder* encoder, const SECURITY_ATTRIBUTES& value)
{
    encoder->EncodeUInt32Value(value.nLength);
    EncodeStructPtr(encoder, reinterpret_cast<SECURITY_DESCRIPTOR*>(value.lpSecurityDescriptor));
    encoder->EncodeInt32Value(value.bInheritHandle);
}

void EncodeStruct(ParameterEncoder* encoder, const VkPushDescriptorSetWithTemplateInfoKHR& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(value.descriptorUpdateTemplate);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineLayoutWrapper>(value.layout);
    encoder->EncodeUInt32Value(value.set);
}

void EncodeStruct(ParameterEncoder* encoder, const VkIndirectExecutionSetCreateInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    switch (value.type)
    {
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT:
            EncodeStructPtr(encoder, value.info.pPipelineInfo);
            break;
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT:
            EncodeStructPtr(encoder, value.info.pShaderInfo);
            break;
        default:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkIndirectCommandsLayoutTokenEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    switch (value.type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT:
            EncodeStructPtr(encoder, value.data.pPushConstant);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            EncodeStructPtr(encoder, value.data.pVertexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            EncodeStructPtr(encoder, value.data.pIndexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            EncodeStructPtr(encoder, value.data.pExecutionSet);
            break;
        default:
            break;
    }
    encoder->EncodeUInt32Value(value.offset);
}

void EncodeStruct(ParameterEncoder* encoder, const VkCopyMemoryToImageInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::ImageWrapper>(value.dstImage);
    encoder->EncodeEnumValue(value.dstImageLayout);
    encoder->EncodeUInt32Value(value.regionCount);

    // Manually encode the VkMemoryToImageCopy array as it requires extra info about the destination image format to
    // properly encode the host pointer
    encoder->EncodeStructArrayPreamble(value.pRegions, value.regionCount);
    if ((value.pRegions != nullptr) && (value.regionCount > 0))
    {
        const auto* image_info = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(value.dstImage);
        for (size_t i = 0; i < value.regionCount; ++i)
        {
            const auto& region = value.pRegions[i];
            VkDeviceSize host_size =
                graphics::GetBufferSizeFromCopyImage(region, image_info->array_layers, image_info->format);

            encoder->EncodeEnumValue(region.sType);
            EncodePNextStruct(encoder, region.pNext);
            encoder->EncodeVoidArray(region.pHostPointer, host_size);
            encoder->EncodeUInt32Value(region.memoryRowLength);
            encoder->EncodeUInt32Value(region.memoryImageHeight);
            EncodeStruct(encoder, region.imageSubresource);
            EncodeStruct(encoder, region.imageOffset);
            EncodeStruct(encoder, region.imageExtent);
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkCopyImageToMemoryInfo& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeFlagsValue(value.flags);
    encoder->EncodeVulkanHandleValue<vulkan_wrappers::ImageWrapper>(value.srcImage);
    encoder->EncodeEnumValue(value.srcImageLayout);
    encoder->EncodeUInt32Value(value.regionCount);

    // Manually encode the VkImageToMemoryCopy array as it requires extra info about the source image format to
    // properly encode the host pointer
    encoder->EncodeStructArrayPreamble(value.pRegions, value.regionCount);
    if ((value.pRegions != nullptr) && (value.regionCount > 0))
    {
        const auto* image_info = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(value.srcImage);
        for (size_t i = 0; i < value.regionCount; ++i)
        {
            const auto&  region = value.pRegions[i];
            VkDeviceSize host_size =
                graphics::GetBufferSizeFromCopyImage(region, image_info->array_layers, image_info->format);

            encoder->EncodeEnumValue(region.sType);
            EncodePNextStruct(encoder, region.pNext);
            encoder->EncodeVoidArray(region.pHostPointer, host_size);
            encoder->EncodeUInt32Value(region.memoryRowLength);
            encoder->EncodeUInt32Value(region.memoryImageHeight);
            EncodeStruct(encoder, region.imageSubresource);
            EncodeStruct(encoder, region.imageOffset);
            EncodeStruct(encoder, region.imageExtent);
        }
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkLayerSettingEXT& value)
{
    encoder->EncodeString(value.pLayerName);
    encoder->EncodeString(value.pSettingName);
    encoder->EncodeEnumValue(value.type);
    encoder->EncodeUInt32Value(value.valueCount);

    switch (value.type)
    {
        case VK_LAYER_SETTING_TYPE_BOOL32_EXT:
            encoder->EncodeUInt32Array(static_cast<const VkBool32*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_INT32_EXT:
            encoder->EncodeInt32Array(static_cast<const int32_t*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_INT64_EXT:
            encoder->EncodeInt64Array(static_cast<const int64_t*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_UINT32_EXT:
            encoder->EncodeUInt32Array(static_cast<const uint32_t*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_UINT64_EXT:
            encoder->EncodeUInt64Array(static_cast<const uint64_t*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT32_EXT:
            encoder->EncodeFloatArray(static_cast<const float*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT64_EXT:
            encoder->EncodeFloat64Array(static_cast<const double*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_STRING_EXT:
            encoder->EncodeStringArray(static_cast<const char* const*>(value.pValues), value.valueCount);
            break;
        case VK_LAYER_SETTING_TYPE_MAX_ENUM_EXT:
            break;
    }
}

void EncodeStruct(ParameterEncoder* encoder, const VkDescriptorGetInfoEXT& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeEnumValue(value.type);
    switch (value.type)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            encoder->EncodeVulkanHandlePtr<vulkan_wrappers::SamplerWrapper>(value.data.pSampler);
            break;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            encoder->EncodeStructPtrPreamble(value.data.pCombinedImageSampler);

            if (value.data.pCombinedImageSampler)
            {
                EncodeStruct(encoder, value.type, *value.data.pCombinedImageSampler);
            }
            break;
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            encoder->EncodeStructPtrPreamble(value.data.pInputAttachmentImage);

            if (value.data.pInputAttachmentImage)
            {
                EncodeStruct(encoder, value.type, *value.data.pInputAttachmentImage);
            }

            break;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            encoder->EncodeStructPtrPreamble(value.data.pSampledImage);

            if (value.data.pSampledImage)
            {
                EncodeStruct(encoder, value.type, *value.data.pSampledImage);
            }
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            encoder->EncodeStructPtrPreamble(value.data.pStorageImage);

            if (value.data.pStorageImage)
            {
                EncodeStruct(encoder, value.type, *value.data.pStorageImage);
            }
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            EncodeStructPtr(encoder, value.data.pUniformTexelBuffer);
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            EncodeStructPtr(encoder, value.data.pStorageTexelBuffer);
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            EncodeStructPtr(encoder, value.data.pUniformBuffer);
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            EncodeStructPtr(encoder, value.data.pStorageBuffer);
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            encoder->EncodeUInt64Value(value.data.accelerationStructure);
            break;
        default:
            break;
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
