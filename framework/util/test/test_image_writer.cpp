#include "util/image_writer.h"

#include <catch2/catch.hpp>

TEST_CASE("ImageWriter::RotateAndMirrorPixels test", "[image_writer]")
{
    // Source image: 3x4 pixels (width = 3, height = 4)
    // 1,  2,  3
    // 4,  5,  6
    // 7,  8,  9
    // 10, 11, 12
    const std::vector<uint32_t> src_pixels = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    const uint32_t              src_width  = 3;
    const uint32_t              src_height = 4;

    using ImageRotation = gfxrecon::util::imagewriter::ImageRotation;

    SECTION("DEG_0, no mirror")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_0,
                                                           false,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           src_width,
                                                           src_height);
        const std::vector<uint32_t> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_90, no mirror")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        const uint32_t        dst_width  = 4;
        const uint32_t        dst_height = 3;
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_90,
                                                           false,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           dst_width,
                                                           dst_height);
        const std::vector<uint32_t> expected = { 3, 6, 9, 12, 2, 5, 8, 11, 1, 4, 7, 10 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_180, no mirror")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_180,
                                                           false,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           src_width,
                                                           src_height);
        const std::vector<uint32_t> expected = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_270, no mirror")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        const uint32_t        dst_width  = 4;
        const uint32_t        dst_height = 3;
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_270,
                                                           false,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           dst_width,
                                                           dst_height);
        const std::vector<uint32_t> expected = { 10, 7, 4, 1, 11, 8, 5, 2, 12, 9, 6, 3 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_0, mirrored")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_0,
                                                           true,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           src_width,
                                                           src_height);
        const std::vector<uint32_t> expected = { 3, 2, 1, 6, 5, 4, 9, 8, 7, 12, 11, 10 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_90, mirrored")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        const uint32_t        dst_width  = 4;
        const uint32_t        dst_height = 3;
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_90,
                                                           true,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           dst_width,
                                                           dst_height);
        const std::vector<uint32_t> expected = { 12, 9, 6, 3, 11, 8, 5, 2, 10, 7, 4, 1 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_180, mirrored")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_180,
                                                           true,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           src_width,
                                                           src_height);
        const std::vector<uint32_t> expected = { 10, 11, 12, 7, 8, 9, 4, 5, 6, 1, 2, 3 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("DEG_270, mirrored")
    {
        std::vector<uint32_t> dst_pixels(12, 0);
        const uint32_t        dst_width  = 4;
        const uint32_t        dst_height = 3;
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(ImageRotation::DEG_270,
                                                           true,
                                                           src_pixels.data(),
                                                           dst_pixels.data(),
                                                           src_width,
                                                           src_height,
                                                           dst_width,
                                                           dst_height);
        const std::vector<uint32_t> expected = { 1, 4, 7, 10, 2, 5, 8, 11, 3, 6, 9, 12 };
        REQUIRE(dst_pixels == expected);
    }

    SECTION("Loop tiling verification (40x35 image)")
    {
        const uint32_t        w = 40;
        const uint32_t        h = 35;
        std::vector<uint32_t> src(w * h);
        for (uint32_t i = 0; i < w * h; ++i)
        {
            src[i] = i;
        }

        // Test DEG_90
        std::vector<uint32_t> dst_tiled(w * h, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(
            ImageRotation::DEG_90, false, src.data(), dst_tiled.data(), w, h, h, w);

        // Reference DEG_90 (no tiling)
        std::vector<uint32_t> dst_ref(w * h, 0);
        for (uint32_t dy = 0; dy < w; ++dy)
        {
            for (uint32_t dx = 0; dx < h; ++dx)
            {
                uint32_t sx          = w - 1 - dy;
                uint32_t sy          = dx;
                dst_ref[dy * h + dx] = src[sy * w + sx];
            }
        }
        REQUIRE(dst_tiled == dst_ref);

        // Test DEG_90 mirrored
        std::vector<uint32_t> dst_tiled_m(w * h, 0);
        gfxrecon::util::imagewriter::RotateAndMirrorPixels(
            ImageRotation::DEG_90, true, src.data(), dst_tiled_m.data(), w, h, h, w);

        // Reference DEG_90 mirrored (no tiling)
        std::vector<uint32_t> dst_ref_m(w * h, 0);
        for (uint32_t dy = 0; dy < w; ++dy)
        {
            for (uint32_t dx = 0; dx < h; ++dx)
            {
                uint32_t mirrored_dx   = h - 1 - dx; // mirror in dest
                uint32_t sx            = w - 1 - dy;
                uint32_t sy            = mirrored_dx;
                dst_ref_m[dy * h + dx] = src[sy * w + sx];
            }
        }
        REQUIRE(dst_tiled_m == dst_ref_m);
    }
}
