/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
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

#include "vulkan_tracked_object_info.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Set physical device which is the parent of this logical device
void TrackedVkDeviceInfo::SetParentPhysicalDevice(VkPhysicalDevice physical_device)
{
    parent_ = physical_device;
}

// Get physical device which is the parent of this logical device
VkPhysicalDevice TrackedVkDeviceInfo::GetParentPhysicalDevice() const
{
    return parent_;
}

// Set capture device physical memory properties
void TrackedVkDeviceInfo::SetCaptureDevicePhysicalMemoryProperties(
    const VkPhysicalDeviceMemoryProperties* memory_properties)
{
    capture_memory_properties_ = memory_properties;
}

// Get capture device physical memory properties
const VkPhysicalDeviceMemoryProperties* TrackedVkDeviceInfo::GetCaptureDevicePhysicalMemoryProperties() const
{
    return capture_memory_properties_;
}

// Set replay device physical memory properties
void TrackedVkDeviceInfo::SetReplayDevicePhysicalMemoryProperties(
    const VkPhysicalDeviceMemoryProperties* memory_properties)
{
    replay_memory_properties_ = memory_properties;
}

// Get replay device physical memory properties
const VkPhysicalDeviceMemoryProperties* TrackedVkDeviceInfo::GetReplayDevicePhysicalMemoryProperties() const
{
    return replay_memory_properties_;
}

// Set trace memory allocation size
void TrackedVkDeviceMemoryInfo::SetTraceMemoryAllocationSize(VkDeviceSize memory_allocation_size)
{
    trace_memory_allocation_size_ = memory_allocation_size;
}

// Get trace memory allocation size
VkDeviceSize TrackedVkDeviceMemoryInfo::GetTraceMemoryAllocationSize() const
{
    return trace_memory_allocation_size_;
}

// Insert the mapped memory size number into the mapped memories sizes list
void TrackedVkDeviceMemoryInfo::InsertMappedMemorySizesList(VkDeviceSize mapped_memory_size)
{
    mapped_memories_sizes_.push_back(mapped_memory_size);
}

// Get mapped memories sizes list
const std::vector<VkDeviceSize>& TrackedVkDeviceMemoryInfo::GetMappedMemorySizesList() const
{
    return mapped_memories_sizes_;
}

// Insert the mapped memory offset number into the mapped memories offsets list
void TrackedVkDeviceMemoryInfo::InsertMappedMemoryOffsetsList(VkDeviceSize mapped_memory_offset)
{
    mapped_memories_offsets_.push_back(mapped_memory_offset);
}

// Get mapped memories offsets list
const std::vector<VkDeviceSize>& TrackedVkDeviceMemoryInfo::GetMappedMemoryOffsetsList() const
{
    return mapped_memories_offsets_;
}

// Insert the filled memory size number into the filled memories sizes list
void TrackedVkDeviceMemoryInfo::InsertFilledMemorySizesList(VkDeviceSize filled_memory_size)
{
    filled_memories_sizes_.push_back(filled_memory_size);
}

// Get filled memories sizes list
const std::vector<VkDeviceSize>& TrackedVkDeviceMemoryInfo::GetFilledMemorySizesList() const
{
    return filled_memories_sizes_;
}

// Insert the filled memory offset number into the filled memories offsets list
void TrackedVkDeviceMemoryInfo::InsertFilledMemoryOffsetsList(VkDeviceSize filled_memory_offset)
{
    filled_memories_offsets_.push_back(filled_memory_offset);
}

// Get filled memories offsets list
const std::vector<VkDeviceSize>& TrackedVkDeviceMemoryInfo::GetFilledMemoryOffsetsList() const
{
    return filled_memories_offsets_;
}

// Insert resource into the  bound resource list
void TrackedVkDeviceMemoryInfo::InsertBoundResourcesList(TrackedVkResourceInfo* resource)
{
    bound_resources_.push_back(resource);
}

// Get bound resource list
std::vector<TrackedVkResourceInfo*>* TrackedVkDeviceMemoryInfo::GetBoundResourcesList()
{
    return &bound_resources_;
}

const std::vector<TrackedVkResourceInfo*>* TrackedVkDeviceMemoryInfo::GetBoundResourcesList() const
{
    return &bound_resources_;
}

void TrackedVkDeviceMemoryInfo::AllocateReplayMemoryAllocationSize(VkDeviceSize size)
{
    replay_memory_allocation_size_ = size;
}

VkDeviceSize TrackedVkDeviceMemoryInfo::GetReplayMemoryAllocationSize() const
{
    return replay_memory_allocation_size_;
}

void TrackedVkDeviceMemoryInfo::SetMemoryPropertyFlags(VkMemoryPropertyFlags property_flags)
{
    property_flags_ = property_flags;
}

VkMemoryPropertyFlags TrackedVkDeviceMemoryInfo::GetMemoryPropertyFlags() const
{
    return property_flags_;
}

// Set memory ID that this resource bound to
void TrackedVkResourceInfo::SetBoundMemoryId(format::HandleId memory_id)
{
    memory_id_ = memory_id;
}

// Get memory ID that this resource bound to
format::HandleId TrackedVkResourceInfo::GetBoundMemoryId() const
{
    return memory_id_;
}

