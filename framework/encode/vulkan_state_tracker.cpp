/*
** Copyright (c) 2019 LunarG, Inc.
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

#include "encode/vulkan_state_tracker.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() : object_count_(0) {}

VulkanStateTracker::~VulkanStateTracker() {}

void VulkanStateTracker::TrackPhysicalDeviceMemoryProperties(VkPhysicalDevice                        physical_device,
                                                             const VkPhysicalDeviceMemoryProperties* properties)
{
    assert(properties != nullptr);

    std::unique_lock<std::mutex> lock(mutex_);

    PhysicalDeviceWrapper* wrapper = state_table_.GetPhysicalDeviceWrapper(format::ToHandleId(physical_device));
    if (wrapper != nullptr)
    {
        for (uint32_t i = 0; i < properties->memoryTypeCount; ++i)
        {
            wrapper->memory_types.push_back(properties->memoryTypes[i]);
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track memory properties for unrecognized physical device handle");
    }
}

void VulkanStateTracker::TrackBufferMemoryBinding(VkDevice       device,
                                                  VkBuffer       buffer,
                                                  VkDeviceMemory memory,
                                                  VkDeviceSize   memoryOffset)
{
    std::unique_lock<std::mutex> lock(mutex_);

    BufferWrapper* wrapper = state_table_.GetBufferWrapper(format::ToHandleId(buffer));
    if (wrapper != nullptr)
    {
        wrapper->bind_device = device;
        wrapper->bind_memory = memory;
        wrapper->bind_offset = memoryOffset;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track bind state for unrecognized buffer handle");
    }
}

void VulkanStateTracker::TrackImageMemoryBinding(VkDevice       device,
                                                 VkImage        image,
                                                 VkDeviceMemory memory,
                                                 VkDeviceSize   memoryOffset)
{
    std::unique_lock<std::mutex> lock(mutex_);

    ImageWrapper* wrapper = state_table_.GetImageWrapper(format::ToHandleId(image));
    if (wrapper != nullptr)
    {
        wrapper->bind_device = device;
        wrapper->bind_memory = memory;
        wrapper->bind_offset = memoryOffset;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track bind state for unrecognized buffer handle");
    }
}

void VulkanStateTracker::TrackMappedMemory(VkDeviceMemory memory,
                                           void*          mapped_data,
                                           VkDeviceSize   mapped_offset,
                                           VkDeviceSize   mapped_size)
{
    std::unique_lock<std::mutex> lock(mutex_);

    DeviceMemoryWrapper* wrapper = state_table_.GetDeviceMemoryWrapper(format::ToHandleId(memory));
    if (wrapper != nullptr)
    {
        wrapper->mapped_data   = mapped_data;
        wrapper->mapped_offset = mapped_offset;
        wrapper->mapped_size   = mapped_size;
    }
    else
    {
        GFXRECON_LOG_WARNING("Attempting to track mapped state for unrecognized device memory handle");
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
