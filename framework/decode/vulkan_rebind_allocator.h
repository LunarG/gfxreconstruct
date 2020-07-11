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

#ifndef GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H
#define GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H

#include "decode/vulkan_resource_allocator.h"
#include "util/defines.h"

#include "vk_mem_alloc.h"

#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanRebindAllocator : public VulkanResourceAllocator
{
  public:
    VulkanRebindAllocator();

    virtual ~VulkanRebindAllocator() override;

    virtual VkResult Initialize(uint32_t                                api_version,
                                VkInstance                              instance,
                                VkPhysicalDevice                        physical_device,
                                VkDevice                                device,
                                const std::vector<std::string>&         enabled_device_extensions,
                                VkPhysicalDeviceType                    capture_device_type,
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) override;

    virtual void Destroy() override;

    virtual VkResult CreateBuffer(const VkBufferCreateInfo*    create_info,
                                  const VkAllocationCallbacks* allocation_callbacks,
                                  format::HandleId             capture_id,
                                  VkBuffer*                    buffer,
                                  ResourceData*                allocator_data) override;

    virtual void DestroyBuffer(VkBuffer                     buffer,
                               const VkAllocationCallbacks* allocation_callbacks,
                               ResourceData                 allocator_data) override;

    virtual VkResult CreateImage(const VkImageCreateInfo*     create_info,
                                 const VkAllocationCallbacks* allocation_callbacks,
                                 format::HandleId             capture_id,
                                 VkImage*                     image,
                                 ResourceData*                allocator_data) override;

    virtual void DestroyImage(VkImage                      image,
                              const VkAllocationCallbacks* allocation_callbacks,
                              ResourceData                 allocator_data) override;

    virtual void GetImageSubresourceLayout(VkImage                    image,
                                           const VkImageSubresource*  subresource,
                                           VkSubresourceLayout*       layout,
                                           const VkSubresourceLayout* original_layout,
                                           ResourceData               allocator_data) override;

    virtual VkResult AllocateMemory(const VkMemoryAllocateInfo*  allocate_info,
                                    const VkAllocationCallbacks* allocation_callbacks,
                                    format::HandleId             capture_id,
                                    VkDeviceMemory*              memory,
                                    MemoryData*                  allocator_data) override;

    virtual void FreeMemory(VkDeviceMemory               memory,
                            const VkAllocationCallbacks* allocation_callbacks,
                            MemoryData                   allocator_data) override;

    virtual void GetDeviceMemoryCommitment(VkDeviceMemory memory,
                                           VkDeviceSize*  committed_memory_in_bytes,
                                           MemoryData     allocator_data) override;

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

    virtual void UnmapMemory(VkDeviceMemory memory, MemoryData allocator_data) override;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memory_range_count,
                                             const VkMappedMemoryRange* memory_ranges,
                                             const MemoryData*          allocator_datas) override;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memory_range_count,
                                                  const VkMappedMemoryRange* memory_ranges,
                                                  const MemoryData*          allocator_datas) override;

    virtual VkResult
    WriteMappedMemoryRange(MemoryData allocator_data, uint64_t offset, uint64_t size, const uint8_t* data) override;

    virtual void ReportAllocateMemoryIncompatibility(const VkMemoryAllocateInfo* allocate_info) override;

    virtual void ReportBindBufferIncompatibility(VkBuffer     buffer,
                                                 ResourceData allocator_resource_data,
                                                 MemoryData   allocator_memory_data) override;

    virtual void ReportBindBuffer2Incompatibility(uint32_t                      bind_info_count,
                                                  const VkBindBufferMemoryInfo* bind_infos,
                                                  const ResourceData*           allocator_resource_datas,
                                                  const MemoryData*             allocator_memory_datas) override;

    virtual void ReportBindImageIncompatibility(VkImage      image,
                                                ResourceData allocator_resource_data,
                                                MemoryData   allocator_memory_data) override;

    virtual void ReportBindImage2Incompatibility(uint32_t                     bind_info_count,
                                                 const VkBindImageMemoryInfo* bind_infos,
                                                 const ResourceData*          allocator_resource_datas,
                                                 const MemoryData*            allocator_memory_datas) override;

  private:
    struct MemoryAllocInfo;

    struct SubresourceLayouts
    {
        VkImageSubresource  subresource{};
        VkSubresourceLayout original{};
        VkSubresourceLayout rebind{};
    };

    struct ResourceAllocInfo
    {
        MemoryAllocInfo* memory_info{ nullptr };
        VmaAllocation    allocation{ VK_NULL_HANDLE };
        bool             is_host_visible{ false };
        void*            mapped_pointer{ nullptr };
        VkDeviceSize     original_offset{ 0 };
        VkDeviceSize     rebind_offset{ 0 };
        VkDeviceSize     size{ 0 };
        bool             is_image{ false };
        VkFlags          usage{ 0 };
        VkImageTiling    tiling{};
        bool             uses_extensions{ false };

        // Image layouts for performing mapped memory writes to linear images with different capture/replay memory
        // alignments.
        std::vector<SubresourceLayouts> layouts;
    };

    struct MemoryAllocInfo
    {
        VkDeviceSize                                     allocation_size{ 0 };
        uint32_t                                         original_index{ std::numeric_limits<uint32_t>::max() };
        bool                                             is_mapped{ false };
        VkDeviceSize                                     mapped_offset{ 0 };
        std::unique_ptr<uint8_t[]>                       original_content;
        std::unordered_map<VkBuffer, ResourceAllocInfo*> original_buffers;
        std::unordered_map<VkImage, ResourceAllocInfo*>  original_images;
    };

  private:
    void WriteBoundResource(ResourceAllocInfo* resource_alloc_info,
                            VkDeviceSize       src_offset,
                            VkDeviceSize       dst_offset,
                            VkDeviceSize       data_size,
                            const uint8_t*     data);

    // Identify sub-ranges of resources that overlap with a memory region from their original memory binding.  If the
    // resource overlapped with the original range, the src_offset is the offset from the start of the original
    // resource, the dst_offset is the offset from the start of the new resource allocation, and the data_size is the
    // region of the resource that overlaps with the original memory region.
    bool TranslateMemoryRange(const ResourceAllocInfo* resource_alloc_info,
                              VkDeviceSize             oiriginal_start,
                              VkDeviceSize             original_end,
                              VkDeviceSize*            src_offset,
                              VkDeviceSize*            dst_offset,
                              VkDeviceSize*            data_size);

    void UpdateBoundResource(ResourceAllocInfo* resource_alloc_info,
                             VkDeviceSize       write_start,
                             VkDeviceSize       write_end,
                             const uint8_t*     data);

    VkResult UpdateMappedMemoryRange(ResourceAllocInfo* resource_alloc_info,
                                     VkDeviceSize       oiriginal_start,
                                     VkDeviceSize       original_end,
                                     void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize));

    VkResult UpdateMappedMemoryRanges(uint32_t                   memory_range_count,
                                      const VkMappedMemoryRange* memory_ranges,
                                      const MemoryData*          allocator_datas,
                                      void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize));

    VmaMemoryUsage GetBufferMemoryUsage(VkBufferUsageFlags          buffer_usage,
                                        VkMemoryPropertyFlags       capture_properties,
                                        const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage GetImageMemoryUsage(VkImageUsageFlags           image_usage,
                                       VkImageTiling               tiling,
                                       VkMemoryPropertyFlags       capture_properties,
                                       const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage AdjustMemoryUsage(VmaMemoryUsage desired_usage, const VkMemoryRequirements& replay_requirements);

    void ReportBindIncompatibility(const ResourceData* allocator_resource_datas, uint32_t resource_count);

  private:
    VkDevice                         device_;
    VmaAllocator                     allocator_;
    Functions                        functions_;
    VmaVulkanFunctions               vma_functions_;
    VkPhysicalDeviceType             capture_device_type_;
    VkPhysicalDeviceMemoryProperties capture_memory_properties_;
    VkPhysicalDeviceMemoryProperties replay_memory_properties_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H
