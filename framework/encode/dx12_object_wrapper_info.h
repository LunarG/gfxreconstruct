/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2022-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H
#define GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H

#include "format/format.h"
#include "graphics/dx12_util.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/page_guard_manager.h"

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_5.h>

#include <array>
#include <unordered_set>
#include <map>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

struct IUnknown_Wrapper;
class ID3D12Resource_Wrapper;
class ID3D12Device_Wrapper;
class ID3D12Heap_Wrapper;
class IDXGISwapChain_Wrapper;

struct GUID_Hash
{
    size_t operator()(REFGUID k) const
    {
        uint64_t data2   = k.Data2;
        uint64_t data3   = k.Data3;
        uint64_t data123 = k.Data1 ^ (data2 << 32) ^ (data3 << 48);
        uint64_t data4   = 0;
        for (uint8_t i = 0; i < 8; ++i)
        {
            uint64_t data4 = k.Data4[i];
            data4 ^= (data4 << (i * 8));
        }
        return std::hash<uint64_t>()(data123) ^ (std::hash<uint64_t>()(data4) << 1);
    }
};

struct GUID_Equal
{
    bool operator()(REFGUID lhs, REFGUID rhs) const { return IsEqualGUID(lhs, rhs); }
};

struct DxWrapperInfo
{
    void SetWrapper(const IUnknown_Wrapper* wrapper)
    {
        // Either the current wrapper or the incoming wrapper must be nullptr, but not both. I.e., wrapper_ is either
        // being set or cleared.
        assert((wrapper_ != wrapper) && ((wrapper == nullptr) || (wrapper_ == nullptr)));
        wrapper_ = wrapper;
    }

    virtual bool IsDxgi() const { return false; }

    const IUnknown_Wrapper* GetWrapper() const { return wrapper_; }

    format::ApiCallId                         create_call_id{ format::ApiCallId::ApiCall_Unknown };
    std::unique_ptr<util::MemoryOutputStream> create_parameters;

    // Info for the object that created this object (if any).
    format::HandleId                     create_object_id{ format::kNullHandleId };
    std::shared_ptr<const DxWrapperInfo> create_object_info;

    std::unordered_map<const GUID, std::vector<uint8_t>, GUID_Hash, GUID_Equal> private_datas;

    std::wstring object_name{ L"" };

  private:
    // A pointer to the wrapper that owns/created this info struct, or nullptr if the wrapper no longer exists.
    const IUnknown_Wrapper* wrapper_ = nullptr;
};

struct DxgiWrapperInfo : public DxWrapperInfo
{
    virtual bool IsDxgi() const override { return true; }
};

// MappedSubresources are contained by ID3D12ResourceInfo.
struct MappedSubresource
{
    void*     data{ nullptr };
    uintptr_t shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    int32_t   map_count{ 0 };
};

// DxDescriptorInfos are contained by DxDescriptorHeapInfo.
struct DxDescriptorInfo
{
    size_t           cpu_address{ 0 };
    uint64_t         gpu_address{ 0 };
    format::HandleId heap_id{ format::kNullHandleId };
    uint32_t         index{ 0 };

    // State tracking info
    format::HandleId                          create_object_id{ format::kNullHandleId };
    format::ApiCallId                         create_call_id{ format::ApiCallId::ApiCall_Unknown };
    std::unique_ptr<util::MemoryOutputStream> create_parameters;
    bool is_copy{ false }; // True if the descriptor was created as a copy with CopyDescriptors

    // Descriptors can be created with up to 2 resource dependencies or a GPU VA.
    std::array<format::HandleId, 2> resource_ids{ format::kNullHandleId, format::kNullHandleId };
    D3D12_GPU_VIRTUAL_ADDRESS       resource_gpu_va{ 0 };
};

struct DxTransitionBarrier
{
    ID3D12Resource_Wrapper*      resource_wrapper{ nullptr };
    UINT                         subresource{};
    D3D12_RESOURCE_STATES        state_before{};
    D3D12_RESOURCE_STATES        state_after{};
    D3D12_RESOURCE_BARRIER_FLAGS barrier_flags{};
};

struct DxImageAcquiredInfo
{
    bool is_acquired{ false };
    UINT sync_interval{ 0 };
    UINT present_flags{ 0 };

