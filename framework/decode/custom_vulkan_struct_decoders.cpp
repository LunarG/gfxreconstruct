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

#include "decode/custom_vulkan_struct_decoders.h"

#include "decode/decode_allocator.h"
#include "decode/value_decoder.h"
#include "decode/vulkan_pnext_typed_node.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/logging.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

size_t DecodePNextStruct(const uint8_t* buffer, size_t buffer_size, PNextNode** pNext);

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

    wrapper->color                = DecodeAllocator::Allocate<Decoded_VkClearColorValue>();
    wrapper->color->decoded_value = &(value->color);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->color);

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

    bytes_read +=
        ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceAddress));
    wrapper->hostAddress = value->deviceAddress;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDeviceOrHostAddressConstKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                         bytes_read = 0;
    VkDeviceOrHostAddressConstKHR* value      = wrapper->decoded_value;

    bytes_read +=
        ValueDecoder::DecodeUInt64Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->deviceAddress));
    wrapper->hostAddress = value->deviceAddress;

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryDataKHR* wrapper)
{
    // TODO
    GFXRECON_LOG_ERROR("VkAccelerationStructureGeometryDataKHR is not supported");
    return 0;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureMotionInstanceNV* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                   bytes_read = 0;
    VkAccelerationStructureMotionInstanceNV* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    switch (value->type)
    {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV:
            wrapper->staticInstance = DecodeAllocator::Allocate<Decoded_VkAccelerationStructureInstanceKHR>();
            wrapper->staticInstance->decoded_value = &value->data.staticInstance;
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->staticInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV:
            wrapper->matrixMotionInstance =
                DecodeAllocator::Allocate<Decoded_VkAccelerationStructureMatrixMotionInstanceNV>();
            wrapper->matrixMotionInstance->decoded_value = &value->data.matrixMotionInstance;
            bytes_read +=
                DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->matrixMotionInstance);
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV:
            wrapper->srtMotionInstance =
                DecodeAllocator::Allocate<Decoded_VkAccelerationStructureSRTMotionInstanceNV>();
            wrapper->srtMotionInstance->decoded_value = &value->data.srtMotionInstance;
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->srtMotionInstance);
            break;
        default:
            break;
    }
    return bytes_read;
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

    wrapper->pImageInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
    bytes_read += wrapper->pImageInfo->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pImageInfo = wrapper->pImageInfo->GetPointer();

    wrapper->pBufferInfo = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorBufferInfo>>();
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

    wrapper->data                = DecodeAllocator::Allocate<Decoded_VkPerformanceValueDataINTEL>();
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

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkAccelerationStructureGeometryKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                              bytes_read = 0;
    VkAccelerationStructureGeometryKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;

    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->geometryType));

    wrapper->geometry = DecodeAllocator::Allocate<Decoded_VkAccelerationStructureGeometryDataKHR>();

    switch (value->geometryType)
    {
        case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            wrapper->geometry->triangles =
                DecodeAllocator::Allocate<Decoded_VkAccelerationStructureGeometryTrianglesDataKHR>();
            wrapper->geometry->triangles->decoded_value = &(value->geometry.triangles);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->geometry->triangles);
            break;
        case VK_GEOMETRY_TYPE_AABBS_KHR:
            wrapper->geometry->aabbs = DecodeAllocator::Allocate<Decoded_VkAccelerationStructureGeometryAabbsDataKHR>();
            wrapper->geometry->aabbs->decoded_value = &(value->geometry.aabbs);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->geometry->aabbs);
            break;
        case VK_GEOMETRY_TYPE_INSTANCES_KHR:
            wrapper->geometry->instances =
                DecodeAllocator::Allocate<Decoded_VkAccelerationStructureGeometryInstancesDataKHR>();
            wrapper->geometry->instances->decoded_value = &(value->geometry.instances);
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->geometry->instances);
            break;
        default:
            break;
    }

    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPushDescriptorSetWithTemplateInfo* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                                  bytes_read = 0;
    VkPushDescriptorSetWithTemplateInfoKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &value->sType);
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->pNext);
    bytes_read += ValueDecoder::DecodeHandleIdValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &wrapper->descriptorUpdateTemplate);
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->layout);
    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &value->set);

    if (wrapper->pNext != nullptr)
        value->pNext = wrapper->pNext->GetPointer();

    return bytes_read;
}

