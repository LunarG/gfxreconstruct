/*
** Copyright (c) 2024 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "decode/vulkan_device_address_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanDeviceAddressTracker::VulkanDeviceAddressTracker(const VulkanObjectInfoTable& object_info_table) :
    _object_info_table(object_info_table)
{}

void decode::VulkanDeviceAddressTracker::TrackBuffer(const decode::VulkanBufferInfo* buffer_info)
{
    if (buffer_info != nullptr && buffer_info->capture_address != 0)
    {
        _buffer_capture_addresses[buffer_info->capture_address] = buffer_info->capture_id;
    }
}

void VulkanDeviceAddressTracker::RemoveBuffer(const VulkanBufferInfo* buffer_info)
{
    if (buffer_info != nullptr)
    {
        _buffer_capture_addresses.erase(buffer_info->capture_address);
    }
}

void VulkanDeviceAddressTracker::TrackAccelerationStructure(
    const VulkanAccelerationStructureKHRInfo* acceleration_structure_info)
{
    if (acceleration_structure_info != nullptr && acceleration_structure_info->capture_address != 0)
    {
        _acceleration_structure_capture_addresses[acceleration_structure_info->capture_address] =
            acceleration_structure_info->capture_id;
    }
}

void VulkanDeviceAddressTracker::RemoveAccelerationStructure(
    const VulkanAccelerationStructureKHRInfo* acceleration_structure_info)
{
    if (acceleration_structure_info != nullptr)
    {
        _acceleration_structure_capture_addresses.erase(acceleration_structure_info->capture_id);
    }
}

const decode::VulkanBufferInfo*
decode::VulkanDeviceAddressTracker::GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address) const
{
    return GetBufferInfo(capture_address, _buffer_capture_addresses);
}

const VulkanBufferInfo*
VulkanDeviceAddressTracker::GetBufferInfo(VkDeviceAddress                                         device_address,
                                          const VulkanDeviceAddressTracker::buffer_address_map_t& address_map) const
{
    if (!address_map.empty())
    {
        // find first address equal or greater
        auto address_it = address_map.lower_bound(device_address);

        if (address_it == address_map.end() || address_it->first > device_address)
        {
            // not found
            if (address_it == address_map.begin())
            {
                return nullptr;
            }

            // decrement iterator, now pointing to the first VkDeviceAddress that is lower than device_address
            address_it--;
        }
        // found_address is lower or equal to device_address
        const auto& [found_address, buffer_handle] = *address_it;
        const VulkanBufferInfo* found_buffer       = _object_info_table.GetVkBufferInfo(buffer_handle);

        if (found_buffer != nullptr)
        {
            if (device_address < found_address + found_buffer->size)
            {
                return found_buffer;
            }
        }
    }
    return nullptr;
}

const VulkanAccelerationStructureKHRInfo*
VulkanDeviceAddressTracker::GetAccelerationStructureByCaptureDeviceAddress(VkDeviceAddress capture_address) const
{
    auto address_it = _acceleration_structure_capture_addresses.find(capture_address);
    if (address_it != _acceleration_structure_capture_addresses.end())
    {
        const auto& [found_address, acceleration_structure_handle] = *address_it;
        const VulkanAccelerationStructureKHRInfo* found_acceleration_structure_info =
            _object_info_table.GetVkAccelerationStructureKHRInfo(acceleration_structure_handle);

        if (found_acceleration_structure_info != nullptr)
        {
            return found_acceleration_structure_info;
        }
    }
    return nullptr;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)