    // DXGI_PRESENT_PARAMETERS
    bool              is_present_parameters{ false };
    std::vector<RECT> dirty_rects;
    RECT              scroll_rect{};
    POINT             scroll_offset{};
};

struct DxTileMappingInfo
{
    format::HandleId                          queue_id;
    format::HandleId                          heap_id;
    std::unique_ptr<util::MemoryOutputStream> call_parameters;
};

struct DxResizeBuffersInfo
{
    format::ApiCallId                         call_id{ format::ApiCall_Unknown };
    std::unique_ptr<util::MemoryOutputStream> call_parameters;
};

struct DxAccelerationStructureCopyInfo
{
    D3D12_GPU_VIRTUAL_ADDRESS dest_gpu_va{ 0 };
    ID3D12Resource_Wrapper*   dest_resource_wrapper{ nullptr };
    D3D12_GPU_VIRTUAL_ADDRESS source_gpu_va{ 0 };
    ID3D12Resource_Wrapper*   source_resource_wrapper{ nullptr };

    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE mode{};
};

struct DxAccelerationStructureBuildInfo
{
    // Unique ID for this acceleration structure. Lower IDs were built or copied first.
    uint64_t id{ 0 };

    // The destination address and associated resource for the acceleration structure build.
    D3D12_GPU_VIRTUAL_ADDRESS dest_gpu_va{ 0 };
    UINT64                    dest_size{ 0 };
    ID3D12Resource_Wrapper*   destination_resource{ nullptr };

    // Build inputs.
    D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS inputs{};

    // Save a copy of the inputs' geometry descs for bottom level accel structs.
    std::vector<D3D12_RAYTRACING_GEOMETRY_DESC> inputs_geometry_descs;

    uint64_t                             input_data_size{ 0 };
    uint64_t                             input_data_header_size{ 0 };
    graphics::dx12::ID3D12ResourceComPtr input_data_resource{ nullptr };

    // Copy state.
    D3D12_GPU_VIRTUAL_ADDRESS copy_source_gpu_va{
        0
    }; ///< GPU VA for the source of the copy used to create this acceleration structure.
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE
    copy_mode{};                   ///< Copy mode used to create this acceleration structure
    bool was_copy_source{ false }; ///< Was this acceleration structure copied to another?

    bool is_tlas_with_array_of_pointers{ false };
};

struct IDXGIKeyedMutexInfo : public DxgiWrapperInfo
{};

struct IDXGIDisplayControlInfo : public DxgiWrapperInfo
{};

struct IDXGIOutputDuplicationInfo : public DxgiWrapperInfo
{};

struct IDXGISurfaceInfo : public DxgiWrapperInfo
{};

struct IDXGIResourceInfo : public DxgiWrapperInfo
{};

struct IDXGIDecodeSwapChainInfo : public DxgiWrapperInfo
{};

struct IDXGIFactoryMediaInfo : public DxgiWrapperInfo
{};

struct IDXGISwapChainMediaInfo : public DxgiWrapperInfo
{};

struct IDXGISwapChainInfo : public DxgiWrapperInfo
{
    format::HandleId command_queue_id{ format::kNullHandleId };
    DXGI_SWAP_EFFECT swap_effect{};
    // Members for general wrapper support.
    std::vector<ID3D12Resource_Wrapper*> child_images;

    graphics::dx12::ID3D12CommandQueueComPtr command_queue{ nullptr };

    // Members for trimming state tracking.
    uint32_t                         current_back_buffer_index{ std::numeric_limits<uint32_t>::max() };
    uint32_t                         last_presented_image{ std::numeric_limits<uint32_t>::max() };
    std::vector<DxImageAcquiredInfo> image_acquired_info;
    DxResizeBuffersInfo              resize_info;

    // HDR state
    bool                   set_color_space{ false };
    bool                   set_hdr_metadata{ false };
    DXGI_COLOR_SPACE_TYPE  color_space_type{};
    DXGI_HDR_METADATA_TYPE hdr_metadata_type{};
    UINT                   hdr_metadata_size{ 0 };
    void*                  hdr_metadata{ nullptr };
};

