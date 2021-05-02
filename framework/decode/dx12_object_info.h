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

#include <d3d12.h>

#include <array>
#include <comdef.h>
#include <memory>
#include <Unknwn.h>
#include <map>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr size_t kNullCpuAddress = 0;
constexpr size_t kNullGpuAddress = 0;

typedef std::map<UINT64, HANDLE>                               FenceEvents;
typedef std::set<UINT64>                                       PendingFenceValues;
typedef std::array<UINT, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES> DescriptorIncrements;

typedef _com_ptr_t<_com_IIID<ID3D12Fence, &__uuidof(ID3D12Fence)>> ID3D12FencePtr;

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

struct DxObjectExtraInfo
{
    DxObjectExtraInfo(DxObjectInfoType type) : extra_info_type(type) {}
    virtual ~DxObjectExtraInfo() {}

    const DxObjectInfoType extra_info_type;
};

struct DxObjectInfo
{
    // Standard info stored for all DX objects.
    IUnknown*                          object{ nullptr };
    format::HandleId                   capture_id{ format::kNullHandleId };
    uint64_t                           ref_count{ 1 };
    uint64_t                           extra_ref{ 0 };
    std::unique_ptr<DxObjectExtraInfo> extra_info;
};

struct DxgiSwapchainInfo : DxObjectExtraInfo
{
    DxgiSwapchainInfo() : DxObjectExtraInfo(DxObjectInfoType::kIDxgiSwapchainInfo) {}

    Window*  window{ nullptr }; ///< Pointer to the platform-specific window object associated with the swapchain.
    uint64_t hwnd_id{ 0 };      ///< Capture ID for the HWND handle used with swapchain creation.
    uint32_t image_count{ 0 };  ///< The number of swapchain images.
    std::unique_ptr<DxObjectInfo*[]> images; ///< Pointers to swapchain image info entries to be kept in the info table
                                             ///< while the swapchain is active.
};

struct D3D12CommandQueueInfo : DxObjectExtraInfo
{
    D3D12CommandQueueInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12CommandQueueInfo) {}

    ID3D12FencePtr sync_fence;
    uint64_t       sync_value{ 0 };
};

struct D3D12DeviceInfo : DxObjectExtraInfo
{
    D3D12DeviceInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12DeviceInfo) {}

    std::shared_ptr<DescriptorIncrements> replay_increments{ std::make_shared<DescriptorIncrements>() };
};

struct D3D12DescriptorHeapInfo : DxObjectExtraInfo
{
    D3D12DescriptorHeapInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12DescriptorHeapInfo) {}

    std::shared_ptr<DescriptorIncrements> replay_increments;
    D3D12_DESCRIPTOR_HEAP_TYPE            descriptor_type{};
    size_t                                replay_cpu_addr_begin{ kNullCpuAddress };
    uint64_t                              replay_gpu_addr_begin{ kNullGpuAddress };
};

struct D3D12FenceInfo : DxObjectExtraInfo
{
    D3D12FenceInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12FenceInfo) {}

    HANDLE             completion_event{ nullptr };
    FenceEvents        event_objects;
    PendingFenceValues signaled_values;
};

struct D3D12HeapInfo : DxObjectExtraInfo
{
    D3D12HeapInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12HeapInfo) {}

    void* external_allocation{ nullptr };
};

struct D3D12ResourceInfo : DxObjectExtraInfo
{
    D3D12ResourceInfo() : DxObjectExtraInfo(DxObjectInfoType::kID3D12ResourceInfo) {}

    std::unordered_map<uint32_t, MappedMemoryInfo> mapped_memory_info; ///< Map subresource index to mapped memory info.
    uint64_t                                       capture_address_{ 0 }; ///< Capture GPU VA.
    uint64_t                                       replay_address_{ 0 };  ///< Replay GPU VA.
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_INFO_H
