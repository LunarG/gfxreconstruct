/*
** Copyright (c) 2021-2025 LunarG, Inc.
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
** This file is generated from dx12_command_list_util_body_generator.py.
**
*/


#include "generated/generated_dx12_command_list_util.h"
#include "encode/dx12_object_wrapper_util.h"
#include "util/logging.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Track_ID3D12GraphicsCommandList_Reset(ID3D12CommandList_Wrapper* wrapper, ID3D12CommandAllocator * pAllocator, ID3D12PipelineState * pInitialState)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pAllocator != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12CommandAllocatorObject].insert(GetDx12WrappedId(pAllocator));
    }
    if(pInitialState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetDx12WrappedId(pInitialState));
    }
}


void Track_ID3D12GraphicsCommandList_ClearState(ID3D12CommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pPipelineState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetDx12WrappedId(pPipelineState));
    }
}


void Track_ID3D12GraphicsCommandList_CopyBufferRegion(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT64 NumBytes)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstBuffer));
    }
    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_CopyTextureRegion(ID3D12CommandList_Wrapper* wrapper, const D3D12_TEXTURE_COPY_LOCATION * pDst, UINT DstX, UINT DstY, UINT DstZ, const D3D12_TEXTURE_COPY_LOCATION * pSrc, const D3D12_BOX * pSrcBox)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDst != nullptr)
    {
        if(pDst->pResource != nullptr)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDst->pResource));
        }
    }
    if(pSrc != nullptr)
    {
        if(pSrc->pResource != nullptr)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrc->pResource));
        }
    }
}


void Track_ID3D12GraphicsCommandList_CopyResource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, ID3D12Resource * pSrcResource)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstResource));
    }
    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList_CopyTiles(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pTiledResource, const D3D12_TILED_RESOURCE_COORDINATE * pTileRegionStartCoordinate, const D3D12_TILE_REGION_SIZE * pTileRegionSize, ID3D12Resource * pBuffer, UINT64 BufferStartOffsetInBytes, D3D12_TILE_COPY_FLAGS Flags)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pTiledResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pTiledResource));
    }
    if(pBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_ResolveSubresource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, ID3D12Resource * pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstResource));
    }
    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList_SetPipelineState(ID3D12CommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pPipelineState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetDx12WrappedId(pPipelineState));
    }
}


void Track_ID3D12GraphicsCommandList_ExecuteBundle(ID3D12CommandList_Wrapper* wrapper, ID3D12GraphicsCommandList * pCommandList)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pCommandList != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12GraphicsCommandListObject].insert(GetDx12WrappedId(pCommandList));
    }
}


void Track_ID3D12GraphicsCommandList_SetDescriptorHeaps(ID3D12CommandList_Wrapper* wrapper, UINT NumDescriptorHeaps, ID3D12DescriptorHeap * const * ppDescriptorHeaps)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(ppDescriptorHeaps != nullptr)
    {
        for (UINT i = 0; i < NumDescriptorHeaps; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12DescriptorHeapObject].insert(GetDx12WrappedId(ppDescriptorHeaps[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList_SetComputeRootSignature(ID3D12CommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pRootSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12RootSignatureObject].insert(GetDx12WrappedId(pRootSignature));
    }
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootSignature(ID3D12CommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pRootSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12RootSignatureObject].insert(GetDx12WrappedId(pRootSignature));
    }
}


void Track_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_descriptor_handles.insert(BaseDescriptor.ptr);
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_descriptor_handles.insert(BaseDescriptor.ptr);
}


void Track_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(ID3D12CommandList_Wrapper* wrapper, UINT RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(BufferLocation);
}


void Track_ID3D12GraphicsCommandList_IASetIndexBuffer(ID3D12CommandList_Wrapper* wrapper, const D3D12_INDEX_BUFFER_VIEW * pView)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pView != nullptr)
    {
        info->command_gpu_virtual_addresses.insert(pView->BufferLocation);
    }
}


void Track_ID3D12GraphicsCommandList_IASetVertexBuffers(ID3D12CommandList_Wrapper* wrapper, UINT StartSlot, UINT NumViews, const D3D12_VERTEX_BUFFER_VIEW * pViews)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pViews != nullptr)
    {
        for (UINT i = 0; i < NumViews; ++i)
        {
            info->command_gpu_virtual_addresses.insert(pViews[i].BufferLocation);
        }
    }
}


