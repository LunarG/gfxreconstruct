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

#include "vulkan_util.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "util/logging.h"
#include "vulkan/vulkan_core.h"

#include <cstdint>
#include <cmath>
#include <chrono>

#include "vulkan_resources_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static constexpr bool IsMemoryCoherent(VkMemoryPropertyFlags property_flags)
{
    return ((property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
}

void GetFormatAspects(VkFormat format, std::vector<VkImageAspectFlagBits>* aspects, bool* combined_depth_stencil)
{
    GFXRECON_ASSERT(aspects != nullptr);

    bool combined = false;

    switch (format)
    {
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            aspects->push_back(VK_IMAGE_ASPECT_DEPTH_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_STENCIL_BIT);
            combined = true;
            break;
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            aspects->push_back(VK_IMAGE_ASPECT_DEPTH_BIT);
            break;
        case VK_FORMAT_S8_UINT:
            aspects->push_back(VK_IMAGE_ASPECT_STENCIL_BIT);
            break;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_0_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_1_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_2_BIT);
            break;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_0_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_1_BIT);
            break;
        default:
            aspects->push_back(VK_IMAGE_ASPECT_COLOR_BIT);
            break;
    }

    if (combined_depth_stencil != nullptr)
    {
        *combined_depth_stencil = combined;
    }
}

VkImageAspectFlags GetFormatAspectMask(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            return VK_IMAGE_ASPECT_DEPTH_BIT;
        case VK_FORMAT_S8_UINT:
            return VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            return VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT | VK_IMAGE_ASPECT_PLANE_2_BIT;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
            return VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

VkFormat GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect)
{
    switch (format)
    {
        // Per-aspect compatible formats as defined by the VkBufferImageCopy documentation.
        case VK_FORMAT_D16_UNORM_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                return VK_FORMAT_D16_UNORM;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        case VK_FORMAT_D24_UNORM_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                // Effectively the same format (D24 texels packed into a 32-bit word).
                return VK_FORMAT_D24_UNORM_S8_UINT;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                return VK_FORMAT_D32_SFLOAT;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        // Per-aspect/plane compatible formats as defined by the "Plane Format Compatibility Table" from the
        // Vulkan specification.
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            // All planes share the same format.
            return VK_FORMAT_R8_UNORM;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R8_UNORM;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R8G8_UNORM;
            }
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            // All planes share the same format.
            return VK_FORMAT_R10X6_UNORM_PACK16;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R10X6_UNORM_PACK16;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R10X6G10X6_UNORM_2PACK16;
            }
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            // All planes share the same format.
            return VK_FORMAT_R12X4_UNORM_PACK16;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R12X4_UNORM_PACK16;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R12X4G12X4_UNORM_2PACK16;
            }
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            // All planes share the same format.
            return VK_FORMAT_R16_UNORM;
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R16_UNORM;
            }
            else
            {
                GFXRECON_ASSERT(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R16G16_UNORM;
            }
        default:
            GFXRECON_ASSERT((aspect == VK_IMAGE_ASPECT_COLOR_BIT) || (aspect == VK_IMAGE_ASPECT_DEPTH_BIT) ||
                            (aspect == VK_IMAGE_ASPECT_STENCIL_BIT));
            return format;
    }
}

bool FindMemoryTypeIndex(const VkPhysicalDeviceMemoryProperties& memory_properties,
                         uint32_t                                memory_type_bits,
                         VkMemoryPropertyFlags                   desired_flags,
                         uint32_t*                               found_index,
                         VkMemoryPropertyFlags*                  found_flags)
{
    bool found = false;

    GFXRECON_ASSERT(memory_properties.memoryTypeCount > 0);

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((memory_type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & desired_flags) == desired_flags))
        {
            found = true;

            if (found_index != nullptr)
            {
                (*found_index) = i;
            }

            if (found_flags != nullptr)
            {
                (*found_flags) = memory_properties.memoryTypes[i].propertyFlags;
            }

            break;
        }
    }

    return found;
}

// Get the info on target image format. The function returns true if the target format
// is supported, and returns texel size and other info to the corresponding pointer if the
// pointer is not nullptr and the image format is supported.
//
// VkFormat format,
//         The target image format for which the function will return its related info.
//
// VkDeviceSize *texel_size,
//         The texel size of target image format.
//
// bool *is_texel_block_size,
//         For the target format, if the texel size is the size for texel rectangle block.
//
// uint16_t *block_width_pointer,
//         If *is_texel_block_size is true, the width of texel rectangle.
//
// uint16_t *block_height_pointer
//         If *is_texel_block_size is true, the height of texel rectangle.
//
bool GetImageTexelSize(VkFormat      format,
                       VkDeviceSize* texel_size_ptr,
                       bool*         is_texel_block_format_ptr,
                       uint16_t*     block_width_ptr,
                       uint16_t*     block_height_ptr)
{
    if (vkuFormatPlaneCount(format) > 1)
    {
        // multi-planar format is not supported.
        GFXRECON_LOG_WARNING_ONCE("The multi-planar format is not supported for the function GetImageTexelSize!");
        return false;
    }
    else
    {
        const struct VKU_FORMAT_INFO format_info = vkuGetFormatInfo(format);

        if (is_texel_block_format_ptr)
        {
            *is_texel_block_format_ptr = false;
        }

        if (format_info.texel_per_block > 1)
        {
            if (is_texel_block_format_ptr)
            {
                *is_texel_block_format_ptr = true;
            }
        }

        if (texel_size_ptr != nullptr)
        {
            *texel_size_ptr = format_info.block_size;
        }

        if (block_width_ptr != nullptr)
        {
            *block_width_ptr = static_cast<uint16_t>(format_info.block_extent.width);
        }

        if (block_height_ptr != nullptr)
        {
            *block_height_ptr = static_cast<uint16_t>(format_info.block_extent.height);
        }

        return true;
    }
}

