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
#include "logging.h"

#include "platform.h"

#include <cstddef>
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

static std::unique_ptr<uint8_t[]> temporary_buffer;
static size_t                     temporary_buffer_size = 0;

// This function is a copy from Renderdoc sources
inline float ConvertFromHalf(uint16_t comp)
{
    bool sign     = (comp & 0x8000) != 0;
    int  exponent = (comp & 0x7C00) >> 10;
    int  mantissa = comp & 0x03FF;

    if (exponent == 0x00)
    {
        if (mantissa == 0)
            return sign ? -0.0f : 0.0f;

        // subnormal
        float ret   = (float)mantissa;
        int*  alias = (int*)&ret;

        // set sign bit and set exponent to 2^-24
        // (2^-14 from spec for subnormals * 2^-10 to convert (float)mantissa to 0.mantissa)
        *alias = (sign ? 0x80000000 : 0) | (*alias - (24 << 23));

        return ret;
    }
    else if (exponent < 0x1f)
    {
        exponent -= 15;

        float ret   = 0.0f;
        int*  alias = (int*)&ret;

        // convert to float. Put sign bit in the right place, convert exponent to be
        // [-128,127] and put in the right place, then shift mantissa up.
        *alias = (sign ? 0x80000000 : 0) | (exponent + 127) << 23 | (mantissa << 13);

        return ret;
    }
    else // if(exponent = 0x1f)
    {
        union
        {
            int   i;
            float f;
        } ret;

        if (mantissa == 0)
            ret.i = (sign ? 0x80000000 : 0) | 0x7F800000;
        else
            ret.i = 0x7F800001;

        return ret.f;
    }
}

// This function is a copy from Renderdoc sources
static float Ufloat11ToFloat(uint16_t val)
{
    const uint32_t        mantissa = val & 0x3f;
    const uint32_t        exponent = (val >> 6) & 0x1f;
    static const uint32_t lead_bit = 0x40;

    if (mantissa == 0 && exponent == 0)
    {
        return 0.0f;
    }
    else
    {
        if (exponent == 0x1f)
        {
            if (mantissa == 0)
            {
                // +inf
                return std::numeric_limits<float>::max();
            }
            else
            {
                // NaN... I don't think we want a Nan in a pixel
                return 0.0f;
            }
        }
        else if (exponent != 0)
        {
            uint32_t combined = lead_bit | mantissa;
            return (static_cast<float>(combined) / static_cast<float>(lead_bit)) *
                   pow(2.0f, static_cast<float>(exponent) - 15.0f);
        }
        else /* if (exponent == 0) */
        {
            return static_cast<float>(mantissa) / static_cast<float>(lead_bit) * pow(2.0f, 1.0f - 15.0f);
        }
    }
}

// This function is a copy from Renderdoc sources
static float Ufloat10ToFloat(uint16_t val)
{
    const uint32_t        mantissa = val & 0x1f;
    const uint32_t        exponent = (val >> 5) & 0x1f;
    static const uint32_t lead_bit = 0x20;

    if (mantissa == 0 && exponent == 0)
    {
        return 0.0f;
    }
    else
    {
        if (exponent == 0x1f)
        {
            if (mantissa == 0)
            {
                // +inf
                return std::numeric_limits<float>::max();
            }
            else
            {
                // NaN... I don't think we want a Nan in a pixel
                return 0.0f;
            }
        }
        else if (exponent != 0)
        {
            uint32_t combined = lead_bit | mantissa;
            return (static_cast<float>(combined) / static_cast<float>(lead_bit)) *
                   pow(2.0f, static_cast<float>(exponent) - 15.0f);
        }
        else /* if (exponent == 0) */
        {
            return static_cast<float>(mantissa) / static_cast<float>(lead_bit) * pow(2.0f, 1.0f - 15.0f);
        }
    }
}

#define CheckFwriteRetVal(_val_, _expected_, _file_)                                                  \
    {                                                                                                 \
        if (_val_ != _expected_)                                                                      \
        {                                                                                             \
            GFXRECON_LOG_ERROR("%s() (%u): fwrite failed (%s)", __func__, __LINE__, strerror(errno)); \
            util::platform::FileClose(_file_);                                                        \
                                                                                                      \
            return false;                                                                             \
        }                                                                                             \
    }

