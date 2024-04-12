/*
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

#ifndef GFXRECON_DECODE_DX12_IMAGE_RENDERER_H
#define GFXRECON_DECODE_DX12_IMAGE_RENDERER_H

#include "util/defines.h"

#ifdef WIN32
#include <d3d12.h>
#include <wrl/client.h>
#endif

#include <memory>
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
static const UINT BytesPerPixel = 4;

//-----------------------------------------------------------------------------
/// A structure of data that data we'll upload to a constant buffer.
//-----------------------------------------------------------------------------
struct ConstantBuffer
{
    UINT rt_width; ///< The width of the render target.
    UINT flip_x;   ///< Responsible for flipping the image horizontally.
    UINT flip_y;   ///< Responsible for flipping the image vertically.
};

//-----------------------------------------------------------------------------
/// A structure containing ImageRenderer initialization info.
//-----------------------------------------------------------------------------
struct DX12ImageRendererConfig
{
    Microsoft::WRL::ComPtr<ID3D12Device>       device;    ///< The device that the Image Renderer will use.
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> cmd_queue; ///< The CommandQueue that the Image Renderer will use.
};

struct CpuImage
{
    std::vector<char> data;   ///< pointer to the image data
    unsigned int      pitch;  ///< pitch of the image
    unsigned int      width;  ///< width of the image
    unsigned int      height; ///< height of the image
};

//-----------------------------------------------------------------------------
/// An Image Renderer used to capture the Render Target of the instrumented
/// application.
//-----------------------------------------------------------------------------
class DX12ImageRenderer
{
  public:
    //-----------------------------------------------------------------------------
    /// Statically create a DX12ImageRenderer.
    /// \param config A structure containing all of the necessary initialization
    /// info. \returns A new DX12ImageRenderer instance.
    //-----------------------------------------------------------------------------
    static std::unique_ptr<DX12ImageRenderer> Create(const DX12ImageRendererConfig& config);

    static void ConvertR8G8B8A8ToB8G8R8A8(std::vector<char>& data, UINT width, UINT height, UINT pitch);

    static void ConvertR10G10B10A2ToB8G8R8A8(std::vector<char>& data, UINT width, UINT height, UINT pitch);

    HRESULT
    RetrieveImageData(CpuImage* img_out, UINT width, UINT height, UINT pitch, DXGI_FORMAT format, bool convert_to_bgra);

    //-----------------------------------------------------------------------------
    /// Destructor.
    //-----------------------------------------------------------------------------
    ~DX12ImageRenderer();

    //-----------------------------------------------------------------------------
    /// Convert a DX12 resource to a CPU-visible linear buffer of pixels.
    /// The data is filled in a user - provided CpuImage struct.
    /// IMPORTANT : Memory inside pImgOut is allocated on behalf of the caller, so
    /// it is their responsibility to free it. \param pRes The Render Target
    /// resource to capture image data for. \param prevState The previous state
    /// that has been set on the resource. \param newWidth The width of the output
    /// image data. \param newHeight The height of the output image data. \param
    /// format The image format for the output image data. \param pImgOut A
    /// pointer to the structure containing all capture image data. \param bFlipX
    /// Option used to flip the image horizontally. \param bFlipY Option used to
    /// flip the image vertically. \returns The result code of the capture
    /// operation.
    //-----------------------------------------------------------------------------
    HRESULT
    CaptureImage(
        ID3D12Resource* res, D3D12_RESOURCE_STATES prev_state, UINT width, UINT height, UINT pitch, DXGI_FORMAT format);

  private:
    //-----------------------------------------------------------------------------
    /// Constructor.
    //-----------------------------------------------------------------------------
    DX12ImageRenderer();

    //-----------------------------------------------------------------------------
    /// Initialize all members needed by this rendering class.
    /// \param config A structure containing all of the necessary initialization
    /// info. \returns The result code for the initialization step.
    //-----------------------------------------------------------------------------
    HRESULT Init(const DX12ImageRendererConfig& config);

    HRESULT CreateStagingResource(unsigned int buffer_byte_size);

    void WaitCmdListFinish();

    /// The structure containing all configuration info for this Image Renderer.
    std::unique_ptr<DX12ImageRendererConfig> config_;

    /// The command allocator used to make a copy the Render Target.
    Microsoft::WRL::ComPtr<ID3D12CommandAllocator> cmd_allocator_;

    /// The command list that will do the work of copying the Render Target data.
    Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> cmd_list_;

    /// Fence used to indicate completed Render Target capture.
    Microsoft::WRL::ComPtr<ID3D12Fence> fence_;

    /// Handle to the event that indicates completed Render Target capture.
    HANDLE fence_event_;

    /// The value to watch for in the next fence wait.
    UINT64 fence_value_;

    Microsoft::WRL::ComPtr<ID3D12Resource> staging_;

    unsigned int staging_resource_size_;

    std::list<DXGI_FORMAT> issued_warning_list_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
