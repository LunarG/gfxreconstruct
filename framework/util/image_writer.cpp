/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
*
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

#include "image_writer.h"

#include "platform.h"

#if defined(GFXRECON_ENABLE_ZLIB_COMPRESSION) && defined(GFXRECON_ENABLE_PNG_SCREENSHOT)
#include <zlib.h>

// This function re-formats the call to the Zlib compress2 function so that we can
// use it in the STB PNG generation code.  Using the default STB PNG compression
// resulted in a 20% reduction versus the original image in tests, while using the
// zlib compress2 function resulted in a 40+% reduction versus the original image.
uint8_t* GFXRECON_zlib_compress2(uint8_t* data, int32_t data_len, int32_t* out_len, int32_t quality)
{
    uint8_t* target = reinterpret_cast<uint8_t*>(malloc(data_len));
    if (nullptr != target)
    {
        unsigned long ret_len = data_len;
        if (Z_OK == compress2(target, &ret_len, data, data_len, quality))
        {
            *out_len = ret_len;
            return target;
        }
        free(target);
    }
    return nullptr;
}
#define STBIW_ZLIB_COMPRESS GFXRECON_zlib_compress2

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_STATIC

#if defined(WIN32)
#define __STDC_LIB_EXT1__
#endif

#include <stb_image_write.h>
#endif // GFXRECON_ENABLE_ZLIB_COMPRESSION && GFXRECON_ENABLE_PNG_SCREENSHOT

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(imagewriter)

const uint16_t kBmpBitCount = 32; // Expecting 32-bit BGRA bitmap data.
const uint32_t kImageBpp    = 4;  // Expecting 4 bytes per pixel for 32-bit BGRA bitmap data.

const uint16_t kBmpBitCountNoAlpha = 24; // Expecting 24-bit BGR bitmap data.
const uint32_t kImageBppNoAlpha    = 3;  // Expecting 3 bytes per pixel for 32-bit BGRA bitmap data; alpha removed.

bool WriteBmpImage(
    const std::string& filename, uint32_t width, uint32_t height, uint64_t data_size, const void* data, uint32_t pitch)
{
    bool     success   = false;
    uint32_t row_pitch = width * kImageBpp;

    if (pitch != 0)
    {
        row_pitch = pitch;
    }

    // BMP image data doesn't require row padding, so compute size with height * width * kImageBpp, not row_pitch *
    // height.
    uint32_t bmp_image_size = height * width * kImageBpp;
    if (bmp_image_size <= data_size)
    {
        FILE*   file   = nullptr;
        int32_t result = util::platform::FileOpen(&file, filename.c_str(), "wb");

        if ((result == 0) && (file != nullptr))
        {
            BmpFileHeader file_header;
            BmpInfoHeader info_header;

            file_header.type      = ('M' << 8) | 'B';
            file_header.reserved1 = 0;
            file_header.reserved2 = 0;
            file_header.off_bits  = sizeof(file_header) + sizeof(info_header);
            file_header.size      = bmp_image_size + file_header.off_bits;

            info_header.size             = sizeof(info_header);
            info_header.width            = width;
            info_header.height           = height;
            info_header.planes           = 1;
            info_header.bit_count        = kBmpBitCount;
            info_header.compression      = 0;
            info_header.size_image       = 0;
            info_header.x_pels_per_meter = 0;
            info_header.y_pels_per_meter = 0;
            info_header.clr_used         = 0;
            info_header.clr_important    = 0;

            util::platform::FileWrite(&file_header, sizeof(file_header), 1, file);
            util::platform::FileWrite(&info_header, sizeof(info_header), 1, file);

            // Y needs to be inverted when writing the bitmap data.
            auto height_1 = height - 1;
            auto bytes    = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t i = 0; i < height; ++i)
            {
                util::platform::FileWrite(&bytes[(height_1 - i) * row_pitch], 1, width * kImageBpp, file);
            }

            if (!ferror(file))
            {
                success = true;
            }

            util::platform::FileClose(file);
        }
    }

    return success;
}