static const uint8_t* ConvertIntoTemporaryBuffer(
    uint32_t width, uint32_t height, const void* data, uint32_t* row_pitch, DataFormats format, bool is_png)
{
    static std::unique_ptr<uint8_t[]> temporary_buffer;
    static size_t                     temporary_buffer_size = 0;

    const uint32_t output_size = width * height * kImageBpp;
    if (output_size > temporary_buffer_size)
    {
        temporary_buffer_size = output_size;
        temporary_buffer      = std::make_unique<uint8_t[]>(output_size);
    }

    uint32_t* temp_buffer = reinterpret_cast<uint32_t*>(temporary_buffer.get());

    switch (format)
    {
        case kFormat_R8:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t r = bytes[y * width + x];

                    const uint32_t rgba = (0xff << 24) | (r << 16) | (r << 8) | r;
                    *(temp_buffer++)    = rgba;
                }
            }
        }
        break;

        case kFormat_RGB:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t r = bytes[y * 3 * width + (3 * x) + 0];
                    const uint8_t g = bytes[y * 3 * width + (3 * x) + 1];
                    const uint8_t b = bytes[y * 3 * width + (3 * x) + 2];

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (0xff << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (0xff << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        case kFormat_RGBA:
        {
            const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const uint8_t r = bytes[y * 4 * width + (4 * x) + 0];
                    const uint8_t g = bytes[y * 4 * width + (4 * x) + 1];
                    const uint8_t b = bytes[y * 4 * width + (4 * x) + 2];
                    const uint8_t a = bytes[y * 4 * width + (4 * x) + 3];

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
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
                    const uint8_t b = bytes[y * 3 * width + (3 * x) + 0];
                    const uint8_t g = bytes[y * 3 * width + (3 * x) + 1];
                    const uint8_t r = bytes[y * 3 * width + (3 * x) + 2];

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (0xff << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (0xff << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
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
                    const uint8_t b = bytes[y * 4 * width + (4 * x) + 0];
                    const uint8_t g = bytes[y * 4 * width + (4 * x) + 1];
                    const uint8_t r = bytes[y * 4 * width + (4 * x) + 2];
                    const uint8_t a = bytes[y * 4 * width + (4 * x) + 3];

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        case kFormat_B10G11R11_UFLOAT:
        {
            const uint32_t* u32_vals = reinterpret_cast<const uint32_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    // clang-format off
                    const float b = Ufloat10ToFloat(static_cast<uint16_t>((u32_vals[y * width + x] & (0xFFC00000)) >> 22));
                    const float g = Ufloat11ToFloat(static_cast<uint16_t>((u32_vals[y * width + x] & (0x003FF800)) >> 11));
                    const float r = Ufloat11ToFloat(static_cast<uint16_t>((u32_vals[y * width + x] & (0x000007FF)) >> 0));
                    // clang-format on

                    const uint8_t b_u8 = static_cast<uint8_t>(std::min(b, 1.0f) * 255.0f);
                    const uint8_t g_u8 = static_cast<uint8_t>(std::min(g, 1.0f) * 255.0f);
                    const uint8_t r_u8 = static_cast<uint8_t>(std::min(r, 1.0f) * 255.0f);

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (0xff << 24) | (b_u8 << 16) | (g_u8 << 8) | r_u8;
                    }
                    else
                    {
                        rgba = (0xff << 24) | (r_u8 << 16) | (g_u8 << 8) | b_u8;
                    }
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        case kFormat_A2B10G10R10:
        {
            const uint32_t* u32_vals = reinterpret_cast<const uint32_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    uint8_t a = static_cast<uint8_t>((u32_vals[y * width + x] & 0xC0000000) >> 30);
                    uint8_t b = static_cast<uint8_t>((u32_vals[y * width + x] & 0x3FF00000) >> 20);
                    uint8_t g = static_cast<uint8_t>((u32_vals[y * width + x] & 0x000FFC00) >> 10);
                    uint8_t r = static_cast<uint8_t>((u32_vals[y * width + x] & 0x000003FF) >> 0);

                    r = static_cast<uint8_t>(static_cast<float>(r) / 1023.0f * 255.0f);
                    g = static_cast<uint8_t>(static_cast<float>(g) / 1023.0f * 255.0f);
                    b = static_cast<uint8_t>(static_cast<float>(b) / 1023.0f * 255.0f);
                    a = static_cast<uint8_t>(static_cast<float>(a) / 3.0f * 255.0f);

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        case kFormat_R16G16B16A16_SFLOAT:
        {
            const uint64_t* u64_vals = reinterpret_cast<const uint64_t*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    uint16_t a_u16 = static_cast<uint16_t>((u64_vals[y * width + x] & 0xFFFF000000000000ULL) >> 48);
                    uint16_t b_u16 = static_cast<uint16_t>((u64_vals[y * width + x] & 0x0000FFFF00000000ULL) >> 32);
                    uint16_t g_u16 = static_cast<uint16_t>((u64_vals[y * width + x] & 0x00000000FFFF0000ULL) >> 16);
                    uint16_t r_u16 = static_cast<uint16_t>((u64_vals[y * width + x] & 0x000000000000FFFFULL) >> 0);

                    float r_f = ConvertFromHalf(r_u16);
                    float g_f = ConvertFromHalf(g_u16);
                    float b_f = ConvertFromHalf(b_u16);
                    float a_f = ConvertFromHalf(a_u16);

                    uint8_t r = static_cast<uint8_t>(r_f * 255.0f);
                    uint8_t g = static_cast<uint8_t>(g_f * 255.0f);
                    uint8_t b = static_cast<uint8_t>(b_f * 255.0f);
                    uint8_t a = static_cast<uint8_t>(a_f * 255.0f);

                    uint32_t rgba;
                    if (is_png)
                    {
                        rgba = (a << 24) | (b << 16) | (g << 8) | r;
                    }
                    else
                    {
                        rgba = (a << 24) | (r << 16) | (g << 8) | b;
                    }
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        case kFormat_D32_FLOAT:
        {
            const float* bytes_float = reinterpret_cast<const float*>(data);

            for (uint32_t y = 0; y < height; ++y)
            {
                for (uint32_t x = 0; x < width; ++x)
                {
                    const float   float_depth = bytes_float[y * width + x];
                    const uint8_t depth       = static_cast<uint8_t>(float_depth * 255.0f);

                    uint32_t rgba    = (0xff << 24) | (depth << 16) | (depth << 8) | depth;
                    *(temp_buffer++) = rgba;
                }
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
                    const uint32_t normalized_depth = bytes_u32[y * width + x] & 0x00FFFFFF;
                    const float    float_depth      = static_cast<float>(normalized_depth) / 8388607.0f;
                    const uint8_t  depth            = static_cast<uint8_t>(float_depth * 255.0f);

                    uint32_t rgba    = (0xff << 24) | (depth << 16) | (depth << 8) | depth;
                    *(temp_buffer++) = rgba;
                }
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
                    const uint16_t normalized_depth = bytes_u16[y * width + x];
                    const float    float_depth      = static_cast<float>(normalized_depth) / 32767.0f;
                    const uint8_t  depth            = static_cast<uint8_t>(float_depth * 255.0f);

                    uint32_t rgba    = (0xff << 24) | (depth << 16) | (depth << 8) | depth;
                    *(temp_buffer++) = rgba;
                }
            }
        }
        break;

        default:
            GFXRECON_LOG_ERROR("Format %u not handled", format);
            assert(0);
            return nullptr;
    }

    *row_pitch = width * sizeof(uint32_t);

    return reinterpret_cast<const uint8_t*>(temporary_buffer.get());
}

bool WriteBmpImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   uint64_t           data_size,
                   const void*        data,
                   uint32_t           pitch,
                   DataFormats        format)
{
    bool     success   = false;
    uint32_t row_pitch = width * kImageBpp;

    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    if (pitch != 0)
    {
        row_pitch = pitch;
    }

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
        file_header.size      = (height * width * kImageBpp) + file_header.off_bits;

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

        size_t ret = util::platform::FileWrite(&file_header, sizeof(file_header), 1, file);
        CheckFwriteRetVal(ret, 1, file);

        ret = util::platform::FileWrite(&info_header, sizeof(info_header), 1, file);
        CheckFwriteRetVal(ret, 1, file);

        // Y needs to be inverted when writing the bitmap data.
        auto height_1 = height - 1;

        if (format == kFormat_BGR || format == kFormat_BGRA)
        {
            for (uint32_t y = 0; y < height; ++y)
            {
                const uint8_t* bytes = reinterpret_cast<const uint8_t*>(data);
                ret = util::platform::FileWrite(&bytes[(height_1 - y) * row_pitch], 1, width * kImageBpp, file);
                CheckFwriteRetVal(ret, width * kImageBpp, file);
            }
        }
        else
        {
            const uint8_t* bytes = ConvertIntoTemporaryBuffer(width, height, data, &row_pitch, format, false);
            for (uint32_t y = 0; y < height; ++y)
            {
                ret = util::platform::FileWrite(&bytes[(height_1 - y) * width * kImageBpp], 1, width * kImageBpp, file);
                CheckFwriteRetVal(ret, width * kImageBpp, file);
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

bool WritePngImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   uint64_t           data_size,
                   const void*        data,
                   uint32_t           pitch,
                   DataFormats        format)
{
    GFXRECON_UNREFERENCED_PARAMETER(format);

    bool success = false;

#ifdef GFXRECON_ENABLE_PNG_SCREENSHOT
    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    const uint8_t* bytes = ConvertIntoTemporaryBuffer(width, height, data, &pitch, format, true);

    uint32_t row_pitch               = pitch == 0 ? width * kImageBpp : pitch;
    stbi_write_png_compression_level = 4;
    if (1 == stbi_write_png(filename.c_str(), width, height, kImageBpp, bytes, row_pitch))
    {
        success = true;
    }
    else
    {
        GFXRECON_LOG_ERROR("%s() Failed to open file (%s)", __func__, strerror(errno));
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
    else
    {
        GFXRECON_LOG_ERROR("%s() Failed to open file (%s)", __func__, strerror(errno));
    }
#endif

    return success;
}

bool WriteAstcImage(const std::string& filename,
                    uint32_t           width,
                    uint32_t           height,
                    uint32_t           depth,
                    uint8_t            block_size_x,
                    uint8_t            block_size_y,
                    uint8_t            block_size_z,
                    const void*        data,
                    size_t             size)
{
    if (data == nullptr || !size)
    {
        return true;
    }

    GFXRECON_LOG_INFO("%s(): Writing file \"%s\"", __func__, filename.c_str())

    AstcFileHeader header;

    header.magic[0] = 0x13;
    header.magic[1] = 0xab;
    header.magic[2] = 0xa1;
    header.magic[3] = 0x5c;

    header.dim_x[0] = static_cast<uint8_t>((width >> 0) & 0xff);
    header.dim_x[1] = static_cast<uint8_t>((width >> 8) & 0xff);
    header.dim_x[2] = static_cast<uint8_t>((width >> 16) & 0xff);

    header.dim_y[0] = static_cast<uint8_t>((height >> 0) & 0xff);
    header.dim_y[1] = static_cast<uint8_t>((height >> 8) & 0xff);
    header.dim_y[2] = static_cast<uint8_t>((height >> 16) & 0xff);

    header.dim_z[0] = static_cast<uint8_t>((depth >> 0) & 0xff);
    header.dim_z[1] = static_cast<uint8_t>((depth >> 8) & 0xff);
    header.dim_z[2] = static_cast<uint8_t>((depth >> 16) & 0xff);

    header.block_x = block_size_x;
    header.block_y = block_size_y;
    header.block_z = block_size_z;

    bool    success = false;
    FILE*   file    = nullptr;
    int32_t result  = util::platform::FileOpen(&file, filename.c_str(), "wb");
    if (!result && file != nullptr)
    {
        // Write the header
        int ret = util::platform::FileWrite(&header, sizeof(header), 1, file);
        CheckFwriteRetVal(ret, 1, file);

        // Write the binary payload
        ret = util::platform::FileWrite(data, size, 1, file);
        CheckFwriteRetVal(ret, 1, file);

        if (!ferror(file))
        {
            success = true;
        }

        if (util::platform::FileClose(file))
        {
            GFXRECON_LOG_ERROR("%s() fclose failed (%s)", __func__, strerror(result));
        }
    }
    else
    {
        success = false;
        GFXRECON_LOG_ERROR("%s() Failed to open file (%s)", __func__, strerror(result));
    }

    return success;
}

GFXRECON_END_NAMESPACE(imagewriter)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
