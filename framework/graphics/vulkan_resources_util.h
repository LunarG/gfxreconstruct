/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2024 Advanced Micro Devices, Inc. All rights reserved.
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
#include "vulkan/vulkan_core.h"

#include <vector>
#include <unordered_map>

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
                        const VkPhysicalDeviceMemoryProperties& memory_properties);

    ~VulkanResourcesUtil();

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

    //! aggregate type to group information about an image-resource
    struct ImageResource
    {
        format::HandleId   handle_id          = format::kNullHandleId;
        VkImage            image              = VK_NULL_HANDLE;
        VkFormat           format             = VK_FORMAT_UNDEFINED;
        VkImageType        type               = VK_IMAGE_TYPE_2D;
        VkExtent3D         extent             = {};
        uint32_t           level_count        = 0;
        uint32_t           layer_count        = 0;
        VkImageTiling      tiling             = VK_IMAGE_TILING_MAX_ENUM;
        VkSampleCountFlags sample_count       = 0;
        VkImageLayout      layout             = VK_IMAGE_LAYOUT_UNDEFINED;
        uint32_t           queue_family_index = 0;
        bool               external_format    = false;
        VkDeviceSize       size               = 0;

        //! optionally provide resource_size
        VkDeviceSize resource_size = 0;

        //! optionally provide sizes of sub-resources (mipmap-levels)
        const std::vector<VkDeviceSize>* level_sizes = nullptr;

        VkImageAspectFlagBits aspect               = VK_IMAGE_ASPECT_NONE;
        bool                  all_layers_per_level = false;
        float                 scale                = 1.0f;
        VkFormat              dst_format           = VK_FORMAT_UNDEFINED;
    };

    //! signature for a callback-function, providing an ImageResource and a corresponding data-pointer
    using ReadImageResourcesCallbackFn =
        std::function<void(const ImageResource& img_resource, const void* data, size_t num_bytes)>;

    /**
     * @brief   ReadImageResources processes an array of ImageResources in batches,
     *          downloads data from GPU-memory using a staging-buffer and provides that data via callback-function.
     *
     * @param   image_resources     an array of ImageResource-structs
     * @param   call_back           a callback-function, consuming data from staging-buffer
     * @param   staging_buffer_size target size for the staging-buffer in bytes. we might allocate a larger buffer,
     *                              depending on largest resource-size
     */
    VkResult ReadImageResources(const std::vector<ImageResource>&   image_resources,
                                const ReadImageResourcesCallbackFn& call_back,
                                size_t                              staging_buffer_size);

    /**
     * @brief   ReadImageResource downloads image-data from GPU-memory using a staging-buffer
     *
     * @param   image_resource  an ImageResource struct
     * @param   out_data        an output array
     */
    VkResult ReadImageResource(const ImageResource& image_resource, std::vector<uint8_t>& out_data);

    // Use this function to dump the content of a buffer resource into the data vector.
    VkResult ReadFromBufferResource(
        VkBuffer buffer, uint64_t size, uint64_t offset, uint32_t queue_family_index, std::vector<uint8_t>& data);

    struct BufferResource
    {
        format::HandleId handle_id          = format::kNullHandleId;
        VkBuffer         buffer             = VK_NULL_HANDLE;
        uint64_t         size               = 0;
        uint64_t         offset             = 0;
        uint32_t         queue_family_index = 0;
    };

    //! signature for a callback-function, providing a BufferResource and a corresponding data-pointer
    using ReadBufferResourcesCallbackFn = std::function<void(const BufferResource& buffer_resource, const void* data)>;

    /**
     * @brief   ReadBufferResources processes an array of BufferResources in batches,
     *          downloads data from GPU-memory using a staging-buffer and provides that data via callback-function.
     *
     * @param   buffer_resources    an array of BufferResource-structs
     * @param   callback            a callback-function, consuming data from staging-buffer
     * @param   staging_buffer_size target size for the staging-buffer in bytes. we might allocate a larger buffer,
     *                                   depending on largest resource-size
     */
    void ReadBufferResources(const std::vector<BufferResource>&   buffer_resources,
                             const ReadBufferResourcesCallbackFn& callback,
                             size_t                               staging_buffer_size);

    bool IsBlitSupported(VkFormat       src_format,
                         VkImageTiling  src_image_tiling,
                         VkFormat       dst_format,
                         VkImageTiling* dst_image_tiling = nullptr) const;

    bool IsScalingSupported(VkFormat          src_format,
                            VkImageTiling     src_image_tiling,
                            VkFormat          dst_format,
                            VkImageType       type,
                            const VkExtent3D& extent,
                            float             scale) const;

  private:
    VkCommandBuffer CreateCommandBufferAndBegin(uint32_t queue_family_index);

    void ResetCommandBuffer(VkCommandBuffer command_buffer);

    VkResult BeginCommandBuffer(VkCommandBuffer command_buffer);

    VkResult MapStagingBuffer();

    void UnmapStagingBuffer();

    void InvalidateStagingBuffer();

    void DestroyStagingBuffer();

    void TransitionImageToTransferOptimal(VkCommandBuffer    command_buffer,
                                          VkImage            image,
                                          VkImageLayout      current_layout,
                                          VkImageLayout      destination_layout,
                                          VkImageAspectFlags aspect,
                                          uint32_t           queue_family_index);

    void TransitionImageFromTransferOptimal(VkCommandBuffer    command_buffer,
                                            VkImage            image,
                                            VkImageLayout      old_layout,
                                            VkImageLayout      new_layout,
                                            VkImageAspectFlags aspect,
                                            uint32_t           queue_family_index);

    void CopyImageBuffer(VkCommandBuffer              command_buffer,
                         VkImage                      image,
                         VkBuffer                     buffer,
                         uint32_t                     buffer_offset,
                         const VkExtent3D&            extent,
                         uint32_t                     mip_levels,
                         uint32_t                     array_layers,
                         VkImageAspectFlags           aspect,
                         const std::vector<uint64_t>& sizes,
                         bool                         all_layers_per_level,
                         CopyBufferImageDirection     copy_direction);

    void CopyBuffer(VkCommandBuffer command_buffer,
                    VkBuffer        source_buffer,
                    VkBuffer        destination_buffer,
                    uint64_t        size,
                    uint64_t        src_offset,
                    uint64_t        dst_offset);

    VkResult ResolveImage(VkCommandBuffer   command_buffer,
                          VkImage           image,
                          VkFormat          format,
                          VkImageType       type,
                          const VkExtent3D& extent,
                          uint32_t          array_layers,
                          VkImageLayout     current_layout,
                          VkImage*          resolve_image,
                          VkDeviceMemory*   resolve_memory);

    VkQueue GetQueue(uint32_t queue_family_index, uint32_t queue_index);

    VkResult SubmitCommandBuffer(VkCommandBuffer command_buffer, VkQueue queue);

    VkResult BlitImage(VkCommandBuffer       command_buffer,
                       VkImage               image,
                       VkFormat              format,
                       VkFormat              dst_format,
                       VkImageType           type,
                       VkImageTiling         tiling,
                       const VkExtent3D&     extent,
                       const VkExtent3D&     scaled_extent,
                       uint32_t              mip_levels,
                       uint32_t              array_layers,
                       VkImageAspectFlagBits aspect,
                       uint32_t              queue_family_index,
                       float                 scale,
                       VkImage&              scaled_image,
                       VkDeviceMemory&       scaled_image_mem);

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
    const encode::VulkanInstanceTable&      instance_table_;
    const VkPhysicalDeviceMemoryProperties& memory_properties_;

    struct command_assets_t
    {
        VkCommandPool   command_pool   = VK_NULL_HANDLE;
        VkCommandBuffer command_buffer = VK_NULL_HANDLE;
    };

    // map queue-family index -> command-pool/buffer
    std::unordered_map<uint32_t, command_assets_t> command_asset_map_;
    StagingBufferContext                           staging_buffer_;

    PFN_vkSetDebugUtilsObjectNameEXT set_debug_utils_object_name_fn_ = nullptr;
};

