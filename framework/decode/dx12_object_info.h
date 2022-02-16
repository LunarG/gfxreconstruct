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
#include "graphics/dx12_shader_id_map.h"
#include "graphics/dx12_util.h"
#include "util/defines.h"
#include "decode/dx12_descriptor_map.h"

#include <d3d12.h>

#include <array>
#include <comdef.h>
#include <deque>
#include <functional>
#include <memory>
#include <Unknwn.h>
#include <map>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

constexpr size_t   kNullCpuAddress = 0;
constexpr uint64_t kNullGpuAddress = 0;

typedef std::array<UINT, D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES> DescriptorIncrements;

enum class DxObjectInfoType : uint32_t
{
    kUnused = 0,
    kIDxgiSwapchainInfo,
    kID3D12CommandQueueInfo,
    kID3D12DeviceInfo,
    kID3D12DescriptorHeapInfo,
    kID3D12FenceInfo,
    kID3D12HeapInfo,
    kID3D12ResourceInfo,
    kID3D12CommandSignatureInfo,
    kID3D12CommandListInfo,
    kID3D12RootSignatureInfo,
    kID3D12StateObjectInfo
};

//
// Structures for storing DirectX object info.
//

struct DxObjectInfo;

struct MappedMemoryInfo
{
    uint32_t count{ 0 };     ///< Number of times that the memory has been mapped.
    uint64_t memory_id{ 0 }; ///< Capture ID for the mapped memory.
};

struct QueueSyncEventInfo
{
    bool          is_wait{ false };
    bool          is_signaled{ false };
    DxObjectInfo* fence_info;
    uint64_t      value;

    std::function<void()> event_function;
};

struct FenceValueSyncInfo
{
    std::vector<HANDLE>        wait_events;
    std::vector<DxObjectInfo*> wait_queues;
};

struct ResourceCopyInfo
{
    DxObjectInfo* dst_resource_object_info{ nullptr };
    uint64_t      dst_offset{ 0 };
    DxObjectInfo* src_resource_object_info{ nullptr };
    uint64_t      src_offset{ 0 };
    uint64_t      num_bytes{ 0 }; ///< 0 indicates copying the entire resource.
};

enum class ResourceValueType : uint8_t
{
    kUnknown,
    kGpuVirtualAddress,
    kGpuDescriptorHandle,
    kShaderRecord
};

struct ResourceValueInfo
{
    uint64_t          offset{ 0 };
    ResourceValueType type{ ResourceValueType::kUnknown };
    uint64_t          size{ 0 };

    bool operator<(const ResourceValueInfo& other) const { return offset < other.offset; }
};

typedef std::map<DxObjectInfo*, std::set<ResourceValueInfo>> ResourceValueInfoMap;

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
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kIDxgiSwapchainInfo;
    static constexpr char             kObjectType[] = "IDXGISwapChain";
    DxgiSwapchainInfo() : DxObjectExtraInfo(kType) {}

    Window*  window{ nullptr }; ///< Pointer to the platform-specific window object associated with the swapchain.
    uint64_t hwnd_id{ 0 };      ///< Capture ID for the HWND handle used with swapchain creation.
    uint32_t image_count{ 0 };  ///< The number of swapchain images.
    std::unique_ptr<DxObjectInfo*[]> images; ///< Pointers to swapchain image info entries to be kept in the info table
                                             ///< while the swapchain is active.
};

struct D3D12CommandQueueInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandQueueInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandQueue";
    D3D12CommandQueueInfo() : DxObjectExtraInfo(kType) {}

    std::deque<QueueSyncEventInfo> pending_events;

    graphics::dx12::ID3D12FenceComPtr sync_fence;
    uint64_t                          sync_value{ 0 };
    DxObjectInfo                      sync_fence_info;
    HANDLE                            sync_event{ nullptr };

    // Synchronization used for mapping values in resource data.
    graphics::dx12::ID3D12FenceComPtr resource_value_map_fence{ nullptr };
    uint64_t                          resource_value_map_fence_value{ 0 };
    DxObjectInfo                      resource_value_map_fence_info;
    HANDLE                            resource_value_map_event{ nullptr };
};

