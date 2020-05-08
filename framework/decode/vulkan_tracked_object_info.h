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

#ifndef GFXRECON_DECODE_TRACKED_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_TRACKED_VULKAN_OBJECT_INFO_H

#include "util/defines.h"
#include "format/format.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This template class stores Vulkan object capture handle ID.
// It is used as a base class for all Vulkan objects.
template <typename T>
class VulkanTrackedObjectInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() { return capture_id_; }

  private:
    typedef T        HandleType;
    format::HandleId capture_id_{ 0 }; // ID assigned to the object at capture.
};

// This class stores only the instance capture Id and replay handle Id
class TrackedInstanceInfo : public VulkanTrackedObjectInfo<VkInstance>
{
  public:
    // Set hanlde ID
    void SetHandleId(VkInstance handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkInstance GetHandleId() { return handle_; }

  private:
    // Instance handle created during first pass
    VkInstance handle_;
};

// This class stores only the physical device capture Id and replay handle Id
class TrackedPhysicalDeviceInfo : public VulkanTrackedObjectInfo<VkPhysicalDevice>
{
  public:
    // Set hanlde ID
    void SetHandleId(VkPhysicalDevice handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkPhysicalDevice GetHandleId() { return handle_; }

  private:
    // Instance handle created during first pass
    VkPhysicalDevice handle_;
};

// This class stores the tracked device information
// during the first pass of the replay.
// It is need to query the resources' new memory requirement.
class TrackedDeviceInfo : public VulkanTrackedObjectInfo<VkDevice>
{
  public:
    // Set hanlde ID
    void SetHandleId(VkDevice handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkDevice GetHandleId() { return handle_; }
    // Set physical device which is the parent of this logical device
    void SetParentPhysicalDevice(VkPhysicalDevice physical_device);

    // Get physical device which is the parent of this logical device
    VkPhysicalDevice GetParentPhysicalDevice();

  private:
    // Device handle created during first pass
    VkDevice         handle_;
    VkPhysicalDevice parent_{ VK_NULL_HANDLE };
};

// This class stores the tracked device memory information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedDeviceMemoryInfo : public VulkanTrackedObjectInfo<VkDeviceMemory>
{
  public:
    // Set memory allocation size
    void SetMemoryAllocationSize(VkDeviceSize memory_allocation_size);

    // Get memory allocation size
    VkDeviceSize GetMemoryAllocationSize();

    // Insert the mapped memory size number into the mapped memories sizes list
    void InsertMappedMemorySizesList(VkDeviceSize mapped_memory_size);

    // Get mapped memories sizes list
    const std::vector<VkDeviceSize>& GetMappedMemorySizesList();

    // Insert the mapped memory offset number into the mapped memories offsets list
    void InsertMappedMemoryOffsetsList(VkDeviceSize mapped_memory_offset);

    // Get mapped memories offsets list
    const std::vector<VkDeviceSize>& GetMappedMemoryOffsetsList();

    // Insert the filled memory size number into the filled memories sizes list
    void InsertFilledMemorySizesList(VkDeviceSize filled_memory_size);

    // Get filled memories sizes list
    const std::vector<VkDeviceSize>& GetFilledMemorySizesList();

    // Insert the filled memory offset number into the filled memories offsets list
    void InsertFilledMemoryOffsetsList(VkDeviceSize filled_memory_offset);

    // Get filled memories offsets list
    const std::vector<VkDeviceSize>& GetFilledMemoryOffsetsList();

    // Insert the buffer capture ID into the  bound buffer ID list
    void InsertBoundBufferIdList(format::HandleId buffer_id);

    // Get bound buffer ID list
    const std::vector<format::HandleId>& GetBoundBufferIdList();

    // Insert the image capture ID into the  bound image ID list
    void InsertBoundImageIdList(format::HandleId image_id);

    // Get bound buffer ID list
    const std::vector<format::HandleId>& GetBoundImageIdList();

  private:
    VkMemoryPropertyFlags property_flags{ 0 };

    // memory allocation size
    VkDeviceSize memory_allocation_size_;

    // mapped memory sizes and offsets
    std::vector<VkDeviceSize> mapped_memories_sizes_;
    std::vector<VkDeviceSize> mapped_memories_offsets_;

    // filled memory sizes and offsets
    std::vector<VkDeviceSize> filled_memories_sizes_;
    std::vector<VkDeviceSize> filled_memories_offsets_;

    // resources id bound to this memory
    std::vector<format::HandleId> buffers_id_;
    std::vector<format::HandleId> images_id_;
};

// This class stores the tracked buffer information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedBufferInfo : public VulkanTrackedObjectInfo<VkBuffer>
{
  public:
    // Set memory ID that this buffer bound to
    void SetBoundMemoryId(format::HandleId memory_id);

    // Get memory ID that this buffer bound to
    format::HandleId GetBoundMemoryId();

    // Set memory property flags that this buffer bound to
    void SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags);