// The WIN32 SID structure has a variable size, so was encoded as an array of bytes instead of a struct.
static uint8_t* unpack_sid_struct(const PointerDecoder<uint8_t>& packed_value)
{
    const uint8_t* bytes = packed_value.GetPointer();

    // Allocate memory for variable length SID struct, to use for unpacking.
    // SidAuthorityCount is the second byte of the packed array.
    size_t sid_authority_size = bytes[1] * sizeof(uint32_t);

    // sizeof(SID) already includes the size of one of the SidAuthority elements,
    // so we can subtract 4 bytes from sid_authority_size.
    size_t   allocation_size = sizeof(SID) + (sid_authority_size - sizeof(uint32_t));
    uint8_t* unpacked_memory = DecodeAllocator::Allocate<uint8_t>(allocation_size);

    SID* sid               = reinterpret_cast<SID*>(unpacked_memory);
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
    value->Owner   = wrapper->Owner;

    bytes_read += wrapper->PackedGroup.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    wrapper->Group = unpack_sid_struct(wrapper->PackedOwner);
    value->Group   = wrapper->Group;

    wrapper->Sacl = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_ACL>>();
    bytes_read += wrapper->Sacl->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->Sacl = wrapper->Sacl->GetPointer();

    wrapper->Dacl = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_ACL>>();
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

    wrapper->lpSecurityDescriptor = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_SECURITY_DESCRIPTOR>>();
    bytes_read += wrapper->lpSecurityDescriptor->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->lpSecurityDescriptor = wrapper->lpSecurityDescriptor->GetPointer();

    bytes_read +=
        ValueDecoder::DecodeInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->bInheritHandle));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectExecutionSetCreateInfoEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                               bytes_read = 0;
    VkIndirectExecutionSetCreateInfoEXT* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->pNext);
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_type);

    switch (wrapper->decoded_type)
    {
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT:
            wrapper->info->pPipelineInfo = DecodeAllocator::Allocate<Decoded_VkIndirectExecutionSetPipelineInfoEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->info->pPipelineInfo);
            break;
        case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT:
            wrapper->info->pShaderInfo = DecodeAllocator::Allocate<Decoded_VkIndirectExecutionSetShaderInfoEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->info->pShaderInfo);
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkIndirectCommandsLayoutTokenEXT* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                            bytes_read = 0;
    VkIndirectCommandsLayoutTokenEXT* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->pNext);
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_type);

    switch (wrapper->decoded_type)
    {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT:
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT:
            wrapper->data->pPushConstant = DecodeAllocator::Allocate<Decoded_VkIndirectCommandsPushConstantTokenEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data->pPushConstant);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT:
            wrapper->data->pVertexBuffer = DecodeAllocator::Allocate<Decoded_VkIndirectCommandsVertexBufferTokenEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data->pVertexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT:
            wrapper->data->pIndexBuffer = DecodeAllocator::Allocate<Decoded_VkIndirectCommandsIndexBufferTokenEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data->pIndexBuffer);
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT:
            wrapper->data->pExecutionSet = DecodeAllocator::Allocate<Decoded_VkIndirectCommandsExecutionSetTokenEXT>();
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data->pExecutionSet);
            break;
        default:
            break;
    }

    bytes_read += ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->offset);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCopyMemoryToImageInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    VkCopyMemoryToImageInfo* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->dstImage));
    value->dstImage = VK_NULL_HANDLE;
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->dstImageLayout));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->regionCount));
    wrapper->pRegions = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkMemoryToImageCopy>>();
    bytes_read += wrapper->pRegions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRegions = wrapper->pRegions->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkMemoryToImageCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    VkMemoryToImageCopy* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += wrapper->pHostPointer.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHostPointer = wrapper->pHostPointer.GetPointer();
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryRowLength));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryImageHeight));
    wrapper->imageSubresource                = DecodeAllocator::Allocate<Decoded_VkImageSubresourceLayers>();
    wrapper->imageSubresource->decoded_value = &(value->imageSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageSubresource);
    wrapper->imageOffset                = DecodeAllocator::Allocate<Decoded_VkOffset3D>();
    wrapper->imageOffset->decoded_value = &(value->imageOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageOffset);
    wrapper->imageExtent                = DecodeAllocator::Allocate<Decoded_VkExtent3D>();
    wrapper->imageExtent->decoded_value = &(value->imageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageExtent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkCopyImageToMemoryInfo* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    VkCopyImageToMemoryInfo* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->flags));
    bytes_read +=
        ValueDecoder::DecodeHandleIdValue((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->srcImage));
    value->srcImage = VK_NULL_HANDLE;
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->srcImageLayout));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->regionCount));
    wrapper->pRegions = DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkImageToMemoryCopy>>();
    bytes_read += wrapper->pRegions->Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pRegions = wrapper->pRegions->GetPointer();

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkImageToMemoryCopy* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    VkImageToMemoryCopy* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &(wrapper->pNext));
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read += wrapper->pHostPointer.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
    value->pHostPointer = wrapper->pHostPointer.GetPointer();
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryRowLength));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->memoryImageHeight));
    wrapper->imageSubresource                = DecodeAllocator::Allocate<Decoded_VkImageSubresourceLayers>();
    wrapper->imageSubresource->decoded_value = &(value->imageSubresource);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageSubresource);
    wrapper->imageOffset                = DecodeAllocator::Allocate<Decoded_VkOffset3D>();
    wrapper->imageOffset->decoded_value = &(value->imageOffset);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageOffset);
    wrapper->imageExtent                = DecodeAllocator::Allocate<Decoded_VkExtent3D>();
    wrapper->imageExtent->decoded_value = &(value->imageExtent);
    bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->imageExtent);

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkLayerSettingEXT* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t             bytes_read = 0;
    VkLayerSettingEXT* value      = wrapper->decoded_value;

    bytes_read += wrapper->pLayerName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pLayerName = wrapper->pLayerName.GetPointer();
    bytes_read += wrapper->pSettingName.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->pSettingName = wrapper->pSettingName.GetPointer();
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->valueCount));

    switch (value->type)
    {
        case VK_LAYER_SETTING_TYPE_BOOL32_EXT:
        case VK_LAYER_SETTING_TYPE_UINT32_EXT:
            bytes_read += wrapper->pValues.DecodeUInt32(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_INT32_EXT:
            bytes_read += wrapper->pValues.DecodeInt32(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_INT64_EXT:
            bytes_read += wrapper->pValues.DecodeInt64(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_UINT64_EXT:
            bytes_read += wrapper->pValues.DecodeUInt64(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT32_EXT:
            bytes_read += wrapper->pValues.DecodeFloat(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT64_EXT:
            bytes_read += wrapper->pValues.DecodeDouble(buffer + bytes_read, buffer_size - bytes_read);
            value->pValues = static_cast<const void*>(wrapper->pValues.GetPointer());
            break;
        case VK_LAYER_SETTING_TYPE_STRING_EXT:
        {
            uint32_t attrib;
            ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &attrib);

            // VkLayerSettingEXT was incorrectly encoded for strings before 23f420bd as void* but also decoded
            // that way (correctly for the encoding).  Decoding captures from before 23f420bd will potentially
            // crash, so detect captures encoded the incorrect way and attempt to handle them gracefully.

            bool is_string = (attrib & format::PointerAttributes::kIsString) == format::PointerAttributes::kIsString;

            if (is_string)
            {
                bytes_read += wrapper->string_decoder.Decode(buffer + bytes_read, buffer_size - bytes_read);
                value->pValues = static_cast<const void*>(wrapper->string_decoder.GetPointer());
            }
            else
            {
                GFXRECON_LOG_INFO("Detected and discarding VkLayerSettingEXT string value incorrectly encoded as "
                                  "void*. Settings will not be passed downstream. See commit 23f420bd.");
                // XXX Note that it is unlikely the encoded buffer (1 uint8_t) will contain the captured layer settings
                // settings.  Decode a uint8_t buffer to move past the data and discard the results.
                bytes_read += wrapper->pValues.DecodeVoid((buffer + bytes_read), (buffer_size - bytes_read));
                value->valueCount = 0;
            }
            break;
        }
        case VK_LAYER_SETTING_TYPE_MAX_ENUM_EXT:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorDataEXT* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t               bytes_read = 0;
    VkDescriptorDataEXT* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeUInt64Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->accelerationStructure));

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkDescriptorGetInfoEXT* wrapper)
{
    GFXRECON_ASSERT((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                  bytes_read = 0;
    VkDescriptorGetInfoEXT* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));
    bytes_read += DecodePNextStruct((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->pNext);
    value->pNext = wrapper->pNext ? wrapper->pNext->GetPointer() : nullptr;
    bytes_read +=
        ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &wrapper->decoded_type);
    value->type = wrapper->decoded_type;

    wrapper->data                = DecodeAllocator::Allocate<Decoded_VkDescriptorDataEXT>();
    wrapper->data->decoded_value = &(value->data);

    switch (wrapper->decoded_type)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            bytes_read += wrapper->data->pSampler.Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pSampler = wrapper->data->pSampler.GetHandlePointer();
            break;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            wrapper->data->pCombinedImageSampler =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
            bytes_read +=
                wrapper->data->pCombinedImageSampler->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pCombinedImageSampler = wrapper->data->pCombinedImageSampler->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            wrapper->data->pInputAttachmentImage =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
            bytes_read +=
                wrapper->data->pInputAttachmentImage->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pInputAttachmentImage = wrapper->data->pInputAttachmentImage->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            wrapper->data->pSampledImage =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
            bytes_read += wrapper->data->pSampledImage->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pSampledImage = wrapper->data->pSampledImage->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            wrapper->data->pStorageImage =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorImageInfo>>();
            bytes_read += wrapper->data->pStorageImage->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pStorageImage = wrapper->data->pStorageImage->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            wrapper->data->pUniformTexelBuffer =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorAddressInfoEXT>>();
            bytes_read += wrapper->data->pUniformTexelBuffer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pUniformTexelBuffer = wrapper->data->pUniformTexelBuffer->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            wrapper->data->pStorageTexelBuffer =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorAddressInfoEXT>>();
            bytes_read += wrapper->data->pStorageTexelBuffer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pStorageTexelBuffer = wrapper->data->pStorageTexelBuffer->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            wrapper->data->pUniformBuffer =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorAddressInfoEXT>>();
            bytes_read += wrapper->data->pUniformBuffer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pUniformBuffer = wrapper->data->pUniformBuffer->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            wrapper->data->pStorageBuffer =
                DecodeAllocator::Allocate<StructPointerDecoder<Decoded_VkDescriptorAddressInfoEXT>>();
            bytes_read += wrapper->data->pStorageBuffer->Decode((buffer + bytes_read), (buffer_size - bytes_read));
            value->data.pStorageBuffer = wrapper->data->pStorageBuffer->GetPointer();
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), wrapper->data);
            value->data.accelerationStructure = wrapper->data->decoded_value->accelerationStructure;
            break;
        default:
            break;
    }

    return bytes_read;
}

