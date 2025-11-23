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
#include "util/gpu_va_range.h"
#include "util/logging.h"
#include "util/gpu_va_map.h"

#include <d3d12.h>

#include <catch2/catch.hpp>
#include <Windows.h>
#include <comdef.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(test)

constexpr D3D12_GPU_VIRTUAL_ADDRESS kGpuVaPageSize = 0x1000;

using Dx12ResourcePtr = _com_ptr_t<_com_IIID<ID3D12Resource, &__uuidof(ID3D12Resource)>>;

void TestDx12BufferInMap(GpuVaMap& gpu_va_map, const Dx12ResourcePtr& dx12_buffer)
{
    const D3D12_RESOURCE_DESC buffer_desc = dx12_buffer->GetDesc();
    REQUIRE(D3D12_RESOURCE_DIMENSION_BUFFER == buffer_desc.Dimension);
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_start = dx12_buffer->GetGPUVirtualAddress();
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_end   = dx12_buffer->GetGPUVirtualAddress() + buffer_desc.Width;
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_inc   = (buffer_desc.Width / 8);
    for (D3D12_GPU_VIRTUAL_ADDRESS gpu_va = gpu_va_start; gpu_va_end > gpu_va; gpu_va += gpu_va_inc)
    {
        const int resource_count = gpu_va_map.GetResourcesCount(gpu_va);
        REQUIRE(1 <= resource_count);
        std::vector<ID3D12Resource*> resource_list{ static_cast<size_t>(resource_count) };
        for (int i = 0; resource_count > i; ++i)
        {
            ID3D12Resource* dx12_resource{ nullptr };
            REQUIRE(true == gpu_va_map.GetResource(gpu_va, i, &dx12_resource));
            resource_list.push_back(dx12_resource);
        }
        REQUIRE(resource_list.end() !=
                std::find(resource_list.begin(), resource_list.end(), dx12_buffer.GetInterfacePtr()));
    }
}