// The function gets texel coordinates for a specific location within subresource data range. There are the following
// two cases for the location within subresource data range (The image must be a linear tiling image.):
//
//     1. The location points to a valid image texel. For this case, the coordinate (x,y,z,layer) of this texel will
//        be returned to the corresponding pointer, pointer_offset_in_texel_or_padding will return the offset which is
//        relative to the start of the texel data. For example, assume the texel size is 32 bytes for the image format,
//        if the pointer_offset_in_texel_or_padding return value 6, it means the input parameter
//        offset_to_subresource_data_start points to the texel and at the location within the texel data where the
//        offset is 6 (relative to the start of the 32 bytes texel data). pointer_padding_location will return false.
//        pointer_current_row_left_size returns the size from this location to the end of this row (only texel of this
//        row be calculated, it doesn't include any padding after valid texel data).
//
//     2. The location points to invalid image data which should be padding area within the subresource data range. For
//        this case, the texel coordinates point to the texel of which its texel data is just before the location.
//        pointer_padding_location will return true. pointer_offset_in_texel_or_padding will return the offset which is
//        relative to the start of the padding range.
//
// VkImageType imageType, uint32_t arrayLayers, VkFormat format, VkExtent3D &extent,
//     Image type, format, array layers and extent from the image create info.
//
// const VkSubresourceLayout &subresource_layout,
//     Target subresource layout info, offset_to_subresource_data_start must be in the subresource data range.
//
// VkDeviceSize offset_to_subresource_data_start
//     the location in the subresource for which the function get the corresponding coordinates.
//
// bool *pointer_texel_rectangle_block_coordinates,
//     If true, it indicate the returned coordinate (x ,y) unit is texel rectangle block.
//
// uint32_t *pointer_x, uint32_t *pointer_y, uint32_t *pointer_z, uint32_t *pointer_layer,
//     point to the returned coordinates for location offset_to_subresource_data_start.
//
// VkDeviceSize *pointer_offset_in_texel_or_padding, bool *pointer_padding_location,
//     If returned *pointer_padding_location is false, pointer_offset_in_texel_or_padding point to the returned offset
//     in target texel.
//
// VkDeviceSize *pointer_current_row_remaining_size
//     The remaining size which is the size of the range from offset_to_subresource_data_start to the row end.
//
bool GetTexelCoordinatesFromOffset(VkImageType                imageType,
                                   uint32_t                   arrayLayers,
                                   VkFormat                   format,
                                   const VkExtent3D&          extent,
                                   const VkSubresourceLayout& subresource_layout,
                                   VkDeviceSize               offset_to_subresource_data_start,
                                   bool*                      texel_rectangle_block_coordinates_ptr,
                                   uint32_t*                  x_ptr,
                                   uint32_t*                  y_ptr,
                                   uint32_t*                  z_ptr,
                                   uint32_t*                  layer_ptr,
                                   VkDeviceSize*              offset_in_texel_or_padding_ptr,
                                   bool*                      padding_location_ptr,
                                   VkDeviceSize*              current_row_remaining_size_ptr)
{
    bool         is_texel_block_size = false;
    VkDeviceSize texel_size          = 0;
    uint16_t     block_width = 0, block_height = 0;
    bool         result = GetImageTexelSize(format, &texel_size, &is_texel_block_size, &block_width, &block_height);

    if (!result)
    {
        // The image format is not supported
        return false;
    }

    bool         padding_location = false;
    uint32_t     x, y, z, layer;
    VkDeviceSize offset_in_texel_or_padding, current_row_remaining_size = 0;
    VkDeviceSize current_offset = offset_to_subresource_data_start;

    if ((arrayLayers > 1) && (subresource_layout.arrayPitch != 0))
    {
        layer          = static_cast<uint32_t>(current_offset / subresource_layout.arrayPitch);
        current_offset = current_offset % subresource_layout.arrayPitch;
        if (layer >= arrayLayers)
        {
            // offset_to_subresource_data_start is beyond the range of subresource data.
            return false;
        }
    }
    else
    {
        // Doc states the value of arrayPitch is undefined for images that were not created as arrays.
        layer = 0;
    }

    switch (imageType)
    {
        case VK_IMAGE_TYPE_3D:
            GFXRECON_ASSERT((extent.depth > 0) && (extent.height > 0) && (extent.width > 0));
            GFXRECON_ASSERT((subresource_layout.depthPitch > 0) && (subresource_layout.rowPitch > 0));

            z = static_cast<uint32_t>(current_offset / subresource_layout.depthPitch);

            if (z >= extent.depth)
            {
                // offset_to_subresource_data_start is beyond the range of subresource data. Because current
                // Vulakn specification doesn't allow VK_IMAGE_TYPE_3D for array image, so no next array layer
                // exist;
                result = false;
            }
            else
            {
                current_offset = current_offset % subresource_layout.depthPitch;

                y = static_cast<uint32_t>(current_offset / subresource_layout.rowPitch);

                current_offset = current_offset % subresource_layout.rowPitch;

                x = static_cast<uint32_t>(current_offset / texel_size);
                if (x >= extent.width)
                {
                    x                          = extent.width - 1;
                    offset_in_texel_or_padding = current_offset - static_cast<VkDeviceSize>(extent.width) * texel_size;
                    padding_location           = true;
                    current_row_remaining_size = 0;
                }
                else
                {
                    offset_in_texel_or_padding = current_offset % texel_size;
                    current_row_remaining_size = (extent.width - x) * texel_size - offset_in_texel_or_padding;
                }
            }

            break;

        case VK_IMAGE_TYPE_2D:
            GFXRECON_ASSERT((extent.height > 0) && (extent.width > 0));
            GFXRECON_ASSERT(subresource_layout.rowPitch > 0);

            z = 0; // Doc states depthPitch is defined only for 3D images.

            y              = static_cast<uint32_t>(current_offset / subresource_layout.rowPitch);
            current_offset = current_offset % subresource_layout.rowPitch;

            x = static_cast<uint32_t>(current_offset / texel_size);

            if (x >= extent.width)
            {
                x                          = extent.width - 1;
                offset_in_texel_or_padding = current_offset - static_cast<VkDeviceSize>(extent.width) * texel_size;
                padding_location           = true;
                current_row_remaining_size = 0;
            }
            else
            {
                offset_in_texel_or_padding = current_offset % texel_size;
                current_row_remaining_size = (extent.width - x) * texel_size - offset_in_texel_or_padding;
            }

            break;

        case VK_IMAGE_TYPE_1D:
            GFXRECON_ASSERT((extent.width > 0));
            z = 0;
            y = 0;

            x = static_cast<uint32_t>(current_offset / texel_size);

            if (x >= extent.width)
            {
                x                          = extent.width - 1;
                offset_in_texel_or_padding = current_offset - static_cast<VkDeviceSize>(extent.width) * texel_size;
                padding_location           = true;
                current_row_remaining_size = 0;
            }
            else
            {
                offset_in_texel_or_padding = current_offset % texel_size;
                current_row_remaining_size = (extent.width - x) * texel_size - offset_in_texel_or_padding;
            }

            break;

        default:
            return false;
            break;
    }

    if (x_ptr != nullptr)
    {
        *x_ptr = x;
    }

    if (y_ptr != nullptr)
    {
        *y_ptr = y;
    }

    if (z_ptr != nullptr)
    {
        *z_ptr = z;
    }

    if (layer_ptr != nullptr)
    {
        *layer_ptr = layer;
    }

    if (texel_rectangle_block_coordinates_ptr != nullptr)
    {
        *texel_rectangle_block_coordinates_ptr = is_texel_block_size;
    }

    if (offset_in_texel_or_padding_ptr != nullptr)
    {
        *offset_in_texel_or_padding_ptr = offset_in_texel_or_padding;
    }

    if (padding_location_ptr != nullptr)
    {
        *padding_location_ptr = padding_location;
    }

    if (current_row_remaining_size_ptr != nullptr)
    {
        *current_row_remaining_size_ptr = current_row_remaining_size;
    }

    return result;
}

// Get the offset which is relative to the start of subresource data for a location (pointed by texel
// coordinates and related values) within the subresource. The image must be a linear tiling image.
//
// VkImageType imageType, uint32_t arrayLayers, VkFormat format, VkExtent3D &extent
//     Image type, format, array layers and extent from the image create info.
//
// const VkSubresourceLayout &subresource_layout
//     Target subresource layout info.
//
// bool *pointer_compressed_texel_block_coordinates
//     If true, it indicates the coordinate (x ,y) unit is a compressed texel block otherwise it's texel coordinate.
//
// uint32_t x, y, z, layer
//     The coordinates to specify the target location in subresource data.
//
// VkDeviceSize offset_in_texel_or_padding, bool padding_location,
//     If padding_location is false, offset_in_texel_or_padding is the offset in texel, otherwise, it is the
//     offset from the target location to the start of the padding range.
//
// VkDeviceSize offset_to_subresource_data_start
//     the offset which corresponds to the target location.
//
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
                                   VkDeviceSize*       offset_to_subresource_data_start)
{
    VkDeviceSize texel_size = 0;
    bool         is_texel_block_size;
    uint16_t     block_width, block_height;
    bool         is_format_supportted =
        GetImageTexelSize(format, &texel_size, &is_texel_block_size, &block_width, &block_height);

    if (!is_format_supportted)
    {
        return false;
    }

    if (arrayLayers <= 1)
    {
        // Doc states that the value of arrayPitch is undefined for images that were not created as arrays.
        subresource_layout.arrayPitch = 0;
    }

    if (imageType != VK_IMAGE_TYPE_3D)
    {
        // Doc states depthPitch is defined only for 3D images.
        subresource_layout.depthPitch = 0;
    }

    if (is_texel_block_size && (!compressed_texel_block_coordinates))
    {
        // If the image format is compressed format and the input coordinates (x, y, z) is not compressed texel block
        // coordinates, proceed the following convertion.
        x = x / block_width;
        y = y / block_height;
    }

    VkDeviceSize offset = layer * subresource_layout.arrayPitch + z * subresource_layout.depthPitch +
                          y * subresource_layout.rowPitch + static_cast<VkDeviceSize>(x) * texel_size;

    if (padding_location)
    {
        offset += offset_in_texel_or_padding + texel_size;
    }
    else
    {
        offset += offset_in_texel_or_padding;
    }

    if (offset_to_subresource_data_start != nullptr)
    {
        *offset_to_subresource_data_start = offset;
    }

    return is_format_supportted;
}

// Get texel coordinates for next row. The input or output coordinates are texel coordinates.
// The image must be a linear tiling image and the meaning of next row in the following handling is
// defined by the subresource layout. For example, assume the image is 2d array image,
// for the last row in a image in the array, the next row will be the first row of next image in the array.
//
// VkImageType imageType, uint32_t arrayLayers, VkFormat format, VkExtent3D &extent
//     Image type, format, array layers and extent from the image create info.
//
// uint32_t& y, z, layer
//     The coordinates to specify the target location in subresource data, the function gets the next
//     row of the target location and also returns the corresponding next row coordinates to y, z,
//     layer.
//
bool NextRowTexelCoordinates(VkImageType       imageType,
                             uint32_t          arrayLayers,
                             VkFormat          format,
                             const VkExtent3D& extent,
                             uint32_t&         y,
                             uint32_t&         z,
                             uint32_t&         layer)
{
    VkDeviceSize texel_size = 0;
    bool         is_texel_block_size;
    uint16_t     block_width, block_height;
    bool         is_format_supportted =
        GetImageTexelSize(format, &texel_size, &is_texel_block_size, &block_width, &block_height);

    if (!is_format_supportted)
    {
        return false;
    }

    bool result = false;

    switch (imageType)
    {
        case VK_IMAGE_TYPE_1D:

            if ((arrayLayers > 1) && ((layer + 1) < arrayLayers))
            {
                y      = 0;
                z      = 0;
                result = true;
                layer++;
            }
            break;

        case VK_IMAGE_TYPE_2D:

            if ((y + 1) < extent.height)
            {
                y++;
                result = true;
            }
            else if ((arrayLayers > 1) && ((layer + 1) < arrayLayers))
            {
                y = 0;
                layer++;
                result = true;
            }

            break;

        case VK_IMAGE_TYPE_3D:

            if ((y + 1) < extent.height)
            {
                y++;
                result = true;
            }
            else if ((z + 1) < extent.depth)
            {
                y = 0;
                z++;
                result = true;
            }
            else
            {
                // If target app and driver implementation strictly follow Vulkan Doc, arrayLayers must be one
                // for VK_IMAGE_TYPE_3D image.
                if ((layer + 1) < arrayLayers)
                {
                    GFXRECON_LOG_WARNING_ONCE("arrayLayers in create info for the VK_IMAGE_TYPE_3D image used by "
                                              "target application is not one, "
                                              "the case is not strictly following Vulkan doc!");
                    y = 0;
                    z = 0;
                    layer++;
                    result = true;
                }
            }
            break;

        default:
            return false;
            break;
    }

    return result;
}

