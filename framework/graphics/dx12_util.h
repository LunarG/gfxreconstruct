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
#include "util/platform.h"
#include "graphics/dx12_image_renderer.h"

#include <comdef.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

typedef _com_ptr_t<_com_IIID<IDXGISwapChain3, &__uuidof(IDXGISwapChain3)>> IDXGISwapChain3ComPtr;

typedef _com_ptr_t<_com_IIID<ID3D12DescriptorHeap, &__uuidof(ID3D12DescriptorHeap)>>     ID3D12DescriptorHeapComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Device, &__uuidof(ID3D12Device)>>                     ID3D12DeviceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Fence, &__uuidof(ID3D12Fence)>>                       ID3D12FenceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Resource, &__uuidof(ID3D12Resource)>>                 ID3D12ResourceComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12PipelineState, &__uuidof(ID3D12PipelineState)>>       ID3D12PipelineStateComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12CommandQueue, &__uuidof(ID3D12CommandQueue)>>         ID3D12CommandQueueComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12CommandAllocator, &__uuidof(ID3D12CommandAllocator)>> ID3D12CommandAllocatorComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12GraphicsCommandList, &__uuidof(ID3D12GraphicsCommandList)>>
    ID3D12GraphicsCommandListComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12DeviceRemovedExtendedData1, &__uuidof(ID3D12DeviceRemovedExtendedData1)>>
ID3D12DeviceRemovedExtendedData1ComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12DeviceRemovedExtendedDataSettings1, &__uuidof(ID3D12DeviceRemovedExtendedDataSettings1)>>
ID3D12DeviceRemovedExtendedDataSettings1ComPtr;
typedef _com_ptr_t<_com_IIID<ID3D12Debug, &__uuidof(ID3D12Debug)>> ID3D12DebugComPtr;

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
HRESULT WaitForQueue(ID3D12CommandQueue* queue);

// Utility function to analyze DRED output. 
// This function is meant to be called when device gets removed, to get extended debug information.
// For it to work, gfxrecon-replay must be launched with: --debug-device-lost
void AnalyzeDeviceRemoved(ID3D12Device* device);

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_DX12_UTIL_H
