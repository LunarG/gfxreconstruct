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

#ifndef GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H
#define GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H

#include "format/format.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"
#include "util/page_guard_manager.h"

#include <d3d12.h>
#include <dxgi.h>

#include <map>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ID3D12Device_Wrapper;
class ID3D12Resource_Wrapper;

struct DxWrapperInfo
{
    format::ApiCallId                         create_call_id{ format::ApiCallId::ApiCall_Unknown };
    format::HandleId                          create_call_object_id{ format::kNullHandleId };
    std::shared_ptr<util::MemoryOutputStream> create_parameters{ nullptr };
};

struct MappedSubresource : public DxWrapperInfo
{
    void*     data{ nullptr };
    uintptr_t shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    int32_t   map_count{ 0 };
};

struct DxDescriptorInfo : public DxWrapperInfo
{
    size_t           cpu_address{ 0 };
    uint64_t         gpu_address{ 0 };
    format::HandleId heap_id{ format::kNullHandleId };
    uint32_t         index{ 0 };
};

struct IDXGIKeyedMutexInfo : public DxWrapperInfo
{};

struct IDXGIDisplayControlInfo : public DxWrapperInfo
{};

struct IDXGIOutputDuplicationInfo : public DxWrapperInfo
{};

struct IDXGISurfaceInfo : public DxWrapperInfo
{};

struct IDXGIResourceInfo : public DxWrapperInfo
{};

struct IDXGIDecodeSwapChainInfo : public DxWrapperInfo
{};

struct IDXGIFactoryMediaInfo : public DxWrapperInfo
{};

struct IDXGISwapChainMediaInfo : public DxWrapperInfo
{};

struct IDXGISwapChainInfo : public DxWrapperInfo
{
    DXGI_SWAP_EFFECT                           swap_effect{};
    uint32_t                                   image_count{ 0 };
    std::unique_ptr<ID3D12Resource_Wrapper*[]> images;
};

struct IDXGIDeviceInfo : public DxWrapperInfo
{};

struct IDXGIAdapterInfo : public DxWrapperInfo
{};

struct IDXGIOutputInfo : public DxWrapperInfo
{};

struct IDXGIFactoryInfo : public DxWrapperInfo
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
    uint32_t                            num_descriptors;
    std::unique_ptr<uint8_t[]>          descriptor_memory;
    std::unique_ptr<DxDescriptorInfo[]> descriptor_info;

    SIZE_T cpu_start{ 0 };
    UINT64 gpu_start{ 0 };
};

struct ID3D12QueryHeapInfo : public DxWrapperInfo
{};

struct ID3D12CommandSignatureInfo : public DxWrapperInfo
{};

struct ID3D12CommandQueueInfo : public DxWrapperInfo
{
    ID3D12Device_Wrapper* device_wrapper{ nullptr };
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
{};

struct ID3D12StateObjectPropertiesInfo : public DxWrapperInfo
{};

struct ID3D12DeviceRemovedExtendedDataSettingsInfo : public DxWrapperInfo
{};

struct ID3D12DeviceRemovedExtendedDataInfo : public DxWrapperInfo
{};

struct ID3D12ProtectedResourceSessionInfo : public DxWrapperInfo
{};

struct ID3D12DeviceInfo : public DxWrapperInfo
{
    // TODO (GH #83): Track debug layer state here?
};

struct ID3D12ResourceInfo : public DxWrapperInfo
{
    format::HandleId                     device_id{ format::kNullHandleId };
    size_t                               num_subresources{ 0 };
    std::unique_ptr<uint64_t[]>          subresource_sizes;
    std::unique_ptr<MappedSubresource[]> mapped_subresources;
    bool                                 has_write_watch{ false };
    D3D12_HEAP_TYPE                      heap_type{};
    D3D12_CPU_PAGE_PROPERTY              page_property{};
    D3D12_MEMORY_POOL                    memory_pool{};
};

struct ID3D12HeapInfo : public DxWrapperInfo
{
    bool                    has_write_watch{ false };
    D3D12_HEAP_TYPE         heap_type{};
    D3D12_CPU_PAGE_PROPERTY page_property{};
    D3D12_MEMORY_POOL       memory_pool{};

    const void* open_existing_address{ nullptr }; ///< Address used to create heap with OpenExistingHeapFromAddress.
};

struct ID3D12MetaCommandInfo : public DxWrapperInfo
{};

struct ID3D12ToolsInfo : public DxWrapperInfo
{};

struct ID3D12GraphicsCommandListInfo : public DxWrapperInfo
{
    util::MemoryOutputStream command_data;
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H
