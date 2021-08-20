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
** This file is generated from dx12_command_list_util_body_generator.py.
**
*/


#include "generated/generated_dx12_command_list_util.h"
#include "encode/dx12_object_wrapper_util.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Track_ID3D12GraphicsCommandList_Reset(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12CommandAllocator * pAllocator, ID3D12PipelineState * pInitialState)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pAllocator != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12CommandAllocatorObject].insert(GetWrappedId(pAllocator));
    }

    if(pInitialState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetWrappedId(pInitialState));
    }
}


void Track_ID3D12GraphicsCommandList_ClearState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pPipelineState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetWrappedId(pPipelineState));
    }
}


void Track_ID3D12GraphicsCommandList_CopyBufferRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT64 NumBytes)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstBuffer));
    }

    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_CopyTextureRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, const D3D12_TEXTURE_COPY_LOCATION * pDst, UINT DstX, UINT DstY, UINT DstZ, const D3D12_TEXTURE_COPY_LOCATION * pSrc, const D3D12_BOX * pSrcBox)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDst != nullptr)
    {
        if(pDst->pResource != nullptr)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDst->pResource));
        }
    }

    if(pSrc != nullptr)
    {
        if(pSrc->pResource != nullptr)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrc->pResource));
        }
    }
}


void Track_ID3D12GraphicsCommandList_CopyResource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, ID3D12Resource * pSrcResource)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstResource));
    }

    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList_CopyTiles(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pTiledResource, const D3D12_TILED_RESOURCE_COORDINATE * pTileRegionStartCoordinate, const D3D12_TILE_REGION_SIZE * pTileRegionSize, ID3D12Resource * pBuffer, UINT64 BufferStartOffsetInBytes, D3D12_TILE_COPY_FLAGS Flags)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pTiledResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pTiledResource));
    }

    if(pBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_ResolveSubresource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, ID3D12Resource * pSrcResource, UINT SrcSubresource, DXGI_FORMAT Format)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstResource));
    }

    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList_SetPipelineState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12PipelineState * pPipelineState)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pPipelineState != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12PipelineStateObject].insert(GetWrappedId(pPipelineState));
    }
}


void Track_ID3D12GraphicsCommandList_ExecuteBundle(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12GraphicsCommandList * pCommandList)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pCommandList != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12GraphicsCommandListObject].insert(GetWrappedId(pCommandList));
    }
}


void Track_ID3D12GraphicsCommandList_SetDescriptorHeaps(ID3D12GraphicsCommandList_Wrapper* wrapper, UINT NumDescriptorHeaps, ID3D12DescriptorHeap * const * ppDescriptorHeaps)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(ppDescriptorHeaps != nullptr)
    {
        for (UINT i = 0; i < NumDescriptorHeaps; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12DescriptorHeapObject].insert(GetWrappedId(ppDescriptorHeaps[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList_SetComputeRootSignature(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pRootSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12RootSignatureObject].insert(GetWrappedId(pRootSignature));
    }
}


void Track_ID3D12GraphicsCommandList_SetGraphicsRootSignature(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12RootSignature * pRootSignature)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pRootSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12RootSignatureObject].insert(GetWrappedId(pRootSignature));
    }
}


void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(ID3D12GraphicsCommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const UINT* Values, UINT NumRects, const D3D12_RECT * pRects)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(ID3D12GraphicsCommandList_Wrapper* wrapper, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, ID3D12Resource * pResource, const FLOAT* Values, UINT NumRects, const D3D12_RECT * pRects)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_DiscardResource(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, const D3D12_DISCARD_REGION * pRegion)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pResource));
    }
}


void Track_ID3D12GraphicsCommandList_BeginQuery(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetWrappedId(pQueryHeap));
    }
}


void Track_ID3D12GraphicsCommandList_EndQuery(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT Index)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetWrappedId(pQueryHeap));
    }
}


