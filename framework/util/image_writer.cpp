/*
** Copyright (c) 2025 LunarG, Inc.
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
#include "util/file_path.h"
#include "util/logging.h"

#include <assert.h>
#include <cstddef>
#include <cstdint>
#include <inttypes.h>
#include <limits>
#include <math.h>
#include <memory>
#if !defined(WIN32)
#include <unistd.h>
#endif

#if defined(GFXRECON_ENABLE_ZLIB_COMPRESSION) && defined(GFXRECON_ENABLE_PNG_SCREENSHOT)
#include <zlib.h>

// This function re-formats the call to the Zlib compress2 function so that we can
// use it in the STB PNG generation code.  Using the default STB PNG compression
// resulted in a 20% reduction versus the original image in tests, while using the
// zlib compress2 function resulted in a 40+% reduction versus the original image.
uint8_t* GFXRECON_zlib_compress2(uint8_t* data, int32_t data_len, int32_t* out_len, int32_t quality)
{
    unsigned long alloc_len = compressBound(static_cast<uLong>(data_len));
    auto*         target    = reinterpret_cast<uint8_t*>(malloc(alloc_len));
    if (nullptr != target)
    {
        unsigned long ret_len = alloc_len;
        if (Z_OK == compress2(target, &ret_len, data, static_cast<uLong>(data_len), quality))
        {
            *out_len = static_cast<int32_t>(ret_len);
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

static size_t               temporary_buffer_size = 0;
static std::vector<uint8_t> temporary_buffer;

#define CheckFwriteRetVal(_val_, _file_)                                                              \
    {                                                                                                 \
        if (!_val_)                                                                                   \
        {                                                                                             \
            GFXRECON_LOG_ERROR("%s() (%u): fwrite failed (%s)", __func__, __LINE__, strerror(errno)); \
            util::platform::FileClose(_file_);                                                        \
                                                                                                      \
            return false;                                                                             \
        }                                                                                             \
    }

static const uint8_t* ConvertIntoTemporaryBuffer(uint32_t    width,
                                                 uint32_t    height,
                                                 const void* data,
                                                 uint32_t    data_pitch,
                                                 DataFormats format,
                                                 bool        is_png,
                                                 bool        write_alpha)
{
    assert(data_pitch);

    uint32_t output_pitch = width * (write_alpha ? kImageBpp : kImageBppNoAlpha);
    if (!is_png)
    {
        output_pitch = static_cast<uint32_t>(util::platform::GetAlignedSize(output_pitch, 4));
    }

    const uint32_t output_size = height * output_pitch;
    if (temporary_buffer_size < output_size)
    {
        temporary_buffer_size = output_size;
        temporary_buffer.resize(output_size);
    }

    uint8_t* temp_buffer = temporary_buffer.data();

    switch (format)
    {
        case kFormat_RGBA:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t r = bytes[(4 * x) + 0];
                    const uint8_t g = bytes[(4 * x) + 1];
                    const uint8_t b = bytes[(4 * x) + 2];
                    const uint8_t a = bytes[(4 * x) + 3];

                    if (is_png)
                    {
                        *(temp_buffer++) = r;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = b;
                    }
                    else
                    {
                        *(temp_buffer++) = b;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = r;
                    }

                    if (write_alpha)
                    {
                        *(temp_buffer++) = a;
                    }
                }

                bytes += data_pitch;
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        case kFormat_BGR:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t b = bytes[(3 * x) + 0];
                    const uint8_t g = bytes[(3 * x) + 1];
                    const uint8_t r = bytes[(3 * x) + 2];

                    if (is_png)
                    {
                        *(temp_buffer++) = r;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = b;
                    }
                    else
                    {
                        *(temp_buffer++) = b;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = r;
                    }

                    if (write_alpha)
                    {
                        *(temp_buffer++) = 0xff;
                    }
                }

                bytes += data_pitch;
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        case kFormat_BGRA:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t b = bytes[(4 * x) + 0];
                    const uint8_t g = bytes[(4 * x) + 1];
                    const uint8_t r = bytes[(4 * x) + 2];
                    const uint8_t a = bytes[(4 * x) + 3];

                    if (is_png)
                    {
                        *(temp_buffer++) = r;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = b;
                    }
                    else
                    {
                        *(temp_buffer++) = b;
                        *(temp_buffer++) = g;
                        *(temp_buffer++) = r;
                    }

                    if (write_alpha)
                    {
                        *(temp_buffer++) = a;
                    }
                }

                bytes += data_pitch;
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        case kFormat_D32_FLOAT:
        {
            const float* floats = reinterpret_cast<const float*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const float   float_depth = floats[x];
                    const uint8_t depth       = static_cast<uint8_t>(float_depth * 255.0f);

                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;

                    if (write_alpha)
                    {
                        *(temp_buffer++) = 0xff;
                    }
                }

                floats      = reinterpret_cast<const float*>(reinterpret_cast<const uint8_t*>(floats) + data_pitch);
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        case kFormat_D24_UNORM:
        {
            const uint32_t* bytes_u32 = reinterpret_cast<const uint32_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint32_t normalized_depth = bytes_u32[x] & 0x00FFFFFF;
                    const float    float_depth = static_cast<float>(normalized_depth) / static_cast<float>(0xffffff);
                    const uint8_t  depth       = static_cast<uint8_t>(float_depth * 255.0f);

                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;

                    if (write_alpha)
                    {
                        *(temp_buffer++) = 0xff;
                    }
                }

                bytes_u32 = reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(bytes_u32) + data_pitch);
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        case kFormat_D16_UNORM:
        {
            const uint16_t* bytes_u16 = reinterpret_cast<const uint16_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint16_t normalized_depth = bytes_u16[x];
                    const float    float_depth      = static_cast<float>(normalized_depth) / static_cast<float>(0xffff);
                    const uint8_t  depth            = static_cast<uint8_t>(float_depth * 255.0f);

                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;
                    *(temp_buffer++) = depth;

                    if (write_alpha)
                    {
                        *(temp_buffer++) = 0xff;
                    }
                }

                bytes_u16 = reinterpret_cast<const uint16_t*>(reinterpret_cast<const uint8_t*>(bytes_u16) + data_pitch);
                temp_buffer = temporary_buffer.data() + (y + 1) * output_pitch;
            }
        }
        break;

        default:
            GFXRECON_LOG_ERROR("Format %u not handled", format);
            assert(0);
            return nullptr;
    }

    return reinterpret_cast<const uint8_t*>(temporary_buffer.data());
}

static uint8_t*
ExtractAlphaChannel(uint32_t width, uint32_t height, const void* data, uint32_t data_pitch, bool expand_to_rgb)
{
    const size_t output_size = width * height * (expand_to_rgb ? kImageBppNoAlpha : 1);
    if (temporary_buffer_size < output_size)
    {
        temporary_buffer_size = output_size;
        temporary_buffer.resize(output_size);
    }

    const uint32_t* pixels      = reinterpret_cast<const uint32_t*>(data);
    uint8_t*        temp_buffer = temporary_buffer.data();

    for (uint32_t y = 0; y < height; ++y)
    {
        for (uint32_t x = 0; x < width; ++x)
        {
            const auto alpha = static_cast<uint8_t>((pixels[x] & 0xff000000) >> 24);

            *(temp_buffer++) = alpha;

            if (expand_to_rgb)
            {
                *(temp_buffer++) = alpha;
                *(temp_buffer++) = alpha;
            }
        }

        pixels = reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(pixels) + data_pitch);
    }

    return temporary_buffer.data();
}

static bool WriteBmpHeader(FILE* file, uint32_t width, uint32_t height, bool write_alpha)
{
    assert(file);

    // BMP image data requires row to be a multiple of 4 bytes
    // Round-up row size to next multiple of 4, if it isn't already
    const uint32_t bmp_pitch =
        static_cast<uint32_t>(util::platform::GetAlignedSize(width * (write_alpha ? kImageBpp : kImageBppNoAlpha), 4));

    BmpFileHeader file_header;
    BmpInfoHeader info_header;

    file_header.type      = ('M' << 8) | 'B';
    file_header.reserved1 = 0;
    file_header.reserved2 = 0;
    file_header.off_bits  = sizeof(file_header) + sizeof(info_header);
    file_header.size      = (height * bmp_pitch) + file_header.off_bits;

    info_header.size             = sizeof(info_header);
    info_header.width            = static_cast<int32_t>(width);
    info_header.height           = static_cast<int32_t>(height);
    info_header.planes           = 1;
    info_header.bit_count        = write_alpha ? kBmpBitCount : kBmpBitCountNoAlpha;
    info_header.compression      = 0;
    info_header.size_image       = 0;
    info_header.x_pels_per_meter = 0;
    info_header.y_pels_per_meter = 0;
    info_header.clr_used         = 0;
    info_header.clr_important    = 0;

    bool ret = util::platform::FileWrite(&file_header, sizeof(file_header), file);
    CheckFwriteRetVal(ret, file);

    ret = util::platform::FileWrite(&info_header, sizeof(info_header), file);
    CheckFwriteRetVal(ret, file);

    return true;
}

bool WriteBmpImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   const void*        data,
                   uint32_t           data_pitch,
                   DataFormats        format,
                   bool               write_alpha)
{
    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    if (data_pitch == 0)
    {
        data_pitch = static_cast<uint32_t>(width * DataFormatsSizes(format));
        if (data_pitch == 0)
        {
            GFXRECON_LOG_ERROR("%s() Failed writing file (data_pitch == 0)", __func__);
            return false;
        }
    }

    bool    success = false;
    FILE*   file    = nullptr;
    int32_t result  = util::platform::FileOpen(&file, filename.c_str(), "wb");

    if ((result == 0) && (file != nullptr))
    {
        success = WriteBmpHeader(file, width, height, write_alpha);
        if (!success)
        {
            GFXRECON_LOG_ERROR("%s() Failed writing file", __func__);
            return false;
        }

        // Y needs to be inverted when writing the bitmap data.
        auto height_1 = height - 1;

        if ((format == kFormat_BGR && !write_alpha) || (format == kFormat_BGRA && write_alpha))
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
            for (uint32_t y = 0; y < height; ++y)
            {
                success = util::platform::FileWrite(&bytes[(height_1 - y) * data_pitch], data_pitch, file);
                CheckFwriteRetVal(success, file);
            }
        }
        else
        {
            const uint32_t bmp_pitch = static_cast<uint32_t>(
                util::platform::GetAlignedSize(width * (write_alpha ? kImageBpp : kImageBppNoAlpha), 4));

            const uint8_t* bytes =
                ConvertIntoTemporaryBuffer(width, height, data, data_pitch, format, false, write_alpha);
            for (uint32_t y = 0; y < height; ++y)
            {
                success = util::platform::FileWrite(&bytes[(height_1 - y) * bmp_pitch], bmp_pitch, file);
                CheckFwriteRetVal(success, file);
            }
        }

        if (!ferror(file))
        {
            success = true;
        }

        util::platform::FileClose(file);
    }
    else
    {
        GFXRECON_LOG_ERROR("%s() Failed to open file (%s)", __func__, strerror(errno));
    }

    return success;
}

bool WriteBmpImageSeparateAlpha(const std::string& filename,
                                uint32_t           width,
                                uint32_t           height,
                                const void*        data,
                                uint32_t           data_pitch,
                                DataFormats        data_format)
{
    bool success = WriteBmpImage(filename, width, height, data, data_pitch, data_format, false);

    if (success && DataFormatHasAlpha(data_format))
    {
        const uint8_t*    alpha_channel  = ExtractAlphaChannel(width, height, data, data_pitch, true);
        const std::string alpha_filename = util::filepath::InsertFilenamePostfix(filename, "_alpha");
        const size_t      alpha_pitch    = width * kImageBppNoAlpha;
        const DataFormats alpha_format   = data_format == kFormat_BGRA ? kFormat_BGR : kFormat_RGB;
        success                          = WriteBmpImage(
            alpha_filename, width, height, alpha_channel, static_cast<uint32_t>(alpha_pitch), alpha_format, false);
    }

    return success;
}

bool WritePngImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   const void*        data,
                   uint32_t           data_pitch,
                   DataFormats        format,
                   bool               write_alpha)
{
    bool success = false;

#ifdef GFXRECON_ENABLE_PNG_SCREENSHOT
    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    if (data_pitch == 0)
    {
        data_pitch = static_cast<uint32_t>(width * DataFormatsSizes(format));
        if (data_pitch == 0)
        {
            GFXRECON_LOG_ERROR("%s() Failed writing file (data_pitch == 0)", __func__);
            return false;
        }
    }

    const uint8_t* bytes = ConvertIntoTemporaryBuffer(width, height, data, data_pitch, format, true, write_alpha);

    stbi_write_png_compression_level = 4;
    const uint32_t png_row_pitch     = width * (write_alpha ? kImageBpp : kImageBppNoAlpha);

    if (1 == stbi_write_png(filename.c_str(),
                            static_cast<int>(width),
                            static_cast<int>(height),
                            static_cast<int>(write_alpha ? kImageBpp : kImageBppNoAlpha),
                            bytes,
                            (int)png_row_pitch))
    {
        success = true;
    }
    else
    {
        GFXRECON_LOG_ERROR("%s() Failed writing file", __func__);
    }
#endif

    return success;
}

bool WritePngImageSeparateAlpha(const std::string& filename,
                                uint32_t           width,
                                uint32_t           height,
                                const void*        data,
                                uint32_t           data_pitch,
                                DataFormats        format)
{
    bool success = WritePngImage(filename, width, height, data, data_pitch, format, false);
    if (success && DataFormatHasAlpha(format))
    {
        const std::string alpha_filename = util::filepath::InsertFilenamePostfix(filename, "_alpha");
        const uint8_t*    alpha_channel  = ExtractAlphaChannel(width, height, data, data_pitch, false);
        const size_t      alpha_pitch    = width;
        success                          = stbi_write_png(alpha_filename.c_str(),
                                 static_cast<int>(width),
                                 static_cast<int>(height),
                                 1,
                                 alpha_channel,
                                 static_cast<int>(alpha_pitch));

        if (!success)
        {
            GFXRECON_LOG_ERROR("%s() Failed writing file %s", __func__, alpha_filename.c_str());
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(imagewriter)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
