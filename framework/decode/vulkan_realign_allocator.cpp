/*
** Copyright (c) 2020-2024 Advanced Micro Devices, Inc. All rights reserved.
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
#include "graphics/vulkan_resources_util.h"

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

// Copy part or whole data of one image subresource to target mapped memory according to its subresource layout
// info of both capture time and replay time. During the copy process, the function may adjust subresource texel
// data location according to the subresource layout difference between capture time and replay time. The function
// is used by UpdateResourceData function. The image must be a linear tiling image.
// Note:
//     multi-planar format is not supported in the following handling, and for depth/stencil format, it cannot handle
//     the case that depth and stencil aspects is stored separately by driver implementation.
//
// const SubresourceLayoutInfo& copy_subresource_info,
//         The info of the target subresource which includes the range of subresource data to be copied , it also
//         includes capture-time and replay-time subresource layout. The data range of this subresource to be copied is
//         (copy_subresource_info.subresource_data_offset, copy_subresource_info.subresource_data_size), the start of
//         the range is capture time offset which is relative to the start of image data. This range could be part or
//         whole subresource data.
//
//
// VkDeviceSize capture_image_data_start,
//         The copied subresource belong to an image which is in mapped memory, the parameter is the offset of the
//         image data start which is relative to the mapped memory, and the offset is capture time binding offset
//         which is got from trace file without any adjustment for replay memory requirement difference.
//
// VkDeviceSize replay_image_data_start,
//         The copied subresource belongs to an image which is in a mapped memory, the parameter is the offset of
//         the image data start which is relative to the mapped memory, and the offset is the image replay time
//         binding offset which is already after adjustment for replay time memory requirement difference.
//
// VkImageType image_type, uint32_t image_arraylayers, VkFormat image_format, VkExtent3D image_extent,
//         These parameters are the create info of the image which has the subresource to be copied.
//
// MemoryData allocator_data,
//         The info of the memory object for which the subresource data will be copied to, including its id and memory
//         type.
//
// uint64_t offset,size,
//         The offset and size of the mapped memory range, the offset is relative to mapped memory, it's the capture
//         time value. The three values (offset, size, data) indicate that during capture time, for mapped memory
//         range (offset, size), the content of the range is data block which is pointed by data pointer.The copied
//         subresource data is from the data block.
//
// const uint8_t* data,
//         pointer to the buffer which is data used to copy to the mapped memory range (offset, size).

VkResult VulkanRealignAllocator::CopyImageSubresourceDataAccordingToLayoutInfo(
    const SubresourceLayoutInfo& copy_subresource_info,
    VkDeviceSize                 capture_image_data_start,
    VkDeviceSize                 replay_image_data_start,
    VkImageType                  image_type,
    uint32_t                     image_array_layers,
    VkFormat                     image_format,
    VkExtent3D                   image_extent,
    MemoryData                   allocator_data,
    uint64_t                     offset,
    uint64_t                     size,
    const uint8_t*               data)
{
    VkResult result                  = VK_ERROR_MEMORY_MAP_FAILED;
    bool     same_subresource_layout = (copy_subresource_info.capture_image_subresource_layout.offset ==
                                    copy_subresource_info.replay_image_subresource_layout.offset) &&
                                   (copy_subresource_info.capture_image_subresource_layout.size ==
                                    copy_subresource_info.replay_image_subresource_layout.size) &&
                                   (copy_subresource_info.capture_image_subresource_layout.arrayPitch ==
                                    copy_subresource_info.replay_image_subresource_layout.arrayPitch) &&
                                   (copy_subresource_info.capture_image_subresource_layout.depthPitch ==
                                    copy_subresource_info.replay_image_subresource_layout.depthPitch) &&
                                   (copy_subresource_info.capture_image_subresource_layout.rowPitch ==
                                    copy_subresource_info.replay_image_subresource_layout.rowPitch);

    if (same_subresource_layout)
    {
        // The layout for this subresource is same between capture time and replay time. So we don't need to
        // adjust the location of texel data relative to image data start because location and size for this
        // subresource and all texel data layout within the subresource keep same between capture and replay
        // time. We just need to consider the replay time image data start is replay_image_data_start.

        result = VulkanDefaultAllocator::WriteMappedMemoryRange(
            allocator_data,
            replay_image_data_start + copy_subresource_info.subresource_data_offset,
            copy_subresource_info.subresource_data_size,
            data + capture_image_data_start + copy_subresource_info.subresource_data_offset - offset);
    }
    else
    {
        // The layout for this subresource is different between capture time and replay time. In the following
        // handling, we'll copy the rows of the subresource data one by one with memory location adjustment based
        // on subresource layout change between capture and replay time.
        //
        // Note: multi-planar format is not supported in the following handling, and for depth/stencil format,
        //       we cannot handle the case that depth and stencil aspects are stored separately by driver
        //       implementation.

        // TODO: add handling for multi-planar and the case for depth/stencil format that depth and stencil
        //      aspects are stored separately by driver implementation.

        VkDeviceSize texel_size = 0;
        bool         is_texel_block_size;
        uint16_t     block_width, block_height;

        bool is_format_supported = gfxrecon::graphics::GetImageTexelSize(
            image_format, &texel_size, &is_texel_block_size, &block_width, &block_height);

        if (!is_format_supported)
        { // The image format is not supported.
            return result;
        }

        VkDeviceSize offset_in_texel; // offset (< texel size) which is relative to texel start.
        uint32_t     x, y, z, layer;
        bool         compressed_texel_block_coordinates, padding_location;

        VkDeviceSize copyable_row_pitch_memory_size =
            std::min(copy_subresource_info.capture_image_subresource_layout.rowPitch,
                     copy_subresource_info.replay_image_subresource_layout.rowPitch);

        // This is the subresource data range to be copied, the start and end of the range are capture time offset which
        // is relative to the start of subresource data.
        VkDeviceSize copy_range_limit_start_to_subresource_start =
                         copy_subresource_info.subresource_data_offset -
                         copy_subresource_info.capture_image_subresource_layout.offset,
                     copy_range_limit_end_to_subresource_start =
                         copy_subresource_info.subresource_data_offset + copy_subresource_info.subresource_data_size -
                         copy_subresource_info.capture_image_subresource_layout.offset;

        // We'll copy the subresource data range to replay time corresponding location from
        // capture_time_row_data_offset_to_subresource_data_start. This is the capture time offset which is relative to
        // the start of the subresource data. We call it capture time location because this is the location in (or
        // determined by) trace file which is without any consideration of cross-GPU/Driver handling such as binding
        // offset adjustment for memory requirement difference or texel data location adjustment for subresource layout
        // difference.
        VkDeviceSize current_row_left_size = 0, capture_time_row_data_offset_to_subresource_data_start =
                                                    copy_range_limit_start_to_subresource_start;

        // In the following handling, we first get the texel coordicates corresponding to the capture time location
        // capture_time_row_data_offset_to_subresource_data_start, then calculate the replay time offset according to
        // the texel coordicates.
        bool result_capture_time_offset_to_coordinates =
            gfxrecon::graphics::GetTexelCoordinatesFromOffset(image_type,
                                                              image_array_layers,
                                                              image_format,
                                                              image_extent,
                                                              copy_subresource_info.capture_image_subresource_layout,
                                                              capture_time_row_data_offset_to_subresource_data_start,
                                                              &compressed_texel_block_coordinates,
                                                              &x,
                                                              &y,
                                                              &z,
                                                              &layer,
                                                              &offset_in_texel,
                                                              &padding_location,
                                                              &current_row_left_size);

        VkDeviceSize replay_time_row_data_offset_to_subresource_data_start;
        bool         result_coordinates_to_replay_time_offset =
            gfxrecon::graphics::GetOffsetFromTexelCoordinates(image_type,
                                                              image_array_layers,
                                                              image_format,
                                                              image_extent,
                                                              copy_subresource_info.replay_image_subresource_layout,
                                                              compressed_texel_block_coordinates,
                                                              x,
                                                              y,
                                                              z,
                                                              layer,
                                                              offset_in_texel,
                                                              padding_location,
                                                              &replay_time_row_data_offset_to_subresource_data_start);

        bool is_valid_row = result_capture_time_offset_to_coordinates && result_coordinates_to_replay_time_offset;

        bool result_coordinates_to_capture_time_offset = false;

        while (is_valid_row)
        {
            if (!padding_location)
            {
                result = VulkanDefaultAllocator::WriteMappedMemoryRange(
                    allocator_data,
                    replay_image_data_start + copy_subresource_info.replay_image_subresource_layout.offset +
                        replay_time_row_data_offset_to_subresource_data_start,
                    current_row_left_size,
                    data + capture_image_data_start + copy_subresource_info.capture_image_subresource_layout.offset +
                        capture_time_row_data_offset_to_subresource_data_start - offset);

                if (result != VK_SUCCESS)
                {
                    GFXRECON_LOG_ERROR("Failed to upload data to image subresource in mapped memory!");
                    break;
                }
            }

            is_valid_row = gfxrecon::graphics::NextRowTexelCoordinates(
                image_type, image_array_layers, image_format, image_extent, y, z, layer);

            if (is_valid_row)
            {
                padding_location = false; // After call NextRowTexelCoordinatesAndOffset, the location we will handle is
                                          // the start of next row, it's the location of valid texel data.

                current_row_left_size = copyable_row_pitch_memory_size;

                result_coordinates_to_replay_time_offset = gfxrecon::graphics::GetOffsetFromTexelCoordinates(
                    image_type,
                    image_array_layers,
                    image_format,
                    image_extent,
                    copy_subresource_info.replay_image_subresource_layout,
                    compressed_texel_block_coordinates,
                    0,
                    y,
                    z,
                    layer,
                    0,
                    false,
                    &replay_time_row_data_offset_to_subresource_data_start);

                result_coordinates_to_capture_time_offset = gfxrecon::graphics::GetOffsetFromTexelCoordinates(
                    image_type,
                    image_array_layers,
                    image_format,
                    image_extent,
                    copy_subresource_info.capture_image_subresource_layout,
                    compressed_texel_block_coordinates,
                    0,
                    y,
                    z,
                    layer,
                    0,
                    false,
                    &capture_time_row_data_offset_to_subresource_data_start);

                is_valid_row = result_coordinates_to_capture_time_offset && result_coordinates_to_replay_time_offset;

                if (is_valid_row)
                {
                    if ((capture_time_row_data_offset_to_subresource_data_start + current_row_left_size) >
                        copy_range_limit_end_to_subresource_start)
                    {
                        if (capture_time_row_data_offset_to_subresource_data_start >=
                            copy_range_limit_end_to_subresource_start)
                        {
                            // The row is out of copy range limit;
                            break;
                        }
                        else
                        {
                            // Part of the row is out of copy range limit;
                            current_row_left_size = copy_range_limit_end_to_subresource_start -
                                                    capture_time_row_data_offset_to_subresource_data_start;
                        }
                    }
                }
            }
        }
    }

    return result;
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
            // The resource is image and it binds to a mapped memory, the full or part image data within the range
            // (offset,size) will be updated by the following handling. According to the tiling of the image, there are
            // the following cases:
            //
            // 1. The tiling is VK_IMAGE_TILING_OPTIMAL
            //
            //    In general, target application should not select the tiling if uploading data to an image from host
            //    because how texels are laid out in memory is opaque and depends on driver implementation. In the
            //    following code, if graphic hardware or driver is different with capture-time, an error message will be
            //    output for this case and image data update will be skipped. if graphic hardware and driver is same
            //    with capture-time, image data will be updated directly without any adjustment to memory location.
            //
            // 2. The tiling is VK_IMAGE_TILING_LINEAR:
            //
            //    This is the way supported by Vulkan doc for uploading data to image in mapped memory. In the following
            //    code, if graphic hardware and driver is same with capture-time, image data will be updated directly
            //    without any adjustment to memory location. if graphic hardware and driver is different with
            //    capture-time, we'll adjust the memory location of the upload image data according to the difference of
            //    subresource memory layout between capture and replay time.
            //
            // 3. The tiling is VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT
            //
            //    If Linux DRM format modifier is DRM_FORMAT_MOD_LINEAR, the image is a linear resource, We leave a TODO
            //    comment for this case. Otherwise, an error message will be output for this case and image data update
            //    will be skipped.

            auto create_info = entry->GetImageCreateInfo();
            bool skip_update = false, update_data_without_change_memory_location = false;
            auto tracked_device_info = tracked_object_table_->GetTrackedVkDeviceInfo(entry->GetCaptureDeviceId());
            auto tracked_physical_device_info = tracked_object_table_->GetTrackedVkPhysicalDeviceInfo(
                tracked_device_info->GetCapturePhysicalDeviceId());

            if (!tracked_physical_device_info->IsGpuDriverChanged())
            {
                // Playback on same hardware/driver, the memory layout of the image is same, just update data according
                // to the memory location info in the trace file.
                update_data_without_change_memory_location = true;
            }
            else
            {
                // Playback on different hardware/driver, we need to consider how texels are laid out in memory.

                if (create_info.tiling == VK_IMAGE_TILING_OPTIMAL)
                {
                    // How texels are laid out in memory is opaque and depends on driver implementation. The case is not
                    // supported by the following handling, The image data update will be skipped with an error message
                    // output. Note, even the image subresource layout from vkGetImageSubresourceLayout is same with
                    // capture time, still no guarantee that the actual memory layout of this image is same.

                    skip_update = true;
                    GFXRECON_LOG_WARNING_ONCE("Skip uploading data to VK_IMAGE_TILING_OPTIMAL image in mapped memory, "
                                              "playback may fail or show corruption!");
                }
                else if (create_info.tiling == VK_IMAGE_TILING_LINEAR)
                {
                    // Target application update image data for linear titling image
                    if (entry->GetImageSubresourceLayoutSize() == 0)
                    {
                        update_data_without_change_memory_location = true;
                        GFXRECON_LOG_WARNING_ONCE("GPU or driver is different between capture time and replay time, no "
                                                  "image subresource layout info can be used when uploading data to "
                                                  "VK_IMAGE_TILING_LINEAR image in mapped memory, "
                                                  "playback may fail or show corruption!");
                    }
                    else
                    {
                        if (!entry->IsImageSubresourceLayoutChanged())
                        {
                            // There's no change with the subresource layout between capture and playback time, and
                            // because it's linear tiling, so how texels are laid out in memory is exactly same with
                            // capture-time. We just need to update the image data with the memory location info in
                            // trace file plus replat-time binding offset adjustment for memory requirement change.
                            update_data_without_change_memory_location = true;
                        }
                    }
                }
                else if (create_info.tiling == VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT)
                {
                    // It's linear image if match the condition that Linux DRM format modifier is
                    // DRM_FORMAT_MOD_LINEAR.

                    // TODO: Add process for the following linear image:
                    //       VkImage created with VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT and whose Linux DRM format
                    //       modifier is DRM_FORMAT_MOD_LINEAR.

                    skip_update = true;
                    GFXRECON_LOG_WARNING_ONCE("Upload data to image in mapped memory is not supported if the image "
                                              "tiling is VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT!");
                }
            }

            if (!skip_update)
            {
                if (update_data_without_change_memory_location)
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

                    VkDeviceSize copy_range_start = std::max(resource_start, copy_data_start);
                    VkDeviceSize copy_range_end   = std::min(resource_end, copy_data_end);
                    copy_size                     = copy_range_end - copy_range_start;
                    mapped_memory_offset          = entry->GetReplayBindOffset() + copy_range_start - resource_start;
                    data_offset                   = copy_range_start - copy_data_start;

                    result = VulkanDefaultAllocator::WriteMappedMemoryRange(
                        allocator_data, mapped_memory_offset, copy_size, data + data_offset);
                }
                else
                {
                    // The image subresource layout changed, we need to calculate the new memory location for
                    // the image subresource data so we can update the image. The following is why and what
                    // we need to do during the process.
                    //
                    // During capture-time, target application updates a mapped memory range (offset, size) with
                    // a data block (data, size). Assume there's an image for which its image data is located within
                    // (the case for partly overlapping is same) the range (offset,size), the image data range is
                    // (capture_image_data_start, capture_image_data_size). Note it's the offset
                    // relative to mapped memory start for capture_image_data_start.
                    //
                    // If without considering any memory requirement change, we can assume the image data range
                    // will keep same as capture_time. If considering the memory requirement change, we know
                    // that the binding offset for resource may have some change, assume the replay-time image
                    // data range for the image is (replay_image_data_start,
                    // replay_image_data_size), note it's the offset relative to mapped memory start for
                    // replay_image_data_start.
                    //
                    // So far, we only considered memory requirement change, let's further consider the
                    // subresource layout change. For the image. Image may have lots of subresource, assume one
                    // of them located at (capture_subresource_start,
                    // capture_subresource_size), during replay-time, the range is
                    // (replay_subresource_start, replay_subresource_size), please note, the
                    // offset here is relative to image data start, not relative to memory start.
                    //
                    // So far, we considered offset/size change with subresource layout, that's not enough
                    // because we also need to consider the inside of subresource: the change for rowPitch,
                    // depthPitch, arrayPitch. For one row data without any padding, it's same between
                    // capture-time and replay-time, but rowPitch, depthPitch, arrayPitch may include padding,
                    // so the location for row data may be changed between capture time and replay time. But the
                    // corresponding texel coordinates is same, in the following process, for row data, we
                    // first get its first texel coordinate from capture-time offset, then from texel
                    // coordinates to calculate its replay-time offset, then we copy the row data to its
                    // replay-time location one by one. The case for depthPitch, arrayPitch is similar.
                    //
                    // In the above info about handling, we ignored the case about part of image data
                    // and part of subresource data. The way for this tool to capture target application
                    // updating mapped memory is by page guard or memory write-watch, it's based on memory not
                    // resource, considering target application may update resource in multiple threads, it's
                    // very possible that the captured mapped memory range only include part of image data or
                    // part of subresource data, the case is also included in the following handling.

                    // capture_image_data_start and capture_image_data_end is the offset relative to
                    // memory start and the range is the whole data range of the image.
                    VkDeviceSize capture_image_data_start = entry->GetTraceBindOffset();
                    VkDeviceSize capture_image_data_end   = entry->GetTraceBindOffset() + entry->GetTraceResourceSize();

                    // copy_data_start and copy_data_end is the offset relative to memory start and the range
                    // define the aera the mapped memory data to be copied. Note, the image data could be
                    // outside/inside/overlaping the range and the range may also include other buffer/image
                    // data.
                    uint64_t copy_data_start = offset;
                    uint64_t copy_data_end   = offset + size;

                    // Get the copy destination offset which is relative to memory start. This is the replay
                    // time location which is adjusted according to replay time image/buffer memory requirement.
                    VkDeviceSize replay_image_data_start = entry->GetReplayBindOffset();

                    // Ignore the image that is outside the copy range.
                    if ((copy_data_start >= capture_image_data_end) || (capture_image_data_start >= copy_data_end))
                    {
                        continue;
                    }

                    // The image copy data range (image_copy_data_start, image_copy_data_size) is the data of this
                    // image within the memory range (offset, size). Note: the range may be full or part data of the
                    // image.
                    uint64_t image_copy_data_start = std::max(copy_data_start, capture_image_data_start);
                    uint64_t image_copy_data_size =
                        std::min(copy_data_end, capture_image_data_end) - image_copy_data_start;

                    // Get the offset of image_copy_data_start which is relative to capture_image_data_start,
                    // it should be zero if the image copy data range is from beginning of whole image data.
                    VkDeviceSize image_copy_data_start_offset_to_image_start =
                        image_copy_data_start - capture_image_data_start;

                    // Search and get all subresources which is inside or overlapped with the image copy data range
                    // (image_copy_data_start, image_copy_data_size)
                    std::vector<SubresourceLayoutInfo> subresource_layouts;
                    bool                               search_result = entry->GetImageSubresourceLayoutsInRange(
                        image_copy_data_start_offset_to_image_start, image_copy_data_size, subresource_layouts);

                    if (search_result)
                    {
                        for (auto& copy_subresource_info : subresource_layouts)
                        {
                            result =
                                CopyImageSubresourceDataAccordingToLayoutInfo(copy_subresource_info,
                                                                              capture_image_data_start,
                                                                              replay_image_data_start,
                                                                              entry->GetImageCreateInfo().imageType,
                                                                              entry->GetImageCreateInfo().arrayLayers,
                                                                              entry->GetImageCreateInfo().format,
                                                                              entry->GetImageCreateInfo().extent,
                                                                              allocator_data,
                                                                              offset,
                                                                              size,
                                                                              data);
                        }
                    }
                }
            }
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
