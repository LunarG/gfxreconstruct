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

#include "encode/vulkan_device_address_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void encode::VulkanDeviceAddressTracker::TrackBuffer(const vulkan_wrappers::BufferWrapper* wrapper)
{
    if (wrapper != nullptr && wrapper->handle != VK_NULL_HANDLE && wrapper->address != 0 && wrapper->created_size != 0)
    {
        _buffer_addresses[wrapper->address] = { wrapper->handle, wrapper->created_size };
    }
}

void VulkanDeviceAddressTracker::RemoveBuffer(const vulkan_wrappers::BufferWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        _buffer_addresses.erase(wrapper->address);
    }
}

void VulkanDeviceAddressTracker::TrackAccelerationStructure(
    const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    if (wrapper != nullptr && wrapper->handle != VK_NULL_HANDLE && wrapper->address != 0)
    {
        _acceleration_structure_addresses[wrapper->address] = wrapper->handle;
    }
}

void VulkanDeviceAddressTracker::RemoveAccelerationStructure(
    const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        _acceleration_structure_addresses.erase(wrapper->address);
    }
}

VkBuffer VulkanDeviceAddressTracker::GetBufferByDeviceAddress(VkDeviceAddress device_address) const
{
    if (!_buffer_addresses.empty())
    {
        // find first address equal or greater
        auto address_it = _buffer_addresses.lower_bound(device_address);

        if (address_it == _buffer_addresses.end() || address_it->first > device_address)
        {
            // not found
            if (address_it == _buffer_addresses.begin())
            {
                return nullptr;
            }

            // decrement iterator, now pointing to the first VkDeviceAddress that is lower than device_address
            address_it--;
        }
        // found_address is lower or equal to device_address
        const auto& [found_address, buffer_item] = *address_it;

        if (device_address < found_address + buffer_item.size)
        {
            return buffer_item.handle;
        }
    }
    return VK_NULL_HANDLE;
}

VkAccelerationStructureKHR
VulkanDeviceAddressTracker::GetAccelerationStructureByDeviceAddress(VkDeviceAddress device_address) const
{
    auto address_it = _acceleration_structure_addresses.find(device_address);
    if (address_it != _acceleration_structure_addresses.end())
    {
        return address_it->second;
    }
    return VK_NULL_HANDLE;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)