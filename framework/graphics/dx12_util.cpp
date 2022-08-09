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

HRESULT WaitForQueue(ID3D12CommandQueue* queue, ID3D12Fence* fence, uint64_t fence_value)
{
    HRESULT            result = E_FAIL;
    ID3D12DeviceComPtr device;
    ID3D12Fence*       temp_fence = nullptr;
    result = queue->GetDevice(IID_PPV_ARGS(&device));
    if (SUCCEEDED(result))
    {
        if (nullptr == fence)
        {
            result = device->CreateFence(fence_value++, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
            temp_fence = fence;
        }
        if (SUCCEEDED(result))
        {
            HANDLE idle_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
            if (idle_event != nullptr)
            {
                result = fence->SetEventOnCompletion(fence_value, idle_event);
                if (SUCCEEDED(result))
                {
                    result = queue->Signal(fence, fence_value);
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
    if (temp_fence != nullptr)
    {
        temp_fence->Release();
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

void GetAccelerationStructureInputsBufferEntries(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& inputs_desc,
                                                 D3D12_RAYTRACING_GEOMETRY_DESC*                       geometry_descs,
                                                 uint64_t&                       inputs_buffer_size,
                                                 std::vector<InputsBufferEntry>& entries)
{
    inputs_buffer_size = 0;
    if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL)
    {
        for (UINT i = 0; i < inputs_desc.NumDescs; ++i)
        {
            auto* geom_desc = &geometry_descs[i];
            GFXRECON_ASSERT(geom_desc);

            if (geom_desc->Type == D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES)
            {
                auto& triangles_desc = geom_desc->Triangles;

                if (triangles_desc.Transform3x4 != 0)
                {
                    const uint64_t kTransform3x4Size = 3 * 4 * sizeof(float);
                    inputs_buffer_size =
                        util::platform::AlignValue<D3D12_RAYTRACING_TRANSFORM3X4_BYTE_ALIGNMENT>(inputs_buffer_size);
                    entries.push_back({ inputs_buffer_size, &triangles_desc.Transform3x4, kTransform3x4Size });
                    inputs_buffer_size += kTransform3x4Size;
                }

                if (triangles_desc.IndexCount != 0)
                {
                    GFXRECON_ASSERT(triangles_desc.IndexBuffer != 0);

                    uint32_t index_size = 0;
                    switch (triangles_desc.IndexFormat)
                    {
                        case DXGI_FORMAT_R32_UINT:
                            index_size         = 4;
                            inputs_buffer_size = util::platform::AlignValue<4>(inputs_buffer_size);
                            break;
                        case DXGI_FORMAT_R16_UINT:
                            index_size         = 2;
                            inputs_buffer_size = util::platform::AlignValue<2>(inputs_buffer_size);
                            break;
                        default:
                            GFXRECON_LOG_ERROR(
                                "Invalid D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC::IndexFormat (IndexFormat=%d).",
                                triangles_desc.IndexFormat);
                            break;
                    }
                    const uint32_t indices_size = triangles_desc.IndexCount * index_size;
                    entries.push_back({ inputs_buffer_size, &triangles_desc.IndexBuffer, indices_size });
                    inputs_buffer_size += indices_size;
                }

                const uint64_t vertices_size = triangles_desc.VertexCount * triangles_desc.VertexBuffer.StrideInBytes;
                if (vertices_size > 0)
                {
                    GFXRECON_ASSERT(triangles_desc.VertexBuffer.StartAddress != 0);

                    // Vertex alignment must be a power of two and a multiple of the size of a single component of the
                    // vertex format. Current component sizes are 2 and 4 bytes, pad to 8 to future proof. If an
                    // alignment larger than 8 is ever needed, those types could be supported here.
                    const uint64_t kVertexAlignment = 8;

                    inputs_buffer_size = util::platform::AlignValue<kVertexAlignment>(inputs_buffer_size);
                    entries.push_back({ inputs_buffer_size, &triangles_desc.VertexBuffer.StartAddress, vertices_size });
                    inputs_buffer_size += vertices_size;
                }
                else
                {
                    GFXRECON_LOG_ERROR("D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC's vertex data has 0 byte size.");
                }
            }
            else if (geom_desc->Type == D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS)
            {
                GFXRECON_ASSERT(geom_desc->AABBs.AABBs.StartAddress != 0);

                auto&    aabbs_desc = geom_desc->AABBs;
                uint64_t aabb_size =
                    std::max(aabbs_desc.AABBs.StrideInBytes, static_cast<uint64_t>(sizeof(D3D12_RAYTRACING_AABB)));
                const uint64_t aabbs_size = aabbs_desc.AABBCount * aabb_size;
                inputs_buffer_size =
                    util::platform::AlignValue<D3D12_RAYTRACING_AABB_BYTE_ALIGNMENT>(inputs_buffer_size);
                entries.push_back({ inputs_buffer_size, &aabbs_desc.AABBs.StartAddress, aabbs_size });
                inputs_buffer_size += aabbs_size;
            }
            else
            {
                GFXRECON_LOG_ERROR("Unrecognized raytracing acceleration geomtry type type (Type=%d).",
                                   geom_desc->Type);
            }
        }
    }
    else if (inputs_desc.Type == D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL)
    {
        if (inputs_desc.DescsLayout == D3D12_ELEMENTS_LAYOUT_ARRAY)
        {
            GFXRECON_ASSERT(inputs_desc.InstanceDescs != 0);

            inputs_buffer_size = inputs_desc.NumDescs * sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
            InputsBufferEntry entry{};
            entry.desc_gpu_va = &inputs_desc.InstanceDescs;
            entry.offset      = 0;
            entry.size        = inputs_buffer_size;
            entries.push_back(entry);
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "Unsupported instance descs layout (DescsLayout=%d) used in BuildRaytracingAccelerationStructure.",
                inputs_desc.DescsLayout);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Unrecognized raytracing acceleration structure inputs type (Type=%d).", inputs_desc.Type);
    }
}

template <typename DescT>
void TrackAdapterDesc(IDXGIAdapter*                     adapter,
                      UINT32                            adapter_idx,
                      const DescT&                      dxgi_desc,
                      graphics::dx12::ActiveAdapterMap& adapters,
                      format::AdapterType               type)
{
    const int64_t packed_luid = (dxgi_desc.AdapterLuid.HighPart << 31) | dxgi_desc.AdapterLuid.LowPart;

    if (adapters.count(packed_luid) == 0)
    {
        format::DxgiAdapterDesc internal_desc = {};

        util::platform::MemoryCopy(&internal_desc.Description,
                                   sizeof(internal_desc.Description),
                                   &dxgi_desc.Description,
                                   sizeof(dxgi_desc.Description));

        internal_desc.VendorId              = dxgi_desc.VendorId;
        internal_desc.DeviceId              = dxgi_desc.DeviceId;
        internal_desc.SubSysId              = dxgi_desc.SubSysId;
        internal_desc.Revision              = dxgi_desc.Revision;
        internal_desc.DedicatedVideoMemory  = dxgi_desc.DedicatedVideoMemory;
        internal_desc.DedicatedSystemMemory = dxgi_desc.DedicatedSystemMemory;
        internal_desc.SharedSystemMemory    = dxgi_desc.SharedSystemMemory;
        internal_desc.LuidLowPart           = dxgi_desc.AdapterLuid.LowPart;
        internal_desc.LuidHighPart          = dxgi_desc.AdapterLuid.HighPart;
        internal_desc.type                  = type;

        ActiveAdapterInfo adapter_info = {};
        adapter_info.internal_desc     = internal_desc;
        adapter_info.adapter           = adapter;
        adapter_info.adapter_idx       = adapter_idx;
        adapter_info.active            = false;

        adapters[packed_luid] = adapter_info;
    }
}

void TrackAdapters(HRESULT result, void** ppFactory, graphics::dx12::ActiveAdapterMap& adapters)
{
    if (SUCCEEDED(result))
    {
        // First see if the created factory can be queried as a 1.1 factory
        IDXGIFactory1* factory1 = reinterpret_cast<IDXGIFactory1*>(*ppFactory);

        // DXGI 1.1 tracking (default)
        if (SUCCEEDED(factory1->QueryInterface(__uuidof(IDXGIFactory1), reinterpret_cast<void**>(&factory1))))
        {
            // Get a fresh enumeration, in case it was previously filled by 1.0 tracking
            adapters.clear();

            // Enumerate 1.1 adapters and fetch data with GetDesc1()
            IDXGIAdapter1* adapter1 = nullptr;

            for (UINT adapter_idx = 0; SUCCEEDED(factory1->EnumAdapters1(adapter_idx, &adapter1)); ++adapter_idx)
            {
                DXGI_ADAPTER_DESC1 dxgi_desc = {};
                adapter1->GetDesc1(&dxgi_desc);

                format::AdapterType adapter_type = format::AdapterType::kHardwareAdapter;
                if (dxgi_desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
                {
                    adapter_type = format::AdapterType::kSoftwareAdapter;
                }

                TrackAdapterDesc(adapter1, adapter_idx, dxgi_desc, adapters, adapter_type);
            }
        }

        // DXGI 1.0 tracking (fall-back)
        else
        {
            // Only enumerate 1.0 factory adapters if nothing has been seen yet
            if (adapters.empty())
            {
                IDXGIFactory* factory = reinterpret_cast<IDXGIFactory*>(*ppFactory);

                if (SUCCEEDED(factory->QueryInterface(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&factory))))
                {
                    // Enumerate 1.0 adapters and fetch data with GetDesc()
                    IDXGIAdapter* adapter = nullptr;

                    for (UINT adapter_idx = 0; SUCCEEDED(factory->EnumAdapters(adapter_idx, &adapter)); ++adapter_idx)
                    {
                        DXGI_ADAPTER_DESC dxgi_desc = {};
                        adapter->GetDesc(&dxgi_desc);

                        TrackAdapterDesc(
                            adapter, adapter_idx, dxgi_desc, adapters, format::AdapterType::kUnknownAdapter);
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("Could not enumerate and track factory's adapters.")
                }
            }
        }
    }
}

format::DxgiAdapterDesc* MarkActiveAdapter(ID3D12Device* device, graphics::dx12::ActiveAdapterMap& adapters)
{
    format::DxgiAdapterDesc* active_adapter_desc = nullptr;

    if (device != nullptr)
    {
        // Get the device's parent adapter identifier
        LUID parent_adapter_luid = device->GetAdapterLuid();

        const int64_t packed_luid = (parent_adapter_luid.HighPart << 31) | parent_adapter_luid.LowPart;

        // Mark an adapter as active
        for (auto& adapter : adapters)
        {
            if (adapter.first == packed_luid)
            {
                // Only return adapter desc pointer if it hasn't already been seen
                if (adapter.second.active == false)
                {
                    active_adapter_desc = &adapter.second.internal_desc;
                }

                adapter.second.active = true;

                break;
            }
        }
    }

    return active_adapter_desc;
}

bool IsSoftwareAdapter(const format::DxgiAdapterDesc& adapter_desc)
{
    bool software_desc = false;

    if ((adapter_desc.type & format::AdapterType::kSoftwareAdapter) ||
        (adapter_desc.DeviceId == 0x8c) && (adapter_desc.VendorId == 0x1414))
    {
        software_desc = true;
    }

    return software_desc;
}

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
