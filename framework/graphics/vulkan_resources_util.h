/*
** Copyright (c) 2023 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_RESOURCES_UTIL_H
#define GFXRECON_GRAPHICS_VULKAN_RESOURCES_UTIL_H

#include "util/defines.h"
#include "generated/generated_vulkan_dispatch_table.h"

#include "vulkan/vulkan.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class VulkanResourcesUtil
{
  public:
    VulkanResourcesUtil() = delete;

    VulkanResourcesUtil(VkDevice                                device,
                        const encode::DeviceTable&              device_table,
                        const VkPhysicalDeviceMemoryProperties& memory_properties) :
        device_(device),
        device_table_(device_table), memory_properties_(memory_properties), queue_family_index_(UINT32_MAX),
        command_pool_(VK_NULL_HANDLE), command_buffer_(VK_NULL_HANDLE)
    {
        assert(device != VK_NULL_HANDLE);
        assert(memory_properties.memoryHeapCount <= VK_MAX_MEMORY_HEAPS);
        assert(memory_properties.memoryTypeCount <= VK_MAX_MEMORY_TYPES);
    }

    ~VulkanResourcesUtil()
    {
        DestroyStagingBuffer();
        DestroyCommandBuffer();
        DestroyCommandPool();
    }

    VkResult CreateStagingBuffer(VkDeviceSize size);

    uint64_t GetImageResourceSizes(VkImage                image,
                                   VkFormat               format,
                                   VkImageType            type,
                                   const VkExtent3D&      extent,
                                   uint32_t               mip_levels,
                                   uint32_t               array_layers,
                                   VkImageTiling          tiling,
                                   VkImageAspectFlagBits  aspect,
                                   std::vector<uint64_t>* mip_level_offsets    = nullptr,
                                   std::vector<uint64_t>* mip_level_sizes      = nullptr,
                                   bool                   need_staging_copy    = true,
                                   bool                   all_layers_per_level = true);

    VkResult ReadFromImageResource(VkImage                image,
                                   VkFormat               format,
                                   VkImageType            type,
                                   const VkExtent3D&      extent,
                                   uint32_t               mip_levels,
                                   uint32_t               array_layers,
                                   VkImageTiling          tiling,
                                   VkSampleCountFlags     samples,
                                   VkImageLayout          layout,
                                   uint32_t               queue_family_index,
                                   VkImageAspectFlagBits  aspect,
                                   std::vector<uint8_t>&  data,
                                   std::vector<uint64_t>& subresource_offsets,
                                   std::vector<uint64_t>& subresource_sizes,
                                   bool                   need_staging_copy    = true,
                                   bool                   all_layers_per_level = true);

    VkResult
    ReadFromBufferResource(VkBuffer buffer, uint64_t size, uint32_t queue_family_index, std::vector<uint8_t>& data);

  private:
    VkResult CreateCommandPool(uint32_t queue_family_index);

    void DestroyCommandPool();

    VkResult CreateCommandBuffer(uint32_t queue_family_index);

    void ResetCommandBuffer();

    VkResult BeginCommandBuffer();

    VkResult EndCommandBuffer();

    void DestroyCommandBuffer();

    VkResult MapStagingBuffer();

    void UnmapStagingBuffer();

    void InvalidateStagingBuffer();

    void DestroyStagingBuffer();

    void TransitionImageToSrcOptimal(VkImage image, VkImageLayout current_layout, VkImageAspectFlags aspect);

    void TransitionImageFromSrcOptimal(VkImage image, VkImageLayout new_layout, VkImageAspectFlags aspect);

    void CopyImageToBuffer(VkImage                      image,
                           const VkExtent3D&            extent,
                           uint32_t                     mip_levels,
                           uint32_t                     array_layers,
                           VkImageAspectFlags           aspect,
                           const std::vector<uint64_t>& sizes,
                           VkBuffer                     destination_buffer,
                           bool                         all_layers_per_level);

    void CopyBuffer(VkBuffer source_buffer, VkBuffer destination_buffer, uint64_t size);

    VkResult ResolveImage(VkImage           image,
                          VkFormat          format,
                          VkImageType       type,
                          const VkExtent3D& extent,
                          uint32_t          array_layers,
                          VkImageLayout     current_layout,
                          VkQueue           queue,
                          uint32_t          queue_family_index,
                          VkImage*          resolve_image,
                          VkDeviceMemory*   resolve_memory);

    VkQueue GetQueue(uint32_t queue_family_index, uint32_t queue_index);

    VkResult SubmitCommandBuffer(VkQueue queue);

    void InvalidateMappedMemoryRange(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size);

    struct StagingBufferContext
    {
        StagingBufferContext() = default;

        VkBuffer              buffer                = VK_NULL_HANDLE;
        VkDeviceMemory        memory                = VK_NULL_HANDLE;
        VkDeviceSize          size                  = 0;
        VkMemoryPropertyFlags memory_property_flags = VkMemoryPropertyFlags(0);
        void*                 mapped_ptr            = nullptr;
    };

    VkDevice                                device_;
    const encode::DeviceTable&              device_table_;
    const VkPhysicalDeviceMemoryProperties& memory_properties_;
    uint32_t                                queue_family_index_;
    VkCommandPool                           command_pool_;
    VkCommandBuffer                         command_buffer_;
    StagingBufferContext                    staging_buffer_;
};

void GetFormatAspects(VkFormat format, std::vector<VkImageAspectFlagBits>* aspects, bool* combined_depth_stencil);

VkImageAspectFlags GetFormatAspectMask(VkFormat format);

VkFormat GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect);

bool FindMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                         uint32_t                                memory_type_bits,
                         VkMemoryPropertyFlags                   desired_flags,
                         uint32_t*                               found_index,
                         VkMemoryPropertyFlags*                  found_flags);

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif /* GFXRECON_GRAPHICS_VULKAN_RESOURCES_UTIL_H */
