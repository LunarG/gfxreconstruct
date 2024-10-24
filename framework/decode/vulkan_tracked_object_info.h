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

#ifndef GFXRECON_DECODE_TRACKED_VULKAN_OBJECT_INFO_H
#define GFXRECON_DECODE_TRACKED_VULKAN_OBJECT_INFO_H

#include "util/defines.h"
#include "format/format.h"

#include "vulkan/vulkan.h"

#include <vector>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// This class stores only the instance capture Id and replay handle Id
class TrackedVkInstanceInfo
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
class TrackedVkPhysicalDeviceInfo
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

    // Set capture device physical properties
    void SetCaptureDevicePhysicalProperties(VkPhysicalDeviceProperties properties) { capture_properties_ = properties; }

    // Get capture device physical properties
    VkPhysicalDeviceProperties* GetCaptureDevicePhysicalProperties() { return &capture_properties_; }

    // Set replay device physical properties
    void SetReplayDevicePhysicalProperties(VkPhysicalDeviceProperties properties) { replay_properties_ = properties; }

    // Get replay device physical properties
    VkPhysicalDeviceProperties* GetReplayDevicePhysicalProperties() { return &replay_properties_; }

    bool IsGpuDriverChanged() const
    {
        bool is_gpu_or_driver_changed = (capture_properties_.vendorID != replay_properties_.vendorID) ||
                                        (capture_properties_.deviceID != replay_properties_.deviceID) ||
                                        (capture_properties_.driverVersion != replay_properties_.driverVersion);
        return is_gpu_or_driver_changed;
    };

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Instance handle created during first pass
    VkPhysicalDevice handle_;

    VkPhysicalDeviceMemoryProperties capture_memory_properties_{};
    VkPhysicalDeviceMemoryProperties replay_memory_properties_{};

    VkPhysicalDeviceProperties capture_properties_{};
    VkPhysicalDeviceProperties replay_properties_{};
};

// This class stores the tracked device information
// during the first pass of the replay.
// It is need to query the resources' memory requirement on the replay device.
class TrackedVkDeviceInfo
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

    // Set capture device ID
    void SetCapturePhysicalDeviceId(format::HandleId capture_id) { capture_physical_device_id_ = capture_id; }

    // Get capture device ID
    format::HandleId GetCapturePhysicalDeviceId() const { return capture_physical_device_id_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Device handle created during first pass
    VkDevice         handle_;
    VkPhysicalDevice parent_{ VK_NULL_HANDLE };
    // capture device and replay device physical memory properties
    const VkPhysicalDeviceMemoryProperties* capture_memory_properties_{ nullptr };
    const VkPhysicalDeviceMemoryProperties* replay_memory_properties_{ nullptr };

    format::HandleId capture_physical_device_id_{ 0 };
};

typedef struct SubresourceLayoutInfo
{
    VkImageSubresource  image_subresource;
    bool                valid_capture_time = false;
    VkSubresourceLayout capture_image_subresource_layout;
    bool                valid_replay_time = false;
    VkSubresourceLayout replay_image_subresource_layout;

    // The range is defined for the image subresource data related handling,
    // It specify the actual data range which may not be whole subresource data.
    VkDeviceSize subresource_data_offset;
    VkDeviceSize subresource_data_size;
} SubresourceLayoutInfo;

