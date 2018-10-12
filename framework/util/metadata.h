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

#ifndef BRIMSTONE_UTIL_METADATA_H
#define BRIMSTONE_UTIL_METADATA_H

#include <cinttypes>
#include <cstdio>
#include <vector>
#include <string>

#include "vulkan/vulkan.h"

#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)
BRIMSTONE_BEGIN_NAMESPACE(metadata)

// Types
#define CURRENT_DEVICE_METADATA_VERSION 1
struct DeviceMetadata
{
    uint32_t              struct_version;
    uint32_t              api_version;
    uint32_t              vendor_id;
    uint32_t              hardware_id;
    VkPhysicalDeviceType  type;
    uint8_t               unique_id[VK_UUID_SIZE];
    bool                  has_extensions;            // Whether or not device extensions were listed/used
    char*                 enabled_device_extensions; // Comma-delimited list of enabled device extensions
    bool                  only_device_present;       // This was the only device present at time of recording
    VkQueueFlags          cummulative_queue_flags;   // Queue family flags for all queue families on selected device
    VkQueueFlags          unique_queue_flags;        // Queue family flags not present on other devices on the system
    bool                  has_most_device_local_mem;
    bool                  has_most_host_visible_mem;
    bool                  has_most_host_coherent_mem;
    bool                  has_most_host_cached_mem;
    bool                  has_most_lazily_allocated_mem;
    bool                  has_most_protected_mem;
};

// Functions

// Generate a metadata block for the current physical device when compared to other
// physical devices that are available on the system to help in selection when
// we replay.
bool GenerateDeviceMetadata(VkInstance instance, uint32_t desired_api_version,
                            VkPhysicalDevice phys_device, const std::vector<std::string>& dev_extensions,
                            DeviceMetadata& dev_metadata);

// Select the best physical device that's available on the system depending on the metadata
// and what physical devices are present.
bool SelectDeviceFromMetadata(VkInstance instance, const DeviceMetadata& dev_metadata,
                              VkPhysicalDevice &phys_device);

// Release any allocated memory used in the DeviceMetadata struct
bool ReleaseDeviceMetadata(DeviceMetadata& dev_metadata);

BRIMSTONE_END_NAMESPACE(metadata)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_UTIL_METADATA_H
