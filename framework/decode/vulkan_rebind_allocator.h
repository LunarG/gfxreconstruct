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
                                const VkPhysicalDeviceMemoryProperties& capture_memory_properties,
                                const VkPhysicalDeviceMemoryProperties& replay_memory_properties,
                                const Functions&                        functions) override;

    virtual void Destroy() override;

    virtual VkResult CreateBuffer(const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
                                  const VkAllocationCallbacks*                            pAllocator,
                                  HandlePointerDecoder<VkBuffer>*                         pBuffer) override;

    virtual void DestroyBuffer(BufferInfo* buffer_info, const VkAllocationCallbacks* pAllocator) override;

    virtual VkResult CreateImage(const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
                                 const VkAllocationCallbacks*                           pAllocator,
                                 HandlePointerDecoder<VkImage>*                         pImage) override;

    virtual void DestroyImage(ImageInfo* image_info, const VkAllocationCallbacks* pAllocator) override;

    virtual VkResult AllocateMemory(const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
                                    const VkAllocationCallbacks*                              pAllocator,
                                    HandlePointerDecoder<VkDeviceMemory>*                     pMemory) override;

    virtual void FreeMemory(DeviceMemoryInfo* memory_info, const VkAllocationCallbacks* pAllocator) override;

    virtual void GetDeviceMemoryCommitment(const DeviceMemoryInfo* memory_info,
                                           VkDeviceSize*           pCommittedMemoryInBytes) override;

    virtual VkResult
    BindBufferMemory(BufferInfo* buffer_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset) override;

    virtual VkResult BindBufferMemory2(uint32_t                      bindInfoCount,
                                       const VkBindBufferMemoryInfo* pBindInfos,
                                       DeviceMemoryInfo* const*      memory_infos,
                                       BufferInfo* const*            buffer_infos) override;

    virtual VkResult
    BindImageMemory(ImageInfo* image_info, DeviceMemoryInfo* memory_info, VkDeviceSize memoryOffset) override;

    virtual VkResult BindImageMemory2(uint32_t                     bindInfoCount,
                                      const VkBindImageMemoryInfo* pBindInfos,
                                      DeviceMemoryInfo* const*     memory_infos,
                                      ImageInfo* const*            image_infos) override;

    virtual VkResult MapMemory(DeviceMemoryInfo* memory_info,
                               VkDeviceSize      offset,
                               VkDeviceSize      size,
                               VkMemoryMapFlags  flags,
                               void**            ppData) override;

    virtual void UnmapMemory(DeviceMemoryInfo* memory_info) override;

    virtual VkResult FlushMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                             const VkMappedMemoryRange* pMemoryRanges,
                                             DeviceMemoryInfo* const*   memory_infos) override;

    virtual VkResult InvalidateMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                                  const VkMappedMemoryRange* pMemoryRanges,
                                                  DeviceMemoryInfo* const*   memory_infos) override;

    virtual void WriteMappedMemoryRange(const DeviceMemoryInfo* memory_info,
                                        uint64_t                offset,
                                        uint64_t                size,
                                        const uint8_t*          data) override;

  private:
    struct MemoryAllocInfo;

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

    VkResult UpdateMappedMemoryRanges(uint32_t                   memoryRangeCount,
                                      const VkMappedMemoryRange* pMemoryRanges,
                                      DeviceMemoryInfo* const*   memory_infos,
                                      void (*update_func)(VmaAllocator, VmaAllocation, VkDeviceSize, VkDeviceSize));

    VmaMemoryUsage GetBufferMemoryUsage(VkBufferUsageFlags          buffer_usage,
                                        VkMemoryPropertyFlags       capture_properties,
                                        const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage GetImageMemoryUsage(VkImageUsageFlags           image_usage,
                                       VkImageTiling               tiling,
                                       VkMemoryPropertyFlags       capture_properties,
                                       const VkMemoryRequirements& replay_requirements);

    VmaMemoryUsage AdjustMemoryUsage(VmaMemoryUsage desired_usage, const VkMemoryRequirements& replay_requirements);

  private:
    VkDevice                         device_;
    VmaAllocator                     allocator_;
    Functions                        functions_;
    VmaVulkanFunctions               vma_functions_;
    VkPhysicalDeviceMemoryProperties capture_memory_properties_;
    VkPhysicalDeviceMemoryProperties replay_memory_properties_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_REBIND_ALLOCATOR_H
