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
#include "util/defines.h"
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
        encoder->EncodeHandleValue(value.sampler);
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
        encoder->EncodeHandleValue(value.imageView);
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
    encoder->EncodeVkDeviceAddressValue(value.deviceAddress);
}

void EncodeStruct(ParameterEncoder* encoder, const VkDeviceOrHostAddressConstKHR& value)
{
    encoder->EncodeVkDeviceAddressValue(value.deviceAddress);
}

// Encodes both VkWriteDescriptorSet and VkDescriptorImageInfo based on descriptor type.
void EncodeStruct(ParameterEncoder* encoder, const VkWriteDescriptorSet& value)
{
    encoder->EncodeEnumValue(value.sType);
    EncodePNextStruct(encoder, value.pNext);
    encoder->EncodeHandleValue(value.dstSet);
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
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
            // TODO
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            // TODO
            break;
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
    encoder->EncodeHandleArray(value.pTexelBufferView, value.descriptorCount, omit_texel_buffer_data);
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
