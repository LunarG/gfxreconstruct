/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2020 LunarG, Inc.
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

#include "decode/vulkan_realign_allocator.h"

#include "decode/portability.h"
#include "decode/vulkan_object_info.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/logging.h"

#include <algorithm>
#include <cassert>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanRealignAllocator::VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table) :
    VulkanDefaultAllocator(), tracked_object_table_(tracked_object_table)
{
    assert(tracked_object_table != nullptr);
}

VulkanRealignAllocator::VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table,
                                               const std::string&                  custom_error_string) :
    VulkanDefaultAllocator(custom_error_string),
    tracked_object_table_(tracked_object_table)
{
    assert(tracked_object_table != nullptr);
}

VulkanRealignAllocator::VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table,
                                               std::string&&                       custom_error_string) :
    VulkanDefaultAllocator(std::move(custom_error_string)),
    tracked_object_table_(tracked_object_table)
{
    assert(tracked_object_table != nullptr);
}

VkResult VulkanRealignAllocator::AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                                const VkAllocationCallbacks* allocation_callbacks,
                                                format::HandleId             capture_id,
                                                VkDeviceMemory*              memory,
                                                MemoryData*                  allocator_data)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if ((allocate_info != nullptr) && (allocator_data != nullptr))
    {
        // allocate new memory allocation size collected from first pass by resource tracking
        auto                 tracked_memory_info   = tracked_object_table_->GetTrackedVkDeviceMemoryInfo(capture_id);
        VkMemoryAllocateInfo realign_allocate_info = *allocate_info;

        VkDeviceSize realign_size = tracked_memory_info->GetReplayMemoryAllocationSize();

        // The realign size can be zero when no resources were bound to allocation.  We skip the size override for this
        // case because vkAllocateMemory can fail with a zero allocation size.
        if (realign_size > 0)
        {
            realign_allocate_info.allocationSize = realign_size;
        }

        result = VulkanDefaultAllocator::AllocateMemory(
            &realign_allocate_info, allocation_callbacks, capture_id, memory, allocator_data);
    }

    return result;
}

VkResult VulkanRealignAllocator::BindBufferMemory(VkBuffer               buffer,
                                                  VkDeviceMemory         memory,
                                                  VkDeviceSize           memory_offset,
                                                  ResourceData           allocator_buffer_data,
                                                  MemoryData             allocator_memory_data,
                                                  VkMemoryPropertyFlags* bind_memory_properties)
{
    VkDeviceSize realign_offset = memory_offset;
    auto         resource_info  = GetResourceAllocInfo(allocator_buffer_data);

    if (resource_info != nullptr)
    {
        // Update buffer to new binding offset from first pass data collected from resource tracking.
        auto tracked_buffer_info = tracked_object_table_->GetTrackedVkResourceInfo(resource_info->capture_id);
        if (tracked_buffer_info != nullptr)
        {
            realign_offset = tracked_buffer_info->GetReplayBindOffset();
        }
    }

    return VulkanDefaultAllocator::BindBufferMemory(
        buffer, memory, realign_offset, allocator_buffer_data, allocator_memory_data, bind_memory_properties);
}

VkResult VulkanRealignAllocator::BindBufferMemory2(uint32_t                      bind_info_count,
                                                   const VkBindBufferMemoryInfo* bind_infos,
                                                   const ResourceData*           allocator_buffer_datas,
                                                   const MemoryData*             allocator_memory_datas,
                                                   VkMemoryPropertyFlags*        bind_memory_properties)
{
    std::unique_ptr<VkBindBufferMemoryInfo[]> realign_bind_infos;

    if ((allocator_buffer_datas != nullptr) && (bind_infos != nullptr))
    {
        realign_bind_infos = std::make_unique<VkBindBufferMemoryInfo[]>(bind_info_count);

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            realign_bind_infos[i] = bind_infos[i];

            auto resource_info = GetResourceAllocInfo(allocator_buffer_datas[i]);
            if (resource_info != nullptr)
            {
                // Update buffer to new binding offset from first pass data collected from resource tracking.
                auto tracked_buffer_info = tracked_object_table_->GetTrackedVkResourceInfo(resource_info->capture_id);
                if (tracked_buffer_info != nullptr)
                {
                    realign_bind_infos[i].memoryOffset = tracked_buffer_info->GetReplayBindOffset();
                }
            }
        }
    }

    return VulkanDefaultAllocator::BindBufferMemory2(bind_info_count,
                                                     realign_bind_infos.get(),
                                                     allocator_buffer_datas,
                                                     allocator_memory_datas,
                                                     bind_memory_properties);
}

