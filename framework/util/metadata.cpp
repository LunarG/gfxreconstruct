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

#include <string>
#include <sstream>

#include "util/metadata.h"
#include "util/platform.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)
BRIMSTONE_BEGIN_NAMESPACE(metadata)

// Find out if the selected physical device has the most of a given type of memory when
// compared to all the other available physical devices on the system.
bool HasMostOfMemoryType(VkPhysicalDevice selected_phys_device,
                         std::vector<VkPhysicalDevice> all_phys_devices,
                         VkMemoryPropertyFlagBits memory_flag)
{
    size_t selected_memory_size = 0;

    // Add up all memory heaps on our selected device to see how much memory that
    // uses.
    VkPhysicalDeviceMemoryProperties selected_memory_properties;
    vkGetPhysicalDeviceMemoryProperties(selected_phys_device, &selected_memory_properties);
    for (uint32_t mem_type = 0; mem_type < selected_memory_properties.memoryTypeCount; ++mem_type)
    {
        VkMemoryPropertyFlags property_flags = selected_memory_properties.memoryTypes[mem_type].propertyFlags;
        uint32_t heap_index = selected_memory_properties.memoryTypes[mem_type].heapIndex;
        size_t heap_size = selected_memory_properties.memoryHeaps[heap_index].size;
        if (property_flags & memory_flag)
        {
            selected_memory_size += heap_size;
        }
    }

    // Now check all other physical devices to see if our selected device has more
    // of that type of memory
    for (uint32_t device = 0; device < all_phys_devices.size(); ++device)
    {
        size_t cur_memory_size = 0;
        if (all_phys_devices[device] == selected_phys_device)
        {
            continue;
        }

        VkPhysicalDeviceMemoryProperties cur_memory_properties;
        vkGetPhysicalDeviceMemoryProperties(all_phys_devices[device], &cur_memory_properties);
        for (uint32_t mem_type = 0; mem_type < cur_memory_properties.memoryTypeCount; ++mem_type)
        {
            VkMemoryPropertyFlags property_flags = cur_memory_properties.memoryTypes[mem_type].propertyFlags;
            uint32_t heap_index = cur_memory_properties.memoryTypes[mem_type].heapIndex;
            size_t heap_size = cur_memory_properties.memoryHeaps[heap_index].size;
            if (property_flags & memory_flag)
            {
                cur_memory_size += heap_size;
            }
        }

        if (cur_memory_size > selected_memory_size)
        {
            return false;
        }
    }
    return true;
}

