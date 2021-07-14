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

#include "gpu_va_map.h"
#include "util/defines.h"

#include <d3d12.h>
#include "logging.h"

#include <array>
#include <Windows.h>

#include <memory>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

bool GpuVaMap::Add(ID3D12Resource* resource)
{
    D3D12_RESOURCE_DESC resource_desc = const_cast<ID3D12Resource*>(resource)->GetDesc();
    if (D3D12_RESOURCE_DIMENSION_BUFFER != resource_desc.Dimension)
    {
        GFXRECON_LOG_INFO("invalid argument passed to a function");
        return false;
    }
    D3D12_GPU_VIRTUAL_ADDRESS gpu_va = resource->GetGPUVirtualAddress();
    return Add(resource,
               /* capture_gpu_va */ gpu_va,
               /* replay_gpu_va */ gpu_va,
               &resource_desc);
}

bool GpuVaMap::Add(ID3D12Resource* resource, D3D12_GPU_VIRTUAL_ADDRESS gpu_va, D3D12_RESOURCE_DESC* desc)
{
    return Add(resource,
               /* capture_gpu_va */ gpu_va,
               /* replay_gpu_va */ gpu_va,
               desc);
}

bool GpuVaMap::Add(ID3D12Resource*           resource,
                   D3D12_GPU_VIRTUAL_ADDRESS capture_gpu_va,
                   D3D12_GPU_VIRTUAL_ADDRESS replay_gpu_va,
                   D3D12_RESOURCE_DESC*      desc)
{
    if (D3D12_RESOURCE_DIMENSION_BUFFER != desc->Dimension)
    {
        GFXRECON_LOG_INFO("invalid argument passed to a function");
        return false;
    }
    const D3D12_GPU_VIRTUAL_ADDRESS capture_range_start{ capture_gpu_va & kZeroPageBitsMask };
    const GpuVaRange                capture_range{
        /* start */ capture_range_start,
        /* end */ (capture_range_start + desc->Width - 1) & kZeroPageBitsMask,
    };
    D3D12_GPU_VIRTUAL_ADDRESS replay_page = (replay_gpu_va & kZeroPageBitsMask);
    bool                      ret_status  = true;
    for (D3D12_GPU_VIRTUAL_ADDRESS page = capture_range.start; capture_range.end >= page;
         page += kPageSize, replay_page += kPageSize)
    {
        const std::array<int, kPageTableLevelCount> table_indices = GetPageTableIndices(page);
        GpuVaPage&                                  gpu_va_page   = GetPage(table_indices);
        auto buffer_iter = std::find(gpu_va_page.buffers.begin(), gpu_va_page.buffers.end(), resource);
        if (gpu_va_page.buffers.end() != buffer_iter)
        {
            ret_status = false;
            GFXRECON_LOG_WARNING("GpuVaMap: Duplicate object in an object map. Object not added.");
        }
        else
        {
            gpu_va_page.buffers.push_back(resource);
        }
        gpu_va_page.gpu_va = replay_page;
    }
    return ret_status;
}

bool GpuVaMap::Remove(ID3D12Resource* resource)
{
    if (page_table.pages.empty())
    {
        GFXRECON_LOG_WARNING("GpuVaMap: Object or resource not found in map or list. Object not removed.");
        return false;
    }
    GpuVaRange buffer_range{};
    bool       ret_status = GetResourceGpuVaRange(resource, &buffer_range);
    if (true != ret_status)
    {
        return ret_status;
    }
    return Remove(resource, buffer_range);
}

bool GpuVaMap::Remove(const ID3D12Resource* resource, GpuVaRange& buffer_range)
{
    bool ret_status    = true;
    buffer_range.start = (buffer_range.start & kZeroPageBitsMask);
    buffer_range.end   = (buffer_range.end & kZeroPageBitsMask);
    for (D3D12_GPU_VIRTUAL_ADDRESS page = buffer_range.start; buffer_range.end >= page; page += kPageSize)
    {
        const std::array<int, kPageTableLevelCount> table_indices = GetPageTableIndices(page);
        if (IsPageAllocated(table_indices))
        {
            GpuVaPage& gpu_va_page = GetPage(table_indices);
            auto       buffer_iter = std::find(gpu_va_page.buffers.begin(), gpu_va_page.buffers.end(), resource);
            if (gpu_va_page.buffers.end() != buffer_iter)
            {
                gpu_va_page.buffers.erase(buffer_iter);
            }
            else
            {
                GFXRECON_LOG_WARNING("GpuVaMap: Object or resource not found in map or list. Object not removed.");
                ret_status = false;
            }
        }
    }

    return ret_status;
}