VkResult VulkanRealignAllocator::BindImageMemory(VkImage                image,
                                                 VkDeviceMemory         memory,
                                                 VkDeviceSize           memory_offset,
                                                 ResourceData           allocator_image_data,
                                                 MemoryData             allocator_memory_data,
                                                 VkMemoryPropertyFlags* bind_memory_properties)
{
    VkDeviceSize realign_offset = memory_offset;
    auto         resource_info  = GetResourceAllocInfo(allocator_image_data);

    if (resource_info != nullptr)
    {
        // Update image to new binding offset from first pass data collected from resource tracking.
        auto tracked_image_info = tracked_object_table_->GetTrackedVkResourceInfo(resource_info->capture_id);
        if (tracked_image_info != nullptr)
        {
            realign_offset = tracked_image_info->GetReplayBindOffset();
        }
    }

    return VulkanDefaultAllocator::BindImageMemory(
        image, memory, realign_offset, allocator_image_data, allocator_memory_data, bind_memory_properties);
}

VkResult VulkanRealignAllocator::BindImageMemory2(uint32_t                     bind_info_count,
                                                  const VkBindImageMemoryInfo* bind_infos,
                                                  const ResourceData*          allocator_image_datas,
                                                  const MemoryData*            allocator_memory_datas,
                                                  VkMemoryPropertyFlags*       bind_memory_properties)
{
    std::unique_ptr<VkBindImageMemoryInfo[]> realign_bind_infos;

    if ((allocator_image_datas != nullptr) && (bind_infos != nullptr))
    {
        realign_bind_infos = std::make_unique<VkBindImageMemoryInfo[]>(bind_info_count);

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            realign_bind_infos[i] = bind_infos[i];

            auto resource_info = GetResourceAllocInfo(allocator_image_datas[i]);
            if (resource_info != nullptr)
            {
                // Update image to new binding offset from first pass data collected from resource tracking.
                auto tracked_image_info = tracked_object_table_->GetTrackedVkResourceInfo(resource_info->capture_id);
                if (tracked_image_info != nullptr)
                {
                    realign_bind_infos[i].memoryOffset = tracked_image_info->GetReplayBindOffset();
                }
            }
        }
    }

    return VulkanDefaultAllocator::BindImageMemory2(bind_info_count,
                                                    realign_bind_infos.get(),
                                                    allocator_image_datas,
                                                    allocator_memory_datas,
                                                    bind_memory_properties);
}

VkResult VulkanRealignAllocator::BindVideoSessionMemory(VkVideoSessionKHR                      video_session,
                                                        uint32_t                               bind_info_count,
                                                        const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                                        const ResourceData*                    allocator_session_datas,
                                                        const MemoryData*                      allocator_memory_datas,
                                                        VkMemoryPropertyFlags*                 bind_memory_properties)
{
    std::unique_ptr<VkBindVideoSessionMemoryInfoKHR[]> realign_bind_infos;

    if ((allocator_session_datas != nullptr) && (bind_infos != nullptr))
    {
        realign_bind_infos = std::make_unique<VkBindVideoSessionMemoryInfoKHR[]>(bind_info_count);

        for (uint32_t i = 0; i < bind_info_count; ++i)
        {
            realign_bind_infos[i] = bind_infos[i];

            auto resource_info = GetResourceAllocInfo(allocator_session_datas[i]);
            if (resource_info != nullptr)
            {
                // Update video seesion to new binding offset from first pass data collected from resource tracking.
                auto tracked_session_info = tracked_object_table_->GetTrackedVkResourceInfo(resource_info->capture_id);
                if (tracked_session_info != nullptr)
                {
                    realign_bind_infos[i].memoryOffset = tracked_session_info->GetReplayBindOffset();
                }
            }
        }
    }

    return VulkanDefaultAllocator::BindVideoSessionMemory(video_session,
                                                          bind_info_count,
                                                          realign_bind_infos.get(),
                                                          allocator_session_datas,
                                                          allocator_memory_datas,
                                                          bind_memory_properties);
}

