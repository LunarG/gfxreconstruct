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

#ifndef BRIMSTONE_FORMAT_METADATA_ENCODE_H
#define BRIMSTONE_FORMAT_METADATA_ENCODE_H

#include "format/metadata.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

size_t EncodeCreateDeviceMetadata(ParameterEncoder* encoder, const CreateDeviceMetadata* create_device_metadata)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(create_device_metadata->struct_id);
    result += encoder->EncodeUInt32Value(create_device_metadata->struct_version);
    result += encoder->EncodeUInt32Value(create_device_metadata->api_version);
    result += encoder->EncodeUInt32Value(create_device_metadata->vendor_id);
    result += encoder->EncodeUInt32Value(create_device_metadata->hardware_id);
    result += encoder->EncodeEnumValue(create_device_metadata->type);
    result += encoder->EncodeUInt8Array(create_device_metadata->unique_id, VK_UUID_SIZE);
    result += encoder->EncodeVkBool32Value(create_device_metadata->has_instance_extensions);
    result += encoder->EncodeString(create_device_metadata->enabled_instance_extensions);
    result += encoder->EncodeVkBool32Value(create_device_metadata->has_device_extensions);
    result += encoder->EncodeString(create_device_metadata->enabled_device_extensions);
    result += encoder->EncodeVkBool32Value(create_device_metadata->only_device_present);
    result += encoder->EncodeVkBool32Value(create_device_metadata->use_device_group);
    result += encoder->EncodeUInt32Value(create_device_metadata->device_group_index);
    result += encoder->EncodeUInt32Value(create_device_metadata->devices_in_group);
    result += encoder->EncodeVkBool32Value(create_device_metadata->group_supports_subset_alloc);
    result += encoder->EncodeFlagsValue(create_device_metadata->cummulative_queue_flags);
    result += encoder->EncodeFlagsValue(create_device_metadata->unique_queue_flags);
    result += encoder->EncodeUInt32Value(create_device_metadata->num_memory_types);
    result +=
        encode_struct_array(encoder, create_device_metadata->memory_types, create_device_metadata->num_memory_types);
    result += encoder->EncodeUInt32Value(create_device_metadata->num_memory_heaps);
    result +=
        encode_struct_array(encoder, create_device_metadata->memory_heaps, create_device_metadata->num_memory_heaps);
    result += encoder->EncodeVkDeviceSizeValue(create_device_metadata->device_local_mem_size);
    result += encoder->EncodeVkDeviceSizeValue(create_device_metadata->host_visible_mem_size);
    result += encoder->EncodeVkDeviceSizeValue(create_device_metadata->host_coherent_mem_size);
    result += encoder->EncodeVkDeviceSizeValue(create_device_metadata->host_cached_mem_size);
    result += encoder->EncodeVkDeviceSizeValue(create_device_metadata->protected_mem_size);
    return result;
}

size_t EncodeAllocateMemoryMetadata(ParameterEncoder* encoder, const AllocateMemoryMetadata* allocate_memory_metadata)
{
    size_t result = 0;
    result += encoder->EncodeUInt32Value(allocate_memory_metadata->struct_id);
    result += encoder->EncodeUInt32Value(allocate_memory_metadata->struct_version);
    result += encoder->EncodeUInt32Value(allocate_memory_metadata->alloc_index);
    result += encoder->EncodeVkDeviceSizeValue(allocate_memory_metadata->requested_size);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->property_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->unique_property_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->largest_of_property_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->largest_of_remaining_property_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->heap_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->unique_heap_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->largest_of_heap_flags);
    result += encoder->EncodeFlagsValue(allocate_memory_metadata->largest_of_remaining_heap_flags);
    return result;
}

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_METADATA_ENCODE_DECODE_H