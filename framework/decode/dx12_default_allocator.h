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

#ifndef GFXRECON_DECODE_DX12_DEFAULT_ALLOCATOR_H
#define GFXRECON_DECODE_DX12_DEFAULT_ALLOCATOR_H

#include "decode/dx12_resource_allocator.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12DefaultAllocator : public Dx12ResourceAllocator
{
  public:
    Dx12DefaultAllocator();

    Dx12DefaultAllocator(const std::string& custom_error_string);

    Dx12DefaultAllocator(std::string&& custom_error_string);

    virtual HRESULT Initialize(const IUnknown* adapter, const void* pvDevice) override;

    virtual void Destroy() override;

    virtual HRESULT CreateHeap(format::HandleId            capture_id,
                               _In_ const D3D12_HEAP_DESC* pDesc,
                               REFIID                      riid,
                               _COM_Outptr_opt_ void**     ppvHeap) override;

    virtual HRESULT CreateHeap1(format::HandleId                         capture_id,
                                _In_ const D3D12_HEAP_DESC*              pDesc,
                                _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                REFIID                                   riid,
                                _COM_Outptr_opt_ void**                  ppvHeap) override;

    virtual HRESULT CreateCommittedResource(_In_ const D3D12_HEAP_PROPERTIES* pHeapProperties,
                                            D3D12_HEAP_FLAGS                  HeapFlags,
                                            _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                            D3D12_RESOURCE_STATES             InitialResourceState,
                                            _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                            REFIID                            riidResource,
                                            HandlePointerDecoder<void*>*      ppvResource) override;

    virtual HRESULT CreatePlacedResource(format::HandleId                  heap_capture_id,
                                         _In_ ID3D12Heap*                  pHeap,
                                         UINT64                            HeapOffset,
                                         _In_ const D3D12_RESOURCE_DESC*   pDesc,
                                         D3D12_RESOURCE_STATES             InitialState,
                                         _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                         REFIID                            riid,
                                         HandlePointerDecoder<void*>*      ppvResource,
                                         UINT64                            max_aliasing_size) override;

    virtual HRESULT CreateReservedResource(_In_ const D3D12_RESOURCE_DESC*   pDesc,
                                           D3D12_RESOURCE_STATES             InitialState,
                                           _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                           REFIID                            riid,
                                           HandlePointerDecoder<void*>*      ppvResource) override;

    virtual HRESULT CreateCommittedResource1(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                             D3D12_HEAP_FLAGS                         HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC*          pDesc,
                                             D3D12_RESOURCE_STATES                    InitialResourceState,
                                             _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                             REFIID                                   riidResource,
                                             HandlePointerDecoder<void*>*             ppvResource) override;

    virtual HRESULT CreatePlacedResource1(format::HandleId                  heap_capture_id,
                                          _In_ ID3D12Heap*                  pHeap,
                                          UINT64                            HeapOffset,
                                          _In_ const D3D12_RESOURCE_DESC1*  pDesc,
                                          D3D12_RESOURCE_STATES             InitialState,
                                          _In_opt_ const D3D12_CLEAR_VALUE* pOptimizedClearValue,
                                          REFIID                            riid,
                                          HandlePointerDecoder<void*>*      ppvResource,
                                          UINT64                            max_aliasing_size) override;

    virtual HRESULT CreateReservedResource1(_In_ const D3D12_RESOURCE_DESC*          pDesc,
                                            D3D12_RESOURCE_STATES                    InitialState,
                                            _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                            _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                            REFIID                                   riid,
                                            HandlePointerDecoder<void*>*             ppvResource) override;

    virtual HRESULT CreateCommittedResource2(_In_ const D3D12_HEAP_PROPERTIES*        pHeapProperties,
                                             D3D12_HEAP_FLAGS                         HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC1*         pDesc,
                                             D3D12_RESOURCE_STATES                    InitialResourceState,
                                             _In_opt_ const D3D12_CLEAR_VALUE*        pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession* pProtectedSession,
                                             REFIID                                   riidResource,
                                             HandlePointerDecoder<void*>*             ppvResource) override;

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
                                          UINT64 max_aliasing_size) override;

    virtual HRESULT CreateReservedResource2(_In_ const D3D12_RESOURCE_DESC*                       pDesc,
                                            D3D12_BARRIER_LAYOUT                                  InitialLayout,
                                            _In_opt_ const D3D12_CLEAR_VALUE*                     pOptimizedClearValue,
                                            _In_opt_ ID3D12ProtectedResourceSession*              pProtectedSession,
                                            UINT32                                                NumCastableFormats,
                                            _In_opt_count_(NumCastableFormats) const DXGI_FORMAT* pCastableFormats,
                                            REFIID                                                riid,
                                            HandlePointerDecoder<void*>*                          ppvResource) override;

    virtual HRESULT CreateCommittedResource3(_In_ const D3D12_HEAP_PROPERTIES*                     pHeapProperties,
                                             D3D12_HEAP_FLAGS                                      HeapFlags,
                                             _In_ const D3D12_RESOURCE_DESC1*                      pDesc,
                                             D3D12_BARRIER_LAYOUT                                  InitialLayout,
                                             _In_opt_ const D3D12_CLEAR_VALUE*                     pOptimizedClearValue,
                                             _In_opt_ ID3D12ProtectedResourceSession*              pProtectedSession,
                                             UINT32                                                NumCastableFormats,
                                             _In_opt_count_(NumCastableFormats) const DXGI_FORMAT* pCastableFormats,
                                             REFIID                                                riidResource,
                                             HandlePointerDecoder<void*>* ppvResource) override;

    virtual HRESULT SetResidencyPriority(UINT                                   NumObjects,
                                         HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
                                         const D3D12_RESIDENCY_PRIORITY*        pPriorities) override;

    virtual void GetResourceTiling(_In_ ID3D12Resource*             pTiledResource,
                                   _Out_opt_ UINT*                  pNumTilesForEntireResource,
                                   _Out_opt_ D3D12_PACKED_MIP_INFO* pPackedMipDesc,
                                   _Out_opt_ D3D12_TILE_SHAPE*      pStandardTileShapeForNonPackedMips,
                                   _Inout_opt_ UINT*                pNumSubresourceTilings,
                                   _In_ UINT                        FirstSubresourceTilingToGet,
                                   _Out_ D3D12_SUBRESOURCE_TILING*  pSubresourceTilingsForNonPackedMips) override;

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
                                    D3D12_TILE_MAPPING_FLAGS                                Flags) override;

    virtual void CopyTileMappings(ID3D12CommandQueue*                             pQueue,
                                  format::HandleId                                dst_resource_capture_id,
                                  _In_ ID3D12Resource*                            pDstResource,
                                  format::HandleId                                src_resource_capture_id,
                                  _In_ ID3D12Resource*                            pSrcResource,
                                  _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
                                  _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
                                  _In_opt_ const D3D12_TILE_REGION_SIZE*          pRegionSize,
                                  D3D12_TILE_MAPPING_FLAGS                        Flags) override;

    virtual void CopyTiles(ID3D12GraphicsCommandList*                      pList,
                           format::HandleId                                resource_capture_id,
                           _In_ ID3D12Resource*                            pResource,
                           _In_opt_ const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
                           _In_opt_ const D3D12_TILE_REGION_SIZE*          pTileRegionSize,
                           format::HandleId                                buffer_capture_id,
                           _In_ ID3D12Resource*                            pBuffer,
                           UINT64                                          BufferStartOffsetInBytes,
                           D3D12_TILE_COPY_FLAGS                           Flags) override;

    virtual bool SupportD3D12MemoryAllocator() override { return false; }

    virtual ULONG Release(IUnknown* object, format::HandleId object_id) override { return 0; }

    virtual void PostPresent() override{};

    virtual void ReportResourceIncompatibility(const D3D12_RESOURCE_DESC* resource_desc) override;

    virtual void ReportResourceIncompatibility1(const D3D12_RESOURCE_DESC1* resource_desc) override;

    virtual bool IsAliasingResourcePairs(const format::HandleId resource_before_id,
                                         const format::HandleId resource_after_id) override
    {
        return true;
    }

  private:
    ID3D12Device* device_;
    std::string   custom_error_string_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_DEFAULT_ALLOCATOR_H
