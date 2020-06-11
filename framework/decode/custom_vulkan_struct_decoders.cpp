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

#include "decode/custom_vulkan_struct_decoders.h"

#include "decode/value_decoder.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, std::unique_ptr<PNextNode>* pNext);

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearColorValue* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t             bytes_read = 0;
    VkClearColorValue* value      = wrapper->decoded_value;

    wrapper->uint32.SetExternalMemory(value->uint32, 4);
    bytes_read += wrapper->uint32.DecodeUInt32((buffer + bytes_read), (buffer_size - bytes_read));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkClearValue* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t        bytes_read = 0;
    VkClearValue* value      = wrapper->decoded_value;

    wrapper->color                = std::make_unique<Decoded_VkClearColorValue>();
    wrapper->color->decoded_value = &(value->color);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->color.get());

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineExecutableStatisticValueKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                 bytes_read = 0;
    VkPipelineExecutableStatisticValueKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->u64));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                    bytes_read = 0;
    VkDeviceOrHostAddressKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceAddress));
    wrapper->hostAddress = value->deviceAddress;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressConstKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    VkDeviceOrHostAddressConstKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceAddress));
    wrapper->hostAddress = value->deviceAddress;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryDataKHR* wrapper)
{
    // TODO
    GFXRECON_LOG_ERROR("VkAccelerationStructureGeometryDataKHR is not supported");
    return 0;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorImageInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                 bytes_read = 0;
    VkDescriptorImageInfo* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->sampler));
    value->sampler = VK_NULL_HANDLE;
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->imageView));
    value->imageView = VK_NULL_HANDLE;
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->imageLayout));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkWriteDescriptorSet* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                bytes_read = 0;
    VkWriteDescriptorSet* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;

    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstSet));
    value->dstSet = VK_NULL_HANDLE;
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstBinding));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstArrayElement));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorCount));
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->descriptorType));

    wrapper->pImageInfo = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
    bytes_read += wrapper->pImageInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageInfo = wrapper->pImageInfo->GetPointer();

    wrapper->pBufferInfo = std::make_unique<StructPointerDecoder<Decoded_VkDescriptorBufferInfo>>();
    bytes_read += wrapper->pBufferInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pBufferInfo = wrapper->pBufferInfo->GetPointer();

    bytes_read += wrapper->pTexelBufferView.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pTexelBufferView = wrapper->pTexelBufferView.GetHandlePointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPerformanceValueINTEL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    VkPerformanceValueINTEL* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));

    wrapper->data                = std::make_unique<Decoded_VkPerformanceValueDataINTEL>();
    wrapper->data->decoded_value = &(value->data);

    if (value->type == VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL)
    {
        bytes_read += wrapper->data->valueString.Decode((buffer + bytes_read), (buffer_size - bytes_read));
        value->data.valueString = wrapper->data->valueString.GetPointer();
    }
    else
    {
        bytes_read +=
            ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->data.value64));
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t*                                       parameter_buffer,
                    size_t                                               buffer_size,
                    Decoded_VkAccelerationStructureBuildGeometryInfoKHR* wrapper)
{
    // TODO
    GFXRECON_LOG_ERROR("VkAccelerationStructureBuildGeometryInfoKHR is not supported");
    return 0;
}

// The WIN32 SID structure has a variable size, so was encoded as an array of bytes instead of a struct.
static std::unique_ptr<uint8_t[]> unpack_sid_struct(const PointerDecoder<uint8_t>& packed_value)
{
    const uint8_t* bytes = packed_value.GetPointer();

    // Allocate memory for variable length SID struct, to use for unpacking.
    // SidAuthorityCount is the second byte of the packed array.
    size_t sid_authority_size = bytes[1] * sizeof(uint32_t);

    // sizeof(SID) already includes the size of one of the SidAuthority elements,
    // so we can subtract 4 bytes from sid_authority_size.
    size_t                     allocation_size = sizeof(SID) + (sid_authority_size - sizeof(uint32_t));
    std::unique_ptr<uint8_t[]> unpacked_memory = std::make_unique<uint8_t[]>(allocation_size);

    SID* sid               = reinterpret_cast<SID*>(unpacked_memory.get());
    sid->Revision          = bytes[0];
    sid->SubAuthorityCount = bytes[1];
    memcpy(sid->IdentifierAuthority.Value, &bytes[2], 6);
    memcpy(sid->SubAuthority, &bytes[8], sid_authority_size);

    return unpacked_memory;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_ACL* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t bytes_read = 0;
    ACL*   value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AclRevision));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz1));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AclSize));
    bytes_read +=
        ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->AceCount));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz2));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_DESCRIPTOR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    SECURITY_DESCRIPTOR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Revision));
    bytes_read += ValueDecoder::DecodeUInt8Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Sbz1));
    bytes_read += ValueDecoder::DecodeUInt16Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->Control));

    // The SID structure has a variable size, so has been packed into an array of bytes.
    bytes_read += wrapper->PackedOwner.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->Owner = unpack_sid_struct(wrapper->PackedOwner);
    value->Owner   = wrapper->Owner.get();

    bytes_read += wrapper->PackedGroup.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->Group = unpack_sid_struct(wrapper->PackedOwner);
    value->Group   = wrapper->Group.get();

    wrapper->Sacl = std::make_unique<StructPointerDecoder<Decoded_ACL>>();
    bytes_read += wrapper->Sacl->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Sacl = wrapper->Sacl->GetPointer();

    wrapper->Dacl = std::make_unique<StructPointerDecoder<Decoded_ACL>>();
    bytes_read += wrapper->Dacl->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Dacl = wrapper->Dacl->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_SECURITY_ATTRIBUTES* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    SECURITY_ATTRIBUTES* value      = wrapper->decoded_value;

    uint32_t nLength = 0;
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &nLength);
    value->nLength = nLength;

    wrapper->lpSecurityDescriptor = std::make_unique<StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>>();
    bytes_read += wrapper->lpSecurityDescriptor->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->lpSecurityDescriptor = wrapper->lpSecurityDescriptor->GetPointer();

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bInheritHandle));

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
