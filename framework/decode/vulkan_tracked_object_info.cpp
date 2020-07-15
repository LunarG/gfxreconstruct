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

#include "vulkan_tracked_object_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Set physical device which is the parent of this logical device
void TrackedDeviceInfo::SetParentPhysicalDevice(VkPhysicalDevice physical_device)
{
    parent_ = physical_device;
}

// Get physical device which is the parent of this logical device
VkPhysicalDevice TrackedDeviceInfo::GetParentPhysicalDevice() const
{
    return parent_;
}

// Set capture device physical memory properties
void TrackedDeviceInfo::SetCaptureDevicePhysicalMemoryProperties(
    const VkPhysicalDeviceMemoryProperties* memory_properties)
{
    capture_memory_properties_ = memory_properties;
}

// Get capture device physical memory properties
const VkPhysicalDeviceMemoryProperties* TrackedDeviceInfo::GetCaptureDevicePhysicalMemoryProperties() const
{
    return capture_memory_properties_;
}

// Set replay device physical memory properties
void TrackedDeviceInfo::SetReplayDevicePhysicalMemoryProperties(
    const VkPhysicalDeviceMemoryProperties* memory_properties)
{
    replay_memory_properties_ = memory_properties;
}

// Get replay device physical memory properties
const VkPhysicalDeviceMemoryProperties* TrackedDeviceInfo::GetReplayDevicePhysicalMemoryProperties() const
{
    return replay_memory_properties_;
}

// Set trace memory allocation size
void TrackedDeviceMemoryInfo::SetTraceMemoryAllocationSize(VkDeviceSize memory_allocation_size)
{
    trace_memory_allocation_size_ = memory_allocation_size;
}

// Get trace memory allocation size
VkDeviceSize TrackedDeviceMemoryInfo::GetTraceMemoryAllocationSize() const
{
    return trace_memory_allocation_size_;
}

// Insert the mapped memory size number into the mapped memories sizes list
void TrackedDeviceMemoryInfo::InsertMappedMemorySizesList(VkDeviceSize mapped_memory_size)
{
    mapped_memories_sizes_.push_back(mapped_memory_size);
}

// Get mapped memories sizes list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetMappedMemorySizesList() const
{
    return mapped_memories_sizes_;
}

// Insert the mapped memory offset number into the mapped memories offsets list
void TrackedDeviceMemoryInfo::InsertMappedMemoryOffsetsList(VkDeviceSize mapped_memory_offset)
{
    mapped_memories_offsets_.push_back(mapped_memory_offset);
}

// Get mapped memories offsets list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetMappedMemoryOffsetsList() const
{
    return mapped_memories_offsets_;
}

// Insert the filled memory size number into the filled memories sizes list
void TrackedDeviceMemoryInfo::InsertFilledMemorySizesList(VkDeviceSize filled_memory_size)
{
    filled_memories_sizes_.push_back(filled_memory_size);
}

// Get filled memories sizes list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetFilledMemorySizesList() const
{
    return filled_memories_sizes_;
}

// Insert the filled memory offset number into the filled memories offsets list
void TrackedDeviceMemoryInfo::InsertFilledMemoryOffsetsList(VkDeviceSize filled_memory_offset)
{
    filled_memories_offsets_.push_back(filled_memory_offset);
}

// Get filled memories offsets list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetFilledMemoryOffsetsList() const
{
    return filled_memories_offsets_;
}

// Insert resource into the  bound resource list
void TrackedDeviceMemoryInfo::InsertBoundResourcesList(TrackedResourceInfo* resource)
{
    bound_resources_.push_back(resource);
}

// Get bound resource list
std::vector<TrackedResourceInfo*>* TrackedDeviceMemoryInfo::GetBoundResourcesList()
{
    return &bound_resources_;
}

const std::vector<TrackedResourceInfo*>* TrackedDeviceMemoryInfo::GetBoundResourcesList() const
{
    return &bound_resources_;
}

void TrackedDeviceMemoryInfo::AllocateReplayMemoryAllocationSize(VkDeviceSize size)
{
    replay_memory_allocation_size_ = size;
}

VkDeviceSize TrackedDeviceMemoryInfo::GetReplayMemoryAllocationSize() const
{
    return replay_memory_allocation_size_;
}

void TrackedDeviceMemoryInfo::SetMemoryPropertyFlags(VkMemoryPropertyFlags property_flags)
{
    property_flags_ = property_flags;
}

VkMemoryPropertyFlags TrackedDeviceMemoryInfo::GetMemoryPropertyFlags() const
{
    return property_flags_;
}

// Set memory ID that this resource bound to
void TrackedResourceInfo::SetBoundMemoryId(format::HandleId memory_id)
{
    memory_id_ = memory_id;
}

// Get memory ID that this resource bound to
format::HandleId TrackedResourceInfo::GetBoundMemoryId() const
{
    return memory_id_;
}

