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

#ifndef BRIMSTONE_FORMAT_METADATA_H
#define BRIMSTONE_FORMAT_METADATA_H

#include <cinttypes>
#include <cstdio>

#include "vulkan/vulkan.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(format)

#define CREATE_DEVICE_METADATA_STRUCT_ID 0xDECAF001
#define CURRENT_CREATE_DEVICE_METADATA_VERSION 1
struct CreateDeviceMetadata
{
    uint32_t             struct_id;
    uint32_t             struct_version;
    uint32_t             api_version;
    uint32_t             vendor_id;
    uint32_t             hardware_id;
    VkPhysicalDeviceType type;
    uint8_t              unique_id[VK_UUID_SIZE];
    VkBool32             has_instance_extensions;     // Whether or not instance extensions were listed/used
    char*                enabled_instance_extensions; // Comma-delimited list of enabled instance extensions
    VkBool32             has_device_extensions;       // Whether or not device extensions were listed/used
    char*                enabled_device_extensions;   // Comma-delimited list of enabled device extensions
    VkBool32             only_device_present;         // This was the only device present at time of recording
    VkBool32             use_device_group;            // True if this is this part must be in a device group
    uint32_t             device_group_index;          // GPU index in the device group
    uint32_t             devices_in_group;            // Number of GPUs in the device group
    VkBool32             group_supports_subset_alloc; // GPUS in the group support subset allocation
    VkQueueFlags         cummulative_queue_flags;     // Queue family flags for all queue families on selected device
    VkQueueFlags         unique_queue_flags;          // Queue family flags not present on other devices on the system
    uint32_t             num_memory_types;
    VkMemoryType*        memory_types;
    uint32_t             num_memory_heaps;
    VkMemoryHeap*        memory_heaps;
    VkDeviceSize         device_local_mem_size;
    VkDeviceSize         host_visible_mem_size;
    VkDeviceSize         host_coherent_mem_size;
    VkDeviceSize         host_cached_mem_size;
    VkDeviceSize         protected_mem_size;
};

#define ALLOCATE_MEMORY_METADATA_STRUCT_ID 0xDECAF002
#define CURRENT_ALLOCATE_MEMORY_METADATA_VERSION 1
struct AllocateMemoryMetadata
{
    uint32_t              struct_id;
    uint32_t              struct_version;
    uint32_t              alloc_index;
    VkDeviceSize          requested_size;
    VkMemoryPropertyFlags property_flags;
    VkMemoryPropertyFlags unique_property_flags;
    VkMemoryPropertyFlags largest_of_property_flags;
    VkMemoryPropertyFlags largest_of_remaining_property_flags;
    VkMemoryHeapFlags     heap_flags;
    VkMemoryHeapFlags     unique_heap_flags;
    VkMemoryHeapFlags     largest_of_heap_flags;
    VkMemoryHeapFlags     largest_of_remaining_heap_flags;
};

BRIMSTONE_END_NAMESPACE(format)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_FORMAT_METADATA_H
