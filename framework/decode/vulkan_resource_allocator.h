/*
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

#ifndef GFXRECON_DECODE_VULKAN_RESOURCE_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_RESOURCE_ALLOCATOR_H

#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct DeviceMemoryInfo;
struct BufferInfo;
struct ImageInfo;

class VulkanResourceAllocator
{
  public:
    typedef uintptr_t ResourceData;
    typedef uintptr_t MemoryData;

  public:
    struct Functions
    {
        PFN_vkGetPhysicalDeviceProperties        get_physical_device_properties{ nullptr };
        PFN_vkGetPhysicalDeviceMemoryProperties  get_physical_device_memory_properties{ nullptr };
        PFN_vkGetPhysicalDeviceMemoryProperties2 get_physical_device_memory_properties2{ nullptr };
        PFN_vkAllocateMemory                     allocate_memory{ nullptr };
        PFN_vkFreeMemory                         free_memory{ nullptr };
        PFN_vkGetDeviceMemoryCommitment          get_device_memory_commitment{ nullptr };
        PFN_vkMapMemory                          map_memory{ nullptr };
        PFN_vkUnmapMemory                        unmap_memory{ nullptr };
        PFN_vkFlushMappedMemoryRanges            flush_memory_ranges{ nullptr };
        PFN_vkInvalidateMappedMemoryRanges       invalidate_memory_ranges{ nullptr };
        PFN_vkCreateBuffer                       create_buffer{ nullptr };
        PFN_vkDestroyBuffer                      destroy_buffer{ nullptr };
        PFN_vkGetBufferMemoryRequirements        get_buffer_memory_requirements{ nullptr };
        PFN_vkGetBufferMemoryRequirements2       get_buffer_memory_requirements2{ nullptr };
        PFN_vkBindBufferMemory                   bind_buffer_memory{ nullptr };
        PFN_vkBindBufferMemory2                  bind_buffer_memory2{ nullptr };
        PFN_vkCmdCopyBuffer                      cmd_copy_buffer{ nullptr };
        PFN_vkCreateImage                        create_image{ nullptr };
        PFN_vkDestroyImage                       destroy_image{ nullptr };
        PFN_vkGetImageMemoryRequirements         get_image_memory_requirements{ nullptr };
        PFN_vkGetImageMemoryRequirements2        get_image_memory_requirements2{ nullptr };
        PFN_vkGetImageSubresourceLayout          get_image_subresource_layout{ nullptr };
        PFN_vkBindImageMemory                    bind_image_memory{ nullptr };
        PFN_vkBindImageMemory2                   bind_image_memory2{ nullptr };
    };

  public:
    virtual ~VulkanResourceAllocator() {}

    virtual VkResult Initialize(uint32_t                                api_version,
                                VkInstance                              instance,
                                VkPhysicalDevice                        physical_device,
                                VkDevice                                device,
                                const std::vector<std::string>&         enabled_device_extensions,
                                VkPhysicalDeviceType                    capture_device_type,
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) = 0;

    virtual void Destroy() = 0;

    virtual VkResult CreateBuffer(const VkBufferCreateInfo*    create_info,
                                  const VkAllocationCallbacks* allocation_callbacks,
                                  format::HandleId             capture_id,
                                  VkBuffer*                    buffer,
                                  ResourceData*                allocator_data) = 0;

    virtual void
    DestroyBuffer(VkBuffer buffer, const VkAllocationCallbacks* allocation_callbacks, ResourceData allocator_data) = 0;

    virtual VkResult CreateImage(const VkImageCreateInfo*     create_info,
                                 const VkAllocationCallbacks* allocation_callbacks,
                                 format::HandleId             capture_id,
                                 VkImage*                     image,
                                 ResourceData*                allocator_data) = 0;

    virtual void
    DestroyImage(VkImage image, const VkAllocationCallbacks* allocation_callbacks, ResourceData allocator_data) = 0;

    virtual void GetImageSubresourceLayout(VkImage                    image,
                                           const VkImageSubresource*  subresource,
                                           VkSubresourceLayout*       layout,
                                           const VkSubresourceLayout* original_layout,
                                           ResourceData               allocator_data) = 0;

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    format::HandleId             capture_id,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) = 0;

    virtual void
    FreeMemory(VkDeviceMemory memory, const VkAllocationCallbacks* allocation_callbacks, MemoryData allocator_data) = 0;

    virtual void GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                           VkDeviceSize*  committed_memory_in_bytes,
                                           MemoryData     allocator_data) = 0;

    virtual VkResult BindBufferMemory(VkBuffer               buffer,
                                      VkDeviceMemory         memory,
                                      VkDeviceSize           memory_offset,
                                      ResourceData           allocator_buffer_data,
                                      MemoryData             allocator_memory_data,
                                      VkMemoryPropertyFlags* bind_memory_properties) = 0;

    virtual VkResult BindBufferMemory2(uint32_t                      bind_info_count,
                                       const VkBindBufferMemoryInfo* bind_infos,
                                       const ResourceData*           allocator_buffer_datas,
                                       const MemoryData*             allocator_memory_datas,
                                       VkMemoryPropertyFlags*        bind_memory_properties) = 0;

    virtual VkResult BindImageMemory(VkImage                image,
                                     VkDeviceMemory         memory,
                                     VkDeviceSize           memory_offset,
                                     ResourceData           allocator_image_data,
                                     MemoryData             allocator_memory_data,
                                     VkMemoryPropertyFlags* bind_memory_properties) = 0;

    virtual VkResult BindImageMemory2(uint32_t                     bind_info_count,
                                      const VkBindImageMemoryInfo* bind_infos,
                                      const ResourceData*          allocator_image_datas,
                                      const MemoryData*            allocator_memory_datas,
                                      VkMemoryPropertyFlags*       bind_memory_properties) = 0;

    virtual VkResult MapMemory(VkDeviceMemory   memory,
                               VkDeviceSize     offset,
                               VkDeviceSize     size,
                               VkMemoryMapFlags flags,
                               void**           data,
                               MemoryData       allocator_data) = 0;

    virtual void UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data) = 0;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                             const VkMappedMemoryRange* memory_ranges,
                                             const MemoryData*          allocator_datas) = 0;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                  const VkMappedMemoryRange* memory_ranges,
                                                  const MemoryData*          allocator_datas) = 0;

    // Offset is relative to the start of the pointer returned by vkMapMemory.
    virtual VkResult
    WriteMappedMemoryRange(MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data) = 0;

    virtual void ReportAllocateMemoryIncompatibility(const VkMemoryAllocateInfo* allocate_info) = 0;

    virtual void ReportBindBufferIncompatibility(VkBuffer     buffer,
                                                 ResourceData allocator_resource_data,
                                                 MemoryData   allocator_memory_data) = 0;

    virtual void ReportBindBuffer2Incompatibility(uint32_t                      bind_info_count,
                                                  const VkBindBufferMemoryInfo* bind_infos,
                                                  const ResourceData*           allocator_resource_datas,
                                                  const MemoryData*             allocator_memory_datas) = 0;

    virtual void ReportBindImageIncompatibility(VkImage      image,
                                                ResourceData allocator_resource_data,
                                                MemoryData   allocator_memory_data) = 0;

    virtual void ReportBindImage2Incompatibility(uint32_t                     bind_info_count,
                                                 const VkBindImageMemoryInfo* bind_infos,
                                                 const ResourceData*          allocator_resource_datas,
                                                 const MemoryData*            allocator_memory_datas) = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_RESOURCE_ALLOCATOR_H
