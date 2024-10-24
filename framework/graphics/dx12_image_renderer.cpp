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

#include "graphics/dx12_image_renderer.h"

#include <d3dcompiler.h>
#include <util/logging.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

//-----------------------------------------------------------------------------
/// Statically create a DX12ImageRenderer.
/// \param config A structure containing all of the necessary initialization
/// info. \returns A new DX12ImageRenderer instance.
//-----------------------------------------------------------------------------
std::unique_ptr<DX12ImageRenderer> DX12ImageRenderer::Create(const DX12ImageRendererConfig& config)
{
    std::unique_ptr<DX12ImageRenderer> out(new DX12ImageRenderer());

    if (out != nullptr)
    {
        if (out->Init(config) != S_OK)
        {
            GFXRECON_LOG_WARNING("DX12ImageRenderer initialization failed");
        }
    }
    return std::move(out);
}

void DX12ImageRenderer::ConvertR8G8B8A8ToB8G8R8A8(std::vector<char>& data, UINT width, UINT height, UINT pitch)
{
    uint32_t* pixel;
    uint32_t  r16, g16, b16, a16, b8g8r8a8;
    for (UINT j = 0; j < height; j++)
    {
        for (UINT i = 0; i < width; i++)
        {
            pixel = (uint32_t*)((uint8_t*)&data[0] + i * 4 + j * pitch);

            r16      = ((*pixel >> 0U) & 0xFFU);
            g16      = ((*pixel >> 8U) & 0xFFU);
            b16      = ((*pixel >> 16U) & 0xFFU);
            a16      = ((*pixel >> 24U) & 0xFFU);
            b8g8r8a8 = ((b16 << 0U) & 0xFFU) | ((g16 << 8U) & 0xFF00U) | ((r16 << 16U) & 0xFF0000U) |
                       ((a16 << 24U) & 0xFF000000);
            *pixel = b8g8r8a8;
        }
    }
}

void DX12ImageRenderer::ConvertR10G10B10A2ToB8G8R8A8(std::vector<char>& data, UINT width, UINT height, UINT pitch)
{
    GFXRECON_LOG_INFO_ONCE("Converting image data form R10G10B10A2 to B8G8R8A8. Image RGB data will be truncated to 8 "
                           "bits and alpha data will be set to 0xFF.");

    uint32_t* pixel;
    uint32_t  r16, g16, b16, a16, b8g8r8a8;
    for (UINT j = 0; j < height; j++)
    {
        for (UINT i = 0; i < width; i++)
        {
            pixel = (uint32_t*)((uint8_t*)&data[0] + i * 4 + j * pitch);

            r16 = ((*pixel >> 0U) & 0x3FFU) << 6U;
            g16 = ((*pixel >> 10U) & 0x3FFU) << 6U;
            b16 = ((*pixel >> 20U) & 0x3FFU) << 6U;

            // Ignore 2-bit alpha, generate opaque image data.
            a16 = 0xFFFFU;

            // This truncates 10bit RGB channels to 8 bits.
            b8g8r8a8 = ((b16 >> 8U) << 0U) | ((g16 >> 8U) << 8U) | ((r16 >> 8U) << 16U) | ((a16 >> 8U) << 24U);
            *pixel   = b8g8r8a8;
        }
    }
}

//-----------------------------------------------------------------------------
/// Constructor.
//-----------------------------------------------------------------------------
DX12ImageRenderer::DX12ImageRenderer() :
    cmd_allocator_(nullptr), cmd_list_(nullptr), fence_(nullptr), fence_event_(0), fence_value_(0), staging_(nullptr),
    staging_resource_size_(0)
{}

//-----------------------------------------------------------------------------
/// Destructor.
//-----------------------------------------------------------------------------
DX12ImageRenderer::~DX12ImageRenderer()
{
    if (fence_event_)
    {
        CloseHandle(fence_event_);
    }
}

