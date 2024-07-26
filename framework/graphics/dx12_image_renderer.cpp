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

#include "graphics/dx12_image_renderer.h"

#include <util/logging.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

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

HRESULT DX12ImageRenderer::Init(const DX12ImageRendererConfig& config)
{
    config_ = config;
    // Create command allocator
    HRESULT result =
        config_.device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&cmd_allocator_));

    // Create command list
    if (result == S_OK)
    {
        result = config_.device->CreateCommandList(
            0, D3D12_COMMAND_LIST_TYPE_DIRECT, cmd_allocator_, nullptr, IID_PPV_ARGS(&cmd_list_));
    }

    // Create synchronization objects
    if (result == S_OK)
    {
        result       = config_.device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence_));
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

HRESULT DX12ImageRenderer::CaptureImage(ID3D12Resource*       res,
                                        D3D12_RESOURCE_STATES prev_state,
                                        uint32_t              width,
                                        uint32_t              height,
                                        uint32_t              pitch,
                                        DXGI_FORMAT           format)
{
    HRESULT result = E_FAIL;

    if ((res != nullptr) && (width > 0) && (height > 0))
    {
        result = cmd_allocator_->Reset();

        if (result == S_OK)
        {
            result = cmd_list_->Reset(cmd_allocator_, nullptr);
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
                D3D12_TEXTURE_COPY_LOCATION dst_location      = { staging_, D3D12_TEXTURE_COPY_TYPE_PLACED_FOOTPRINT };
                dst_location.PlacedFootprint.Footprint.Width  = width;
                dst_location.PlacedFootprint.Footprint.Height = height;
                dst_location.PlacedFootprint.Footprint.Depth  = 1;
                dst_location.PlacedFootprint.Footprint.Format = format;
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
                ID3D12CommandList* pp_command_lists[] = { cmd_list_ };
                config_.cmd_queue->ExecuteCommandLists(_countof(pp_command_lists), pp_command_lists);
                WaitCmdListFinish();
            }
        }
    }

    return result;
}

HRESULT DX12ImageRenderer::CreateStagingResource(uint32_t buffer_byte_size)
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

    auto result = config_.device->CreateCommittedResource(
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
    const uint64_t fence_v = fence_value_;
    HRESULT        result  = config_.cmd_queue->Signal(fence_, fence_v);
    fence_value_++;

    const uint64_t fenceCompletedVal = fence_->GetCompletedValue();

    // Wait until the previous frame is finished
    if (fenceCompletedVal < fence_v)
    {
        result = fence_->SetEventOnCompletion(fence_v, fence_event_);
        WaitForSingleObject(fence_event_, INFINITE);
    }
}

HRESULT
DX12ImageRenderer::RetrieveImageData(
    CpuImage& img_out, uint32_t width, uint32_t height, uint32_t pitch, DXGI_FORMAT format, bool convert_to_bgra)
{
    void*       uav_data   = nullptr;
    D3D12_RANGE read_range = { 0, 0 };

    auto result = staging_->Map(0, &read_range, &uav_data);

    if (result == S_OK)
    {
        const uint32_t total_bytes = pitch * height;

        img_out.pitch  = pitch;
        img_out.width  = width;
        img_out.height = height;
        img_out.data.resize(total_bytes);

        auto success = CopyImageData(std::data(img_out.data),
                                     reinterpret_cast<const uint8_t*>(uav_data),
                                     total_bytes,
                                     width,
                                     height,
                                     pitch,
                                     format,
                                     convert_to_bgra);

        if (!success)
        {
            // Only report errors once per format.
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
