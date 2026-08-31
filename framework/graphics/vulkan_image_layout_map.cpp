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

#include "graphics/vulkan_image_layout_map.h"

#include "util/logging.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

VkImageAspectFlags ImageLayoutMap::GetAspectFromIndex(uint32_t aspect_index)
{
    switch (aspect_index)
    {
        case 0:
            return VK_IMAGE_ASPECT_COLOR_BIT;
        case 1:
            return VK_IMAGE_ASPECT_DEPTH_BIT;
        case 2:
            return VK_IMAGE_ASPECT_STENCIL_BIT;
        case 3:
            return VK_IMAGE_ASPECT_PLANE_0_BIT;
        case 4:
            return VK_IMAGE_ASPECT_PLANE_1_BIT;
        case 5:
            return VK_IMAGE_ASPECT_PLANE_2_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

uint32_t ImageLayoutMap::GetAspectSlotCount() const
{
    uint32_t slot_count = 0;
    for (uint32_t aspect_index = 0; aspect_index < kAspectSlotCount; ++aspect_index)
    {
        if ((aspects_ & GetAspectFromIndex(aspect_index)) != 0)
        {
            slot_count = aspect_index + 1;
        }
    }
    return slot_count;
}

void ImageLayoutMap::Initialize(uint32_t mip_levels, uint32_t array_layers, VkImageAspectFlags aspects)
{
    mip_levels_   = (mip_levels != 0) ? mip_levels : 1;
    array_layers_ = (array_layers != 0) ? array_layers : 1;

    // Default to a color image so its transitions are still recorded
    aspects_ = (aspects != 0) ? aspects : VK_IMAGE_ASPECT_COLOR_BIT;

    is_uniform_     = true;
    uniform_layout_ = VK_IMAGE_LAYOUT_UNDEFINED;
    subresource_layouts_.clear();
}

void ImageLayoutMap::SetUniformLayout(VkImageLayout layout)
{
    is_uniform_     = true;
    uniform_layout_ = layout;
    subresource_layouts_.clear();
}

void ImageLayoutMap::SetLayout(const VkImageSubresourceRange& range, VkImageLayout layout)
{
    if (!IsInitialized())
    {
        return;
    }

    // A range naming no aspect this image has tells us nothing about which subresources moved, so record nothing.
    const VkImageAspectFlags aspect_mask = range.aspectMask & aspects_;
    if (aspect_mask == 0)
    {
        return;
    }

    // Clamping to make sure we don't go out of bounds
    const uint32_t base_mip    = std::min(range.baseMipLevel, mip_levels_);
    const uint32_t level_count = (range.levelCount == VK_REMAINING_MIP_LEVELS)
                                     ? (mip_levels_ - base_mip)
                                     : std::min(range.levelCount, mip_levels_ - base_mip);

    const uint32_t base_layer  = std::min(range.baseArrayLayer, array_layers_);
    const uint32_t layer_count = (range.layerCount == VK_REMAINING_ARRAY_LAYERS)
                                     ? (array_layers_ - base_layer)
                                     : std::min(range.layerCount, array_layers_ - base_layer);

    if ((level_count == 0) || (layer_count == 0))
    {
        return;
    }

    // A transition covering everything returns the tracker to the uniform fast path.
    if ((aspect_mask == aspects_) && (base_mip == 0) && (level_count == mip_levels_) && (base_layer == 0) &&
        (layer_count == array_layers_))
    {
        SetUniformLayout(layout);
        return;
    }

    if (is_uniform_)
    {
        ExpandUniform();
    }

    for (uint32_t aspect_index = 0; aspect_index < kAspectSlotCount; ++aspect_index)
    {
        if ((aspect_mask & GetAspectFromIndex(aspect_index)) == 0)
        {
            continue;
        }

        for (uint32_t mip = base_mip; mip < (base_mip + level_count); ++mip)
        {
            for (uint32_t layer = base_layer; layer < (base_layer + layer_count); ++layer)
            {
                subresource_layouts_[GetSubresourceIndex(aspect_index, mip, layer)] = layout;
            }
        }
    }
}

void ImageLayoutMap::MergeFrom(const ImageLayoutMap& src)
{
    if (!IsInitialized() || !src.IsInitialized())
    {
        return;
    }

    if (src.is_uniform_)
    {
        if (src.uniform_layout_ != VK_IMAGE_LAYOUT_UNDEFINED)
        {
            SetLayout({ aspects_, 0, mip_levels_, 0, array_layers_ }, src.uniform_layout_);
        }
        return;
    }

    if (is_uniform_)
    {
        ExpandUniform();
    }

    GFXRECON_ASSERT((mip_levels_ == src.mip_levels_) && (array_layers_ == src.array_layers_) &&
                    (aspects_ == src.aspects_));

    for (size_t i = 0; i < subresource_layouts_.size(); ++i)
    {
        const VkImageLayout layout = src.subresource_layouts_[i];
        if (layout != VK_IMAGE_LAYOUT_UNDEFINED)
        {
            subresource_layouts_[i] = layout;
        }
    }
}

VkImageLayout ImageLayoutMap::GetLayout(VkImageAspectFlagBits aspect, uint32_t mip_level, uint32_t array_layer) const
{
    if ((aspect & aspects_) == 0 || (mip_level >= mip_levels_) || (array_layer >= array_layers_))
    {
        return VK_IMAGE_LAYOUT_UNDEFINED;
    }

    if (is_uniform_)
    {
        return uniform_layout_;
    }

    const VkImageAspectFlags aspect_mask = aspect & aspects_;
    for (uint32_t aspect_index = 0; aspect_index < kAspectSlotCount; ++aspect_index)
    {
        if ((aspect_mask & GetAspectFromIndex(aspect_index)) != 0)
        {
            return subresource_layouts_[GetSubresourceIndex(aspect_index, mip_level, array_layer)];
        }
    }

    return VK_IMAGE_LAYOUT_UNDEFINED;
}

VkImageAspectFlags GetLayoutAspects(VkImageLayout layout)
{
    switch (layout)
    {
        case VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL:
        case VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL:
            return VK_IMAGE_ASPECT_DEPTH_BIT;

        case VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL:
        case VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL:
            return VK_IMAGE_ASPECT_STENCIL_BIT;

        default:
            return ~VkImageAspectFlags(0);
    }
}

void ImageLayoutMap::ExpandUniform()
{
    is_uniform_ = false;
    subresource_layouts_.assign(static_cast<size_t>(GetAspectSlotCount()) * mip_levels_ * array_layers_,
                                uniform_layout_);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
