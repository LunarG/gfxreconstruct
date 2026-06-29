/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_SWAPCHAIN_FORMAT_H
#define GFXRECON_DECODE_VULKAN_SWAPCHAIN_FORMAT_H

#include "util/defines.h"

#include "Vulkan-Utility-Libraries/vk_format_utils.h"
#include "vulkan/vulkan.h"

#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Selects a presentable fallback surface-format, preferring the BGRA8 variant matching want_srgb,
// then the first supported format of matching sRGB-ness, then the first supported format
// (or the preferred BGRA8 variant when the list is empty). Accepts a range of VkFormat or
// VkSurfaceFormatKHR.
template <typename FormatRange>
VkFormat SelectFallbackSurfaceFormat(const FormatRange& supported, bool want_srgb)
{
    auto as_format = [](const auto& entry) -> VkFormat {
        if constexpr (std::is_same_v<std::decay_t<decltype(entry)>, VkSurfaceFormatKHR>)
        {
            return entry.format;
        }
        else
        {
            return entry;
        }
    };
    const VkFormat preferred        = want_srgb ? VK_FORMAT_B8G8R8A8_SRGB : VK_FORMAT_B8G8R8A8_UNORM;
    VkFormat       first_supported  = VK_FORMAT_UNDEFINED;
    VkFormat       first_srgb_match = VK_FORMAT_UNDEFINED;
    for (const auto& entry : supported)
    {
        const VkFormat format = as_format(entry);
        if (format == preferred)
        {
            return preferred;
        }
        if (first_supported == VK_FORMAT_UNDEFINED)
        {
            first_supported = format;
        }
        if (first_srgb_match == VK_FORMAT_UNDEFINED && vkuFormatIsSRGB(format) == want_srgb)
        {
            first_srgb_match = format;
        }
    }
    if (first_srgb_match != VK_FORMAT_UNDEFINED)
    {
        return first_srgb_match;
    }
    return first_supported == VK_FORMAT_UNDEFINED ? preferred : first_supported;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SWAPCHAIN_FORMAT_H
