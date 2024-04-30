/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#include "util/defines.h"
#include "util/logging.h"
#include "util/options.h"
#include "util/platform.h"
#ifdef WIN32
#include "graphics/dx12_image_renderer.h"
#else
#include "format/platform_types.h"
#endif
#include "format/format.h"

#ifdef WIN32
#include <comdef.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#endif
#include <vector>
#include <unordered_map>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

#ifdef WIN32
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
typedef _com_ptr_t<_com_IIID<ID3D12Object, &__uuidof(ID3D12Object)>> ID3D12ObjectComPtr;
#endif

struct ActiveAdapterInfo
{
    format::DxgiAdapterDesc internal_desc;
    IDXGIAdapter*           adapter;
    UINT32                  adapter_idx;
    bool                    active;
};

typedef std::map<int64_t, ActiveAdapterInfo> ActiveAdapterMap;

static const uint8_t  kAdapterTypeMask  = 0x3;
static const uint32_t kAdapterTypeShift = 0;
static const uint32_t kAdapterIdMask    = 0xFFFFFFFc;
static const uint32_t kAdapterIdShift   = 2;

struct AdapterSubmissionMapping
{
    std::unordered_map<format::HandleId, format::HandleId> queue_to_device_map;
    std::unordered_map<format::HandleId, format::HandleId> device_to_adapter_map;
    std::unordered_map<format::HandleId, int64_t>          adapter_to_luid_map;
    std::unordered_map<format::HandleId, uint64_t>         adapter_submit_counts;
};

struct ResourceStateInfo
{
    D3D12_RESOURCE_STATES        states{};
    D3D12_RESOURCE_BARRIER_FLAGS barrier_flags{};
};

const D3D12_RANGE kZeroRange       = { 0, 0 };
const double      kMemoryTolerance = 2.1;

#ifdef WIN32
// Take a screenshot
void TakeScreenshot(std::unique_ptr<gfxrecon::graphics::DX12ImageRenderer>& image_renderer,
                    ID3D12CommandQueue*                                     queue,
                    IDXGISwapChain*                                         swapchain,
                    uint32_t                                                frame_num,
                    const std::string&                                      filename_prefix,
                    gfxrecon::util::ScreenshotFormat                        screenshot_format);

// Maps a given sub resource and returns a pointer to the mapped region in data_ptr.
HRESULT MapSubresource(ID3D12Resource*    resource,
                       UINT               subresource,
                       const D3D12_RANGE* read_range,
                       uint8_t*&          data_ptr,
                       bool               is_texture_with_unknown_layout = false);

// Waits for the given queue to complete all pending tasks.
HRESULT WaitForQueue(ID3D12CommandQueue* queue, ID3D12Fence* fence = nullptr, uint64_t fence_value = 0);

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

// Get one pixel byte size for specific DXGI_FORMAT. The function is used by GetOneRowSizeByDXGIFormat
// function.
// Note: The function only support the formats for which one pixel has one or multiple bytes.
//       For those formats which are comppreesed types, or one pixel has bits that
//       are not one or multiple bytes such as DXGI_FORMAT_R1_UNORM, DXGI_FORMAT_BC1_TYPELESS,
//       they are not supported and the return value will be zero.
uint64_t GetSubresourcePixelByteSize(DXGI_FORMAT format);

// Get one row unpadded byte size by DXGIFormat.
// Note: The function only support the formats for which one pixel has one or multiple bytes.
//       For those formats which are not supported, the return value will be zero.
//       For these unsupported formats, another GetOneRowSizeByDXGIFormat function can be used
//       to query the one row unpadded size through inserting some API calls.
uint64_t GetOneRowSizeByDXGIFormat(DXGI_FORMAT format, UINT width);

// Get one row unpadded byte size by DXGIFormat.
// Note: The function support all formats in DXGI_FORMAT. It first use the function
//       GetOneRowSizeByDXGIFormat(DXGI_FORMAT Format, UINT width) to calculate the
//       size, if the format is not supported (like one pixel has 1 bit, 4 bits
//       or comppreesed types), the function will query the size through inserting
//       some API calls.
uint64_t GetOneRowSizeByDXGIFormat(ID3D12Resource*      resource,
                                   D3D12_RESOURCE_DESC* resource_desc,
                                   UINT                 dst_subresource,
                                   uint64_t             width);

// Get the size of writing data for a subresource for API ID3D12Resource::WriteToSubresource.
// The parameters DstSubresource, pDstBox, SrcRowPitch and SrcDepthPitch are same with their
// meaning in this API.
uint64_t GetSubresourceWriteDataSize(
    ID3D12Resource* resource, UINT dst_subresource, const D3D12_BOX* dst_box, UINT src_row_pitch, UINT src_depth_pitch);