VkResult VulkanRealignAllocator::MapMemory(VkDeviceMemory   memory,
                                           VkDeviceSize     offset,
                                           VkDeviceSize     size,
                                           VkMemoryMapFlags flags,
                                           void**           data,
                                           MemoryData       allocator_data)
{
    VkDeviceSize realign_offset = offset;
    auto         memory_info    = GetMemoryAllocInfo(allocator_data);

    if (memory_info != nullptr)
    {
        // Update map memory size to new allocated memory size.
        auto tracked_memory_info = tracked_object_table_->GetTrackedVkDeviceMemoryInfo(memory_info->capture_id);

        // Update map memory size.
        auto map_memories_sizes_list = tracked_memory_info->GetMappedMemorySizesList();
        if (map_memories_sizes_list.size() == 1)
        {
            size = std::max(tracked_memory_info->GetReplayMemoryAllocationSize(), size);
        }

        // Update map memory offset.
        realign_offset = FindMatchingResourceOffset(tracked_memory_info, offset);
    }

    return VulkanDefaultAllocator::MapMemory(memory, realign_offset, size, flags, data, allocator_data);
}

VkResult VulkanRealignAllocator::FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                                         const VkMappedMemoryRange* memory_ranges,
                                                         const MemoryData*          allocator_datas)
{
    std::unique_ptr<VkMappedMemoryRange[]> realign_memory_ranges =
        UpdateMappedMemoryOffsets(memory_range_count, memory_ranges, allocator_datas);

    return VulkanDefaultAllocator::FlushMappedMemoryRanges(
        memory_range_count, realign_memory_ranges.get(), allocator_datas);
}

VkResult VulkanRealignAllocator::InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                              const VkMappedMemoryRange* memory_ranges,
                                                              const MemoryData*          allocator_datas)
{
    std::unique_ptr<VkMappedMemoryRange[]> realign_memory_ranges =
        UpdateMappedMemoryOffsets(memory_range_count, memory_ranges, allocator_datas);

    return VulkanDefaultAllocator::InvalidateMappedMemoryRanges(
        memory_range_count, realign_memory_ranges.get(), allocator_datas);
}

VkResult VulkanRealignAllocator::WriteMappedMemoryRange(MemoryData     allocator_data,
                                                        uint64_t       offset,
                                                        uint64_t       size,
                                                        const uint8_t* data)
{
    VkResult     result         = VK_ERROR_MEMORY_MAP_FAILED;
    VkDeviceSize realign_offset = offset;
    auto         memory_info    = GetMemoryAllocInfo(allocator_data);

    if (memory_info != nullptr)
    {
        result = UpdateResourceData(memory_info->capture_id, allocator_data, offset, size, data);
    }
    else
    {
        GFXRECON_LOG_WARNING("VulkanRalignAllocator writing to mapped VkDeviceMemory object without allocator data");
        result = VulkanDefaultAllocator::WriteMappedMemoryRange(allocator_data, offset, size, data);
    }

    return result;
}

// Util function to find the matching offset with the resources offsets.
VkDeviceSize VulkanRealignAllocator::FindMatchingResourceOffset(const TrackedVkDeviceMemoryInfo* tracked_memory_info,
                                                                VkDeviceSize                     offset) const
{
    assert(tracked_memory_info != nullptr);

    auto tracked_bound_resources = tracked_memory_info->GetBoundResourcesList();
    assert(tracked_bound_resources != nullptr);

    for (auto entry : (*tracked_bound_resources))
    {
        assert(entry != nullptr);

        if ((offset > entry->GetTraceBindOffset()) &&
            (offset <= (entry->GetTraceBindOffset() + entry->GetReplayResourceSize())))
        {
            int64_t offset_diff = entry->GetReplayBindOffset() - entry->GetTraceBindOffset();
            offset += offset_diff;
        }
    }

    return offset;
}

