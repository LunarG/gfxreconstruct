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

#include "graphics/vulkan_image_layout_map_util.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

namespace
{

ImageLayoutMap
MakeUniformMap(uint32_t mip_levels, uint32_t array_layers, VkImageAspectFlags aspects, VkImageLayout layout)
{
    ImageLayoutMap map;
    map.Initialize(mip_levels, array_layers, aspects);
    map.SetUniformLayout(layout);
    return map;
}

void CheckRange(const VkImageSubresourceRange& actual, const VkImageSubresourceRange& expected)
{
    CHECK(actual.aspectMask == expected.aspectMask);
    CHECK(actual.baseMipLevel == expected.baseMipLevel);
    CHECK(actual.levelCount == expected.levelCount);
    CHECK(actual.baseArrayLayer == expected.baseArrayLayer);
    CHECK(actual.layerCount == expected.layerCount);
}

} // namespace

TEST_CASE("IsRestorableLayout", "[image-layout-map-util]")
{
    CHECK_FALSE(IsRestorableLayout(VK_IMAGE_LAYOUT_UNDEFINED));
    CHECK_FALSE(IsRestorableLayout(VK_IMAGE_LAYOUT_PREINITIALIZED));
    CHECK(IsRestorableLayout(VK_IMAGE_LAYOUT_GENERAL));
}

TEST_CASE("ToBarrierAspects", "[image-layout-map-util]")
{
    const VkImageAspectFlags planes = VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT;

    CHECK(ToBarrierAspects(VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_ASPECT_COLOR_BIT) == VK_IMAGE_ASPECT_COLOR_BIT);
    CHECK(ToBarrierAspects(planes, planes) == VK_IMAGE_ASPECT_COLOR_BIT);
    CHECK(ToBarrierAspects(VK_IMAGE_ASPECT_PLANE_0_BIT, planes) == VK_IMAGE_ASPECT_PLANE_0_BIT);
}

TEST_CASE("AppendImageLayoutBarriers transitions the whole image", "[image-layout-map-util]")
{
    const ImageLayoutMap current = MakeUniformMap(2, 3, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_GENERAL);
    const ImageLayoutMap target =
        MakeUniformMap(2, 3, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

    std::vector<VkImageMemoryBarrier> barriers;
    AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

    REQUIRE(barriers.size() == 1);
    CHECK(barriers[0].oldLayout == VK_IMAGE_LAYOUT_GENERAL);
    CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
    CheckRange(barriers[0].subresourceRange, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 2, 0, 3 });
}

TEST_CASE("AppendImageLayoutBarriers transitions only the changed subresource", "[image-layout-map-util]")
{
    const ImageLayoutMap current = MakeUniformMap(1, 2, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_GENERAL);
    ImageLayoutMap       target  = current;
    target.SetLayout({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 1, 1 }, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

    std::vector<VkImageMemoryBarrier> barriers;
    AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

    REQUIRE(barriers.size() == 1);
    CHECK(barriers[0].oldLayout == VK_IMAGE_LAYOUT_GENERAL);
    CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
    CheckRange(barriers[0].subresourceRange, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 1, 1 });
}

TEST_CASE("AppendImageLayoutBarriers skips matching layouts", "[image-layout-map-util]")
{
    const ImageLayoutMap current = MakeUniformMap(1, 1, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_GENERAL);

    std::vector<VkImageMemoryBarrier> barriers;
    AppendImageLayoutBarriers(VK_NULL_HANDLE, current, current, barriers);

    CHECK(barriers.empty());
}

