/*
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

#include "util/defines.h"
#include "decode/dx12_tracking_consumer.h"

#include <algorithm>
#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: all functions are declared as skeletons,
// need to fill up the functions body to do resources tracking

DX12TrackingConsumer::DX12TrackingConsumer(const DxReplayOptions&      options,
                                           Dx12TrackedObjectInfoTable* tracked_object_info_table) :
    options_(options),
    tracked_object_info_table_(tracked_object_info_table)
{
    assert(tracked_object_info_table != nullptr);
}

DX12TrackingConsumer::~DX12TrackingConsumer() {}

void DX12TrackingConsumer::ProcessFillMemoryCommand(uint64_t       memory_id,
                                                    uint64_t       offset,
                                                    uint64_t       size,
                                                    const uint8_t* data)
{}

void DX12TrackingConsumer::Process_CreateDXGIFactory1(HRESULT                      returnValue,
                                                      Decoded_GUID                 riid,
                                                      HandlePointerDecoder<void*>* ppFactory)
{}

void DX12TrackingConsumer::Process_CreateDXGIFactory2(HRESULT                      returnValue,
                                                      UINT                         Flags,
                                                      Decoded_GUID                 riid,
                                                      HandlePointerDecoder<void*>* ppFactory)
{}

void DX12TrackingConsumer::Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                                    HRESULT          original_result,
                                                                    D3D12_FEATURE    feature,
                                                                    const void*      capture_feature_data,
                                                                    void*            replay_feature_data,
                                                                    UINT             feature_data_size)
{}

void DX12TrackingConsumer::Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                                     HRESULT          original_result,
                                                                     DXGI_FEATURE     feature,
                                                                     const void*      capture_feature_data,
                                                                     void*            replay_feature_data,
                                                                     UINT             feature_data_size)
{}

void DX12TrackingConsumer::Process_IDXGIFactory_EnumAdapters(format::HandleId                     object_id,
                                                             HRESULT                              returnValue,
                                                             UINT                                 Adapter,
                                                             HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{}

void DX12TrackingConsumer::Process_D3D12CreateDevice(HRESULT                      returnValue,
                                                     format::HandleId             pAdapter,
                                                     D3D_FEATURE_LEVEL            MinimumFeatureLevel,
                                                     Decoded_GUID                 riid,
                                                     HandlePointerDecoder<void*>* ppDevice)
{}

void DX12TrackingConsumer::Process_ID3D12Device_CreateCommittedResource(
    format::HandleId                                     object_id,
    HRESULT                                              returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                                     HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>*   pDesc,
    D3D12_RESOURCE_STATES                                InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*     pOptimizedClearValue,
    Decoded_GUID                                         riidResource,
    HandlePointerDecoder<void*>*                         ppvResource)
{}

void DX12TrackingConsumer::Process_ID3D12Device_CreateHeap(format::HandleId                               object_id,
                                                           HRESULT                                        returnValue,
                                                           StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
                                                           Decoded_GUID                                   riid,
                                                           HandlePointerDecoder<void*>*                   ppvHeap)
{}

void DX12TrackingConsumer::Process_ID3D12Device_CreatePlacedResource(
    format::HandleId                                   object_id,
    HRESULT                                            returnValue,
    format::HandleId                                   pHeap,
    UINT64                                             HeapOffset,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                              InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   pOptimizedClearValue,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       ppvResource)
{}

void DX12TrackingConsumer::Process_ID3D12Device_CreateReservedResource(
    format::HandleId                                   object_id,
    HRESULT                                            returnValue,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                              InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>*   pOptimizedClearValue,
    Decoded_GUID                                       riid,
    HandlePointerDecoder<void*>*                       ppvResource)
{}

void DX12TrackingConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId                                   object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO             returnValue,
    UINT                                               visibleMask,
    UINT                                               numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