    // Get memory property flags that this buffer bound to
    VkMemoryPropertyFlags GetBoundMemoryPropertyFlags();

    // Set buffer binding offset
    void SetBufferBindOffset(VkDeviceSize bind_offset);

    // Get buffer binding offset
    VkDeviceSize GetBufferBindOffset();

    // Set buffer's queue family index
    void SetQueueFamilyIndex(uint32_t queue_family_index);

    // Get buffer's queue family index
    uint32_t GetQueueFamilyIndex();

    // Set buffer creation information
    void SetBufferCreateInfo(VkBufferCreateInfo buffer_create_info);

    // Get buffer binding offset
    VkBufferCreateInfo GetBufferCreateInfo();

    // Set memory requirement of the buffer in the replay device
    void SetMemoryRequirement(VkMemoryRequirements memory_requirement);

    // Get memory requirement of the buffer in the replay device
    VkMemoryRequirements GetMemoryRequirement();

    // Set hanlde ID
    void SetHandleId(VkBuffer handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkBuffer GetHandleId() { return handle_; }

  private:
    format::HandleId      memory_id_;
    VkMemoryPropertyFlags memory_property_flags_{ 0 };
    VkDeviceSize          bind_offset_{ 0 };
    uint32_t              queue_family_index_{ 0 };

    VkBuffer handle_;

    // Buffer create info (buffer size etc)
    VkBufferCreateInfo buffer_create_info_;

    // Buffer new memory requirement
    VkMemoryRequirements buffer_memory_requirement_;
};

// This class stores the tracked image information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedImageInfo : public VulkanTrackedObjectInfo<VkImage>
{
  public:
    // Set memory ID that this image bound to
    void SetBoundMemoryId(format::HandleId memory_id);

    // Get memory ID that this image bound to
    format::HandleId GetBoundMemoryId();

    // Set memory property flags that this image bound to
    void SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags);

    // Get memory property flags that this image bound to
    VkMemoryPropertyFlags GetBoundMemoryPropertyFlags();

    // Set image binding offset
    void SetImageBindOffset(VkDeviceSize bind_offset);

    // Get image binding offset
    VkDeviceSize GetImageBindOffset();

    // Set image's queue family index
    void SetQueueFamilyIndex(uint32_t queue_family_index);

    // Get image's queue family index
    uint32_t GetQueueFamilyIndex();

    // Set image creation information
    void SetImageCreateInfo(VkImageCreateInfo image_create_info);

    // Get image binding offset
    VkImageCreateInfo GetimageCreateInfo();

    // Set memory requirement of the image in the replay device
    void SetMemoryRequirement(VkMemoryRequirements memory_requirement);

    // Get memory requirement of the image in the replay device
    VkMemoryRequirements GetMemoryRequirement();

    // Set hanlde ID
    void SetHandleId(VkImage handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkImage GetHandleId() { return handle_; }

  private:
    format::HandleId      memory_id_;
    VkMemoryPropertyFlags memory_property_flags_{ 0 };
    VkDeviceSize          bind_offset_{ 0 };
    uint32_t              queue_family_index_{ 0 };

    VkImage handle_;

    // Image create info (image size etc)
    VkImageCreateInfo image_create_info_;

    // Image new memory requirement
    VkMemoryRequirements image_memory_requirement_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_INFO_H