VulkanResourcesUtil::VulkanResourcesUtil(VkDevice                                device,
                                         VkPhysicalDevice                        physical_device,
                                         const encode::VulkanDeviceTable&        device_table,
                                         const encode::VulkanInstanceTable&      instance_table,
                                         const VkPhysicalDeviceMemoryProperties& memory_properties) :
    device_(device),
    device_table_(device_table), physical_device_(physical_device), instance_table_(instance_table),
    memory_properties_(memory_properties)
{
    GFXRECON_ASSERT(device != VK_NULL_HANDLE);
    GFXRECON_ASSERT(memory_properties.memoryHeapCount <= VK_MAX_MEMORY_HEAPS);
    GFXRECON_ASSERT(memory_properties.memoryTypeCount <= VK_MAX_MEMORY_TYPES);

    set_debug_utils_object_name_fn_ = reinterpret_cast<PFN_vkSetDebugUtilsObjectNameEXT>(
        device_table_.GetDeviceProcAddr(device_, "vkSetDebugUtilsObjectNameEXT"));
}

VulkanResourcesUtil::~VulkanResourcesUtil()
{
    DestroyStagingBuffer();

    for (const auto& [queue_family_index, command_asset] : command_asset_map_)
    {
        if (command_asset.command_buffer != VK_NULL_HANDLE)
        {
            GFXRECON_ASSERT(command_asset.command_pool != VK_NULL_HANDLE);
            device_table_.FreeCommandBuffers(device_, command_asset.command_pool, 1, &command_asset.command_buffer);
        }

        if (command_asset.command_pool != VK_NULL_HANDLE)
        {
            device_table_.DestroyCommandPool(device_, command_asset.command_pool, nullptr);
        }
    }
}

uint64_t VulkanResourcesUtil::GetImageResourceSizesOptimal(VkImage                image,
                                                           VkFormat               format,
                                                           VkImageType            type,
                                                           const VkExtent3D&      extent,
                                                           uint32_t               mip_levels,
                                                           uint32_t               array_layers,
                                                           VkImageTiling          tiling,
                                                           VkImageAspectFlagBits  aspect,
                                                           std::vector<uint64_t>* subresource_offsets,
                                                           std::vector<uint64_t>* subresource_sizes,
                                                           bool                   all_layers_per_level)
{
    GFXRECON_ASSERT(mip_levels <= 1 + floor(log2(std::max(std::max(extent.width, extent.height), extent.depth))));

    if (subresource_sizes != nullptr)
    {
        subresource_sizes->clear();
    }

    if (subresource_offsets != nullptr)
    {
        subresource_offsets->clear();
    }

    uint64_t resource_size = 0;

    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = type;
    create_info.format                = GetImageAspectFormat(format, aspect);
    create_info.extent                = extent;
    create_info.mipLevels             = 1;
    create_info.arrayLayers           = all_layers_per_level ? array_layers : 1;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = tiling;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    for (uint32_t m = 0; m < mip_levels; ++m)
    {
        create_info.extent.width  = std::max(1u, (extent.width >> m));
        create_info.extent.height = std::max(1u, (extent.height >> m));
        create_info.extent.depth  = std::max(1u, (extent.depth >> m));

        VkImage  temp_image;
        VkResult result = device_table_.CreateImage(device_, &create_info, nullptr, &temp_image);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanResourcesUtil::%s() Failed creating VkImage", __func__)

            if (subresource_offsets != nullptr)
            {
                subresource_offsets->clear();
            }

            if (subresource_sizes != nullptr)
            {
                subresource_sizes->clear();
            }

            return 0;
        }

        VkMemoryRequirements memory_requirements;
        device_table_.GetImageMemoryRequirements(device_, temp_image, &memory_requirements);

        for (uint32_t l = 0; l < array_layers; ++l)
        {
            if (subresource_offsets != nullptr)
            {
                subresource_offsets->push_back(resource_size);
            }

            if (subresource_sizes != nullptr)
            {
                subresource_sizes->push_back(memory_requirements.size);
            }

            resource_size += memory_requirements.size;

            if (all_layers_per_level)
            {
                break;
            }
        }

        device_table_.DestroyImage(device_, temp_image, nullptr);
    }

    return resource_size;
}

VkResult VulkanResourcesUtil::CreateStagingBuffer(VkDeviceSize size)
{
    GFXRECON_ASSERT(size > 0);

    if (staging_buffer_.buffer != VK_NULL_HANDLE)
    {
        if (staging_buffer_.size < size)
        {
            DestroyStagingBuffer();
        }
        else
        {
            return VK_SUCCESS;
        }
    }

    GFXRECON_ASSERT(staging_buffer_.buffer == VK_NULL_HANDLE && staging_buffer_.size == 0);

    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = size;
    create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    VkResult result = device_table_.CreateBuffer(device_, &create_info, nullptr, &staging_buffer_.buffer);
    if (result == VK_SUCCESS)
    {
        uint32_t             memory_type_index = std::numeric_limits<uint32_t>::max();
        VkMemoryRequirements memory_requirements;

        device_table_.GetBufferMemoryRequirements(device_, staging_buffer_.buffer, &memory_requirements);

        bool found = FindMemoryTypeIndex(memory_properties_,
                                         memory_requirements.memoryTypeBits,
                                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT,
                                         &memory_type_index,
                                         &staging_buffer_.memory_property_flags);
        if (!found)
        {
            // If we are here it is likely that we lack support for HOST_CACHED, fallback to COHERENT
            found = FindMemoryTypeIndex(memory_properties_,
                                        memory_requirements.memoryTypeBits,
                                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                        &memory_type_index,
                                        &staging_buffer_.memory_property_flags);
        }

        if (found)
        {
            VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            alloc_info.pNext                = nullptr;
            alloc_info.allocationSize       = memory_requirements.size;
            alloc_info.memoryTypeIndex      = memory_type_index;

            result = device_table_.AllocateMemory(device_, &alloc_info, nullptr, &staging_buffer_.memory);
            if (result == VK_SUCCESS)
            {
                device_table_.BindBufferMemory(device_, staging_buffer_.buffer, staging_buffer_.memory, 0);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to allocate staging buffer memory for resource memory snapshot");

                device_table_.DestroyBuffer(device_, staging_buffer_.buffer, nullptr);
                staging_buffer_.buffer = VK_NULL_HANDLE;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to find a memory type with host visible and host cached or coherent "
                               "properties for resource memory snapshot staging buffer creation");

            result = VK_ERROR_INITIALIZATION_FAILED;
        }

        if (result == VK_SUCCESS)
        {
            staging_buffer_.size       = size;
            staging_buffer_.mapped_ptr = nullptr;

            if (set_debug_utils_object_name_fn_ != nullptr)
            {
                VkDebugUtilsObjectNameInfoEXT object_name_info = {};
                object_name_info.sType                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
                object_name_info.objectType                    = VK_OBJECT_TYPE_BUFFER;
                object_name_info.objectHandle                  = VK_HANDLE_TO_UINT64(staging_buffer_.buffer);
                object_name_info.pObjectName                   = "VulkanResourcesUtil internal staging-buffer";
                set_debug_utils_object_name_fn_(device_, &object_name_info);
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create staging buffer for resource memory snapshot");
    }

    return result;
}

VkResult VulkanResourcesUtil::MapStagingBuffer()
{
    GFXRECON_ASSERT(staging_buffer_.buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(staging_buffer_.memory != VK_NULL_HANDLE);
    GFXRECON_ASSERT(staging_buffer_.size);

    VkResult result = VK_SUCCESS;

    if (staging_buffer_.mapped_ptr == nullptr)
    {
        result =
            device_table_.MapMemory(device_, staging_buffer_.memory, 0, VK_WHOLE_SIZE, 0, &staging_buffer_.mapped_ptr);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed mapping staging buffer");
        }
    }

    return result;
}

void VulkanResourcesUtil::UnmapStagingBuffer()
{
    if (staging_buffer_.mapped_ptr != nullptr)
    {
        GFXRECON_ASSERT(staging_buffer_.buffer != VK_NULL_HANDLE);
        GFXRECON_ASSERT(staging_buffer_.memory != VK_NULL_HANDLE);
        GFXRECON_ASSERT(staging_buffer_.size);

        device_table_.UnmapMemory(device_, staging_buffer_.memory);
        staging_buffer_.mapped_ptr = nullptr;
    }
}

void VulkanResourcesUtil::InvalidateStagingBuffer()
{
    GFXRECON_ASSERT(staging_buffer_.buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(staging_buffer_.memory != VK_NULL_HANDLE);
    GFXRECON_ASSERT(staging_buffer_.size);

    if (!IsMemoryCoherent(staging_buffer_.memory_property_flags))
    {
        GFXRECON_ASSERT(staging_buffer_.mapped_ptr != nullptr);

        const VkMappedMemoryRange range{
            VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE, nullptr, staging_buffer_.memory, 0, staging_buffer_.size
        };

        device_table_.InvalidateMappedMemoryRanges(device_, 1, &range);
    }
}

void VulkanResourcesUtil::DestroyStagingBuffer()
{
    UnmapStagingBuffer();

    if (staging_buffer_.buffer != VK_NULL_HANDLE)
    {
        device_table_.DestroyBuffer(device_, staging_buffer_.buffer, nullptr);
        staging_buffer_.buffer = VK_NULL_HANDLE;
    }

    if (staging_buffer_.memory != VK_NULL_HANDLE)
    {
        device_table_.FreeMemory(device_, staging_buffer_.memory, nullptr);
        staging_buffer_.memory = VK_NULL_HANDLE;
    }

    staging_buffer_.memory_property_flags = VkMemoryPropertyFlags(0);
    staging_buffer_.size                  = 0;
}

VkCommandBuffer VulkanResourcesUtil::CreateCommandBufferAndBegin(uint32_t queue_family_index)
{
    auto& command_asset = command_asset_map_[queue_family_index];

    if (command_asset.command_pool == VK_NULL_HANDLE)
    {
        VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
        create_info.pNext                   = nullptr;
        create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        create_info.queueFamilyIndex        = queue_family_index;

        VkResult result = device_table_.CreateCommandPool(device_, &create_info, nullptr, &command_asset.command_pool);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to create a command pool for resource memory snapshot");
            return VK_NULL_HANDLE;
        }
    }

    if (command_asset.command_buffer == VK_NULL_HANDLE)
    {
        GFXRECON_ASSERT(command_asset.command_pool != VK_NULL_HANDLE);

        VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
        alloc_info.pNext                       = nullptr;
        alloc_info.commandPool                 = command_asset.command_pool;
        alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandBufferCount          = 1;

        VkResult result = device_table_.AllocateCommandBuffers(device_, &alloc_info, &command_asset.command_buffer);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("Failed to create a command buffer for resource memory snapshot");
            return VK_NULL_HANDLE;
        }

        // Because this command buffer was not allocated through the loader, it must be assigned a dispatch table.
        *reinterpret_cast<void**>(command_asset.command_buffer) = *reinterpret_cast<void**>(device_);

        if (set_debug_utils_object_name_fn_ != nullptr)
        {
            VkDebugUtilsObjectNameInfoEXT object_name_info = {};
            object_name_info.sType                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
            object_name_info.objectType                    = VK_OBJECT_TYPE_COMMAND_BUFFER;

            // NOTE: VK_HANDLE_TO_UINT64 fails here for 32bit (while it does work for VkBuffer), open for suggestions
            object_name_info.objectHandle = (uint64_t)command_asset.command_buffer;
            object_name_info.pObjectName  = "VulkanResourcesUtil internal command-buffer";
            set_debug_utils_object_name_fn_(device_, &object_name_info);
        }
    }

    // begin + return handle
    BeginCommandBuffer(command_asset.command_buffer);
    return command_asset.command_buffer;
}

void VulkanResourcesUtil::ResetCommandBuffer(VkCommandBuffer command_buffer)
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    device_table_.ResetCommandBuffer(command_buffer, VkCommandBufferResetFlags(0));
}

