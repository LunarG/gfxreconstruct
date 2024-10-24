/*
** Copyright (c) 2018-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "dx12_utils.h"
#include "util/gpu_va_map.h"
#include "dx12_pointers.h"
#include "dxgi_pointers.h"

#include <Windows.h>
#include <catch2/catch.hpp>
#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(test)

namespace
{
DxgiAdapterPtr CreateDxgiAdapter()
{
    UINT dxgi_factory_flags = 0;
#ifdef _DEBUG
    {
        Dx12Debug dx12_debug;

        HRESULT result = D3D12GetDebugInterface(__uuidof(ID3D12Debug), reinterpret_cast<void**>(&dx12_debug));
        REQUIRE(S_OK == result);
        dx12_debug->EnableDebugLayer();
        dxgi_factory_flags |= DXGI_CREATE_FACTORY_DEBUG;
    }
#endif // _DEBUG
    DxgiFactoryPtr dxgi_factory{};
    HRESULT        result = ::CreateDXGIFactory2(
        dxgi_factory_flags, __uuidof(DxgiFactoryPtr::Interface), reinterpret_cast<void**>(&dxgi_factory));
    REQUIRE(S_OK == result);
    DxgiAdapterPtr dxgi_adapter{};

    result =
        dxgi_factory->EnumWarpAdapter(__uuidof(DxgiAdapterPtr::Interface), reinterpret_cast<void**>(&dxgi_adapter));
    REQUIRE(S_OK == result);
    return dxgi_adapter;
}

int GetDx12BufferAlignedOffset(int offset)
{
    return ((offset / D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT) + 1) * D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
}

Dx12HeapPtr CreateDx12Heap(Dx12DevicePtr& dx12_device, int heap_size)
{
    REQUIRE(0 < heap_size);
    const D3D12_HEAP_DESC heap_desc{
        static_cast<UINT64>(heap_size),
        /* Properties */
        {
            D3D12_HEAP_TYPE_DEFAULT,
            D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
            D3D12_MEMORY_POOL_UNKNOWN,
            /* CreationNodeMask */ 0,
            /* VisibleNodeMask */ 0,
        },
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        D3D12_HEAP_FLAG_NONE,
    };
    Dx12HeapPtr dx12_heap{};
    HRESULT     result =
        dx12_device->CreateHeap(&heap_desc, __uuidof(Dx12HeapPtr::Interface), reinterpret_cast<void**>(&dx12_heap));
    REQUIRE(S_OK == result);
    return dx12_heap;
}

Dx12ResourcePtr CreateDx12PlacedBuffer(Dx12DevicePtr& dx12_device, Dx12HeapPtr& dx12_heap, int offset, int size)
{
    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(size);
    Dx12ResourcePtr           dx12_buffer{};
    HRESULT                   result = dx12_device->CreatePlacedResource(dx12_heap,
                                                       offset,
                                                       &buffer_desc,
                                                       D3D12_RESOURCE_STATE_COMMON,
                                                       nullptr,
                                                       __uuidof(Dx12ResourcePtr::Interface),
                                                       reinterpret_cast<void**>(&dx12_buffer));
    REQUIRE(S_OK == result);
    return dx12_buffer;
}

} // namespace

Dx12DevicePtr CreateDx12Device() noexcept
{
    DxgiAdapterPtr dxgi_adapter = CreateDxgiAdapter();
    // The feature level list must be ordered from high to low priority
    static constexpr std::array<D3D_FEATURE_LEVEL, 4> kDxFeatureLevelList{
        D3D_FEATURE_LEVEL_12_1,
        D3D_FEATURE_LEVEL_12_0,
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
    };
    Dx12DevicePtr dx12_device{};

    for (auto dx_feature_level : kDxFeatureLevelList)
    {
        HRESULT result = S_OK;
        D3D12CreateDevice(
            dxgi_adapter, dx_feature_level, __uuidof(Dx12DevicePtr::Interface), reinterpret_cast<void**>(&dx12_device));
        if (S_OK == result)
        {
            D3D12_FEATURE_DATA_D3D12_OPTIONS5 dx12_features{};
            result = dx12_device->CheckFeatureSupport(
                D3D12_FEATURE_D3D12_OPTIONS5, &dx12_features, static_cast<UINT>(sizeof(dx12_features)));
            // TODO(XCAP-1671) add checks that ray tracing is supported if
            //      any DXR specific calls need to be made.
            if (S_OK == result)
            {
                return dx12_device;
            }
        }
    }
    FAIL("Failed to create DX12 device");
    return Dx12DevicePtr();
}