void Track_ID3D12GraphicsCommandList_ResolveQueryData(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12QueryHeap * pQueryHeap, D3D12_QUERY_TYPE Type, UINT StartIndex, UINT NumQueries, ID3D12Resource * pDestinationBuffer, UINT64 AlignedDestinationBufferOffset)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pQueryHeap != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12QueryHeapObject].insert(GetWrappedId(pQueryHeap));
    }

    if(pDestinationBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDestinationBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_SetPredication(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pBuffer, UINT64 AlignedBufferOffset, D3D12_PREDICATION_OP Operation)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pBuffer));
    }
}


void Track_ID3D12GraphicsCommandList_ExecuteIndirect(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12CommandSignature * pCommandSignature, UINT MaxCommandCount, ID3D12Resource * pArgumentBuffer, UINT64 ArgumentBufferOffset, ID3D12Resource * pCountBuffer, UINT64 CountBufferOffset)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pCommandSignature != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12CommandSignatureObject].insert(GetWrappedId(pCommandSignature));
    }

    if(pArgumentBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pArgumentBuffer));
    }

    if(pCountBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pCountBuffer));
    }
}


void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstBuffer));
    }

    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcBuffer));
    }

    if(ppDependentResources != nullptr)
    {
        for (UINT i = 0; i < Dependencies; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(ppDependentResources[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstBuffer, UINT64 DstOffset, ID3D12Resource * pSrcBuffer, UINT64 SrcOffset, UINT Dependencies, ID3D12Resource * const * ppDependentResources, const D3D12_SUBRESOURCE_RANGE_UINT64 * pDependentSubresourceRanges)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstBuffer));
    }

    if(pSrcBuffer != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcBuffer));
    }

    if(ppDependentResources != nullptr)
    {
        for (UINT i = 0; i < Dependencies; ++i)
        {
            info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(ppDependentResources[i]));
        }
    }
}


void Track_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, ID3D12Resource * pSrcResource, UINT SrcSubresource, D3D12_RECT * pSrcRect, DXGI_FORMAT Format, D3D12_RESOLVE_MODE ResolveMode)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pDstResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pDstResource));
    }

    if(pSrcResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pSrcResource));
    }
}


void Track_ID3D12GraphicsCommandList3_SetProtectedResourceSession(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12ProtectedResourceSession * pProtectedResourceSession)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pProtectedResourceSession != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ProtectedResourceSessionObject].insert(GetWrappedId(pProtectedResourceSession));
    }
}


void Track_ID3D12GraphicsCommandList4_InitializeMetaCommand(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pInitializationParametersData, SIZE_T InitializationParametersDataSizeInBytes)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pMetaCommand != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12MetaCommandObject].insert(GetWrappedId(pMetaCommand));
    }
}


void Track_ID3D12GraphicsCommandList4_ExecuteMetaCommand(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12MetaCommand * pMetaCommand, const void * pExecutionParametersData, SIZE_T ExecutionParametersDataSizeInBytes)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pMetaCommand != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12MetaCommandObject].insert(GetWrappedId(pMetaCommand));
    }
}


void Track_ID3D12GraphicsCommandList4_SetPipelineState1(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12StateObject * pStateObject)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pStateObject != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12StateObjectObject].insert(GetWrappedId(pStateObject));
    }
}


void Track_ID3D12GraphicsCommandList5_RSSetShadingRateImage(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * shadingRateImage)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(shadingRateImage != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(shadingRateImage));
    }
}


void Track_ID3D12DebugCommandList1_AssertResourceState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pResource));
    }
}


void Track_ID3D12DebugCommandList_AssertResourceState(ID3D12GraphicsCommandList_Wrapper* wrapper, ID3D12Resource * pResource, UINT Subresource, UINT State)
{
    assert(wrapper != nullptr);
    auto info = wrapper->GetObjectInfo();
    assert(info != nullptr);

    if(pResource != nullptr)
    {
        info->command_objects[D3D12GraphicsCommandObjectType::ID3D12ResourceObject].insert(GetWrappedId(pResource));
    }
}



GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
