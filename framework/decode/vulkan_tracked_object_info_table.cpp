/*
** Copyright (c) 2020-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "vulkan_tracked_object_info_table.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Add tracked instance information into the instances table map
void VulkanTrackedObjectInfoTable::AddTrackedInstanceInfo(TrackedInstanceInfo&& info)
{
    AddTrackedObjectInfo(std::move(info), &tracked_instance_map_);
}

// Add tracked physical device information into the physical devices table map
void VulkanTrackedObjectInfoTable::AddTrackedPhysicalDeviceInfo(TrackedPhysicalDeviceInfo&& info)
{
    AddTrackedObjectInfo(std::move(info), &tracked_physical_device_map_);
}

// Add tracked device information into the devices table map
void VulkanTrackedObjectInfoTable::AddTrackedDeviceInfo(TrackedDeviceInfo&& info)
{
    AddTrackedObjectInfo(std::move(info), &tracked_device_map_);
}

// Add tracked memory information into the tracked memories information table map
void VulkanTrackedObjectInfoTable::AddTrackedDeviceMemoryInfo(TrackedDeviceMemoryInfo&& info)
{
    AddTrackedObjectInfo(std::move(info), &tracked_device_memory_map_);
}

// Add tracked resource information into the tracked buffers information table map
void VulkanTrackedObjectInfoTable::AddTrackedResourceInfo(TrackedResourceInfo&& info)
{
    AddTrackedObjectInfo(std::move(info), &tracked_resource_map_);
}

TrackedInstanceInfo* VulkanTrackedObjectInfoTable::GetTrackedInstanceInfo(format::HandleId id)
{
    return GetTrackedObjectInfo<TrackedInstanceInfo>(id, &tracked_instance_map_);
}

const TrackedInstanceInfo* VulkanTrackedObjectInfoTable::GetTrackedInstanceInfo(format::HandleId id) const
{
    return GetTrackedObjectInfo<TrackedInstanceInfo>(id, &tracked_instance_map_);
}

TrackedPhysicalDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedPhysicalDeviceInfo(format::HandleId id)
{
    return GetTrackedObjectInfo<TrackedPhysicalDeviceInfo>(id, &tracked_physical_device_map_);
}

const TrackedPhysicalDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedPhysicalDeviceInfo(format::HandleId id) const
{
    return GetTrackedObjectInfo<TrackedPhysicalDeviceInfo>(id, &tracked_physical_device_map_);
}

TrackedDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedDeviceInfo(format::HandleId id)
{
    return GetTrackedObjectInfo<TrackedDeviceInfo>(id, &tracked_device_map_);
}

const TrackedDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedDeviceInfo(format::HandleId id) const
{
    return GetTrackedObjectInfo<TrackedDeviceInfo>(id, &tracked_device_map_);
}

// Return specified handle ID's device memory information from the tracked memories information table map
TrackedDeviceMemoryInfo* VulkanTrackedObjectInfoTable::GetTrackedDeviceMemoryInfo(format::HandleId id)
{
    return GetTrackedObjectInfo<TrackedDeviceMemoryInfo>(id, &tracked_device_memory_map_);
}

const TrackedDeviceMemoryInfo* VulkanTrackedObjectInfoTable::GetTrackedDeviceMemoryInfo(format::HandleId id) const
{
    return GetTrackedObjectInfo<TrackedDeviceMemoryInfo>(id, &tracked_device_memory_map_);
}

// Return specified handle ID's buffer information from the tracked buffers information table map
TrackedResourceInfo* VulkanTrackedObjectInfoTable::GetTrackedResourceInfo(format::HandleId id)
{
    return GetTrackedObjectInfo<TrackedResourceInfo>(id, &tracked_resource_map_);
}

const TrackedResourceInfo* VulkanTrackedObjectInfoTable::GetTrackedResourceInfo(format::HandleId id) const
{
    return GetTrackedObjectInfo<TrackedResourceInfo>(id, &tracked_resource_map_);
}

std::unordered_map<format::HandleId, TrackedDeviceMemoryInfo>*
VulkanTrackedObjectInfoTable::GetTrackedDeviceMemoriesInfoMap()
{
    return &tracked_device_memory_map_;
}

const std::unordered_map<format::HandleId, TrackedDeviceMemoryInfo>*
VulkanTrackedObjectInfoTable::GetTrackedDeviceMemoriesInfoMap() const
{
    return &tracked_device_memory_map_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