size_t DecodeStruct(const uint8_t* buffer, size_t buffer_size, Decoded_VkPipelineCreateInfoKHR* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->decoded_value != nullptr));

    size_t                   bytes_read = 0;
    VkPipelineCreateInfoKHR* value      = wrapper->decoded_value;

    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->sType));

    // Peek at the pointer attribute mask to make sure we have a non-NULL value that can be decoded.
    const uint32_t attrib = *(reinterpret_cast<const uint32_t*>(buffer + bytes_read));
    // According to the Vulkan specification, pNext cannot be NULL for this structure
    assert((attrib & format::PointerAttributes::kIsNull) != format::PointerAttributes::kIsNull);

    // Offset to VkStructureType, after the pointer encoding preamble.
    size_t stype_offset = sizeof(attrib);
    if ((attrib & format::PointerAttributes::kHasAddress) == format::PointerAttributes::kHasAddress)
    {
        stype_offset += sizeof(format::AddressEncodeType);
    }

    const VkStructureType* sType = reinterpret_cast<const VkStructureType*>(buffer + bytes_read + stype_offset);
    switch (*sType)
    {
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            wrapper->pNext = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkGraphicsPipelineCreateInfo>>();
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            wrapper->pNext = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkRayTracingPipelineCreateInfoKHR>>();
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            wrapper->pNext = DecodeAllocator::Allocate<PNextTypedNode<Decoded_VkComputePipelineCreateInfo>>();
            break;
        default:
        {
            GFXRECON_LOG_ERROR("Unrecognized VkPipelineCreateInfoKHR::pNext structure type: %d", *sType);
            break;
        }
    }

    if (wrapper->pNext != nullptr)
    {
        bytes_read += wrapper->pNext->Decode((buffer + bytes_read), (buffer_size - bytes_read));
        value->pNext = wrapper->pNext->GetPointer();
    }
    else
    {
        value->pNext = nullptr;
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
