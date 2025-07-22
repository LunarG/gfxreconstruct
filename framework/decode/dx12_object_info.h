/*
** Copyright (c) 2021-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
#include "util/logging.h"
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
    kID3D12StateObjectInfo,
    kID3D12PipelineLibraryInfo
};

//
// Enumerations for storing variable length array replay sizes.
//
enum class VariableLengthArrayIndices : uint32_t
{
    kDxgiObjectArrayGetPrivateData = 0,
    kDxgiOutputArrayGetDisplayModeList,
    kDxgiOutput1ArrayGetDisplayModeList1,
    kD3D12ObjectArrayGetPrivateData,
    kD3D12Device5ArrayEnumerateMetaCommands,
    kD3D12Device5ArrayEnumerateMetaCommandParameters,
    kD3D12InfoQueueArrayGetMessage,
    kD3D12InfoQueueArrayGetStorageFilter,
    kD3D12InfoQueueArrayGetRetrievalFilter,
    kD3D12ShaderCacheSessionArrayFindValue
};

//
// Structures for storing DirectX object info.
//

struct DxObjectInfo;
struct D3D12StateObjectInfo;
struct D3D12ResourceInfo;
struct D3D12CommandSignatureInfo;

// Util function for getting the extra info object from a DxObjectInfo.
template <typename T>
T* GetExtraInfo(DxObjectInfo* info)
{
    if ((info != nullptr) && (info->extra_info != nullptr) && (info->extra_info->extra_info_type == T::kType))
    {
        return static_cast<T*>(info->extra_info.get());
    }

    GFXRECON_LOG_FATAL("%s object does not have an associated info structure", T::kObjectType);

    return nullptr;
}

template <typename T>
const T* GetExtraInfo(const DxObjectInfo* info)
{
    if ((info != nullptr) && (info->extra_info != nullptr) && (info->extra_info->extra_info_type == T::kType))
    {
        return static_cast<T*>(info->extra_info.get());
    }

    GFXRECON_LOG_FATAL("%s object does not have an associated info structure", T::kObjectType);

    return nullptr;
}

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

typedef format::ResourceValueType ResourceValueType;

static size_t GetResourceValueSize(ResourceValueType type)
{
    switch (type)
    {
        case ResourceValueType::kGpuVirtualAddress:
            return sizeof(D3D12_GPU_VIRTUAL_ADDRESS);
        case ResourceValueType::kGpuDescriptorHandle:
            return sizeof(D3D12_GPU_DESCRIPTOR_HANDLE::ptr);
        case ResourceValueType::kShaderIdentifier:
            return D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES;
        default:
            GFXRECON_ASSERT(false && "Unrecognized resource value type.");
            return 0;
    }
}

struct ArgumentBufferExtraInfo
{
    D3D12CommandSignatureInfo* command_signature_info{ nullptr };
    DxObjectInfo*              argument_buffer{ nullptr };
    uint64_t                   argument_buffer_offset{ 0 };
};

struct ResourceValueInfo
{
    uint64_t                offset{ 0 };
    ResourceValueType       type{ ResourceValueType::kUnknown };
    uint64_t                size{ 0 };
    D3D12StateObjectInfo*   state_object{ nullptr }; ///< Used to map values in shader records.
    ArgumentBufferExtraInfo arg_buffer_extra_info;
    uint32_t                max_command_count{ 0 };

    ResourceValueInfo(uint64_t                in_offset,
                      ResourceValueType       in_type,
                      uint64_t                in_size,
                      D3D12StateObjectInfo*   in_state_object,
                      ArgumentBufferExtraInfo in_arg_buffer_extra_info,
                      uint32_t                in_max_command_count)
    {
        offset                = in_offset;
        type                  = in_type;
        size                  = in_size;
        state_object          = in_state_object;
        arg_buffer_extra_info = in_arg_buffer_extra_info;
        max_command_count     = in_max_command_count;
    }

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
    IUnknown*                                              object{ nullptr };
    format::HandleId                                       capture_id{ format::kNullHandleId };
    uint64_t                                               ref_count{ 1 };
    uint64_t                                               extra_ref{ 0 };
    std::unique_ptr<DxObjectExtraInfo>                     extra_info;
    std::unordered_map<VariableLengthArrayIndices, size_t> array_counts;
};

struct DxgiSwapchainInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kIDxgiSwapchainInfo;
    static constexpr char             kObjectType[] = "IDXGISwapChain";
    DxgiSwapchainInfo() : DxObjectExtraInfo(kType) {}

    uint32_t init_buffer_index{ 0 };
    Window*  window{ nullptr }; ///< Pointer to the platform-specific window object associated with the swapchain.
    uint64_t hwnd_id{ 0 };      ///< Capture ID for the HWND handle used with swapchain creation.

    std::vector<format::HandleId>
        image_ids; ///< HandleIds of swapchain image info entries to be kept in the info table while the swapchain is
                   ///< active. The length of this vector is the number of images in the swapchain.

    graphics::dx12::ID3D12CommandQueueComPtr command_queue{
        nullptr
    }; ///< The command queue that was used to create the swapchain.
    bool is_fullscreen{ false }; ///< Swapchain full screen flag.
};

struct D3D12CommandQueueInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandQueueInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandQueue";
    D3D12CommandQueueInfo() : DxObjectExtraInfo(kType) {}

    std::deque<QueueSyncEventInfo> pending_events;

    graphics::dx12::ID3D12FenceComPtr sync_fence;
    uint64_t                          sync_value{ 0 };
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
    virtual ~D3D12DeviceInfo()
    {
        if (adapter3 != nullptr)
        {
            adapter3->Release();
        }
    }

    // Track the device's parent adapter as IDXGIAdapter3
    // This enables checking GPU memory availability via QueryVideoMemoryInfo()
    IDXGIAdapter3* adapter3{ nullptr };
    uint32_t       adapter_node_index{ 0 };

    std::shared_ptr<DescriptorIncrements> capture_increments{ std::make_shared<DescriptorIncrements>() };
    std::shared_ptr<DescriptorIncrements> replay_increments{ std::make_shared<DescriptorIncrements>() };

    // Cache features of the device to avoid repeated queries
    bool is_uma{ false };
};

// Constant Buffer View, Shader Resource View and Unordered Access View could overrride each other.
// So they should be in the one container.
struct DHConstantBufferViewInfo
{
    D3D12_CONSTANT_BUFFER_VIEW_DESC captured_desc{};
    bool                            is_desc_null{ false };
    D3D12_CPU_DESCRIPTOR_HANDLE     replay_handle{ kNullCpuAddress };
};

struct DHShaderResourceViewInfo
{
    D3D12_SHADER_RESOURCE_VIEW_DESC desc{};
    bool                            is_desc_null{ false };
    format::HandleId                resource_id{ format::kNullHandleId };
    D3D12_CPU_DESCRIPTOR_HANDLE     replay_handle{ kNullCpuAddress };
    std::vector<uint32_t>           subresource_indices; // Only use for dump resources
};

struct DHUnorderedAccessViewInfo
{
    D3D12_UNORDERED_ACCESS_VIEW_DESC desc{};
    bool                             is_desc_null{ false };
    format::HandleId                 resource_id{ format::kNullHandleId };
    format::HandleId                 counter_resource_id{ format::kNullHandleId };
    D3D12_CPU_DESCRIPTOR_HANDLE      replay_handle{ kNullCpuAddress };
    std::vector<uint32_t>            subresource_indices; // Only use for dump resources
};

struct DHCbvSrvUavInfo
{
    D3D12_DESCRIPTOR_RANGE_TYPE type{};
    DHConstantBufferViewInfo    cbv;
    DHShaderResourceViewInfo    srv;
    DHUnorderedAccessViewInfo   uav;
};

struct DHRenderTargetViewInfo
{
    format::HandleId              resource_id{ format::kNullHandleId };
    D3D12_RENDER_TARGET_VIEW_DESC desc{};
    bool                          is_desc_null{ false };
    D3D12_CPU_DESCRIPTOR_HANDLE   replay_handle{ kNullCpuAddress };
    std::vector<uint32_t>         subresource_indices; // Only use for dump resources
};

struct DHDepthStencilViewInfo
{
    format::HandleId              resource_id{ format::kNullHandleId };
    D3D12_DEPTH_STENCIL_VIEW_DESC desc{};
    bool                          is_desc_null{ false };
    D3D12_CPU_DESCRIPTOR_HANDLE   replay_handle{ kNullCpuAddress };
    std::vector<uint32_t>         subresource_indices; // Only use for dump resources
};

struct DHSamplerInfo
{
    D3D12_SAMPLER_DESC          desc{};
    D3D12_CPU_DESCRIPTOR_HANDLE replay_handle{ kNullCpuAddress };
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

    // Descriptor info maps. Key is descriptor's uint32_t heap index.
    std::map<uint32_t, DHCbvSrvUavInfo>        cbv_srv_uav_infos;
    std::map<uint32_t, DHRenderTargetViewInfo> rtv_infos;
    std::map<uint32_t, DHDepthStencilViewInfo> dsv_infos;
    std::map<uint32_t, DHSamplerInfo>          sampler_infos;
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

    D3D12_RESOURCE_DESC1 desc = {};
    format::HandleId     swap_chain_id{ format::kNullHandleId };
    uint32_t             buffer_index{ 0 };

    size_t                                         subresource_count{ 0 };
    std::vector<graphics::dx12::ResourceStateInfo> resource_state_infos;
};

struct D3D12CommandSignatureInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandSignatureInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandSignature";
    D3D12CommandSignatureInfo() : DxObjectExtraInfo(kType) {}

    std::set<ResourceValueInfo> resource_value_infos;
    UINT                        byte_stride{ 0 };
};

struct ResourceStatesOrder
{
    D3D12_RESOURCE_TRANSITION_BARRIER transition;
    D3D12_RESOURCE_BARRIER_FLAGS      barrier_flags;
    uint64_t                          block_index{ 0 };
};

struct D3D12CommandListInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12CommandListInfo;
    static constexpr char             kObjectType[] = "ID3D12CommandListInfo";
    D3D12CommandListInfo() : DxObjectExtraInfo(kType) {}

    D3D12_COMMAND_LIST_TYPE create_list_type{ D3D12_COMMAND_LIST_TYPE_NONE };

    bool requires_sync_after_execute{ false };

    // Tracked state used by Dx12ResourceValueMapper.
    std::vector<ResourceCopyInfo> resource_copies;
    ResourceValueInfoMap          resource_value_info_map;
    DxObjectInfo*                 active_state_object{ nullptr };

    std::map<format::HandleId, std::vector<ResourceStatesOrder>> pending_resource_states; // HandleId is Resource.
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

    std::map<std::wstring, format::HandleId>                              export_name_lrs_map;
    std::map<graphics::Dx12ShaderIdentifier, std::set<ResourceValueInfo>> shader_id_lrs_map;
};

struct D3D12PipelineLibraryInfo : DxObjectExtraInfo
{
    static constexpr DxObjectInfoType kType         = DxObjectInfoType::kID3D12PipelineLibraryInfo;
    static constexpr char             kObjectType[] = "ID3D12PipelineLibrary";
    D3D12PipelineLibraryInfo() : DxObjectExtraInfo(kType) {}

    std::unique_ptr<uint8_t[]> cache_data;
    size_t                     replay_cache_data_size{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_OBJECT_INFO_H
