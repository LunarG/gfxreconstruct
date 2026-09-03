#include "util/image_writer.h"
#include "util/options.h"

#include <catch2/catch.hpp>

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

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

namespace
{

std::vector<uint8_t> ReadWholeFile(const std::string& path)
{
    std::ifstream file(path, std::ios::binary);
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

} // namespace

// A bitmap row is aligned to four bytes.  The conversion writes width * 3 bytes
// and skips to the next row, and the buffer it writes into is kept between
// calls, thus the alignment gap used to carry bytes of the image written before
// this one.  The same image written twice gave two different files.
//
// A width of 7 gives a row of 21 bytes, which aligns to 24: three bytes of gap
// per row.  A width of 8 gives 24 already and never had the problem, which is
// why the common resolutions hid it.
TEST_CASE("ImageWriter::WriteBmpImage row padding is deterministic", "[image_writer]")
{
    using gfxrecon::util::ScreenshotFormat;
    namespace imagewriter = gfxrecon::util::imagewriter;

    const uint32_t       height = 5;
    std::vector<uint8_t> pixels(8 * height * 4);
    for (size_t i = 0; i < pixels.size(); ++i)
    {
        pixels[i] = static_cast<uint8_t>((i * 7) + 3);
    }

    // Written between the two runs, to leave something behind in the shared
    // conversion buffer.  Larger, so the buffer grows and holds its bytes.
    std::vector<uint8_t> other(64 * 64 * 4, 0xab);

    auto write_twice_and_compare = [&](uint32_t width) {
        const std::string first  = "image_writer_padding_first.bmp";
        const std::string second = "image_writer_padding_second.bmp";

        REQUIRE(imagewriter::WriteBmpImage(first, width, height, pixels.data(), 8 * 4));
        REQUIRE(imagewriter::WriteBmpImage("image_writer_padding_other.bmp", 64, 64, other.data(), 64 * 4));
        REQUIRE(imagewriter::WriteBmpImage(second, width, height, pixels.data(), 8 * 4));

        const std::vector<uint8_t> first_bytes  = ReadWholeFile(first);
        const std::vector<uint8_t> second_bytes = ReadWholeFile(second);

        REQUIRE_FALSE(first_bytes.empty());
        REQUIRE(first_bytes == second_bytes);
    };

    SECTION("a width whose row needs padding")
    {
        write_twice_and_compare(7);
    }

    SECTION("a width whose row is already aligned")
    {
        write_twice_and_compare(8);
    }
}

// The alpha file of a separate-alpha write holds the alpha channel of the
// source, with each value put in all three colour channels, thus the file is
// grey.  Two faults stopped that from happening.
//
// The extraction wrote the grey pixels into the conversion buffer and gave that
// buffer to the writer as its source, thus the conversion read and wrote one
// buffer.  A bitmap row is aligned to four bytes, so the write ran ahead of the
// read and destroyed the rows it had not read yet.
//
// A source that is not BGRA also asked for kFormat_RGB, which the conversion
// has no arm for, thus the write asserted and returned a null pointer.
namespace
{

// Whether every pixel of a 24-bit bitmap is grey and matches the expected alpha.
bool AlphaFileIsGrey(const std::string& path, uint32_t width, uint32_t height, const std::vector<uint8_t>& expected)
{
    const std::vector<uint8_t> bytes = ReadWholeFile(path);

    const uint32_t aligned_row = ((width * 3) + 3) & ~3u;

    // A bitmap row is aligned to four bytes, thus the file holds exactly this.
    if (bytes.size() != (54 + (aligned_row * height)))
    {
        return false;
    }

    const uint8_t* pixel_start = bytes.data() + 54;

    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            // A bitmap holds its rows from the bottom up.
            const uint8_t* p = pixel_start + ((height - 1 - y) * aligned_row) + (x * 3);
            if ((p[0] != p[1]) || (p[1] != p[2]) || (p[0] != expected[(y * width) + x]))
            {
                return false;
            }
        }
    }

    return true;
}

} // namespace

TEST_CASE("ImageWriter::WriteBmpImageSeparateAlpha writes the alpha channel", "[image_writer]")
{
    namespace imagewriter = gfxrecon::util::imagewriter;

    // A width whose three-byte rows need alignment padding, which is what made
    // the write run ahead of the read.
    const uint32_t width  = 7;
    const uint32_t height = 5;

    std::vector<uint8_t> pixels(width * height * 4);
    std::vector<uint8_t> expected_alpha(width * height);

    for (uint32_t i = 0; i < width * height; ++i)
    {
        const uint8_t alpha = static_cast<uint8_t>((i * 9) + 17);
        pixels[(i * 4) + 0] = static_cast<uint8_t>(i);
        pixels[(i * 4) + 1] = static_cast<uint8_t>(i + 1);
        pixels[(i * 4) + 2] = static_cast<uint8_t>(i + 2);
        pixels[(i * 4) + 3] = alpha;
        expected_alpha[i]   = alpha;
    }

    SECTION("a BGRA source")
    {
        const std::string name = "image_writer_alpha_bgra.bmp";
        REQUIRE(imagewriter::WriteBmpImageSeparateAlpha(
            name, width, height, pixels.data(), width * 4, imagewriter::kFormat_BGRA));
        REQUIRE(AlphaFileIsGrey("image_writer_alpha_bgra_alpha.bmp", width, height, expected_alpha));
    }

    SECTION("an RGBA source")
    {
        const std::string name = "image_writer_alpha_rgba.bmp";
        REQUIRE(imagewriter::WriteBmpImageSeparateAlpha(
            name, width, height, pixels.data(), width * 4, imagewriter::kFormat_RGBA));
        REQUIRE(AlphaFileIsGrey("image_writer_alpha_rgba_alpha.bmp", width, height, expected_alpha));
    }
}
