/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_DX12_UTIL_H
#define GFXRECON_GRAPHICS_DX12_UTIL_H

#include "util/defines.h"
#include "util/logging.h"
#include "util/platform.h"
#include "graphics/dx12_image_renderer.h"
#include "format/format.h"

#include <comdef.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <vector>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

typedef _com_ptr_t<_com_IIID<IDXGISwapChain3, &__uuidof(IDXGISwapChain3)>> IDXGISwapChain3ComPtr;

typedef _com_ptr_t<_com_IIID<ID3D12DescriptorHeap, &__uuidof(ID3D12DescriptorHeap)>>     ID3D12DescriptorHeapComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Device, &__uuidof(ID3D12Device)>>                     ID3D12DeviceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Device5, &__uuidof(ID3D12Device5)>>                   ID3D12Device5ComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Fence, &__uuidof(ID3D12Fence)>>                       ID3D12FenceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Resource, &__uuidof(ID3D12Resource)>>                 ID3D12ResourceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12PipelineState, &__uuidof(ID3D12PipelineState)>>       ID3D12PipelineStateComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12CommandQueue, &__uuidof(ID3D12CommandQueue)>>         ID3D12CommandQueueComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12CommandAllocator, &__uuidof(ID3D12CommandAllocator)>> ID3D12CommandAllocatorComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12GraphicsCommandList, &__uuidof(ID3D12GraphicsCommandList)>>
    ID3D12GraphicsCommandListComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12GraphicsCommandList4, &__uuidof(ID3D12GraphicsCommandList4)>>
    ID3D12GraphicsCommandList4ComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12DeviceRemovedExtendedData1, &__uuidof(ID3D12DeviceRemovedExtendedData1)>>
    ID3D12DeviceRemovedExtendedData1ComPtr;
typedef _com_ptr_t<
    _com_IIID<ID3D12DeviceRemovedExtendedDataSettings1, &__uuidof(ID3D12DeviceRemovedExtendedDataSettings1)>>
                                                                   ID3D12DeviceRemovedExtendedDataSettings1ComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Debug, &__uuidof(ID3D12Debug)>> ID3D12DebugComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12StateObjectProperties, &__uuidof(ID3D12StateObjectProperties)>>
    ID3D12StateObjectPropertiesComPtr;
typedef _com_ptr_t<
    _com_IIID<ID3D12VersionedRootSignatureDeserializer, &__uuidof(ID3D12VersionedRootSignatureDeserializer)>>
    ID3D12VersionedRootSignatureDeserializerComPtr;

struct ActiveAdapterInfo
{
    format::DxgiAdapterDesc internal_desc;
    IDXGIAdapter*           adapter;
    UINT32                  adapter_idx;
    bool                    active;
};

typedef std::map<int64_t, ActiveAdapterInfo> ActiveAdapterMap;

struct ResourceStateInfo
{
    D3D12_RESOURCE_STATES        states{};
    D3D12_RESOURCE_BARRIER_FLAGS barrier_flags{};
};

const D3D12_RANGE kZeroRange = { 0, 0 };

// Take a screenshot
void TakeScreenshot(std::unique_ptr<gfxrecon::graphics::DX12ImageRenderer>& image_renderer,
                    ID3D12CommandQueue*                                     queue,
                    IDXGISwapChain*                                         swapchain,
                    uint32_t                                                frame_num,
                    const std::string&                                      filename_prefix);

// Maps a given sub resource and returns a pointer to the mapped region in data_ptr.
HRESULT MapSubresource(ID3D12Resource* resource, UINT subresource, const D3D12_RANGE* read_range, uint8_t*& data_ptr);

// Waits for the given queue to complete all pending tasks.
HRESULT WaitForQueue(ID3D12CommandQueue* queue, ID3D12Fence *fence  = nullptr, uint64_t fence_value = 0);

// Utility function to analyze DRED output.
// This function is meant to be called when device gets removed, to get extended debug information.
// For it to work, gfxrecon-replay must be launched with: --debug-device-lost
void AnalyzeDeviceRemoved(ID3D12Device* device);

ID3D12ResourceComPtr CreateBufferResource(ID3D12Device*         device,
                                          uint64_t              size,
                                          D3D12_HEAP_TYPE       heap_type,
                                          D3D12_RESOURCE_STATES initial_state,
                                          D3D12_RESOURCE_FLAGS  flags);

template <typename DeviceT>
auto GetDeviceComPtrFromChild(ID3D12DeviceChild* device_child)
{
    _com_ptr_t<_com_IIID<DeviceT, &__uuidof(DeviceT)>> device = nullptr;
    HRESULT                                            hr     = device_child->GetDevice(IID_PPV_ARGS(&device));
    GFXRECON_ASSERT(SUCCEEDED(hr))
    GFXRECON_ASSERT(device);
    return device;
}

struct InputsBufferEntry
{
    uint64_t                   offset{ 0 };      ///< Offset for the inputs data within the inputs buffer.
    D3D12_GPU_VIRTUAL_ADDRESS* desc_gpu_va{ 0 }; ///< Pointer to the desc's GPU VA that references this inputs data.
    uint64_t                   size{ 0 };        ///< Size of the inputs data in the inputs buffer.
};

// This function is used to compute the sizes and offsets of inputs used by BuildRayTracingAccelerationStructure. The
// inputs are stored on GPU resources and referenced by the INPUTS desc. A non-const D3D12_RAYTRACING_GEOMETRY_DESC*
// array must be provided as geometry_descs argument and will be referenced instead of
// inputs_desc.pGeometries/ppGeometries.
void GetAccelerationStructureInputsBufferEntries(D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& inputs_desc,
                                                 D3D12_RAYTRACING_GEOMETRY_DESC*                       geometry_descs,
                                                 uint64_t&                       inputs_buffer_size,
                                                 std::vector<InputsBufferEntry>& entries);

void TrackAdapters(HRESULT result, void** ppfactory, graphics::dx12::ActiveAdapterMap& adapters);

format::DxgiAdapterDesc* MarkActiveAdapter(ID3D12Device* device, graphics::dx12::ActiveAdapterMap& adapters);

bool IsSoftwareAdapter(const format::DxgiAdapterDesc& adapter_desc);

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_DX12_UTIL_H
