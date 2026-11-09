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

// Catch must come before the Vulkan headers because Xlib defines None and Always as macros.
#include <catch2/catch.hpp>

#include "graphics/vulkan_image_layout_map.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

namespace
{

constexpr uint32_t              kMipLevels   = 4;
constexpr uint32_t              kArrayLayers = 3;
constexpr VkImageAspectFlagBits kColor       = VK_IMAGE_ASPECT_COLOR_BIT;

ImageLayoutMap MakeColorMap()
{
    ImageLayoutMap map;
    map.Initialize(kMipLevels, kArrayLayers, kColor);
    return map;
}

VkImageSubresourceRange WholeRange()
{
    return { kColor, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS };
}

} // namespace

TEST_CASE("ImageLayoutMap::SetLayout on part of the image", "[image-layout-map]")
{
    ImageLayoutMap map = MakeColorMap();

    // A transition over the whole image keeps the map uniform.
    map.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);

    CHECK(map.IsUniform());
    CHECK(map.GetSubresourceLayout(kColor, 0, 0) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(map.GetSubresourceLayout(kColor, 3, 2) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);

    // Mipmap generation moves one mip level at a time. Here: mip 2, layers 1 and 2.
    map.SetLayout({ kColor, 2, 1, 1, 2 }, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    CHECK_FALSE(map.IsUniform());

    // The transitioned subresources.
    CHECK(map.GetSubresourceLayout(kColor, 2, 1) == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    CHECK(map.GetSubresourceLayout(kColor, 2, 2) == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    // Their neighbors keep the old layout.
    CHECK(map.GetSubresourceLayout(kColor, 2, 0) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(map.GetSubresourceLayout(kColor, 1, 1) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    CHECK(map.GetSubresourceLayout(kColor, 3, 2) == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
}

TEST_CASE("ImageLayoutMap::SetLayout over the whole image makes a split map uniform again", "[image-layout-map]")
{
    ImageLayoutMap map = MakeColorMap();
    map.SetLayout({ kColor, 2, 1, 1, 2 }, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    REQUIRE_FALSE(map.IsUniform());

    map.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

    CHECK(map.IsUniform());

    // A subresource that was split off, and one that was not.
    CHECK(map.GetSubresourceLayout(kColor, 2, 1) == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
    CHECK(map.GetSubresourceLayout(kColor, 0, 0) == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
}

TEST_CASE("ImageLayoutMap::MergeFrom applies only the transitioned subresources", "[image-layout-map]")
{
    ImageLayoutMap image_layouts = MakeColorMap();
    image_layouts.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_GENERAL);

    ImageLayoutMap command_buffer_layouts = MakeColorMap();
    command_buffer_layouts.SetLayout({ kColor, 1, 1, 0, 1 }, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    image_layouts.MergeFrom(command_buffer_layouts);

    // The transitioned subresource.
    CHECK(image_layouts.GetSubresourceLayout(kColor, 1, 0) == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    // The command buffer left these UNDEFINED, so they keep the layout of the image.
    CHECK(image_layouts.GetSubresourceLayout(kColor, 0, 0) == VK_IMAGE_LAYOUT_GENERAL);
    CHECK(image_layouts.GetSubresourceLayout(kColor, 1, 1) == VK_IMAGE_LAYOUT_GENERAL);
    CHECK(image_layouts.GetSubresourceLayout(kColor, 3, 2) == VK_IMAGE_LAYOUT_GENERAL);
}

TEST_CASE("ImageLayoutMap::MergeFrom a command buffer that transitioned the whole image", "[image-layout-map]")
{
    ImageLayoutMap image_layouts = MakeColorMap();
    image_layouts.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_GENERAL);
    image_layouts.SetLayout({ kColor, 2, 1, 1, 2 }, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    REQUIRE_FALSE(image_layouts.IsUniform());

    ImageLayoutMap command_buffer_layouts = MakeColorMap();
    command_buffer_layouts.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
    REQUIRE(command_buffer_layouts.IsUniform());

    image_layouts.MergeFrom(command_buffer_layouts);

    CHECK(image_layouts.IsUniform());

    // A subresource that was split off, and one that was not.
    CHECK(image_layouts.GetSubresourceLayout(kColor, 2, 1) == VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
    CHECK(image_layouts.GetSubresourceLayout(kColor, 0, 0) == VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL);
}

TEST_CASE("ImageLayoutMap::MergeFrom a command buffer that never transitioned the image changes nothing",
          "[image-layout-map]")
{
    ImageLayoutMap image_layouts = MakeColorMap();
    image_layouts.SetLayout(WholeRange(), VK_IMAGE_LAYOUT_GENERAL);
    image_layouts.SetLayout({ kColor, 2, 1, 1, 2 }, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    // Still uniformly UNDEFINED.
    const ImageLayoutMap command_buffer_layouts = MakeColorMap();

    image_layouts.MergeFrom(command_buffer_layouts);

    CHECK_FALSE(image_layouts.IsUniform());
    CHECK(image_layouts.GetSubresourceLayout(kColor, 2, 1) == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    CHECK(image_layouts.GetSubresourceLayout(kColor, 0, 0) == VK_IMAGE_LAYOUT_GENERAL);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
