/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_DX12_OBJECT_INFO_H
#define GFXRECON_DECODE_DX12_OBJECT_INFO_H

#include "decode/window.h"
#include "format/format.h"
#include "util/defines.h"
#include "decode/dx12_descriptor_map.h"

#include <d3d12.h>

#include <comdef.h>
#include <memory>
#include <Unknwn.h>
#include <map>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

typedef _com_ptr_t<_com_IIID<ID3D12Fence, &__uuidof(ID3D12Fence)>> ID3D12FencePtr;

typedef std::map<UINT64, HANDLE>                               FenceEvents;
typedef std::set<UINT64>                                       PendingFenceValues;

enum class DxObjectInfoType : uint32_t
{
    kUnused = 0,
    kIDxgiSwapchainInfo,
    kID3D12CommandQueueInfo,
    kID3D12DeviceInfo,
    kID3D12DescriptorHeapInfo,
    kID3D12FenceInfo,
    kID3D12HeapInfo,
    kID3D12ResourceInfo
};

//
// Structures for storing DirectX object info.
//

struct MappedMemoryInfo
{
    uint32_t count{ 0 };     ///< Number of times that the memory has been mapped.
    uint64_t memory_id{ 0 }; ///< Capture ID for the mapped memory.
};

struct DxObjectInfo
{
    // Standard info stored for all DX objects.
    IUnknown*        object{ nullptr };
    format::HandleId capture_id{ format::kNullHandleId };
    uint64_t         ref_count{ 1 };
    DxObjectInfoType extra_info_type{ DxObjectInfoType::kUnused };
    void*            extra_info{ nullptr };
};

struct DxgiSwapchainInfo
{
    Window*  window{ nullptr }; ///< Pointer to the platform-specific window object associated with the swapchain.
    uint64_t hwnd_id{ 0 };      ///< Capture ID for the HWND handle used with swapchain creation.
};

struct D3D12CommandQueueInfo
{
    ID3D12FencePtr sync_fence;
    uint64_t       sync_value{ 0 };
};

struct D3D12DeviceInfo
{
    std::shared_ptr<DescriptorIncrements> capture_increments{ std::make_shared<DescriptorIncrements>() };
    std::shared_ptr<DescriptorIncrements> replay_increments{ std::make_shared<DescriptorIncrements>() };
};

struct D3D12DescriptorHeapInfo
{
    std::shared_ptr<DescriptorIncrements> capture_increments;
    std::shared_ptr<DescriptorIncrements> replay_increments;

    D3D12_DESCRIPTOR_HEAP_TYPE descriptor_type{};
    uint32_t                   descriptor_count{ 0 };

    size_t   capture_cpu_addr_begin{ Dx12DescriptorMap::kNullCpuAddress };
    uint64_t capture_gpu_addr_begin{ Dx12DescriptorMap::kNullGpuAddress };
};

struct D3D12FenceInfo
{
    HANDLE             completion_event{ nullptr };
    FenceEvents        event_objects;
    PendingFenceValues signaled_values;
};

struct D3D12HeapInfo
{
    void* external_allocation{ nullptr };
};

struct D3D12ResourceInfo
{
    std::unordered_map<uint32_t, MappedMemoryInfo> mapped_memory_info; ///< Map subresource index to mapped memory info.
    uint64_t                                       capture_address_{ 0 }; ///< Capture GPU VA.
    uint64_t                                       replay_address_{ 0 };  ///< Replay GPU VA.
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_INFO_H