int GpuVaMap::GetResourcesCount(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) ///< )
    const
{
    const std::array<int, kPageTableLevelCount> table_indices = GetPageTableIndices(gpu_va);
    if (!IsPageAllocated(table_indices))
    {
        return 0;
    }
    return static_cast<int>(GetPage(table_indices).buffers.size());
}

bool GpuVaMap::GetResource(D3D12_GPU_VIRTUAL_ADDRESS gpu_va, int resource_index, ID3D12Resource** resource) const
{
    if ((0 > resource_index) || (nullptr == resource))
    {
        GFXRECON_LOG_INFO("invalid argument passed to a function");
        return false;
    }
    const std::array<int, kPageTableLevelCount> table_indices = GetPageTableIndices(gpu_va);
    const GpuVaPage&                            gpu_va_page   = GetPage(table_indices);
    if (!IsPageAllocated(table_indices))
    {

        GFXRECON_LOG_INFO("Object or resource not found in map or list");
        return false;
    }
    if (gpu_va_page.buffers.size() <= static_cast<size_t>(resource_index))
    {
        GFXRECON_LOG_INFO("invalid argument passed to a function");
        return false;
    }
    (*resource) = gpu_va_page.buffers[resource_index];
    return true;
}

D3D12_GPU_VIRTUAL_ADDRESS GpuVaMap::GetReplayGpuVa(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) const
{
    if (0 == gpu_va)
    {
        return 0;
    }
    const std::array<int, kPageTableLevelCount> table_indices = GetPageTableIndices(gpu_va);
    if (!IsPageAllocated(table_indices))
    {
        return 0;
    }
    const GpuVaPage& gpu_va_page = GetPage(table_indices);
    if (0 == gpu_va_page.gpu_va)
    {
        return 0;
    }
    return (gpu_va_page.gpu_va + (gpu_va & kPageBitsMask));
}

const std::array<int, GpuVaMap::kPageTableLevelCount>
GpuVaMap::GetPageTableIndices(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) noexcept
{
    std::array<int, kPageTableLevelCount> indices{};
    D3D12_GPU_VIRTUAL_ADDRESS             va = gpu_va;
    for (int i = (kPageTableLevelCount - 1); 0 < i; --i)
    {
        va         = va >> kPageTableBitSize;
        indices[i] = (va & kPageTableBitMask);
    }
    indices[0] = (va & kTopPageTableBitMask);
    return indices;
}

bool GpuVaMap::IsPageAllocated(const std::array<int, kPageTableLevelCount>& table_indices) const noexcept
{
    if (page_table.pages[table_indices[0]].pages.empty())
    {
        return false;
    }
    if (page_table.pages[table_indices[0]].pages[table_indices[1]].pages.empty())
    {
        return false;
    }
    if (page_table.pages[table_indices[0]].pages[table_indices[1]].pages[table_indices[2]].pages.empty())
    {
        return false;
    }
    return true;
}

const GpuVaMap::GpuVaPage& GpuVaMap::GetPage(const std::array<int, kPageTableLevelCount>& table_indices) const
{
    if (page_table.pages.empty())
    {
        (const_cast<GpuVaMap*>(this))->page_table.pages.resize(1 << kTopPageTableBitSize);
    }
    if (page_table.pages[table_indices[0]].pages.empty())
    {
        (const_cast<GpuVaMap*>(this))->page_table.pages[table_indices[0]].pages.resize(1 << kPageTableBitSize);
    }
    if (page_table.pages[table_indices[0]].pages[table_indices[1]].pages.empty())
    {
        (const_cast<GpuVaMap*>(this))
            ->page_table.pages[table_indices[0]]
            .pages[table_indices[1]]
            .pages.resize(1 << kPageTableBitSize);
    }
    if (page_table.pages[table_indices[0]].pages[table_indices[1]].pages[table_indices[2]].pages.empty())
    {
        (const_cast<GpuVaMap*>(this))
            ->page_table.pages[table_indices[0]]
            .pages[table_indices[1]]
            .pages[table_indices[2]]
            .pages.resize(1 << kPageTableBitSize);
    }
    return page_table.pages[table_indices[0]].pages[table_indices[1]].pages[table_indices[2]].pages[table_indices[3]];
}

GpuVaMap::GpuVaPage& GpuVaMap::GetPage(const std::array<int, kPageTableLevelCount>& table_indices)
{
    return const_cast<GpuVaPage&>((const_cast<const GpuVaMap*>(this))->GetPage(table_indices));
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)