// Generate a metadata block for the current physical device when compared to other
// physical devices that are available on the system to help in selection when
// we replay.
bool GenerateDeviceMetadata(VkInstance instance, uint32_t desired_api_version,
                            VkPhysicalDevice phys_device, const std::vector<std::string>& dev_extensions,
                            DeviceMetadata& dev_metadata)
{
    // Setup the metadata
    dev_metadata = {};
    dev_metadata.struct_version = CURRENT_DEVICE_METADATA_VERSION;

    // Grab the actual device information
    VkPhysicalDeviceProperties used_phys_dev_props;
    vkGetPhysicalDeviceProperties(phys_device, &used_phys_dev_props);

    // Copy over the physical device properties used by the application
    dev_metadata.api_version = desired_api_version;
    dev_metadata.vendor_id   = used_phys_dev_props.vendorID;
    dev_metadata.hardware_id = used_phys_dev_props.deviceID;
    dev_metadata.type        = used_phys_dev_props.deviceType;
    platform::MemoryCopy(dev_metadata.unique_id, VK_UUID_SIZE * sizeof(uint8_t),
                         used_phys_dev_props.pipelineCacheUUID, VK_UUID_SIZE * sizeof(uint8_t));
    if (0 < dev_extensions.size())
    {
        dev_metadata.has_extensions = true;
        std::string extension_list;
        for (uint32_t ext = 0; ext < dev_extensions.size(); ++ext)
        {
            if (ext > 0)
            {
                extension_list += ",";
            }
            extension_list += dev_extensions[ext];
        }
        
        size_t ext_string_len = extension_list.size() + 1;
        dev_metadata.enabled_device_extensions = new char[ext_string_len];
        if (nullptr == dev_metadata.enabled_device_extensions)
        {
            return false;
        }
        else
        {
            if (platform::StringCopy(dev_metadata.enabled_device_extensions, ext_string_len,
                                     extension_list.c_str(), extension_list.size()))
            {
                return false;
            }
            dev_metadata.enabled_device_extensions[ext_string_len] = '\0';
        }
    }
    else
    {
        dev_metadata.has_extensions = false;
    }

    // Find out what other physical devices are available for this instance
    uint32_t number_of_total_devices = 0;
    VkResult result = vkEnumeratePhysicalDevices(instance, &number_of_total_devices, nullptr);
    if (VK_SUCCESS != result)
    {
        return false;
    }

    if (number_of_total_devices == 1)
    {
        // Only one device, so we have nothing to compare it against.  Therefor,
        // when we select a device later, we just select the one we think is best.
        dev_metadata.only_device_present = true;
    }
    else
    {
        dev_metadata.has_most_device_local_mem = false;
        dev_metadata.has_most_host_visible_mem = false;
        dev_metadata.has_most_host_coherent_mem = false;
        dev_metadata.has_most_host_cached_mem = false;
        dev_metadata.has_most_lazily_allocated_mem = false;
        dev_metadata.has_most_protected_mem = false;

        uint32_t num_queue_families = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(phys_device, &num_queue_families, nullptr);
        if (num_queue_families == 0)
        {
            return false;
        }
        std::vector<VkQueueFamilyProperties> device_queue_properties;
        device_queue_properties.resize(num_queue_families);
        vkGetPhysicalDeviceQueueFamilyProperties(phys_device, &num_queue_families,
                                                device_queue_properties.data());
        if (num_queue_families == 0)
        {
            return false;
        }

        // Determine what queue flags are available for this device
        dev_metadata.cummulative_queue_flags = 0;
        for (uint32_t family = 0; family < num_queue_families; ++family)
        {
            dev_metadata.cummulative_queue_flags |= device_queue_properties[family].queueFlags;
        }
        dev_metadata.unique_queue_flags = dev_metadata.cummulative_queue_flags;

        std::vector<VkPhysicalDevice> all_phys_devices;
        all_phys_devices.resize(number_of_total_devices);
        result = vkEnumeratePhysicalDevices(instance, &number_of_total_devices, all_phys_devices.data());
        if (VK_SUCCESS != result)
        {
            return false;
        }
        std::vector<VkPhysicalDeviceProperties> all_phys_dev_props;
        all_phys_dev_props.resize(number_of_total_devices);
        for (uint32_t dev = 0; dev < number_of_total_devices; ++dev)
        {
            // Don't look at the current physical device
            if (all_phys_devices[dev] == phys_device)
            {
                continue;
            }
            vkGetPhysicalDeviceProperties(all_phys_devices[dev], &all_phys_dev_props[dev]);
            uint32_t cur_queue_families = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(all_phys_devices[dev], &cur_queue_families, nullptr);
            // If something happened, just skip this device
            if (cur_queue_families == 0)
            {
                continue;
            }
            std::vector<VkQueueFamilyProperties> cur_device_queue_properties;
            cur_device_queue_properties.resize(cur_queue_families);
            vkGetPhysicalDeviceQueueFamilyProperties(all_phys_devices[dev], &cur_queue_families,
                                                     cur_device_queue_properties.data());
            // If something happened, just skip this device
            if (cur_queue_families == 0)
            {
                continue;
            }
            // Figure out any queue family flags that make the selected device unique by
            // removing any common flags common to both our device and the current device in the list.
            for (uint32_t family = 0; family < cur_queue_families; ++family)
            {
                dev_metadata.unique_queue_flags &= ~device_queue_properties[family].queueFlags;
            }

            // Determine if this device has the most of any particular kind of memory
            dev_metadata.has_most_device_local_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
            dev_metadata.has_most_host_visible_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
            dev_metadata.has_most_host_coherent_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
            dev_metadata.has_most_host_cached_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_HOST_CACHED_BIT);
            dev_metadata.has_most_lazily_allocated_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
            dev_metadata.has_most_protected_mem = HasMostOfMemoryType(
                    phys_device, all_phys_devices, VK_MEMORY_PROPERTY_PROTECTED_BIT);
        }
    }

    return true;
}