VkResult VulkanResourcesUtil::BeginCommandBuffer(VkCommandBuffer command_buffer)
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    VkResult result = device_table_.BeginCommandBuffer(command_buffer, &begin_info);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to begin a command buffer for resource memory snapshot");
    }
    return result;
}

void VulkanResourcesUtil::TransitionImageToTransferOptimal(VkCommandBuffer    command_buffer,
                                                           VkImage            image,
                                                           VkImageLayout      current_layout,
                                                           VkImageLayout      destination_layout,
                                                           VkImageAspectFlags aspect,
                                                           uint32_t           queue_family_index)
{
    GFXRECON_ASSERT(image != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    VkImageMemoryBarrier memory_barrier;
    memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    memory_barrier.pNext                           = nullptr;
    memory_barrier.srcAccessMask                   = VK_ACCESS_MEMORY_WRITE_BIT;
    memory_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
    memory_barrier.oldLayout                       = current_layout;
    memory_barrier.newLayout                       = destination_layout;
    memory_barrier.srcQueueFamilyIndex             = queue_family_index;
    memory_barrier.dstQueueFamilyIndex             = queue_family_index;
    memory_barrier.image                           = image;
    memory_barrier.subresourceRange.aspectMask     = aspect;
    memory_barrier.subresourceRange.baseMipLevel   = 0;
    memory_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    memory_barrier.subresourceRange.baseArrayLayer = 0;
    memory_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    device_table_.CmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &memory_barrier);
}

void VulkanResourcesUtil::TransitionImageFromTransferOptimal(VkCommandBuffer    command_buffer,
                                                             VkImage            image,
                                                             VkImageLayout      old_layout,
                                                             VkImageLayout      new_layout,
                                                             VkImageAspectFlags aspect,
                                                             uint32_t           queue_family_index)
{
    GFXRECON_ASSERT(image != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    VkImageMemoryBarrier memory_barrier;
    memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    memory_barrier.pNext                           = nullptr;
    memory_barrier.srcQueueFamilyIndex             = queue_family_index;
    memory_barrier.dstQueueFamilyIndex             = queue_family_index;
    memory_barrier.image                           = image;
    memory_barrier.subresourceRange.aspectMask     = aspect;
    memory_barrier.subresourceRange.baseMipLevel   = 0;
    memory_barrier.subresourceRange.levelCount     = VK_REMAINING_MIP_LEVELS;
    memory_barrier.subresourceRange.baseArrayLayer = 0;
    memory_barrier.subresourceRange.layerCount     = VK_REMAINING_ARRAY_LAYERS;

    memory_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    memory_barrier.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT;
    memory_barrier.oldLayout     = old_layout;
    memory_barrier.newLayout     = new_layout;

    device_table_.CmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &memory_barrier);
}

void VulkanResourcesUtil::CopyImageBuffer(VkCommandBuffer              command_buffer,
                                          VkImage                      image,
                                          VkBuffer                     buffer,
                                          uint32_t                     buffer_offset,
                                          const VkExtent3D&            extent,
                                          uint32_t                     mip_levels,
                                          uint32_t                     array_layers,
                                          VkImageAspectFlags           aspect,
                                          const std::vector<uint64_t>& sizes,
                                          bool                         all_layers_per_level,
                                          CopyBufferImageDirection     copy_direction)
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    const uint32_t n_subresources = all_layers_per_level ? mip_levels : mip_levels * array_layers;

    GFXRECON_ASSERT(sizes.size() == n_subresources);

    std::vector<VkBufferImageCopy> copy_regions;

    VkBufferImageCopy copy_region;
    copy_region.bufferRowLength             = 0; // Request tightly packed data.
    copy_region.bufferImageHeight           = 0; // Request tightly packed data.
    copy_region.bufferOffset                = buffer_offset;
    copy_region.imageOffset.x               = 0;
    copy_region.imageOffset.y               = 0;
    copy_region.imageOffset.z               = 0;
    copy_region.imageSubresource.aspectMask = aspect;
    copy_region.imageSubresource.layerCount = all_layers_per_level ? array_layers : 1;

    uint32_t sr = 0;
    for (uint32_t m = 0; m < mip_levels; ++m)
    {
        copy_region.imageSubresource.mipLevel = m;
        copy_region.imageExtent.width         = std::max(1u, (extent.width >> m));
        copy_region.imageExtent.height        = std::max(1u, (extent.height >> m));
        copy_region.imageExtent.depth         = std::max(1u, (extent.depth >> m));

        for (uint32_t l = 0; l < array_layers; ++l)
        {
            copy_region.imageSubresource.baseArrayLayer = l;
            copy_regions.push_back(copy_region);

            copy_region.bufferOffset += sizes[sr];
            ++sr;

            if (all_layers_per_level)
            {
                break;
            }
        }
    }
    GFXRECON_ASSERT(sr == n_subresources);

    if (copy_direction == kImageToBuffer)
    {
        device_table_.CmdCopyImageToBuffer(command_buffer,
                                           image,
                                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                           buffer,
                                           static_cast<uint32_t>(copy_regions.size()),
                                           copy_regions.data());
    }
    else
    {
        GFXRECON_ASSERT(copy_direction == kBufferToImage);

        device_table_.CmdCopyBufferToImage(command_buffer,
                                           buffer,
                                           image,
                                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                           static_cast<uint32_t>(copy_regions.size()),
                                           copy_regions.data());
    }
}