// This class stores the tracked resources (buffer and image) information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedVkResourceInfo
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

    bool IsSameImageSubresourceLayout(VkSubresourceLayout* capture_image_subresource_layout,
                                      VkSubresourceLayout* image_subresource_layout_playback_time)
    {
        bool result = false;
        if ((capture_image_subresource_layout->arrayPitch == image_subresource_layout_playback_time->arrayPitch) &&
            (capture_image_subresource_layout->depthPitch == image_subresource_layout_playback_time->depthPitch) &&
            (capture_image_subresource_layout->offset == image_subresource_layout_playback_time->offset) &&
            (capture_image_subresource_layout->rowPitch == image_subresource_layout_playback_time->rowPitch) &&
            (capture_image_subresource_layout->size == image_subresource_layout_playback_time->size))
        {
            result = true;
        }
        return result;
    }

    // Set image subresource layout
    void SetImageSubresourceLayout(VkImageSubresource*  image_subresource,
                                   VkSubresourceLayout* capture_image_subresource_layout,
                                   VkSubresourceLayout* replay_image_subresource_layout)
    {
        if ((image_subresource != nullptr) && (capture_image_subresource_layout != nullptr))
        {
            SubresourceLayoutInfo subresource_layout_info;
            subresource_layout_info.image_subresource                = *image_subresource;
            subresource_layout_info.capture_image_subresource_layout = *capture_image_subresource_layout;
            subresource_layout_info.valid_capture_time               = true;
            subresource_layout_info.subresource_data_offset          = capture_image_subresource_layout->offset;
            subresource_layout_info.subresource_data_size            = capture_image_subresource_layout->size;

            if (replay_image_subresource_layout != nullptr)
            {
                subresource_layout_info.replay_image_subresource_layout = *replay_image_subresource_layout;
                subresource_layout_info.valid_replay_time               = true;
                if (!IsSameImageSubresourceLayout(capture_image_subresource_layout, replay_image_subresource_layout))
                {
                    image_subresource_layout_changed_ = true;
                }
            }

            image_subresource_layouts_[capture_image_subresource_layout->offset] = std::move(subresource_layout_info);
        }
    };

    // Check and get intersected range for test_range (test_range_offset, test_range_size) and range (range_offset,
    // range_size) Return true if two ranges are intersected, and if corresponding pointer is not nullptr, return
    // intersect range and the intersect range is full test range or not.
    bool IsIntersected(VkDeviceSize  test_range_offset,
                       VkDeviceSize  test_range_size,
                       VkDeviceSize  range_offset,
                       VkDeviceSize  range_size,
                       bool*         is_test_range_covered,
                       VkDeviceSize* intersect_offset_in,
                       VkDeviceSize* intersect_size_in)
    {
        bool         test_range_covered = false, result = false;
        VkDeviceSize intersect_offset = 0, intersect_size = 0;
        bool         outside_of_range = (test_range_offset >= (range_offset + range_size)) ||
                                ((test_range_offset + test_range_size) <= range_offset);

        if (!outside_of_range)
        {
            result           = true;
            intersect_offset = std::max(test_range_offset, range_offset);
            intersect_size =
                std::min(test_range_offset + test_range_size, range_offset + range_size) - intersect_offset;
            test_range_covered = (intersect_size == test_range_size);
        }

        if (is_test_range_covered != nullptr)
        {
            *is_test_range_covered = test_range_covered;
        }

        if (intersect_offset_in != nullptr)
        {
            *intersect_offset_in = intersect_offset;
        }

        if (intersect_size_in != nullptr)
        {
            *intersect_size_in = intersect_size;
        }

        return result;
    }

    // Get all image subresource layouts for which its part or whole subresource data is located in target image data
    // range.
    //
    // VkDeviceSize  offset_to_image_data_start
    //         The start offset of the target image data range.
    //
    // VkDeviceSize size,
    //         The size of the target image data range.
    //
    // std::vector<SubresourceLayoutInfo>& subresource_layouts
    //         The matched image subresource layouts. For any subresource X in the returned vector,
    //         X.subresource_data_offset and X.subresource_data_size is the actual range of the subresource data, the
    //         actual range may be part or whole subresource data. The whole subresource data range is
    //         (X.capture_image_subresource_layout.offset, X.capture_image_subresource_layout.size) for
    //         capture-time or (X.replay_image_subresource_layout.offset,
    //         X.replay_image_subresource_layout.size) for replay-time.
    //
    bool GetImageSubresourceLayoutsInRange(VkDeviceSize                        offset_to_image_data_start,
                                           VkDeviceSize                        size,
                                           std::vector<SubresourceLayoutInfo>& subresource_layouts)
    {
        bool result = false;
        if (image_subresource_layouts_.size() != 0)
        {
            // For all items at or after iterator_subresource_for_range_begin, the key >=offset_to_image_data_start,
            // for all items at or after iterator_subresource_for_range_end, the key >=
            // (offset_to_image_data_start+size), so for any subresource in the range from
            // iterator_subresource_for_range_begin to the item just before iterator_subresource_for_range_end, its part
            // or whole subresource data is located in target image data range.
            auto iterator_subresource_for_range_begin =
                image_subresource_layouts_.lower_bound(offset_to_image_data_start);
            auto iterator_subresource_for_range_end =
                image_subresource_layouts_.lower_bound(offset_to_image_data_start + size);

            //  we need to consider the boundary conditions for iterator_subresource_for_range_begin and check if the
            //  previous subresource data range overlapping the target range, so we include the subresource into the
            //  searching scope. we don't need to care about iterator_subresource_for_range_begin is end() or not.
            if (iterator_subresource_for_range_begin != image_subresource_layouts_.begin())
            {
                iterator_subresource_for_range_begin--;
            }

            bool         full_subresource_data = false, is_intersected = false;
            VkDeviceSize intersect_offset = 0, intersect_size = 0;

            while (iterator_subresource_for_range_begin != image_subresource_layouts_.end())
            {
                if (iterator_subresource_for_range_begin != iterator_subresource_for_range_end)
                {
                    is_intersected = IsIntersected(iterator_subresource_for_range_begin->second.subresource_data_offset,
                                                   iterator_subresource_for_range_begin->second.subresource_data_size,
                                                   offset_to_image_data_start,
                                                   size,
                                                   &full_subresource_data,
                                                   &intersect_offset,
                                                   &intersect_size);
                    if (is_intersected)
                    {
                        result = true;
                        subresource_layouts.push_back(iterator_subresource_for_range_begin->second);

                        // If target range only include part data of the subresource, we need to
                        // adjust the layout info to describe the part data.
                        if (!full_subresource_data)
                        {
                            auto& target_layout_info                   = subresource_layouts.back();
                            target_layout_info.subresource_data_offset = intersect_offset;
                            target_layout_info.subresource_data_size   = intersect_size;
                        }
                    }

                    iterator_subresource_for_range_begin++;
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }

    size_t GetImageSubresourceLayoutSize() { return image_subresource_layouts_.size(); }

    bool IsImageSubresourceLayoutChanged() { return image_subresource_layout_changed_; }

    // Set capture device ID
    void SetCaptureDeviceId(format::HandleId capture_id) { capture_device_id_ = capture_id; }

    // Get capture device ID
    format::HandleId GetCaptureDeviceId() const { return capture_device_id_; }

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

    format::HandleId capture_device_id_{ 0 };

    bool image_subresource_layout_changed_ = false;

    std::map<VkDeviceSize, SubresourceLayoutInfo> image_subresource_layouts_;
};

// This class stores the tracked device memory information
// during the first pass of the replay.
// It is accessed by replay consumer class in second pass of
// replay to support memory portability
class TrackedVkDeviceMemoryInfo
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
    void InsertBoundResourcesList(TrackedVkResourceInfo* buffer_id);

    // Get bound resource list
    std::vector<TrackedVkResourceInfo*>*       GetBoundResourcesList();
    const std::vector<TrackedVkResourceInfo*>* GetBoundResourcesList() const;

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
    std::vector<TrackedVkResourceInfo*> bound_resources_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_TRACKED_OBJECT_INFO_H
