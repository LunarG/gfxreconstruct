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
void VulkanTrackedObjectInfoTable::AddTrackedVkInstanceInfo(TrackedVkInstanceInfo&& info)
{
    AddTrackedVkObjectInfo(std::move(info), &tracked_instance_map_);
}

// Add tracked physical device information into the physical devices table map
void VulkanTrackedObjectInfoTable::AddTrackedVkPhysicalDeviceInfo(TrackedVkPhysicalDeviceInfo&& info)
{
    AddTrackedVkObjectInfo(std::move(info), &tracked_physical_device_map_);
}

// Add tracked device information into the devices table map
void VulkanTrackedObjectInfoTable::AddTrackedVkDeviceInfo(TrackedVkDeviceInfo&& info)
{
    AddTrackedVkObjectInfo(std::move(info), &tracked_device_map_);
}

// Add tracked memory information into the tracked memories information table map
void VulkanTrackedObjectInfoTable::AddTrackedVkDeviceMemoryInfo(TrackedVkDeviceMemoryInfo&& info)
{
    AddTrackedVkObjectInfo(std::move(info), &tracked_device_memory_map_);
}

// Add tracked resource information into the tracked buffers information table map
void VulkanTrackedObjectInfoTable::AddTrackedVkResourceInfo(TrackedVkResourceInfo&& info)
{
    AddTrackedVkObjectInfo(std::move(info), &tracked_resource_map_);
}

TrackedVkInstanceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkInstanceInfo(format::HandleId id)
{
    return GetTrackedVkObjectInfo<TrackedVkInstanceInfo>(id, &tracked_instance_map_);
}

const TrackedVkInstanceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkInstanceInfo(format::HandleId id) const
{
    return GetTrackedVkObjectInfo<TrackedVkInstanceInfo>(id, &tracked_instance_map_);
}

TrackedVkPhysicalDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkPhysicalDeviceInfo(format::HandleId id)
{
    return GetTrackedVkObjectInfo<TrackedVkPhysicalDeviceInfo>(id, &tracked_physical_device_map_);
}

const TrackedVkPhysicalDeviceInfo*
VulkanTrackedObjectInfoTable::GetTrackedVkPhysicalDeviceInfo(format::HandleId id) const
{
    return GetTrackedVkObjectInfo<TrackedVkPhysicalDeviceInfo>(id, &tracked_physical_device_map_);
}

TrackedVkDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkDeviceInfo(format::HandleId id)
{
    return GetTrackedVkObjectInfo<TrackedVkDeviceInfo>(id, &tracked_device_map_);
}

const TrackedVkDeviceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkDeviceInfo(format::HandleId id) const
{
    return GetTrackedVkObjectInfo<TrackedVkDeviceInfo>(id, &tracked_device_map_);
}

// Return specified handle ID's device memory information from the tracked memories information table map
TrackedVkDeviceMemoryInfo* VulkanTrackedObjectInfoTable::GetTrackedVkDeviceMemoryInfo(format::HandleId id)
{
    return GetTrackedVkObjectInfo<TrackedVkDeviceMemoryInfo>(id, &tracked_device_memory_map_);
}

const TrackedVkDeviceMemoryInfo* VulkanTrackedObjectInfoTable::GetTrackedVkDeviceMemoryInfo(format::HandleId id) const
{
    return GetTrackedVkObjectInfo<TrackedVkDeviceMemoryInfo>(id, &tracked_device_memory_map_);
}

// Return specified handle ID's buffer information from the tracked buffers information table map
TrackedVkResourceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkResourceInfo(format::HandleId id)
{
    return GetTrackedVkObjectInfo<TrackedVkResourceInfo>(id, &tracked_resource_map_);
}

const TrackedVkResourceInfo* VulkanTrackedObjectInfoTable::GetTrackedVkResourceInfo(format::HandleId id) const
{
    return GetTrackedVkObjectInfo<TrackedVkResourceInfo>(id, &tracked_resource_map_);
}

std::unordered_map<format::HandleId, TrackedVkDeviceMemoryInfo>*
VulkanTrackedObjectInfoTable::GetTrackedVkDeviceMemoriesInfoMap()
{
    return &tracked_device_memory_map_;
}

const std::unordered_map<format::HandleId, TrackedVkDeviceMemoryInfo>*
VulkanTrackedObjectInfoTable::GetTrackedVkDeviceMemoriesInfoMap() const
{
    return &tracked_device_memory_map_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