void TestDx12BufferNotInMap(GpuVaMap& gpu_va_map, const Dx12ResourcePtr& dx12_buffer)
{
    const D3D12_RESOURCE_DESC buffer_desc = dx12_buffer->GetDesc();
    REQUIRE(D3D12_RESOURCE_DIMENSION_BUFFER == buffer_desc.Dimension);
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_start = dx12_buffer->GetGPUVirtualAddress();
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_end   = dx12_buffer->GetGPUVirtualAddress() + buffer_desc.Width;
    const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_inc   = (buffer_desc.Width / 8);
    for (D3D12_GPU_VIRTUAL_ADDRESS gpu_va = gpu_va_start; gpu_va_end > gpu_va; gpu_va += gpu_va_inc)
    {
        ID3D12Resource* dx12_resource{};
        REQUIRE(false == gpu_va_map.GetResource(gpu_va, 0, &dx12_resource));
    }
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get tests", "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize  = 32;
    static constexpr int         kBufferSize      = 1024;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        REQUIRE(true == gpu_va_map.Add(dx12_buffer));
    }
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        TestDx12BufferInMap(gpu_va_map, dx12_buffer);
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add(ID3D12Resource*, D3D12_GPU_VIRTUAL_ADDRESS, "
          "D3D12_RESOURCE_DESC*) override and GpuVaMap::Get tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize  = 32;
    static constexpr int         kBufferSize      = 1024;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        D3D12_RESOURCE_DESC resource_desc = dx12_buffer->GetDesc();
        REQUIRE(true ==
                gpu_va_map.Add((ID3D12Resource*)dx12_buffer, dx12_buffer->GetGPUVirtualAddress(), &resource_desc));
    }
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        TestDx12BufferInMap(gpu_va_map, dx12_buffer);
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get equal range overlapping buffer "
          "tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferBoundCount   = 16;
    static constexpr int         kBufferOverlapCount = 2;
    static constexpr int         kBufferSize         = 1536;
    std::vector<Dx12ResourcePtr> dx12_buffer_list =
        GenerateDx12OverlappingBufferList(kBufferBoundCount, kBufferOverlapCount, kBufferSize);
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer));
    }
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        TestDx12BufferInMap(gpu_va_map, dx12_buffer);
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get partial range overlapping "
          "sequential buffer tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kListsize        = 8;
    static constexpr int         kBufferSize      = D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT + 2048;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12OverlappingBufferList(kListsize, kBufferSize);
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer));
    }
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        const D3D12_RESOURCE_DESC       buffer_desc  = dx12_buffer->GetDesc();
        const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_start = dx12_buffer->GetGPUVirtualAddress();
        const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_end   = dx12_buffer->GetGPUVirtualAddress() + buffer_desc.Width;
        const D3D12_GPU_VIRTUAL_ADDRESS gpu_va_inc   = (buffer_desc.Width / 8);
        std::vector<ID3D12Resource*>    resource_list{};
        for (D3D12_GPU_VIRTUAL_ADDRESS gpu_va = gpu_va_start; gpu_va_end > gpu_va; gpu_va += gpu_va_inc)
        {
            TestDx12BufferInMap(gpu_va_map, dx12_buffer);
        }
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get partial range overlapping "
          "non sequential buffer tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kListsize        = 16;
    static constexpr int         kBufferSize      = D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT + 2048;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12OverlappingBufferList(kListsize, kBufferSize);
    static constexpr std::array<int, kListsize> kShuffledListIndices = { 8,  7,  10, 1,  6, 11, 5, 2,
                                                                         15, 12, 14, 13, 3, 0,  4, 9 };
    for (int i : kShuffledListIndices)
    {
        Dx12ResourcePtr dx12_buffer = dx12_buffer_list[i];
        REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer));
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get negative tests", "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize  = 2;
    static constexpr int         kBufferSize      = 1024;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer_list[0]));
    REQUIRE(false == gpu_va_map.Add((ID3D12Resource*)dx12_buffer_list[0]));
    ID3D12Resource* dx12_resource{ nullptr };
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[0]->GetGPUVirtualAddress() - 4));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[0]->GetGPUVirtualAddress() - 4,
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[0]->GetGPUVirtualAddress() +
                                              dx12_buffer_list[0]->GetDesc().Width + kGpuVaPageSize));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[0]->GetGPUVirtualAddress() +
                                                dx12_buffer_list[0]->GetDesc().Width + kGpuVaPageSize,
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[1]->GetGPUVirtualAddress()));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[1]->GetGPUVirtualAddress(),
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(false == gpu_va_map.GetResource(0, /* resource_index */ 0, &dx12_resource));
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add(ID3D12Resource*, D3D12_GPU_VIRTUAL_ADDRESS, "
          "D3D12_RESOURCE_DESC*) override and GpuVaMap::Get negative tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize  = 2;
    static constexpr int         kBufferSize      = 1024;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    D3D12_RESOURCE_DESC          resource_desc    = dx12_buffer_list[0]->GetDesc();
    REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer_list[0],
                                   dx12_buffer_list[0]->GetGPUVirtualAddress(),
                                   &resource_desc));
    REQUIRE(false == gpu_va_map.Add((ID3D12Resource*)dx12_buffer_list[0],
                                    dx12_buffer_list[0]->GetGPUVirtualAddress(),
                                    &resource_desc));
    ID3D12Resource* dx12_resource{ nullptr };
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[0]->GetGPUVirtualAddress() - 4));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[0]->GetGPUVirtualAddress() - 4,
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[0]->GetGPUVirtualAddress() +
                                              dx12_buffer_list[0]->GetDesc().Width + kGpuVaPageSize));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[0]->GetGPUVirtualAddress() +
                                                dx12_buffer_list[0]->GetDesc().Width + kGpuVaPageSize,
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(0 == gpu_va_map.GetResourcesCount(dx12_buffer_list[1]->GetGPUVirtualAddress()));
    REQUIRE(false == gpu_va_map.GetResource(dx12_buffer_list[1]->GetGPUVirtualAddress(),
                                            /* resource_index */ 0,
                                            &dx12_resource));
    REQUIRE(false == gpu_va_map.GetResource(0, /* resource_index */ 0, &dx12_resource));
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Remove tests", "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize  = 32;
    static constexpr int         kBufferSize      = 1024;
    std::vector<Dx12ResourcePtr> dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer));
    }
    for (const auto& dx12_buffer : dx12_buffer_list)
    {
        TestDx12BufferInMap(gpu_va_map, dx12_buffer);
    }
    SECTION("Remove every other buffer")
    {
        bool remove_buffer = false;
        for (const auto& dx12_buffer : dx12_buffer_list)
        {
            TestDx12BufferInMap(gpu_va_map, dx12_buffer);
            if (remove_buffer)
            {
                REQUIRE(true == gpu_va_map.Remove(dx12_buffer.GetInterfacePtr()));
                TestDx12BufferNotInMap(gpu_va_map, dx12_buffer);
            }
            remove_buffer = !remove_buffer;
        }
    }
    SECTION("Multiple add/remove buffer")
    {
        Dx12ResourcePtr      dx12_buffer         = dx12_buffer_list[kBufferListSize / 2];
        static constexpr int kRemoveAddTestCount = 3;
        for (int i = 0; kRemoveAddTestCount > i; ++i)
        {
            TestDx12BufferInMap(gpu_va_map, dx12_buffer);
            REQUIRE(true == gpu_va_map.Remove(dx12_buffer.GetInterfacePtr()));
            TestDx12BufferNotInMap(gpu_va_map, dx12_buffer);
            REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer));
        }
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::Add and GpuVaMap::Get capture to replay GPU VA mapping "
          "tests",
          "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                     gpu_va_map;
    static constexpr int         kBufferListSize          = 1;
    static constexpr int         kBufferSize              = 1024;
    std::vector<Dx12ResourcePtr> dx12_capture_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    std::vector<Dx12ResourcePtr> dx12_replay_buffer_list  = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    for (int i = 0; kBufferListSize > i; ++i)
    {
        D3D12_RESOURCE_DESC buffer_desc = dx12_capture_buffer_list[i]->GetDesc();
        REQUIRE(true == gpu_va_map.Add(dx12_capture_buffer_list[i].GetInterfacePtr(),
                                       dx12_capture_buffer_list[i]->GetGPUVirtualAddress(),
                                       dx12_replay_buffer_list[i]->GetGPUVirtualAddress(),
                                       &buffer_desc));
    }
    for (int i = 0; kBufferListSize > i; ++i)
    {
        TestDx12BufferInMap(gpu_va_map, dx12_capture_buffer_list[i]);
        const D3D12_GPU_VIRTUAL_ADDRESS capture_gpu_va         = dx12_capture_buffer_list[i]->GetGPUVirtualAddress();
        const D3D12_GPU_VIRTUAL_ADDRESS expected_replay_gpu_va = dx12_replay_buffer_list[i]->GetGPUVirtualAddress();
        for (D3D12_GPU_VIRTUAL_ADDRESS offset = 0; kBufferSize > offset; offset += (kBufferSize / 8))
        {
            ID3D12Resource* dx12_resource{ nullptr };
            REQUIRE(true == gpu_va_map.GetResource(capture_gpu_va + offset,
                                                   /* resource_index */ 0,
                                                   &dx12_resource));
            D3D12_GPU_VIRTUAL_ADDRESS replay_gpu_va = gpu_va_map.GetReplayGpuVa(capture_gpu_va + offset);
            REQUIRE(expected_replay_gpu_va + offset == replay_gpu_va);
        }
    }
    gfxrecon::util::Log::Release();
}

