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

#ifndef GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_H
#define GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

// Maps every subresource of a single VkImage to the VkImageLayout it is currently in.
//
// A VkImage does not have one layout: each (aspect, mip level, array layer) subresource has its own. Depth/stencil
// images routinely hold split layouts, and applications generating mipmaps transition individual mip levels.
class ImageLayoutMap
{
  public:
    ImageLayoutMap() = default;

    void Initialize(uint32_t mip_levels, uint32_t array_layers, VkImageAspectFlags aspects);

    [[nodiscard]] bool               IsInitialized() const { return aspects_ != 0; }
    [[nodiscard]] bool               IsUniform() const { return is_uniform_; }
    [[nodiscard]] VkImageAspectFlags GetAspects() const { return aspects_; }
    [[nodiscard]] uint32_t           GetMipLevels() const { return mip_levels_; }
    [[nodiscard]] uint32_t           GetArrayLayers() const { return array_layers_; }

    // Put every subresource in the same layout.
    void SetUniformLayout(VkImageLayout layout);

    void SetLayout(const VkImageSubresourceRange& range, VkImageLayout layout);

    // Merges every subresource layout from `src` that is not VK_IMAGE_LAYOUT_UNDEFINED into this map.
    void MergeFrom(const ImageLayoutMap& src);

    // Layout of a single subresource, or VK_IMAGE_LAYOUT_UNDEFINED if the image has no such aspect.
    [[nodiscard]] VkImageLayout GetSubresourceLayout(VkImageAspectFlagBits aspect,
                                                      uint32_t              mip_level,
                                                      uint32_t              array_layer) const;

  private:
    // Highest slot supported for aspect.
    static constexpr uint32_t kAspectSlotCount = 6;

    [[nodiscard]] static VkImageAspectFlags GetAspectFromIndex(uint32_t aspect_index);

    [[nodiscard]] uint32_t GetAspectSlotCount() const;

    [[nodiscard]] uint32_t GetSubresourceIndex(uint32_t aspect_index, uint32_t mip_level, uint32_t array_layer) const
    {
        return (aspect_index * mip_levels_ * array_layers_) + (mip_level * array_layers_) + array_layer;
    }

    void ExpandUniform();

    uint32_t           mip_levels_{ 1 };
    uint32_t           array_layers_{ 1 };
    VkImageAspectFlags aspects_{ 0 };

    bool                       is_uniform_{ true };
    VkImageLayout              uniform_layout_{ VK_IMAGE_LAYOUT_UNDEFINED };
    std::vector<VkImageLayout> subresource_layouts_;
};

// Aspects that a layout describes.
VkImageAspectFlags GetLayoutAspects(VkImageLayout layout);

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_IMAGE_LAYOUT_MAP_H
