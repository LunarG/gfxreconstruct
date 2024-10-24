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

#include "dx12_utils.h"
#include "util/logging.h"

#include <d3d12.h>

#include <catch2/catch.hpp>
#include <Windows.h>
#include <comdef.h>

bool VirtualQuerySuccess(UINT8* data_begin, MEMORY_BASIC_INFORMATION& memory_info)
{
    auto sizecheck = VirtualQuery(data_begin, &memory_info, sizeof(memory_info));
    if (sizecheck > 0)
    {
        return true;
    }
    return false;
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(test)

static constexpr int kBufferSize = 1024;
static constexpr int kListSize   = 16;

TEST_CASE("GetWriteWatch::CreatePlacedResource, no writing to memory", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);

    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };

    Dx12DevicePtr         dx12_device = CreateDx12Device();
    const D3D12_HEAP_DESC heap_desc{
        static_cast<UINT64>(kBufferSize),
        {
            D3D12_HEAP_TYPE_UPLOAD,
            D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
            D3D12_MEMORY_POOL_UNKNOWN,
            0,
            0,
        },
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        D3D12_HEAP_FLAG_NONE | D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
    };

    HRESULT result =
        dx12_device->CreateHeap(&heap_desc, __uuidof(Dx12HeapPtr::Interface), reinterpret_cast<void**>(&dx12_heap));

    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);
    Dx12ResourcePtr           dx12_buffer{};
    result = dx12_device->CreatePlacedResource(dx12_heap,
                                               0,
                                               &buffer_desc,
                                               D3D12_RESOURCE_STATE_GENERIC_READ,
                                               nullptr,
                                               __uuidof(Dx12ResourcePtr::Interface),
                                               reinterpret_cast<void**>(&dx12_buffer));
    REQUIRE(result == S_OK);

    REQUIRE(dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin)) == S_OK);
    if (VirtualQuerySuccess(data_begin, memory_info))
    {
        INFO(memory_info.AllocationProtect);
    }

    if (GetWriteWatch(
            WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) == 0)
    {
        REQUIRE(modified_count == 0);
    }
    else
    {
        WARN("GetWriteWatch() returns error");
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GetWriteWatch::CreatePlacedResource", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    Dx12DevicePtr            dx12_device    = CreateDx12Device();
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };
    const D3D12_HEAP_DESC    heap_desc{
        static_cast<UINT64>(kBufferSize),
        {
               D3D12_HEAP_TYPE_UPLOAD,
               D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
               D3D12_MEMORY_POOL_UNKNOWN,
               0,
               0,
        },
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        D3D12_HEAP_FLAG_NONE | D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
    };

    HRESULT result =
        dx12_device->CreateHeap(&heap_desc, __uuidof(Dx12HeapPtr::Interface), reinterpret_cast<void**>(&dx12_heap));

    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);
    Dx12ResourcePtr           dx12_buffer{};
    result = dx12_device->CreatePlacedResource(dx12_heap,
                                               0,
                                               &buffer_desc,
                                               D3D12_RESOURCE_STATE_GENERIC_READ,
                                               nullptr,
                                               __uuidof(Dx12ResourcePtr::Interface),
                                               reinterpret_cast<void**>(&dx12_buffer));
    REQUIRE(result == S_OK);

    REQUIRE(dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin)) == S_OK);

    if (VirtualQuerySuccess(data_begin, memory_info))
    {
        INFO(memory_info.AllocationProtect);
    }

    data_begin[0] = 0xAC;
    if (GetWriteWatch(
            WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) == 0)
    {
        REQUIRE(modified_count > 0);
    }
    else
    {
        WARN("GetWriteWatch() returns error");
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GetWriteWatch::CreatePlacedResource buffer list", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    static constexpr int buffer_alignment =
        ((kBufferSize / D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT) + 1) * D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT;
    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    const int                heap_size      = kListSize * buffer_alignment;
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };
    REQUIRE(0 != heap_size);
    Dx12DevicePtr dx12_device = CreateDx12Device();

    const D3D12_HEAP_DESC heap_desc{
        static_cast<UINT64>(heap_size),
        {
            D3D12_HEAP_TYPE_UPLOAD,
            D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
            D3D12_MEMORY_POOL_UNKNOWN,
            0,
            0,
        },
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        D3D12_HEAP_FLAG_NONE | D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
    };

    HRESULT result =
        dx12_device->CreateHeap(&heap_desc, __uuidof(Dx12HeapPtr::Interface), reinterpret_cast<void**>(&dx12_heap));
    REQUIRE(result == S_OK);
    Dx12ResourcePtr              dx12_buffer{};
    std::vector<Dx12ResourcePtr> dx12_buffers{};
    dx12_buffers.reserve(kListSize);
    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);
    for (int i = 0; i < kListSize; ++i)
    {
        result = dx12_device->CreatePlacedResource(dx12_heap,
                                                   static_cast<UINT64>(i) * buffer_alignment,
                                                   &buffer_desc,
                                                   D3D12_RESOURCE_STATE_GENERIC_READ,
                                                   nullptr,
                                                   __uuidof(Dx12ResourcePtr::Interface),
                                                   reinterpret_cast<void**>(&dx12_buffer));
        REQUIRE(result == S_OK);
        dx12_buffers.push_back(dx12_buffer);
    }

    result = dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin));
    REQUIRE(result == S_OK);

    if (VirtualQuerySuccess(data_begin, memory_info))
    {
        INFO(memory_info.AllocationProtect);
    }
    data_begin[kBufferSize / 2] = 0xAC;
    if (GetWriteWatch(
            WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) == 0)
    {
        REQUIRE(modified_count > 0);
    }
    else
    {
        WARN("GetWriteWatch() returns error");
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GetWriteWatch::CreatePlacedResource D3D12_HEAP_TYPE_DEFAULT flag", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };
    Dx12DevicePtr            dx12_device    = CreateDx12Device();

    const D3D12_HEAP_DESC heap_desc{
        static_cast<UINT64>(kBufferSize),
        {
            D3D12_HEAP_TYPE_DEFAULT,
            D3D12_CPU_PAGE_PROPERTY_UNKNOWN,
            D3D12_MEMORY_POOL_UNKNOWN,
            0,
            0,
        },
        D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT,
        D3D12_HEAP_FLAG_NONE | D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
    };

    HRESULT result =
        dx12_device->CreateHeap(&heap_desc, __uuidof(Dx12HeapPtr::Interface), reinterpret_cast<void**>(&dx12_heap));
    // Failed to create heap D3D12_HEAP_TYPE_DEFAULT together with D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH flag
    if (result == S_OK)
    {
        const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);
        Dx12ResourcePtr           dx12_buffer{};
        result = dx12_device->CreatePlacedResource(dx12_heap,
                                                   0,
                                                   &buffer_desc,
                                                   D3D12_RESOURCE_STATE_GENERIC_READ,
                                                   nullptr,
                                                   __uuidof(Dx12ResourcePtr::Interface),
                                                   reinterpret_cast<void**>(&dx12_buffer));
        REQUIRE(result == S_OK);

        UINT8*      data_begin;
        D3D12_RANGE read_range{ 0, 0 };
        result = dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin));
        REQUIRE(result == S_OK);

        if (VirtualQuerySuccess(data_begin, memory_info))
        {
            INFO(memory_info.AllocationProtect);
        }

        data_begin[0] = 0xAC;
        if (GetWriteWatch(
                WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) ==
            0)
        {
            REQUIRE(modified_count > 0);
        }
        else
        {
            WARN("GetWriteWatch() returns error");
        }
    }
    else
    {
        INFO("Cannot CreatePlacedResource D3D12_HEAP_TYPE_DEFAULT together with D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH ");
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GetWriteWatch::CreateCommittedResource", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };
    Dx12DevicePtr            dx12_device    = CreateDx12Device();

    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);

    D3D12_HEAP_PROPERTIES heap_props{
        D3D12_HEAP_TYPE_READBACK, D3D12_CPU_PAGE_PROPERTY_UNKNOWN, D3D12_MEMORY_POOL_UNKNOWN, 0, 0,
    };

    Dx12ResourcePtr dx12_buffer{};
    HRESULT         result = dx12_device->CreateCommittedResource(&heap_props,
                                                          D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
                                                          &buffer_desc,
                                                          D3D12_RESOURCE_STATE_COPY_DEST,
                                                          nullptr,
                                                          __uuidof(Dx12ResourcePtr::Interface),
                                                          reinterpret_cast<void**>(&dx12_buffer));
    REQUIRE(result == S_OK);

    result = dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin));
    REQUIRE(result == S_OK);

    if (VirtualQuerySuccess(data_begin, memory_info))
    {
        INFO(memory_info.AllocationProtect);
    }

    data_begin[kBufferSize / 2] = 0xAC;

    if (GetWriteWatch(
            WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) == 0)
    {
        REQUIRE(modified_count > 0);
    }
    else
    {
        WARN("GetWriteWatch() returns error");
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GetWriteWatch::CreateCommittedResource buffer list", "[memory_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    ULONG                    granularity;
    void*                    modified_addresses[kBufferSize];
    D3D12_RANGE              read_range{ 0, 0 };
    Dx12HeapPtr              dx12_heap;
    UINT8*                   data_begin     = nullptr;
    ULONG_PTR                modified_count = kBufferSize;
    MEMORY_BASIC_INFORMATION memory_info    = { 0 };
    Dx12DevicePtr            dx12_device    = CreateDx12Device();

    const D3D12_RESOURCE_DESC buffer_desc = GetDx12BufferDesc(kBufferSize);

    D3D12_HEAP_PROPERTIES heap_props{
        D3D12_HEAP_TYPE_READBACK, D3D12_CPU_PAGE_PROPERTY_UNKNOWN, D3D12_MEMORY_POOL_UNKNOWN, 0, 0,
    };

    Dx12ResourcePtr              dx12_buffer{};
    std::vector<Dx12ResourcePtr> dx12_resource_list{};
    for (int i = 0; i < kListSize; ++i)
    {
        HRESULT result = dx12_device->CreateCommittedResource(&heap_props,
                                                              D3D12_HEAP_FLAG_ALLOW_WRITE_WATCH,
                                                              &buffer_desc,
                                                              D3D12_RESOURCE_STATE_COPY_DEST,
                                                              nullptr,
                                                              __uuidof(Dx12ResourcePtr::Interface),
                                                              reinterpret_cast<void**>(&dx12_buffer));
        REQUIRE(S_OK == result);

        dx12_resource_list.push_back(dx12_buffer);
    }

    HRESULT result = dx12_buffer->Map(0, &read_range, reinterpret_cast<void**>(&data_begin));
    if (VirtualQuerySuccess(data_begin, memory_info))
    {
        INFO(memory_info.AllocationProtect);
    }

    REQUIRE(result == S_OK);

    data_begin[kBufferSize / 2] = 0xAC;

    if (GetWriteWatch(
            WRITE_WATCH_FLAG_RESET, data_begin, kBufferSize, modified_addresses, &modified_count, &granularity) == 0)
    {
        REQUIRE(modified_count > 0);
    }
    else
    {
        WARN("GetWriteWatch() returns error");
    }
    gfxrecon::util::Log::Release();
}

GFXRECON_END_NAMESPACE(test)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