struct IDXGIDeviceInfo : public DxgiWrapperInfo
{};

struct IDXGIAdapterInfo : public DxgiWrapperInfo
{};

struct IDXGIOutputInfo : public DxgiWrapperInfo
{};

struct IDXGIFactoryInfo : public DxgiWrapperInfo
{};

struct ID3D12RootSignatureInfo : public DxWrapperInfo
{};

struct ID3D12RootSignatureDeserializerInfo : public DxWrapperInfo
{};

struct ID3D12VersionedRootSignatureDeserializerInfo : public DxWrapperInfo
{};

struct ID3D12CommandAllocatorInfo : public DxWrapperInfo
{};

struct ID3D12FenceInfo : public DxWrapperInfo
{
    std::mutex                            pending_events_mutex;
    std::map<UINT64, std::vector<HANDLE>> pending_events;
};

struct ID3D12PipelineStateInfo : public DxWrapperInfo
{};

struct ID3D12DescriptorHeapInfo : public DxWrapperInfo
{
    std::unique_ptr<uint8_t[]>          descriptor_memory;
    std::unique_ptr<DxDescriptorInfo[]> descriptor_info;

    SIZE_T cpu_start{ 0 };
    UINT64 gpu_start{ 0 };
    UINT32 descriptor_increment;
};

struct ID3D12QueryHeapInfo : public DxWrapperInfo
{};

struct ID3D12CommandSignatureInfo : public DxWrapperInfo
{};

struct AccelerationStructureBuildTrackingObjects
{
    AccelerationStructureBuildTrackingObjects(
        graphics::dx12::ID3D12ResourceComPtr             _resource,
        graphics::dx12::ID3D12CommandAllocatorComPtr     _post_build_copy_cmd_allocator,
        graphics::dx12::ID3D12GraphicsCommandList4ComPtr _post_build_copy_cmd_list) :
        resource(_resource), post_build_copy_cmd_allocator(_post_build_copy_cmd_allocator),
        post_build_copy_cmd_list(_post_build_copy_cmd_list)
    {}

    // Target resource for build inputs.
    graphics::dx12::ID3D12ResourceComPtr resource = nullptr;

    // Objects used to copy inputs for TLAS builds that use D3D12_ELEMENTS_LAYOUT_ARRAY_OF_POINTERS for DescLayout.
    graphics::dx12::ID3D12CommandAllocatorComPtr     post_build_copy_cmd_allocator = nullptr;
    graphics::dx12::ID3D12GraphicsCommandList4ComPtr post_build_copy_cmd_list      = nullptr;
};

struct ID3D12CommandQueueInfo : public DxWrapperInfo
{
    //// Begin state tracking members

    // Fence that is signalled on the queue after AS builds.
    graphics::dx12::ID3D12FenceComPtr acceleration_structure_build_tracking_fence;

    // Objects that need to be kept alive until the associated AS build has completed on the GPU. Key of the map is the
    // fence signal value to indicate the AS build is complete.
    std::map<uint64_t, AccelerationStructureBuildTrackingObjects> acceleration_structure_build_tracking_objects;
};

struct ID3D12PipelineLibraryInfo : public DxWrapperInfo
{};

struct ID3D12LifetimeOwnerInfo : public DxWrapperInfo
{};

struct ID3D12SwapChainAssistantInfo : public DxWrapperInfo
{};

struct ID3D12LifetimeTrackerInfo : public DxWrapperInfo
{};

struct ID3D12StateObjectInfo : public DxWrapperInfo
{
    //// Begin state tracking members

    std::unordered_map<format::HandleId, std::shared_ptr<const DxWrapperInfo>> root_signature_wrapper_infos;

    std::pair<format::HandleId, std::shared_ptr<const DxWrapperInfo>> grow_from_state_object_wrapper_info{
        format::kNullHandleId, nullptr
    };
};

struct ID3D12StateObjectPropertiesInfo : public DxWrapperInfo
{
    //// Begin state tracking members

    std::unordered_map<std::wstring, std::shared_ptr<util::MemoryOutputStream>> get_shader_identifier_call_parameters;
};

