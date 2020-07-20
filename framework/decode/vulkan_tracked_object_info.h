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

// This class stores only the instance capture Id and replay handle Id
class TrackedInstanceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set hanlde ID
    void SetHandleId(VkInstance handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkInstance GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Instance handle created during first pass
    VkInstance handle_;
};

// This class stores only the physical device capture Id and replay handle Id
class TrackedPhysicalDeviceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set hanlde ID
    void SetHandleId(VkPhysicalDevice handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkPhysicalDevice GetHandleId() const { return handle_; }
    // Set capture device physical memory properties
    void SetCaptureDevicePhysicalMemoryProperties(VkPhysicalDeviceMemoryProperties memory_properties);

    // Get capture device physical memory properties
    VkPhysicalDeviceMemoryProperties*       GetCaptureDevicePhysicalMemoryProperties();
    const VkPhysicalDeviceMemoryProperties* GetCaptureDevicePhysicalMemoryProperties() const;

    // Set replay device physical memory properties
    void SetReplayDevicePhysicalMemoryProperties(VkPhysicalDeviceMemoryProperties memory_properties);

    // Get replay device physical memory properties
    VkPhysicalDeviceMemoryProperties*       GetReplayDevicePhysicalMemoryProperties();
    const VkPhysicalDeviceMemoryProperties* GetReplayDevicePhysicalMemoryProperties() const;

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Instance handle created during first pass
    VkPhysicalDevice handle_;

    VkPhysicalDeviceMemoryProperties capture_memory_properties_{};
    VkPhysicalDeviceMemoryProperties replay_memory_properties_{};
};

// This class stores the tracked device information
// during the first pass of the replay.
// It is need to query the resources' memory requirement on the replay device.
class TrackedDeviceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set hanlde ID
    void SetHandleId(VkDevice handle_id) { handle_ = handle_id; }

    // Get handle ID
    VkDevice GetHandleId() const { return handle_; }

    // Set physical device which is the parent of this logical device
    void SetParentPhysicalDevice(VkPhysicalDevice physical_device);

    // Get physical device which is the parent of this logical device
    VkPhysicalDevice GetParentPhysicalDevice() const;

    // Set capture device physical memory properties
    void SetCaptureDevicePhysicalMemoryProperties(const VkPhysicalDeviceMemoryProperties* memory_properties);

    // Get capture device physical memory properties
    const VkPhysicalDeviceMemoryProperties* GetCaptureDevicePhysicalMemoryProperties() const;

    // Set replay device physical memory properties
    void SetReplayDevicePhysicalMemoryProperties(const VkPhysicalDeviceMemoryProperties* memory_properties);

    // Get replay device physical memory properties
    const VkPhysicalDeviceMemoryProperties* GetReplayDevicePhysicalMemoryProperties() const;

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Device handle created during first pass
    VkDevice         handle_;
    VkPhysicalDevice parent_{ VK_NULL_HANDLE };
    // capture device and replay device physical memory properties
    const VkPhysicalDeviceMemoryProperties* capture_memory_properties_{ nullptr };
    const VkPhysicalDeviceMemoryProperties* replay_memory_properties_{ nullptr };
};