void VulkanResourcesUtil::CopyBuffer(VkCommandBuffer command_buffer,
                                     VkBuffer        source_buffer,
                                     VkBuffer        destination_buffer,
                                     uint64_t        size,
                                     uint64_t        src_offset,
                                     uint64_t        dst_offset)
{
    GFXRECON_ASSERT(source_buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);

    VkBufferCopy copy_region;
    copy_region.srcOffset = src_offset;
    copy_region.dstOffset = dst_offset;
    copy_region.size      = size;

    device_table_.CmdCopyBuffer(command_buffer, source_buffer, destination_buffer, 1, &copy_region);
}

VkQueue VulkanResourcesUtil::GetQueue(uint32_t queue_family_index, uint32_t queue_index)
{
    VkQueue queue = VK_NULL_HANDLE;
    device_table_.GetDeviceQueue(device_, queue_family_index, queue_index, &queue);

    if (queue != VK_NULL_HANDLE)
    {
        // Because this queue was not allocated through the loader, it must be assigned a dispatch table.
        *reinterpret_cast<void**>(queue) = *reinterpret_cast<void**>(device_);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to retrieve a queue for resource memory snapshot");
    }

    return queue;
}

VkResult VulkanResourcesUtil::SubmitCommandBuffer(VkCommandBuffer command_buffer, VkQueue queue)
{
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(queue != VK_NULL_HANDLE);

    device_table_.EndCommandBuffer(command_buffer);

    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    VkFence                 fence;
    const VkFenceCreateInfo ci     = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO, nullptr, 0 };
    VkResult                result = device_table_.CreateFence(device_, &ci, nullptr, &fence);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create fence (%s)", util::ToString(result).c_str());
        return result;
    }

    result = device_table_.QueueSubmit(queue, 1, &submit_info, fence);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to submit command buffer for execution while taking a resource memory snapshot");
        return result;
    }

    result = device_table_.WaitForFences(device_, 1, &fence, VK_TRUE, ~0UL);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("WaitForFences returned %d while taking a resource memory snapshot", result);
        return result;
    }

    ResetCommandBuffer(command_buffer);

    return result;
}