TEST_CASE("GpuVaMap::GetReplayGpuVa 4K page tests", "[gpu_va_map][pre_submit]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);
    GpuVaMap                                   gpu_va_map;
    static constexpr int                       kBufferListSize  = 4;
    static constexpr int                       kBufferSize      = 1024;
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kBufferOffset    = 0x100;
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kCaptureGPUVa    = 0x0000000012340000;
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kPageSize        = 0x1000;
    std::vector<Dx12ResourcePtr>               dx12_buffer_list = GenerateDx12BufferList(kBufferListSize, kBufferSize);
    for (size_t index = 0; index < dx12_buffer_list.size(); ++index)
    {
        D3D12_RESOURCE_DESC       buffer_desc   = dx12_buffer_list[index].GetInterfacePtr()->GetDesc();
        D3D12_GPU_VIRTUAL_ADDRESS replay_gpu_va = dx12_buffer_list[index].GetInterfacePtr()->GetGPUVirtualAddress();
        REQUIRE(true == gpu_va_map.Add((ID3D12Resource*)dx12_buffer_list[index],
                                       kCaptureGPUVa + index * kPageSize,
                                       replay_gpu_va,
                                       &buffer_desc));
    }
    for (size_t index = 0; index < dx12_buffer_list.size(); ++index)
    {
        D3D12_GPU_VIRTUAL_ADDRESS replay_gpu_va = dx12_buffer_list[index].GetInterfacePtr()->GetGPUVirtualAddress();
        REQUIRE(replay_gpu_va + kBufferOffset ==
                gpu_va_map.GetReplayGpuVa(kCaptureGPUVa + index * kPageSize + kBufferOffset));
    }
    gfxrecon::util::Log::Release();
}
GFXRECON_END_NAMESPACE(test)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