TEST_CASE("AppendImageLayoutBarriers coalesces depth and stencil with the same transition", "[image-layout-map-util]")
{
    // Change only layer 0 so the map is not uniform and each subresource is visited.
    const VkImageAspectFlags depth_stencil = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
    const ImageLayoutMap     current       = MakeUniformMap(1, 2, depth_stencil, VK_IMAGE_LAYOUT_GENERAL);
    ImageLayoutMap           target        = current;

    std::vector<VkImageMemoryBarrier> barriers;

    SECTION("same transition gives one barrier")
    {
        target.SetLayout({ depth_stencil, 0, 1, 0, 1 }, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

        AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

        REQUIRE(barriers.size() == 1);
        CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        CheckRange(barriers[0].subresourceRange, { depth_stencil, 0, 1, 0, 1 });
    }

    SECTION("different transitions give one barrier each")
    {
        target.SetLayout({ VK_IMAGE_ASPECT_DEPTH_BIT, 0, 1, 0, 1 }, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        target.SetLayout({ VK_IMAGE_ASPECT_STENCIL_BIT, 0, 1, 0, 1 }, VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL);

        AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

        REQUIRE(barriers.size() == 2);
        CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        CheckRange(barriers[0].subresourceRange, { VK_IMAGE_ASPECT_DEPTH_BIT, 0, 1, 0, 1 });
        CHECK(barriers[1].newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL);
        CheckRange(barriers[1].subresourceRange, { VK_IMAGE_ASPECT_STENCIL_BIT, 0, 1, 0, 1 });
    }
}

TEST_CASE("AppendImageLayoutBarriers uses COLOR only when every plane transitions", "[image-layout-map-util]")
{
    // Change only layer 0 so the map is not uniform and each subresource is visited.
    const VkImageAspectFlags planes  = VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT;
    const ImageLayoutMap     current = MakeUniformMap(1, 2, planes, VK_IMAGE_LAYOUT_GENERAL);
    ImageLayoutMap           target  = current;

    std::vector<VkImageMemoryBarrier> barriers;

    SECTION("every plane transitions")
    {
        target.SetLayout({ planes, 0, 1, 0, 1 }, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

        AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

        REQUIRE(barriers.size() == 1);
        CheckRange(barriers[0].subresourceRange, { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 });
    }

    SECTION("one plane transitions")
    {
        target.SetLayout({ VK_IMAGE_ASPECT_PLANE_1_BIT, 0, 1, 0, 1 }, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

        AppendImageLayoutBarriers(VK_NULL_HANDLE, current, target, barriers);

        REQUIRE(barriers.size() == 1);
        CheckRange(barriers[0].subresourceRange, { VK_IMAGE_ASPECT_PLANE_1_BIT, 0, 1, 0, 1 });
    }
}

TEST_CASE("BuildCopyableSubresourceRanges excludes undefined layers", "[image-layout-map-util]")
{
    ImageLayoutMap layouts = MakeUniformMap(1, 3, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_GENERAL);
    layouts.SetLayout({ VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 2, 1 }, VK_IMAGE_LAYOUT_UNDEFINED);

    std::vector<VkImageSubresourceRange> ranges;
    std::vector<VkImageSubresourceRange> excluded_ranges;
    BuildCopyableSubresourceRanges(VK_FORMAT_R8G8B8A8_UNORM, 1, 3, layouts, ranges, excluded_ranges);

    REQUIRE(ranges.size() == 1);
    CheckRange(ranges[0], { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 2 });
    REQUIRE(excluded_ranges.size() == 1);
    CheckRange(excluded_ranges[0], { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 2, 1 });
}

TEST_CASE("AppendTransferLayoutBarriers and ReverseLayoutBarriers", "[image-layout-map-util]")
{
    const ImageLayoutMap current = MakeUniformMap(1, 1, VK_IMAGE_ASPECT_COLOR_BIT, VK_IMAGE_LAYOUT_GENERAL);

    std::vector<VkImageMemoryBarrier> barriers;
    AppendTransferLayoutBarriers(VK_NULL_HANDLE, current, {}, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, barriers);

    REQUIRE(barriers.size() == 1);
    CHECK(barriers[0].oldLayout == VK_IMAGE_LAYOUT_GENERAL);
    CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);

    ReverseLayoutBarriers(barriers);

    CHECK(barriers[0].oldLayout == VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    CHECK(barriers[0].newLayout == VK_IMAGE_LAYOUT_GENERAL);
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