// Set memory property flags that this resource bound to
void TrackedResourceInfo::SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags)
{
    memory_property_flags_ = memory_property_flags;
}

// Get memory property flags that this resource bound to
VkMemoryPropertyFlags TrackedResourceInfo::GetBoundMemoryPropertyFlags() const
{
    return memory_property_flags_;
}

// Set trace resource binding offset
void TrackedResourceInfo::SetTraceBindOffset(VkDeviceSize bind_offset)
{
    if (bind_offset > 0)
    {
        trace_bind_offset_ = bind_offset;
    }
}

// Get trace source binding offset
VkDeviceSize TrackedResourceInfo::GetTraceBindOffset() const
{
    return trace_bind_offset_;
}

void TrackedResourceInfo::SetReplayBindOffset(VkDeviceSize bind_offset)
{
    if (bind_offset > 0)
    {
        replay_bind_offset_ = bind_offset;
    }
}

VkDeviceSize TrackedResourceInfo::GetReplayBindOffset() const
{
    return replay_bind_offset_;
}

void TrackedResourceInfo::SetTraceResourceSize(VkDeviceSize size)
{
    if (size > 0)
    {
        trace_size_ = size;
    }
}

VkDeviceSize TrackedResourceInfo::GetTraceResourceSize() const
{
    return trace_size_;
}

void TrackedResourceInfo::SetTraceResourceAlignment(VkDeviceSize alignment)
{
    if (alignment > 0)
    {
        trace_alignment_ = alignment;
    }
}

VkDeviceSize TrackedResourceInfo::GetTraceResourceAlignment() const
{
    return trace_alignment_;
}

void TrackedResourceInfo::SetTraceResourceMemoryTypeBits(uint32_t memory_type_bits)
{
    trace_memory_type_bits_ = memory_type_bits;
}

uint32_t TrackedResourceInfo::GetTraceResourceMemoryTypeBits() const
{
    return trace_memory_type_bits_;
}

void TrackedResourceInfo::SetReplayResourceSize(VkDeviceSize size)
{
    if (size > 0)
    {
        replay_size_ = size;
    }
}

VkDeviceSize TrackedResourceInfo::GetReplayResourceSize() const
{
    return replay_size_;
}

void TrackedResourceInfo::SetReplayResourceAlignment(VkDeviceSize alignment)
{
    if (alignment > 0)
    {
        replay_alignment_ = alignment;
    }
}

VkDeviceSize TrackedResourceInfo::GetReplayResourceAlignment() const
{
    return replay_alignment_;
}

void TrackedResourceInfo::SetReplayResourceMemoryTypeBits(uint32_t memory_type_bits)
{
    replay_memory_type_bits_ = memory_type_bits;
}

uint32_t TrackedResourceInfo::GetReplayResourceMemoryTypeBits() const
{
    return replay_memory_type_bits_;
}

// Set resource's queue family index
void TrackedResourceInfo::SetQueueFamilyIndex(uint32_t queue_family_index)
{
    queue_family_index_ = queue_family_index;
}

// Get resource's queue family index
uint32_t TrackedResourceInfo::GetQueueFamilyIndex() const
{
    return queue_family_index_;
}

// Set buffer creation information
void TrackedResourceInfo::SetBufferCreateInfo(VkBufferCreateInfo buffer_create_info)
{
    buffer_create_info_ = buffer_create_info;
}

// Get buffer binding offset
VkBufferCreateInfo TrackedResourceInfo::GetBufferCreateInfo() const
{
    return buffer_create_info_;
}

void TrackedResourceInfo::SetImageCreateInfo(VkImageCreateInfo image_create_info)
{
    image_create_info_ = image_create_info;
}

VkImageCreateInfo TrackedResourceInfo::GetImageCreateInfo() const
{
    return image_create_info_;
}

void TrackedPhysicalDeviceInfo::SetCaptureDevicePhysicalMemoryProperties(
    VkPhysicalDeviceMemoryProperties memory_properties)
{
    capture_memory_properties_ = memory_properties;
}

VkPhysicalDeviceMemoryProperties* TrackedPhysicalDeviceInfo::GetCaptureDevicePhysicalMemoryProperties()
{
    return &capture_memory_properties_;
}

const VkPhysicalDeviceMemoryProperties* TrackedPhysicalDeviceInfo::GetCaptureDevicePhysicalMemoryProperties() const
{
    return &capture_memory_properties_;
}

void TrackedPhysicalDeviceInfo::SetReplayDevicePhysicalMemoryProperties(
    VkPhysicalDeviceMemoryProperties memory_properties)
{
    replay_memory_properties_ = memory_properties;
}

VkPhysicalDeviceMemoryProperties* TrackedPhysicalDeviceInfo::GetReplayDevicePhysicalMemoryProperties()
{
    return &replay_memory_properties_;
}

const VkPhysicalDeviceMemoryProperties* TrackedPhysicalDeviceInfo::GetReplayDevicePhysicalMemoryProperties() const
{
    return &replay_memory_properties_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
