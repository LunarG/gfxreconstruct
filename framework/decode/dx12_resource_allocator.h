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

#ifndef GFXRECON_DECODE_DX12_RESOURCE_ALLOCATOR_H
#define GFXRECON_DECODE_DX12_RESOURCE_ALLOCATOR_H

#include "decode/handle_pointer_decoder.h"
#include "format/format.h"
#include "util/defines.h"
#include "graphics/dx12_util.h"
#include <d3d12.h>
#include <dxgi.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ResourceAllocator
{
  public:
    virtual ~Dx12ResourceAllocator() {}

    virtual HRESULT Initialize(const IUnknown* adapter, const void* pvDevice) = 0;

    virtual void Destroy() = 0;

    virtual HRESULT CreateHeap(format::HandleId            capture_id,
                               _In_ const D3D12_HEAP_DESC* pDesc,
                               REFIID                      riid,
                               _COM_Outptr_opt_ void**     ppvHeap) = 0;

    virtual HRESULT CreateHeap1(format::HandleId                         capture_id,
                                _In_ const D3D12_HEAP_DESC*              pDesc,
                                _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                REFIID                                   riid,
                                _COM_Outptr_opt_ void**                  ppvHeap) = 0;

    virtual HRESULT CreateCommittedResource(_In_ const D3D12_HEAP_PROPERTIES* pHeapProperties,
                                            D3D12_HEAP_FLAGS                  HeapFlags,
                                            _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                            D3D12_RESOURCE_STATES             InitialResourceState,
                                            _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                            REFIID                            riidResource,
                                            HandlePointerDecoder<void*>*      ppvResource) = 0;

    virtual HRESULT CreatePlacedResource(format::HandleId                  heap_capture_id,
                                         _In_ ID3D12Heap*                  pHeap,
                                         UINT64                            HeapOffset,
                                         _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                         D3D12_RESOURCE_STATES             InitialState,
                                         _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                         REFIID                            riid,
                                         HandlePointerDecoder<void*>*      ppvResource,
                                         UINT64                            max_aliasing_size) = 0;

    virtual HRESULT CreateReservedResource(_In_ const D3D12_RESOURCE_DESC*   pDesc,
                                           D3D12_RESOURCE_STATES             InitialState,
                                           _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                           REFIID                            riid,
                                           HandlePointerDecoder<void*>*      ppvResource) = 0;

    virtual HRESULT CreateCommittedResource1(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                             D3D12_HEAP_FLAGS                         HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC*          pDesc,
                                             D3D12_RESOURCE_STATES                    InitialResourceState,
                                             _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                             REFIID                                   riidResource,
                                             HandlePointerDecoder<void*>*             ppvResource) = 0;

    virtual HRESULT CreatePlacedResource1(format::HandleId                  heap_capture_id,
                                          _In_ ID3D12Heap*                  pHeap,
                                          UINT64                            HeapOffset,
                                          _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                          D3D12_RESOURCE_STATES             InitialState,
                                          _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                          REFIID                            riid,
                                          HandlePointerDecoder<void*>*      ppvResource,
                                          UINT64                            max_aliasing_size) = 0;

    virtual HRESULT CreateReservedResource1(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                            D3D12_RESOURCE_STATES                    InitialState,
                                            _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                            _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                            REFIID                                   riid,
                                            HandlePointerDecoder<void*>*             ppvResource) = 0;

    virtual HRESULT CreateCommittedResource2(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                             D3D12_HEAP_FLAGS                         HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                             D3D12_RESOURCE_STATES                    InitialResourceState,
                                             _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                             REFIID                                   riidResource,
                                             HandlePointerDecoder<void*>*             ppvResource) = 0;

    virtual HRESULT CreatePlacedResource2(format::HandleId                                      heap_capture_id,
                                          _In_ ID3D12Heap*                                      pHeap,
                                          UINT64                                                HeapOffset,
                                          _In_ const D3D12_RESOURCE_DESC1*                      pDesc,
                                          D3D12_BARRIER_LAYOUT                                  InitialLayout,
                                          _In_opt_ const D3D12_CLEAR_VALUE*                     pOptimizedClearValue,
                                          UINT32                                                NumCastableFormats,
                                          _In_opt_count_(NumCastableFormats) const DXGI_FORMAT* pCastableFormats,
                                          REFIID                                                riid,
                                          HandlePointerDecoder<void*>*                          ppvResource,
                                          UINT64                                                max_aliasing_size) = 0;

    virtual HRESULT CreateReservedResource2(_In_ const D3D12_RESOURCE_DESC*                       pDesc,
                                            D3D12_BARRIER_LAYOUT                                  InitialLayout,
                                            _In_opt_ const D3D12_CLEAR_VALUE*                     pOptimizedClearValue,
                                            _In_opt_ ID3D12ProtectedResourceSession*              pProtectedSession,
                                            UINT32                                                NumCastableFormats,
                                            _In_opt_count_(NumCastableFormats) const DXGI_FORMAT* pCastableFormats,
                                            REFIID                                                riid,
                                            HandlePointerDecoder<void*>*                          ppvResource) = 0;

    virtual HRESULT CreateCommittedResource3(_In_ const D3D12_HEAP_PROPERTIES*                     pHeapProperties,
                                             D3D12_HEAP_FLAGS                                      HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC1*                      pDesc,
                                             D3D12_BARRIER_LAYOUT                                  InitialLayout,
                                             _In_opt_ const D3D12_CLEAR_VALUE*                     pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession*              pProtectedSession,
                                             UINT32                                                NumCastableFormats,
                                             _In_opt_count_(NumCastableFormats) const DXGI_FORMAT* pCastableFormats,
                                             REFIID                                                riidResource,
                                             HandlePointerDecoder<void*>*                          ppvResource) = 0;

    virtual HRESULT SetResidencyPriority(UINT                                   NumObjects,
                                         HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
                                         const D3D12_RESIDENCY_PRIORITY*        pPriorities) = 0;

    virtual void GetResourceTiling(_In_ ID3D12Resource*             pTiledResource,
                                   _Out_opt_ UINT*                  pNumTilesForEntireResource,
                                   _Out_opt_ D3D12_PACKED_MIP_INFO* pPackedMipDesc,
                                   _Out_opt_ D3D12_TILE_SHAPE*      pStandardTileShapeForNonPackedMips,
                                   _Inout_opt_ UINT*                pNumSubresourceTilings,
                                   _In_ UINT                        FirstSubresourceTilingToGet,
                                   _Out_ D3D12_SUBRESOURCE_TILING*  pSubresourceTilingsForNonPackedMips) = 0;

    virtual void UpdateTileMappings(ID3D12CommandQueue*  pQueue,
                                    format::HandleId     resource_capture_id,
                                    format::HandleId     heap_capture_id,
                                    _In_ ID3D12Resource* pResource,
                                    UINT                 NumResourceRegions,
                                    _In_reads_opt_(NumResourceRegions)
                                        const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
                                    _In_reads_opt_(NumResourceRegions)
                                        const D3D12_TILE_REGION_SIZE*                       pResourceRegionSizes,
                                    _In_opt_ ID3D12Heap*                                    pHeap,
                                    UINT                                                    NumRanges,
                                    _In_reads_opt_(NumRanges) const D3D12_TILE_RANGE_FLAGS* pRangeFlags,
                                    _In_reads_opt_(NumRanges) const UINT*                   pHeapRangeStartOffsets,
                                    _In_reads_opt_(NumRanges) const UINT*                   pRangeTileCounts,
                                    D3D12_TILE_MAPPING_FLAGS                                Flags) = 0;

    virtual void CopyTileMappings(ID3D12CommandQueue*                             pQueue,
                                  format::HandleId                                dst_resource_capture_id,
                                  _In_ ID3D12Resource*                            pDstResource,
                                  format::HandleId                                src_resource_capture_id,
                                  _In_ ID3D12Resource*                            pSrcResource,
                                  _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
                                  _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
                                  _In_opt_ const D3D12_TILE_REGION_SIZE*          pRegionSize,
                                  D3D12_TILE_MAPPING_FLAGS                        Flags) = 0;

    virtual void CopyTiles(ID3D12GraphicsCommandList*                      pList,
                           format::HandleId                                resource_capture_id,
                           _In_ ID3D12Resource*                            pResource,
                           _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
                           _In_opt_ const D3D12_TILE_REGION_SIZE*          pTileRegionSize,
                           format::HandleId                                buffer_capture_id,
                           _In_ ID3D12Resource*                            pBuffer,
                           UINT64                                          BufferStartOffsetInBytes,
                           D3D12_TILE_COPY_FLAGS                           Flags) = 0;

    virtual bool SupportD3D12MemoryAllocator() = 0;

    virtual ULONG Release(IUnknown* object, format::HandleId object_id) = 0;

    virtual void PostPresent() = 0;

    virtual void ReportResourceIncompatibility(const D3D12_RESOURCE_DESC* resource_desc) = 0;

    virtual void ReportResourceIncompatibility1(const D3D12_RESOURCE_DESC1* resource_desc) = 0;

    virtual bool IsAliasingResourcePairs(const format::HandleId resource_before_id,
                                         const format::HandleId resource_after_id) = 0;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_RESOURCE_ALLOCATOR_H