VkResult VulkanResourcesUtil::ResolveImage(VkCommandBuffer   command_buffer,
                                           VkImage           image,
                                           VkFormat          format,
                                           VkImageType       type,
                                           const VkExtent3D& extent,
                                           uint32_t          array_layers,
                                           VkImageLayout     current_layout,
                                           VkImage*          resolved_image,
                                           VkDeviceMemory*   resolved_image_memory)
{
    GFXRECON_ASSERT((image != VK_NULL_HANDLE) && (resolved_image != nullptr) && (resolved_image_memory != nullptr));

    VkFormatProperties format_properties{};
    instance_table_.GetPhysicalDeviceFormatProperties(physical_device_, format, &format_properties);
    if ((format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) !=
        VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "Multisampled images that do not support VK_FORMAT_FEATURE_COLOR_ATTACHMENT will not be resolved");
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }

    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = type;
    create_info.format                = format;
    create_info.extent                = extent;
    create_info.mipLevels             = 1;
    create_info.arrayLayers           = array_layers;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    VkResult result = device_table_.CreateImage(device_, &create_info, nullptr, resolved_image);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create temporary image for multisample resolve.");
        return result;
    }

    uint32_t             memory_type_index = std::numeric_limits<uint32_t>::max();
    VkMemoryRequirements memory_requirements;

    device_table_.GetImageMemoryRequirements(device_, *resolved_image, &memory_requirements);

    bool found = FindMemoryTypeIndex(memory_properties_,
                                     memory_requirements.memoryTypeBits,
                                     VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                     &memory_type_index,
                                     nullptr);

    if (!found)
    {
        GFXRECON_LOG_ERROR(
            "Failed to find a device local memory type for multisample resolve temporary image creation");
        result = VK_ERROR_INITIALIZATION_FAILED;
        device_table_.DestroyImage(device_, *resolved_image, nullptr);
        *resolved_image = VK_NULL_HANDLE;
        return result;
    }

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.pNext                = nullptr;
    alloc_info.allocationSize       = memory_requirements.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    result = device_table_.AllocateMemory(device_, &alloc_info, nullptr, resolved_image_memory);
    if (result == VK_SUCCESS)
    {
        device_table_.BindImageMemory(device_, *resolved_image, *resolved_image_memory, 0);

        if (command_buffer != VK_NULL_HANDLE)
        {
            VkImageAspectFlags aspect_mask = GetFormatAspectMask(format);

            uint32_t             num_barriers = 1;
            VkImageMemoryBarrier memory_barriers[2];

            // Destination image
            memory_barriers[0].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            memory_barriers[0].pNext                           = nullptr;
            memory_barriers[0].srcAccessMask                   = 0;
            memory_barriers[0].dstAccessMask                   = VK_ACCESS_TRANSFER_WRITE_BIT;
            memory_barriers[0].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
            memory_barriers[0].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            memory_barriers[0].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barriers[0].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barriers[0].image                           = *resolved_image;
            memory_barriers[0].subresourceRange.aspectMask     = aspect_mask;
            memory_barriers[0].subresourceRange.baseMipLevel   = 0;
            memory_barriers[0].subresourceRange.levelCount     = 1;
            memory_barriers[0].subresourceRange.baseArrayLayer = 0;
            memory_barriers[0].subresourceRange.layerCount     = array_layers;

            // Multi-sample source image
            if (current_layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
            {
                num_barriers = 2;

                memory_barriers[1].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                memory_barriers[1].pNext                           = nullptr;
                memory_barriers[1].srcAccessMask                   = VK_ACCESS_MEMORY_WRITE_BIT;
                memory_barriers[1].dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
                memory_barriers[1].oldLayout                       = current_layout;
                memory_barriers[1].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                memory_barriers[1].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                memory_barriers[1].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                memory_barriers[1].image                           = image;
                memory_barriers[1].subresourceRange.aspectMask     = aspect_mask;
                memory_barriers[1].subresourceRange.baseMipLevel   = 0;
                memory_barriers[1].subresourceRange.levelCount     = 1;
                memory_barriers[1].subresourceRange.baseArrayLayer = 0;
                memory_barriers[1].subresourceRange.layerCount     = array_layers;
            }

            device_table_.CmdPipelineBarrier(command_buffer,
                                             VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             0,
                                             nullptr,
                                             num_barriers,
                                             memory_barriers);

            VkImageResolve region;
            region.srcSubresource.aspectMask     = aspect_mask;
            region.srcSubresource.mipLevel       = 0;
            region.srcSubresource.baseArrayLayer = 0;
            region.srcSubresource.layerCount     = array_layers;
            region.srcOffset.x                   = 0;
            region.srcOffset.y                   = 0;
            region.srcOffset.z                   = 0;
            region.dstSubresource.aspectMask     = aspect_mask;
            region.dstSubresource.mipLevel       = 0;
            region.dstSubresource.baseArrayLayer = 0;
            region.dstSubresource.layerCount     = array_layers;
            region.dstOffset.x                   = 0;
            region.dstOffset.y                   = 0;
            region.dstOffset.z                   = 0;
            region.extent.width                  = extent.width;
            region.extent.height                 = extent.height;
            region.extent.depth                  = extent.depth;

            device_table_.CmdResolveImage(command_buffer,
                                          image,
                                          VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                          *resolved_image,
                                          VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                          1,
                                          &region);

            // Prepare the resolved image for the next staging copy.
            memory_barriers[0].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
            memory_barriers[0].dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
            memory_barriers[0].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            memory_barriers[0].newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

            if (num_barriers == 2)
            {
                memory_barriers[1].srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                memory_barriers[1].dstAccessMask = 0;
                memory_barriers[1].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                memory_barriers[1].newLayout     = current_layout;
            }

            device_table_.CmdPipelineBarrier(command_buffer,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             0,
                                             nullptr,
                                             num_barriers,
                                             memory_barriers);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to allocate temporary image memory for multisample resolve");
        device_table_.DestroyImage(device_, *resolved_image, nullptr);
        *resolved_image = VK_NULL_HANDLE;
    }
    return result;
}

VkResult VulkanResourcesUtil::ReadImageResources(const std::vector<ImageResource>&   image_resources,
                                                 const ReadImageResourcesCallbackFn& call_back,
                                                 size_t                              staging_buffer_size)
{
    if (image_resources.empty())
    {
        return VK_SUCCESS;
    }
    // aggregate to store temporary data during batch-processing
    struct image_resource_tmp_data_t
    {
        uint64_t                  resource_size       = 0;
        VkDeviceSize              staging_offset      = 0;
        VkImage                   resolve_image       = VK_NULL_HANDLE;
        VkDeviceMemory            resolve_memory      = VK_NULL_HANDLE;
        VkImage                   scaled_image        = VK_NULL_HANDLE;
        VkDeviceMemory            scaled_image_memory = VK_NULL_HANDLE;
        bool                      use_blit            = false;
        bool                      scaling_supported   = false;
        VkExtent3D                scaled_extent       = {};
        VkImageAspectFlags        transition_aspect   = VK_IMAGE_ASPECT_NONE;
        std::vector<VkDeviceSize> level_sizes;

        VkDevice                         device       = VK_NULL_HANDLE;
        const encode::VulkanDeviceTable* device_table = nullptr;

        image_resource_tmp_data_t& operator=(image_resource_tmp_data_t other)
        {
            std::swap(resource_size, other.resource_size);
            std::swap(staging_offset, other.staging_offset);
            std::swap(resolve_image, other.resolve_image);
            std::swap(resolve_memory, other.resolve_memory);
            std::swap(scaled_image, other.scaled_image);
            std::swap(scaled_image_memory, other.scaled_image_memory);
            std::swap(use_blit, other.use_blit);
            std::swap(scaling_supported, other.scaling_supported);
            std::swap(scaled_extent, other.scaled_extent);
            std::swap(transition_aspect, other.transition_aspect);
            std::swap(level_sizes, other.level_sizes);
            std::swap(device, other.device);
            std::swap(device_table, other.device_table);
            return *this;
        }

        ~image_resource_tmp_data_t()
        {
            if (device_table != nullptr && device != VK_NULL_HANDLE)
            {
                if (resolve_image != VK_NULL_HANDLE)
                {
                    device_table->DestroyImage(device, resolve_image, nullptr);
                    device_table->FreeMemory(device, resolve_memory, nullptr);
                }

                if (scaled_image != VK_NULL_HANDLE)
                {
                    device_table->DestroyImage(device, scaled_image, nullptr);
                    device_table->FreeMemory(device, scaled_image_memory, nullptr);
                }
            }
        }
    };
    std::vector<image_resource_tmp_data_t> tmp_data(image_resources.size());
    uint32_t                               current_batch_size = 0;

    // start with entire range
    std::vector<std::pair<uint32_t, uint32_t>> batch_ranges = { { 0, static_cast<uint32_t>(image_resources.size()) } };

    // iterate inputs, determine sizes, split into batches
    for (uint32_t i = 0; i < image_resources.size(); ++i)
    {
        const auto& img = image_resources[i];

        // allow temporary data to cleanup after itself
        tmp_data[i].device       = device_;
        tmp_data[i].device_table = &device_table_;

        VkFormat dst_format = img.dst_format != VK_FORMAT_UNDEFINED ? img.dst_format : img.format;

        GFXRECON_ASSERT(img.level_count <=
                        1 + floor(log2(std::max(std::max(img.extent.width, img.extent.height), img.extent.depth))));
        GFXRECON_ASSERT((img.aspect == VK_IMAGE_ASPECT_COLOR_BIT) || (img.aspect == VK_IMAGE_ASPECT_DEPTH_BIT) ||
                        (img.aspect == VK_IMAGE_ASPECT_STENCIL_BIT));

        bool blit_supported = IsBlitSupported(img.format, img.tiling, dst_format);
        tmp_data[i].scaling_supported =
            IsScalingSupported(img.format, img.tiling, dst_format, img.type, img.extent, img.scale);

        tmp_data[i].use_blit =
            (img.format != dst_format && blit_supported) || (img.scale != 1.0f && tmp_data[i].scaling_supported);

        tmp_data[i].scaled_extent = {
            static_cast<uint32_t>(std::max(static_cast<float>(img.extent.width) * img.scale, 1.0f)),
            static_cast<uint32_t>(std::max(static_cast<float>(img.extent.height) * img.scale, 1.0f)),
            static_cast<uint32_t>(std::max(static_cast<float>(img.extent.depth) * img.scale, 1.0f))
        };

        uint64_t resource_size = img.resource_size;

        if (img.external_format)
        {
            resource_size = img.size;
            tmp_data[i].level_sizes.push_back(resource_size);
        }
        else if (resource_size == 0 || img.level_sizes == nullptr)
        {
            resource_size = GetImageResourceSizesOptimal(img.image,
                                                         tmp_data[i].use_blit ? dst_format : img.format,
                                                         img.type,
                                                         tmp_data[i].use_blit ? tmp_data[i].scaled_extent : img.extent,
                                                         img.level_count,
                                                         img.layer_count,
                                                         img.tiling,
                                                         img.aspect,
                                                         nullptr,
                                                         &tmp_data[i].level_sizes,
                                                         img.all_layers_per_level);
        }

        if (resource_size > staging_buffer_size)
        {
            // we need a bigger boat
            staging_buffer_size = resource_size;
        }

        if (current_batch_size + resource_size > staging_buffer_size)
        {
            // end current batch, start next
            auto& current_batch  = batch_ranges.back();
            current_batch.second = i;

            auto& next_batch   = batch_ranges.emplace_back(i, static_cast<uint32_t>(image_resources.size()));
            current_batch_size = 0;
        }

        tmp_data[i].resource_size  = resource_size;
        tmp_data[i].staging_offset = current_batch_size;
        current_batch_size += resource_size;
    } // image_resources, 1st batch-splitting pass

    VkResult result = CreateStagingBuffer(staging_buffer_size);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "%s: could not create a staging-buffer of size: %d kB", __func__, staging_buffer_size >> 10U);
        return result;
    }

    // accumulate timing data
    uint32_t gpu_micros = 0, cpu_micros = 0;

    for (const auto& [start_idx, end_idx] : batch_ranges)
    {
        auto                                          start_time = std::chrono::high_resolution_clock::now();
        std::unordered_map<uint32_t, VkCommandBuffer> command_buffer_map;

        // iterate over current batch
        for (uint32_t i = start_idx; i < end_idx; ++i)
        {
            const auto& img = image_resources[i];

            VkCommandBuffer command_buffer = VK_NULL_HANDLE;
            auto            cmd_buf_it     = command_buffer_map.find(img.queue_family_index);
            if (cmd_buf_it == command_buffer_map.end())
            {
                command_buffer                             = CreateCommandBufferAndBegin(img.queue_family_index);
                command_buffer_map[img.queue_family_index] = command_buffer;
            }
            else
            {
                command_buffer = cmd_buf_it->second;
            }

            VkImage copy_image = tmp_data[i].resolve_image != VK_NULL_HANDLE ? tmp_data[i].resolve_image : img.image;

            if (img.sample_count != VK_SAMPLE_COUNT_1_BIT)
            {
                result = ResolveImage(command_buffer,
                                      img.image,
                                      img.format,
                                      img.type,
                                      img.extent,
                                      img.layer_count,
                                      img.layout,
                                      &tmp_data[i].resolve_image,
                                      &tmp_data[i].resolve_memory);
                if (result != VK_SUCCESS)
                {
                    GFXRECON_ASSERT(false);
                    return result;
                }
            }

            tmp_data[i].transition_aspect = img.aspect;
            if ((img.aspect == VK_IMAGE_ASPECT_DEPTH_BIT) || (img.aspect == VK_IMAGE_ASPECT_STENCIL_BIT))
            {
                // Depth and stencil aspects need to be transitioned together, so get full aspect
                // mask for image.
                tmp_data[i].transition_aspect = GetFormatAspectMask(img.format);
            }

            if (img.sample_count == VK_SAMPLE_COUNT_1_BIT && img.layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
            {
                TransitionImageToTransferOptimal(command_buffer,
                                                 img.image,
                                                 img.layout,
                                                 VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                 tmp_data[i].transition_aspect,
                                                 img.queue_family_index);
            }

            VkFormat dst_format = img.dst_format != VK_FORMAT_UNDEFINED ? img.dst_format : img.format;

            // Blit image to change dimensions or convert format
            if (tmp_data[i].use_blit)
            {
                VkImage blit_src = tmp_data[i].resolve_image ? tmp_data[i].resolve_image : img.image;
                result           = BlitImage(command_buffer,
                                   blit_src,
                                   img.format,
                                   dst_format,
                                   img.type,
                                   img.tiling,
                                   img.extent,
                                   tmp_data[i].scaled_extent,
                                   img.level_count,
                                   img.layer_count,
                                   img.aspect,
                                   img.queue_family_index,
                                   img.scale,
                                   tmp_data[i].scaled_image,
                                   tmp_data[i].scaled_image_memory);

                copy_image = tmp_data[i].scaled_image != VK_NULL_HANDLE ? tmp_data[i].scaled_image : copy_image;

                if (result != VK_SUCCESS)
                {
                    return result;
                }
            }

            if (!img.external_format)
            {
                // Copy image to staging buffer
                CopyImageBuffer(command_buffer,
                                copy_image,
                                staging_buffer_.buffer,
                                tmp_data[i].staging_offset,
                                tmp_data[i].scaled_extent,
                                img.level_count,
                                img.layer_count,
                                img.aspect,
                                img.level_sizes != nullptr ? *img.level_sizes : tmp_data[i].level_sizes,
                                img.all_layers_per_level,
                                kImageToBuffer);
            }

            // Cache flushing barrier. Make results visible to host
            VkBufferMemoryBarrier buffer_barrier;
            buffer_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buffer_barrier.pNext               = nullptr;
            buffer_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buffer_barrier.dstAccessMask       = VK_ACCESS_HOST_READ_BIT;
            buffer_barrier.srcQueueFamilyIndex = img.queue_family_index;
            buffer_barrier.dstQueueFamilyIndex = img.queue_family_index;
            buffer_barrier.buffer              = staging_buffer_.buffer;
            buffer_barrier.offset              = 0;
            buffer_barrier.size                = VK_WHOLE_SIZE;

            device_table_.CmdPipelineBarrier(command_buffer,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_HOST_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             1,
                                             &buffer_barrier,
                                             0,
                                             nullptr);

            if ((img.sample_count == VK_SAMPLE_COUNT_1_BIT) && (img.layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                (img.layout != VK_IMAGE_LAYOUT_PREINITIALIZED) && (img.layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL))
            {
                TransitionImageFromTransferOptimal(command_buffer,
                                                   img.image,
                                                   VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                   img.layout,
                                                   tmp_data[i].transition_aspect,
                                                   img.queue_family_index);
            }
        } // current batch, record commands

        // submit recorded command-buffer(s)
        for (const auto& [queue_family_index, command_buffer] : command_buffer_map)
        {
            VkQueue queue = GetQueue(queue_family_index, 0);
            if (queue == VK_NULL_HANDLE)
            {
                return VK_ERROR_INITIALIZATION_FAILED;
            }
            SubmitCommandBuffer(command_buffer, queue);
        }

        result = MapStagingBuffer();
        if (result != VK_SUCCESS)
        {
            return result;
        }

        // guarantees that all device writes are now visible to host
        InvalidateStagingBuffer();

        gpu_micros += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() -
                                                                            start_time)
                          .count();

        // consume staging-buffer, cleanup temporary resources
        for (uint32_t i = start_idx; i < end_idx; ++i)
        {
            const auto& img = image_resources[i];
            auto* out_ptr   = reinterpret_cast<const uint8_t*>(staging_buffer_.mapped_ptr) + tmp_data[i].staging_offset;
            if (call_back)
            {
                call_back(img, out_ptr, tmp_data[i].resource_size);
            }

            // free potential temporary resources
            tmp_data[i] = {};
        } // current batch, consume staging-buffer

        UnmapStagingBuffer();

        auto batch_micros = std::chrono::duration_cast<std::chrono::microseconds>(
                                std::chrono::high_resolution_clock::now() - start_time)
                                .count();
        cpu_micros += batch_micros - gpu_micros;
    } // batch_ranges
    GFXRECON_LOG_DEBUG("gpu: %d ms - cpu: %d ms", gpu_micros / 1000, cpu_micros / 1000);
    return VK_SUCCESS;
}