D3D12_RESOURCE_DESC GetDx12BufferDesc(int size) noexcept
{
    return D3D12_RESOURCE_DESC{
        D3D12_RESOURCE_DIMENSION_BUFFER,
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        /* Width */ static_cast<UINT64>(size),
        /* Height */ 1,
        /* DepthOrArraySize */ 1,
        /* MipLevels */ 1,
        /* Format */ DXGI_FORMAT_UNKNOWN,
        /* SampleDesc */ { 1, 0 },
        /* Layout */ D3D12_TEXTURE_LAYOUT_ROW_MAJOR,
        /* Flags */ D3D12_RESOURCE_FLAG_NONE,
    };
}

std::vector<Dx12ResourcePtr>
GenerateDx12BufferList(Dx12DevicePtr::Interface* dx12_device, int list_size, int buffer_size, bool mappable) noexcept
{
    std::vector<Dx12ResourcePtr> dx12_resource_list{};
    const D3D12_RESOURCE_DESC    resource_desc = GetDx12BufferDesc(buffer_size);
    const D3D12_HEAP_PROPERTIES  kHeapProperties{
        mappable ? D3D12_HEAP_TYPE_UPLOAD : D3D12_HEAP_TYPE_DEFAULT,
        D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
        D3D12_MEMORY_POOL_UNKNOWN,
        /* CreationNodeMask */ 0,
        /* VisibleNodeMask */ 0,
    };
    for (int i = 0; i < list_size; ++i)
    {
        Dx12ResourcePtr dx12_resource{};
        HRESULT         result = dx12_device->CreateCommittedResource(&kHeapProperties,
                                                              D3D12_HEAP_FLAG_NONE,
                                                              &resource_desc,
                                                              mappable ? D3D12_RESOURCE_STATE_GENERIC_READ
                                                                               : D3D12_RESOURCE_STATE_COMMON,
                                                              /* pOptimizedClearValue */ nullptr,
                                                              __uuidof(Dx12ResourcePtr::Interface),
                                                              reinterpret_cast<void**>(&dx12_resource));
        REQUIRE(S_OK == result);
        dx12_resource_list.push_back(dx12_resource);
    }
    return dx12_resource_list;
}

std::vector<Dx12ResourcePtr> GenerateDx12BufferList(int list_size, int buffer_size) noexcept
{
    Dx12DevicePtr dx12_device = CreateDx12Device();
    return GenerateDx12BufferList(dx12_device, list_size, buffer_size, false);
}

std::vector<Dx12ResourcePtr>
GenerateDx12OverlappingBufferList(int bound_count, int overlap_count, int buffer_size) noexcept
{
    const int buffer_alignment = GetDx12BufferAlignedOffset(buffer_size);
    const int list_size        = bound_count * overlap_count;
    const int heap_size        = list_size * buffer_alignment;
    REQUIRE(0 != heap_size);
    Dx12DevicePtr                dx12_device = CreateDx12Device();
    Dx12HeapPtr                  dx12_heap   = CreateDx12Heap(dx12_device, heap_size);
    std::vector<Dx12ResourcePtr> dx12_buffers{};
    dx12_buffers.reserve(list_size);
    for (int bi = 0; bi < bound_count; ++bi)
    {
        for (int oi = 0; oi < overlap_count; ++oi)
        {
            dx12_buffers.push_back(CreateDx12PlacedBuffer(dx12_device, dx12_heap, bi * buffer_alignment, buffer_size));
        }
    }
    return dx12_buffers;
}

std::vector<Dx12ResourcePtr> GenerateDx12OverlappingBufferList(int list_size, int buffer_size) noexcept
{
    REQUIRE(D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT < static_cast<UINT64>(buffer_size));
    const int heap_size = ((list_size - 1) * D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT) + buffer_size;
    REQUIRE(0 != heap_size);
    Dx12DevicePtr                dx12_device = CreateDx12Device();
    Dx12HeapPtr                  dx12_heap   = CreateDx12Heap(dx12_device, heap_size);
    std::vector<Dx12ResourcePtr> dx12_buffers{};
    dx12_buffers.reserve(list_size);
    for (int i = 0; i < list_size; ++i)
    {
        dx12_buffers.push_back(CreateDx12PlacedBuffer(
            dx12_device, dx12_heap, i * D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT, buffer_size));
    }
    return dx12_buffers;
}

GFXRECON_END_NAMESPACE(test)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
