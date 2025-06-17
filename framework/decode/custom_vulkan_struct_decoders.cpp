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
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/defines.h"
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
