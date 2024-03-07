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
    enum CopyBufferImageDirection
    {
        kBufferToImage = 0,
        kImageToBuffer
    };

  public:
    VulkanResourcesUtil() = delete;

    VulkanResourcesUtil(VkDevice                                device,
                        VkPhysicalDevice                        physical_device,
                        const encode::VulkanDeviceTable&        device_table,
                        const encode::VulkanInstanceTable&      instance_table,
                        const VkPhysicalDeviceMemoryProperties& memory_properties) :
        device_(device),
        physical_device_(physical_device), device_table_(device_table), instance_table_(instance_table),
        memory_properties_(memory_properties), queue_family_index_(UINT32_MAX), command_pool_(VK_NULL_HANDLE),
        command_buffer_(VK_NULL_HANDLE)
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

    // This function creates a staging buffer that will be used by the ReadFromImageResourceStaging() and
    // ReadFromBufferResource() functions. It is not necessary to do so but can be useful when dumping multiple
    // resource and the size of the biggest staging buffer necessary is known in advance.
    VkResult CreateStagingBuffer(VkDeviceSize size);

    // Will return the size requirements and offsets for each subresource contained in the specified image.
    // Sizes and offsets are calculated in such a way that the each subresource will be tightly packed.
    //
    // The sizes are returned in the subresource_sizes vector and will be in the order:
    //    M0 L0 L1 ... La M1 L0 L1 ... La ... Mm L0 L1 ... La
    // Where M denotes the mip map levels and L the array layers.
    // The offsets will be returned in the subresource_offsets vector in the same manner.
    // all_layers_per_level boolean determines if all array layer per mip map level will be accounted as one.
    //
    // Return value is the total size of the image.
    uint64_t GetImageResourceSizesOptimal(VkImage                image,
                                          VkFormat               format,
                                          VkImageType            type,
                                          const VkExtent3D&      extent,
                                          uint32_t               mip_levels,
                                          uint32_t               array_layers,
                                          VkImageTiling          tiling,
                                          VkImageAspectFlagBits  aspect,
                                          std::vector<uint64_t>* subresource_offsets  = nullptr,
                                          std::vector<uint64_t>* subresource_sizes    = nullptr,
                                          bool                   all_layers_per_level = false);

    // Will return the size requirements and offsets for each subresource contained in the specified image.
    // Sizes and offsets are calculated in such a way that the each subresource will be tightly packed.
    //
    // This function will use texel size values from the Vulkan Utilities Library and is intented to be used
    // with images that can be created with Linear tiling and therefore it is possible to be accesses directly
    // without using a staging buffer.
    //
    // The sizes are returned in the subresource_sizes vector and will be in the order:
    //    M0 L0 L1 ... La M1 L0 L1 ... La ... Mm L0 L1 ... La
    // Where M denotes the mip map levels and L the array layers.
    // The offsets will be returned in the subresource_offsets vector in the same manner.
    // all_layers_per_level boolean determines if all array layer per mip map level will be accounted as one.
    //
    // Return value is the total size of the image.
    uint64_t GetImageResourceSizesLinear(VkImage                image,
                                         VkFormat               format,
                                         const VkExtent3D&      extent,
                                         uint32_t               mip_levels,
                                         uint32_t               array_layers,
                                         VkImageAspectFlagBits  aspect,
                                         std::vector<uint64_t>* subresource_offsets  = nullptr,
                                         std::vector<uint64_t>* subresource_sizes    = nullptr,
                                         bool                   all_layers_per_level = false);

    // Use this function to dump an image sub resources into data vector.
    // This function is intented to be used when accessing the image content directly is not possible
    // and a staging buffer is required.
    // subresource_offsets and subresource_sizes will be populated in the same manner as with
    // GetImageResourceSizesOptimal()
    VkResult ReadFromImageResourceStaging(VkImage                image,
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
                                          bool&                  scaling_supported,
                                          bool                   all_layers_per_level = false,
                                          float                  scale                = 1.0f);

    // Use this function to dump an image sub resources into data vector.
    // This function is intented to be used when the image content can be accessed directly and expects to received a
    // pointer to the mapped memory.
    // subresource_offsets and subresource_sizes will be populated in the same manner as
    // with GetImageResourceSizesLinear()
    void ReadFromImageResourceLinear(VkImage                image,
                                     VkFormat               format,
                                     VkImageType            type,
                                     const VkExtent3D&      extent,
                                     uint32_t               mip_levels,
                                     uint32_t               array_layers,
                                     VkImageAspectFlagBits  aspect,
                                     const void*            mapped_image_ptr,
                                     std::vector<uint8_t>&  data,
                                     std::vector<uint64_t>& subresource_offsets,
                                     std::vector<uint64_t>& subresource_sizes);

    VkResult WriteToImageResourceStaging(VkImage                      image,
                                         VkFormat                     format,
                                         VkImageType                  type,
                                         const VkExtent3D&            extent,
                                         uint32_t                     mip_levels,
                                         uint32_t                     array_layers,
                                         VkImageAspectFlagBits        aspect,
                                         VkImageLayout                layout,
                                         uint32_t                     queue_family_index,
                                         const void*                  data,
                                         const std::vector<uint64_t>& subresource_offsets,
                                         const std::vector<uint64_t>& subresource_sizes);

    // Use this function to dump the content of a buffer resource into the data vector.
    VkResult ReadFromBufferResource(
        VkBuffer buffer, uint64_t size, uint64_t offset, uint32_t queue_family_index, std::vector<uint8_t>& data);

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

    void TransitionImageToTransferOptimal(VkImage            image,
                                          VkImageLayout      current_layout,
                                          VkImageLayout      destination_layout,
                                          VkImageAspectFlags aspect,
                                          uint32_t           queue_family_index);

    void TransitionImageFromTransferOptimal(VkImage            image,
                                            VkImageLayout      old_layout,
                                            VkImageLayout      new_layout,
                                            VkImageAspectFlags aspect,
                                            uint32_t           queue_family_index);

    void CopyImageBuffer(VkImage                      image,
                         VkBuffer                     buffer,
                         const VkExtent3D&            extent,
                         uint32_t                     mip_levels,
                         uint32_t                     array_layers,
                         VkImageAspectFlags           aspect,
                         const std::vector<uint64_t>& sizes,
                         bool                         all_layers_per_level,
                         CopyBufferImageDirection     copy_direction);

    void CopyBuffer(VkBuffer source_buffer, VkBuffer destination_buffer, uint64_t size, uint64_t offset);

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

    VkResult BlitImage(VkImage               image,
                       VkFormat              format,
                       VkImageType           type,
                       const VkExtent3D&     extent,
                       VkExtent3D&           scaled_extent,
                       uint32_t              mip_levels,
                       uint32_t              array_layers,
                       VkImageAspectFlagBits aspect,
                       uint32_t              queue_family_index,
                       float                 scale,
                       VkImage&              scaled_image,
                       VkDeviceMemory&       scaled_image_mem,
                       bool&                 scaling_supported);

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
    const encode::VulkanDeviceTable&        device_table_;
    VkPhysicalDevice                        physical_device_;
    const encode::VulkanDeviceTable&        device_table_;
    const encode::VulkanInstanceTable&      instance_table_;
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
