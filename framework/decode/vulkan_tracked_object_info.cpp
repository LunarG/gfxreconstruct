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
VkPhysicalDevice TrackedDeviceInfo::GetParentPhysicalDevice()
{
    return parent_;
}

// Set memory allocation size
void TrackedDeviceMemoryInfo::SetMemoryAllocationSize(VkDeviceSize memory_allocation_size)
{
    memory_allocation_size_ = memory_allocation_size;
}

// Get memory allocation size
VkDeviceSize TrackedDeviceMemoryInfo::GetMemoryAllocationSize()
{
    return memory_allocation_size_;
}

// Insert the mapped memory size number into the mapped memories sizes list
void TrackedDeviceMemoryInfo::InsertMappedMemorySizesList(VkDeviceSize mapped_memory_size)
{
    mapped_memories_sizes_.push_back(mapped_memory_size);
}

// Get mapped memories sizes list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetMappedMemorySizesList()
{
    return mapped_memories_sizes_;
}

// Insert the mapped memory offset number into the mapped memories offsets list
void TrackedDeviceMemoryInfo::InsertMappedMemoryOffsetsList(VkDeviceSize mapped_memory_offset)
{
    mapped_memories_offsets_.push_back(mapped_memory_offset);
}

// Get mapped memories offsets list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetMappedMemoryOffsetsList()
{
    return mapped_memories_offsets_;
}

// Insert the filled memory size number into the filled memories sizes list
void TrackedDeviceMemoryInfo::InsertFilledMemorySizesList(VkDeviceSize filled_memory_size)
{
    filled_memories_sizes_.push_back(filled_memory_size);
}

// Get filled memories sizes list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetFilledMemorySizesList()
{
    return filled_memories_sizes_;
}

// Insert the filled memory offset number into the filled memories offsets list
void TrackedDeviceMemoryInfo::InsertFilledMemoryOffsetsList(VkDeviceSize filled_memory_offset)
{
    filled_memories_offsets_.push_back(filled_memory_offset);
}

// Get filled memories offsets list
const std::vector<VkDeviceSize>& TrackedDeviceMemoryInfo::GetFilledMemoryOffsetsList()
{
    return filled_memories_offsets_;
}

// Insert the buffer capture ID into the  bound buffer ID list
void TrackedDeviceMemoryInfo::InsertBoundBufferIdList(format::HandleId buffer_id)
{
    buffers_id_.push_back(buffer_id);
}

// Get bound buffer ID list
const std::vector<format::HandleId>& TrackedDeviceMemoryInfo::GetBoundBufferIdList()
{
    return buffers_id_;
}

// Insert the image capture ID into the  bound image ID list
void TrackedDeviceMemoryInfo::InsertBoundImageIdList(format::HandleId image_id)
{
    images_id_.push_back(image_id);
}

// Get bound buffer ID list
const std::vector<format::HandleId>& TrackedDeviceMemoryInfo::GetBoundImageIdList()
{
    return images_id_;
}

// Set memory ID that this buffer bound to
void TrackedBufferInfo::SetBoundMemoryId(format::HandleId memory_id)
{
    memory_id_ = memory_id;
}

// Get memory ID that this buffer bound to
format::HandleId TrackedBufferInfo::GetBoundMemoryId()
{
    return memory_id_;
}

// Set memory property flags that this buffer bound to
void TrackedBufferInfo::SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags)
{
    memory_property_flags_ = memory_property_flags;
}

// Get memory property flags that this buffer bound to
VkMemoryPropertyFlags TrackedBufferInfo::GetBoundMemoryPropertyFlags()
{
    return memory_property_flags_;
}

// Set buffer binding offset
void TrackedBufferInfo::SetBufferBindOffset(VkDeviceSize bind_offset)
{
    bind_offset_ = bind_offset;
}

// Get buffer binding offset
VkDeviceSize TrackedBufferInfo::GetBufferBindOffset()
{
    return bind_offset_;
}

// Set buffer's queue family index
void TrackedBufferInfo::SetQueueFamilyIndex(uint32_t queue_family_index)
{
    queue_family_index_ = queue_family_index;
}

// Get buffer's queue family index
uint32_t TrackedBufferInfo::GetQueueFamilyIndex()
{
    return queue_family_index_;
}

// Set buffer creation information
void TrackedBufferInfo::SetBufferCreateInfo(VkBufferCreateInfo buffer_create_info)
{
    buffer_create_info_ = buffer_create_info;
}

// Get buffer binding offset
VkBufferCreateInfo TrackedBufferInfo::GetBufferCreateInfo()
{
    return buffer_create_info_;
}

void TrackedBufferInfo::SetMemoryRequirement(VkMemoryRequirements memory_requirement)
{
    buffer_memory_requirement_ = memory_requirement;
}

VkMemoryRequirements TrackedBufferInfo::GetMemoryRequirement()
{
    return buffer_memory_requirement_;
}

// Set memory ID that this image bound to
void TrackedImageInfo::SetBoundMemoryId(format::HandleId memory_id)
{
    memory_id_ = memory_id;
}

// Get memory ID that this image bound to
format::HandleId TrackedImageInfo::GetBoundMemoryId()
{
    return memory_id_;
}

// Set memory property flags that this image bound to
void TrackedImageInfo::SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags)
{
    memory_property_flags_ = memory_property_flags;
}

// Get memory property flags that this image bound to
VkMemoryPropertyFlags TrackedImageInfo::GetBoundMemoryPropertyFlags()
{
    return memory_property_flags_;
}

// Set image binding offset
void TrackedImageInfo::SetImageBindOffset(VkDeviceSize bind_offset)
{
    bind_offset_ = bind_offset;
}

// Get image binding offset
VkDeviceSize TrackedImageInfo::GetImageBindOffset()
{
    return bind_offset_;
}

// Set image's queue family index
void TrackedImageInfo::SetQueueFamilyIndex(uint32_t queue_family_index)
{
    queue_family_index_ = queue_family_index;
}

// Get image's queue family index
uint32_t TrackedImageInfo::GetQueueFamilyIndex()
{
    return queue_family_index_;
}

// Set image creation information
void TrackedImageInfo::SetImageCreateInfo(VkImageCreateInfo image_create_info)
{
    image_create_info_ = image_create_info;
}

// Get image binding offset
VkImageCreateInfo TrackedImageInfo::GetimageCreateInfo()
{
    return image_create_info_;
}

void TrackedImageInfo::SetMemoryRequirement(VkMemoryRequirements memory_requirement)
{
    image_memory_requirement_ = memory_requirement;
}

VkMemoryRequirements TrackedImageInfo::GetMemoryRequirement()
{
    return image_memory_requirement_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)