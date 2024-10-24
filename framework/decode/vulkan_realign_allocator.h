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

#ifndef GFXRECON_DECODE_VULKAN_REALIGN_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_REALIGN_ALLOCATOR_H

#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "util/defines.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanRealignAllocator : public VulkanDefaultAllocator
{
  public:
    VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table);

    VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table,
                           const std::string&                  custom_error_string);

    VulkanRealignAllocator(const VulkanTrackedObjectInfoTable* tracked_object_table, std::string&& custom_error_string);

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    format::HandleId             capture_id,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) override;

    virtual VkResult BindBufferMemory(VkBuffer               buffer,
                                      VkDeviceMemory         memory,
                                      VkDeviceSize           memory_offset,
                                      ResourceData           allocator_buffer_data,
                                      MemoryData             allocator_memory_data,
                                      VkMemoryPropertyFlags* bind_memory_properties) override;

    virtual VkResult BindBufferMemory2(uint32_t                      bind_info_count,
                                       const VkBindBufferMemoryInfo* bind_infos,
                                       const ResourceData*           allocator_buffer_datas,
                                       const MemoryData*             allocator_memory_datas,
                                       VkMemoryPropertyFlags*        bind_memory_properties) override;

    virtual VkResult BindImageMemory(VkImage                image,
                                     VkDeviceMemory         memory,
                                     VkDeviceSize           memory_offset,
                                     ResourceData           allocator_image_data,
                                     MemoryData             allocator_memory_data,
                                     VkMemoryPropertyFlags* bind_memory_properties) override;

    virtual VkResult BindImageMemory2(uint32_t                     bind_info_count,
                                      const VkBindImageMemoryInfo* bind_infos,
                                      const ResourceData*          allocator_image_datas,
                                      const MemoryData*            allocator_memory_datas,
                                      VkMemoryPropertyFlags*       bind_memory_properties) override;

    virtual VkResult BindVideoSessionMemory(VkVideoSessionKHR                      video_session,
                                            uint32_t                               bind_info_count,
                                            const VkBindVideoSessionMemoryInfoKHR* bind_infos,
                                            const ResourceData*                    allocator_session_datas,
                                            const MemoryData*                      allocator_memory_datas,
                                            VkMemoryPropertyFlags*                 bind_memory_properties) override;

    virtual VkResult MapMemory(VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           data,
                               MemoryData       allocator_data) override;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                             const VkMappedMemoryRange* memory_ranges,
                                             const MemoryData*          allocator_datas) override;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                  const VkMappedMemoryRange* memory_ranges,
                                                  const MemoryData*          allocator_datas) override;

    virtual VkResult
    WriteMappedMemoryRange(MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data) override;

  private:
    // Util function to find the matching offset with the resources offsets.
    VkDeviceSize FindMatchingResourceOffset(const TrackedVkDeviceMemoryInfo* tracked_memory_info,
                                            VkDeviceSize                     original_offset) const;

    // Util function to update the resource data (memcpy to mapped memory).
    VkResult UpdateResourceData(
        format::HandleId capture_id, MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data);

    VkResult CopyImageSubresourceDataAccordingToLayoutInfo(const SubresourceLayoutInfo& copy_subresource_info,
                                                           VkDeviceSize                 capture_image_data_start,
                                                           VkDeviceSize                 replay_image_data_start,
                                                           VkImageType                  image_type,
                                                           uint32_t                     array_layers,
                                                           VkFormat                     format,
                                                           VkExtent3D                   extent,
                                                           MemoryData                   allocator_data,
                                                           uint64_t                     offset,
                                                           uint64_t                     size,
                                                           const uint8_t*               data);

    std::unique_ptr<VkMappedMemoryRange[]> UpdateMappedMemoryOffsets(uint32_t                   memory_range_count,
                                                                     const VkMappedMemoryRange* memory_ranges,
                                                                     const MemoryData*          allocator_datas) const;

  private:
    const VulkanTrackedObjectInfoTable* tracked_object_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REALIGN_ALLOCATOR_H