void GetFormatAspects(VkFormat                            format,
                      std::vector<VkImageAspectFlagBits>* aspects,
                      bool*                               combined_depth_stencil = nullptr);

VkImageAspectFlags GetFormatAspectMask(VkFormat format);

VkFormat GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect);

bool FindMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                         uint32_t                                memory_type_bits,
                         VkMemoryPropertyFlags                   desired_flags,
                         uint32_t*                               found_index,
                         VkMemoryPropertyFlags*                  found_flags);

bool GetImageTexelSize(VkFormat      format,
                       VkDeviceSize* texel_size,
                       bool*         is_texel_block_size,
                       uint16_t*     block_width_pointer,
                       uint16_t*     block_height_pointer);

bool GetTexelCoordinatesFromOffset(VkImageType                imageType,
                                   uint32_t                   arrayLayers,
                                   VkFormat                   format,
                                   const VkExtent3D&          extent,
                                   const VkSubresourceLayout& subresource_layout,
                                   VkDeviceSize               offset_to_subresource_data_start,
                                   bool*                      pointer_texel_rectangle_block_coordinates,
                                   uint32_t*                  pointer_x,
                                   uint32_t*                  pointer_y,
                                   uint32_t*                  pointer_z,
                                   uint32_t*                  pointer_layer,
                                   VkDeviceSize*              pointer_offset_in_texel_or_padding,
                                   bool*                      pointer_padding_location,
                                   VkDeviceSize*              pointer_current_row_left_size);

bool GetOffsetFromTexelCoordinates(VkImageType         imageType,
                                   uint32_t            arrayLayers,
                                   VkFormat            format,
                                   const VkExtent3D&   extent,
                                   VkSubresourceLayout subresource_layout,
                                   bool                compressed_texel_block_coordinates,
                                   uint32_t            x,
                                   uint32_t            y,
                                   uint32_t            z,
                                   uint32_t            layer,
                                   VkDeviceSize        offset_in_texel_or_padding,
                                   bool                padding_location,
                                   VkDeviceSize*       offset_to_subresource_data_start);

bool NextRowTexelCoordinates(VkImageType       imageType,
                             uint32_t          arrayLayers,
                             VkFormat          format,
                             const VkExtent3D& extent,
                             uint32_t&         y,
                             uint32_t&         z,
                             uint32_t&         layer);

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)

#endif /* GFXRECON_GRAPHICS_VULKAN_RESOURCES_UTIL_H */