// Filter out devices that can't possibly meet our needs
static bool FilterDeviceListUsingMetadata(std::vector<VkPhysicalDevice>& all_phys_devices, const DeviceMetadata& dev_metadata)
{
    std::vector<std::string> expected_extension_list;
    uint32_t expected_extension_count = 0;

    // Support a device that has at least an API version that we need.
    uint32_t metadata_api_major_version = VK_VERSION_MAJOR(dev_metadata.api_version);
    uint32_t metadata_api_minor_version = VK_VERSION_MINOR(dev_metadata.api_version);
    for (int32_t dev = 0; dev < all_phys_devices.size(); ++dev)
    {
        VkPhysicalDeviceProperties cur_phys_device_properties;
        vkGetPhysicalDeviceProperties(all_phys_devices[dev], &cur_phys_device_properties);
        uint32_t device_api_major_version = VK_VERSION_MAJOR(cur_phys_device_properties.apiVersion);
        uint32_t device_api_minor_version = VK_VERSION_MINOR(cur_phys_device_properties.apiVersion);
        if (device_api_major_version < metadata_api_major_version ||
            (device_api_major_version == metadata_api_major_version && device_api_major_version < metadata_api_major_version))
        {
            all_phys_devices.erase(all_phys_devices.begin() + dev);
            --dev;
        }
    }

    // If extensions are listed, device also needs to support those extensions
    if (dev_metadata.has_extensions)
    {
        std::istringstream ext_string_stream(dev_metadata.enabled_device_extensions);
        std::string current_string;
        while (getline(ext_string_stream, current_string, ','))
        {
            expected_extension_list.push_back(current_string);
        }

        std::vector<bool> found_device_extension;
        found_device_extension.resize(expected_extension_count);
        for (int32_t dev = 0; dev < all_phys_devices.size(); ++dev)
        {
            bool can_use = true;
            uint32_t device_extension_count = 0;
            if (VK_SUCCESS != vkEnumerateDeviceExtensionProperties(all_phys_devices[dev],
                                                                nullptr,
                                                                &device_extension_count,
                                                                nullptr) ||
                expected_extension_count > device_extension_count)
            {
                // Can't query data, so don't use.
                can_use = false;
            }
            else
            {
                std::vector<VkExtensionProperties> device_extension_properties;
                device_extension_properties.resize(device_extension_count);
                if (VK_SUCCESS != vkEnumerateDeviceExtensionProperties(all_phys_devices[dev],
                                                                    nullptr,
                                                                    &device_extension_count,
                                                                    device_extension_properties.data()))
                {
                    // Can't query data, so don't use.
                    can_use = false;
                }
                else
                {
                    // Check each extension since we will need each of them and reject any device
                    // which doesn't support all of them.
                    for (uint32_t ext1 = 0; ext1 < expected_extension_count; ++ext1)
                    {
                        bool found = false;
                        for (uint32_t ext2 = 0; ext2 < device_extension_count; ++ext2)
                        {
                            if (expected_extension_list[ext1] == device_extension_properties[ext2].extensionName)
                            {
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                        {
                            can_use = false;
                            break;
                        }
                    }
                }
            }

            // We can't use this device at all, so just remove it.
            if (!can_use)
            {
                all_phys_devices.erase(all_phys_devices.begin() + dev);
                --dev;
            }
        }
    }

    return all_phys_devices.size() > 0;
}

// Select the best physical device that's available on the system depending on the metadata
// and what physical devices are present.
bool SelectDeviceFromMetadata(VkInstance instance, const DeviceMetadata& dev_metadata,
                              VkPhysicalDevice &phys_device)
{
    // Find out what physical devices are available for this instance
    uint32_t number_of_total_devices = 0;
    VkResult result = vkEnumeratePhysicalDevices(instance, &number_of_total_devices, nullptr);
    if (VK_SUCCESS != result || 0 == number_of_total_devices)
    {
        return false;
    }
    std::vector<VkPhysicalDevice> all_phys_devices;
    all_phys_devices.resize(number_of_total_devices);
    result = vkEnumeratePhysicalDevices(instance, &number_of_total_devices, all_phys_devices.data());
    if (VK_SUCCESS != result)
    {
        return false;
    }

    // Process list of devices down to the very basic idea of what we need (supports the needed API
    // version and list of extensions)
    if (!FilterDeviceListUsingMetadata(all_phys_devices, dev_metadata))
    {
        return false;
    }

    // If there's only one device, we can only use that.
    if (number_of_total_devices == 1)
    {
        phys_device = all_phys_devices[0];
    }
    else
    {
        // There's more than one Vulkan-capable device available.  So, grab
        // their properties, and start determining which is the best match for
        // what this capture was recorded on.
        phys_device = VK_NULL_HANDLE;
        VkPhysicalDevice best_phys_device = VK_NULL_HANDLE;
        VkPhysicalDeviceProperties best_phys_dev_props;
        for (uint32_t dev = 0; dev < number_of_total_devices; ++dev)
        {
            VkPhysicalDeviceProperties phys_dev_props;
            vkGetPhysicalDeviceProperties(all_phys_devices[dev], &phys_dev_props);

            // First, look for the exact same device, if it is, just bail.
            size_t uuid_size = VK_UUID_SIZE * sizeof(uint8_t);
            if (!platform::MemoryCompare(dev_metadata.unique_id, phys_dev_props.pipelineCacheUUID, uuid_size))
            {
                phys_device = all_phys_devices[dev];
                break;
            }
            // Next, look for a device by the same vendor
            if (dev_metadata.vendor_id == phys_dev_props.vendorID)
            {
                // If it's the same device ID, it's the same type of device used
                // for the capture, so use it.  Also, if nothing else has been selected
                // at this point, use this device if it's the same type of device.
                // However, don't stop here in case the exact device is still present.
                if (dev_metadata.hardware_id == phys_dev_props.deviceID ||
                    (VK_NULL_HANDLE == phys_device && dev_metadata.type == phys_dev_props.deviceType))
                {
                    phys_device = all_phys_devices[dev];
                    continue;
                }
            }

            // Choose the first one as the best physical device, then pick the one with the
            // best type of GPU.  There might be more than one of each of these.
            if (0 == dev ||
                (best_phys_dev_props.deviceType != phys_dev_props.deviceType &&
                 best_phys_dev_props.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU &&
                 (phys_dev_props.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ||
                  phys_dev_props.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU)))
            {
                best_phys_device = all_phys_devices[dev];
                best_phys_dev_props = phys_dev_props;
                continue;
            }
            // Not integrated or discrete, don't test anymore.
            else if (phys_dev_props.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ||
                     phys_dev_props.deviceType != VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU)
            {
                continue;
            }

            // If this recorded with more than one device present, try to pick a similar GPU
            if (!dev_metadata.only_device_present)
            {
                // If the GPU we recorded on had the most local memory, and this one does,
                // then use this device
                if (dev_metadata.has_most_device_local_mem &&
                    HasMostOfMemoryType(all_phys_devices[dev],
                                        all_phys_devices, 
                                        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT))
                {
                    best_phys_device = all_phys_devices[dev];
                    best_phys_dev_props = phys_dev_props;
                    continue;
                }
            }
        }
        // If we didn't find the exact same card, then pick the next best
        if (VK_NULL_HANDLE == phys_device)
        {
            phys_device = best_phys_device;
        }
    }
    return true;
}

// Release any allocated memory used in the DeviceMetadata struct
bool ReleaseDeviceMetadata(DeviceMetadata& dev_metadata)
{
    if (dev_metadata.has_extensions && nullptr != dev_metadata.enabled_device_extensions)
    {
        delete dev_metadata.enabled_device_extensions;
        dev_metadata.enabled_device_extensions = nullptr;
        dev_metadata.has_extensions = false;
    }
    return true;
}

BRIMSTONE_END_NAMESPACE(metadata)
BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