struct EnableDREDInfo
{
    format::HandleId      dred_settings1_object_id{ format::kNullHandleId }; // ID3D12DeviceRemovedExtendedDataSettings1
    D3D12_DRED_ENABLEMENT set_auto_breadcrumbs_enablement_{ D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED };
    D3D12_DRED_ENABLEMENT set_breadcrumb_context_enablement_{ D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED };
    D3D12_DRED_ENABLEMENT set_page_fault_enablement_{ D3D12_DRED_ENABLEMENT_SYSTEM_CONTROLLED };
};

struct ID3D12DeviceRemovedExtendedDataSettingsInfo : public DxWrapperInfo
{};

struct ID3D12DeviceRemovedExtendedDataInfo : public DxWrapperInfo
{};

struct ID3D12ProtectedResourceSessionInfo : public DxWrapperInfo
{};

struct ID3D12DeviceInfo : public DxWrapperInfo
{
    // Track the device's parent adapter as IDXGIAdapter3
    // This enables checking GPU memory availability via QueryVideoMemoryInfo()
    IDXGIAdapter3* adapter3{ nullptr };
    uint32_t       adapter_node_index{ 0 };

    std::unordered_map<format::HandleId, D3D12_RESIDENCY_PRIORITY> residency_priorities; // ID3D12Pageable

    // Cache features of the device to avoid repeated queries
    bool is_uma{ false };
};

struct ID3D12ResourceInfo : public DxWrapperInfo
{
    ID3D12Device_Wrapper*                device_wrapper{ nullptr };
    size_t                               num_subresources{ 0 };
    std::unique_ptr<uint64_t[]>          subresource_sizes;
    std::unique_ptr<MappedSubresource[]> mapped_subresources;
    bool                                 has_write_watch{ false };
    D3D12_HEAP_TYPE                      heap_type{};
    D3D12_CPU_PAGE_PROPERTY              page_property{};
    D3D12_MEMORY_POOL                    memory_pool{};
    D3D12_RESOURCE_DIMENSION             dimension{ D3D12_RESOURCE_DIMENSION_UNKNOWN };
    D3D12_TEXTURE_LAYOUT                 layout{ D3D12_TEXTURE_LAYOUT_UNKNOWN };
    //// State tracking data:

    // Most recent transitions for each subresource.
    D3D12_RESOURCE_STATES                          initial_state;
    std::vector<graphics::dx12::ResourceStateInfo> subresource_transitions;

    // Track tile mappings for reserved resources.
    std::vector<DxTileMappingInfo> tile_mappings;

    bool is_swapchain_buffer{ false };

    D3D12_GPU_VIRTUAL_ADDRESS gpu_va{ 0 };

    // Track acceleration structures that were built to this resource
    std::map<D3D12_GPU_VIRTUAL_ADDRESS, DxAccelerationStructureBuildInfo> acceleration_structure_builds;

    ID3D12Heap_Wrapper* heap_wrapper{ nullptr };
    uint64_t            heap_offset;
    uint64_t            heap_id{ format::kNullHandleId };

    IDXGISwapChain_Wrapper* swapchain_wrapper{ nullptr };
};

struct ID3D12HeapInfo : public DxWrapperInfo
{
    bool                      has_write_watch{ false };
    D3D12_HEAP_TYPE           heap_type{};
    D3D12_CPU_PAGE_PROPERTY   page_property{};
    D3D12_MEMORY_POOL         memory_pool{};
    uint64_t                  heap_size{ 0 };
    D3D12_GPU_VIRTUAL_ADDRESS gpu_va{ 0 };
    D3D12_HEAP_FLAGS          heap_flags{ D3D12_HEAP_FLAG_NONE };

    const void* open_existing_address{ nullptr }; ///< Address used to create heap with OpenExistingHeapFromAddress.
};

struct ID3D12MetaCommandInfo : public DxWrapperInfo
{
    bool                                      was_initialized{ false };
    std::unique_ptr<util::MemoryOutputStream> initialize_parameters;
};

struct ID3D12ShaderCacheSessionInfo : public DxWrapperInfo
{};

struct ID3D12SDKConfigurationInfo : public DxWrapperInfo
{};

struct ID3D12ToolsInfo : public DxWrapperInfo
{};