// Set memory property flags that this resource bound to
void TrackedVkResourceInfo::SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags)
{
    memory_property_flags_ = memory_property_flags;
}

// Get memory property flags that this resource bound to
VkMemoryPropertyFlags TrackedVkResourceInfo::GetBoundMemoryPropertyFlags() const
{
    return memory_property_flags_;
}

// Set trace resource binding offset
void TrackedVkResourceInfo::SetTraceBindOffset(VkDeviceSize bind_offset)
{
    if (bind_offset > 0)
    {
        trace_bind_offset_ = bind_offset;
    }
}

// Get trace source binding offset
VkDeviceSize TrackedVkResourceInfo::GetTraceBindOffset() const
{
    return trace_bind_offset_;
}

void TrackedVkResourceInfo::SetReplayBindOffset(VkDeviceSize bind_offset)
{
    if (bind_offset > 0)
    {
        replay_bind_offset_ = bind_offset;
    }
}

VkDeviceSize TrackedVkResourceInfo::GetReplayBindOffset() const
{
    return replay_bind_offset_;
}

void TrackedVkResourceInfo::SetTraceResourceSize(VkDeviceSize size)
{
    if (size > 0)
    {
        trace_size_ = size;
    }
}

VkDeviceSize TrackedVkResourceInfo::GetTraceResourceSize() const
{
    return trace_size_;
}

void TrackedVkResourceInfo::SetTraceResourceAlignment(VkDeviceSize alignment)
{
    if (alignment > 0)
    {
        trace_alignment_ = alignment;
    }
}

VkDeviceSize TrackedVkResourceInfo::GetTraceResourceAlignment() const
{
    return trace_alignment_;
}

void TrackedVkResourceInfo::SetTraceResourceMemoryTypeBits(uint32_t memory_type_bits)
{
    trace_memory_type_bits_ = memory_type_bits;
}

uint32_t TrackedVkResourceInfo::GetTraceResourceMemoryTypeBits() const
{
    return trace_memory_type_bits_;
}

void TrackedVkResourceInfo::SetReplayResourceSize(VkDeviceSize size)
{
    if (size > 0)
    {
        replay_size_ = size;
    }
}

VkDeviceSize TrackedVkResourceInfo::GetReplayResourceSize() const
{
    return replay_size_;
}

void TrackedVkResourceInfo::SetReplayResourceAlignment(VkDeviceSize alignment)
{
    if (alignment > 0)
    {
        replay_alignment_ = alignment;
    }
}

VkDeviceSize TrackedVkResourceInfo::GetReplayResourceAlignment() const
{
    return replay_alignment_;
}

void TrackedVkResourceInfo::SetReplayResourceMemoryTypeBits(uint32_t memory_type_bits)
{
    replay_memory_type_bits_ = memory_type_bits;
}

uint32_t TrackedVkResourceInfo::GetReplayResourceMemoryTypeBits() const
{
    return replay_memory_type_bits_;
}

// Set resource's queue family index
void TrackedVkResourceInfo::SetQueueFamilyIndex(uint32_t queue_family_index)
{
    queue_family_index_ = queue_family_index;
}

// Get resource's queue family index
uint32_t TrackedVkResourceInfo::GetQueueFamilyIndex() const
{
    return queue_family_index_;
}

// Set buffer creation information
void TrackedVkResourceInfo::SetBufferCreateInfo(VkBufferCreateInfo buffer_create_info)
{
    buffer_create_info_ = buffer_create_info;
}

// Get buffer binding offset
VkBufferCreateInfo TrackedVkResourceInfo::GetBufferCreateInfo() const
{
    return buffer_create_info_;
}

void TrackedVkResourceInfo::SetImageCreateInfo(VkImageCreateInfo image_create_info)
{
    image_create_info_ = image_create_info;
}

VkImageCreateInfo TrackedVkResourceInfo::GetImageCreateInfo() const
{
    return image_create_info_;
}

void TrackedVkPhysicalDeviceInfo::SetCaptureDevicePhysicalMemoryProperties(
    VkPhysicalDeviceMemoryProperties memory_properties)
{
    capture_memory_properties_ = memory_properties;
}

VkPhysicalDeviceMemoryProperties* TrackedVkPhysicalDeviceInfo::GetCaptureDevicePhysicalMemoryProperties()
{
    return &capture_memory_properties_;
}

const VkPhysicalDeviceMemoryProperties* TrackedVkPhysicalDeviceInfo::GetCaptureDevicePhysicalMemoryProperties() const
{
    return &capture_memory_properties_;
}

void TrackedVkPhysicalDeviceInfo::SetReplayDevicePhysicalMemoryProperties(
    VkPhysicalDeviceMemoryProperties memory_properties)
{
    replay_memory_properties_ = memory_properties;
}

VkPhysicalDeviceMemoryProperties* TrackedVkPhysicalDeviceInfo::GetReplayDevicePhysicalMemoryProperties()
{
    return &replay_memory_properties_;
}

const VkPhysicalDeviceMemoryProperties* TrackedVkPhysicalDeviceInfo::GetReplayDevicePhysicalMemoryProperties() const
{
    return &replay_memory_properties_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
