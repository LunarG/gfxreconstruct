/*
** Copyright (c) 2021-2023 LunarG, Inc.
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

#include <dxgiformat.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3d11_2.h>
#include <d3d11_3.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgitype.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

#include "generated/generated_dx12_wrappers.h"

#include "util/defines.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Track_ID3D12GraphicsCommandList_Reset(ID3D12CommandList_Wrapper* wrapper, ID3D12CommandAllocator * pAllocator, ID3D12PipelineState * pInitialState);

void Track_ID3D12GraphicsCommandList_ClearState(ID3D12CommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState);

void Track_ID3D12GraphicsCommandList_CopyBufferRegion(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT64 NumBytes);

void Track_ID3D12GraphicsCommandList_CopyTextureRegion(ID3D12CommandList_Wrapper* wrapper, const D3D12_TEXTURE_COPY_LOCATION * pDst, UINT DstX, UINT DstY, UINT DstZ, const D3D12_TEXTURE_COPY_LOCATION * pSrc, const D3D12_BOX * pSrcBox);

void Track_ID3D12GraphicsCommandList_CopyResource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, ID3D12Resource * pSrcResource);

void Track_ID3D12GraphicsCommandList_CopyTiles(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pTiledResource, const D3D12_TILED_RESOURCE_COORDINATE * pTileRegionStartCoordinate, const D3D12_TILE_REGION_SIZE * pTileRegionSize, ID3D12Resource * pBuffer, UINT64 BufferStartOffsetInBytes, D3D12_TILE_COPY_FLAGS Flags);

void Track_ID3D12GraphicsCommandList_ResolveSubresource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, ID3D12Resource * pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format);

void Track_ID3D12GraphicsCommandList_SetPipelineState(ID3D12CommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState);

void Track_ID3D12GraphicsCommandList_ExecuteBundle(ID3D12CommandList_Wrapper* wrapper, ID3D12GraphicsCommandList * pCommandList);

void Track_ID3D12GraphicsCommandList_SetDescriptorHeaps(ID3D12CommandList_Wrapper* wrapper, UINT NumDescriptorHeaps, ID3D12DescriptorHeap * const * ppDescriptorHeaps);

void Track_ID3D12GraphicsCommandList_SetComputeRootSignature(ID3D12CommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootSignature(ID3D12CommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature);

void Track_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Track_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Track_ID3D12GraphicsCommandList_IASetIndexBuffer(ID3D12CommandList_Wrapper* wrapper, const D3D12_INDEX_BUFFER_VIEW * pView);

void Track_ID3D12GraphicsCommandList_IASetVertexBuffers(ID3D12CommandList_Wrapper* wrapper, UINT StartSlot, UINT NumViews, const D3D12_VERTEX_BUFFER_VIEW * pViews);

void Track_ID3D12GraphicsCommandList_SOSetTargets(ID3D12CommandList_Wrapper* wrapper, UINT StartSlot, UINT NumViews, const D3D12_STREAM_OUTPUT_BUFFER_VIEW * pViews);

void Track_ID3D12GraphicsCommandList_OMSetRenderTargets(ID3D12CommandList_Wrapper* wrapper, UINT NumRenderTargetDescriptors, const D3D12_CPU_DESCRIPTOR_HANDLE * pRenderTargetDescriptors, BOOL RTsSingleHandleToDescriptorRange, const D3D12_CPU_DESCRIPTOR_HANDLE * pDepthStencilDescriptor);

void Track_ID3D12GraphicsCommandList_ClearDepthStencilView(ID3D12CommandList_Wrapper* wrapper, D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView, D3D12_CLEAR_FLAGS ClearFlags, FLOAT Depth, UINT8 Stencil, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_ClearRenderTargetView(ID3D12CommandList_Wrapper* wrapper, D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView, const FLOAT* ColorRGBA, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const UINT* Values, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const FLOAT* Values, UINT NumRects, const D3D12_RECT * pRects);

void Track_ID3D12GraphicsCommandList_DiscardResource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, const D3D12_DISCARD_REGION * pRegion);

void Track_ID3D12GraphicsCommandList_BeginQuery(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index);

void Track_ID3D12GraphicsCommandList_EndQuery(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index);

void Track_ID3D12GraphicsCommandList_ResolveQueryData(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT StartIndex, UINT NumQueries, ID3D12Resource * pDestinationBuffer, UINT64 AlignedDestinationBufferOffset);

void Track_ID3D12GraphicsCommandList_SetPredication(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pBuffer, UINT64 AlignedBufferOffset, D3D12_PREDICATION_OP Operation);

void Track_ID3D12GraphicsCommandList_ExecuteIndirect(ID3D12CommandList_Wrapper* wrapper, ID3D12CommandSignature * pCommandSignature, UINT MaxCommandCount, ID3D12Resource * pArgumentBuffer, UINT64 ArgumentBufferOffset, ID3D12Resource * pCountBuffer, UINT64 CountBufferOffset);

void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges);

void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges);

void Track_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, ID3D12Resource * pSrcResource, UINT SrcSubresource, D3D12_RECT * pSrcRect, DXGI_FORMAT Format, D3D12_RESOLVE_MODE ResolveMode);

void Track_ID3D12GraphicsCommandList2_WriteBufferImmediate(ID3D12CommandList_Wrapper* wrapper, UINT Count, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER * pParams, const D3D12_WRITEBUFFERIMMEDIATE_MODE * pModes);

void Track_ID3D12GraphicsCommandList3_SetProtectedResourceSession(ID3D12CommandList_Wrapper* wrapper, ID3D12ProtectedResourceSession * pProtectedResourceSession);

void Track_ID3D12GraphicsCommandList4_InitializeMetaCommand(ID3D12CommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pInitializationParametersData, SIZE_T InitializationParametersDataSizeInBytes);

void Track_ID3D12GraphicsCommandList4_ExecuteMetaCommand(ID3D12CommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pExecutionParametersData, SIZE_T ExecutionParametersDataSizeInBytes);

void Track_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(ID3D12CommandList_Wrapper* wrapper, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC * pDesc, UINT NumSourceAccelerationStructures, const D3D12_GPU_VIRTUAL_ADDRESS * pSourceAccelerationStructureData);

void Track_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData, D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

void Track_ID3D12GraphicsCommandList4_SetPipelineState1(ID3D12CommandList_Wrapper* wrapper, ID3D12StateObject * pStateObject);

void Track_ID3D12GraphicsCommandList4_DispatchRays(ID3D12CommandList_Wrapper* wrapper, const D3D12_DISPATCH_RAYS_DESC * pDesc);

void Track_ID3D12GraphicsCommandList5_RSSetShadingRateImage(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * shadingRateImage);

void Track_ID3D12GraphicsCommandList7_Barrier(ID3D12CommandList_Wrapper* wrapper, UINT32 NumBarrierGroups, const D3D12_BARRIER_GROUP * pBarrierGroups);

void Track_ID3D12GraphicsCommandList10_SetProgram(ID3D12CommandList_Wrapper* wrapper, const D3D12_SET_PROGRAM_DESC * pDesc);

void Track_ID3D12GraphicsCommandList10_DispatchGraph(ID3D12CommandList_Wrapper* wrapper, const D3D12_DISPATCH_GRAPH_DESC * pDesc);

void Track_ID3D12DebugCommandList1_AssertResourceState(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State);

void Track_ID3D12DebugCommandList_AssertResourceState(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State);

void Track_ID3D12DebugCommandList3_AssertResourceAccess(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, D3D12_BARRIER_ACCESS Access);

void Track_ID3D12DebugCommandList3_AssertTextureLayout(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, D3D12_BARRIER_LAYOUT Layout);


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