enum D3D12GraphicsCommandObjectType : uint32_t
{
    ID3D12CommandAllocatorObject = 0,
    ID3D12PipelineStateObject,
    ID3D12ResourceObject,
    ID3D12GraphicsCommandListObject,
    ID3D12DescriptorHeapObject,
    ID3D12RootSignatureObject,
    ID3D12QueryHeapObject,
    ID3D12ProtectedResourceSessionObject,
    ID3D12MetaCommandObject,
    ID3D12StateObjectObject,
    ID3D12CommandSignatureObject,
    NumObjectTypes
};

struct ID3D12CommandListInfo : public DxWrapperInfo
{
    bool                             was_reset{ false };
    bool                             is_closed{ false };
    util::MemoryOutputStream         command_data;
    std::vector<DxTransitionBarrier> transition_barriers;
    D3D12_COMMAND_LIST_TYPE          command_list_type{};

    // Track command list dependencies.
    format::HandleId                                  create_command_allocator_id{ format::kNullHandleId };
    std::shared_ptr<const ID3D12CommandAllocatorInfo> create_command_allocator_info;
    format::HandleId                                  reset_command_allocator_id{ format::kNullHandleId };
    std::unordered_set<format::HandleId>              command_objects[D3D12GraphicsCommandObjectType::NumObjectTypes];
    std::unordered_set<SIZE_T>                        command_cpu_descriptor_handles;
    std::unordered_set<D3D12_GPU_VIRTUAL_ADDRESS>     command_gpu_virtual_addresses;

    // Record for future. It's not used for now.
    std::unordered_set<UINT64> command_gpu_descriptor_handles;

    // Track acceleration structure builds that are recorded to this command list.
    std::vector<DxAccelerationStructureBuildInfo> acceleration_structure_builds;
    std::vector<DxAccelerationStructureCopyInfo>  acceleration_structure_copies;

    uint32_t draw_call_count{ 0 }; // DrawInstanced, DrawIndexedInstanced, Dispatch, ExecuteIndirect, ExecuteBundle

    // GFXRECON_CAPTURE_DRAW_CALLS
    std::array<graphics::dx12::CommandSet, 3>    split_command_sets;
    bool                                         is_split_commandlist{ false };
    uint32_t                                     find_target_draw_call_count{ 0 };
    std::shared_ptr<const ID3D12CommandListInfo> target_bundle_commandlist_info;
    bool                                         is_trim_target{ false };
};

struct ID3D10BlobInfo : public DxWrapperInfo
{};

struct ID3DDestructionNotifierInfo : public DxWrapperInfo
{};

struct ID3D12DebugInfo : public DxWrapperInfo
{};

struct ID3D12Debug1Info : public DxWrapperInfo
{};

struct ID3D12Debug2Info : public DxWrapperInfo
{};

struct ID3D12DebugDeviceInfo : public DxWrapperInfo
{};

struct ID3D12DebugDevice1Info : public DxWrapperInfo
{};

struct ID3D12DebugCommandQueueInfo : public DxWrapperInfo
{};

struct ID3D12DebugCommandListInfo : public DxWrapperInfo
{};

struct ID3D12DebugCommandList1Info : public DxWrapperInfo
{};

struct ID3D12SharingContractInfo : public DxWrapperInfo
{};

struct ID3D12InfoQueueInfo : public DxWrapperInfo
{};

struct ID3D12VirtualizationGuestDeviceInfo : public DxWrapperInfo
{};

struct ID3D12DeviceFactoryInfo : public DxWrapperInfo
{};

struct ID3D12DeviceConfigurationInfo : public DxWrapperInfo
{};

struct ID3D12DSRDeviceFactoryInfo : public DxWrapperInfo
{};

struct ID3D12ManualWriteTrackingResourceInfo : public DxWrapperInfo
{};

struct ID3D12WorkGraphPropertiesInfo : public DxWrapperInfo
{};

struct ID3D12PageableToolsInfo : public DxWrapperInfo
{};

struct ID3D12DeviceToolsInfo : public DxWrapperInfo
{};

struct ID3D12GBVDiagnosticsInfo : public DxWrapperInfo
{};

struct AgsContextInfo : public DxWrapperInfo
{};

struct AgsDeviceInfo : public DxWrapperInfo
{};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H
