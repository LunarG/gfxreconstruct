/*
** Copyright (c) 2020-2025 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "decode/dx12_default_allocator.h"
#include "graphics/dx12_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12DefaultAllocator::Dx12DefaultAllocator() : device_(nullptr) {}

Dx12DefaultAllocator::Dx12DefaultAllocator(const std::string& custom_error_string) :
    device_(nullptr), custom_error_string_(custom_error_string)
{}

Dx12DefaultAllocator::Dx12DefaultAllocator(std::string&& custom_error_string) :
    device_(nullptr), custom_error_string_(std::move(custom_error_string))
{}

HRESULT Dx12DefaultAllocator::Initialize(const IUnknown* adapter, const void* pvDevice)
{
    GFXRECON_UNREFERENCED_PARAMETER(adapter);

    device_ = reinterpret_cast<ID3D12Device*>(const_cast<void*>(pvDevice));

    return S_OK;
}

void Dx12DefaultAllocator::Destroy()
{
    device_ = nullptr;
}

void Dx12DefaultAllocator::ReportResourceIncompatibility(const D3D12_RESOURCE_DESC* resource_desc)
{
    D3D12_RESOURCE_ALLOCATION_INFO  alloc_info  = {};
    D3D12_RESOURCE_ALLOCATION_INFO1 alloc_info1 = {};

    if (device_ != nullptr && resource_desc != nullptr)
    {
        graphics::dx12::ID3D12Device4ComPtr device4;
        device_->QueryInterface(IID_PPV_ARGS(&device4));

        if (device4 != nullptr)
        {
            device4->GetResourceAllocationInfo1(0, 1, resource_desc, &alloc_info1);
            alloc_info.SizeInBytes = alloc_info1.SizeInBytes;
            alloc_info.Alignment   = alloc_info1.Alignment;
        }
        else
        {
            alloc_info = device_->GetResourceAllocationInfo(0, 1, resource_desc);
        }

        if (alloc_info.Alignment && resource_desc->Alignment && alloc_info.Alignment != resource_desc->Alignment)
        {
            GFXRECON_LOG_WARNING("The captured resource may be incompatible with the replayed device!");

            if (!custom_error_string_.empty())
            {
                GFXRECON_LOG_WARNING("%s", custom_error_string_.c_str());
            }
        }
    }
}

void Dx12DefaultAllocator::ReportResourceIncompatibility1(const D3D12_RESOURCE_DESC1* resource_desc)
{
    D3D12_RESOURCE_ALLOCATION_INFO  alloc_info  = {};
    D3D12_RESOURCE_ALLOCATION_INFO1 alloc_info1 = {};

    if (device_ != nullptr && resource_desc != nullptr)
    {
        graphics::dx12::ID3D12Device8ComPtr device8;
        device_->QueryInterface(IID_PPV_ARGS(&device8));

        if (device8 != nullptr)
        {
            device8->GetResourceAllocationInfo2(0, 1, resource_desc, &alloc_info1);
            alloc_info.SizeInBytes = alloc_info1.SizeInBytes;
            alloc_info.Alignment   = alloc_info1.Alignment;
        }
        else
        {
            D3D12_RESOURCE_DESC* desc =
                reinterpret_cast<D3D12_RESOURCE_DESC*>(const_cast<D3D12_RESOURCE_DESC1*>(resource_desc));
            alloc_info = device_->GetResourceAllocationInfo(0, 1, desc);
        }

        if (alloc_info.Alignment && resource_desc->Alignment && alloc_info.Alignment != resource_desc->Alignment)
        {
            GFXRECON_LOG_WARNING("The captured resource may be incompatible with the replayed device!");

            if (!custom_error_string_.empty())
            {
                GFXRECON_LOG_WARNING("%s", custom_error_string_.c_str());
            }
        }
    }
}

HRESULT Dx12DefaultAllocator::CreateHeap(format::HandleId            capture_id,
                                         _In_ const D3D12_HEAP_DESC* pDesc,
                                         REFIID                      riid,
                                         _COM_Outptr_opt_ void**     ppvHeap)
{
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    HRESULT result = S_FALSE;
    result         = device_->CreateHeap(pDesc, riid, ppvHeap);
    return result;
}

HRESULT Dx12DefaultAllocator::CreateHeap1(format::HandleId                         capture_id,
                                          _In_ const D3D12_HEAP_DESC*              pDesc,
                                          _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                          REFIID                                   riid,
                                          _COM_Outptr_opt_ void**                  ppvHeap)
{
    GFXRECON_UNREFERENCED_PARAMETER(capture_id);

    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device4ComPtr device4;
    device_->QueryInterface(IID_PPV_ARGS(&device4));
    result = device4->CreateHeap1(pDesc, pProtectedSession, riid, ppvHeap);

    return result;
}

HRESULT Dx12DefaultAllocator::CreateCommittedResource(_In_ const D3D12_HEAP_PROPERTIES* pHeapProperties,
                                                      D3D12_HEAP_FLAGS                  HeapFlags,
                                                      _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                      D3D12_RESOURCE_STATES             InitialResourceState,
                                                      _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                      REFIID                            riidResource,
                                                      HandlePointerDecoder<void*>*      ppvResource)
{
    HRESULT result = S_FALSE;
    ReportResourceIncompatibility(pDesc);
    result = device_->CreateCommittedResource(pHeapProperties,
                                              HeapFlags,
                                              pDesc,
                                              InitialResourceState,
                                              pOptimizedClearValue,
                                              riidResource,
                                              ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreatePlacedResource(format::HandleId                  heap_capture_id,
                                                   _In_ ID3D12Heap*                  pHeap,
                                                   UINT64                            HeapOffset,
                                                   _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                   D3D12_RESOURCE_STATES             InitialState,
                                                   _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                   REFIID                            riid,
                                                   HandlePointerDecoder<void*>*      ppvResource,
                                                   UINT64                            max_aliasing_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(max_aliasing_size);

    HRESULT result = S_FALSE;
    ReportResourceIncompatibility(pDesc);
    result = device_->CreatePlacedResource(
        pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource->GetHandlePointer());
    return result;
}

HRESULT Dx12DefaultAllocator::CreateReservedResource(_In_ const D3D12_RESOURCE_DESC*   pDesc,
                                                     D3D12_RESOURCE_STATES             InitialState,
                                                     _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                     REFIID                            riid,
                                                     HandlePointerDecoder<void*>*      ppvResource)
{
    HRESULT result = S_FALSE;
    ReportResourceIncompatibility(pDesc);
    result = device_->CreateReservedResource(
        pDesc, InitialState, pOptimizedClearValue, riid, ppvResource->GetHandlePointer());
    return result;
}

HRESULT Dx12DefaultAllocator::CreateCommittedResource1(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                       D3D12_HEAP_FLAGS                         HeapFlags,
                                                       _In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                       D3D12_RESOURCE_STATES                    InitialResourceState,
                                                       _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                       _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                       REFIID                                   riidResource,
                                                       HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device4ComPtr device4;
    device_->QueryInterface(IID_PPV_ARGS(&device4));
    ReportResourceIncompatibility(pDesc);
    result = device4->CreateCommittedResource1(pHeapProperties,
                                               HeapFlags,
                                               pDesc,
                                               InitialResourceState,
                                               pOptimizedClearValue,
                                               pProtectedSession,
                                               riidResource,
                                               ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreatePlacedResource1(format::HandleId                  heap_capture_id,
                                                    _In_ ID3D12Heap*                  pHeap,
                                                    UINT64                            HeapOffset,
                                                    _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                                    D3D12_RESOURCE_STATES             InitialState,
                                                    _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                    REFIID                            riid,
                                                    HandlePointerDecoder<void*>*      ppvResource,
                                                    UINT64                            max_aliasing_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(max_aliasing_size);

    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device8ComPtr device8;
    device_->QueryInterface(IID_PPV_ARGS(&device8));
    ReportResourceIncompatibility1(pDesc);
    result = device8->CreatePlacedResource1(
        pHeap, HeapOffset, pDesc, InitialState, pOptimizedClearValue, riid, ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreateReservedResource1(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                      D3D12_RESOURCE_STATES                    InitialState,
                                                      _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                      _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                      REFIID                                   riid,
                                                      HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device4ComPtr device4;
    device_->QueryInterface(IID_PPV_ARGS(&device4));
    ReportResourceIncompatibility(pDesc);
    result = device4->CreateReservedResource1(
        pDesc, InitialState, pOptimizedClearValue, pProtectedSession, riid, ppvResource->GetHandlePointer());
    return result;
}

HRESULT Dx12DefaultAllocator::CreateCommittedResource2(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                       D3D12_HEAP_FLAGS                         HeapFlags,
                                                       _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                                       D3D12_RESOURCE_STATES                    InitialResourceState,
                                                       _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                       _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                       REFIID                                   riidResource,
                                                       HandlePointerDecoder<void*>*             ppvResource)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device8ComPtr device8;
    device_->QueryInterface(IID_PPV_ARGS(&device8));
    ReportResourceIncompatibility1(pDesc);
    result = device8->CreateCommittedResource2(pHeapProperties,
                                               HeapFlags,
                                               pDesc,
                                               InitialResourceState,
                                               pOptimizedClearValue,
                                               pProtectedSession,
                                               riidResource,
                                               ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreatePlacedResource2(format::HandleId                  heap_capture_id,
                                                    _In_ ID3D12Heap*                  pHeap,
                                                    UINT64                            HeapOffset,
                                                    _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                                    D3D12_BARRIER_LAYOUT              InitialLayout,
                                                    _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                                    UINT32                            NumCastableFormats,
                                                    _In_opt_count_(NumCastableFormats)
                                                        const DXGI_FORMAT*       pCastableFormats,
                                                    REFIID                       riid,
                                                    HandlePointerDecoder<void*>* ppvResource,
                                                    UINT64                       max_aliasing_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(heap_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(max_aliasing_size);

    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device10ComPtr device10;
    device_->QueryInterface(IID_PPV_ARGS(&device10));
    ReportResourceIncompatibility1(pDesc);
    result = device10->CreatePlacedResource2(pHeap,
                                             HeapOffset,
                                             pDesc,
                                             InitialLayout,
                                             pOptimizedClearValue,
                                             NumCastableFormats,
                                             pCastableFormats,
                                             riid,
                                             ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreateReservedResource2(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                                      D3D12_BARRIER_LAYOUT                     InitialLayout,
                                                      _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                      _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                      UINT32                                   NumCastableFormats,
                                                      _In_opt_count_(NumCastableFormats)
                                                          const DXGI_FORMAT*       pCastableFormats,
                                                      REFIID                       riid,
                                                      HandlePointerDecoder<void*>* ppvResource)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device10ComPtr device10;
    device_->QueryInterface(IID_PPV_ARGS(&device10));
    ReportResourceIncompatibility(pDesc);
    result = device10->CreateReservedResource2(pDesc,
                                               InitialLayout,
                                               pOptimizedClearValue,
                                               pProtectedSession,
                                               NumCastableFormats,
                                               pCastableFormats,
                                               riid,
                                               ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::CreateCommittedResource3(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                                       D3D12_HEAP_FLAGS                         HeapFlags,
                                                       _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                                       D3D12_BARRIER_LAYOUT                     InitialLayout,
                                                       _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                                       _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                                       UINT32                                   NumCastableFormats,
                                                       _In_opt_count_(NumCastableFormats)
                                                           const DXGI_FORMAT*       pCastableFormats,
                                                       REFIID                       riidResource,
                                                       HandlePointerDecoder<void*>* ppvResource)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device10ComPtr device10;
    device_->QueryInterface(IID_PPV_ARGS(&device10));
    ReportResourceIncompatibility1(pDesc);
    result = device10->CreateCommittedResource3(pHeapProperties,
                                                HeapFlags,
                                                pDesc,
                                                InitialLayout,
                                                pOptimizedClearValue,
                                                pProtectedSession,
                                                NumCastableFormats,
                                                pCastableFormats,
                                                riidResource,
                                                ppvResource->GetHandlePointer());

    return result;
}

HRESULT Dx12DefaultAllocator::SetResidencyPriority(UINT                                   NumObjects,
                                                   HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
                                                   const D3D12_RESIDENCY_PRIORITY*        pPriorities)
{
    HRESULT result = S_FALSE;

    graphics::dx12::ID3D12Device1ComPtr device1;
    device_->QueryInterface(IID_PPV_ARGS(&device1));

    if (device1 != nullptr)
    {
        result = device1->SetResidencyPriority(NumObjects, ppObjects->GetHandlePointer(), pPriorities);
    }

    return result;
}

void Dx12DefaultAllocator::GetResourceTiling(_In_ ID3D12Resource*             pTiledResource,
                                             _Out_opt_ UINT*                  pNumTilesForEntireResource,
                                             _Out_opt_ D3D12_PACKED_MIP_INFO* pPackedMipDesc,
                                             _Out_opt_ D3D12_TILE_SHAPE*      pStandardTileShapeForNonPackedMips,
                                             _Inout_opt_ UINT*                pNumSubresourceTilings,
                                             _In_ UINT                        FirstSubresourceTilingToGet,
                                             _Out_ D3D12_SUBRESOURCE_TILING*  pSubresourceTilingsForNonPackedMips)
{
    device_->GetResourceTiling(pTiledResource,
                               pNumTilesForEntireResource,
                               pPackedMipDesc,
                               pStandardTileShapeForNonPackedMips,
                               pNumSubresourceTilings,
                               FirstSubresourceTilingToGet,
                               pSubresourceTilingsForNonPackedMips);
}

void Dx12DefaultAllocator::UpdateTileMappings(ID3D12CommandQueue*                    pQueue,
                                              format::HandleId                       resource_capture_id,
                                              format::HandleId                       heap_capture_id,
                                              ID3D12Resource*                        pResource,
                                              UINT                                   NumResourceRegions,
                                              const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
                                              const D3D12_TILE_REGION_SIZE*          pResourceRegionSizes,
                                              ID3D12Heap*                            pHeap,
                                              UINT                                   NumRanges,
                                              const D3D12_TILE_RANGE_FLAGS*          pRangeFlags,
                                              const UINT*                            pHeapRangeStartOffsets,
                                              const UINT*                            pRangeTileCounts,
                                              D3D12_TILE_MAPPING_FLAGS               Flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(resource_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(heap_capture_id);

    pQueue->UpdateTileMappings(pResource,
                               NumResourceRegions,
                               pResourceRegionStartCoordinates,
                               pResourceRegionSizes,
                               pHeap,
                               NumRanges,
                               pRangeFlags,
                               pHeapRangeStartOffsets,
                               pRangeTileCounts,
                               Flags);
}

void Dx12DefaultAllocator::CopyTileMappings(ID3D12CommandQueue*                    pQueue,
                                            format::HandleId                       dst_resource_capture_id,
                                            ID3D12Resource*                        pDstResource,
                                            format::HandleId                       src_resource_capture_id,
                                            ID3D12Resource*                        pSrcResource,
                                            const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
                                            const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
                                            const D3D12_TILE_REGION_SIZE*          pRegionSize,
                                            D3D12_TILE_MAPPING_FLAGS               Flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(dst_resource_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(src_resource_capture_id);

    pQueue->CopyTileMappings(
        pDstResource, pDstRegionStartCoordinate, pSrcResource, pSrcRegionStartCoordinate, pRegionSize, Flags);
}

void Dx12DefaultAllocator::CopyTiles(ID3D12GraphicsCommandList*             pList,
                                     format::HandleId                       resource_capture_id,
                                     ID3D12Resource*                        pResource,
                                     const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
                                     const D3D12_TILE_REGION_SIZE*          pTileRegionSize,
                                     format::HandleId                       buffer_capture_id,
                                     ID3D12Resource*                        pBuffer,
                                     UINT64                                 BufferStartOffsetInBytes,
                                     D3D12_TILE_COPY_FLAGS                  Flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(resource_capture_id);
    GFXRECON_UNREFERENCED_PARAMETER(buffer_capture_id);
    pList->CopyTiles(pResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