//-----------------------------------------------------------------------------
/// Initialize all members needed by this rendering class.
/// \param config A structure containing all of the necessary initialization
/// info. \returns The result code for the initialization step.
//-----------------------------------------------------------------------------
HRESULT DX12ImageRenderer::Init(const DX12ImageRendererConfig& config)
{
    config_ = std::make_unique<DX12ImageRendererConfig>(config);
    // Create command allocator
    HRESULT result =
        config_->device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&cmd_allocator_));

    // Create command list
    if (result == S_OK)
    {
        result = config_->device->CreateCommandList(
            0, D3D12_COMMAND_LIST_TYPE_DIRECT, cmd_allocator_.Get(), nullptr, IID_PPV_ARGS(&cmd_list_));
    }

    // Create synchronization objects
    if (result == S_OK)
    {
        result       = config_->device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence_));
        fence_value_ = 1;

        // Create an event handle to use for frame synchronization
        fence_event_ = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    }

    if (result == S_OK)
    {
        // Command lists are created in the recording state, but there is nothing
        // to record yet. The main loop expects it to be closed, so close it now.
        result = cmd_list_->Close();
    }

    return result;
}

//-----------------------------------------------------------------------------
/// Convert a DX12 resource to a CPU-visible linear buffer of pixels.
/// The data is filled in a user - provided CpuImage struct.
/// IMPORTANT : Memory inside pImgOut is allocated on behalf of the caller, so
/// it is their responsibility to free it. \param pRes The Render Target
/// resource to capture image data for. \param prevState The previous state that
/// has been set on the resource. \param newWidth The width of the output image
/// data. \param newHeight The height of the output image data. \param format
/// The image format for the output image data. \param pImgOut A pointer to the
/// structure containing all capture image data. \param bFlipX Option used to
/// flip the image horizontally. \param bFlipY Option used to flip the image
/// vertically. \returns The result code of the capture operation.
//-----------------------------------------------------------------------------

HRESULT DX12ImageRenderer::CaptureImage(
    ID3D12Resource* res, D3D12_RESOURCE_STATES prev_state, UINT width, UINT height, UINT pitch, DXGI_FORMAT format)
{
    HRESULT result = E_FAIL;

    if ((res != nullptr) && (width > 0) && (height > 0))
    {
        auto desc = res->GetDesc();
        // Create temp assets used in this capture

        result = cmd_allocator_->Reset();

        if (result == S_OK)
        {
            result = cmd_list_->Reset(cmd_allocator_.Get(), nullptr);
        }

        // Render work
        if (result == S_OK)
        {

            D3D12_TEXTURE_COPY_LOCATION src_location = { res, D3D12_TEXTURE_COPY_TYPE_SUBRESOURCE_INDEX };
            src_location.SubresourceIndex            = 0;

            auto buffer_byte_size = pitch * height;
            if (staging_resource_size_ != buffer_byte_size)
            {
                if (staging_ != nullptr)
                {
                    staging_->Release();
                }
                result = CreateStagingResource(buffer_byte_size);
            }

            if (result == S_OK)
            {
                D3D12_TEXTURE_COPY_LOCATION dst_location = { staging_.Get(), D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT };
                dst_location.PlacedFootprint.Footprint.Width    = width;
                dst_location.PlacedFootprint.Footprint.Height   = height;
                dst_location.PlacedFootprint.Footprint.Depth    = 1;
                dst_location.PlacedFootprint.Footprint.Format   = format;
                dst_location.PlacedFootprint.Footprint.RowPitch = pitch;
                dst_location.PlacedFootprint.Offset             = 0;

                cmd_list_->CopyTextureRegion(&dst_location, 0, 0, 0, &src_location, nullptr);

                D3D12_RESOURCE_BARRIER barrier{};
                barrier.Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
                barrier.Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
                barrier.Transition.pResource   = res;
                barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_COPY_SOURCE;
                barrier.Transition.StateAfter  = prev_state;
                barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
                cmd_list_->ResourceBarrier(1, &barrier);

                // Execute the command list
                result                                = cmd_list_->Close();
                ID3D12CommandList* pp_command_lists[] = { cmd_list_.Get() };
                config_->cmd_queue->ExecuteCommandLists(_countof(pp_command_lists), pp_command_lists);
                WaitCmdListFinish();
            }
        }
    }

    return result;
}

