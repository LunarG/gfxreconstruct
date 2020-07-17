/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2020 LunarG, Inc.
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
    VkDeviceSize FindMatchingResourceOffset(const TrackedDeviceMemoryInfo* tracked_memory_info,
                                            VkDeviceSize                   original_offset) const;

    // Util function to update the resource data (memcpy to mapped memory).
    VkResult UpdateResourceData(
        format::HandleId capture_id, MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data);

    std::unique_ptr<VkMappedMemoryRange[]> UpdateMappedMemoryOffsets(uint32_t                   memory_range_count,
                                                                     const VkMappedMemoryRange* memory_ranges,
                                                                     const MemoryData*          allocator_datas) const;

  private:
    const VulkanTrackedObjectInfoTable* tracked_object_table_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REALIGN_ALLOCATOR_H
