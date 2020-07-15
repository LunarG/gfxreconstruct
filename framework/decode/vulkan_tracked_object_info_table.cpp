/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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
