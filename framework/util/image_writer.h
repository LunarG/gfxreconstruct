/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_UTIL_IMAGE_WRITER_H
#define GFXRECON_UTIL_IMAGE_WRITER_H

#include "logging.h"
#include "util/defines.h"

#include <assert.h>
#include <cstdint>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(imagewriter)

#pragma pack(push)
#pragma pack(2)

struct BmpFileHeader
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t off_bits;
};

struct BmpInfoHeader
{
    uint32_t size;
    int32_t  width;
    int32_t  height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t  x_pels_per_meter;
    int32_t  y_pels_per_meter;
    uint32_t clr_used;
    uint32_t clr_important;
};

#pragma pack(pop)

enum DataFormats
{
    kFormat_UNSPECIFIED = 0,
    kFormat_RGB,
    kFormat_RGBA,
    kFormat_BGR,
    kFormat_BGRA,
    kFormat_D32_FLOAT,
    kFormat_D24_UNORM,
    kFormat_D16_UNORM,
    kFormat_S8_UINT
};

constexpr bool DataFormatHasAlpha(DataFormats format)
{
    switch (format)
    {
        case kFormat_RGBA:
        case kFormat_BGRA:
            return true;

        case kFormat_RGB:
        case kFormat_BGR:
        case kFormat_D32_FLOAT:
        case kFormat_D24_UNORM:
        case kFormat_D16_UNORM:
        case kFormat_S8_UINT:
            return false;

        default:
            assert(0);
            return false;
    }
}

constexpr size_t DataFormatsSizes(DataFormats format)
{
    switch (format)
    {
        case kFormat_D16_UNORM:
            return 2;

        case kFormat_D24_UNORM:
        case kFormat_RGB:
        case kFormat_BGR:
            return 3;

        case kFormat_RGBA:
        case kFormat_BGRA:
        case kFormat_D32_FLOAT:
            return 4;

        case kFormat_UNSPECIFIED:
        default:
            GFXRECON_LOG_WARNING("%s(): Unrecognized format %u", __func__, static_cast<uint32_t>(format));
            assert(0);
            return 0;
    }
}

bool WriteBmpImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   const void*        data,
                   uint32_t           pitch       = 0,
                   DataFormats        data_format = kFormat_BGRA,
                   bool               write_alpha = false);

bool WriteBmpImageSeparateAlpha(const std::string& filename,
                                uint32_t           width,
                                uint32_t           height,
                                const void*        data,
                                uint32_t           pitch,
                                DataFormats        data_format);

bool WritePngImage(const std::string& filename,
                   uint32_t           width,
                   uint32_t           height,
                   const void*        data,
                   uint32_t           pitch       = 0,
                   DataFormats        format      = kFormat_BGRA,
                   bool               write_alpha = false);

bool WritePngImageSeparateAlpha(
    const std::string& filename, uint32_t width, uint32_t height, const void* data, uint32_t pitch, DataFormats format);

/**
 * @brief Specifies the rotation angle applied to an image.
 */
enum class ImageRotation
{
    DEG_0,   ///< No rotation
    DEG_90,  ///< 90 degrees clockwise rotation
    DEG_180, ///< 180 degrees clockwise rotation
    DEG_270  ///< 270 degrees clockwise rotation
};

/**
 * @brief Rotates and optionally mirrors image pixels on the CPU using loop tiling for cache friendliness.
 *
 * If both mirroring and rotation are enabled, the image content is mirrored horizontally first, then rotated.
 *
 * @param rotation     Runtime rotation enum (0, 90, 180, or 270 degrees).
 * @param is_mirrored  Runtime boolean flag indicating whether the image should be mirrored.
 * @param src_pixels   Pointer to the source pixel data buffer (uint32_t representation).
 * @param dst_pixels   Pointer to the destination pixel data buffer (uint32_t representation).
 * @param src_width    Width of the source image in pixels.
 * @param src_height   Height of the source image in pixels.
 * @param dst_width    Width of the destination image in pixels.
 * @param dst_height   Height of the destination image in pixels.
 */
void RotateAndMirrorPixels(ImageRotation   rotation,
                           bool            is_mirrored,
                           const uint32_t* src_pixels,
                           uint32_t*       dst_pixels,
                           uint32_t        src_width,
                           uint32_t        src_height,
                           uint32_t        dst_width,
                           uint32_t        dst_height);

GFXRECON_END_NAMESPACE(imagewriter)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_IMAGE_WRITER_H