void Track_ID3D12GraphicsCommandList_SOSetTargets(ID3D12CommandList_Wrapper* wrapper, UINT StartSlot, UINT NumViews, const D3D12_STREAM_OUTPUT_BUFFER_VIEW * pViews)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pViews != nullptr)
    {
        for (UINT i = 0; i < NumViews; ++i)
        {
            info->command_gpu_virtual_addresses.insert(pViews[i].BufferLocation);
            info->command_gpu_virtual_addresses.insert(pViews[i].BufferFilledSizeLocation);
        }
    }
}


void Track_ID3D12GraphicsCommandList_OMSetRenderTargets(ID3D12CommandList_Wrapper* wrapper, UINT NumRenderTargetDescriptors, const D3D12_CPU_DESCRIPTOR_HANDLE * pRenderTargetDescriptors, BOOL RTsSingleHandleToDescriptorRange, const D3D12_CPU_DESCRIPTOR_HANDLE * pDepthStencilDescriptor)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pRenderTargetDescriptors != nullptr)
    {
        for (UINT i = 0; i < (NumRenderTargetDescriptors ? (RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors) : 0); ++i)
        {
            info->command_cpu_descriptor_handles.insert(pRenderTargetDescriptors[i].ptr);
        }
    }
    if(pDepthStencilDescriptor != nullptr)
    {
        info->command_cpu_descriptor_handles.insert(pDepthStencilDescriptor->ptr);
    }
}


void Track_ID3D12GraphicsCommandList_ClearDepthStencilView(ID3D12CommandList_Wrapper* wrapper, D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView, D3D12_CLEAR_FLAGS ClearFlags, FLOAT Depth, UINT8 Stencil, UINT NumRects, const D3D12_RECT * pRects)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_cpu_descriptor_handles.insert(DepthStencilView.ptr);
}


void Track_ID3D12GraphicsCommandList_ClearRenderTargetView(ID3D12CommandList_Wrapper* wrapper, D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView, const FLOAT* ColorRGBA, UINT NumRects, const D3D12_RECT * pRects)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_cpu_descriptor_handles.insert(RenderTargetView.ptr);
}


void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const UINT* Values, UINT NumRects, const D3D12_RECT * pRects)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_descriptor_handles.insert(ViewGPUHandleInCurrentHeap.ptr);
    info->command_cpu_descriptor_handles.insert(ViewCPUHandle.ptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const FLOAT* Values, UINT NumRects, const D3D12_RECT * pRects)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_descriptor_handles.insert(ViewGPUHandleInCurrentHeap.ptr);
    info->command_cpu_descriptor_handles.insert(ViewCPUHandle.ptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_DiscardResource(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, const D3D12_DISCARD_REGION * pRegion)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_BeginQuery(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetDx12WrappedId(pQueryHeap));
    }
}


void Track_ID3D12GraphicsCommandList_EndQuery(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetDx12WrappedId(pQueryHeap));
    }
}


void Track_ID3D12GraphicsCommandList_ResolveQueryData(ID3D12CommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT StartIndex, UINT NumQueries, ID3D12Resource * pDestinationBuffer, UINT64 AlignedDestinationBufferOffset)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetDx12WrappedId(pQueryHeap));
    }
    if(pDestinationBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDestinationBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_SetPredication(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pBuffer, UINT64 AlignedBufferOffset, D3D12_PREDICATION_OP Operation)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_ExecuteIndirect(ID3D12CommandList_Wrapper* wrapper, ID3D12CommandSignature * pCommandSignature, UINT MaxCommandCount, ID3D12Resource * pArgumentBuffer, UINT64 ArgumentBufferOffset, ID3D12Resource * pCountBuffer, UINT64 CountBufferOffset)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pCommandSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12CommandSignatureObject].insert(GetDx12WrappedId(pCommandSignature));
    }
    if(pArgumentBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pArgumentBuffer));
    }
    if(pCountBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pCountBuffer));
    }
}


void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstBuffer));
    }
    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcBuffer));
    }
    if(ppDependentResources != nullptr)
    {
        for (UINT i = 0; i < Dependencies; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(ppDependentResources[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstBuffer));
    }
    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcBuffer));
    }
    if(ppDependentResources != nullptr)
    {
        for (UINT i = 0; i < Dependencies; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(ppDependentResources[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, ID3D12Resource * pSrcResource, UINT SrcSubresource, D3D12_RECT * pSrcRect, DXGI_FORMAT Format, D3D12_RESOLVE_MODE ResolveMode)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pDstResource));
    }
    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList2_WriteBufferImmediate(ID3D12CommandList_Wrapper* wrapper, UINT Count, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER * pParams, const D3D12_WRITEBUFFERIMMEDIATE_MODE * pModes)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pParams != nullptr)
    {
        for (UINT i = 0; i < Count; ++i)
        {
            info->command_gpu_virtual_addresses.insert(pParams[i].Dest);
        }
    }
}