// This class stores the tracked resources (buffer and image) information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedResourceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set memory ID that this buffer bound to
    void SetBoundMemoryId(format::HandleId memory_id);

    // Get memory ID that this buffer bound to
    format::HandleId GetBoundMemoryId() const;

    // Set memory property flags that this buffer bound to
    void SetBoundMemoryPropertyFlags(VkMemoryPropertyFlags memory_property_flags);

    // Get memory property flags that this buffer bound to
    VkMemoryPropertyFlags GetBoundMemoryPropertyFlags() const;

    // Set trace resource binding offset
    void SetTraceBindOffset(VkDeviceSize bind_offset);

    // Get trace resource binding offset
    VkDeviceSize GetTraceBindOffset() const;

    // Set replay resource binding offset
    void SetReplayBindOffset(VkDeviceSize bind_offset);

    // Get replay resource binding offset
    VkDeviceSize GetReplayBindOffset() const;

    // Set required size of the resource in the replay device
    void SetReplayResourceSize(VkDeviceSize size);

    // Get required size of the resource in the replay device
    VkDeviceSize GetReplayResourceSize() const;

    // Set required alignment of the resource in the replay device
    void SetReplayResourceAlignment(VkDeviceSize alignment);

    // Get required alignment of the resource in the replay device
    VkDeviceSize GetReplayResourceAlignment() const;

    // Set required memory type bit of the resource in the replay device
    void SetReplayResourceMemoryTypeBits(uint32_t memory_type_bits);

    // Get required memory type bit of the resource in the replay device
    uint32_t GetReplayResourceMemoryTypeBits() const;

    // Set required size of the resource in the trace device
    void SetTraceResourceSize(VkDeviceSize size);

    // Get required size of the resource in the trace device
    VkDeviceSize GetTraceResourceSize() const;

    // Set required alignment of the resource in the trace device
    void SetTraceResourceAlignment(VkDeviceSize alignment);

    // Get required alignment of the resource in the trace device
    VkDeviceSize GetTraceResourceAlignment() const;

    // Set required memory type bit of the resource in the trace device
    void SetTraceResourceMemoryTypeBits(uint32_t memory_type_bits);

    // Get required memory type bit of the resource in the trace device
    uint32_t GetTraceResourceMemoryTypeBits() const;

    // Set buffer's queue family index
    void SetQueueFamilyIndex(uint32_t queue_family_index);

    // Get buffer's queue family index
    uint32_t GetQueueFamilyIndex() const;

    // Set buffer replay handle ID
    void SetBufferReplayHandleId(VkBuffer handle_id) { buffer_handle_ = handle_id; }

    // Get buffer replay handle ID
    VkBuffer GetBufferReplayHandleId() const { return buffer_handle_; }

    // Set buffer creation information
    void SetBufferCreateInfo(VkBufferCreateInfo buffer_create_info);

    // Get buffer binding offset
    VkBufferCreateInfo GetBufferCreateInfo() const;

    // Set image replay handle ID
    void SetImageReplayHandleId(VkImage handle_id) { image_handle_ = handle_id; }

    // Get image replay handle ID
    VkImage GetImageReplayHandleId() const { return image_handle_; }

    // Set image creation information
    void SetImageCreateInfo(VkImageCreateInfo image_create_info);

    // Get image creation information
    VkImageCreateInfo GetImageCreateInfo() const;

    // Set image flag
    void SetImageFlag(bool flag) { is_image = flag; };

    // Get image flag
    bool GetImageFlag() const { return is_image; };

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // bound memory id and property flags
    format::HandleId      memory_id_;
    VkMemoryPropertyFlags memory_property_flags_{ 0 };

    // binding offsets
    VkDeviceSize trace_bind_offset_{ 0 };
    VkDeviceSize replay_bind_offset_{ 0 };

    // Trace memory requirement
    VkDeviceSize trace_size_{ 0 };
    VkDeviceSize trace_alignment_{ 0 };
    uint32_t     trace_memory_type_bits_{ 0 };

    // Replay memory requirement
    VkDeviceSize replay_size_{ 0 };
    VkDeviceSize replay_alignment_{ 0 };
    uint32_t     replay_memory_type_bits_{ 0 };

    // Replay queue family index
    uint32_t queue_family_index_{ 0 };

    // Buffer replay handle and create info (buffer size etc)
    VkBuffer           buffer_handle_;
    VkBufferCreateInfo buffer_create_info_;

    // Image replay handle and create info (image format etc)
    VkImage           image_handle_;
    VkImageCreateInfo image_create_info_;

    // Flag to indicate if this resource is an image (true) or a buffer (false)
    bool is_image{ false };
};

// This class stores the tracked device memory information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedDeviceMemoryInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() { return capture_id_; }

    // Set trace memory allocation size
    void SetTraceMemoryAllocationSize(VkDeviceSize memory_allocation_size);

    // Get trace memory allocation size
    VkDeviceSize GetTraceMemoryAllocationSize() const;

    // Insert the mapped memory size number into the mapped memories sizes list
    void InsertMappedMemorySizesList(VkDeviceSize mapped_memory_size);

    // Get mapped memories sizes list
    const std::vector<VkDeviceSize>& GetMappedMemorySizesList() const;

    // Insert the mapped memory offset number into the mapped memories offsets list
    void InsertMappedMemoryOffsetsList(VkDeviceSize mapped_memory_offset);

    // Get mapped memories offsets list
    const std::vector<VkDeviceSize>& GetMappedMemoryOffsetsList() const;

    // Insert the filled memory size number into the filled memories sizes list
    void InsertFilledMemorySizesList(VkDeviceSize filled_memory_size);

    // Get filled memories sizes list
    const std::vector<VkDeviceSize>& GetFilledMemorySizesList() const;

    // Insert the filled memory offset number into the filled memories offsets list
    void InsertFilledMemoryOffsetsList(VkDeviceSize filled_memory_offset);

    // Get filled memories offsets list
    const std::vector<VkDeviceSize>& GetFilledMemoryOffsetsList() const;

    // Insert resource into the bound resource list
    void InsertBoundResourcesList(TrackedResourceInfo* buffer_id);

    // Get bound resource list
    std::vector<TrackedResourceInfo*>*       GetBoundResourcesList();
    const std::vector<TrackedResourceInfo*>* GetBoundResourcesList() const;

    // Allocate replay memory allocation size by increment
    // on each resource binding call
    void AllocateReplayMemoryAllocationSize(VkDeviceSize size);

    // Get replay memory allocation size number
    VkDeviceSize GetReplayMemoryAllocationSize() const;

    // Set memory property flags
    void SetMemoryPropertyFlags(VkMemoryPropertyFlags property_flags);

    // Get memory property flags
    VkMemoryPropertyFlags GetMemoryPropertyFlags() const;

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // memory property flags in replay
    VkMemoryPropertyFlags property_flags_{ 0 };

    // memory allocation size
    VkDeviceSize trace_memory_allocation_size_{ 0 };
    VkDeviceSize replay_memory_allocation_size_{ 0 };

    // mapped memory sizes and offsets
    std::vector<VkDeviceSize> mapped_memories_sizes_;
    std::vector<VkDeviceSize> mapped_memories_offsets_;

    // filled memory sizes and offsets
    std::vector<VkDeviceSize> filled_memories_sizes_;
    std::vector<VkDeviceSize> filled_memories_offsets_;

    // a list of tracked resources (buffers and images) bound to this memory
    std::vector<TrackedResourceInfo*> bound_resources_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_INFO_H