bool WriteBmpImageNoAlpha(
    const std::string& filename, uint32_t width, uint32_t height, uint64_t data_size, const void* data, uint32_t pitch)
{
    bool     success   = false;
    uint32_t row_pitch = width * kImageBpp;

    if (pitch != 0)
    {
        row_pitch = pitch;
    }

    // BMP image data requires row to be a multiple of 4 bytes
    // Round-up row size to next multiple of 4, if it isn't already
    const uint32_t rowSizeNoAlpha = util::platform::GetAlignedSize(width * kImageBppNoAlpha, 4);
    uint32_t       bmp_image_size = height * rowSizeNoAlpha;
    if (bmp_image_size <= data_size)
    {
        FILE*   file   = nullptr;
        int32_t result = util::platform::FileOpen(&file, filename.c_str(), "wb");

        if ((result == 0) && (file != nullptr))
        {
            BmpFileHeader file_header;
            BmpInfoHeader info_header;

            file_header.type      = ('M' << 8) | 'B';
            file_header.reserved1 = 0;
            file_header.reserved2 = 0;
            file_header.off_bits  = sizeof(file_header) + sizeof(info_header);
            file_header.size      = bmp_image_size + file_header.off_bits;

            info_header.size             = sizeof(info_header);
            info_header.width            = width;
            info_header.height           = height;
            info_header.planes           = 1;
            info_header.bit_count        = kBmpBitCountNoAlpha;
            info_header.compression      = 0;
            info_header.size_image       = 0;
            info_header.x_pels_per_meter = 0;
            info_header.y_pels_per_meter = 0;
            info_header.clr_used         = 0;
            info_header.clr_important    = 0;

            util::platform::FileWrite(&file_header, sizeof(file_header), 1, file);
            util::platform::FileWrite(&info_header, sizeof(info_header), 1, file);

            // Y needs to be inverted when writing the bitmap data.
            auto height_1 = height - 1;
            auto bytes    = reinterpret_cast<const uint8_t*>(data);

            // Row data without alpha
            std::vector<uint8_t> rowBytes(rowSizeNoAlpha, 0);
            for (uint32_t i = 0; i < height; ++i)
            {
                const uint32_t bytesOffset = (height_1 - i) * row_pitch;
                for (uint32_t j = 0; j < width; j++)
                {
                    memcpy(&rowBytes[j * kImageBppNoAlpha], &bytes[bytesOffset + (j * kImageBpp)], kImageBppNoAlpha);
                }
                util::platform::FileWrite(rowBytes.data(), 1, rowSizeNoAlpha, file);
            }

            if (!ferror(file))
            {
                success = true;
            }

            util::platform::FileClose(file);
        }
    }

    return success;
}

bool WritePngImage(
    const std::string& filename, uint32_t width, uint32_t height, uint64_t data_size, const void* data, uint32_t pitch)
{
    bool success = false;

#ifdef GFXRECON_ENABLE_PNG_SCREENSHOT
    uint32_t row_pitch               = pitch == 0 ? width * kImageBpp : pitch;
    stbi_write_png_compression_level = 4;
    if (1 == stbi_write_png(filename.c_str(), width, height, kImageBpp, data, row_pitch))
    {
        success = true;
    }
#endif

    return success;
}

bool WritePngImageNoAlpha(
    const std::string& filename, uint32_t width, uint32_t height, uint64_t data_size, const void* data, uint32_t pitch)
{
    bool success = false;

#ifdef GFXRECON_ENABLE_PNG_SCREENSHOT
    uint32_t row_pitch               = pitch == 0 ? width * kImageBpp : pitch;
    stbi_write_png_compression_level = 4;

    const uint32_t       row_pitch_no_alpha = (row_pitch * kImageBppNoAlpha) / kImageBpp;
    std::vector<uint8_t> dataNoAlpha(height * kImageBppNoAlpha * row_pitch_no_alpha);
    auto                 dataWithAlpha = reinterpret_cast<const uint8_t*>(data);
    for (uint32_t i = 0; i < height; i++)
    {
        const uint32_t offset_with_alpha = i * row_pitch;
        const uint32_t offset_no_alpha   = i * row_pitch_no_alpha;
        for (uint32_t j = 0; j < width; j++)
        {
            memcpy(&dataNoAlpha[offset_no_alpha + (j * kImageBppNoAlpha)],
                   &dataWithAlpha[offset_with_alpha + (j * kImageBpp)],
                   kImageBppNoAlpha);
        }
    }
    if (1 == stbi_write_png(filename.c_str(), width, height, kImageBppNoAlpha, dataNoAlpha.data(), row_pitch_no_alpha))
    {
        success = true;
    }
#endif
    return success;
}

GFXRECON_END_NAMESPACE(imagewriter)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
