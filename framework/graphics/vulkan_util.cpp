/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "graphics/vulkan_util.h"
#include "graphics/vulkan_struct_get_pnext.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

util::platform::LibraryHandle InitializeLoader(const char* loader_path)
{
    if (loader_path != nullptr && loader_path[0] != '\0')
    {
        return util::platform::OpenLibrary(loader_path);
    }
    else
    {
        return util::platform::OpenLibrary(kLoaderLibNames);
    }
}

void ReleaseLoader(util::platform::LibraryHandle loader_handle)
{
    if (loader_handle != nullptr)
    {
        util::platform::CloseLibrary(loader_handle);
    }
}

bool ImageHasUsage(VkImageUsageFlags usage_flags, VkImageUsageFlagBits bit)
{
    return (usage_flags & bit) == bit;
}

VkDeviceSize AlignBufferOffset(VkDeviceSize offset, VkDeviceSize alignment)
{
    // Vulkan only specifies alignments for buffer-image copies. Use modulo math so
    // non-power-of-two alignments (e.g. 3-byte RGB formats) are handled correctly.
    GFXRECON_ASSERT(alignment > 0);

    if (alignment <= 1)
    {
        return offset;
    }

    const VkDeviceSize remainder = offset % alignment;
    if (remainder == 0)
    {
        return offset;
    }

    return offset + (alignment - remainder);
}

VkDeviceSize GetBufferImageCopyOffsetAlignment(VkFormat format, VkImageAspectFlags aspect_mask)
{
    if (format == VK_FORMAT_UNDEFINED)
    {
        // Defensive fallback for external-format images where no concrete VkFormat is available.
        return 1;
    }

    if (vkuFormatIsDepthOrStencil(format))
    {
        // Vulkan requires 4-byte bufferOffset alignment for depth/stencil image copies.
        return 4;
    }

    if (vkuFormatIsMultiplane(format))
    {
        // For multiplane formats, alignment comes from the selected plane's compatible format.
        VkImageAspectFlagBits plane_aspect = VK_IMAGE_ASPECT_PLANE_0_BIT;
        if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_1_BIT) != 0)
        {
            plane_aspect = VK_IMAGE_ASPECT_PLANE_1_BIT;
        }
        else if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_2_BIT) != 0)
        {
            plane_aspect = VK_IMAGE_ASPECT_PLANE_2_BIT;
        }

        const VkFormat compatible_format = vkuFindMultiplaneCompatibleFormat(format, plane_aspect);
        GFXRECON_ASSERT(compatible_format != VK_FORMAT_UNDEFINED);
        if (compatible_format != VK_FORMAT_UNDEFINED)
        {
            const VKU_FORMAT_INFO format_info = vkuGetFormatInfo(compatible_format);
            GFXRECON_ASSERT(format_info.block_size > 0);
            return format_info.block_size;
        }

        return 1;
    }

    const VKU_FORMAT_INFO format_info = vkuGetFormatInfo(format);
    GFXRECON_ASSERT(format_info.block_size > 0);
    return format_info.block_size;
}

uint32_t FindTransferQueueFamilyIndex(const VulkanQueueFamilyFlags& families)
{
    uint32_t index = VK_QUEUE_FAMILY_IGNORED;

    for (uint32_t i = 0; i < static_cast<uint32_t>(families.queue_family_index_enabled.size()); ++i)
    {
        if (families.queue_family_index_enabled[i])
        {
            const auto& flags_entry = families.queue_family_properties_flags.find(i);
            if ((flags_entry != families.queue_family_properties_flags.end()))
            {
                if ((flags_entry->second & VK_QUEUE_TRANSFER_BIT) == VK_QUEUE_TRANSFER_BIT)
                {
                    return i;
                }
                else if ((flags_entry->second & (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT)))
                {
                    index = i;
                }
            }
        }
    }

    return index;
}

uint32_t FindComputeQueueFamilyIndex(const VulkanQueueFamilyFlags& families)
{
    for (uint32_t i = 0; i < static_cast<uint32_t>(families.queue_family_index_enabled.size()); ++i)
    {
        if (families.queue_family_index_enabled[i])
        {
            const auto& flags_entry = families.queue_family_properties_flags.find(i);
            if ((flags_entry != families.queue_family_properties_flags.end()))
            {
                if ((flags_entry->second & VK_QUEUE_COMPUTE_BIT) == VK_QUEUE_COMPUTE_BIT)
                {
                    return i;
                }
            }
        }
    }

    return VK_QUEUE_FAMILY_IGNORED;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