void TrackAdapters(HRESULT result, void** ppfactory, graphics::dx12::ActiveAdapterMap& adapters);

void RemoveDeactivatedAdapters(graphics::dx12::ActiveAdapterMap& adapters);

format::DxgiAdapterDesc* MarkActiveAdapter(ID3D12Device* device, graphics::dx12::ActiveAdapterMap& adapters);

// Query adapter and index by LUID
bool GetAdapterAndIndexbyLUID(LUID                              luid,
                              IDXGIAdapter*&                    adapter_ptr,
                              uint32_t&                         index,
                              graphics::dx12::ActiveAdapterMap& adapters);

// Get list of active adapters
void GetActiveAdapterLuids(graphics::dx12::ActiveAdapterMap adapters, std::vector<LUID>& adapter_luids);

// Qeury the D3D12Device's IDXGIAdatper3 interface and the adapter's index
bool GetAdapterAndIndexbyDevice(ID3D12Device*                     device,
                                IDXGIAdapter3*&                   adapter3_ptr,
                                uint32_t&                         index,
                                graphics::dx12::ActiveAdapterMap& adapters);

format::DxgiAdapterDesc* GetAdapterDescByLUID(LUID parent_adapter_luid, graphics::dx12::ActiveAdapterMap& adapters);

// Get the adapter at specified index
IDXGIAdapter* GetAdapterbyIndex(graphics::dx12::ActiveAdapterMap& adapters, int32_t index);

// Returns whether the device passed represents a unified memory architecture
// (UMA) GPU as with most integrated graphics / APUs and mobile SOCs.
// The pointer is assumed to be valid.
// If the underlying D3D call fails, the function will also return false and the
// error will be logged.
bool IsUma(ID3D12Device* device);

// This function is used to get available GPU virtual memory.
// The input is current adapter which created current device.
uint64_t GetAvailableGpuAdapterMemory(IDXGIAdapter3* adapter, double max_usage, bool is_uma);

// This function is used to get available CPU memory.
uint64_t GetAvailableCpuMemory(double max_usage);

// Give require memory size to check if there are enough CPU&GPU memory to allocate the resource. If max_cpu_mem_usage
// > 1.0, the result is not limited by available physical memory.
bool IsMemoryAvailable(uint64_t requried_memory, IDXGIAdapter3* adapter, double max_mem_usage, bool is_uma);

// Get GPU memory usage by resource desc
uint64_t GetResourceSizeInBytes(ID3D12Device* device, const D3D12_RESOURCE_DESC* desc);
uint64_t GetResourceSizeInBytes(ID3D12Device8* device, const D3D12_RESOURCE_DESC1* desc);
#endif

bool IsSoftwareAdapter(const format::DxgiAdapterDesc& adapter_desc);

bool IsDepthStencilFormat(const DXGI_FORMAT format);

bool IsTextureWithUnknownLayout(D3D12_RESOURCE_DIMENSION dimension, D3D12_TEXTURE_LAYOUT layout);

bool VerifyAgilitySDKRuntime();

inline void InjectAdapterCaptureId(uint32_t& extra_info, format::HandleId capture_id)
{
    extra_info &= ~(kAdapterIdMask);
    extra_info |= static_cast<format::HandleId>(capture_id) << kAdapterIdShift;
}

inline void InjectAdapterType(uint32_t& extra_info, format::AdapterType type)
{
    extra_info &= ~(kAdapterTypeMask);
    extra_info |= static_cast<format::AdapterType>(type) << kAdapterTypeShift;
}

inline format::HandleId ExtractAdapterCaptureId(uint32_t extra_info)
{
    return static_cast<format::HandleId>((extra_info & kAdapterIdMask) >> kAdapterIdShift);
}

inline format::AdapterType ExtractAdapterType(uint32_t extra_info)
{
    return static_cast<format::AdapterType>((extra_info & kAdapterTypeMask));
}

#ifdef WIN32
void RobustGetCopyableFootprint(ID3D12Device*                       device,
                                ID3D12Resource*                     resource,
                                const D3D12_RESOURCE_DESC*          pResourceDesc,
                                UINT                                FirstSubresource,
                                UINT                                NumSubresources,
                                UINT64                              BaseOffset,
                                D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
                                UINT*                               pNumRows,
                                UINT64*                             pRowSizeInBytes,
                                UINT64*                             pTotalBytes);
#endif

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) || defined(ENABLE_OPENXR_SUPPORT)

#endif // GFXRECON_GRAPHICS_DX12_UTIL_H
