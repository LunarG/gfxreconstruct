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

#include "graphics/dx11_image_renderer.h"

#include <util/logging.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

std::unique_ptr<DX11ImageRenderer> DX11ImageRenderer::Create(const DX11ImageRendererConfig& config)
{
    std::unique_ptr<DX11ImageRenderer> out(new DX11ImageRenderer());

    if (out != nullptr)
    {
        if (out->Init(config) != S_OK)
        {
            GFXRECON_LOG_WARNING("DX11ImageRenderer initialization failed");
        }
    }
    return std::move(out);
}

//-----------------------------------------------------------------------------
/// Constructor.
//-----------------------------------------------------------------------------
DX11ImageRenderer::DX11ImageRenderer() :
    staging_resource_format_(DXGI_FORMAT_UNKNOWN), staging_resource_width_(0), staging_resource_height_(0),
    resolve_resource_format_(DXGI_FORMAT_UNKNOWN), resolve_resource_width_(0), resolve_resource_height_(0)

{}

//-----------------------------------------------------------------------------
/// Destructor.
//-----------------------------------------------------------------------------
DX11ImageRenderer::~DX11ImageRenderer() {}

HRESULT DX11ImageRenderer::Init(const DX11ImageRendererConfig& config)
{
    GFXRECON_ASSERT(config.device && config.context);

    if (config.device && config.context)
    {
        config_ = config;
    }

    return S_OK;
}

HRESULT DX11ImageRenderer::CaptureImage(
    ID3D11Texture2D* res, uint32_t sample_count, uint32_t width, uint32_t height, DXGI_FORMAT format)
{
    HRESULT result = E_FAIL;

    if ((res != nullptr) && (width > 0) && (height > 0))
    {
        ID3D11Resource* src = res;
        result              = S_OK;

        if (sample_count > 1)
        {
            if ((resolve_resource_format_ != format) || (resolve_resource_width_ != width) ||
                (resolve_resource_height_ != height))
            {
                result = CreateResolveResource(width, height, format);
            }

            if (SUCCEEDED(result))
            {
                GFXRECON_ASSERT(resolve_);
                config_.context->ResolveSubresource(resolve_, 0, src, 0, format);
                src = resolve_;
            }
        }

        if ((staging_resource_format_ != format) || (staging_resource_width_ != width) ||
            (staging_resource_height_ != height))
        {
            result = CreateStagingResource(width, height, format);
        }

        if (SUCCEEDED(result))
        {
            GFXRECON_ASSERT(staging_ != nullptr);
            config_.context->CopySubresourceRegion(staging_, 0, 0, 0, 0, src, 0, nullptr);
        }
    }

    return result;
}

HRESULT DX11ImageRenderer::CreateStagingResource(uint32_t width, uint32_t height, DXGI_FORMAT format)
{
    D3D11_TEXTURE2D_DESC desc{};
    desc.Width              = width;
    desc.Height             = height;
    desc.MipLevels          = 1;
    desc.ArraySize          = 1;
    desc.Format             = format;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage              = D3D11_USAGE_STAGING;
    desc.BindFlags          = 0;
    desc.CPUAccessFlags     = D3D11_CPU_ACCESS_READ;
    desc.MiscFlags          = 0;

    auto result = config_.device->CreateTexture2D(&desc, nullptr, &staging_);
    if (result == S_OK)
    {
        staging_resource_width_  = width;
        staging_resource_height_ = height;
        staging_resource_format_ = format;
    }
    return result;
}

HRESULT DX11ImageRenderer::CreateResolveResource(uint32_t width, uint32_t height, DXGI_FORMAT format)
{
    D3D11_TEXTURE2D_DESC desc{};
    desc.Width              = width;
    desc.Height             = height;
    desc.MipLevels          = 1;
    desc.ArraySize          = 1;
    desc.Format             = format;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage              = D3D11_USAGE_DEFAULT;
    desc.BindFlags          = 0;
    desc.CPUAccessFlags     = 0;
    desc.MiscFlags          = 0;

    auto result = config_.device->CreateTexture2D(&desc, nullptr, &resolve_);
    if (result == S_OK)
    {
        resolve_resource_width_  = width;
        resolve_resource_height_ = height;
        resolve_resource_format_ = format;
    }
    return result;
}

HRESULT DX11ImageRenderer::RetrieveImageData(
    CpuImage& img_out, uint32_t width, uint32_t height, DXGI_FORMAT format, bool convert_to_bgra)
{
    D3D11_MAPPED_SUBRESOURCE mapped_subresource{};
    auto                     result = config_.context->Map(staging_, 0, D3D11_MAP_READ, 0, &mapped_subresource);

    if (SUCCEEDED(result) && mapped_subresource.pData != nullptr)
    {
        const auto total_bytes = mapped_subresource.RowPitch * height;

        img_out.pitch  = mapped_subresource.RowPitch;
        img_out.width  = width;
        img_out.height = height;
        img_out.data.resize(total_bytes);

        auto success = CopyImageData(std::data(img_out.data),
                                     reinterpret_cast<const uint8_t*>(mapped_subresource.pData),
                                     total_bytes,
                                     width,
                                     height,
                                     mapped_subresource.RowPitch,
                                     format,
                                     convert_to_bgra);

        if (!success)
        {
            // Only report errors once per format.
            auto entry = std::find(issued_warning_list_.begin(), issued_warning_list_.end(), format);
            if (entry == issued_warning_list_.end())
            {
                issued_warning_list_.insert(entry, format);
                GFXRECON_LOG_ERROR("DX11ImageRenderer does not support %d DXGI_FORMAT", format);
            }
        }

        config_.context->Unmap(staging_, 0);
    }

    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