struct D3D12DeviceInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12DeviceInfo;
    static constexpr char             kObjectType[] = "ID3D12Device";
    D3D12DeviceInfo() : DxObjectExtraInfo(kType) {}

    std::shared_ptr<DescriptorIncrements> capture_increments{ std::make_shared<DescriptorIncrements>() };
    std::shared_ptr<DescriptorIncrements> replay_increments{ std::make_shared<DescriptorIncrements>() };
};

struct D3D12DescriptorHeapInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12DescriptorHeapInfo;
    static constexpr char             kObjectType[] = "ID3D12DescriptorHeap";
    D3D12DescriptorHeapInfo() : DxObjectExtraInfo(kType) {}

    std::shared_ptr<DescriptorIncrements> capture_increments;
    std::shared_ptr<DescriptorIncrements> replay_increments;
    D3D12_DESCRIPTOR_HEAP_TYPE            descriptor_type{};
    uint32_t                              descriptor_count{};
    uint64_t                              capture_gpu_addr_begin{ kNullGpuAddress };
    size_t                                replay_cpu_addr_begin{ kNullCpuAddress };
    uint64_t                              replay_gpu_addr_begin{ kNullGpuAddress };
};

struct D3D12FenceInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12FenceInfo;
    static constexpr char             kObjectType[] = "ID3D12FenceInfo";
    D3D12FenceInfo() : DxObjectExtraInfo(kType) {}

    uint64_t                               last_signaled_value{ 0 };
    std::map<uint64_t, FenceValueSyncInfo> waiting_objects;
};

struct D3D12HeapInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12HeapInfo;
    static constexpr char             kObjectType[] = "ID3D12HeapInfo";
    D3D12HeapInfo() : DxObjectExtraInfo(kType) {}

    void* external_allocation{ nullptr };
};

struct D3D12ResourceInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12ResourceInfo;
    static constexpr char             kObjectType[] = "ID3D12Resource";
    D3D12ResourceInfo() : DxObjectExtraInfo(kType) {}

    std::unordered_map<uint32_t, MappedMemoryInfo> mapped_memory_info; ///< Map subresource index to mapped memory info.
    uint64_t                                       capture_address_{ 0 }; ///< Capture GPU VA.
    uint64_t                                       replay_address_{ 0 };  ///< Replay GPU VA.

    bool is_reserved_resource{ false };

    std::map<uint64_t, uint64_t>                       mapped_gpu_addresses;
    std::map<uint64_t, graphics::Dx12ShaderIdentifier> mapped_shader_ids;
};

struct D3D12CommandSignatureInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandSignatureInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandSignature";
    D3D12CommandSignatureInfo() : DxObjectExtraInfo(kType) {}

    std::set<ResourceValueInfo> resource_value_infos;
    UINT                        byte_stride{ 0 };
};

struct D3D12CommandListInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandListInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandListInfo";
    D3D12CommandListInfo() : DxObjectExtraInfo(kType) {}

    std::vector<ResourceCopyInfo> resource_copies;

    ResourceValueInfoMap resource_value_info_map;
};

struct D3D12RootSignatureInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12RootSignatureInfo;
    static constexpr char             kObjectType[] = "ID3D12RootSignatureInfo";
    D3D12RootSignatureInfo() : DxObjectExtraInfo(kType) {}

    std::set<ResourceValueInfo> resource_value_infos;
};

struct D3D12StateObjectInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12StateObjectInfo;
    static constexpr char             kObjectType[] = "ID3D12StateObjectInfo";
    D3D12StateObjectInfo() : DxObjectExtraInfo(kType) {}

    std::map<std::wstring, format::HandleId>                          export_name_lrs_map;
    std::map<graphics::Dx12ShaderIdentifier, D3D12RootSignatureInfo*> shader_id_lrs_map;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_INFO_H
