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

#ifndef GFXRECON_DECODE_DX12_IMAGE_RENDERER_H
#define GFXRECON_DECODE_DX12_IMAGE_RENDERER_H

#include "graphics/dx_image_renderer.h"
#include "graphics/dx12_util.h"
#include "util/defines.h"

#ifdef WIN32
#include <d3d12.h>
#endif

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

//-----------------------------------------------------------------------------
/// A structure containing ImageRenderer initialization info.
//-----------------------------------------------------------------------------
struct DX12ImageRendererConfig
{
    dx12::ID3D12DeviceComPtr       device;    ///< The device that the Image Renderer will use.
    dx12::ID3D12CommandQueueComPtr cmd_queue; ///< The CommandQueue that the Image Renderer will use.
};

//-----------------------------------------------------------------------------
/// An Image Renderer used to capture the DX12 Render Target of the
/// instrumented application.
//-----------------------------------------------------------------------------
class DX12ImageRenderer : public DXImageRenderer
{
  public:
    //-----------------------------------------------------------------------------
    /// Statically create a DX12ImageRenderer.
    /// \param config A structure containing all of the necessary initialization
    ///               info.
    /// \returns A new DX12ImageRenderer instance.
    //-----------------------------------------------------------------------------
    static std::unique_ptr<DX12ImageRenderer> Create(const DX12ImageRendererConfig& config);

    //-----------------------------------------------------------------------------
    /// Destructor.
    //-----------------------------------------------------------------------------
    virtual ~DX12ImageRenderer() override;

    HRESULT RetrieveImageData(
        CpuImage& img_out, uint32_t width, uint32_t height, uint32_t pitch, DXGI_FORMAT format, bool convert_to_bgra);

    //-----------------------------------------------------------------------------
    /// Convert a DX12 resource to a CPU-visible linear buffer of pixels.
    /// The data is filled in a user-provided CpuImage struct retrieved with
    /// #RetrieveImageData.
    /// \param res The Render Target resource to capture image data for.
    /// \param width The width of the image data.
    /// \param height The height of the image data.
    /// \param pitch The row pitch of the image data.
    /// \param format The image format for the output image data.
    /// \returns The result code of the capture operation.
    //-----------------------------------------------------------------------------
    HRESULT
    CaptureImage(ID3D12Resource*       res,
                 D3D12_RESOURCE_STATES prev_state,
                 uint32_t              width,
                 uint32_t              height,
                 uint32_t              pitch,
                 DXGI_FORMAT           format);

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

    HRESULT CreateStagingResource(uint32_t buffer_byte_size);

    void WaitCmdListFinish();

  private:
    DX12ImageRendererConfig config_; ///< The structure containing all configuration info for this Image Renderer.
    dx12::ID3D12CommandAllocatorComPtr cmd_allocator_; ///< The command allocator used to make a copy the Render Target.
    dx12::ID3D12GraphicsCommandListComPtr
                               cmd_list_; ///< The command list that will do the work of copying the Render Target data.
    dx12::ID3D12FenceComPtr    fence_;    ///< Fence used to indicate completed Render Target capture.
    HANDLE                     fence_event_; ///< Handle to the event that indicates completed Render Target capture.
    uint64_t                   fence_value_; ///< The value to watch for in the next fence wait.
    dx12::ID3D12ResourceComPtr staging_;
    uint32_t                   staging_resource_size_;
    std::list<DXGI_FORMAT>     issued_warning_list_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_IMAGE_RENDERER_H
