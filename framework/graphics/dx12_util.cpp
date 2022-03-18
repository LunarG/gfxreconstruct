/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "graphics/dx12_util.h"

#include "util/image_writer.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

void TakeScreenshot(std::unique_ptr<graphics::DX12ImageRenderer>& image_renderer,
                    ID3D12CommandQueue*                           queue,
                    IDXGISwapChain*                               swapchain,
                    uint32_t                                      frame_num,
                    const std::string&                            filename_prefix)
{
    if (queue != nullptr && swapchain != nullptr)
    {
        Microsoft::WRL::ComPtr<IDXGISwapChain3> swapchain3   = nullptr;
        Microsoft::WRL::ComPtr<IDXGISwapChain>  swapChainCom = swapchain;

        HRESULT hr = swapChainCom.As(&swapchain3);

        if (hr == S_OK)
        {
            const int backbuffer_idx = swapchain3->GetCurrentBackBufferIndex();

            Microsoft::WRL::ComPtr<ID3D12Resource> frame_buffer_resource = nullptr;
            hr                                                           = swapchain->GetBuffer(backbuffer_idx,
                                      __uuidof(ID3D12Resource),
                                      reinterpret_cast<void**>(frame_buffer_resource.GetAddressOf()));

            if (hr == S_OK)
            {
                if (image_renderer == nullptr)
                {
                    Microsoft::WRL::ComPtr<ID3D12Device> parent_device = nullptr;
                    hr                                                 = queue->GetDevice(IID_PPV_ARGS(&parent_device));

                    if (hr == S_OK)
                    {
                        gfxrecon::graphics::DX12ImageRendererConfig renderer_config;
                        renderer_config.cmd_queue = queue;
                        renderer_config.device    = parent_device.Get();

                        image_renderer = gfxrecon::graphics::DX12ImageRenderer::Create(renderer_config);
                    }
                }

                if (image_renderer != nullptr)
                {
                    D3D12_RESOURCE_DESC fb_desc = frame_buffer_resource->GetDesc();

                    auto pitch = (fb_desc.Width * graphics::BytesPerPixel + D3D12_TEXTURE_DATA_PITCH_ALIGNMENT - 1) /
                                 D3D12_TEXTURE_DATA_PITCH_ALIGNMENT * D3D12_TEXTURE_DATA_PITCH_ALIGNMENT;

                    graphics::CpuImage captured_image = {};

                    HRESULT capture_result = image_renderer->CaptureImage(frame_buffer_resource.Get(),
                                                                          D3D12_RESOURCE_STATE_PRESENT,
                                                                          static_cast<unsigned int>(fb_desc.Width),
                                                                          fb_desc.Height,
                                                                          static_cast<unsigned int>(pitch),
                                                                          fb_desc.Format);

                    if (capture_result == S_OK)
                    {
                        auto buffer_byte_size = pitch * fb_desc.Height;
                        auto desc             = frame_buffer_resource->GetDesc();
                        capture_result        = image_renderer->RetrieveImageData(&captured_image,
                                                                           static_cast<unsigned int>(fb_desc.Width),
                                                                           fb_desc.Height,
                                                                           static_cast<unsigned int>(pitch),
                                                                           desc.Format);

                        if (capture_result == S_OK)
                        {
                            auto        datasize = static_cast<int>(buffer_byte_size);
                            std::string filename = filename_prefix;

                            filename += "_frame_";
                            filename += std::to_string(frame_num);
                            filename += ".bmp";

                            util::imagewriter::WriteBmpImage(filename,
                                                             static_cast<unsigned int>(fb_desc.Width),
                                                             static_cast<unsigned int>(fb_desc.Height),
                                                             datasize,
                                                             std::data(captured_image.data),
                                                             static_cast<unsigned int>(pitch));
                        }
                    }
                }
            }
        }
    }
}

HRESULT MapSubresource(ID3D12Resource* resource, UINT subresource, const D3D12_RANGE* read_range, uint8_t*& data_ptr)
{
    HRESULT result = E_FAIL;

    // Map the readable resource.
    void* void_ptr = nullptr;
    result         = resource->Map(subresource, read_range, &void_ptr);
    if (SUCCEEDED(result))
    {
        data_ptr = static_cast<uint8_t*>(void_ptr);
        if (data_ptr == nullptr)
        {
            D3D12_RANGE write_range = { 0, 0 };
            resource->Unmap(subresource, &write_range);
            result = E_POINTER;
        }
    }

    return result;
}

HRESULT WaitForQueue(ID3D12CommandQueue* queue)
{
    HRESULT            result = E_FAIL;
    ID3D12DeviceComPtr device;
    result = queue->GetDevice(IID_PPV_ARGS(&device));
    if (SUCCEEDED(result))
    {
        ID3D12FenceComPtr fence;
        result = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
        if (SUCCEEDED(result))
        {
            HANDLE idle_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
            if (idle_event != nullptr)
            {
                result = fence->SetEventOnCompletion(1, idle_event);
                if (SUCCEEDED(result))
                {
                    result = queue->Signal(fence, 1);
                    if (SUCCEEDED(result))
                    {
                        WaitForSingleObject(idle_event, INFINITE);
                        result = S_OK;
                    }
                }
                CloseHandle(idle_event);
            }
        }
    }
    return result;
}

void AnalyzeDeviceRemoved(ID3D12Device* device)
{
    ID3D12DeviceRemovedExtendedData1ComPtr dred = nullptr;
    HRESULT                                hr   = device->QueryInterface(IID_PPV_ARGS(&dred));

    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 dred_auto_breadcrumb_output = {};
    hr = dred->GetAutoBreadcrumbsOutput1(&dred_auto_breadcrumb_output);

    D3D12_DRED_PAGE_FAULT_OUTPUT dred_page_fault_output = {};
    hr                                                  = dred->GetPageFaultAllocationOutput(&dred_page_fault_output);

    // Analyze output structs here
}

ID3D12ResourceComPtr CreateBufferResource(ID3D12Device*         device,
                                          uint64_t              size,
                                          D3D12_HEAP_TYPE       heap_type,
                                          D3D12_RESOURCE_STATES initial_state,
                                          D3D12_RESOURCE_FLAGS  flags)
{
    D3D12_HEAP_PROPERTIES heap_props;
    heap_props.Type                 = heap_type;
    heap_props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    heap_props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    heap_props.CreationNodeMask     = 1;
    heap_props.VisibleNodeMask      = 1;

    D3D12_RESOURCE_DESC res_desc;
    res_desc.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    res_desc.Alignment          = 0;
    res_desc.Width              = size;
    res_desc.Height             = 1;
    res_desc.DepthOrArraySize   = 1;
    res_desc.MipLevels          = 1;
    res_desc.Format             = DXGI_FORMAT_UNKNOWN;
    res_desc.SampleDesc.Count   = 1;
    res_desc.SampleDesc.Quality = 0;
    res_desc.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    res_desc.Flags              = flags;

    ID3D12ResourceComPtr resource = nullptr;
    device->CreateCommittedResource(
        &heap_props, D3D12_HEAP_FLAG_NONE, &res_desc, initial_state, nullptr, IID_PPV_ARGS(&resource));
    GFXRECON_ASSERT(resource);

    return resource;
}

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