void Track_ID3D12GraphicsCommandList3_SetProtectedResourceSession(ID3D12CommandList_Wrapper* wrapper, ID3D12ProtectedResourceSession * pProtectedResourceSession)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pProtectedResourceSession != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ProtectedResourceSessionObject].insert(GetDx12WrappedId(pProtectedResourceSession));
    }
}


void Track_ID3D12GraphicsCommandList4_InitializeMetaCommand(ID3D12CommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pInitializationParametersData, SIZE_T InitializationParametersDataSizeInBytes)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pMetaCommand != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12MetaCommandObject].insert(GetDx12WrappedId(pMetaCommand));
    }
}


void Track_ID3D12GraphicsCommandList4_ExecuteMetaCommand(ID3D12CommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pExecutionParametersData, SIZE_T ExecutionParametersDataSizeInBytes)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pMetaCommand != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12MetaCommandObject].insert(GetDx12WrappedId(pMetaCommand));
    }
}


void Track_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(ID3D12CommandList_Wrapper* wrapper, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC * pDesc, UINT NumSourceAccelerationStructures, const D3D12_GPU_VIRTUAL_ADDRESS * pSourceAccelerationStructureData)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDesc != nullptr)
    {
        info->command_gpu_virtual_addresses.insert(pDesc->DestBuffer);
    }
    if(pSourceAccelerationStructureData != nullptr)
    {
        for (UINT i = 0; i < NumSourceAccelerationStructures; ++i)
        {
            info->command_gpu_virtual_addresses.insert(pSourceAccelerationStructureData[i]);
        }
    }
}


void Track_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(ID3D12CommandList_Wrapper* wrapper, D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData, D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    info->command_gpu_virtual_addresses.insert(DestAccelerationStructureData);
    info->command_gpu_virtual_addresses.insert(SourceAccelerationStructureData);
}


void Track_ID3D12GraphicsCommandList4_SetPipelineState1(ID3D12CommandList_Wrapper* wrapper, ID3D12StateObject * pStateObject)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pStateObject != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12StateObjectObject].insert(GetDx12WrappedId(pStateObject));
    }
}


void Track_ID3D12GraphicsCommandList4_DispatchRays(ID3D12CommandList_Wrapper* wrapper, const D3D12_DISPATCH_RAYS_DESC * pDesc)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pDesc != nullptr)
    {
        info->command_gpu_virtual_addresses.insert(pDesc->RayGenerationShaderRecord.StartAddress);
        info->command_gpu_virtual_addresses.insert(pDesc->MissShaderTable.StartAddress);
        info->command_gpu_virtual_addresses.insert(pDesc->HitGroupTable.StartAddress);
        info->command_gpu_virtual_addresses.insert(pDesc->CallableShaderTable.StartAddress);
    }
}


void Track_ID3D12GraphicsCommandList5_RSSetShadingRateImage(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * shadingRateImage)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(shadingRateImage != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(shadingRateImage));
    }
}


void Track_ID3D12GraphicsCommandList7_Barrier(ID3D12CommandList_Wrapper* wrapper, UINT32 NumBarrierGroups, const D3D12_BARRIER_GROUP * pBarrierGroups)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
}


void Track_ID3D12GraphicsCommandList10_SetProgram(ID3D12CommandList_Wrapper* wrapper, const D3D12_SET_PROGRAM_DESC * pDesc)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
}


void Track_ID3D12GraphicsCommandList10_DispatchGraph(ID3D12CommandList_Wrapper* wrapper, const D3D12_DISPATCH_GRAPH_DESC * pDesc)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
}


void Track_ID3D12DebugCommandList1_AssertResourceState(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12DebugCommandList_AssertResourceState(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12DebugCommandList3_AssertResourceAccess(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, D3D12_BARRIER_ACCESS Access)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}


void Track_ID3D12DebugCommandList3_AssertTextureLayout(ID3D12CommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, D3D12_BARRIER_LAYOUT Layout)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    GFXRECON_ASSERT(info != nullptr);
    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetDx12WrappedId(pResource));
    }
}



GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
