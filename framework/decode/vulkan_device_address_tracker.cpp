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
    object_info_table_(object_info_table)
{}

void decode::VulkanDeviceAddressTracker::TrackBuffer(const decode::VulkanBufferInfo* buffer_info)
{
    if (buffer_info != nullptr)
    {
        // track capture device address
        if (buffer_info->capture_address != 0)
        {
            buffer_capture_addresses_[buffer_info->capture_address] = buffer_info->capture_id;
        }

        // track replay device address
        if (buffer_info->replay_address != 0)
        {
            buffer_replay_addresses_[buffer_info->replay_address]    = buffer_info->capture_id;
            address_lookup_helper_map_[buffer_info->capture_address] = { buffer_info->replay_address,
                                                                         buffer_info->size };
        }

        // track vulkan-handle
        if (buffer_info->handle != VK_NULL_HANDLE)
        {
            buffer_handles_[buffer_info->handle] = buffer_info->capture_id;
        }
    }
}

void VulkanDeviceAddressTracker::RemoveBuffer(const VulkanBufferInfo* buffer_info)
{
    if (buffer_info != nullptr)
    {
        buffer_capture_addresses_.erase(buffer_info->capture_address);
        buffer_replay_addresses_.erase(buffer_info->replay_address);
        buffer_handles_.erase(buffer_info->handle);
        address_lookup_helper_map_.erase(buffer_info->capture_address);
    }
}

void VulkanDeviceAddressTracker::TrackAccelerationStructure(
    const VulkanAccelerationStructureKHRInfo* acceleration_structure_info)
{
    if (acceleration_structure_info != nullptr)
    {
        // track capture device address
        if (acceleration_structure_info->capture_address != 0)
        {
            acceleration_structure_capture_addresses_[acceleration_structure_info->capture_address] =
                acceleration_structure_info->capture_id;
        }

        // track vulkan-handle
        if (acceleration_structure_info->handle != VK_NULL_HANDLE)
        {
            acceleration_structure_handles_[acceleration_structure_info->handle] =
                acceleration_structure_info->capture_id;
        }
    }
}

void VulkanDeviceAddressTracker::RemoveAccelerationStructure(
    const VulkanAccelerationStructureKHRInfo* acceleration_structure_info)
{
    if (acceleration_structure_info != nullptr)
    {
        acceleration_structure_capture_addresses_.erase(acceleration_structure_info->capture_address);
        acceleration_structure_handles_.erase(acceleration_structure_info->handle);
    }
}

const decode::VulkanBufferInfo*
decode::VulkanDeviceAddressTracker::GetBufferByCaptureDeviceAddress(VkDeviceAddress capture_address) const
{
    return GetBufferInfo(capture_address, buffer_capture_addresses_);
}

const decode::VulkanBufferInfo*
decode::VulkanDeviceAddressTracker::GetBufferByReplayDeviceAddress(VkDeviceAddress replay_address) const
{
    return GetBufferInfo(replay_address, buffer_replay_addresses_);
}

const VulkanBufferInfo* VulkanDeviceAddressTracker::GetBufferByHandle(VkBuffer handle) const
{
    auto handle_it = buffer_handles_.find(handle);
    if (handle_it != buffer_handles_.end())
    {
        const auto& [h, handle_id] = *handle_it;
        return object_info_table_.GetVkBufferInfo(handle_id);
    }
    return nullptr;
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
        const VulkanBufferInfo* found_buffer       = object_info_table_.GetVkBufferInfo(buffer_handle);

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
    auto address_it = acceleration_structure_capture_addresses_.find(capture_address);
    if (address_it != acceleration_structure_capture_addresses_.end())
    {
        const auto& [found_address, acceleration_structure_handle] = *address_it;
        return object_info_table_.GetVkAccelerationStructureKHRInfo(acceleration_structure_handle);
    }
    return nullptr;
}

[[nodiscard]] const VulkanAccelerationStructureKHRInfo*
VulkanDeviceAddressTracker::GetAccelerationStructureByHandle(VkAccelerationStructureKHR handle) const
{
    auto handle_it = acceleration_structure_handles_.find(handle);
    if (handle_it != acceleration_structure_handles_.end())
    {
        const auto& [h, handle_id] = *handle_it;
        return object_info_table_.GetVkAccelerationStructureKHRInfo(handle_id);
    }
    return nullptr;
}

std::unordered_map<VkDeviceAddress, VkDeviceAddress>
VulkanDeviceAddressTracker::GetAccelerationStructureDeviceAddressMap() const
{
    std::unordered_map<VkDeviceAddress, VkDeviceAddress> ret;
    for (const auto& [address, handleId] : acceleration_structure_capture_addresses_)
    {
        const VulkanAccelerationStructureKHRInfo* acceleration_structure_info =
            object_info_table_.GetVkAccelerationStructureKHRInfo(handleId);

        if (acceleration_structure_info != nullptr && acceleration_structure_info->replay_address != 0)
        {
            ret[address] = acceleration_structure_info->replay_address;
        }
    }
    return ret;
}

const std::unordered_map<VkDeviceAddress, VulkanDeviceAddressTracker::device_address_item_t>&
VulkanDeviceAddressTracker::GetBufferDeviceAddressMap() const
{
    return address_lookup_helper_map_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)