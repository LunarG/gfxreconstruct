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

#ifndef GFXRECON_DECODE_DX11_IMAGE_RENDERER_H
#define GFXRECON_DECODE_DX11_IMAGE_RENDERER_H

#include "graphics/dx_image_renderer.h"
#include "graphics/dx12_util.h"
#include "util/defines.h"

#ifdef WIN32
#include <d3d11.h>
#endif

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

//-----------------------------------------------------------------------------
/// A structure containing ImageRenderer initialization info.
//-----------------------------------------------------------------------------
struct DX11ImageRendererConfig
{
    dx12::ID3D11DeviceComPtr        device;  ///< The device that the Image Renderer will use.
    dx12::ID3D11DeviceContextComPtr context; ///< The DeviceContext that the Image Renderer will use.
};

//-----------------------------------------------------------------------------
/// An Image Renderer used to capture the DX11 Render Target of the
/// instrumented application.
//-----------------------------------------------------------------------------
class DX11ImageRenderer : public DXImageRenderer
{
  public:
    //-----------------------------------------------------------------------------
    /// Statically create a DX11ImageRenderer.
    /// \param config A structure containing all of the necessary initialization
    ///               info.
    /// \returns A new DX11ImageRenderer instance.
    //-----------------------------------------------------------------------------
    static std::unique_ptr<DX11ImageRenderer> Create(const DX11ImageRendererConfig& config);

    //-----------------------------------------------------------------------------
    /// Destructor.
    //-----------------------------------------------------------------------------
    virtual ~DX11ImageRenderer() override;

    HRESULT
    RetrieveImageData(CpuImage& img_out, uint32_t width, uint32_t height, DXGI_FORMAT format, bool convert_to_bgra);

    //-----------------------------------------------------------------------------
    /// Convert a DX11 resource to a CPU-visible linear buffer of pixels.
    /// The data is filled in a user-provided CpuImage struct retrieved with
    /// #RetrieveImageData.
    /// \param res The Render Target resource to capture image data for.
    /// \param width The width of the image data.
    /// \param height The height of the image data.
    /// \returns The result code of the capture operation.
    //-----------------------------------------------------------------------------
    HRESULT
    CaptureImage(ID3D11Texture2D* res, uint32_t sample_count, uint32_t width, uint32_t height, DXGI_FORMAT format);

  private:
    //-----------------------------------------------------------------------------
    /// Constructor.
    //-----------------------------------------------------------------------------
    DX11ImageRenderer();

    //-----------------------------------------------------------------------------
    /// Initialize all members needed by this rendering class.
    /// \param config A structure containing all of the necessary initialization
    /// info. \returns The result code for the initialization step.
    //-----------------------------------------------------------------------------
    HRESULT Init(const DX11ImageRendererConfig& config);

    HRESULT CreateStagingResource(uint32_t width, uint32_t height, DXGI_FORMAT format);

    HRESULT CreateResolveResource(uint32_t width, uint32_t height, DXGI_FORMAT format);

  private:
    DX11ImageRendererConfig     config_; ///< The structure containing all configuration info for this Image Renderer.
    dx12::ID3D11Texture2DComPtr staging_;
    DXGI_FORMAT                 staging_resource_format_;
    uint32_t                    staging_resource_width_;
    uint32_t                    staging_resource_height_;
    dx12::ID3D11Texture2DComPtr resolve_;
    DXGI_FORMAT                 resolve_resource_format_;
    uint32_t                    resolve_resource_width_;
    uint32_t                    resolve_resource_height_;
    std::list<DXGI_FORMAT>      issued_warning_list_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX11_IMAGE_RENDERER_H
