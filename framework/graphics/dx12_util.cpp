/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "graphics/dx12_util.h"

#include "util/image_writer.h"
#include "util/logging.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

#ifdef WIN32

UINT GetTexturePitch(UINT64 width)
{
    return (width * graphics::BytesPerPixel + D3D12_TEXTURE_DATA_PITCH_ALIGNMENT - 1) /
           D3D12_TEXTURE_DATA_PITCH_ALIGNMENT * D3D12_TEXTURE_DATA_PITCH_ALIGNMENT;
}

void TakeScreenshot(std::unique_ptr<graphics::DX12ImageRenderer>& image_renderer,
                    ID3D12CommandQueue*                           queue,
                    IDXGISwapChain*                               swapchain,
                    uint32_t                                      frame_num,
                    const std::string&                            filename_prefix,
                    gfxrecon::util::ScreenshotFormat              screenshot_format)
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

                    auto pitch = GetTexturePitch(fb_desc.Width);

                    graphics::CpuImage captured_image = {};

                    HRESULT capture_result = image_renderer->CaptureImage(frame_buffer_resource.Get(),
                                                                          D3D12_RESOURCE_STATE_PRESENT,
                                                                          static_cast<unsigned int>(fb_desc.Width),
                                                                          fb_desc.Height,
                                                                          static_cast<unsigned int>(pitch),
                                                                          fb_desc.Format);

                    if (capture_result == S_OK)
                    {
                        bool convert_to_bgra  = (screenshot_format == gfxrecon::util::ScreenshotFormat::kBmp);
                        auto buffer_byte_size = pitch * fb_desc.Height;
                        capture_result        = image_renderer->RetrieveImageData(&captured_image,
                                                                           static_cast<unsigned int>(fb_desc.Width),
                                                                           fb_desc.Height,
                                                                           static_cast<unsigned int>(pitch),
                                                                           fb_desc.Format,
                                                                           convert_to_bgra);

                        if (capture_result == S_OK)
                        {
                            auto        datasize = static_cast<int>(buffer_byte_size);
                            std::string filename = filename_prefix;

                            filename += "_frame_";
                            filename += std::to_string(frame_num);

                            switch (screenshot_format)
                            {
                                default:
                                    GFXRECON_LOG_ERROR(
                                        "Screenshot format invalid!  Expected BMP or PNG, falling back to BMP.");
                                    // Intentional fall-through
                                case gfxrecon::util::ScreenshotFormat::kBmp:
                                    if (!util::imagewriter::WriteBmpImage(filename + ".bmp",
                                                                          static_cast<unsigned int>(fb_desc.Width),
                                                                          static_cast<unsigned int>(fb_desc.Height),
                                                                          datasize,
                                                                          std::data(captured_image.data),
                                                                          static_cast<unsigned int>(pitch)))
                                    {
                                        GFXRECON_LOG_ERROR(
                                            "Screenshot could not be created: failed to write BMP file %s",
                                            filename.c_str());
                                    }
                                    break;
                                case gfxrecon::util::ScreenshotFormat::kPng:
                                    if (!util::imagewriter::WritePngImage(filename + ".png",
                                                                          static_cast<unsigned int>(fb_desc.Width),
                                                                          static_cast<unsigned int>(fb_desc.Height),
                                                                          datasize,
                                                                          std::data(captured_image.data),
                                                                          static_cast<unsigned int>(pitch),
                                                                          util::imagewriter::kFormat_RGBA))
                                    {
                                        GFXRECON_LOG_ERROR(
                                            "Screenshot could not be created: failed to write PNG file %s",
                                            filename.c_str());
                                    }
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }
}

HRESULT MapSubresource(ID3D12Resource*    resource,
                       UINT               subresource,
                       const D3D12_RANGE* read_range,
                       uint8_t*&          data_ptr,
                       bool               is_texture_with_unknown_layout)
{
    HRESULT result = E_FAIL;

    // Map the readable resource.
    if (!is_texture_with_unknown_layout)
    {
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
    }
    else
    {
        // Quote: "A null pointer is valid and is useful to cache a CPU virtual address range for methods like
        // WriteToSubresource."
        //
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-map
        //
        // Compared with other types of resource, it has the following difference for mapping
        // and access data of texture with unknown layout:
        //
        // 1. Map call cannot get map pointer and ppData parameter must be nullptr.
        //
        // 2. After mapping, the following access to the resource data need call
        //    ID3D12Resource::WriteToSubresource or ID3D12Resource::ReadFromSubresource.

        result   = resource->Map(subresource, read_range, nullptr);
        data_ptr = nullptr;
    }

    return result;
}

HRESULT WaitForQueue(ID3D12CommandQueue* queue, ID3D12Fence* fence, uint64_t fence_value)
{
    HRESULT            result = E_FAIL;
    ID3D12DeviceComPtr device;
    ID3D12Fence*       temp_fence = nullptr;
    result                        = queue->GetDevice(IID_PPV_ARGS(&device));
    if (SUCCEEDED(result))
    {
        if (nullptr == fence)
        {
            result     = device->CreateFence(fence_value++, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
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
                    GFXRECON_LOG_DEBUG("D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC's vertex data has 0 byte size. "
                                       "(vertex count: %u, vertex stride in bytes: %" PRIu64
                                       "). Skipping acceleration structure input data for this desc.",
                                       triangles_desc.VertexCount,
                                       triangles_desc.VertexBuffer.StrideInBytes);
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
            if (inputs_desc.NumDescs > 0)
            {
                GFXRECON_ASSERT(inputs_desc.InstanceDescs != 0);

                inputs_buffer_size = inputs_desc.NumDescs * sizeof(D3D12_RAYTRACING_INSTANCE_DESC);
                InputsBufferEntry entry{};
                entry.desc_gpu_va = &inputs_desc.InstanceDescs;
                entry.offset      = 0;
                entry.size        = inputs_buffer_size;
                entries.push_back(entry);
            }
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

// Get one pixel byte size for specific DXGI_FORMAT. The function is used by GetOneRowUnpaddedSize
// function.
// Note: The function only support the formats for which one pixel has one or multiple bytes.
//       For those formats which are comppreesed types, or one pixel has bits that
//       are not one or multiple bytes such as DXGI_FORMAT_R1_UNORM, DXGI_FORMAT_BC1_TYPELESS,
//       they are not supported and the return value will be zero.
//       For these unsupported formats, GetOneRowUnpaddedSize function will query the one row
//       unpadded size through inserting some API calls.
uint64_t GetSubresourcePixelByteSize(DXGI_FORMAT format)
{
    uint64_t                                 size          = 0;
    std::unordered_map<DXGI_FORMAT, uint8_t> byte_size_map = {
        { DXGI_FORMAT_R32G32B32A32_TYPELESS, 16 },
        { DXGI_FORMAT_R32G32B32A32_FLOAT, 16 },
        { DXGI_FORMAT_R32G32B32A32_UINT, 16 },
        { DXGI_FORMAT_R32G32B32A32_SINT, 16 },
        { DXGI_FORMAT_R32G32B32_TYPELESS, 12 },
        { DXGI_FORMAT_R32G32B32_FLOAT, 12 },
        { DXGI_FORMAT_R32G32B32_UINT, 12 },
        { DXGI_FORMAT_R32G32B32_SINT, 12 },
        { DXGI_FORMAT_R16G16B16A16_TYPELESS, 8 },
        { DXGI_FORMAT_R16G16B16A16_FLOAT, 8 },
        { DXGI_FORMAT_R16G16B16A16_UNORM, 8 },
        { DXGI_FORMAT_R16G16B16A16_UINT, 8 },
        { DXGI_FORMAT_R16G16B16A16_SNORM, 8 },
        { DXGI_FORMAT_R16G16B16A16_SINT, 8 },
        { DXGI_FORMAT_R32G32_TYPELESS, 8 },
        { DXGI_FORMAT_R32G32_FLOAT, 8 },
        { DXGI_FORMAT_R32G32_UINT, 8 },
        { DXGI_FORMAT_R32G32_SINT, 8 },
        { DXGI_FORMAT_R32G8X24_TYPELESS, 8 },
        { DXGI_FORMAT_D32_FLOAT_S8X24_UINT, 4 },
        { DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS, 4 },
        { DXGI_FORMAT_X32_TYPELESS_G8X24_UINT, 4 },
        { DXGI_FORMAT_R10G10B10A2_TYPELESS, 4 },
        { DXGI_FORMAT_R10G10B10A2_UNORM, 4 },
        { DXGI_FORMAT_R10G10B10A2_UINT, 4 },
        { DXGI_FORMAT_R11G11B10_FLOAT, 4 },
        { DXGI_FORMAT_R8G8B8A8_TYPELESS, 4 },
        { DXGI_FORMAT_R8G8B8A8_UNORM, 4 },
        { DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, 4 },
        { DXGI_FORMAT_R8G8B8A8_UINT, 4 },
        { DXGI_FORMAT_R8G8B8A8_SNORM, 4 },
        { DXGI_FORMAT_R8G8B8A8_SINT, 4 },
        { DXGI_FORMAT_R16G16_TYPELESS, 4 },
        { DXGI_FORMAT_R16G16_FLOAT, 4 },
        { DXGI_FORMAT_R16G16_UNORM, 4 },
        { DXGI_FORMAT_R16G16_UINT, 4 },
        { DXGI_FORMAT_R16G16_SNORM, 4 },
        { DXGI_FORMAT_R16G16_SINT, 4 },
        { DXGI_FORMAT_R32_TYPELESS, 4 },
        { DXGI_FORMAT_D32_FLOAT, 4 },
        { DXGI_FORMAT_R32_FLOAT, 4 },
        { DXGI_FORMAT_R32_UINT, 4 },
        { DXGI_FORMAT_R32_SINT, 4 },
        { DXGI_FORMAT_R24G8_TYPELESS, 4 },
        { DXGI_FORMAT_D24_UNORM_S8_UINT, 4 },
        { DXGI_FORMAT_R24_UNORM_X8_TYPELESS, 4 },
        { DXGI_FORMAT_X24_TYPELESS_G8_UINT, 4 },
        { DXGI_FORMAT_R8G8_TYPELESS, 2 },
        { DXGI_FORMAT_R8G8_UNORM, 2 },
        { DXGI_FORMAT_R8G8_UINT, 2 },
        { DXGI_FORMAT_R8G8_SNORM, 2 },
        { DXGI_FORMAT_R8G8_SINT, 2 },
        { DXGI_FORMAT_R16_TYPELESS, 2 },
        { DXGI_FORMAT_R16_FLOAT, 2 },
        { DXGI_FORMAT_D16_UNORM, 2 },
        { DXGI_FORMAT_R16_UNORM, 2 },
        { DXGI_FORMAT_R16_UINT, 2 },
        { DXGI_FORMAT_R16_SNORM, 2 },
        { DXGI_FORMAT_R16_SINT, 2 },
        { DXGI_FORMAT_R8_TYPELESS, 1 },
        { DXGI_FORMAT_R8_UNORM, 1 },
        { DXGI_FORMAT_R8_UINT, 1 },
        { DXGI_FORMAT_R8_SNORM, 1 },
        { DXGI_FORMAT_R8_SINT, 1 },
        { DXGI_FORMAT_A8_UNORM, 1 },
        { DXGI_FORMAT_R9G9B9E5_SHAREDEXP, 4 },
        { DXGI_FORMAT_R8G8_B8G8_UNORM,
          2 }, // Each 32-bit block describes a pair of pixels: (R8, G8, B8) and (R8, G8, B8) where the R8/B8 values are
               // repeated, and the G8 values are unique to each pixel
        { DXGI_FORMAT_G8R8_G8B8_UNORM,
          2 }, //  Each 32-bit block describes a pair of pixels: (R8, G8, B8) and (R8, G8, B8) where the R8/B8 values
               //  are repeated, and the G8 values are unique to each pixel
        { DXGI_FORMAT_B5G6R5_UNORM, 2 }, // A three-component, 16-bit unsigned-normalized-integer format that supports 5
                                         // bits for blue, 6 bits for green, and 5 bits for red
        { DXGI_FORMAT_B5G5R5A1_UNORM, 4 },
        { DXGI_FORMAT_B8G8R8A8_UNORM, 4 },
        { DXGI_FORMAT_B8G8R8X8_UNORM, 4 },
        { DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM, 4 },
        { DXGI_FORMAT_B8G8R8A8_TYPELESS, 4 },
        { DXGI_FORMAT_B8G8R8A8_UNORM_SRGB, 4 },
        { DXGI_FORMAT_B8G8R8X8_TYPELESS, 4 },
        { DXGI_FORMAT_B8G8R8X8_UNORM_SRGB, 4 },
        { DXGI_FORMAT_P8, 1 },
        { DXGI_FORMAT_A8P8, 2 },
        { DXGI_FORMAT_B4G4R4A4_UNORM, 2 },

        { DXGI_FORMAT_P208, 1 },
        { DXGI_FORMAT_V208, 1 },
        { DXGI_FORMAT_V408, 1 },

        { DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE, 4 },
        { DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE, 4 }
    };

    if (byte_size_map.find(format) != byte_size_map.end())
    {
        size = byte_size_map[format];
    }
    else
    {
        GFXRECON_LOG_ERROR("Unsupported format: %d", format);
    }

    return size;
}

uint64_t GetOneRowSizeByDXGIFormat(DXGI_FORMAT format, UINT width)
{
    return width * GetSubresourcePixelByteSize(format);
}

uint64_t GetOneRowSizeByDXGIFormat(ID3D12Resource*      resource,
                                   D3D12_RESOURCE_DESC* resource_desc,
                                   UINT                 dst_subresource,
                                   uint64_t             width)
{
    uint64_t data_size = GetOneRowSizeByDXGIFormat(resource_desc->Format, static_cast<UINT>(width));

    if (data_size == 0)
    {
        // The returned one row unpadded size is zero that mean the format isnot supported by
        // GetOneRowUnpaddedSize(DXGI_FORMAT Format, UINT width). We need to insert API calls
        // to calculate the size.
        graphics::dx12::ID3D12DeviceComPtr device = nullptr;
        if (SUCCEEDED(resource->GetDevice(IID_PPV_ARGS(&device))))
        {
            UINT64 subresource_row_size_bytes = 0;
            device->GetCopyableFootprints(
                resource_desc, dst_subresource, 1, 0, nullptr, nullptr, &subresource_row_size_bytes, nullptr);

            data_size = subresource_row_size_bytes * width / resource_desc->Width;
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to retrieve device from resource");
        }
    }

    return data_size;
}

// Get the size of writing data for a subresource for API ID3D12Resource::WriteToSubresource.
// The parameters DstSubresource, pDstBox, SrcRowPitch and SrcDepthPitch are same with their
// meaning in this API.
uint64_t GetSubresourceWriteDataSize(
    ID3D12Resource* resource, UINT dst_subresource, const D3D12_BOX* dst_box, UINT src_row_pitch, UINT src_depth_pitch)
{
    uint64_t            data_size      = 0;
    D3D12_RESOURCE_DESC resource_desc  = resource->GetDesc();
    D3D12_BOX           valid_size_box = {};
    bool                empty_box      = false;

    if (dst_box != nullptr)
    {
        if ((dst_box->left >= dst_box->right) || (dst_box->front >= dst_box->back) || (dst_box->top >= dst_box->bottom))
        {
            empty_box = true;
        }

        // When the box is empty, WriteToSubresource call doesn't perform any operation
        // Quote: An empty box results in a no-op. A box is empty if the top value is greater than or equal to
        //        the bottom value, or the left value is greater than or equal to the right value, or the front
        //        value is greater than or equal to the back value. When the box is empty, this method doesn't
        //        perform any operation.
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource
        if (!empty_box)
        {
            valid_size_box.right  = dst_box->right - dst_box->left;
            valid_size_box.back   = dst_box->back - dst_box->front;
            valid_size_box.bottom = dst_box->bottom - dst_box->top;
        }

        // The dimensions of the valid_size_box must fit the destination
        // Quote: The dimensions of the source must fit the destination (see D3D12_BOX).
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource
        if (valid_size_box.right > resource_desc.Width)
        {
            valid_size_box.right = static_cast<UINT>(resource_desc.Width);
        }

        if (valid_size_box.bottom > resource_desc.Height)
        {
            valid_size_box.bottom = static_cast<UINT>(resource_desc.Height);
        }

        if (valid_size_box.back > resource_desc.DepthOrArraySize)
        {
            valid_size_box.back = static_cast<UINT>(resource_desc.DepthOrArraySize);
        }
    }
    else
    {
        // If pDstBox == nullptr, the data is written to the destination subresource with no offset
        // Quote: A pointer to a box that defines the portion of the destination subresource to copy
        //        the resource data into. If NULL, the data is written to the destination subresource
        //        with no offset.
        // Source: https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12resource-writetosubresource
        valid_size_box.right  = static_cast<UINT>(resource_desc.Width);
        valid_size_box.bottom = static_cast<UINT>(resource_desc.Height);
        valid_size_box.back   = static_cast<UINT>(resource_desc.DepthOrArraySize);
    }

    if (!empty_box)
    {
        switch (resource_desc.Dimension)
        {
            case D3D12_RESOURCE_DIMENSION_TEXTURE1D:
                data_size = GetOneRowSizeByDXGIFormat(
                    resource, &resource_desc, dst_subresource, (uint64_t)valid_size_box.right);
                break;
            case D3D12_RESOURCE_DIMENSION_TEXTURE2D:
                data_size = static_cast<uint64_t>(src_row_pitch) * static_cast<uint64_t>((valid_size_box.bottom - 1)) +
                            GetOneRowSizeByDXGIFormat(
                                resource, &resource_desc, dst_subresource, (uint64_t)valid_size_box.right);
                break;
            case D3D12_RESOURCE_DIMENSION_TEXTURE3D:
                data_size = static_cast<uint64_t>(src_depth_pitch) * static_cast<uint64_t>((valid_size_box.back - 1)) +
                            static_cast<uint64_t>(src_row_pitch) * static_cast<uint64_t>((valid_size_box.bottom - 1)) +
                            GetOneRowSizeByDXGIFormat(
                                resource, &resource_desc, dst_subresource, (uint64_t)valid_size_box.right);
                break;
            case D3D12_RESOURCE_DIMENSION_UNKNOWN:
                GFXRECON_LOG_ERROR("Detected resource with D3D12_RESOURCE_DIMENSION_UNKNOWN dimensions");
                data_size = 0;
                break;
            case D3D12_RESOURCE_DIMENSION_BUFFER:
                // If the resource is a buffer, all coordinates are in bytes
                // Quote: If the resources are buffers, all coordinates are in bytes;
                // Source:
                // https://docs.microsoft.com/en-us/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion
                data_size = valid_size_box.right;
                break;
            default:
                GFXRECON_LOG_ERROR("Detected invalid resource dimensions");
                data_size = 0;
                break;
        }
    }

    return data_size;
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
        InjectAdapterType(internal_desc.extra_info, type);

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
            RemoveDeactivatedAdapters(adapters);

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

void RemoveDeactivatedAdapters(graphics::dx12::ActiveAdapterMap& adapters)
{
    std::vector<int64_t> deactivated_adapters;
    for (const auto& adapter : adapters)
    {
        if (adapter.second.active == false)
        {
            deactivated_adapters.push_back(adapter.first);
        }
    }

    for (auto deactive_adapter : deactivated_adapters)
    {
        adapters.erase(deactive_adapter);
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
#endif // WIN32

bool IsSoftwareAdapter(const format::DxgiAdapterDesc& adapter_desc)
{
    bool software_desc = false;
    auto adapter_type  = ExtractAdapterType(adapter_desc.extra_info);

    if ((adapter_type & format::AdapterType::kSoftwareAdapter) ||
        (adapter_desc.DeviceId == 0x8c) && (adapter_desc.VendorId == 0x1414))
    {
        software_desc = true;
    }

    return software_desc;
}

bool VerifyAgilitySDKRuntime()
{
    bool        detected_runtime = false;
    std::string tool_executable_path;

#if defined(D3D12_SUPPORT) && defined(WIN32)
    std::vector<char> module_name(MAX_PATH);

    auto ret = GetModuleFileNameA(nullptr, module_name.data(), MAX_PATH);
    if ((ret == 0) || ((ret == MAX_PATH) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER)))
    {
        GFXRECON_LOG_ERROR("GetModuleFileNameA failed with error code %d", GetLastError());
    }
    else
    {
        tool_executable_path = module_name.data();
    }

    if (!tool_executable_path.empty())
    {
        std::string tool_working_dir = "";
        size_t      dir_location     = tool_executable_path.find_last_of(util::filepath::kAltPathLastSepStr);
        if (dir_location >= 0)
        {
            tool_working_dir = tool_executable_path.substr(0, dir_location);
        }
        const std::string runtime_path = "\\D3D12\\D3D12Core.dll";
        if (gfxrecon::util::filepath::IsFile(tool_working_dir + runtime_path))
        {
            detected_runtime = true;
        }
    }
#endif

    return detected_runtime;
}

#if WIN32
bool GetAdapterAndIndexbyLUID(LUID                              luid,
                              IDXGIAdapter*&                    adapter_ptr,
                              uint32_t&                         index,
                              graphics::dx12::ActiveAdapterMap& adapters)
{
    bool success = false;

    const int64_t packed_luid = (luid.HighPart << 31) | luid.LowPart;

    auto search = adapters.find(packed_luid);
    if (search != adapters.end())
    {
        index       = search->second.adapter_idx;
        adapter_ptr = search->second.adapter;
        success     = true;
    }
    return success;
}

void GetActiveAdapterLuids(graphics::dx12::ActiveAdapterMap adapters, std::vector<LUID>& adapter_luids)
{
    for (auto& adapter : adapters)
    {
        if (adapter.second.active == true)
        {
            LUID info;
            info.HighPart = adapter.second.internal_desc.LuidHighPart;
            info.LowPart  = adapter.second.internal_desc.LuidLowPart;
            adapter_luids.push_back(info);
        }
    }
    if (adapter_luids.empty())
    {
        GFXRECON_LOG_WARNING("No active adapters were found");
    }
}

IDXGIAdapter* GetAdapterbyIndex(graphics::dx12::ActiveAdapterMap& adapters, int32_t index)
{
    for (auto adapter : adapters)
    {
        if (static_cast<int32_t>(adapter.second.adapter_idx) == index)
        {
            return adapter.second.adapter;
        }
    }
    return nullptr;
}

bool GetAdapterAndIndexbyDevice(ID3D12Device*                     device,
                                IDXGIAdapter3*&                   adapter3_ptr,
                                uint32_t&                         index,
                                graphics::dx12::ActiveAdapterMap& adapters)
{
    bool success = false;

    if (device != nullptr)
    {
        IDXGIAdapter* device_adapter      = nullptr;
        LUID          parent_adapter_luid = device->GetAdapterLuid();
        success = GetAdapterAndIndexbyLUID(parent_adapter_luid, device_adapter, index, adapters);

        if (success == true)
        {
            if (SUCCEEDED(
                    device_adapter->QueryInterface(__uuidof(IDXGIAdapter3), reinterpret_cast<void**>(&adapter3_ptr))))
            {
                success = true;
            }
            else
            {
                adapter3_ptr = nullptr;

                GFXRECON_LOG_ERROR("Could not Query adapter as IDXGIAdapter3");
            }
        }
        else
        {
            adapter3_ptr = nullptr;

            GFXRECON_LOG_ERROR("Could not retrieve tracked adapter %ll", parent_adapter_luid);
        }
    }

    return success;
}

format::DxgiAdapterDesc* GetAdapterDescByLUID(LUID parent_adapter_luid, graphics::dx12::ActiveAdapterMap& adapters)
{
    const int64_t            packed_luid         = (parent_adapter_luid.HighPart << 31) | parent_adapter_luid.LowPart;
    format::DxgiAdapterDesc* parent_adapter_desc = nullptr;
    for (auto& adapter : adapters)
    {
        if (adapter.first == packed_luid)
        {
            parent_adapter_desc = &adapter.second.internal_desc;
            break;
        }
    }
    return parent_adapter_desc;
}

bool IsUma(ID3D12Device* device)
{
    GFXRECON_ASSERT(nullptr != device && "Null device pointer is expected to have been checked by callers.");
    bool                             isUma = false;
    D3D12_FEATURE_DATA_ARCHITECTURE1 architecture_info{};
    const auto                       result =
        device->CheckFeatureSupport(D3D12_FEATURE_ARCHITECTURE1, &architecture_info, sizeof(architecture_info));
    if (SUCCEEDED(result))
    {
        isUma = architecture_info.UMA;
    }
    else
    {
        GFXRECON_LOG_ERROR("CheckFeatureSupport(D3D12_FEATURE_ARCHITECTURE,...) failed with result: %ld. The GPU will "
                           "be assumed to be non-UMA.",
                           static_cast<long>(result));
    }
    return isUma;
}

uint64_t GetAvailableGpuAdapterMemory(IDXGIAdapter3* adapter, double memory_usage, const bool is_uma)
{
    GFXRECON_ASSERT(memory_usage > 0.0 && memory_usage <= 1.0);
    uint64_t available_mem = 0;
    if (adapter != nullptr)
    {
        DXGI_QUERY_VIDEO_MEMORY_INFO video_memory_info = {};
        DXGI_MEMORY_SEGMENT_GROUP    memory_segment    = DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL;
        if (is_uma)
        {
            memory_segment = DXGI_MEMORY_SEGMENT_GROUP_LOCAL;
        }
        if (SUCCEEDED(adapter->QueryVideoMemoryInfo(0, memory_segment, &video_memory_info)))
        {
            uint64_t total_memory = static_cast<uint64_t>(video_memory_info.Budget * memory_usage);
            if (total_memory > video_memory_info.CurrentUsage)
            {
                available_mem = total_memory - video_memory_info.CurrentUsage;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Could not query available memory from adapter.");
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Could not identify adapter to fetch available memory.");
    }

    return available_mem;
}

uint64_t GetAvailableCpuMemory(double max_usage)
{
    GFXRECON_ASSERT(max_usage > 0.0 && max_usage <= 1.0);
    MEMORYSTATUSEX mem_info = {};
    mem_info.dwLength       = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&mem_info) == FALSE)
    {
        GFXRECON_LOG_ERROR("Failed to get available virtual memory");
    }

    // Only limit by available physical memory if max_usage <= 1.0.
    uint64_t avail_phys = std::numeric_limits<uint64_t>::max();
    if (max_usage <= 1.0)
    {
        double reserved_phys = mem_info.ullTotalPhys * (1.0 - max_usage);
        avail_phys           = static_cast<uint64_t>(std::max(0.0, mem_info.ullAvailPhys - reserved_phys));
    }
    // Always limit by available virtual memory.
    return std::min(avail_phys, mem_info.ullAvailVirtual);
}

bool IsMemoryAvailable(uint64_t required_memory, IDXGIAdapter3* adapter, double max_mem_usage, const bool is_uma)
{
    bool available = false;
    if (max_mem_usage == 0.0)
    {
        // 0.0 means no batching, skip memory checking
        return available;
    }
#ifdef _WIN64
    // For 32bit, only upload one buffer at one time, to save memory usage.
    if (max_mem_usage > 0.0 && max_mem_usage <= 1.0)
    {
        if (adapter != nullptr)
        {
            uint64_t total_available_gpu_adapter_memory = GetAvailableGpuAdapterMemory(adapter, max_mem_usage, is_uma);
            uint64_t total_available_cpu_memory         = GetAvailableCpuMemory(max_mem_usage);
            uint64_t total_required_memory              = static_cast<uint64_t>(required_memory * kMemoryTolerance);
            if ((total_required_memory < total_available_gpu_adapter_memory) &&
                (total_required_memory < total_available_cpu_memory))
            {
                available = true;
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Memory usage setting out of range");
    }
#endif
    return available;
}

uint64_t GetResourceSizeInBytes(ID3D12Device* device, const D3D12_RESOURCE_DESC* desc)
{
    uint64_t size = 0;

    if (device != nullptr)
    {
        size = device->GetResourceAllocationInfo(0, 1, desc).SizeInBytes;
    }

    return size;
}

uint64_t GetResourceSizeInBytes(ID3D12Device8* device, const D3D12_RESOURCE_DESC1* desc)
{
    uint64_t size = 0;

    if (device != nullptr)
    {
        D3D12_RESOURCE_ALLOCATION_INFO1 allocationinfo1 = {};
        size = device->GetResourceAllocationInfo2(0, 1, desc, &allocationinfo1).SizeInBytes;
    }

    return size;
}
#endif // WIN32

bool IsDepthStencilFormat(const DXGI_FORMAT format)
{
    switch (format)
    {
        // Depth Formats:
        case DXGI_FORMAT_D32_FLOAT:
        case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
        case DXGI_FORMAT_D24_UNORM_S8_UINT:
        case DXGI_FORMAT_D16_UNORM:
            return true;

        // Assumed colour formats listed explicitly so a new format added to the enum would trigger a compiler warning
        // to update this:
        case DXGI_FORMAT_R32G32B32A32_TYPELESS:
        case DXGI_FORMAT_R32G32B32A32_FLOAT:
        case DXGI_FORMAT_R32G32B32A32_UINT:
        case DXGI_FORMAT_R32G32B32A32_SINT:
        case DXGI_FORMAT_R32G32B32_TYPELESS:
        case DXGI_FORMAT_R32G32B32_FLOAT:
        case DXGI_FORMAT_R32G32B32_UINT:
        case DXGI_FORMAT_R32G32B32_SINT:
        case DXGI_FORMAT_R16G16B16A16_TYPELESS:
        case DXGI_FORMAT_R16G16B16A16_FLOAT:
        case DXGI_FORMAT_R16G16B16A16_UNORM:
        case DXGI_FORMAT_R16G16B16A16_UINT:
        case DXGI_FORMAT_R16G16B16A16_SNORM:
        case DXGI_FORMAT_R16G16B16A16_SINT:
        case DXGI_FORMAT_R32G32_TYPELESS:
        case DXGI_FORMAT_R32G32_FLOAT:
        case DXGI_FORMAT_R32G32_UINT:
        case DXGI_FORMAT_R32G32_SINT:
        case DXGI_FORMAT_R32G8X24_TYPELESS:
        case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
        case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
        case DXGI_FORMAT_R10G10B10A2_TYPELESS:
        case DXGI_FORMAT_R10G10B10A2_UNORM:
        case DXGI_FORMAT_R10G10B10A2_UINT:
        case DXGI_FORMAT_R11G11B10_FLOAT:
        case DXGI_FORMAT_R8G8B8A8_TYPELESS:
        case DXGI_FORMAT_R8G8B8A8_UNORM:
        case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
        case DXGI_FORMAT_R8G8B8A8_UINT:
        case DXGI_FORMAT_R8G8B8A8_SNORM:
        case DXGI_FORMAT_R8G8B8A8_SINT:
        case DXGI_FORMAT_R16G16_TYPELESS:
        case DXGI_FORMAT_R16G16_FLOAT:
        case DXGI_FORMAT_R16G16_UNORM:
        case DXGI_FORMAT_R16G16_UINT:
        case DXGI_FORMAT_R16G16_SNORM:
        case DXGI_FORMAT_R16G16_SINT:
        case DXGI_FORMAT_R32_TYPELESS:
        case DXGI_FORMAT_R32_FLOAT:
        case DXGI_FORMAT_R32_UINT:
        case DXGI_FORMAT_R32_SINT:
        case DXGI_FORMAT_R24G8_TYPELESS:
        case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
        case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
        case DXGI_FORMAT_R8G8_TYPELESS:
        case DXGI_FORMAT_R8G8_UNORM:
        case DXGI_FORMAT_R8G8_UINT:
        case DXGI_FORMAT_R8G8_SNORM:
        case DXGI_FORMAT_R8G8_SINT:
        case DXGI_FORMAT_R16_TYPELESS:
        case DXGI_FORMAT_R16_FLOAT:
        case DXGI_FORMAT_R16_UNORM:
        case DXGI_FORMAT_R16_UINT:
        case DXGI_FORMAT_R16_SNORM:
        case DXGI_FORMAT_R16_SINT:
        case DXGI_FORMAT_R8_TYPELESS:
        case DXGI_FORMAT_R8_UNORM:
        case DXGI_FORMAT_R8_UINT:
        case DXGI_FORMAT_R8_SNORM:
        case DXGI_FORMAT_R8_SINT:
        case DXGI_FORMAT_A8_UNORM:
        case DXGI_FORMAT_R1_UNORM:
        case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
        case DXGI_FORMAT_R8G8_B8G8_UNORM:
        case DXGI_FORMAT_G8R8_G8B8_UNORM:
        case DXGI_FORMAT_BC1_TYPELESS:
        case DXGI_FORMAT_BC1_UNORM:
        case DXGI_FORMAT_BC1_UNORM_SRGB:
        case DXGI_FORMAT_BC2_TYPELESS:
        case DXGI_FORMAT_BC2_UNORM:
        case DXGI_FORMAT_BC2_UNORM_SRGB:
        case DXGI_FORMAT_BC3_TYPELESS:
        case DXGI_FORMAT_BC3_UNORM:
        case DXGI_FORMAT_BC3_UNORM_SRGB:
        case DXGI_FORMAT_BC4_TYPELESS:
        case DXGI_FORMAT_BC4_UNORM:
        case DXGI_FORMAT_BC4_SNORM:
        case DXGI_FORMAT_BC5_TYPELESS:
        case DXGI_FORMAT_BC5_UNORM:
        case DXGI_FORMAT_BC5_SNORM:
        case DXGI_FORMAT_B5G6R5_UNORM:
        case DXGI_FORMAT_B5G5R5A1_UNORM:
        case DXGI_FORMAT_B8G8R8A8_UNORM:
        case DXGI_FORMAT_B8G8R8X8_UNORM:
        case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
        case DXGI_FORMAT_B8G8R8A8_TYPELESS:
        case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
        case DXGI_FORMAT_B8G8R8X8_TYPELESS:
        case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
        case DXGI_FORMAT_BC6H_TYPELESS:
        case DXGI_FORMAT_BC6H_UF16:
        case DXGI_FORMAT_BC6H_SF16:
        case DXGI_FORMAT_BC7_TYPELESS:
        case DXGI_FORMAT_BC7_UNORM:
        case DXGI_FORMAT_BC7_UNORM_SRGB:
        case DXGI_FORMAT_AYUV:
        case DXGI_FORMAT_Y410:
        case DXGI_FORMAT_Y416:
        case DXGI_FORMAT_NV12:
        case DXGI_FORMAT_P010:
        case DXGI_FORMAT_P016:
        case DXGI_FORMAT_420_OPAQUE:
        case DXGI_FORMAT_YUY2:
        case DXGI_FORMAT_Y210:
        case DXGI_FORMAT_Y216:
        case DXGI_FORMAT_NV11:
        case DXGI_FORMAT_AI44:
        case DXGI_FORMAT_IA44:
        case DXGI_FORMAT_P8:
        case DXGI_FORMAT_A8P8:
        case DXGI_FORMAT_B4G4R4A4_UNORM:
        case DXGI_FORMAT_P208:
        case DXGI_FORMAT_V208:
        case DXGI_FORMAT_V408:
        case DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE:
        case DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE:
            return false;
    }
    // Log the error if a new format shows up but on balance of probabilities assume it isn't depth:
    GFXRECON_LOG_ERROR("Unknown DXGI_FORMAT value: %u.", static_cast<unsigned>(format));
    return false;
}

bool IsTextureWithUnknownLayout(D3D12_RESOURCE_DIMENSION dimension, D3D12_TEXTURE_LAYOUT layout)
{
    bool is_texture_with_unknown_layout = false;

    if (layout == D3D12_TEXTURE_LAYOUT_UNKNOWN)
    {
        if ((dimension == D3D12_RESOURCE_DIMENSION_TEXTURE1D) || (dimension == D3D12_RESOURCE_DIMENSION_TEXTURE2D) ||
            (dimension == D3D12_RESOURCE_DIMENSION_TEXTURE3D))
        {
            is_texture_with_unknown_layout = true;
        }
    }

    return is_texture_with_unknown_layout;
}

#ifdef WIN32
void RobustGetCopyableFootprint(ID3D12Device*                       device,
                                ID3D12Resource*                     resource,
                                const D3D12_RESOURCE_DESC*          pResourceDesc,
                                UINT                                FirstSubresource,
                                UINT                                NumSubresources,
                                UINT64                              BaseOffset,
                                D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
                                UINT*                               pNumRows,
                                UINT64*                             pRowSizeInBytes,
                                UINT64*                             pTotalBytes)
{
    UINT64 total_bytes = 0;

    device->GetCopyableFootprints(pResourceDesc,
                                  FirstSubresource,
                                  NumSubresources,
                                  BaseOffset,
                                  pLayouts,
                                  pNumRows,
                                  pRowSizeInBytes,
                                  &total_bytes);

    if ((total_bytes == UINT64_MAX) && ((pResourceDesc->Flags & D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS) ==
                                        D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS))
    {
        // Not all resource formats are compatible with the D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS flag, so remove
        // it before querying the copyable footprint. This handles the case where a resource is created with castable
        // formats but the format in the resource desc is not compatible with
        // D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS.
        D3D12_RESOURCE_DESC modified_desc = *pResourceDesc;
        modified_desc.Flags               = (modified_desc.Flags & ~D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);

        device->GetCopyableFootprints(&modified_desc,
                                      FirstSubresource,
                                      NumSubresources,
                                      BaseOffset,
                                      pLayouts,
                                      pNumRows,
                                      pRowSizeInBytes,
                                      &total_bytes);
    }

    if (total_bytes == UINT64_MAX)
    {
        GFXRECON_LOG_ERROR("Call to GetCopyableFootprints failed. GFXReconstruct may fail.");
    }

    if (pTotalBytes != nullptr)
    {
        *pTotalBytes = total_bytes;
    }
}
#endif

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)
