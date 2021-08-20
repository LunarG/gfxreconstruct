/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

/*
** This file is generated from dx12_command_list_util_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_COMMAND_LIST_UTIL_H
#define  GFXRECON_GENERATED_DX12_COMMAND_LIST_UTIL_H

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

#include "generated/generated_dx12_wrappers.h"

#include "util/defines.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Track_ID3D12GraphicsCommandList_Reset(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12CommandAllocator * pAllocator, ID3D12PipelineState * pInitialState);

void Track_ID3D12GraphicsCommandList_ClearState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState);

void Track_ID3D12GraphicsCommandList_CopyBufferRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT64 NumBytes);

void Track_ID3D12GraphicsCommandList_CopyTextureRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, const D3D12_TEXTURE_COPY_LOCATION * pDst, UINT DstX, UINT DstY, UINT DstZ, const D3D12_TEXTURE_COPY_LOCATION * pSrc, const D3D12_BOX * pSrcBox);

void Track_ID3D12GraphicsCommandList_CopyResource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, ID3D12Resource * pSrcResource);

void Track_ID3D12GraphicsCommandList_CopyTiles(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pTiledResource, const D3D12_TILED_RESOURCE_COORDINATE * pTileRegionStartCoordinate, const D3D12_TILE_REGION_SIZE * pTileRegionSize, ID3D12Resource * pBuffer, UINT64 BufferStartOffsetInBytes, D3D12_TILE_COPY_FLAGS Flags);

void Track_ID3D12GraphicsCommandList_ResolveSubresource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, ID3D12Resource * pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format);

void Track_ID3D12GraphicsCommandList_SetPipelineState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState);

void Track_ID3D12GraphicsCommandList_ExecuteBundle(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12GraphicsCommandList * pCommandList);

void Track_ID3D12GraphicsCommandList_SetDescriptorHeaps(ID3D12GraphicsCommandList_Wrapper* wrapper, UINT NumDescriptorHeaps, ID3D12DescriptorHeap * const * ppDescriptorHeaps);

void Track_ID3D12GraphicsCommandList_SetComputeRootSignature(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootSignature(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature);

void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(ID3D12GraphicsCommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const UINT* Values, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(ID3D12GraphicsCommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const FLOAT* Values, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_DiscardResource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, const D3D12_DISCARD_REGION * pRegion);

void Track_ID3D12GraphicsCommandList_BeginQuery(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index);

void Track_ID3D12GraphicsCommandList_EndQuery(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index);

void Track_ID3D12GraphicsCommandList_ResolveQueryData(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT StartIndex, UINT NumQueries, ID3D12Resource * pDestinationBuffer, UINT64 AlignedDestinationBufferOffset);

void Track_ID3D12GraphicsCommandList_SetPredication(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pBuffer, UINT64 AlignedBufferOffset, D3D12_PREDICATION_OP Operation);

void Track_ID3D12GraphicsCommandList_ExecuteIndirect(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12CommandSignature * pCommandSignature, UINT MaxCommandCount, ID3D12Resource * pArgumentBuffer, UINT64 ArgumentBufferOffset, ID3D12Resource * pCountBuffer, UINT64 CountBufferOffset);

void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges);

void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges);

void Track_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, ID3D12Resource * pSrcResource, UINT SrcSubresource, D3D12_RECT * pSrcRect, DXGI_FORMAT Format, D3D12_RESOLVE_MODE ResolveMode);

void Track_ID3D12GraphicsCommandList3_SetProtectedResourceSession(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12ProtectedResourceSession * pProtectedResourceSession);

void Track_ID3D12GraphicsCommandList4_InitializeMetaCommand(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pInitializationParametersData, SIZE_T InitializationParametersDataSizeInBytes);

void Track_ID3D12GraphicsCommandList4_ExecuteMetaCommand(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pExecutionParametersData, SIZE_T ExecutionParametersDataSizeInBytes);

void Track_ID3D12GraphicsCommandList4_SetPipelineState1(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12StateObject * pStateObject);

void Track_ID3D12GraphicsCommandList5_RSSetShadingRateImage(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * shadingRateImage);

void Track_ID3D12DebugCommandList1_AssertResourceState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State);

void Track_ID3D12DebugCommandList_AssertResourceState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State);


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
