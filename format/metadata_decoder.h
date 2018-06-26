/*
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef BRIMSTONE_FORMAT_METADATA_DECODE_H
#define BRIMSTONE_FORMAT_METADATA_DECODE_H

#include "format/metadata.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

struct Decoded_CreateDeviceMetadata
{
    using struct_type = CreateDeviceMetadata;

    CreateDeviceMetadata* value{ nullptr };

    PointerDecoder<uint8_t>                    unique_id;
    StringDecoder                              enabled_instance_extensions;
    StringDecoder                              enabled_device_extensions;
    StructPointerDecoder<Decoded_VkMemoryType> memory_types;
    StructPointerDecoder<Decoded_VkMemoryHeap> memory_heaps;
};

struct Decoded_AllocateMemoryMetadata
{
    using struct_type = AllocateMemoryMetadata;

    AllocateMemoryMetadata* value{ nullptr };
};

size_t DecodeCreateDeviceMetadata(const uint8_t* buffer, size_t buffer_size, Decoded_CreateDeviceMetadata* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));
    size_t                bytes_read = 0;
    CreateDeviceMetadata* value      = wrapper->value;
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->struct_id));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->struct_version));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->api_version));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->vendor_id));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->hardware_id));
    bytes_read += ValueDecoder::DecodeEnumValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->type));
    wrapper->unique_id.SetExternalMemory(value->unique_id, VK_UUID_SIZE);
    bytes_read += wrapper->unique_id.DecodeUInt8((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkBool32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->has_instance_extensions));
    bytes_read += wrapper->enabled_instance_extensions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->enabled_instance_extensions = wrapper->enabled_instance_extensions.GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->has_device_extensions));
    bytes_read += wrapper->enabled_device_extensions.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    value->enabled_device_extensions = wrapper->enabled_device_extensions.GetPointer();
    bytes_read += ValueDecoder::DecodeVkBool32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->only_device_present));
    bytes_read += ValueDecoder::DecodeVkBool32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->use_device_group));
    bytes_read += ValueDecoder::DecodeUInt32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->device_group_index));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->devices_in_group));
    bytes_read += ValueDecoder::DecodeVkBool32Value(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->group_supports_subset_alloc));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->cummulative_queue_flags));
    bytes_read +=
        ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->unique_queue_flags));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->num_memory_types));
    wrapper->memory_types.SetExternalMemory(value->memory_types, value->num_memory_types);
    bytes_read += wrapper->memory_types.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->num_memory_heaps));
    wrapper->memory_heaps.SetExternalMemory(value->memory_heaps, value->num_memory_heaps);
    bytes_read += wrapper->memory_heaps.Decode((buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->device_local_mem_size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->host_visible_mem_size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->host_coherent_mem_size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->host_cached_mem_size));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->protected_mem_size));
    return bytes_read;
}

size_t DecodeAllocateMemoryMetadata(const uint8_t* buffer, size_t buffer_size, Decoded_AllocateMemoryMetadata* wrapper)
{
    assert((wrapper != nullptr) && (wrapper->value != nullptr));
    size_t                  bytes_read = 0;
    AllocateMemoryMetadata* value      = wrapper->value;
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->struct_id));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->struct_version));
    bytes_read +=
        ValueDecoder::DecodeUInt32Value((buffer + bytes_read), (buffer_size - bytes_read), &(value->alloc_index));
    bytes_read += ValueDecoder::DecodeVkDeviceSizeValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->requested_size));
    bytes_read +=
        ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->property_flags));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->unique_property_flags));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->largest_of_property_flags));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->largest_of_remaining_property_flags));
    bytes_read +=
        ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->heap_flags));
    bytes_read +=
        ValueDecoder::DecodeFlagsValue((buffer + bytes_read), (buffer_size - bytes_read), &(value->unique_heap_flags));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->largest_of_heap_flags));
    bytes_read += ValueDecoder::DecodeFlagsValue(
        (buffer + bytes_read), (buffer_size - bytes_read), &(value->largest_of_remaining_heap_flags));
    return bytes_read;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_METADATA_DECODE_H