VkResult VulkanResourcesUtil::ReadImageResource(const VulkanResourcesUtil::ImageResource& image_resource,
                                                std::vector<uint8_t>&                     out_data)
{
    return ReadImageResources(
        { image_resource },
        [&out_data](const ImageResource& img, const void* data, size_t num_bytes) {
            const auto* ptr = reinterpret_cast<const uint8_t*>(data);
            out_data.clear();
            out_data.insert(out_data.end(), ptr, ptr + num_bytes);
        },
        0);
}

VkResult VulkanResourcesUtil::ReadFromBufferResource(
    VkBuffer buffer, uint64_t size, uint64_t offset, uint32_t queue_family_index, std::vector<uint8_t>& data)
{
    GFXRECON_ASSERT(buffer != VK_NULL_HANDLE);
    GFXRECON_ASSERT(size);

    VkQueue queue = GetQueue(queue_family_index, 0);
    if (queue == VK_NULL_HANDLE)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkResult result = CreateStagingBuffer(size);
    if (result != VK_SUCCESS)
    {
        return result;
    }

    VkCommandBuffer command_buffer = CreateCommandBufferAndBegin(queue_family_index);
    GFXRECON_ASSERT(command_buffer != VK_NULL_HANDLE);
    if (command_buffer == VK_NULL_HANDLE)
    {
        return VK_ERROR_UNKNOWN;
    }

    CopyBuffer(command_buffer, buffer, staging_buffer_.buffer, size, offset, 0);

    result = SubmitCommandBuffer(command_buffer, queue);
    if (result != VK_SUCCESS)
    {
        return result;
    }

    result = MapStagingBuffer();
    if (result != VK_SUCCESS)
    {
        return result;
    }

    data.resize(static_cast<size_t>(size));

    InvalidateStagingBuffer();
    util::platform::MemoryCopy(data.data(), size, staging_buffer_.mapped_ptr, size);

    return result;
}

void VulkanResourcesUtil::ReadBufferResources(const std::vector<BufferResource>& buffer_resources,
                                              const VulkanResourcesUtil::ReadBufferResourcesCallbackFn& callback,
                                              size_t staging_buffer_size)
{
    if (buffer_resources.empty())
    {
        return;
    }
    std::vector<VkDeviceSize> staging_offsets(buffer_resources.size());

    uint32_t current_batch_size = 0;

    // start with entire range
    std::vector<std::pair<uint32_t, uint32_t>> batch_ranges = { { 0, static_cast<uint32_t>(buffer_resources.size()) } };

    for (uint32_t i = 0; i < buffer_resources.size(); ++i)
    {
        const auto& buffer_resource = buffer_resources[i];

        if (buffer_resource.size > staging_buffer_size)
        {
            // we need a bigger boat
            staging_buffer_size = buffer_resource.size;
        }

        if (current_batch_size + buffer_resource.size > staging_buffer_size)
        {
            // end current batch, start next
            auto& current_batch  = batch_ranges.back();
            current_batch.second = i;

            batch_ranges.emplace_back(i, static_cast<uint32_t>(buffer_resources.size()));
            current_batch_size = 0;
        }

        staging_offsets[i] = current_batch_size;
        current_batch_size += buffer_resource.size;
    } // buffer_resources, split into batches

    VkResult result = CreateStagingBuffer(staging_buffer_size);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR(
            "%s: could not create a staging-buffer of size: %d kB", __func__, staging_buffer_size >> 10U);
        return;
    }

    for (const auto& [start_idx, end_idx] : batch_ranges)
    {
        auto                                          start_time = std::chrono::high_resolution_clock::now();
        std::unordered_map<uint32_t, VkCommandBuffer> command_buffer_map;

        // iterate over current batch
        for (uint32_t i = start_idx; i < end_idx; ++i)
        {
            const auto& buf = buffer_resources[i];

            VkCommandBuffer command_buffer = VK_NULL_HANDLE;
            auto            cmd_buf_it     = command_buffer_map.find(buf.queue_family_index);
            if (cmd_buf_it == command_buffer_map.end())
            {
                command_buffer                             = CreateCommandBufferAndBegin(buf.queue_family_index);
                command_buffer_map[buf.queue_family_index] = command_buffer;
            }
            else
            {
                command_buffer = cmd_buf_it->second;
            }

            CopyBuffer(command_buffer, buf.buffer, staging_buffer_.buffer, buf.size, buf.offset, staging_offsets[i]);
        }

        // submit recorded command-buffer(s)
        for (const auto& [queue_family_index, command_buffer] : command_buffer_map)
        {
            // Cache flushing barrier. Make results visible to host
            VkBufferMemoryBarrier buffer_barrier;
            buffer_barrier.sType               = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
            buffer_barrier.pNext               = nullptr;
            buffer_barrier.srcAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
            buffer_barrier.dstAccessMask       = VK_ACCESS_HOST_READ_BIT;
            buffer_barrier.srcQueueFamilyIndex = queue_family_index;
            buffer_barrier.dstQueueFamilyIndex = queue_family_index;
            buffer_barrier.buffer              = staging_buffer_.buffer;
            buffer_barrier.offset              = 0;
            buffer_barrier.size                = VK_WHOLE_SIZE;

            device_table_.CmdPipelineBarrier(command_buffer,
                                             VK_PIPELINE_STAGE_TRANSFER_BIT,
                                             VK_PIPELINE_STAGE_HOST_BIT,
                                             0,
                                             0,
                                             nullptr,
                                             1,
                                             &buffer_barrier,
                                             0,
                                             nullptr);

            VkQueue queue = GetQueue(queue_family_index, 0);
            if (queue == VK_NULL_HANDLE)
            {
                GFXRECON_ASSERT(false);
                return;
            }
            SubmitCommandBuffer(command_buffer, queue);
        }

        result = MapStagingBuffer();
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("%s: could not map staging-buffer", __func__);
            return;
        }

        // guarantees that all device writes are now visible to host
        InvalidateStagingBuffer();

        // consume staging-buffer
        for (uint32_t i = start_idx; i < end_idx; ++i)
        {
            const auto& buf     = buffer_resources[i];
            auto*       out_ptr = reinterpret_cast<const uint8_t*>(staging_buffer_.mapped_ptr) + staging_offsets[i];
            if (callback)
            {
                callback(buf, out_ptr);
            }
        } // current batch, consume staging-buffer

        GFXRECON_LOG_DEBUG("%s: batch done: %d - %d (%d)", __func__, start_idx, end_idx, buffer_resources.size());
    }
}