HRESULT DX12ImageRenderer::CreateStagingResource(unsigned int buffer_byte_size)
{
    D3D12_HEAP_PROPERTIES props{};
    props.Type                 = D3D12_HEAP_TYPE_READBACK;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 1;
    props.VisibleNodeMask      = 1;

    D3D12_RESOURCE_DESC descriptor{};
    descriptor.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    descriptor.Alignment          = 0;
    descriptor.Width              = buffer_byte_size;
    descriptor.Height             = 1;
    descriptor.DepthOrArraySize   = 1;
    descriptor.MipLevels          = 1;
    descriptor.Format             = DXGI_FORMAT_UNKNOWN;
    descriptor.SampleDesc.Count   = 1;
    descriptor.SampleDesc.Quality = 0;
    descriptor.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    descriptor.Flags              = D3D12_RESOURCE_FLAG_NONE;

    auto result = config_->device->CreateCommittedResource(
        &props, D3D12_HEAP_FLAG_NONE, &descriptor, D3D12_RESOURCE_STATE_COPY_DEST, nullptr, IID_PPV_ARGS(&staging_));
    if (result == S_OK)
    {
        staging_resource_size_ = buffer_byte_size;
    }
    return result;
}

void DX12ImageRenderer::WaitCmdListFinish()
{
    // Signal and increment the fence value
    const UINT64 fence_v = fence_value_;
    HRESULT      result  = config_->cmd_queue->Signal(fence_.Get(), fence_v);
    fence_value_++;

    const UINT64 fenceCompletedVal = fence_->GetCompletedValue();

    // Wait until the previous frame is finished
    if (fenceCompletedVal < fence_v)
    {
        result = fence_->SetEventOnCompletion(fence_v, fence_event_);
        WaitForSingleObject(fence_event_, INFINITE);
    }
}

HRESULT
DX12ImageRenderer::RetrieveImageData(
    CpuImage* img_out, UINT width, UINT height, UINT pitch, DXGI_FORMAT format, bool convert_to_bgra)
{
    void*       uav_data   = nullptr;
    D3D12_RANGE read_range = { 0, 0 };

    auto result = staging_->Map(0, &read_range, &uav_data);

    if (result == S_OK)
    {
        const UINT total_bytes = pitch * height;

        img_out->pitch  = pitch;
        img_out->width  = width;
        img_out->height = height;
        img_out->data.resize(total_bytes);
        memcpy(&img_out->data[0], uav_data, total_bytes);

        bool is_bgr8        = B8G8R8.find(format) != B8G8R8.end();
        bool is_rgb8        = R8G8B8A8.find(format) != R8G8B8A8.end();
        bool is_r10g10b10a2 = R10G10B10A2.find(format) != R10G10B10A2.end();

        bool swap_red_blue = (convert_to_bgra && is_rgb8) || (!convert_to_bgra && is_bgr8);

        if (swap_red_blue)
        {
            ConvertR8G8B8A8ToB8G8R8A8(img_out->data, width, height, pitch);
        }
        else if (is_r10g10b10a2)
        {
            ConvertR10G10B10A2ToB8G8R8A8(img_out->data, width, height, pitch);
            if (!convert_to_bgra)
            {
                ConvertR8G8B8A8ToB8G8R8A8(img_out->data, width, height, pitch);
            }
        }
        else if (!(is_bgr8 || is_rgb8 || is_r10g10b10a2))
        {
            auto entry = std::find(issued_warning_list_.begin(), issued_warning_list_.end(), format);
            if (entry == issued_warning_list_.end())
            {
                issued_warning_list_.insert(entry, format);
                GFXRECON_LOG_ERROR("DX12ImageRenderer does not support %d DXGI_FORMAT", format);
            }
        }
        staging_->Unmap(0, nullptr);
    }
    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
