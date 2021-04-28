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

#include "util/defines.h"
#include "util/page_guard_manager.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class ID3D12Resource_Wrapper;

struct MappedSubresource
{
    void*     data{ nullptr };
    uintptr_t shadow_allocation{ util::PageGuardManager::kNullShadowHandle };
    int32_t   map_count{ 0 };
};

struct IDXGIKeyedMutexInfo
{};

struct IDXGIDisplayControlInfo
{};

struct IDXGIOutputDuplicationInfo
{};

struct IDXGISurfaceInfo
{};

struct IDXGIResourceInfo
{};

struct IDXGIDecodeSwapChainInfo
{};

struct IDXGIFactoryMediaInfo
{};

struct IDXGISwapChainMediaInfo
{};

struct IDXGISwapChainInfo
{
    DXGI_SWAP_EFFECT                           swap_effect{};
    uint32_t                                   image_count{ 0 };
    std::unique_ptr<ID3D12Resource_Wrapper*[]> images;
};

struct IDXGIDeviceInfo
{};

struct IDXGIAdapterInfo
{};

struct IDXGIOutputInfo
{};

struct IDXGIFactoryInfo
{};

struct ID3D12RootSignatureInfo
{};

struct ID3D12RootSignatureDeserializerInfo
{};

struct ID3D12VersionedRootSignatureDeserializerInfo
{};

struct ID3D12CommandAllocatorInfo
{};

struct ID3D12FenceInfo
{};

struct ID3D12PipelineStateInfo
{};

struct ID3D12DescriptorHeapInfo
{};

struct ID3D12QueryHeapInfo
{};

struct ID3D12CommandSignatureInfo
{};

struct ID3D12CommandQueueInfo
{};

struct ID3D12PipelineLibraryInfo
{};

struct ID3D12LifetimeOwnerInfo
{};

struct ID3D12SwapChainAssistantInfo
{};

struct ID3D12LifetimeTrackerInfo
{};

struct ID3D12StateObjectInfo
{};

struct ID3D12StateObjectPropertiesInfo
{};

struct ID3D12DeviceRemovedExtendedDataSettingsInfo
{};

struct ID3D12DeviceRemovedExtendedDataInfo
{};

struct ID3D12ProtectedResourceSessionInfo
{};

struct ID3D12DeviceInfo
{};

struct ID3D12ResourceInfo
{
    size_t                               num_subresources{ 0 };
    std::unique_ptr<uint64_t[]>          subresource_sizes;
    std::unique_ptr<MappedSubresource[]> mapped_subresources;
    bool                                 has_write_watch{ false };
    D3D12_HEAP_TYPE                      heap_type{};
    D3D12_CPU_PAGE_PROPERTY              page_property{};
};

struct ID3D12HeapInfo
{
    bool                    has_write_watch{ false };
    D3D12_HEAP_TYPE         heap_type{};
    D3D12_CPU_PAGE_PROPERTY page_property{};
};

struct ID3D12MetaCommandInfo
{};

struct ID3D12ToolsInfo
{};

struct ID3D12GraphicsCommandListInfo
{};

struct ID3D10BlobInfo
{};

struct ID3DDestructionNotifierInfo
{};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_OBJECT_WRAPPER_INFO_H
