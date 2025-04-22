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

#ifndef GFXRECON_DECODE_DX_IMAGE_RENDERER_H
#define GFXRECON_DECODE_DX_IMAGE_RENDERER_H

#include "util/defines.h"

#ifdef WIN32
#include <dxgi.h>
#endif

#include <vector>
#include <set>
#include <list>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static const std::set<DXGI_FORMAT> B8G8R8 = { DXGI_FORMAT_B8G8R8A8_UNORM,    DXGI_FORMAT_B8G8R8X8_UNORM,
                                              DXGI_FORMAT_B8G8R8A8_TYPELESS, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
                                              DXGI_FORMAT_B8G8R8X8_TYPELESS, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB };

static const std::set<DXGI_FORMAT> R8G8B8A8 = { DXGI_FORMAT_R8G8B8A8_TYPELESS, DXGI_FORMAT_R8G8B8A8_TYPELESS,
                                                DXGI_FORMAT_R8G8B8A8_UNORM,    DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
                                                DXGI_FORMAT_R8G8B8A8_UINT,     DXGI_FORMAT_R8G8B8A8_SNORM,
                                                DXGI_FORMAT_R8G8B8A8_SINT };

static const std::set<DXGI_FORMAT> R10G10B10A2 = { DXGI_FORMAT_R10G10B10A2_TYPELESS,
                                                   DXGI_FORMAT_R10G10B10A2_UNORM,
                                                   DXGI_FORMAT_R10G10B10A2_UINT };

/// Bytes per pixel definition
constexpr uint32_t BytesPerPixel = 4;

//-----------------------------------------------------------------------------
/// A structure of data that data we'll upload to a constant buffer.
//-----------------------------------------------------------------------------
struct ConstantBuffer
{
    uint32_t rt_width; ///< The width of the render target.
    uint32_t flip_x;   ///< Responsible for flipping the image horizontally.
    uint32_t flip_y;   ///< Responsible for flipping the image vertically.
};

struct CpuImage
{
    std::vector<uint8_t> data;   ///< pointer to the image data
    uint32_t             pitch;  ///< pitch of the image
    uint32_t             width;  ///< width of the image
    uint32_t             height; ///< height of the image
};

//-----------------------------------------------------------------------------
/// An Image Renderer base class providing common functionality to capture
/// DX11 and DX12 Render Targets.
//-----------------------------------------------------------------------------
class DXImageRenderer
{
  public:
    //-----------------------------------------------------------------------------
    /// Destructor.
    //-----------------------------------------------------------------------------
    virtual ~DXImageRenderer();

  protected:
    static void
    ConvertR8G8B8A8ToB8G8R8A8(uint8_t* dst, const uint8_t* src, uint32_t width, uint32_t height, uint32_t pitch);

    static void
    ConvertR10G10B10A2ToB8G8R8A8(uint8_t* dst, const uint8_t* src, uint32_t width, uint32_t height, uint32_t pitch);

    //-----------------------------------------------------------------------------
    /// Constructor.
    //-----------------------------------------------------------------------------
    DXImageRenderer();

    bool CopyImageData(uint8_t*       dst,
                       const uint8_t* src,
                       size_t         total_bytes,
                       uint32_t       width,
                       uint32_t       height,
                       uint32_t       pitch,
                       DXGI_FORMAT    format,
                       bool           convert_to_bgra);

  private:
    std::list<DXGI_FORMAT> issued_warning_list_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX_IMAGE_RENDERER_H