VkResult VulkanRealignAllocator::UpdateResourceData(
    format::HandleId capture_id, MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data)
{
    // Find the corresponding resources offset and update fill memory to new offset.
    auto tracked_memory_info = tracked_object_table_->GetTrackedVkDeviceMemoryInfo(capture_id);

    auto         tracked_bound_resources = tracked_memory_info->GetBoundResourcesList();
    VkDeviceSize mapped_memory_offset    = offset;
    VkDeviceSize data_offset             = 0;
    uint64_t     copy_size               = 0;
    VkResult     result                  = VK_ERROR_INITIALIZATION_FAILED;

    // Loop through all the bound resources in the memory objects and update the mapped memory offset, data offset and
    // data size.
    for (auto entry : (*tracked_bound_resources))
    {
        assert(entry != nullptr);

        if (entry->GetImageFlag() == false)
        {
            VkDeviceSize resource_start  = entry->GetTraceBindOffset();
            VkDeviceSize resource_end    = entry->GetTraceBindOffset() + entry->GetReplayResourceSize();
            uint64_t     copy_data_start = offset;
            uint64_t     copy_data_end   = offset + size;

            // Ignore the resource that is outside the copy range.
            if ((copy_data_start >= resource_end) || (resource_start >= copy_data_end))
            {
                continue;
            }

            // below are the condition checks for resource is within the
            // copy data range or overlap with the copy data range,
            // if resource is within the copy data range,
            // update the copy offset, data offset and data size
            // which will be used later in memcpy
            else if ((resource_start >= copy_data_start) && (resource_end <= copy_data_end))
            {
                mapped_memory_offset = entry->GetReplayBindOffset();
                data_offset          = resource_start - copy_data_start;
                copy_size            = entry->GetReplayResourceSize();
            }
            else if ((copy_data_start > resource_start) && (copy_data_end > resource_end))
            {
                copy_size            = resource_end - copy_data_start;
                mapped_memory_offset = entry->GetReplayBindOffset() + (copy_data_start - resource_start);
            }
            else if ((resource_start > copy_data_start) && (resource_end > copy_data_end))
            {
                data_offset          = resource_start - copy_data_start;
                copy_size            = (copy_data_end)-resource_start;
                mapped_memory_offset = entry->GetReplayBindOffset();
            }
            else if ((resource_start <= copy_data_start) && (resource_end >= copy_data_end))
            {
                copy_size            = size;
                mapped_memory_offset = entry->GetReplayBindOffset() + (copy_data_start - resource_start);
            }
            else if ((resource_start < copy_data_start) && (resource_end < copy_data_end))
            {
                copy_size            = (resource_end)-copy_data_start;
                mapped_memory_offset = entry->GetReplayBindOffset() + (copy_data_start - resource_start);
            }
            else
            {
                // Fail to determine if the resource is within the copy range.
                GFXRECON_LOG_FATAL("Fill memory offset translation failed!");
            }

            result = VulkanDefaultAllocator::WriteMappedMemoryRange(
                allocator_data, mapped_memory_offset, copy_size, data + data_offset);
        }
        else
        {
            // TODO: Handle copy image subresources.
            GFXRECON_LOG_ERROR(
                "VulkanRealignAllocator::WriteMappedMemoryRange does not support updates to mapped image resources");
            result = VK_ERROR_MEMORY_MAP_FAILED;
        }
    }

    return result;
}

std::unique_ptr<VkMappedMemoryRange[]> VulkanRealignAllocator::UpdateMappedMemoryOffsets(
    uint32_t memory_range_count, const VkMappedMemoryRange* memory_ranges, const MemoryData* allocator_datas) const
{
    std::unique_ptr<VkMappedMemoryRange[]> realign_memory_ranges;

    if ((allocator_datas != nullptr) && (memory_ranges != nullptr))
    {
        realign_memory_ranges = std::make_unique<VkMappedMemoryRange[]>(memory_range_count);

        for (uint32_t i = 0; i < memory_range_count; ++i)
        {
            realign_memory_ranges[i] = memory_ranges[i];

            auto memory_info = GetMemoryAllocInfo(allocator_datas[i]);

            if (memory_info != nullptr)
            {
                // Update map memory size to new allocated memory size.
                auto tracked_memory_info = tracked_object_table_->GetTrackedVkDeviceMemoryInfo(memory_info->capture_id);

                if (tracked_memory_info != nullptr)
                {
                    // Update map memory offset.
                    realign_memory_ranges[i].offset =
                        FindMatchingResourceOffset(tracked_memory_info, memory_ranges[i].offset);
                }
            }
        }
    }

    return realign_memory_ranges;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
