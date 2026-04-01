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

VulkanDeviceAddressTracker::VulkanDeviceAddressTracker(VulkanDeviceAddressTracker&& other) noexcept :
    VulkanDeviceAddressTracker()
{
    swap(*this, other);
}

VulkanDeviceAddressTracker& VulkanDeviceAddressTracker::operator=(VulkanDeviceAddressTracker other)
{
    swap(*this, other);
    return *this;
}

void swap(VulkanDeviceAddressTracker& lhs, VulkanDeviceAddressTracker& rhs) noexcept
{
    std::lock(lhs.mutex_, rhs.mutex_);
    std::lock_guard lock_lhs(lhs.mutex_, std::adopt_lock);
    std::lock_guard lock_rhs(rhs.mutex_, std::adopt_lock);
    std::swap(lhs.buffer_addresses_, rhs.buffer_addresses_);
    std::swap(lhs.acceleration_structure_addresses_, rhs.acceleration_structure_addresses_);
}

void encode::VulkanDeviceAddressTracker::TrackBuffer(const vulkan_wrappers::BufferWrapper* wrapper)
{
    if (wrapper != nullptr && wrapper->handle != VK_NULL_HANDLE && wrapper->address != 0 && wrapper->size != 0)
    {
        std::unique_lock lock(mutex_);

        if (auto iter = buffer_addresses_.find(wrapper->address); iter != buffer_addresses_.end())
        {
            GFXRECON_LOG_WARNING("[VulkanDeviceAddressTracker] Buffer already exists for address: %" PRIu64
                                 ". Replacing old buffer: %p with new buffer: %p",
                                 wrapper->address,
                                 iter->second.handle,
                                 wrapper->handle);
        }
        buffer_addresses_[wrapper->address] = { wrapper->handle, wrapper->size };
    }
}

void VulkanDeviceAddressTracker::RemoveBuffer(const vulkan_wrappers::BufferWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        std::unique_lock lock(mutex_);

        // If existing buffer found in the map is different from the wrapped buffer, do not remove the mapping.
        // This can happen if two different vkBuffers have the same backing vkDeviceMemory at the same offset and hence
        // same device address. So when the app calls vkDestroyBuffer on the older buffer, we should not remove the
        // mapping for its address because that would invalidate the mapping for the newer buffer that is still alive.
        if (auto iter = buffer_addresses_.find(wrapper->address); iter != buffer_addresses_.end())
        {
            if (iter->second.handle != wrapper->handle)
            {
                GFXRECON_LOG_WARNING("[VulkanDeviceAddressTracker] Cannot remove buffer %p with address: %" PRIu64
                                     " because another buffer: %p with same device address exists",
                                     wrapper->handle,
                                     wrapper->address,
                                     iter->second.handle);
            }
            else
            {
                // Remove the mapping only if the handles match
                buffer_addresses_.erase(wrapper->address);
            }
        }
    }
}

void VulkanDeviceAddressTracker::TrackAccelerationStructure(
    const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    if (wrapper != nullptr && wrapper->handle != VK_NULL_HANDLE && wrapper->address != 0)
    {
        std::unique_lock lock(mutex_);
        acceleration_structure_addresses_[wrapper->address] = wrapper->handle;
    }
}

void VulkanDeviceAddressTracker::RemoveAccelerationStructure(
    const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    if (wrapper != nullptr)
    {
        std::unique_lock lock(mutex_);
        acceleration_structure_addresses_.erase(wrapper->address);
    }
}

VkBuffer VulkanDeviceAddressTracker::GetBufferByDeviceAddress(VkDeviceAddress device_address) const
{
    std::shared_lock lock(mutex_);

    if (!buffer_addresses_.empty())
    {
        // find first address equal or greater
        auto address_it = buffer_addresses_.lower_bound(device_address);

        if (address_it == buffer_addresses_.end() || address_it->first > device_address)
        {
            // not found
            if (address_it == buffer_addresses_.begin())
            {
                return VK_NULL_HANDLE;
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
    std::shared_lock lock(mutex_);
    auto             address_it = acceleration_structure_addresses_.find(device_address);
    if (address_it != acceleration_structure_addresses_.end())
    {
        return address_it->second;
    }
    return VK_NULL_HANDLE;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)