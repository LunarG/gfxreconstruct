/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#include "graphics/dx_image_renderer.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

void DXImageRenderer::ConvertR8G8B8A8ToB8G8R8A8(
    uint8_t* dst, const uint8_t* src, uint32_t width, uint32_t height, uint32_t pitch)
{
    const uint32_t* src_pixel;
    uint32_t*       dst_pixel;
    uint32_t        r8, g8, b8, a8, b8g8r8a8;
    for (UINT j = 0; j < height; j++)
    {
        for (UINT i = 0; i < width; i++)
        {
            auto offset = i * 4 + j * pitch;
            src_pixel   = reinterpret_cast<const uint32_t*>(src + offset);
            dst_pixel   = reinterpret_cast<uint32_t*>(dst + offset);

            r8 = ((*src_pixel >> 0U) & 0xFFU);
            g8 = ((*src_pixel >> 8U) & 0xFFU);
            b8 = ((*src_pixel >> 16U) & 0xFFU);
            a8 = ((*src_pixel >> 24U) & 0xFFU);
            b8g8r8a8 =
                ((b8 << 0U) & 0xFFU) | ((g8 << 8U) & 0xFF00U) | ((r8 << 16U) & 0xFF0000U) | ((a8 << 24U) & 0xFF000000);
            *dst_pixel = b8g8r8a8;
        }
    }
}

void DXImageRenderer::ConvertR10G10B10A2ToB8G8R8A8(
    uint8_t* dst, const uint8_t* src, uint32_t width, uint32_t height, uint32_t pitch)
{
    GFXRECON_LOG_INFO_ONCE("Converting image data form R10G10B10A2 to B8G8R8A8. Image RGB data will be truncated to 8 "
                           "bits and alpha data will be set to 0xFF.");

    const uint32_t* src_pixel;
    uint32_t*       dst_pixel;
    uint32_t        r16, g16, b16, a16, b8g8r8a8;
    for (UINT j = 0; j < height; j++)
    {
        for (UINT i = 0; i < width; i++)
        {
            auto offset = i * 4 + j * pitch;
            src_pixel   = reinterpret_cast<const uint32_t*>(src + offset);
            dst_pixel   = reinterpret_cast<uint32_t*>(dst + offset);

            r16 = ((*src_pixel >> 0U) & 0x3FFU) << 6U;
            g16 = ((*src_pixel >> 10U) & 0x3FFU) << 6U;
            b16 = ((*src_pixel >> 20U) & 0x3FFU) << 6U;

            // Ignore 2-bit alpha, generate opaque image data.
            a16 = 0xFFFFU;

            // This truncates 10bit RGB channels to 8 bits.
            b8g8r8a8   = ((b16 >> 8U) << 0U) | ((g16 >> 8U) << 8U) | ((r16 >> 8U) << 16U) | ((a16 >> 8U) << 24U);
            *dst_pixel = b8g8r8a8;
        }
    }
}

//-----------------------------------------------------------------------------
/// Constructor.
//-----------------------------------------------------------------------------
DXImageRenderer::DXImageRenderer() {}

//-----------------------------------------------------------------------------
/// Destructor.
//-----------------------------------------------------------------------------
DXImageRenderer::~DXImageRenderer() {}

bool DXImageRenderer::CopyImageData(uint8_t*       dst,
                                    const uint8_t* src,
                                    size_t         total_bytes,
                                    uint32_t       width,
                                    uint32_t       height,
                                    uint32_t       pitch,
                                    DXGI_FORMAT    format,
                                    bool           convert_to_bgra)
{
    bool is_bgr8        = B8G8R8.find(format) != B8G8R8.end();
    bool is_rgb8        = R8G8B8A8.find(format) != R8G8B8A8.end();
    bool is_r10g10b10a2 = R10G10B10A2.find(format) != R10G10B10A2.end();

    if (!(is_bgr8 || is_rgb8 || is_r10g10b10a2))
    {
        return false;
    }

    bool swap_red_blue = (convert_to_bgra && is_rgb8) || (!convert_to_bgra && is_bgr8);

    if (swap_red_blue)
    {
        ConvertR8G8B8A8ToB8G8R8A8(dst, src, width, height, pitch);
    }
    else if (is_r10g10b10a2)
    {
        ConvertR10G10B10A2ToB8G8R8A8(dst, src, width, height, pitch);
        if (!convert_to_bgra)
        {
            ConvertR8G8B8A8ToB8G8R8A8(dst, src, width, height, pitch);
        }
    }
    else
    {
        memcpy(dst, src, total_bytes);
    }

    return true;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