bool VulkanResourcesUtil::IsBlitSupported(VkFormat       src_format,
                                          VkImageTiling  src_image_tiling,
                                          VkFormat       dst_format,
                                          VkImageTiling* dst_image_tiling) const
{
    // Integer formats must match
    if ((vkuFormatIsSINT(src_format) != vkuFormatIsSINT(dst_format)) ||
        (vkuFormatIsUINT(src_format) != vkuFormatIsUINT(dst_format)))
    {
        return false;
    }

    // Depth formats must be the same for src and destination images
    if ((vkuFormatIsDepthOrStencil(src_format) != vkuFormatIsDepthOrStencil(dst_format)) ||
        (vkuFormatIsDepthOrStencil(src_format) && src_format != dst_format))
    {
        return false;
    }

    VkFormatProperties src_format_props;
    instance_table_.GetPhysicalDeviceFormatProperties(physical_device_, src_format, &src_format_props);

    if (src_image_tiling == VK_IMAGE_TILING_OPTIMAL &&
        (src_format_props.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT) != VK_FORMAT_FEATURE_BLIT_SRC_BIT)
    {
        return false;
    }
    else if (src_image_tiling == VK_IMAGE_TILING_LINEAR &&
             (src_format_props.linearTilingFeatures & VK_FORMAT_FEATURE_BLIT_SRC_BIT) != VK_FORMAT_FEATURE_BLIT_SRC_BIT)
    {
        return false;
    }

    VkFormatProperties dst_format_props;
    instance_table_.GetPhysicalDeviceFormatProperties(physical_device_, dst_format, &dst_format_props);
    if ((dst_format_props.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT) == VK_FORMAT_FEATURE_BLIT_DST_BIT)
    {
        if (dst_image_tiling != nullptr)
        {
            *dst_image_tiling = VK_IMAGE_TILING_OPTIMAL;
        }
        return true;
    }
    else if ((dst_format_props.linearTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT) == VK_FORMAT_FEATURE_BLIT_DST_BIT)
    {
        if (dst_image_tiling != nullptr)
        {
            *dst_image_tiling = VK_IMAGE_TILING_LINEAR;
        }
        return true;
    }

    return false;
}

bool VulkanResourcesUtil::IsScalingSupported(VkFormat          src_format,
                                             VkImageTiling     src_image_tiling,
                                             VkFormat          dst_format,
                                             VkImageType       type,
                                             const VkExtent3D& extent,
                                             float             scale) const
{
    VkImageTiling dst_image_tiling;
    bool          is_blit_supported = IsBlitSupported(src_format, src_image_tiling, dst_format, &dst_image_tiling);

    if (is_blit_supported && scale > 1.0f)
    {
        VkImageFormatProperties dst_img_format_props;
        instance_table_.GetPhysicalDeviceImageFormatProperties(physical_device_,
                                                               dst_format,
                                                               type,
                                                               dst_image_tiling,
                                                               VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                                                               0,
                                                               &dst_img_format_props);

        if (dst_img_format_props.maxExtent.width < static_cast<uint32_t>(static_cast<float>(extent.width) * scale) ||
            dst_img_format_props.maxExtent.height < static_cast<uint32_t>(static_cast<float>(extent.height) * scale))
        {
            return false;
        }
    }

    return scale == 1.0f || is_blit_supported;
}

VkResult VulkanResourcesUtil::BlitImage(VkCommandBuffer       command_buffer,
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
                                        VkDeviceMemory&       scaled_image_mem)
{
    scaled_image     = VK_NULL_HANDLE;
    scaled_image_mem = VK_NULL_HANDLE;
    VkImageTiling dst_img_tiling;

    bool blit_supported = IsBlitSupported(format, tiling, dst_format, &dst_img_tiling);

    // In case of scalling an image up, check if the image resolution is supported by the implementation
    if (blit_supported && scale > 1.0f)
    {
        blit_supported = IsScalingSupported(format, tiling, dst_format, type, extent, scale);
        if (!blit_supported)
        {
            blit_supported = false;
        }
    }

    if (!blit_supported)
    {
        return VK_SUCCESS;
    }

    // Create a scaled image and then blit to scaled image
    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = type;
    create_info.format                = dst_format;
    create_info.extent                = (scale > 1.0f) ? scaled_extent : extent;
    create_info.mipLevels             = mip_levels;
    create_info.arrayLayers           = array_layers;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = dst_img_tiling;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    VkResult result = device_table_.CreateImage(device_, &create_info, nullptr, &scaled_image);
    if (result != VK_SUCCESS)
    {
        return result;
    }

    // Get image mem requirements, allocate image memory, and bind image memory
    VkMemoryRequirements scaled_image_mem_requirements;
    uint32_t             memory_type_index = std::numeric_limits<uint32_t>::max();
    device_table_.GetImageMemoryRequirements(device_, scaled_image, &scaled_image_mem_requirements);
    bool found = FindMemoryTypeIndex(memory_properties_,
                                     scaled_image_mem_requirements.memoryTypeBits,
                                     VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                     &memory_type_index,
                                     nullptr);
    if (!found)
    {
        device_table_.DestroyImage(device_, scaled_image, nullptr);

        GFXRECON_LOG_ERROR("Failed to find a memory type with host visible and host cached or coherent "
                           "properties for resource memory snapshot staging buffer creation");

        return VK_ERROR_UNKNOWN;
    }

    VkMemoryAllocateInfo allocate_info = {
        VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr, scaled_image_mem_requirements.size, memory_type_index
    };

    result = device_table_.AllocateMemory(device_, &allocate_info, nullptr, &scaled_image_mem);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("AllocateMemory failed with error: %d", result);
        device_table_.DestroyImage(device_, scaled_image, nullptr);
        return result;
    }
    result = device_table_.BindImageMemory(device_, scaled_image, scaled_image_mem, 0);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("BinadImageMemory failed with error: %d", result);
        device_table_.FreeMemory(device_, scaled_image_mem, nullptr);
        device_table_.DestroyImage(device_, scaled_image, nullptr);
        return result;
    }

    VkImageAspectFlags aspectMask = static_cast<VkImageAspectFlagBits>(aspect);

    // Transition scaled image into TRANSFER_DST_OPTIMAL
    VkImageMemoryBarrier img_barrier;
    img_barrier.sType               = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    img_barrier.pNext               = nullptr;
    img_barrier.srcAccessMask       = 0;
    img_barrier.dstAccessMask       = VK_ACCESS_TRANSFER_WRITE_BIT;
    img_barrier.oldLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
    img_barrier.newLayout           = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    img_barrier.srcQueueFamilyIndex = queue_family_index;
    img_barrier.dstQueueFamilyIndex = queue_family_index;
    img_barrier.image               = scaled_image;
    img_barrier.subresourceRange    = { aspectMask, 0, mip_levels, 0, array_layers };

    device_table_.CmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    VkImageBlit blit_region;
    blit_region.srcOffsets[0].x = 0;
    blit_region.srcOffsets[0].y = 0;
    blit_region.srcOffsets[0].z = 0;

    blit_region.dstOffsets[0].x = 0;
    blit_region.dstOffsets[0].y = 0;
    blit_region.dstOffsets[0].z = 0;

    GFXRECON_ASSERT(mip_levels);
    // assert(dst_img_mip_levels);
    std::vector<VkImageBlit> blit_regions(mip_levels);
    for (uint32_t i = 0; i < mip_levels; ++i)
    {
        blit_region.srcOffsets[1].x = std::max((int32_t)extent.width >> i, 1);
        blit_region.srcOffsets[1].y = std::max((int32_t)extent.height >> i, 1);
        blit_region.srcOffsets[1].z = std::max((int32_t)extent.depth >> i, 1);
        blit_region.srcSubresource  = { aspectMask, i, 0, array_layers };

        blit_region.dstOffsets[1].x = std::max((int32_t)scaled_extent.width >> i, 1);
        blit_region.dstOffsets[1].y = std::max((int32_t)scaled_extent.height >> i, 1);
        blit_region.dstOffsets[1].z = std::max((int32_t)scaled_extent.depth >> i, 1);
        blit_region.dstSubresource  = { aspectMask, i, 0, array_layers };

        blit_regions[i] = blit_region;
    }

    device_table_.CmdBlitImage(command_buffer,
                               image,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               scaled_image,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               static_cast<uint32_t>(blit_regions.size()),
                               blit_regions.data(),
                               VK_FILTER_NEAREST);

    // Make sure blit is complete before copying from the scaled image.
    // Also transition scaled image DST_OPTIMAL -> SRC_OPTIMAL
    img_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    img_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
    img_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    img_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

    device_table_.CmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &img_barrier);

    return VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(encode)
